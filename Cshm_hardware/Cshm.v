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

module alphabets_1_5 #(
    parameter WIDTH = 16
)(
    input  clock,
    input  signed [WIDTH-1:0] multiplier_in,
    output reg signed [WIDTH+2:0] alphabet_1,
    output reg signed [WIDTH+2:0] alphabet_3,
    output reg signed [WIDTH+2:0] alphabet_5
);

    always @(posedge clock) begin
        alphabet_1 <= multiplier_in;
        alphabet_3 <= (multiplier_in << 1) + multiplier_in; // 3x
        alphabet_5 <= (multiplier_in << 2) + multiplier_in; // 5x
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
    parameter PROD  = 24
)(
    input  clock,
    input  signed [WIDTH-1:0] a,
    input  [11:0] key0, 
    input  [11:0] key1,
    
    output reg signed [PROD-1:0] out0,
    output reg signed [PROD-1:0] out1
);
    
    wire signed [WIDTH+2:0] alphabet_1, alphabet_3, alphabet_5, alphabet_7;

    alphabets_1_7 #(.WIDTH(WIDTH)) alphabets_inst (
        .clock(clock),
        .multiplier_in(a),
        .alphabet_1(alphabet_1),
        .alphabet_3(alphabet_3),
        .alphabet_5(alphabet_5),
        .alphabet_7(alphabet_7)
    );

    reg [11:0] key0_q1, key1_q1;
    always @(posedge clock) begin
        key0_q1 <= key0;
        key1_q1 <= key1;
    end
    
    wire signed [WIDTH+2:0] slot00, slot01, slot10, slot11;

    assign slot00 = (key0_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key0_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key0_q1[11:10] == 2'b10) ? alphabet_5 :
                    (key0_q1[11:10] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    assign slot01 = (key0_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key0_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key0_q1[5:4] == 2'b10) ? alphabet_5 :
                    (key0_q1[5:4] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    assign slot10 = (key1_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key1_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key1_q1[11:10] == 2'b10) ? alphabet_5 :
                    (key1_q1[11:10] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    assign slot11 = (key1_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key1_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key1_q1[5:4] == 2'b10) ? alphabet_5 :
                    (key1_q1[5:4] == 2'b11) ? alphabet_7 : {WIDTH+3{1'bx}};

    // Wires for shift outputs (WIDTH+3) + 7 max shift = WIDTH+10 bits wide
    wire signed [WIDTH+9:0] shift_out_00_wire, shift_out_01_wire, shift_out_10_wire, shift_out_11_wire;

    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter00 (.data_in(slot00), .shift_amount(key0_q1[9:7]), .data_out(shift_out_00_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter01 (.data_in(slot01), .shift_amount(key0_q1[3:1]), .data_out(shift_out_01_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter10 (.data_in(slot10), .shift_amount(key1_q1[9:7]), .data_out(shift_out_10_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter11 (.data_in(slot11), .shift_amount(key1_q1[3:1]), .data_out(shift_out_11_wire));

    // Pipeline Registers for Stage 2 Data & Signs
    reg signed [WIDTH+9:0] shift_out_00_q2, shift_out_01_q2, shift_out_10_q2, shift_out_11_q2;
    reg sign_00_q2, sign_01_q2, sign_10_q2, sign_11_q2; 

    always @(posedge clock) begin
        shift_out_00_q2 <= shift_out_00_wire;
        shift_out_01_q2 <= shift_out_01_wire;
        shift_out_10_q2 <= shift_out_10_wire;
        shift_out_11_q2 <= shift_out_11_wire;
        
        sign_00_q2 <= key0_q1[6];
        sign_01_q2 <= key0_q1[0];
        sign_10_q2 <= key1_q1[6];
        sign_11_q2 <= key1_q1[0];
    end
    
    wire signed [WIDTH+9:0] sign_out_00_wire, sign_out_01_wire, sign_out_10_wire, sign_out_11_wire;

    sign_selection #(.WIDTH(WIDTH+10)) sign_select00 (.data_in(shift_out_00_q2), .sign_select(sign_00_q2), .data_out(sign_out_00_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select01 (.data_in(shift_out_01_q2), .sign_select(sign_01_q2), .data_out(sign_out_01_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select10 (.data_in(shift_out_10_q2), .sign_select(sign_10_q2), .data_out(sign_out_10_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select11 (.data_in(shift_out_11_q2), .sign_select(sign_11_q2), .data_out(sign_out_11_wire));

    // Pipeline Registers for Stage 3
    reg signed [WIDTH+9:0] sign_out_00_q3, sign_out_01_q3, sign_out_10_q3, sign_out_11_q3;

    always @(posedge clock) begin
        sign_out_00_q3 <= sign_out_00_wire;
        sign_out_01_q3 <= sign_out_01_wire;
        sign_out_10_q3 <= sign_out_10_wire;
        sign_out_11_q3 <= sign_out_11_wire;
    end
    
    always @(posedge clock) begin
        // Verilog implicitly sign-extends the WIDTH+10 bit sum to fit the PROD bit output
        out0 <= sign_out_00_q3 + sign_out_01_q3;
        out1 <= sign_out_10_q3 + sign_out_11_q3;
    end

endmodule

module cshm_3_keys #(
    parameter WIDTH = 16,
    parameter PROD  = 24
)(
    input  clock,
    input  signed [WIDTH-1:0] a,
    input  [11:0] key0, 
    input  [11:0] key1,
    input  [11:0] key2,
    
    output reg signed [PROD-1:0] out0,
    output reg signed [PROD-1:0] out1
);

    wire signed [WIDTH+2:0] alphabet_1, alphabet_3, alphabet_5;

    alphabets_1_5 #(.WIDTH(WIDTH)) alphabets_inst (
        .clock(clock),
        .multiplier_in(a),
        .alphabet_1(alphabet_1),
        .alphabet_3(alphabet_3),
        .alphabet_5(alphabet_5)
    );

    reg [11:0] key0_q1, key1_q1, key2_q1;
    always @(posedge clock) begin
        key0_q1 <= key0;
        key1_q1 <= key1;
        key2_q1 <= key2;
    end
    
    wire signed [WIDTH+2:0] slot00, slot01, slot10, slot11, slot02, slot12;

    assign slot00 = (key0_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key0_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key0_q1[11:10] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot01 = (key0_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key0_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key0_q1[5:4] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot10 = (key1_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key1_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key1_q1[11:10] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot11 = (key1_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key1_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key1_q1[5:4] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot02 = (key2_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key2_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key2_q1[11:10] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot12 = (key2_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key2_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key2_q1[5:4] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    wire signed [WIDTH+9:0] shift_out_00_wire, shift_out_01_wire, shift_out_10_wire;
    wire signed [WIDTH+9:0] shift_out_11_wire, shift_out_02_wire, shift_out_12_wire;

    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter00 (.data_in(slot00), .shift_amount(key0_q1[9:7]), .data_out(shift_out_00_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter01 (.data_in(slot01), .shift_amount(key0_q1[3:1]), .data_out(shift_out_01_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter10 (.data_in(slot10), .shift_amount(key1_q1[9:7]), .data_out(shift_out_10_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter11 (.data_in(slot11), .shift_amount(key1_q1[3:1]), .data_out(shift_out_11_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter02 (.data_in(slot02), .shift_amount(key2_q1[9:7]), .data_out(shift_out_02_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter12 (.data_in(slot12), .shift_amount(key2_q1[3:1]), .data_out(shift_out_12_wire));

    reg signed [WIDTH+9:0] shift_out_00_q2, shift_out_01_q2, shift_out_10_q2, shift_out_11_q2, shift_out_02_q2, shift_out_12_q2;
    reg sign_00_q2, sign_01_q2, sign_10_q2, sign_11_q2, sign_02_q2, sign_12_q2; 

    always @(posedge clock) begin
        shift_out_00_q2 <= shift_out_00_wire;
        shift_out_01_q2 <= shift_out_01_wire;
        shift_out_10_q2 <= shift_out_10_wire;
        shift_out_11_q2 <= shift_out_11_wire;
        shift_out_02_q2 <= shift_out_02_wire;
        shift_out_12_q2 <= shift_out_12_wire;
        
        sign_00_q2 <= key0_q1[6];
        sign_01_q2 <= key0_q1[0];
        sign_10_q2 <= key1_q1[6];
        sign_11_q2 <= key1_q1[0];
        sign_02_q2 <= key2_q1[6];
        sign_12_q2 <= key2_q1[0];
    end

    wire signed [WIDTH+9:0] sign_out_00_wire, sign_out_01_wire, sign_out_10_wire, sign_out_11_wire, sign_out_02_wire, sign_out_12_wire;

    sign_selection #(.WIDTH(WIDTH+10)) sign_select00 (.data_in(shift_out_00_q2), .sign_select(sign_00_q2), .data_out(sign_out_00_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select01 (.data_in(shift_out_01_q2), .sign_select(sign_01_q2), .data_out(sign_out_01_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select10 (.data_in(shift_out_10_q2), .sign_select(sign_10_q2), .data_out(sign_out_10_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select11 (.data_in(shift_out_11_q2), .sign_select(sign_11_q2), .data_out(sign_out_11_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select02 (.data_in(shift_out_02_q2), .sign_select(sign_02_q2), .data_out(sign_out_02_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select12 (.data_in(shift_out_12_q2), .sign_select(sign_12_q2), .data_out(sign_out_12_wire));

    reg signed [WIDTH+9:0] sign_out_00_q3, sign_out_01_q3, sign_out_10_q3, sign_out_11_q3, sign_out_02_q3, sign_out_12_q3;

    always @(posedge clock) begin
        sign_out_00_q3 <= sign_out_00_wire;
        sign_out_01_q3 <= sign_out_01_wire;
        sign_out_10_q3 <= sign_out_10_wire;
        sign_out_11_q3 <= sign_out_11_wire;
        sign_out_02_q3 <= sign_out_02_wire;
        sign_out_12_q3 <= sign_out_12_wire;
    end
    

    reg signed [WIDTH+9:0] partial_product_0, partial_product_1;
    reg signed [WIDTH+9:0] partial_product_2, partial_product_3;

    always @(posedge clock) begin
        partial_product_0 <= sign_out_00_q3 + sign_out_01_q3;
        partial_product_1 <= sign_out_10_q3 + sign_out_11_q3;
        partial_product_2 <= sign_out_02_q3;
        partial_product_3 <= sign_out_12_q3;

        out0 <= partial_product_0 + partial_product_2;
        out1 <= partial_product_1 + partial_product_3;
    end

endmodule

module cshm_2_keys_3_alpha #(
    parameter WIDTH = 16,
    parameter PROD  = 24
)(
    input  clock,
    input  signed [WIDTH-1:0] a,
    input  [11:0] key0, 
    input  [11:0] key1,
    
    output reg signed [PROD-1:0] out0,
    output reg signed [PROD-1:0] out1
);

    wire signed [WIDTH+2:0] alphabet_1, alphabet_3, alphabet_5;

    alphabets_1_5 #(.WIDTH(WIDTH)) alphabets_inst (
        .clock(clock),
        .multiplier_in(a),
        .alphabet_1(alphabet_1),
        .alphabet_3(alphabet_3),
        .alphabet_5(alphabet_5)
    );

    reg [11:0] key0_q1, key1_q1;
    always @(posedge clock) begin
        key0_q1 <= key0;
        key1_q1 <= key1;
    end
    
    wire signed [WIDTH+2:0] slot00, slot01, slot10, slot11;

    assign slot00 = (key0_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key0_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key0_q1[11:10] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot01 = (key0_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key0_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key0_q1[5:4] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot10 = (key1_q1[11:10] == 2'b00) ? alphabet_1 :
                    (key1_q1[11:10] == 2'b01) ? alphabet_3 :
                    (key1_q1[11:10] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    assign slot11 = (key1_q1[5:4] == 2'b00) ? alphabet_1 :
                    (key1_q1[5:4] == 2'b01) ? alphabet_3 :
                    (key1_q1[5:4] == 2'b10) ? alphabet_5 : {WIDTH+3{1'bx}};

    wire signed [WIDTH+9:0] shift_out_00_wire, shift_out_01_wire, shift_out_10_wire;
    wire signed [WIDTH+9:0] shift_out_11_wire;

    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter00 (.data_in(slot00), .shift_amount(key0_q1[9:7]), .data_out(shift_out_00_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter01 (.data_in(slot01), .shift_amount(key0_q1[3:1]), .data_out(shift_out_01_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter10 (.data_in(slot10), .shift_amount(key1_q1[9:7]), .data_out(shift_out_10_wire));
    barrel_shifter_lossless #(.DATA_WIDTH(WIDTH+3), .SHIFT_WIDTH(3)) shifter11 (.data_in(slot11), .shift_amount(key1_q1[3:1]), .data_out(shift_out_11_wire));

    reg signed [WIDTH+9:0] shift_out_00_q2, shift_out_01_q2, shift_out_10_q2, shift_out_11_q2;
    reg sign_00_q2, sign_01_q2, sign_10_q2, sign_11_q2; 
    always @(posedge clock) begin
        shift_out_00_q2 <= shift_out_00_wire;
        shift_out_01_q2 <= shift_out_01_wire;
        shift_out_10_q2 <= shift_out_10_wire;
        shift_out_11_q2 <= shift_out_11_wire;
        
        sign_00_q2 <= key0_q1[6];
        sign_01_q2 <= key0_q1[0];
        sign_10_q2 <= key1_q1[6];
        sign_11_q2 <= key1_q1[0];
    end

    wire signed [WIDTH+9:0] sign_out_00_wire, sign_out_01_wire, sign_out_10_wire, sign_out_11_wire, sign_out_02_wire, sign_out_12_wire;

    sign_selection #(.WIDTH(WIDTH+10)) sign_select00 (.data_in(shift_out_00_q2), .sign_select(sign_00_q2), .data_out(sign_out_00_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select01 (.data_in(shift_out_01_q2), .sign_select(sign_01_q2), .data_out(sign_out_01_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select10 (.data_in(shift_out_10_q2), .sign_select(sign_10_q2), .data_out(sign_out_10_wire));
    sign_selection #(.WIDTH(WIDTH+10)) sign_select11 (.data_in(shift_out_11_q2), .sign_select(sign_11_q2), .data_out(sign_out_11_wire));

    reg signed [WIDTH+9:0] sign_out_00_q3, sign_out_01_q3, sign_out_10_q3, sign_out_11_q3;

    always @(posedge clock) begin
        sign_out_00_q3 <= sign_out_00_wire;
        sign_out_01_q3 <= sign_out_01_wire;
        sign_out_10_q3 <= sign_out_10_wire;
        sign_out_11_q3 <= sign_out_11_wire;
    end

    reg signed [WIDTH+9:0] partial_product_0, partial_product_1;

    always @(posedge clock) begin
        out0 <= sign_out_00_q3 + sign_out_01_q3;
        out1 <= sign_out_10_q3 + sign_out_11_q3;
    end

endmodule