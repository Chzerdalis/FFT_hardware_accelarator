`timescale 1ns / 1ps

module multiplierless_8_twiddles #(
    parameter WIDTH = 16,
    parameter PROD  = 24
)(
    input  clock,
    input  signed [WIDTH-1:0] a,
    input  [2:0] sel, // 3 bits to select Twiddle 0-7
    
    output reg signed [PROD-1:0] out_real,
    output reg signed [PROD-1:0] out_imag
);

    // ----------------------------------------------------------------------
    // STAGE 1: Input Latching and Sign Extension
    // ----------------------------------------------------------------------
    reg signed [PROD-1:0] a_q1;
    reg [2:0] sel_q1;
    
    always @(posedge clock) begin
        a_q1   <= {{PROD-WIDTH{a[WIDTH-1]}}, a};
        sel_q1 <= sel;
    end

    // ----------------------------------------------------------------------
    // STAGE 2: Hardwired Shifts (Zero Logic Cost)
    // ----------------------------------------------------------------------
    wire signed [PROD-1:0] a_shl_7 = a_q1 << 7; // a * 128
    wire signed [PROD-1:0] a_shl_6 = a_q1 << 6; // a * 64
    wire signed [PROD-1:0] a_shl_5 = a_q1 << 5; // a * 32
    wire signed [PROD-1:0] a_shl_4 = a_q1 << 4; // a * 16
    wire signed [PROD-1:0] a_shl_3 = a_q1 << 3; // a * 8
    wire signed [PROD-1:0] a_shl_2 = a_q1 << 2; // a * 4
    wire signed [PROD-1:0] a_shl_1 = a_q1 << 1; // a * 2

    // ----------------------------------------------------------------------
    // STAGE 2: Minimum-Adder Coefficient Generation (CSD)
    // ----------------------------------------------------------------------
    reg signed [PROD-1:0] c49, c91, c118, c127, c128;
    reg [2:0] sel_q2;

    always @(posedge clock) begin
        c49  <= a_shl_6 - a_shl_4 + a_q1;                   // 64 - 16 + 1
        c91  <= a_shl_7 - a_shl_5 - a_shl_2 - a_q1;         // 128 - 32 - 4 - 1
        c118 <= a_shl_7 - a_shl_3 - a_shl_1;                // 128 - 8 - 2
        c127 <= a_shl_7 - a_q1;                             // 128 - 1
        c128 <= a_shl_7;                                    // 128
        
        sel_q2 <= sel_q1;
    end

    // ----------------------------------------------------------------------
    // STAGE 3: Final MUX Routing
    // ----------------------------------------------------------------------
    always @(posedge clock) begin
        // --- REAL PART ROUTING ---
        case (sel_q2)
            3'd0: out_real <=  c127;
            3'd1: out_real <=  c118;
            3'd2: out_real <=  c91;
            3'd3: out_real <=  c49;
            3'd4: out_real <=  {PROD{1'b0}};
            3'd5: out_real <= -c49;
            3'd6: out_real <= -c91;
            3'd7: out_real <= -c118;
        endcase

        // --- IMAGINARY PART ROUTING ---
        case (sel_q2)
            3'd0: out_imag <=  {PROD{1'b0}};
            3'd1: out_imag <= -c49;
            3'd2: out_imag <= -c91;
            3'd3: out_imag <= -c118;
            3'd4: out_imag <= -c128;
            3'd5: out_imag <= -c118;
            3'd6: out_imag <= -c91;
            3'd7: out_imag <= -c49;
        endcase
    end

endmodule