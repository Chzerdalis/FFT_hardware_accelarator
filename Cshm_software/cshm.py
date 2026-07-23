import numpy as np
import itertools
import math

def quantize_twiddles(twiddles, bit_width, type_fft="radix-2", fft_size=16):
    """
    Quantizes complex floating-point twiddle factors to a specified bit width 
    using Two's Complement representation.
    """
    # 1. The scale factor (fractional bits)
    fractional_bits = bit_width - 1
    scale_factor = 1 << fractional_bits
    
    # 2. The clipping boundaries
    min_val = -scale_factor               # e.g., -128 for 8-bit
    max_val = scale_factor - 1            # e.g., 127 for 8-bit
    
    # 3. The bitmask to force Two's Complement wrapping in Python
    mask = (1 << bit_width) - 1           # e.g., 0xFF for 8-bit
    
    # 4. Apply the math
    real_q = np.clip(np.round(twiddles.real * scale_factor), min_val, max_val).astype(int)
    imag_q = np.clip(np.round(twiddles.imag * scale_factor), min_val, max_val).astype(int)

    if type_fft == "radix-2":
        real_q = real_q[0 : fft_size // 2]
        imag_q = imag_q[0 : fft_size // 2]
        
    elif type_fft == "radix-4":
        real_q = real_q[0 : 3 * fft_size // 4]
        imag_q = imag_q[0 : 3 * fft_size // 4]
        
    elif type_fft == "split-radix":
        # 0 : fft_size // 4 grabs the first quarter (the 'n' twiddles)
        # 0 : 3 * fft_size // 4 : 3 grabs every 3rd twiddle (the '3n' twiddles)
        real_q = np.concatenate((
            real_q[0 : fft_size // 4], 
            real_q[0 : 3 * fft_size // 4 : 3]
        ))
        
        imag_q = np.concatenate((
            imag_q[0 : fft_size // 4], 
            imag_q[0 : 3 * fft_size // 4 : 3]
        ))
    
    else:
        real_q = real_q
        imag_q = imag_q

    return real_q, imag_q

def find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=3, max_alphabet_size=8, fft_size=16, type_fft="radix-2", tolerance_per=0):
    signs = [1, -1]
    
    bit_widths = [6, 8, 9, 12, 16]

    k = np.arange(fft_size)
    twiddles = np.exp(-2j * np.pi * k / fft_size)

    #print(twiddles)

    for bit_width in bit_widths:
        # The required integers for this bit-width
        if type_fft == "everything":
            target_range = set(range(-2**(bit_width-1), 2**(bit_width-1)))
        else:
            real_quantized, imag_quantized = quantize_twiddles(twiddles, bit_width, type_fft=type_fft, fft_size=fft_size)
            target_range = set(real_quantized.tolist() + imag_quantized.tolist())

        # Calculate the 10% tolerance window for this bit-width
        max_target_val = max(abs(t) for t in target_range) if target_range else 0
        tolerance = tolerance_per * max_target_val

        shifts = range(bit_width)
        
        print(f"\n{'='*60}")
        print(f"Evaluating {bit_width}-bit twiddles ({2*bit_width}-bit Data width) (FFT Size: {fft_size}), Type: {type_fft}")
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
                #else:
                    # Optional: Print how many gaps are left before trying a bigger alphabet
                    #print(f"    Failed: Alphabet {alphabets} left {len(missing_values)} gaps.")
            
            if missing_values:
                print(f" -> ERROR: {num_slots} slots cannot cover {bit_width}-bit numbers even with a {max_alphabet_size}-element alphabet.")


def find_cshm_instructions_2(fft_size=16, bit_width=8, type_fft="radix-2", alphabets=0, num_slots=2, tolerance_per=0):
    # Default alphabet if none is provided (remember to include 0!)
    if alphabets == 0:
        alphabets = [1, 3, 5, 7]
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
        real_quantized, imag_quantized = quantize_twiddles(twiddles, bit_width, type_fft=type_fft, fft_size=fft_size)
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

    print(f"CSHM Search | Bits: {bit_width} | FFT: {fft_size} ({type_fft}) | Slots: {num_slots} | Alphabet: {alphabets} | Tolerance: {tolerance_per*100:.2f}% | Max_Tolerance: {tolerance:.2f}")
    print("-" * 75)
    print(f"{'Target':>7} | {'Equation':>42} | {'Status'} {'|':>3} {'Encoding(Slot A | ... | Slot N)'}")
    print("-" * 75)

    shift_total = 0
    max_shift = 0

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
            
            #print(f"{target:>7.2f} {f' (~{closest_val:<4})' if target != closest_val else '        '} {best_match:>35} | RESOLVED | key: {encoded_results[target]}")
            
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
        print(f"\nCONCLUSION: Proof successful. All required {bit_width}-bit numbers can be built with {num_slots} slots, {len(alphabets)} alphabets and tolerance: {tolerance_per} | Mean Shifts: {shift_total / (num_slots*success_count):.2f} | Max Shift: {max_shift}")
    else:
        print(f"\nCONCLUSION: Hardware expansion required. Gaps: {unresolvable_gaps}")

if __name__ == "__main__":

    find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=3, max_alphabet_size=10, fft_size=256, type_fft="everything", tolerance_per=0.016)
    #find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=4, max_alphabet_size=10, fft_size=256, type_fft="radix-2")
    #find_cshm_slots_alfabets_for_fft_size_and_type(max_slots=4, max_alphabet_size=10, fft_size=256, type_fft="radix-4")

    #find_cshm_instructions_2(fft_size=256, bit_width=8, type_fft="everything", alphabets=2, num_slots=2, tolerance_per=0.015)
