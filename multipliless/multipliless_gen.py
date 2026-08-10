import math

# ==========================================
# 1. YOUR INPUT DATA
# ==========================================
# Plug in your real and imaginary lists here
real_vals = [127, 118, 91, 49, 0, -49, -91, -118]
imag_vals = [0, -49, -91, -118, -128, -118, -91, -49]

# ==========================================
# 2. CSD ALGORITHM (Canonical Signed Digit)
# ==========================================
# Finds the nearest power of 2, subtracts it, and repeats.
# This mathematically guarantees the fewest adders possible!
def get_csd(val):
    if val == 0: 
        return []
    p = 0
    while (1 << p) <= abs(val): 
        p += 1
        
    dist_above = abs(abs(val) - (1 << p))
    dist_below = abs(abs(val) - (1 << (p - 1)))
    
    best_p = p if dist_above < dist_below else p - 1
    sign = 1 if val > 0 else -1
    
    rem = val - sign * (1 << best_p)
    return [(sign, best_p)] + get_csd(rem)

# ==========================================
# 3. VERILOG GENERATOR
# ==========================================
def generate_verilog(real_list, imag_list):
    num_states = len(real_list)
    sel_bits = math.ceil(math.log2(num_states))
    
    # Extract unique absolute values (ignoring 0)
    all_vals = set([abs(x) for x in real_list] + [abs(x) for x in imag_list])
    if 0 in all_vals:
        all_vals.remove(0)
    unique_vals = sorted(list(all_vals))
    
    # Find the maximum shift needed
    max_shift = 0
    for v in unique_vals:
        for sign, p in get_csd(v):
            if p > max_shift: max_shift = p

    print("`timescale 1ns / 1ps\n")
    print(f"module multiplierless_{num_states}_twiddles #(")
    print("    parameter WIDTH = 16,")
    print("    parameter PROD  = 24")
    print(")(")
    print("    input  clock,")
    print("    input  signed [WIDTH-1:0] a,")
    print(f"    input  [{sel_bits-1}:0] sel,")
    print("    ")
    print("    output reg signed [PROD-1:0] out_real,")
    print("    output reg signed [PROD-1:0] out_imag")
    print(");\n")
    
    print("    // STAGE 1: Input Latching")
    print("    reg signed [PROD-1:0] a_q1;")
    print(f"    reg [{sel_bits-1}:0] sel_q1, sel_q2;")
    print("    always @(posedge clock) begin")
    print("        a_q1   <= {{PROD-WIDTH{a[WIDTH-1]}}, a};")
    print("        sel_q1 <= sel;")
    print("    end\n")

    print("    // STAGE 2: Hardwired Shifts")
    for p in range(max_shift, 0, -1):
        print(f"    wire signed [PROD-1:0] a_shl_{p} = a_q1 << {p};")
    print("")

    print("    // STAGE 2: Minimum-Adder Coefficients")
    reg_names = ", ".join([f"c{v}" for v in unique_vals])
    print(f"    reg signed [PROD-1:0] {reg_names};")
    print("    always @(posedge clock) begin")
    
    for v in unique_vals:
        terms = get_csd(v)
        equation = ""
        for i, (sign, p) in enumerate(terms):
            var_name = f"a_shl_{p}" if p > 0 else "a_q1"
            if i == 0:
                equation += f"{var_name}" if sign == 1 else f"-{var_name}"
            else:
                equation += f" + {var_name}" if sign == 1 else f" - {var_name}"
        print(f"        c{v:<4} <= {equation};")
        
    print("        sel_q2 <= sel_q1;")
    print("    end\n")

    print("    // STAGE 3: Final MUX Routing")
    print("    always @(posedge clock) begin")
    print("        // REAL PART")
    print("        case (sel_q2)")
    for i, val in enumerate(real_list):
        if val == 0:
            print(f"            {sel_bits}'d{i}: out_real <= {{PROD{{1'b0}}}};")
        else:
            sign_str = "-" if val < 0 else " "
            print(f"            {sel_bits}'d{i}: out_real <= {sign_str}c{abs(val)};")
    print("        endcase\n")

    print("        // IMAGINARY PART")
    print("        case (sel_q2)")
    for i, val in enumerate(imag_list):
        if val == 0:
            print(f"            {sel_bits}'d{i}: out_imag <= {{PROD{{1'b0}}}};")
        else:
            sign_str = "-" if val < 0 else " "
            print(f"            {sel_bits}'d{i}: out_imag <= {sign_str}c{abs(val)};")
    print("        endcase")
    print("    end")
    print("endmodule")

# Run the generator
generate_verilog(real_vals, imag_vals)