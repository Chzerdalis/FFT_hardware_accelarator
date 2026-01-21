`timescale 1ns / 1ps

(* use_dsp = "no" *)

module multiplier_sythesis #(
    parameter WIDTH = 16
)(
    input                 clock,
    input                 reset,
    input  signed [WIDTH-1:0] a,
    input  signed [WIDTH/2-1:0] b,
    input  signed start,
    output reg signed [WIDTH + WIDTH/2 -1:0] product,
    output reg done
);

reg signed [WIDTH-1:0] ragA, regB;
reg signed [WIDTH + WIDTH/2 -1:0] product_reg_1, product_reg_2;
reg done_reg_1, done_reg_2, done_reg_3;

always @(posedge clock) begin
    if (reset) begin
        done <= 1'b0;
        product <= 0;
        done_reg_1 <= 1'b0;
        done_reg_2 <= 1'b0;
        product_reg_1 <= 0;
        product_reg_2 <= 0;
        regB <= 0;
        ragA <= 0;
    end else begin
        ragA <= a;
        regB <= b;
        done_reg_1 <= start;

        product_reg_1 <= ragA * regB;
        done_reg_2 <= done_reg_1;

        product_reg_2 <= product_reg_1;
        done_reg_3 <= done_reg_2;

        product <= product_reg_2;
        done <= done_reg_3;

    end
end

endmodule

`timescale 1ns / 1ps

(* use_dsp = "no" *)
module multiplier_sythesis_2 #(
    parameter WIDTH = 16
)(
    input                     clock,
    input                     reset,
    input                     start,
    input      signed [WIDTH-1:0]    a,
    input      signed [WIDTH/2-1:0]  b,
    output reg signed [WIDTH + WIDTH/2 -1:0] product,
    output reg                done
);

    // =========================================================================
    // Parameters & Derived Widths
    // =========================================================================
    localparam B_WIDTH  = WIDTH / 2;
    localparam P_WIDTH  = WIDTH + B_WIDTH; 

    // =========================================================================
    // Pipeline Registers
    // =========================================================================
    reg signed [P_WIDTH-1:0]   a_pipe     [0:B_WIDTH-1];
    reg signed [B_WIDTH-1:0]   b_pipe     [0:B_WIDTH-1]; 
    reg signed [P_WIDTH-1:0]   sum_pipe   [0:B_WIDTH-1];
    reg signed [P_WIDTH-1:0]   carry_pipe [0:B_WIDTH-1];
    reg                        valid_pipe [0:B_WIDTH-1]; 

    integer i;
    
    // =========================================================================
    // Combinatorial Signals (The fix for the timing bug)
    // =========================================================================
    // We need variables to hold the math result *before* the register update
    reg signed [P_WIDTH-1:0]   comb_pp;
    reg signed [P_WIDTH-1:0]   comb_sum;
    reg signed [P_WIDTH-1:0]   comb_carry;

    always @(posedge clock) begin
        if (reset) begin
            done <= 0;
            product <= 0;
            for (i=0; i<B_WIDTH; i=i+1) begin
                valid_pipe[i] <= 0;
                a_pipe[i]     <= 0;
                b_pipe[i]     <= 0;
                sum_pipe[i]   <= 0;
                carry_pipe[i] <= 0;
            end

        end else begin
            
            // -----------------------------------------------------------
            // Stage 0: Input Latching
            // -----------------------------------------------------------
            valid_pipe[0] <= start;
            a_pipe[0]     <= {{B_WIDTH{a[WIDTH-1]}}, a}; // Sign extend input A
            b_pipe[0]     <= b;

            // Calculate Stage 0 Math Combinatorially
            // If b[0] is 1, PP is A. Else 0.
            if (b[0]) comb_pp = {{B_WIDTH{a[WIDTH-1]}}, a};
            else      comb_pp = {P_WIDTH{1'b0}};

            // For the first stage, Sum is just PP, Carry is 0
            sum_pipe[0]   <= comb_pp;
            carry_pipe[0] <= {P_WIDTH{1'b0}};


            // -----------------------------------------------------------
            // Stages 1 to B_WIDTH-2: The Core Pipeline
            // -----------------------------------------------------------
            for (i=1; i < B_WIDTH-1; i=i+1) begin
                
                // 1. Pass Data & Control Down
                valid_pipe[i] <= valid_pipe[i-1];
                a_pipe[i]     <= a_pipe[i-1];
                b_pipe[i]     <= b_pipe[i-1];

                // 2. Calculate Math using PREVIOUS stage data (i-1)
                //    This ensures we use the data currently sitting at the input of this stage.
                
                // A. Generate Partial Product (Combinatorial)
                if (b_pipe[i-1][i]) 
                    comb_pp = (a_pipe[i-1] << i);
                else 
                    comb_pp = {P_WIDTH{1'b0}};

                // B. Perform Full Adder Reduction (Combinatorial)
                //    Inputs: Sum[i-1], Carry[i-1], and the new PP
                comb_sum   = sum_pipe[i-1] ^ carry_pipe[i-1] ^ comb_pp;
                comb_carry = ((sum_pipe[i-1] & carry_pipe[i-1]) | 
                              (sum_pipe[i-1] & comb_pp) | 
                              (carry_pipe[i-1] & comb_pp)) << 1;

                // 3. Latch results into CURRENT stage registers (i)
                sum_pipe[i]   <= comb_sum;
                carry_pipe[i] <= comb_carry;
            end


            // -----------------------------------------------------------
            // Final Stage (MSB): Subtraction Logic
            // -----------------------------------------------------------
            i = B_WIDTH - 1; 

            // Calculate the MSB Partial Product from the pipe that just finished
            // Note: We use i-1 because the data is coming from the register set just before this block
            if (b_pipe[i-1][i]) 
                comb_pp = (a_pipe[i-1] << i);
            else 
                comb_pp = {P_WIDTH{1'b0}};

            if (valid_pipe[i-1]) begin
                // Check MSB of the multiplier for signed subtraction
                if (b_pipe[i-1][i]) begin
                    // Product = (Accumulated Sum + Accumulated Carry) - MSB_Term
                    product <= (sum_pipe[i-1] + carry_pipe[i-1]) - comb_pp;
                end else begin
                    // Product = Accumulated Sum + Accumulated Carry
                    product <= sum_pipe[i-1] + carry_pipe[i-1]; 
                end
                done <= 1'b1;
            end else begin
                done <= 1'b0;
            end
        end
    end

endmodule