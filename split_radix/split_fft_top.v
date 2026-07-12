`timescale 1ns/1ps

module split_fft_top #(
    parameter WIDTH = 16,
    parameter N = 64,
    parameter SIMPLE_MULT = 1
)(
    input                   clock,
    input                   reset,
    input                   input_en,
    input       [WIDTH-1:0] input_real_0,
    input       [WIDTH-1:0] input_real_1,
    input       [WIDTH-1:0] input_real_2,
    input       [WIDTH-1:0] input_real_3,
    input       [WIDTH-1:0] input_imag_0,
    input       [WIDTH-1:0] input_imag_1,
    input       [WIDTH-1:0] input_imag_2,
    input       [WIDTH-1:0] input_imag_3,
    output                  output_en,
    output      [WIDTH-1:0] output_real_0,
    output      [WIDTH-1:0] output_real_1,
    output      [WIDTH-1:0] output_real_2,
    output      [WIDTH-1:0] output_real_3,
    output      [WIDTH-1:0] output_imag_0,
    output      [WIDTH-1:0] output_imag_1,
    output      [WIDTH-1:0] output_imag_2,
    output      [WIDTH-1:0] output_imag_3
);
    localparam STAGE_NUM = $clog2(N) - 1; // For split-radix FFT

    wire [WIDTH-1:0] input_real_stage_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_real_stage_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_real_stage_2 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_real_stage_3 [0:STAGE_NUM-1];

    wire [WIDTH-1:0] input_imag_stage_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_imag_stage_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_imag_stage_2 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_imag_stage_3 [0:STAGE_NUM-1];

    wire [WIDTH-1:0] stage_output_real_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_real_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_real_2 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_real_3 [0:STAGE_NUM-1];

    wire [WIDTH-1:0] stage_output_imag_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_imag_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_imag_2 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_imag_3 [0:STAGE_NUM-1];

    wire enable_stage [0:STAGE_NUM];
    wire step_mode [0:STAGE_NUM];
    //wire step_mode_out;

    assign input_real_stage_0[0] = input_real_0;
    assign input_real_stage_1[0] = input_real_1;
    assign input_real_stage_2[0] = input_real_2;
    assign input_real_stage_3[0] = input_real_3;

    assign input_imag_stage_0[0] = input_imag_0;
    assign input_imag_stage_1[0] = input_imag_1;
    assign input_imag_stage_2[0] = input_imag_2;
    assign input_imag_stage_3[0] = input_imag_3;

    assign enable_stage[0] = input_en;
    assign output_en = enable_stage[STAGE_NUM];

    assign output_real_0 = stage_output_real_0[STAGE_NUM-1];
    assign output_real_1 = stage_output_real_1[STAGE_NUM-1];
    assign output_real_2 = stage_output_real_2[STAGE_NUM-1];
    assign output_real_3 = stage_output_real_3[STAGE_NUM-1];

    assign output_imag_0 = stage_output_imag_0[STAGE_NUM-1];
    assign output_imag_1 = stage_output_imag_1[STAGE_NUM-1];
    assign output_imag_2 = stage_output_imag_2[STAGE_NUM-1];
    assign output_imag_3 = stage_output_imag_3[STAGE_NUM-1];

    Split_radix_FirstStage #(
        .WIDTH(WIDTH),
        .Num_of_samples(N)
    ) first_stage_inst (
        .clock(clock),
        .reset(reset),
        .input_en(enable_stage[0]),
        .input_real_0(input_real_stage_0[0]),
        .input_imag_0(input_imag_stage_0[0]),
        .input_real_1(input_real_stage_1[0]),
        .input_imag_1(input_imag_stage_1[0]),
        .input_real_2(input_real_stage_2[0]),
        .input_imag_2(input_imag_stage_2[0]),
        .input_real_3(input_real_stage_3[0]),
        .input_imag_3(input_imag_stage_3[0]),
        .output_en(enable_stage[1]),
        .output_real_0(stage_output_real_0[0]),
        .output_imag_0(stage_output_imag_0[0]),
        .output_real_1(stage_output_real_1[0]),
        .output_imag_1(stage_output_imag_1[0]),
        .output_real_2(stage_output_real_2[0]),
        .output_imag_2(stage_output_imag_2[0]), 
        .output_real_3(stage_output_real_3[0]),
        .output_imag_3(stage_output_imag_3[0])
    );

    assign input_real_stage_0[1] = stage_output_real_0[0];    
    assign input_real_stage_1[1] = stage_output_real_1[0];
    assign input_real_stage_2[1] = stage_output_real_2[0];
    assign input_real_stage_3[1] = stage_output_real_3[0];

    assign input_imag_stage_0[1] = stage_output_imag_0[0];
    assign input_imag_stage_1[1] = stage_output_imag_1[0];
    assign input_imag_stage_2[1] = stage_output_imag_2[0];
    assign input_imag_stage_3[1] = stage_output_imag_3[0];

    Split_radix_SecondStage #(
        .WIDTH(WIDTH),
        .Num_of_samples(N),
        .SIMPLE_MULT(SIMPLE_MULT)
    ) second_stage_inst (
        .clock(clock),
        .reset(reset),
        .input_en(enable_stage[1]),
        .input_real_0(input_real_stage_0[1]),
        .input_imag_0(input_imag_stage_0[1]),
        .input_real_1(input_real_stage_1[1]),
        .input_imag_1(input_imag_stage_1[1]),
        .input_real_2(input_real_stage_2[1]),
        .input_imag_2(input_imag_stage_2[1]),
        .input_real_3(input_real_stage_3[1]),
        .input_imag_3(input_imag_stage_3[1]),
        .output_en(enable_stage[2]),
        .output_real_0(stage_output_real_0[1]),
        .output_imag_0(stage_output_imag_0[1]),
        .output_real_1(stage_output_real_1[1]),
        .output_imag_1(stage_output_imag_1[1]),
        .output_real_2(stage_output_real_2[1]),
        .output_imag_2(stage_output_imag_2[1]),
        .output_real_3(stage_output_real_3[1]),
        .output_imag_3(stage_output_imag_3[1])
    );

    assign input_real_stage_0[2] = stage_output_real_0[1];
    assign input_real_stage_1[2] = stage_output_real_1[1];
    assign input_real_stage_2[2] = stage_output_real_2[1];
    assign input_real_stage_3[2] = stage_output_real_3[1];

    assign input_imag_stage_0[2] = stage_output_imag_0[1];
    assign input_imag_stage_1[2] = stage_output_imag_1[1];
    assign input_imag_stage_2[2] = stage_output_imag_2[1];
    assign input_imag_stage_3[2] = stage_output_imag_3[1];
    assign step_mode[2] = 1'b0;

    genvar i;
    generate
        for (i = 2; i < STAGE_NUM - 2; i = i + 1) begin : gen_stages
            Split_radix_ThirdStage #(
                .WIDTH(WIDTH),
                .Num_of_samples(N),
                .SIMPLE_MULT(SIMPLE_MULT),
                .STAGE_NUM(i+1)
            ) third_stage_inst (
                .clock(clock),
                .reset(reset),
                .input_en(enable_stage[i]),
                .step_mode(step_mode[i]),
                .input_real_0(input_real_stage_0[i]),
                .input_imag_0(input_imag_stage_0[i]),
                .input_real_1(input_real_stage_1[i]),
                .input_imag_1(input_imag_stage_1[i]),
                .input_real_2(input_real_stage_2[i]),
                .input_imag_2(input_imag_stage_2[i]),
                .input_real_3(input_real_stage_3[i]),
                .input_imag_3(input_imag_stage_3[i]),
                .output_en(enable_stage[i+1]),
                .step_mode_output(step_mode[i+1]),
                .output_real_0(stage_output_real_0[i]),
                .output_imag_0(stage_output_imag_0[i]),
                .output_real_1(stage_output_real_1[i]),
                .output_imag_1(stage_output_imag_1[i]),
                .output_real_2(stage_output_real_2[i]),
                .output_imag_2(stage_output_imag_2[i]),
                .output_real_3(stage_output_real_3[i]),
                .output_imag_3(stage_output_imag_3[i])
            );

            assign input_real_stage_0[i+1] = stage_output_real_0[i];
            assign input_real_stage_1[i+1] = stage_output_real_1[i];
            assign input_real_stage_2[i+1] = stage_output_real_2[i];
            assign input_real_stage_3[i+1] = stage_output_real_3[i];

            assign input_imag_stage_0[i+1] = stage_output_imag_0[i];
            assign input_imag_stage_1[i+1] = stage_output_imag_1[i];
            assign input_imag_stage_2[i+1] = stage_output_imag_2[i];
            assign input_imag_stage_3[i+1] = stage_output_imag_3[i];
        end
    endgenerate

    // REPLACED 'i+1' WITH 'STAGE_NUM - 2'
    Split_radix_secToLast_stage #(
        .WIDTH(WIDTH),
        .Num_of_samples(N),
        .STAGE_NUM(STAGE_NUM - 1),
        .SIMPLE_MULT(SIMPLE_MULT)
    ) sec_to_last_stage_inst (
        .clock(clock),
        .reset(reset),
        .input_en(enable_stage[STAGE_NUM - 2]),
        .step_mode(step_mode[STAGE_NUM - 2]),
        .input_real_0(input_real_stage_0[STAGE_NUM - 2]),
        .input_imag_0(input_imag_stage_0[STAGE_NUM - 2]),
        .input_real_1(input_real_stage_1[STAGE_NUM - 2]),
        .input_imag_1(input_imag_stage_1[STAGE_NUM - 2]),
        .input_real_2(input_real_stage_2[STAGE_NUM - 2]),
        .input_imag_2(input_imag_stage_2[STAGE_NUM - 2]),
        .input_real_3(input_real_stage_3[STAGE_NUM - 2]),
        .input_imag_3(input_imag_stage_3[STAGE_NUM - 2]),
        .output_en(enable_stage[STAGE_NUM - 1]),
        .step_mode_output(step_mode[STAGE_NUM - 1]),
        .output_real_0(stage_output_real_0[STAGE_NUM - 2]),
        .output_imag_0(stage_output_imag_0[STAGE_NUM - 2]),
        .output_real_1(stage_output_real_1[STAGE_NUM - 2]),
        .output_imag_1(stage_output_imag_1[STAGE_NUM - 2]),
        .output_real_2(stage_output_real_2[STAGE_NUM - 2]),
        .output_imag_2(stage_output_imag_2[STAGE_NUM - 2]),
        .output_real_3(stage_output_real_3[STAGE_NUM - 2]),
        .output_imag_3(stage_output_imag_3[STAGE_NUM - 2])
    );

    // REPLACED 'i+2' WITH 'STAGE_NUM - 1'
    assign input_real_stage_0[STAGE_NUM - 1] = stage_output_real_0[STAGE_NUM - 2];
    assign input_real_stage_1[STAGE_NUM - 1] = stage_output_real_1[STAGE_NUM - 2];
    assign input_real_stage_2[STAGE_NUM - 1] = stage_output_real_2[STAGE_NUM - 2];
    assign input_real_stage_3[STAGE_NUM - 1] = stage_output_real_3[STAGE_NUM - 2];

    assign input_imag_stage_0[STAGE_NUM - 1] = stage_output_imag_0[STAGE_NUM - 2];
    assign input_imag_stage_1[STAGE_NUM - 1] = stage_output_imag_1[STAGE_NUM - 2];
    assign input_imag_stage_2[STAGE_NUM - 1] = stage_output_imag_2[STAGE_NUM - 2];
    assign input_imag_stage_3[STAGE_NUM - 1] = stage_output_imag_3[STAGE_NUM - 2];

    Split_radix_Last_stage #(
        .WIDTH(WIDTH),
        .Num_of_samples(N),
        .STAGE_NUM(STAGE_NUM),
        .SIMPLE_MULT(SIMPLE_MULT)
    ) last_stage_inst (
        .clock(clock),
        .reset(reset),
        .input_en(enable_stage[STAGE_NUM - 1]),
        .step_mode(step_mode[STAGE_NUM - 1]),
        .input_real_0(input_real_stage_0[STAGE_NUM - 1]),
        .input_imag_0(input_imag_stage_0[STAGE_NUM - 1]),
        .input_real_1(input_real_stage_1[STAGE_NUM - 1]),
        .input_imag_1(input_imag_stage_1[STAGE_NUM - 1]),
        .input_real_2(input_real_stage_2[STAGE_NUM - 1]),
        .input_imag_2(input_imag_stage_2[STAGE_NUM - 1]),
        .input_real_3(input_real_stage_3[STAGE_NUM - 1]),
        .input_imag_3(input_imag_stage_3[STAGE_NUM - 1]),
        .output_en(enable_stage[STAGE_NUM]),
        .output_real_0(stage_output_real_0[STAGE_NUM - 1]),
        .output_imag_0(stage_output_imag_0[STAGE_NUM - 1]),
        .output_real_1(stage_output_real_1[STAGE_NUM - 1]),
        .output_imag_1(stage_output_imag_1[STAGE_NUM - 1]),
        .output_real_2(stage_output_real_2[STAGE_NUM - 1]),
        .output_imag_2(stage_output_imag_2[STAGE_NUM - 1]),
        .output_real_3(stage_output_real_3[STAGE_NUM - 1]),
        .output_imag_3(stage_output_imag_3[STAGE_NUM - 1])
    );
endmodule