`timescale 1ns/1ps

module fft_top #(
    parameter WIDTH = 16,
    parameter Num_of_samples = 4096
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
    localparam STAGE_NUM = $clog2(Num_of_samples)/$clog2(4); // For radix-4 FFT

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

    genvar i;
    generate
        for (i = 0; i < STAGE_NUM; i = i + 1) begin : gen_stages
            SdfUnit4_fast #(
                .WIDTH(WIDTH),
                .STAGE_NUM(i + 1),
                .Num_of_samples(Num_of_samples)
            ) stage_inst (
                .clock(clock),
                .reset(reset),
                .input_en(enable_stage[i]),
                .input_real_0(input_real_stage_0[i]),
                .input_real_1(input_real_stage_1[i]),
                .input_real_2(input_real_stage_2[i]),
                .input_real_3(input_real_stage_3[i]),
                .input_imag_0(input_imag_stage_0[i]),
                .input_imag_1(input_imag_stage_1[i]),
                .input_imag_2(input_imag_stage_2[i]),
                .input_imag_3(input_imag_stage_3[i]),
                .output_en(enable_stage[i + 1]),
                .output_real_0(stage_output_real_0[i]),
                .output_real_1(stage_output_real_1[i]),
                .output_real_2(stage_output_real_2[i]),
                .output_real_3(stage_output_real_3[i]),
                .output_imag_0(stage_output_imag_0[i]),
                .output_imag_1(stage_output_imag_1[i]),
                .output_imag_2(stage_output_imag_2[i]),
                .output_imag_3(stage_output_imag_3[i])
            );

            if (i < STAGE_NUM - 1) begin
                assign input_real_stage_0[i + 1] = stage_output_real_0[i];
                assign input_real_stage_1[i + 1] = stage_output_real_1[i];
                assign input_real_stage_2[i + 1] = stage_output_real_2[i];
                assign input_real_stage_3[i + 1] = stage_output_real_3[i];

                assign input_imag_stage_0[i + 1] = stage_output_imag_0[i];
                assign input_imag_stage_1[i + 1] = stage_output_imag_1[i];
                assign input_imag_stage_2[i + 1] = stage_output_imag_2[i];
                assign input_imag_stage_3[i + 1] = stage_output_imag_3[i];
            end
        end
    endgenerate
endmodule