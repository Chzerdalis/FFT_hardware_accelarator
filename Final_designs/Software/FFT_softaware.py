import numpy as np
import math
import subprocess
import sys
import os
import shutil

"""
Twiddle ROM generation with optional inline CSHM (shift-and-add) encoding.

    # raw twiddles (original behaviour)
    generate_twiddles(256, 9, type_fft=0)

    # CSHM instruction words instead
    enc = CSHMEncoder(bit_width=9, alphabets=8, num_slots=2)
    generate_twiddles(256, 9, type_fft=0, cshm=enc)
    enc.word_bits      # <-- ROM width the RTL must use (NOT twiddle_width)

Instruction word layout, slot 0 in the MSBs:

    [ alpha_idx : alpha_bits ][ sign : 1 ][ shift : shift_bits ]  x num_slots

hardware computes:  sum_i  (+/-) (alphabet[alpha_idx_i] * x) << shift_i
"""

import math
import itertools
import numpy as np


# ===========================================================================
# CSHM encoder
# ===========================================================================

class CSHMEncoder:
    """
    bit_width      width the twiddles were quantised to
    alphabets      int N -> [1, 3, 5, ...] of length N, or an explicit list
    num_slots      number of shift-add terms per constant
    tolerance_per  allowed error as a fraction of full scale (0 = exact only)
    allow_nearest  use the closest reachable value instead of failing
    """

    def __init__(self, bit_width, alphabets=8, num_slots=2, tolerance_per=0.0,
                 max_magnitude=None, allow_nearest=False):
        if isinstance(alphabets, int):
            if alphabets <= 0:
                raise ValueError("alphabets must be > 0")
            alphabets = [2 * n + 1 for n in range(alphabets)]
        self.alphabets = list(alphabets)
        self.bit_width = bit_width
        self.num_slots = num_slots
        self.tolerance_per = tolerance_per
        self.allow_nearest = allow_nearest
        self.max_magnitude = (1 << (bit_width - 1)) if max_magnitude is None else max_magnitude
        self.tolerance = tolerance_per * self.max_magnitude

        shifts = range(bit_width)
        single_terms = []
        for alpha in self.alphabets:
            for shift in shifts:
                for sign in (1, -1):
                    single_terms.append((sign * (alpha << shift), sign, alpha, shift))

        # cheapest (fewest total shifts) way to build each reachable value
        self._best = {}
        for combo in itertools.combinations_with_replacement(single_terms, num_slots):
            total = sum(t[0] for t in combo)
            cost = sum(t[3] for t in combo)
            prev = self._best.get(total)
            if prev is None or cost < prev[0]:
                self._best[total] = (cost, combo)
        self._reachable = sorted(self._best.keys())

        self.alpha_bits = math.ceil(math.log2(len(self.alphabets))) if len(self.alphabets) > 1 else 0
        self.shift_bits = max(1, math.ceil(math.log2(bit_width)))
        self.slot_bits = self.alpha_bits + 1 + self.shift_bits
        self.word_bits = self.slot_bits * num_slots

        self._cache = {}
        self.exact = 0
        self.approx = 0
        self.max_abs_error = 0

    @property
    def hex_chars(self):
        return (self.word_bits + 3) // 4

    def _match(self, value):
        cands = [v for v in self._reachable if abs(v - value) <= self.tolerance]
        if cands:
            return min(cands, key=lambda v: abs(v - value))
        if self.allow_nearest:
            return min(self._reachable, key=lambda v: abs(v - value))
        return None

    def prevalidate(self, values):
        """Raise if any value is unreachable, before anything is written."""
        bad = sorted({int(v) for v in values if self._match(int(v)) is None})
        if bad:
            raise ValueError(
                f"CSHM cannot represent {len(bad)} value(s) with num_slots="
                f"{self.num_slots}, alphabet={self.alphabets}, tolerance_per="
                f"{self.tolerance_per}: {bad[:12]}{' ...' if len(bad) > 12 else ''}. "
                f"Increase num_slots, widen the alphabet, raise tolerance_per, "
                f"or set allow_nearest=True."
            )

    def encode(self, value):
        """Signed twiddle value -> packed instruction word."""
        value = int(value)
        hit = self._cache.get(value)
        if hit is not None:
            return hit

        best = self._match(value)
        if best is None:
            raise ValueError(
                f"CSHM cannot represent {value} (tolerance {self.tolerance})."
            )

        word = 0
        for (_v, sign, alpha, shift) in self._best[best][1]:
            slot = (self.alphabets.index(alpha) << (1 + self.shift_bits))
            slot |= (0 if sign > 0 else 1) << self.shift_bits
            slot |= shift
            word = (word << self.slot_bits) | slot

        if best == value:
            self.exact += 1
        else:
            self.approx += 1
            self.max_abs_error = max(self.max_abs_error, abs(best - value))
        self._cache[value] = word
        return word

    def equation(self, value):
        """Readable shift-add expression chosen for a value."""
        best = self._match(int(value))
        if best is None:
            return None
        parts = []
        for i, (_v, sign, alpha, shift) in enumerate(self._best[best][1]):
            lead = ("-" if sign < 0 else "") if i == 0 else (" - " if sign < 0 else " + ")
            parts.append(f"{lead}({alpha}x << {shift})")
        return "".join(parts)

    def summary(self):
        return (f"CSHM word={self.word_bits}b ({self.num_slots} x "
                f"[alpha:{self.alpha_bits}|sign:1|shift:{self.shift_bits}]) "
                f"| distinct={len(self._cache)} exact={self.exact} "
                f"approx={self.approx} max_err={self.max_abs_error}")

    # -- inverse, for checking a ROM word or the RTL decoder ---------------

    def decode(self, word):
        """word -> list of (sign, alpha, shift)."""
        slots = []
        for i in range(self.num_slots):
            sh = self.slot_bits * (self.num_slots - 1 - i)
            slot = (word >> sh) & ((1 << self.slot_bits) - 1)
            shift = slot & ((1 << self.shift_bits) - 1)
            sign = -1 if (slot >> self.shift_bits) & 1 else 1
            idx = (slot >> (self.shift_bits + 1)) & ((1 << self.alpha_bits) - 1) if self.alpha_bits else 0
            slots.append((sign, self.alphabets[idx], shift))
        return slots

    def evaluate(self, word):
        """word -> the constant it represents."""
        return sum(s * (a << sh) for s, a, sh in self.decode(word))


# ===========================================================================
# Twiddle generation
# ===========================================================================

def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0, cshm=None,
                      data_dir="../Data"):
    """
    cshm:  None        -> raw two's-complement twiddle values (unchanged)
           CSHMEncoder -> packed CSHM instruction words
           dict        -> e.g. {"alphabets": 8, "num_slots": 2}

    When encoding, the whole value set is validated before any file is
    written, so an unrepresentable value fails cleanly rather than leaving
    a half-raw / half-encoded ROM set on disk.
    """
    if type_fft == 0:
        stages = int(math.log2(N))
    elif type_fft == 1:
        stages = int(math.log2(N)) // 2   # radix-4: half the stages
    elif type_fft == 2:
        stages = int(math.log2(N))        # split-radix: same as radix-2
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

    k = np.arange(N)
    twiddles = np.exp(-2j * np.pi * k / N)

    real_file_r2   = lambda s: f"{data_dir}/f_twiddle_real_{s}.mem"
    imag_file_r2   = lambda s: f"{data_dir}/f_twiddle_imag_{s}.mem"
    real_file_r4_1 = lambda s: f"{data_dir}/f_twiddle_real_{s}_1.mem"
    imag_file_r4_1 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_1.mem"
    real_file_r4_2 = lambda s: f"{data_dir}/f_twiddle_real_{s}_2.mem"
    imag_file_r4_2 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_2.mem"
    real_file_r4_3 = lambda s: f"{data_dir}/f_twiddle_real_{s}_3.mem"
    imag_file_r4_3 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_3.mem"

    fractional_bits = twiddle_width - 1
    scale_factor = 1 << fractional_bits
    min_val = -scale_factor
    max_val = scale_factor - 1

    # error_magnitude = 0.01 * scale_factor
    
    # # Generate random errors for real and imaginary parts
    # error_real = np.random.uniform(-error_magnitude, error_magnitude, size=N)
    # error_imag = np.random.uniform(-error_magnitude, error_magnitude, size=N)

    # # Create a mask that is True for roughly 5% of the indices
    # apply_error_mask = np.random.rand(N) < 0.05

    # # Zero out the error for the 95% of values that should remain untouched
    # error_real = error_real * apply_error_mask
    # error_imag = error_imag * apply_error_mask

    # # Apply scaling, inject the 2% error (only on 30% of them), then clip and mask
    # twiddle_real = np.clip((twiddles.real * scale_factor) + error_real, min_val, max_val).astype(int)
    # twiddle_imag = np.clip((twiddles.imag * scale_factor) + error_imag, min_val, max_val).astype(int) 

    twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int)
    twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int)

    if isinstance(cshm, dict):
        cshm = CSHMEncoder(bit_width=twiddle_width, **cshm)
    encoding = cshm is not None

    if encoding:
        cshm.prevalidate(set(twiddle_real.tolist()) | set(twiddle_imag.tolist()))
        out_bits = cshm.word_bits
    else:
        out_bits = twiddle_width

    hex_chars = (out_bits + 3) // 4
    out_mask = (1 << out_bits) - 1

    def dump(path, values):
        with open(path, "w") as f:
            for v in values:
                word = cshm.encode(v) if encoding else int(v)
                f.write(f"{word & out_mask:0{hex_chars}X}\n")

    for stage in range(1, stages + 1):
        if type_fft == 0:
            real_q = twiddle_real[0: N // 2]
            imag_q = twiddle_imag[0: N // 2]
            stride = (N // 2) // 2 ** (stage - 1)
            iter_count = 2 ** (stage - 1)

            dump(real_file_r2(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r2(stage), [imag_q[stride * j] for j in range(iter_count)])

        elif type_fft == 1:
            real_q, imag_q = twiddle_real, twiddle_imag
            stride = (N // 4) // 4 ** (stage - 1)
            iter_count = 4 ** (stage - 1)

            dump(real_file_r4_1(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r4_1(stage), [imag_q[stride * j] for j in range(iter_count)])
            dump(real_file_r4_2(stage), [real_q[stride * j * 2] for j in range(iter_count)])
            dump(imag_file_r4_2(stage), [imag_q[stride * j * 2] for j in range(iter_count)])
            dump(real_file_r4_3(stage), [real_q[stride * j * 3] for j in range(iter_count)])
            dump(imag_file_r4_3(stage), [imag_q[stride * j * 3] for j in range(iter_count)])

        elif type_fft == 2:
            real_q, imag_q = twiddle_real, twiddle_imag
            if stage == 1:
                continue                  # split-radix stage 1 has no twiddle
            stride = 2 ** (stage - 2)
            iter_count = int(N // (2 ** stage))

            dump(real_file_r4_1(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r4_1(stage), [imag_q[stride * j] for j in range(iter_count)])
            dump(real_file_r4_2(stage), [real_q[stride * j * 3] for j in range(iter_count)])
            dump(imag_file_r4_2(stage), [imag_q[stride * j * 3] for j in range(iter_count)])

    return twiddles.real, twiddles.imag


def twiddle_files(fft_size, type_fft, data_dir="../Data"):
    """The .mem paths generate_twiddles writes for this configuration."""
    if type_fft == 0:
        stages = int(math.log2(fft_size))
    elif type_fft == 1:
        stages = int(math.log2(fft_size)) // 2
    elif type_fft == 2:
        stages = int(math.log2(fft_size))
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

    files = []
    for stage in range(1, stages + 1):
        if type_fft == 0:
            files += [f"{data_dir}/f_twiddle_real_{stage}.mem",
                      f"{data_dir}/f_twiddle_imag_{stage}.mem"]
        elif type_fft == 1:
            for k in (1, 2, 3):
                files += [f"{data_dir}/f_twiddle_real_{stage}_{k}.mem",
                          f"{data_dir}/f_twiddle_imag_{stage}_{k}.mem"]
        else:
            if stage == 1:
                continue
            for k in (1, 2):
                files += [f"{data_dir}/f_twiddle_real_{stage}_{k}.mem",
                          f"{data_dir}/f_twiddle_imag_{stage}_{k}.mem"]
    return files

def clean_data_folder(folder_path="../Data"):
    """
    Deletes all files and subdirectories inside the specified folder.
    """
    # Convert to an absolute path to prevent accidental deletions in the wrong directory
    abs_path = os.path.abspath(folder_path)
    
    # Check if the folder actually exists before trying to clean it
    if not os.path.exists(abs_path):
        print(f"Folder not found: {abs_path}. Nothing to clean.")
        # Optionally create it if you want it to always exist:
        # os.makedirs(abs_path)
        return

    print(f"Cleaning folder: {abs_path}...")
    
    # Loop through everything inside the folder
    for item_name in os.listdir(abs_path):
        item_path = os.path.join(abs_path, item_name)
        
        try:
            if os.path.isfile(item_path) or os.path.islink(item_path):
                os.unlink(item_path)  # Delete the file or link
            elif os.path.isdir(item_path):
                shutil.rmtree(item_path)  # Delete the subdirectory and its contents
        except Exception as e:
            print(f"Failed to delete {item_path}. Reason: {e}")
            
    print("Folder cleaned successfully!")

def read_values(filepath="../Data/latencies.txt"):
    with open(filepath, 'r') as file:
        # read().split() handles both newlines and spaces automatically
        data = file.read().split()
        
        if len(data) >= 2:
            val1 = int(data[0])
            val2 = int(data[1])
            return val1, val2
        else:
            raise ValueError("The file does not contain at least two values.")

# Example usage:
# val1, val2 = read_values('my_file.txt')
# print(val1, val2)

def generate_input_output(Num_of_windows, N, tw_width, type_fft=0, signal_mode="random"):

    #Used to find the sign of a number
    def sign(x):
        return '-' if x < 0 else ''

    # Used to perform bit reversal for radix-2 FFT``
    def bitrev_2(n, bits):
        result = 0
        for i in range(bits):
            if (n >> i) & 1:
                result |= 1 << (bits - 1 - i)
        return result
    
    # Used to perform bit reversal for radix-4 FFT
    def bitrev_4(num, n):
        res = 0
        for i in range(n):
            bit = (num >> i*2) & 0x3
            res |= bit << 2*(n - 1 - i)
        return res

    rng = np.random.default_rng()
    
    # Use endpoint=False for DSP time vectors to prevent the wave from wrapping incorrectly
    t = np.linspace(0, 1, N, endpoint=False) 
    x_all = []

    for _ in range(Num_of_windows):
        x_real = np.zeros(len(t))
        x_imag = np.zeros(len(t))

        # 1. Determine frequency boundaries based on the mode
        if signal_mode == "low":
            # Pick 10 frequencies in the bottom 12% of the spectrum
            freqs = rng.integers(1, N // 8, size=10)
            
        elif signal_mode == "high":
            # Pick 10 frequencies in the top 12% of the spectrum (near Nyquist)
            freqs = rng.integers(N // 2 - N // 8, int(N / 2), size=10)
            
        elif signal_mode == "mixed":
            # Pick 5 very low frequencies and 5 very high frequencies
            f_low = rng.integers(1, N // 16, size=5)
            f_high = rng.integers(N // 2 - N // 16, int(N / 2), size=5)
            freqs = np.concatenate((f_low, f_high))

        elif signal_mode == "stress":
            # -- MAX MULTIPLICATION MODE --
            # Do not use sine waves. Instead, force every single sample 
            # to be the maximum positive (+1.0) or maximum negative (-1.0) value.
            # This pushes the dynamic range to the absolute limit.
            x_real = rng.choice([-1.0, 1.0], size=N)
            x_imag = rng.choice([-1.0, 1.0], size=N)
            
        else: # "random"
            # Pick 10 completely random frequencies across the whole spectrum
            freqs = rng.integers(1, int(N / 2), size=10)

        if(signal_mode != "stress"):
            # 2. Randomize amplitudes and phases
            ampls = rng.uniform(0.1, 1.0, size=len(freqs))
            phases = rng.uniform(0, 2 * np.pi, size=len(freqs))

            # 3. Construct the wave
            for freq, ampl, phase in zip(freqs, ampls, phases):
                x_real += ampl * np.sin(2 * np.pi * freq * t + phase)
                x_imag += ampl * np.cos(2 * np.pi * freq * t + phase)
            
        # 4. Normalize the signal to span exactly -1 to 1
        if x_real.max() != x_real.min():
            x_real = 2 * (x_real - x_real.min()) / (x_real.max() - x_real.min()) - 1
        if x_imag.max() != x_imag.min():
            x_imag = 2 * (x_imag - x_imag.min()) / (x_imag.max() - x_imag.min()) - 1
        
        x_all.append(x_real + 1j * x_imag)

    x_all = np.array(x_all)

    #Quantize the input data based on the specified tw_width
    component_width = tw_width
    
    # 2. Calculate the maximum positive value for a signed integer of that width
    # Example: If Data_width=32, component=16. (1 << 15) - 1 = 32767 (or 0x7FFF)
    scale_factor = (1 << (component_width - 1)) - 1
    
    # 3. Apply the quantization
    x_quantized = (x_all.real * scale_factor).astype(int) + 1j * (x_all.imag * scale_factor).astype(int)
    
    #Compute the FFT of the quantized input data
    x_fft_all = []
    for x in x_quantized:
        x_fft = np.fft.fft(x, len(x))
        x_fft.real = x_fft.real.astype(int)
        x_fft.imag = x_fft.imag.astype(int)
        x_fft_all.append(x_fft)

    x_fft_all = np.array(x_fft_all)
   
    N = x_quantized.shape[1]
    bits = int(math.log2(N))
    
    # 2. Pre-calculate the reordered indices EXACTLY ONCE
    if type_fft == 0:
        indices = [bitrev_2(i, bits) for i in range(N)]
    elif type_fft == 1:
        indices = [bitrev_4(i, bits//2) for i in range(N)]
    else:
        indices = list(range(N))
        
    # 3. Apply the indices to all windows simultaneously using NumPy advanced indexing
    # This reorders the items in every window based on the 'indices' list we just made
    x_reordered = x_quantized[:, indices]
    
    # 4. Flatten the 2D reordered array into a 1D array
    flat_x = x_reordered.flatten()
    
    # 5. Extract real and imaginary parts into a 2-column integer array
    out_data = np.column_stack((flat_x.real.astype(int), flat_x.imag.astype(int)))
    
    # 6. Write directly to the file using C-optimized savetxt (handles negative signs automatically)
    np.savetxt('../Data/input_data.txt', out_data, fmt='%d %d')

    if __debug__:
        print(f"Generated: ../Data/input_data.txt")

    # Write the FFT output data to 'correct_output.txt'
    # with open(f'../Data/correct_output.txt', 'w') as f:
    #     for window in x_fft_all:
    #         for i, value in enumerate(window):
    #             xir = int(value.real)
    #             xii = int(value.imag)
    #             f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')

    # 1. Flatten the 2D array into a 1D array of complex numbers
    flat_fft = x_fft_all.flatten()

    # 2. Extract real and imaginary parts into a 2-column array of integers
    out_data = np.column_stack((flat_fft.real.astype(int), flat_fft.imag.astype(int)))

    # 3. Write directly to the file using space separation ('%d %d')
    np.savetxt('../Data/correct_output.txt', out_data, fmt='%d %d')

    if __debug__:
        print(f"Generated: ../Data/correct_output.txt")

    return x_reordered

def generate_twiddle_pkg(N, src_dir, type_fft=0):
    """
    Generate twiddle_pkg.vh with ternary-macro file lookup trees.

    type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
                   macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

    type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
                   stage (W^1, W^2, W^3)
                   macros:  GET_REAL_FILE_1/2/3(idx)
                            GET_IMAG_FILE_1/2/3(idx)
    """
    if type_fft == 0:
        stages = int(math.log2(N))
    elif type_fft == 1:
        stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
    elif type_fft == 2:
        stages = int(math.log2(N))  # Split-Radix has the same number of stages as Radix-2

    def build_macro(macro_name, path_fn):
        """Build one ternary lookup tree mapping stage index -> filename."""
        s = f"`define {macro_name}(idx) \\\n"
        for stage in range(1, stages + 1):
            s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
        s += f'    "{path_fn(1)}"\n\n'  # Default fallback
        return s

    pkg_content = ""

    if type_fft == 0:
        # ---------------- Radix-2: one twiddle pair per stage -------------
        real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
        imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

        pkg_content += build_macro("GET_REAL_FILE", real_file)
        pkg_content += build_macro("GET_IMAG_FILE", imag_file)

    elif type_fft == 1:
        # ---------------- Radix-4: three twiddle pairs per stage ----------
        # NOTE: these filename patterns must match exactly what
        # generate_twiddles() writes for the radix-4 case.
        # Order is stage first, then the twiddle index k (1,2,3).
        real_file_r4 = lambda k: (
            lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
        )
        imag_file_r4 = lambda k: (
            lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
        )

        for k in (1, 2, 3):
            pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
            pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))
    elif type_fft == 2:
        # ---------------- Radix-4: three twiddle pairs per stage ----------
        # NOTE: these filename patterns must match exactly what
        # generate_twiddles() writes for the radix-4 case.
        # Order is stage first, then the twiddle index k (1,2,3).
        real_file_r4 = lambda k: (
            lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
        )
        imag_file_r4 = lambda k: (
            lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
        )

        for k in (1, 2):
            pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
            pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))

    # Write to a header file
    filepath = f"{src_dir}twiddle_pkg.vh"
    with open(filepath, "w") as f:
        f.write(pkg_content)

    radix = "radix-2" if type_fft == 0 else "radix-4" if type_fft == 1 else "split-radix"
    per_stage = 1 if type_fft == 0 else 3
    print(
        f"Generated {filepath} with ternary macros for {stages} {radix} "
        f"stages ({per_stage} twiddle pair(s) per stage)."
    )

def compile_simulation_verilator(Data_width=16, Tw_width=8, N=256, type_fft=0, window_size=1, SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=1, bit_growth=0, output_pipeline_bram=0, input_pipeline_bram=0, Cshm=0, Key_width=14, waves=False):
    # 1. Define the source directory and files
    if type_fft == 0:
        if Cshm == 0:
            src_dir = "../Radix-2/"
        else:
            src_dir = "../Radix-2_cshm/"
    elif type_fft == 1:
        if Cshm == 0:
            src_dir = "../Radix-4/"
        else:
            src_dir = "../Radix-4_cshm/"
    elif type_fft == 2:
        if Cshm == 0:
            src_dir = "../Radix-split/"
        else:
            src_dir = "../Radix-split_cshm/"

    generate_twiddle_pkg(N, src_dir, type_fft)

    if type_fft == 0:
        if Cshm == 0:
            design_files = [
                f"{src_dir}twiddle_pkg.vh", f"{src_dir}butterfly.v", f"{src_dir}delay_buffer.v",
                f"{src_dir}stage_unit.sv", f"{src_dir}tb_top_radix_2.v", f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}delay_reg.v", f"{src_dir}Carry_mult.v"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", f"-GTw_WIDTH={Tw_width}",
                f"-GMAX_FILE_SAMPLES={window_size * N + 1000}", f"-GSimpleMult={SimpleMult}",
                f"-GFast_DSP={Fast_DSP}", f"-Gcarry_save={carry_save}", f"-GBram={Bram}", f"-Gbit_growth={bit_growth}"
            ]
        else:
            design_files = [
                f"{src_dir}twiddle_pkg.vh", f"{src_dir}butterfly.v", f"{src_dir}delay_buffer.v",
                f"{src_dir}stage_unit.sv", f"{src_dir}tb_top_radix_2.v", f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}delay_reg.v",  f"{src_dir}cshm.v"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", f"-GTw_WIDTH={Tw_width}",
                f"-GMAX_FILE_SAMPLES={window_size * N + 1000}",
                f"-GBram={Bram}", f"-Gbit_growth={bit_growth}",
                f"-GKEY_WIDTH={Key_width}"
            ]
        top_module = "tb_radix2_top"

    elif type_fft == 1:
        if Cshm == 0:    
            design_files = [
                f"{src_dir}butterfly.v", f"{src_dir}memory.v", f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_4.v", f"{src_dir}fft_radix_4_top.sv", f"{src_dir}delay_reg.v", f"{src_dir}Carry_mult.v",
                f"{src_dir}twiddle_pkg.vh"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", f"-GTw_WIDTH={Tw_width}",
                f"-GBram={Bram}", f"-GSimpleMult={SimpleMult}", f"-GFast_DSP={Fast_DSP}",
                f"-Gcarry_save={carry_save}", f"-Goutput_pipeline_bram={output_pipeline_bram}",
                f"-Gbit_growth={bit_growth}", f"-GMAX_FILE_SAMPLES={window_size * N + 1000}"
            ]
        else:
            design_files = [
                f"{src_dir}butterfly.v", f"{src_dir}memory.v", f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_4.v", f"{src_dir}fft_radix_4_top.sv", f"{src_dir}delay_reg.v", f"{src_dir}cshm.v",
                f"{src_dir}twiddle_pkg.vh"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", f"-GTw_WIDTH={Tw_width}",
                f"-GBram={Bram}", f"-Goutput_pipeline_bram={output_pipeline_bram}",
                f"-Gbit_growth={bit_growth}", f"-GMAX_FILE_SAMPLES={window_size * N + 1000}",
                f"-GKEY_WIDTH={Key_width}"
            ]
        top_module = "tb_radix4_top"

    elif type_fft == 2:
        if Cshm == 0:
            design_files = [
                f"{src_dir}tb_split_fft_top.v", f"{src_dir}split_fft_top.v", f"{src_dir}first_stage.v",
                f"{src_dir}fsm_control_unit_last_stage.v", f"{src_dir}second_stage.v", f"{src_dir}third_stage_fsm.v",
                f"{src_dir}memory_first_stage.v", f"{src_dir}memory_second_stage.v", f"{src_dir}memory_third_stage.v",
                f"{src_dir}fsm_control_unit.v", f"{src_dir}complex_multiplier.v", f"{src_dir}delay_reg.v",
                f"{src_dir}butterfly.v", f"{src_dir}second_to_last_stage.v", f"{src_dir}last_stage.v",
                f"{src_dir}Carry_mult.v"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", 
                f"-GMAX_FILE_SAMPLES={window_size * N + 1000}",
                f"-GSimpleMult={SimpleMult}", f"-GFast_DSP={Fast_DSP}", f"-GTw_WIDTH={Tw_width}", 
                f"-Gcarry_save={carry_save}",
                f"-GBram={Bram}",
                f"-Goutput_pipeline_bram={output_pipeline_bram}", f"-Ginput_pipeline_bram={input_pipeline_bram}"
            ]
        else:
            design_files = [
                f"{src_dir}tb_split_fft_top.v", f"{src_dir}split_fft_top.v", f"{src_dir}first_stage.v",
                f"{src_dir}fsm_control_unit_last_stage.v", f"{src_dir}second_stage.v", f"{src_dir}third_stage_fsm.v",
                f"{src_dir}memory_first_stage.v", f"{src_dir}memory_second_stage.v", f"{src_dir}memory_third_stage.v",
                f"{src_dir}fsm_control_unit.v", f"{src_dir}complex_multiplier.v", f"{src_dir}delay_reg.v",
                f"{src_dir}butterfly.v", f"{src_dir}second_to_last_stage.v", f"{src_dir}last_stage.v",
                f"{src_dir}cshm.v"
            ]
            parameters = [
                f"-GWIDTH={Data_width}", f"-GNum_of_samples={N}", 
                f"-GMAX_FILE_SAMPLES={window_size * N + 1000}",
                f"-GTw_WIDTH={Tw_width}", f"-GBram={Bram}",
                f"-Goutput_pipeline_bram={output_pipeline_bram}", f"-Ginput_pipeline_bram={input_pipeline_bram}",
                f"-GKEY_WIDTH={Key_width}"
            ]
        top_module = "tb_split_fft_top"


    if __debug__:
        print("Compiling with Verilator...")

    if type_fft == 0:
        top_module = "tb_radix2_top"
    elif type_fft == 1:
        top_module = "tb_radix4_top"

    if waves:
        compile_cmd = [
            "verilator", 
            "--binary",       # Builds the C++ executable automatically
            "--timing",       # Supports standard Verilog #delays in the testbench
            "--trace",
            "-Wno-fatal",
            f"-I{src_dir}",     # Prevents minor linting warnings from failing the build
            "--top", top_module
        ] + parameters + design_files
    else:
        compile_cmd = [
            "verilator", 
            "--binary",       # Builds the C++ executable automatically
            "--timing",       # Supports standard Verilog #delays in the testbench
            "-Wno-fatal",     # Prevents minor linting warnings from failing the build
            f"-I{src_dir}",     # Prevents minor linting warnings from failing the build
            "--top", top_module
        ] + parameters + design_files
    
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("Compilation failed!")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
        sys.exit(1)

def compile_simulation_xsim(Data_width=16, Tw_width=8, N=256, type_fft=0, window_size=1, SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=1, bit_growth=0, output_pipeline_bram=0, input_pipeline_bram=0, Cshm=0, Key_width=14, waves=False):
    # 1. Define the source directory and files based on type_fft
    if type_fft == 0:
        if Cshm == 0:
            src_dir = "../Radix-2/"
        else:
            src_dir = "../Radix-2_cshm/"
    elif type_fft == 1:
        if Cshm == 0:
            src_dir = "../Radix-4/"
        else:
            src_dir = "../Radix-4_cshm/"
    elif type_fft == 2:
        if Cshm == 0:
            src_dir = "../Radix-split/"
        else:
            src_dir = "../Radix-split_cshm/"

    generate_twiddle_pkg(N, src_dir, type_fft) 

    if type_fft == 0:
        if Cshm == 0:
            design_files = [
                f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_buffer.v",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_2.v",
                f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}delay_reg.v",
                f"{src_dir}Carry_mult.v",
            ]
            top_module = "tb_radix2_top"
            snapshot_name = "tb_radix2_top_snapshot"
            
            # Generic parameters for Radix-2
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}",
                "-generic_top", f"SimpleMult={SimpleMult}",
                "-generic_top", f"Fast_DSP={Fast_DSP}",
                "-generic_top", f"carry_save={carry_save}",
                "-generic_top", f"Bram={Bram}",
                "-generic_top", f"bit_growth={bit_growth}"
            ]
        else:
            design_files = [
                f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_buffer.v",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_2.v",
                f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}delay_reg.v",
                f"{src_dir}cshm.v"
            ]
            top_module = "tb_radix2_top"
            snapshot_name = "tb_radix2_top_snapshot"
            
            # Generic parameters for Radix-2 with CSHM
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}",
                "-generic_top", f"Bram={Bram}",
                "-generic_top", f"bit_growth={bit_growth}",
                "-generic_top", f"KEY_WIDTH={Key_width}"
            ]

    elif type_fft == 1:
        if Cshm == 0:
            design_files = [
                f"{src_dir}butterfly.v",
                f"{src_dir}memory.v",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_4.v",
                f"{src_dir}fft_radix_4_top.sv",
                f"{src_dir}delay_reg.v",
                f"{src_dir}Carry_mult.v"
            ]
            top_module = "tb_radix4_top"
            snapshot_name = "tb_radix4_top_snapshot"
            
            # Generic parameters for Radix-4
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}",
                "-generic_top", f"SimpleMult={SimpleMult}",
                "-generic_top", f"Fast_DSP={Fast_DSP}",
                "-generic_top", f"carry_save={carry_save}",
                "-generic_top", f"Bram={Bram}",
                "-generic_top", f"output_pipeline_bram={output_pipeline_bram}",
                "-generic_top", f"bit_growth={bit_growth}"
            ]
        else:
            design_files = [
                f"{src_dir}butterfly.v",
                f"{src_dir}memory.v",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}tb_top_radix_4.v",
                f"{src_dir}fft_radix_4_top.sv",
                f"{src_dir}delay_reg.v",
                f"{src_dir}cshm.v"
            ]
            top_module = "tb_radix4_top"
            snapshot_name = "tb_radix4_top_snapshot"
            
            # Generic parameters for Radix-4 with CSHM
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}",
                "-generic_top", f"Bram={Bram}",
                "-generic_top", f"output_pipeline_bram={output_pipeline_bram}",
                "-generic_top", f"bit_growth={bit_growth}",
                "-generic_top", f"KEY_WIDTH={Key_width}"
            ]
    elif type_fft == 2:
        if Cshm == 0:
            design_files = [
                f"{src_dir}tb_split_fft_top.v", f"{src_dir}split_fft_top.v", f"{src_dir}first_stage.v",
                f"{src_dir}fsm_control_unit_last_stage.v", f"{src_dir}second_stage.v", f"{src_dir}third_stage_fsm.v",
                f"{src_dir}memory_first_stage.v", f"{src_dir}memory_second_stage.v", f"{src_dir}memory_third_stage.v",
                f"{src_dir}fsm_control_unit.v", f"{src_dir}complex_multiplier.v", f"{src_dir}delay_reg.v",
                f"{src_dir}butterfly.v", f"{src_dir}second_to_last_stage.v", f"{src_dir}last_stage.v",
                f"{src_dir}Carry_mult.v"
            ]
            top_module = "tb_split_fft_top"
            snapshot_name = "tb_split_fft_top_snapshot"
            
            # Generic parameters for Split-Radix (mapped directly to the TB parameters)
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}"
                "-generic_top", f"SimpleMult={SimpleMult}",
                "-generic_top", f"Fast_DSP={Fast_DSP}",
                "-generic_top", f"carry_save={carry_save}",
                "-generic_top", f"input_pipeline_bram={input_pipeline_bram}"
                "-generic_top", f"output_pipeline_bram={output_pipeline_bram}",
                "-generic_top", f"Bram={Bram}"
            ]
        else:
            design_files = [
                f"{src_dir}tb_split_fft_top.v", f"{src_dir}split_fft_top.v", f"{src_dir}first_stage.v",
                f"{src_dir}fsm_control_unit_last_stage.v", f"{src_dir}second_stage.v", f"{src_dir}third_stage_fsm.v",
                f"{src_dir}memory_first_stage.v", f"{src_dir}memory_second_stage.v", f"{src_dir}memory_third_stage.v",
                f"{src_dir}fsm_control_unit.v", f"{src_dir}complex_multiplier.v", f"{src_dir}delay_reg.v",
                f"{src_dir}butterfly.v", f"{src_dir}second_to_last_stage.v", f"{src_dir}last_stage.v",
                f"{src_dir}cshm.v"
            ]
            top_module = "tb_split_fft_top"
            snapshot_name = "tb_split_fft_top_snapshot"
            
            # Generic parameters for Split-Radix with CSHM
            generics = [
                "-generic_top", f"WIDTH={Data_width}",
                "-generic_top", f"Tw_WIDTH={Tw_width}",
                "-generic_top", f"Num_of_samples={N}",
                "-generic_top", f"MAX_FILE_SAMPLES={window_size * N + 1000}"
                "-generic_top", f"input_pipeline_bram={input_pipeline_bram}"
                "-generic_top", f"output_pipeline_bram={output_pipeline_bram}",
                "-generic_top", f"Bram={Bram}",
                "-generic_top", f"KEY_WIDTH={Key_width}"
            ]

    
    if __debug__:
        print(f"Compiling with Xilinx XSIM (Radix-{2 if type_fft == 0 else 4})...")

    # Step 1: Analysis (xvlog)
    xvlog_cmd = ["xvlog", "-sv", "--relax"] + design_files
    
    if __debug__:
        print(f"Running xvlog: {' '.join(xvlog_cmd)}")
        
    result = subprocess.run(xvlog_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("xvlog compilation failed!")
        print("Standard Output:\n", result.stdout)
        print("Standard Error:\n", result.stderr)
        sys.exit(1)

    # Step 2: Elaboration (xelab)
    # Use valid XSIM debug options: 'typical' for waves, 'off' for no waves
    debug_val = "typical" if waves else "off"

    xelab_cmd = [
        "xelab",
        "--incr",
        "--debug", debug_val,
        "--relax",
        "--top", top_module
    ] + generics + ["-s", snapshot_name]
    
    if __debug__:
        print(f"Running xelab: {' '.join(xelab_cmd)}")
        
    result = subprocess.run(xelab_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("xelab elaboration failed!")
        print("Standard Output:\n", result.stdout)
        print("Standard Error:\n", result.stderr)
        sys.exit(1)
        
    print(f"XSIM compilation successful! Snapshot created: {snapshot_name}")
    return snapshot_name

def run_simulation_verilator(type_fft=0):
    if __debug__:
        print("Running simulation...")
    # Verilator outputs the executable into 'obj_dir', prefixed with 'V'
    if type_fft == 0:
        sim_cmd = ["./obj_dir/Vtb_radix2_top"]
    elif type_fft == 1:
        sim_cmd = ["./obj_dir/Vtb_radix4_top"]
    elif type_fft == 2:
        sim_cmd = ["./obj_dir/Vtb_split_fft_top"]
    
    result = subprocess.run(sim_cmd, capture_output=True, text=True)
    
    if result.returncode != 0:
        print("--- SIMULATION FAILED ---")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
    else:
        if __debug__:
            print(result.stdout)

def run_simulation_xsim(snapshot_name="tb_radix2_top_snapshot", waves=False):
    if __debug__:
        print("Running simulation with XSIM...")
    
    # XSIM runs the elaborated snapshot generated by xelab
    sim_cmd = ["xsim", snapshot_name]
    
    if waves:
        # Open in GUI mode for waveform inspection
        sim_cmd.append("-gui")
    else:
        # Run-all in batch mode to completion via $finish statements
        sim_cmd.append("-runall")
    
    result = subprocess.run(sim_cmd, capture_output=True, text=True)
    
    if result.returncode != 0:
        print("--- XSIM SIMULATION FAILED ---")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
        sys.exit(1)
    else:
        if __debug__:
            print(result.stdout)

def run_simulation():
    # 3. Run the simulation
    if __debug__:
        print("Running simulation...")

    sim_cmd = ["vvp", "sim.vvp"]
    result = subprocess.run(sim_cmd, capture_output=True, text=True)
    
    # If the simulation fails (non-zero return code), print the errors
    if result.returncode != 0:
        print("--- SIMULATION FAILED ---")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)

def load_file(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
    data = [list(map(int, line.strip().split())) for line in lines if line.strip()]
    return np.array(data)


import numpy as np

def advanced_sqnr(golden, hardware):
    """
    Calculates both Raw SQNR and Gain-Compensated SQNR to isolate 
    true quantization noise from fixed-point attenuation.
    """
    # Ensure inputs are high-precision floats to prevent math overflow during calculation
    golden = np.asarray(golden, dtype=np.float64)
    hardware = np.asarray(hardware, dtype=np.float64)
    
    # 1. Raw SQNR (What your previous function did)
    raw_signal_power = np.mean(golden ** 2)
    raw_noise_power = np.mean((golden - hardware) ** 2)
    
    if raw_noise_power == 0:
        raw_sqnr = float('inf')
    else:
        raw_sqnr = 10 * np.log10(raw_signal_power / raw_noise_power)
        
    # 2. Calculate the optimal systematic gain (Least-Squares Fit)
    # This finds the exact volume reduction your hardware applied.
    # Math: g = sum(golden * hardware) / sum(golden^2)
    gain = np.sum(golden * hardware) / np.sum(golden ** 2)
    
    # 3. Apply the gain to the golden model to match the hardware's scale
    compensated_golden = golden * gain
    compensated_signal_power = np.mean(compensated_golden ** 2)
    
    # 4. Calculate True Noise Power (Scatter only)
    true_noise = hardware - compensated_golden
    true_noise_power = np.mean(true_noise ** 2)
    
    if true_noise_power == 0:
        comp_sqnr = float('inf')
    else:
        comp_sqnr = 10 * np.log10(compensated_signal_power / true_noise_power)
        
    return {
        "sqnr_raw_db": raw_sqnr,
        "sqnr_compensated_db": comp_sqnr,
        "measured_gain": gain,
        "attenuation_percent": (1 - gain) * 100
    }

def sqnr(original, quantized):
    # Signal power is the mean of the squared original signal
    signal_power = np.mean(original ** 2)
    
    # Quantization noise power is the mean of the squared difference
    noise_power = np.mean((original - quantized) ** 2)
    
    if noise_power == 0:
        return float('inf') # Infinite SQNR if there's no quantization error
        
    sqnr_val = 10 * np.log10(signal_power / noise_power)
    return sqnr_val

def compare_results(Data_width):
    # Load data
    out = load_file("../Data/fft_output.txt")
    correct = load_file(f"../Data/correct_output.txt")

    out_real = out[:, 0]
    out_imag = out[:, 1]
    correct_real = correct[:, 0]
    correct_imag = correct[:, 1]

    max_value = 2**(Data_width - 1) - 1
    stats_real  = advanced_sqnr(correct_real, out_real)
    stats_imag = advanced_sqnr(correct_imag, out_imag)

    if __debug__:
        print(f"SQNR (Real): {stats_real['sqnr_compensated_db']:.2f} dB")
        print(f"SQNR (Imag): {stats_imag['sqnr_compensated_db']:.2f} dB")
    return stats_real['sqnr_compensated_db'], stats_imag['sqnr_compensated_db']

def analyze_vector_advanced(a, fs=1.0):
    """
    Analyzes time and frequency domain characteristics of a vector.
    
    Parameters:
        a (array_like): The input signal vector.
        fs (float): The sampling frequency in Hz (defaults to 1.0 for normalized frequencies).
    """
    arr = np.asarray(a).flatten()
    N = len(arr)
    
    # --- Time-Domain Characteristics ---
    characteristics = {
        "length": N,
        "mean": np.mean(arr),
        "variance": np.var(arr),
        "std_dev": np.std(arr),
        "min_val": np.min(arr),
        "max_val": np.max(arr),
        "peak_to_peak": np.ptp(arr),
        "energy": np.sum(np.abs(arr)**2),
        "rms": np.sqrt(np.mean(np.abs(arr)**2))
    }
    
    # --- Frequency-Domain Characteristics ---
    # Automatically handle both real and complex input vectors
    if np.iscomplexobj(arr):
        fft_vals = np.fft.fft(arr)
        freqs = np.fft.fftfreq(N, d=1/fs)
    else:
        fft_vals = np.fft.rfft(arr)
        freqs = np.fft.rfftfreq(N, d=1/fs)
        
    # Calculate magnitude spectrum (normalized by N)
    magnitudes = np.abs(fft_vals) / N
    
    # 1. DC Component (Magnitude at 0 Hz)
    characteristics["dc_magnitude"] = magnitudes[0]
    
    # 2. Dominant Frequency (Highest peak excluding the DC component)
    if len(magnitudes) > 1:
        peak_idx = np.argmax(magnitudes[1:]) + 1
        characteristics["dominant_freq_hz"] = freqs[peak_idx]
        characteristics["dominant_magnitude"] = magnitudes[peak_idx]
        
        # 3. Spectral Centroid (Center of mass of the spectrum)
        # Adding a tiny epsilon (1e-12) to avoid division by zero if array is all zeros
        centroid = np.sum(freqs * magnitudes) / (np.sum(magnitudes) + 1e-12)
        characteristics["spectral_centroid_hz"] = centroid
    else:
        characteristics["dominant_freq_hz"] = 0
        characteristics["dominant_magnitude"] = 0
        characteristics["spectral_centroid_hz"] = 0
        
    return characteristics
    
def main(N, Data_width, Tw_width=8, Num_of_windows=1, type_fft=0, iterations=10, signal_mode="random", bit_growth=0, SimpleMult=0, Fast_DSP=0, 
         carry_save=0, Bram=1, output_pipeline_bram=0, input_pipeline_bram=0, Cshm=0, waves=False):
    if __debug__:
        if(type_fft == 0):
            print(f"Radix-2 FFT")
        elif(type_fft == 1):
            print(f"Radix-4 FFT")
        else:
           print(f"Split-Radix FFT")

    min_psnr_real = float('inf')
    min_psnr_imag = float('inf')

    max_psnr_real = float('-inf')
    max_psnr_imag = float('-inf')

    total_psnr_real = 0
    total_psnr_imag = 0

    enc = CSHMEncoder(bit_width=Tw_width, alphabets=4, num_slots=2, tolerance_per=0.004)
    Key_width = enc.word_bits


    if(bit_growth == 1):
        snapshot = compile_simulation_xsim(Data_width, Tw_width=Tw_width, type_fft=type_fft, bit_growth=bit_growth, N=N,window_size=Num_of_windows, SimpleMult=SimpleMult, 
                                           Fast_DSP=Fast_DSP, carry_save=carry_save, Bram=Bram, output_pipeline_bram=output_pipeline_bram, 
                                           input_pipeline_bram=input_pipeline_bram, Cshm=Cshm, Key_width=Key_width, waves=waves)
    else:
        compile_simulation_verilator(Data_width, Tw_width=Tw_width, type_fft=type_fft, N=N, window_size=Num_of_windows, SimpleMult=SimpleMult, 
                                     Fast_DSP=Fast_DSP, carry_save=carry_save, Bram=Bram, bit_growth=bit_growth, output_pipeline_bram=output_pipeline_bram, 
                                     input_pipeline_bram=input_pipeline_bram, Cshm=Cshm, Key_width=Key_width, waves=waves)

    if Cshm == 1:
        generate_twiddles(N=N, twiddle_width=Tw_width, type_fft=type_fft, cshm=enc)
    else:
        generate_twiddles(N=N, twiddle_width=Tw_width, type_fft=type_fft, cshm=None)

    for i in range(iterations):
        input = generate_input_output(Num_of_windows, N, Tw_width, type_fft, signal_mode)
        
        if(bit_growth == 1):
            run_simulation_xsim(snapshot_name=snapshot, waves=waves)
        else:
            run_simulation_verilator(type_fft=type_fft)

        real_psnr, imag_psnr = compare_results(Data_width)

        total_psnr_real += real_psnr
        total_psnr_imag += imag_psnr

        if real_psnr < min_psnr_real:
            min_psnr_real = real_psnr
            min_input_real = input.real
        if imag_psnr < min_psnr_imag:
            min_psnr_imag = imag_psnr
            min_input_imag = input.imag
        if real_psnr > max_psnr_real:
            max_psnr_real = real_psnr
            max_input_real = input.real
        if imag_psnr > max_psnr_imag:
            max_psnr_imag = imag_psnr
            max_input_imag = input.imag

    lat1, lat2 = read_values()

    print(f"Minimum PSNR (Real): {min_psnr_real:.2f} dB")
    print(f"Minimum PSNR (Imag): {min_psnr_imag:.2f} dB")
    print(f"Maximum PSNR (Real): {max_psnr_real:.2f} dB")
    print(f"Maximum PSNR (Imag): {max_psnr_imag:.2f} dB")
    print(f"Average PSNR (Real): {total_psnr_real/iterations:.2f} dB")
    print(f"Average PSNR (Imag): {total_psnr_imag/iterations:.2f} dB")
    print(f"Latency FIFO: {lat1} clock cycles")
    print(f"Latency FILO: {lat2} clock cycles")

    # characteristics_min_real = analyze_vector_advanced(min_input_real)
    # characteristics_min_imag = analyze_vector_advanced(min_input_imag)
    # characteristics_max_real = analyze_vector_advanced(max_input_real)
    # characteristics_max_imag = analyze_vector_advanced(max_input_imag)

if __name__ == "__main__":
    clean_data_folder()
    
    #main(N=256, Data_width=25, Tw_width = 16, Num_of_windows=100, type_fft=0, iterations=10, signal_mode="random", bit_growth=1, Bram=0, Cshm=1, waves=False)
    #main(N=256, Data_width=25, Tw_width = 16, Num_of_windows=100, type_fft=0, iterations=10, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, Cshm=0, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=100, type_fft=1, iterations=10, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, Cshm=1, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=100, type_fft=1, iterations=10, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, Cshm=0, waves=False)
    main(N=256, Data_width=17, Tw_width = 9, Num_of_windows=100, type_fft=2, iterations=10, signal_mode="random", bit_growth=0, SimpleMult=1, Fast_DSP=0, carry_save=0, Bram=0, Cshm=1, output_pipeline_bram=0, input_pipeline_bram=1, waves=False)
    main(N=256, Data_width=17, Tw_width = 9, Num_of_windows=100, type_fft=2, iterations=10, signal_mode="random", bit_growth=0, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, Cshm=0, output_pipeline_bram=0, input_pipeline_bram=1, waves=False)
   
    

    






