import numpy as np
import math
import subprocess
import sys
import os
import shutil

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

def generate_input_output(Num_of_windows, N, Data_width, type_fft=0, signal_mode="random"):

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

    #Quantize the input data based on the specified Data_width
    component_width = Data_width // 2
    
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

    
def generate_twiddles(N, twiddle_width, type_fft=0):
    twiddles = []

    k = np.arange(N)
    twiddles = np.exp(-2j * np.pi * k / N)
        
    fractional_bits = twiddle_width - 1
    scale_factor = 1 << fractional_bits       # e.g., 1 << 15 for 16-bit
    
    min_val = -scale_factor                   # e.g., -32768 for 16-bit
    max_val = scale_factor - 1                # e.g., 32767 for 16-bit
    mask = (1 << twiddle_width) - 1           # e.g., 0xFFFF for 16-bit

    twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
    twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask

    idx_real = np.arange(len(twiddle_real))
    idx_imag = np.arange(len(twiddle_imag))

    real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
    imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

    for stage in range(1, int(math.log2(N)) + 1):
        if(type_fft == 0): 
            real_q = twiddle_real[0 : N // 2]
            idx_real = idx_real[0 : N // 2]
            
            imag_q = twiddle_imag[0 : N // 2]
            idx_imag = idx_imag[0 : N // 2]

            stride = (N // 2) // 2**(stage-1)
            iter = 2**(stage-1)

            temp_real, temp_idx_real = [], []
            temp_imag, temp_idx_imag = [], []

            for j in range(0, iter):
                temp_real.append(real_q[stride*j])
                temp_idx_real.append(idx_real[stride*j])
                
                temp_imag.append(imag_q[stride*j])
                temp_idx_imag.append(idx_imag[stride*j])


            # print(temp_idx_real)
            # print(temp_idx_imag)

            with open(real_file(stage), "w") as f_real:
                for value in temp_real:
                    f_real.write(f"{value:0{(twiddle_width + 3)//4}X}\n")

            with open(imag_file(stage), "w") as f_imag:
                for value in temp_imag:
                    f_imag.write(f"{value:0{(twiddle_width + 3)//4}X}\n")

    # twiddle_real = twiddle_real[:len(twiddle_real)//2]
    # twiddle_imag = twiddle_imag[:len(twiddle_imag)//2]

    # with open("../Data/f_twiddle_real.mem", "w") as f_real:
    #     for value in twiddle_real:
    #         f_real.write(f"{value:0{(twiddle_width + 3)//4}X}\n")

    # with open("../Data/f_twiddle_imag.mem", "w") as f_imag:
    #     for value in twiddle_imag:
    #         f_imag.write(f"{value:0{(twiddle_width + 3)//4}X}\n")


    if __debug__:
        print(f"Generated: {real_file}")
        print(f"Generated: {imag_file}")


    return twiddle_real, twiddle_imag

import math

def generate_twiddle_pkg(N, src_dir):
    # Calculate the number of stages (log2 of N)
    stages = int(math.log2(N))
    pkg_path = f"{src_dir}twiddle_pkg.sv"
    
    with open(pkg_path, "w") as f:
        f.write("package twiddle_pkg;\n")
        f.write(f"    parameter int STAGE_NUM = {stages};\n\n")
        
        # Generate the REAL_FILES array
        f.write(f"    parameter string REAL_FILES [0:{stages-1}] = '{{\n")
        real_files = [f'        "../Data/f_twiddle_real_{i+1}.mem"' for i in range(stages)]
        f.write(",\n".join(real_files))
        f.write("\n    };\n\n")
        
        # Generate the IMAG_FILES array
        f.write(f"    parameter string IMAG_FILES [0:{stages-1}] = '{{\n")
        imag_files = [f'        "../Data/f_twiddle_imag_{i+1}.mem"' for i in range(stages)]
        f.write(",\n".join(imag_files))
        f.write("\n    };\n")
        
        f.write("endpackage\n")
        
    print(f"Generated {pkg_path} for {stages} stages.")
    return pkg_path

def compile_simulation(Data_width=16, N=256, window_size=1):
    # 1. Define the source directory and files
    src_dir = "../Radix-2/"
    
    design_files = [
        f"{src_dir}butterfly.v",
        f"{src_dir}delay_buffer.v",
        f"{src_dir}stage_unit.v",
        f"{src_dir}tb_top_radix_2.v",
        f"{src_dir}fft_radix_2_top.v"
    ]
    
    parameters_file = [
        f"-Ptb_radix2_top.WIDTH={Data_width}", 
        f"-Ptb_radix2_top.Num_of_samples={N}",
        f"-Ptb_radix2_top.MAX_FILE_SAMPLES={window_size * N + 1000}",
    ] 


    # 2. Compile the Verilog files
    print("Compiling...")
    compile_cmd = ["iverilog", "-o", "sim.vvp", "-g2012"] + design_files + parameters_file
    
    result = subprocess.run(compile_cmd)
    if result.returncode != 0:
        print("Compilation failed!")
        sys.exit(1)

def compile_simulation_verilator(Data_width=16, N=256, window_size=1, waves=False):
    # 1. Define the source directory and files
    src_dir = "../Radix-2/"
    

    generate_twiddle_pkg(256, src_dir) 

    design_files = [
        f"{src_dir}twiddle_pkg.sv",
        f"{src_dir}butterfly.v",
        f"{src_dir}delay_buffer.v",
        f"{src_dir}stage_unit.sv",
        f"{src_dir}tb_top_radix_2.v",
        f"{src_dir}fft_radix_2_top.sv",
        f"{src_dir}delay_reg.v",
        f"{src_dir}Carry_mult.v",
    ]
    
    # Verilator uses -G to override top-level parameters
    parameters = [
        f"-GWIDTH={Data_width}", 
        f"-GNum_of_samples={N}",
        f"-GMAX_FILE_SAMPLES={window_size * N + 1000}"
    ]
    
    if __debug__:
        print("Compiling with Verilator...")

    if waves:
        compile_cmd = [
            "verilator", 
            "--binary",       # Builds the C++ executable automatically
            "--timing",       # Supports standard Verilog #delays in the testbench
            "--trace",
            "-Wno-fatal",     # Prevents minor linting warnings from failing the build
            "--top", "tb_radix2_top"
        ] + parameters + design_files
    else:
        compile_cmd = [
            "verilator", 
            "--binary",       # Builds the C++ executable automatically
            "--timing",       # Supports standard Verilog #delays in the testbench
            "-Wno-fatal",     # Prevents minor linting warnings from failing the build
            "--top", "tb_radix2_top"
        ] + parameters + design_files
    
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("Compilation failed!")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
        sys.exit(1)

def run_simulation_verilator():
    if __debug__:
        print("Running simulation...")
    # Verilator outputs the executable into 'obj_dir', prefixed with 'V'
    sim_cmd = ["./obj_dir/Vtb_radix2_top"]
    
    result = subprocess.run(sim_cmd, capture_output=False, text=True)
    
    if result.returncode != 0:
        print("--- SIMULATION FAILED ---")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
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


def psnr(original, compressed, max_val):
    mse = np.mean((original - compressed) ** 2)
    if mse == 0:
        return 100
    psnr_val = 20 * np.log10(max_val) - 10 * np.log10(mse)
    return psnr_val

def compare_results(Data_width):
    # Load data
    out = load_file("../Data/fft_output.txt")
    correct = load_file(f"../Data/correct_output.txt")

    out_real = out[:, 0]
    out_imag = out[:, 1]
    correct_real = correct[:, 0]
    correct_imag = correct[:, 1]

    max_value = 2**(Data_width - 1) - 1
    psnr_real = psnr(correct_real, out_real, max_value)
    psnr_imag = psnr(correct_imag, out_imag, max_value)

    if __debug__:
        print(f"PSNR (Real): {psnr_real:.2f} dB")
        print(f"PSNR (Imag): {psnr_imag:.2f} dB")

    return psnr_real, psnr_imag

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
    
def main(N, Data_width, Num_of_windows=1, type_fft=0, iterations=10, signal_mode="random", waves=False):
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

    compile_simulation_verilator(Data_width, N, Num_of_windows)
    generate_twiddles(N, Data_width//2)

    for i in range(iterations):
        input = generate_input_output(Num_of_windows, N, Data_width, type_fft, signal_mode="low")
        run_simulation_verilator()
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

    print(f"Minimum PSNR (Real): {min_psnr_real:.2f} dB")
    print(f"Minimum PSNR (Imag): {min_psnr_imag:.2f} dB")
    print(f"Maximum PSNR (Real): {max_psnr_real:.2f} dB")
    print(f"Maximum PSNR (Imag): {max_psnr_imag:.2f} dB")
    print(f"Average PSNR (Real): {total_psnr_real/iterations:.2f} dB")
    print(f"Average PSNR (Imag): {total_psnr_imag/iterations:.2f} dB")

    characteristics_min_real = analyze_vector_advanced(min_input_real)
    characteristics_min_imag = analyze_vector_advanced(min_input_imag)
    characteristics_max_real = analyze_vector_advanced(max_input_real)
    characteristics_max_imag = analyze_vector_advanced(max_input_imag)

    # print("\nCharacteristics of Input Vector with Minimum PSNR (Real):")
    # for key, value in characteristics_min_real.items():
    #     print(f"{key}: {value}")

    # print("\nCharacteristics of Input Vector with Minimum PSNR (Imag):")
    # for key, value in characteristics_min_imag.items():
    #     print(f"{key}: {value}")

    # print("\nCharacteristics of Input Vector with Maximum PSNR (Real):")
    # for key, value in characteristics_max_real.items():
    #     print(f"{key}: {value}")

    # print("\nCharacteristics of Input Vector with Maximum PSNR (Imag):")
    # for key, value in characteristics_max_imag.items():
    #     print(f"{key}: {value}")

if __name__ == "__main__":

    clean_data_folder("../Data")
    # print("LOW")
    # main(256, 16, 1, 1, 0, 1000, "low")
    # print("MIXED")
    # main(256, 16, 1, 1, 0, 1000, "mixed")
    # print("HIGH")
    # main(256, 16, 1, 1, 0, 1000, "high")
    # print("RANDOM")
    main(256, 16, 1, 0, 100, "stress", waves=False)
    # main(1024, 18, 1, 1, 0, 100, "stress")
    # main(4096, 24, 1, 1, 0, 100, "stress")


