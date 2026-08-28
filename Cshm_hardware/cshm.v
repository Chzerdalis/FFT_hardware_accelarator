`timescale 1ns / 1ps

module alphabets_1_7 #(
    parameter WIDTH = 16
)(
    input  clock,
    input  signed [WIDTH-1:0] multiplier_in,
    output reg signed [WIDTH+2:0] alphabet_1,
    output reg signed [WIDTH+2:0] alphabet_3,
    output reg signed [WIDTH+2:0] alphabet_5,
    output reg signed [WIDTH+2:0] alphabet_7
);

    always @(posedge clock) begin
        alphabet_1 <= multiplier_in;
        alphabet_3 <= (multiplier_in << 1) + multiplier_in; // 3x
        alphabet_5 <= (multiplier_in << 2) + multiplier_in; // 5x
        alphabet_7 <= (multiplier_in << 3) - multiplier_in; // 7x
    end

endmodule

module barrel_shifter_lossless #(
    parameter DATA_WIDTH = 19,
    parameter SHIFT_WIDTH = 3
)(
    input  signed [DATA_WIDTH-1:0] data_in,
    input  [SHIFT_WIDTH-1:0] shift_amount,
    
    // Output width = DATA_WIDTH + (2^SHIFT_WIDTH - 1)
    output signed [(DATA_WIDTH + (1<<SHIFT_WIDTH) - 1) - 1 : 0] data_out
);

    localparam MAX_SHIFT = (1 << SHIFT_WIDTH) - 1;
    localparam OUT_WIDTH = DATA_WIDTH + MAX_SHIFT;

    // Safely sign-extend the input before shifting
    wire signed [OUT_WIDTH-1:0] extended_data = data_in;

    assign data_out = extended_data << shift_amount;

endmodule

module sign_selection #(
    parameter WIDTH = 26
)(
    input  signed [WIDTH-1:0] data_in,
    input  sign_select,
    output reg signed [WIDTH-1:0] data_out
);

    always @(*) begin
        case (sign_select)
            1'b0: data_out = data_in;        
            1'b1: data_out = -data_in; // Two's complement negation       
            default: data_out = {WIDTH{1'bx}};  
        endcase
    end

endmodule

module cshm_2_keys #(
    parameter WIDTH = 16,
    parameter Tw_WIDTH = 8,
    parameter PROD  = WIDTH + Tw_WIDTH // Note: Consider increasing PROD to 27 to prevent silent truncation!
)(
    input  clock,
    input  signed [WIDTH-1:0] a,
    input  [13:0] key0, 
    input  [13:0] key1,
    
    output reg signed [PROD-1:0] out0,
    output reg signed [PROD-1:0] out1
);

    // =========================================================================
    // STAGE 1: Input Bounding
    // Prevents external pins from feeding directly into the alphabet adders.
    // =========================================================================
    reg signed [WIDTH-1:0] a_q1;
    reg [13:0] key0_q1, key1_q1;

    always @(posedge clock) begin
        a_q1    <= a;
        key0_q1 <= key0;
        key1_q1 <= key1;
    end

    // =========================================================================
    // STAGE 2: Alphabet Generation
    // The alphabets_1_7 module has 1 cycle of latency.
    // =========================================================================
    wire signed [WIDTH+2:0] alphabet_1, alphabet_3, alphabet_5, alphabet_7;

    alphabets_1_7 #(.WIDTH(WIDTH)) alphabets_inst (
        .clock(clock),
        .multiplier_in(a_q1),
        .alphabet_1(alphabet_1),
        .alphabet_3(alphabet_3),
        .alphabet_5(alphabet_5),
        .alphabet_7(alphabet_7)
    );

    // Delay keys to stay aligned with the alphabet generation cycle
    reg [13:0] key0_q2, key1_q2;
    always @(posedge clock) begin
        key0_q2 <= key0_q1;
        key1_q2 <= key1_q1;
    end

    // =========================================================================
    // STAGE 3: Multiplexing & Mux Registration
    // Slices the path between the multiplexer cloud and the shifters.
    // =========================================================================
    wire signed [WIDTH+2:0] mux00, mux01, mux10, mux11;

    assign mux00 = (key0_q2[13:12] == 2'b00) ? alphabet_1 :
                   (key0_q2[13:12] == 2'b01) ? alphabet_3 :
                   (key0_q2[13:12] == 2'b10) ? alphabet_5 :
                   (key0_q2[13:12] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    assign mux01 = (key0_q2[6:5] == 2'b00)   ? alphabet_1 :
                   (key0_q2[6:5] == 2'b01)   ? alphabet_3 :
                   (key0_q2[6:5] == 2'b10)   ? alphabet_5 :
                   (key0_q2[6:5] == 2'b11)   ? alphabet_7 : {WIDTH+3{1'bx}};

    assign mux10 = (key1_q2[13:12] == 2'b00) ? alphabet_1 :
                   (key1_q2[13:12] == 2'b01) ? alphabet_3 :
                   (key1_q2[13:12] == 2'b10) ? alphabet_5 :
                   (key1_q2[13:12] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    assign mux11 = (key1_q2[6:5] == 2'b00)   ? alphabet_1 :
                   (key1_q2[6:5] == 2'b01)   ? alphabet_3 :
                   (key1_q2[6:5] == 2'b10)   ? alphabet_5 :
                   (key1_q2[6:5] == 2'b11)   ? alphabet_7 : {WIDTH+3{1'bx}};

    reg signed [WIDTH+2:0] slot00_q3, slot01_q3, slot10_q3, slot11_q3;
    reg [13:0] key0_q3, key1_q3;

    always @(posedge clock) begin
        slot00_q3 <= mux00;
        slot01_q3 <= mux01;
        slot10_q3 <= mux10;
        slot11_q3 <= mux11;
        key0_q3   <= key0_q2;
        key1_q3   <= key1_q2;
    end

    // =========================================================================
    // STAGE 4: Barrel Shifting
    // =========================================================================
    wire signed [PROD-1:0] shift_out_00_wire, shift_out_01_wire, shift_out_10_wire, shift_out_11_wire;

    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(4)) shifter00 (.data_in(slot00_q3), .shift_amount(key0_q3[10:7]), .data_out(shift_out_00_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(4)) shifter01 (.data_in(slot01_q3), .shift_amount(key0_q3[3:0]), .data_out(shift_out_01_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(4)) shifter10 (.data_in(slot10_q3), .shift_amount(key1_q3[10:7]), .data_out(shift_out_10_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(4)) shifter11 (.data_in(slot11_q3), .shift_amount(key1_q3[3:0]), .data_out(shift_out_11_wire));

    reg signed [PROD-1:0] shift_out_00_q4, shift_out_01_q4, shift_out_10_q4, shift_out_11_q4;
    reg sign_00_q4, sign_01_q4, sign_10_q4, sign_11_q4; 

    always @(posedge clock) begin
        shift_out_00_q4 <= shift_out_00_wire;
        shift_out_01_q4 <= shift_out_01_wire;
        shift_out_10_q4 <= shift_out_10_wire;
        shift_out_11_q4 <= shift_out_11_wire;
        
        // Extract the target sign bits
        sign_00_q4 <= key0_q3[11];
        sign_01_q4 <= key0_q3[4];
        sign_10_q4 <= key1_q3[11];
        sign_11_q4 <= key1_q3[4];
    end

    // =========================================================================
    // STAGE 5: Fast Negation & Final Accumulation
    // Replaces the `sign_selection` module to save a logic level.
    // =========================================================================
    always @(posedge clock) begin
        // Two's complement math: if sign is 1, invert the bits (~x) and add 1 (via the + sign_XX_q4).
        out0 <= (sign_00_q4 ? ~shift_out_00_q4 : shift_out_00_q4) + sign_00_q4 + 
                (sign_01_q4 ? ~shift_out_01_q4 : shift_out_01_q4) + sign_01_q4;

        out1 <= (sign_10_q4 ? ~shift_out_10_q4 : shift_out_10_q4) + sign_10_q4 + 
                (sign_11_q4 ? ~shift_out_11_q4 : shift_out_11_q4) + sign_11_q4;
    end

endmodule