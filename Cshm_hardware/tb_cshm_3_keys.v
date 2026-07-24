`timescale 1ns / 1ps

module tb_cshm_3_keys;

    // Parameters
    parameter WIDTH = 16;
    parameter PROD  = 24; // 16-bit Data + 8-bit Twiddle = 24 bits

    // Inputs
    reg clock;
    reg signed [WIDTH-1:0] a;
    reg [11:0] key0;
    reg [11:0] key1;
    reg [11:0] key2;

    // Outputs
    wire signed [PROD-1:0] out0;
    wire signed [PROD-1:0] out1;

    // --- The Magic Q8.8 Slicer ---
    // PROD-2 = 22. PROD-WIDTH-1 = 7. 
    // This perfectly extracts the 16 bits and drops the 7 twiddle fractions.
    wire signed [WIDTH-1:0] out0_q8_8 = out0[PROD-2 : PROD-WIDTH-1];
    wire signed [WIDTH-1:0] out1_q8_8 = out1[PROD-2 : PROD-WIDTH-1];

    // Instantiate the Unit Under Test (UUT)
    cshm_3_keys #(
        .WIDTH(WIDTH),
        .PROD(PROD)
    ) uut (
        .clock(clock),
        .a(a),
        .key0(key0),
        .key1(key1),
        .key2(key2),
        .out0(out0),
        .out1(out1)
    );

    // 1. Clock Generation (100 MHz)
    initial begin
        clock = 0;
        forever #5 clock = ~clock; // 10ns period
    end

    // 2. Stimulus and Checking
    initial begin
        a = 0; key0 = 0; key1 = 0; key2 = 0;
        #15; // Wait for startup

        // -----------------------------------------------------------
        // TEST 1: Multiply 1.5 by Twiddles (0.8125 and -0.65625)
        // -----------------------------------------------------------
        // Input: 1.5 in Q8.8 format -> 1.5 * 256 = 384
        a = 384; 
        
        // --- OUT 0 Twiddle = 0.8125 ---
        // In Q1.7 format -> 0.8125 * 128 = 104
        // 104 = 64 + 32 + 8 = (1x << 6) + (1x << 5) + (1x << 3)
        // Slot 00: Alpha 1 (00), Shift 6 (110), Sign + (0)  -> 00_110_0
        // Slot 01: Alpha 1 (00), Shift 5 (101), Sign + (0)  -> 00_101_0
        // Slot 02 (Key 2 Top): Alpha 1 (00), Shift 3 (011), Sign + (0) -> 00_011_0
        key0 = 12'b00_110_0_00_101_0;
        
        // --- OUT 1 Twiddle = -0.65625 ---
        // In Q1.7 format -> -0.65625 * 128 = -84
        // -84 = -64 - 16 - 4 = -(1x << 6) - (1x << 4) - (1x << 2)
        // Slot 10: Alpha 1 (00), Shift 6 (110), Sign - (1)  -> 00_110_1
        // Slot 11: Alpha 1 (00), Shift 4 (100), Sign - (1)  -> 00_100_1
        // Slot 12 (Key 2 Bot): Alpha 1 (00), Shift 2 (010), Sign - (1) -> 00_010_1
        key1 = 12'b00_110_1_00_100_1;
        
        // --- KEY 2 COMBINED ---
        // Key 2 = {Slot 02, Slot 12}
        key2 = 12'b00_011_0_00_010_1;
        
        // Wait 5 clock cycles for the 5-stage pipeline to finish!
        // 5 cycles * 10ns = 50ns
        #50; 
        
        $display("--------------------------------------------------");
        $display("TEST 1: Input = 1.5 (Raw Q8.8: %d)", a);
        $display("--------------------------------------------------");
        $display("MATH 1: 1.5 *  0.8125   =  1.21875   (Expected Raw Q8.8:  312)");
        $display("OUT 0 : Raw = %0d | Float = %f", out0_q8_8, $itor(out0_q8_8) / 256.0);
        $display("");
        
        $display("MATH 2: 1.5 * -0.65625  = -0.984375  (Expected Raw Q8.8: -252)");
        $display("OUT 1 : Raw = %0d | Float = %f", out1_q8_8, $itor(out1_q8_8) / 256.0);
        $display("\n");


        // -----------------------------------------------------------
        // TEST 2: Multiply negative number (-2.25)
        // -----------------------------------------------------------
        // Input: -2.25 in Q8.8 format -> -2.25 * 256 = -576
        a = -576; 
        
        // We leave the 3 keys exactly the same to test negative input handling
        // Key 0, 1, and 2 hold the Twiddles 0.8125 and -0.65625
        
        // Wait 5 clock cycles for the 5-stage pipeline
        #50; 
        
        $display("--------------------------------------------------");
        $display("TEST 2: Input = -2.25 (Raw Q8.8: %d)", a);
        $display("--------------------------------------------------");
        $display("MATH 1: -2.25 *  0.8125  = -1.828125 (Expected Raw Q8.8: -468)");
        $display("OUT 0 : Raw = %0d | Float = %f", out0_q8_8, $itor(out0_q8_8) / 256.0);
        $display("");
        
        $display("MATH 2: -2.25 * -0.65625 =  1.4765625(Expected Raw Q8.8:  378)");
        $display("OUT 1 : Raw = %0d | Float = %f", out1_q8_8, $itor(out1_q8_8) / 256.0);
        $display("--------------------------------------------------");

        $finish;
    end

endmodule