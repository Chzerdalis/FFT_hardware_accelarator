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

    
def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0):
    if type_fft == 0:
        stages = int(math.log2(N))
    elif type_fft == 1:
        stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
    #max_stage_num = twiddle_width + 1
    #Current_bits_stages = min(stages, max_stage_num)
    #bit_growth_stages = max(0, stages - max_stage_num)

    k = np.arange(N)
    twiddles = np.exp(-2j * np.pi * k / N)

    real_file_r2 = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
    imag_file_r2 = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

    real_file_r4_1 = lambda stage: f"../Data/f_twiddle_real_{stage}_1.mem"
    imag_file_r4_1 = lambda stage: f"../Data/f_twiddle_imag_{stage}_1.mem"

    real_file_r4_2 = lambda stage: f"../Data/f_twiddle_real_{stage}_2.mem"
    imag_file_r4_2 = lambda stage: f"../Data/f_twiddle_imag_{stage}_2.mem"

    real_file_r4_3 = lambda stage: f"../Data/f_twiddle_real_{stage}_3.mem"
    imag_file_r4_3 = lambda stage: f"../Data/f_twiddle_imag_{stage}_3.mem"

    # =========================================================================
    # Fallback for No Bit Growth
    # =========================================================================
    # Calculate scaling once for the static width
    fractional_bits = twiddle_width - 1
    scale_factor = 1 << fractional_bits
    min_val = -scale_factor
    max_val = scale_factor - 1
    mask = (1 << twiddle_width) - 1

    twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
    twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask

    for stage in range(1, stages + 1):
        if (type_fft == 0): 
            real_q = twiddle_real[0 : N // 2]
            imag_q = twiddle_imag[0 : N // 2]

            stride = (N // 2) // 2**(stage-1)
            iter_count = 2**(stage-1)

            temp_real = []
            temp_imag = []

            for j in range(0, iter_count):
                temp_real.append(real_q[stride*j])
                temp_imag.append(imag_q[stride*j])

            hex_chars = (twiddle_width + 3) // 4
            with open(real_file_r2(stage), "w") as f_real:
                for value in temp_real:
                    f_real.write(f"{value:0{hex_chars}X}\n")

            with open(imag_file_r2(stage), "w") as f_imag:
                for value in temp_imag:
                    f_imag.write(f"{value:0{hex_chars}X}\n")
        elif (type_fft == 1): 
            real_q = twiddle_real
            imag_q = twiddle_imag

            stride = (N // 4) // 4**(stage-1)
            iter_count = 4**(stage-1)

            temp_real_1 = []
            temp_imag_1 = []
            temp_real_2 = []
            temp_imag_2 = []
            temp_real_3 = []
            temp_imag_3 = []

            for j in range(0, iter_count):
                temp_real_1.append(real_q[stride*j])
                temp_imag_1.append(imag_q[stride*j])
            
            for j in range(0, iter_count):
                temp_real_2.append(real_q[stride*j*2])
                temp_imag_2.append(imag_q[stride*j*2])

            for j in range(0, iter_count):
                temp_real_3.append(real_q[stride*j*3])
                temp_imag_3.append(imag_q[stride*j*3])

            hex_chars = (twiddle_width + 3) // 4

            with open(real_file_r4_1(stage), "w") as f_real:
                for value in temp_real_1:
                    f_real.write(f"{value:0{hex_chars}X}\n")

            with open(imag_file_r4_1(stage), "w") as f_imag:
                for value in temp_imag_1:
                    f_imag.write(f"{value:0{hex_chars}X}\n")

            with open(real_file_r4_2(stage), "w") as f_real:
                for value in temp_real_2:
                    f_real.write(f"{value:0{hex_chars}X}\n")

            with open(imag_file_r4_2(stage), "w") as f_imag:
                for value in temp_imag_2:
                    f_imag.write(f"{value:0{hex_chars}X}\n")

            with open(real_file_r4_3(stage), "w") as f_real:
                for value in temp_real_3:
                    f_real.write(f"{value:0{hex_chars}X}\n")

            with open(imag_file_r4_3(stage), "w") as f_imag:
                for value in temp_imag_3:
                    f_imag.write(f"{value:0{hex_chars}X}\n")

            with open(real_file_r2(stage), "w") as f_real:
                for value in real_q:
                    f_real.write(f"{value:0{hex_chars}X}\n")

            with open(imag_file_r2(stage), "w") as f_imag:
                for value in imag_q:
                    f_imag.write(f"{value:0{hex_chars}X}\n")


    if __debug__:
        print(f"Generated twiddles for {stages} stages.")

    # Return the base twiddles for reference
    return twiddles.real, twiddles.imag

# def generate_twiddle_pkg(N, src_dir, type_fft=0):
#     if type_fft == 0:
#         stages = int(math.log2(N))
#     elif type_fft == 1:
#         stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages

#     real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#     imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

#     # 1. Generate the REAL file macro tree
#     pkg_content = "`define GET_REAL_FILE(idx) \\\n"
#     for stage in range(1, stages + 1):
#         pkg_content += f"    ((idx) == {stage-1}) ? \"{real_file(stage)}\" : \\\n"
#     pkg_content += f"    \"{real_file(1)}\"\n\n" # Default fallback

#     # 2. Generate the IMAG file macro tree
#     pkg_content += "`define GET_IMAG_FILE(idx) \\\n"
#     for stage in range(1, stages + 1):
#         pkg_content += f"    ((idx) == {stage-1}) ? \"{imag_file(stage)}\" : \\\n"
#     pkg_content += f"    \"{imag_file(1)}\"\n\n" # Default fallback

#     # Write to a header file
#     filepath = f"{src_dir}twiddle_pkg.vh"
#     with open(filepath, "w") as f:
#         f.write(pkg_content)
        
#     print(f"Generated {filepath} with ternary macros for {stages} stages.")

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
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

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

    else:
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

    # Write to a header file
    filepath = f"{src_dir}twiddle_pkg.vh"
    with open(filepath, "w") as f:
        f.write(pkg_content)

    radix = "radix-2" if type_fft == 0 else "radix-4"
    per_stage = 1 if type_fft == 0 else 3
    print(
        f"Generated {filepath} with ternary macros for {stages} {radix} "
        f"stages ({per_stage} twiddle pair(s) per stage)."
    )
    
def compile_simulation(Data_width=16, N=256, window_size=1):
    # 1. Define the source directory and files
    src_dir = "../Radix-2/"
    
    design_files = [
        f"{src_dir}butterfly.v",
        f"{src_dir}delay_buffer.v",
        f"{src_dir}stage_unit.sv",
        f"{src_dir}tb_top_radix_2.v",
        f"{src_dir}fft_radix_2_top.sv"
    ]
    
    parameters_file = [
        f"-Ptb_radix2_top.WIDTH={Data_width}", 
        f"-Ptb_radix2_top.Num_of_samples={N}",
        f"-Ptb_radix2_top.MAX_FILE_SAMPLES={window_size * N + 1000}",
    ] 


    # 2. Compile the Verilog files
    print("Compiling...")
    compile_cmd = ["iverilog", "-o", "sim.vvp", "-g2012"] + design_files + parameters_file
    
    result = subprocess.run(compile_cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("Compilation failed!")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
        sys.exit(1)

def compile_simulation_verilator(Data_width=16, Tw_width=8, N=256, type_fft=0, window_size=1, SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=1, bit_growth=0, output_pipeline_bram=0, waves=False):
    # 1. Define the source directory and files
    if type_fft == 0:
        src_dir = "../Radix-2/"
    elif type_fft == 1:
        src_dir = "../Radix-4/"
    
    generate_twiddle_pkg(N, src_dir, type_fft) 

    if(type_fft == 0):
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
    
        # Verilator uses -G to override top-level parameters
        parameters = [
            f"-GWIDTH={Data_width}", 
            f"-GNum_of_samples={N}",
            f"-GTw_WIDTH={Tw_width}",
            f"-GMAX_FILE_SAMPLES={window_size * N + 1000}",
            f"-GSimpleMult={SimpleMult}",
            f"-GFast_DSP={Fast_DSP}",
            f"-Gcarry_save={carry_save}",
            f"-GBram={Bram}",
            f"-Gbit_growth={bit_growth}"
        ]
    elif(type_fft == 1):
        design_files = [
            f"{src_dir}butterfly.v",
            f"{src_dir}memory.v",
            f"{src_dir}stage_unit.sv",
            f"{src_dir}tb_top_radix_4.v",
            f"{src_dir}fft_radix_4_top.sv",
            f"{src_dir}delay_reg.v",
            f"{src_dir}Carry_mult.v"
        ]
    
        # Verilator uses -G to override top-level parameters
        parameters = [
            f"-GWIDTH={Data_width}", 
            f"-GNum_of_samples={N}",
            f"-GTw_WIDTH={Tw_width}",
            f"-GBram={Bram}",
            f"-GSimpleMult={SimpleMult}",
            f"-GFast_DSP={Fast_DSP}",
            f"-Gcarry_save={carry_save}",
            f"-Goutput_pipeline_bram={output_pipeline_bram}",
            f"-Gbit_growth={bit_growth}",
            f"-GMAX_FILE_SAMPLES={window_size * N + 1000}"
        ]
    
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

def compile_simulation_xsim(Data_width=16, Tw_width=8, N=256, type_fft=0, window_size=1, SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=1, bit_growth=0, output_pipeline_bram=0, waves=False):
    # 1. Define the source directory and files based on type_fft
    if type_fft == 0:
        src_dir = "../Radix-2/"
    elif type_fft == 1:
        src_dir = "../Radix-4/"
    
    generate_twiddle_pkg(N, src_dir, type_fft) 

    if type_fft == 0:
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

    elif type_fft == 1:
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
         carry_save=0, Bram=1, output_pipeline_bram=0, waves=False):
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

    if(bit_growth == 1):
        snapshot = compile_simulation_xsim(Data_width, Tw_width, type_fft=type_fft, N=N, window_size=Num_of_windows, SimpleMult=SimpleMult, Fast_DSP=Fast_DSP, carry_save=carry_save, Bram=Bram, bit_growth=bit_growth, waves=waves)
    else:
        compile_simulation_verilator(Data_width, Tw_width, type_fft=type_fft, N=N, window_size=Num_of_windows, SimpleMult=SimpleMult, Fast_DSP=Fast_DSP, carry_save=carry_save, Bram=Bram, bit_growth=bit_growth, output_pipeline_bram=output_pipeline_bram, waves=waves)
    generate_twiddles(N, Tw_width, type_fft, bit_growth)

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
    main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=100, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, waves=False)
    # main(N=1024, Data_width=11, Tw_width = 9, Num_of_windows=60, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=1, carry_save=0, Bram=1, output_pipeline_bram=1, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=40, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=1, output_pipeline_bram=0, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=40, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=1, carry_save=0, Bram=1, output_pipeline_bram=1, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=40, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=0, Fast_DSP=1, carry_save=0, Bram=1, output_pipeline_bram=1, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=40, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0, output_pipeline_bram=0, waves=False)
    # main(N=256, Data_width=11, Tw_width = 9, Num_of_windows=40, type_fft=1, iterations=1, signal_mode="random", bit_growth=1, SimpleMult=0, Fast_DSP=0, carry_save=1, Bram=0, output_pipeline_bram=0, waves=False)





