import numpy as np
import itertools
import math
import sys

def quantize_twiddles(twiddles, bit_width, type_fft="radix-2", fft_size=16, stage=1):
    """
    Quantizes complex floating-point twiddle factors to a specified bit width 
    using Two's Complement representation. Also it chooses the twiddle factors based on the FFT type and stage.
    """

    if 2**stage > fft_size and type_fft in ["radix-2", "split-radix"]:
        raise ValueError(f"Stage {stage} is too large for FFT size {fft_size}. Maximum stage is {int(np.log2(fft_size))}.")
    elif 4**stage > fft_size and type_fft == "radix-4":
        raise ValueError(f"Stage {stage} is too large for FFT size {fft_size}. Maximum stage is {int(np.log4(fft_size))}.")

    # 1. The scale factor (fractional bits)
    fractional_bits = bit_width - 1
    scale_factor = 1 << fractional_bits
    
    # 2. The clipping boundaries
    min_val = -scale_factor               
    max_val = scale_factor - 1            
    
    # 3. Apply the math
    real_q = np.clip(np.round(twiddles.real * scale_factor), min_val, max_val).astype(int)
    imag_q = np.clip(np.round(twiddles.imag * scale_factor), min_val, max_val).astype(int)

    # 4. Create arrays to track the ORIGINAL indices
    idx_real = np.arange(len(real_q))
    idx_imag = np.arange(len(imag_q))

    """Pick twiddle factors based on FFT type and it's stage"""
    if type_fft == "radix-2":
        real_q = real_q[0 : fft_size // 2]
        idx_real = idx_real[0 : fft_size // 2]
        
        imag_q = imag_q[0 : fft_size // 2]
        idx_imag = idx_imag[0 : fft_size // 2]

        stride = (fft_size // 2) // 2**(stage-1)
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

        real_q = np.array(temp_real)
        imag_q = np.array(temp_imag)
        
    elif type_fft == "radix-4":
        real_q = real_q[0 : 3 * fft_size // 4 - 2]
        idx_real = idx_real[0 : 3 * fft_size // 4 - 2]
        
        imag_q = imag_q[0 : 3 * fft_size // 4 - 2]
        idx_imag = idx_imag[0 : 3 * fft_size // 4 - 2]

        temp_real_0, temp_idx_real_0 = [], []
        temp_imag_0, temp_idx_imag_0 = [], []

        temp_real_1, temp_idx_real_1 = [], []
        temp_imag_1, temp_idx_imag_1 = [], []

        temp_real_2, temp_idx_real_2 = [], []
        temp_imag_2, temp_idx_imag_2 = [], []

        stride = (fft_size // 4) // 4**(stage-1)
        iter = 4**(stage-1)

        for j in range(0, iter):
            temp_real_0.append(real_q[stride*j])
            temp_idx_real_0.append(idx_real[stride*j])
            
            temp_imag_0.append(imag_q[stride*j])
            temp_idx_imag_0.append(idx_imag[stride*j])

            temp_real_1.append(real_q[2*stride*j])
            temp_idx_real_1.append(idx_real[2*stride*j])
            
            temp_imag_1.append(imag_q[2*stride*j])
            temp_idx_imag_1.append(idx_imag[2*stride*j])

            temp_real_2.append(real_q[3*stride*j])
            temp_idx_real_2.append(idx_real[3*stride*j])
            
            temp_imag_2.append(imag_q[3*stride*j])
            temp_idx_imag_2.append(idx_imag[3*stride*j])

        # print(temp_idx_real_0)
        # print(temp_idx_real_1)
        # print(temp_idx_real_2)

        real_q = np.concatenate((temp_real_0, temp_real_1, temp_real_2))
        imag_q = np.concatenate((temp_imag_0, temp_imag_1, temp_imag_2))
        
    elif type_fft == "split-radix":
        # Concatenate values
        # real_q = np.concatenate((real_q[0 : fft_size // 4], real_q[0 : 3 * fft_size // 4 : 3]))
        # imag_q = np.concatenate((imag_q[0 : fft_size // 4], imag_q[0 : 3 * fft_size // 4 : 3]))
        
        # idx_real = np.concatenate((idx_real[0 : fft_size // 4], idx_real[0 : 3 * fft_size // 4 : 3]))
        # idx_imag = np.concatenate((idx_imag[0 : fft_size // 4], idx_imag[0 : 3 * fft_size // 4 : 3]))

        #print(real_q)

        temp_real_0, temp_idx_real_0 = [], []
        temp_imag_0, temp_idx_imag_0 = [], []

        temp_real_1, temp_idx_real_1 = [], []
        temp_imag_1, temp_idx_imag_1 = [], []

        stride_0 = 2**(stage-2)
        stride_1 = 3*stride_0
        iter = (fft_size)//(2**(stage))

        #print(idx_real)

        for j in range(iter):
            #print(f"j {j}")
            #print(f"Stride0 {stride_0} Stride1 {stride_1}")
            temp_real_0.append(real_q[stride_0*j])
            temp_idx_real_0.append(idx_real[stride_0*j])
                
            temp_imag_0.append(imag_q[stride_0*j])
            temp_idx_imag_0.append(idx_imag[stride_0*j])

            temp_real_1.append(real_q[stride_1*j])
            temp_idx_real_1.append(idx_real[stride_1*j])
                
            temp_imag_1.append(imag_q[stride_1*j])
            temp_idx_imag_1.append(idx_imag[stride_1*j])

            #print(idx_real[stride_0*j])
            #print(idx_real[stride_1*j])

        #print(temp_idx_real_0)
        #print(temp_idx_real_1)

        real_q = np.concatenate((temp_real_0, temp_real_1))
        imag_q = np.concatenate((temp_imag_0, temp_imag_1))

    # 5. Finally, zip them together into lists of tuples: [(original_index, value), ...]
    return real_q, imag_q

def find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=3, max_alphabet_size=8, fft_size=16, type_fft="radix-2", stage=1, bit_width=8, tolerance_per=0):
    """
    Finds the best possible combination og alphabets and slots for a given FFT size, 
    type, stage, and bit width. It checks if the hardware can generate all required twiddle factors within a specified tolerance.
    """
    
    signs = [1, -1]
    
    k = np.arange(fft_size)
    twiddles = np.exp(-2j * np.pi * k / fft_size)

    #print(twiddles)

    if(fft_type == "split-radix" and stage==1):
        return

    # The required integers for this bit-width
    if type_fft == "everything":
        target_range = set(range(-2**(bit_width-1), 2**(bit_width-1)))
    else:
        print(f"\nQuantizing twiddles for {bit_width}-bit width, FFT Size: {fft_size}, Type: {type_fft}, Stage: {stage}")
        real_quantized, imag_quantized = quantize_twiddles(twiddles, bit_width, type_fft=type_fft, fft_size=fft_size, stage=stage)
        target_range = set(real_quantized.tolist() + imag_quantized.tolist())


    # Calculate the tolerance window for this bit-width
    max_target_val = max(abs(t) for t in target_range) if target_range else 0
    tolerance = tolerance_per * max_target_val

    shifts = range(bit_width)
    
    print(f"\n{'='*60}")
    print(f"Evaluating {bit_width}-bit twiddles ({2*bit_width}-bit Data width) (FFT Size: {fft_size}), Type: {type_fft}, Stage: {stage}")
    print(f"Target Range: {len(target_range)} unique values")
    print(f"Tolerance:    +/- {tolerance_per*100:.2f}% | Max Tolerance: {tolerance:.2f}")
    print(f"{'='*60}")

    
    for num_slots in range(2, max_slots + 1):
        print(f"\n--- Testing Hardware with {num_slots} Slots ---")
        
        for alphabet_size in range(1, max_alphabet_size + 1):
            # Generate odd alphabets: 0 is included to simulate turning a slot "off"
            alphabets = [2 * n + 1 for n in range(alphabet_size)]
            
            # Step 1: Generate all possible values for a SINGLE slot
            single_slot_values = set()
            for alpha in alphabets:
                for shift in shifts:
                    for sign in signs:
                        single_slot_values.add(sign * (alpha << shift))
            
            # Step 2: Combine slots to find all possible numbers this hardware can make
            # itertools.combinations_with_replacement simulates picking 'num_slots' values
            n_slot_values = set(
                sum(combo) for combo in itertools.combinations_with_replacement(single_slot_values, num_slots)
            )
            
            # Step 3: Check if our generated numbers cover the entire target range WITH TOLERANCE
            missing_values = set()
            for target in target_range:
                # If NO generated hardware value falls within the +/- tolerance of the target, mark it missing
                if not any(abs(val - target) <= tolerance for val in n_slot_values):
                    missing_values.add(target)
            
            if not missing_values:
                print(f" -> SUCCESS: {num_slots} Slots | Min Alphabet: {alphabets}")
                break  # Stop checking larger alphabets for this slot count
            else:
                # Optional: Print how many gaps are left before trying a bigger alphabet
                print(f"    Failed: Alphabet {alphabets} left {len(missing_values)} gaps.")
        
        if missing_values:
            print(f" -> ERROR: {num_slots} slots cannot cover {bit_width}-bit numbers even with a {max_alphabet_size}-element alphabet.")


def find_cshm_instructions_2(fft_size=16, bit_width=8, type_fft="radix-2", stage=1, alphabets=0, num_slots=2, tolerance_per=0):
    """Given a specific FFT size, bit width, type, alphabets and slots, this function checks if the hardware 
    can generate all required twiddle factors within a specified tolerance. It also prints the resulting equations 
    and their corresponding bit encodings.""" 

    # Default alphabet if none is provided (remember to include 0!)
    if alphabets == 0:
        raise ValueError("Alphabets must be greater than 0. Please provide a valid alphabet size.")
    else:
        alphabets = [2 * n + 1 for n in range(alphabets)] 
        
    shifts = range(bit_width)
    signs = [1, -1] 

    # 1. Generate the targets using your quantization function
    # (Assuming quantize_twiddles is defined elsewhere in your code)
    k = np.arange(fft_size)
    twiddles = np.exp(-2j * np.pi * k / fft_size)

    if type_fft == "everything":
        target_range = set(range(-2**(bit_width-1), 2**(bit_width-1)-1))
    else:
        real_quantized, imag_quantized = quantize_twiddles(twiddles, bit_width, type_fft=type_fft, fft_size=fft_size, stage=stage)
        target_range = set(real_quantized.tolist() + imag_quantized.tolist())
    
    # 2. Generate all possible values for a SINGLE slot
    # We store a tuple of (value, sign, alpha, shift) so we can print the equation later
    single_terms = []
    for alpha in alphabets:
        for shift in shifts:
            for sign in signs:
                val = sign * (alpha << shift)
                single_terms.append((val, sign, alpha, shift))
                
    # 3. Precompute all combinations and find the lowest cost for every possible number
    # Dictionary format: { integer_value : (shift_cost, combo_tuple) }
    best_combos = {}
    
    for combo in itertools.combinations_with_replacement(single_terms, num_slots):
        total_val = sum(t[0] for t in combo)
        shift_cost = sum(t[3] for t in combo)
        
        # If we haven't seen this number yet, OR if this new equation uses fewer shifts, save it
        if total_val not in best_combos or shift_cost < best_combos[total_val][0]:
            best_combos[total_val] = (shift_cost, combo)

    # 4. Evaluate our specific FFT targets
    unresolvable_gaps = []
    success_count = 0
    encoded_results = {} # Dictionary to hold our bit encodings
    
    # Calculate required bits for encoding
    alpha_bits = max(0, math.ceil(math.log2(len(alphabets))))
    shift_bits = max(0, math.ceil(math.log2(bit_width)))

    max_target_val = max(abs(t) for t in target_range)
    tolerance = tolerance_per * max_target_val

    print(f"\n{'='*75}")
    print(f"CSHM Search | Bits: {bit_width} | FFT: {fft_size} ({type_fft}) stage {stage} | Slots: {num_slots} | Alphabet: {alphabets} | Tolerance: {tolerance_per*100:.2f}% | Max_Tolerance: {tolerance:.2f}")
    print("-" * 75)
    print(f"{'Target':>7} | {'Equation':>42} | {'Status'} {'|':>3} {'Encoding(Slot A | ... | Slot N)'}")
    print("-" * 75)

    shift_total = 0
    max_shift = 0
    total_approx = 0

    for target in target_range:
        valid_matches = [val for val in best_combos.keys() if abs(val - target) <= tolerance]
        
        if valid_matches:
            closest_val = min(valid_matches, key=lambda x: abs(x - target))
            shift_cost, combo = best_combos[closest_val]
            
            # Format the equation string perfectly based on the number of slots
            eq_parts = []
            slot_encodings = []
            
            for i, (val, sign, alpha, shift) in enumerate(combo):
                # Equation formatting
                if i == 0:
                    eq_parts.append(f"{'-' if sign < 0 else ''}({alpha}x << {shift})")
                else:
                    eq_parts.append(f"{' - ' if sign < 0 else ' + '}({alpha}x << {shift})")
                
                # Bit Encoding (Alphabet Index | Sign | Shift)
                alpha_idx = alphabets.index(alpha)
                sign_bit = 0 if sign > 0 else 1 # 0 for positive, 1 for negative
                
                # Format into binary strings (e.g. 000 0 000)
                slot_bin = f"{alpha_idx:0{alpha_bits}b} {sign_bit} {shift:0{shift_bits}b}"
                slot_encodings.append(slot_bin)

                shift_total += shift  # Total shifts for this combination
                max_shift = max(max_shift, shift)  # Track the maximum shift used
                    
            best_match = "".join(eq_parts)
            encoded_results[target] = " | ".join(slot_encodings)
            
            print(f"{target:>7.2f} {f' (~{closest_val:<4})' if target != closest_val else '        '} {best_match:>35} | RESOLVED | key: {encoded_results[target]}")

            if target != closest_val:
                total_approx += 1

            # Save the generated encoding for the summary
            success_count += 1
        else:
            #print(f"{target:>7.2f} {'NO COMBINATION FOUND':>44} | FAILED")
            unresolvable_gaps.append(target)

    # 5. Summary Report
    print("-" * 75)
    print("SEARCH COMPLETE")
    print(f"Total Targets Checked: {len(target_range)}")
    print(f"Successfully Resolved: {success_count}")
    print(f"Unresolvable Gaps:     {len(unresolvable_gaps)}")
    
    if len(unresolvable_gaps) == 0:
        print(f"\nCONCLUSION: Proof successful. All required {bit_width}-bit numbers can be built with {num_slots} slots, {len(alphabets)} alphabets and tolerance: {tolerance_per} | Mean Shifts: {shift_total / (num_slots*success_count):.2f} | Max Shift: {max_shift} | Total Approximations: {total_approx} | Approx_percentage: {total_approx / len(target_range) * 100:.2f}%")
    else:
        print(f"\nCONCLUSION: Hardware expansion required. Gaps: {unresolvable_gaps}")

if __name__ == "__main__":

    #find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=3, max_alphabet_size=10, fft_size=256, bit_width=8, type_fft="split-radix", stage=5, tolerance_per=0)
    #find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=4, max_alphabet_size=10, fft_size=256, bit_width=8, type_fft="radix-2")
    #find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=4, max_alphabet_size=10, fft_size=256, bit_width=8, type_fft="radix-4")

    #find_cshm_instructions_2(fft_size=256, bit_width=8, type_fft="radix-2", stage=5, alphabets=4, num_slots=2, tolerance_per=0)

    if len(sys.argv) == 6:
        Type_search = sys.argv[1]
        fft_type = sys.argv[2]
        fft_size = int(sys.argv[3])
        bit_width = int(sys.argv[4])
        tolerance_per = int(sys.argv[5]) / 1000.0 
    else:
        raise ValueError("Usage: python cshm.py <Type_search> <fft_type> <fft_size> <bit_width> <tolerance>")

    if Type_search == "min":
        if(fft_type == "radix-2" or fft_type == "split-radix"):
            stages = int(np.log2(fft_size))
        elif(fft_type == "radix-4"):
            stages = int(np.log2(fft_size) / 2)

        for i in range(1, stages+1):
            find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=3, max_alphabet_size=10, fft_size=fft_size, bit_width=bit_width, type_fft=fft_type, stage=i, tolerance_per=tolerance_per)
