`timescale 1ns/1ps

module fft_top #(
    parameter WIDTH = 16,
    parameter Num_of_samples = 256 
)(
    input                   clock,
    input                   reset,
    input                   input_en,
    input       [WIDTH-1:0] input_real_0,
    input       [WIDTH-1:0] input_real_1,
    input       [WIDTH-1:0] input_imag_0,
    input       [WIDTH-1:0] input_imag_1,
    output                  output_en,
    output      [WIDTH-1:0] output_real_0,
    output      [WIDTH-1:0] output_real_1,
    output      [WIDTH-1:0] output_imag_0,
    output      [WIDTH-1:0] output_imag_1
);
    // For Radix-2, the number of stages is log2 of samples
    localparam STAGE_NUM = $clog2(Num_of_samples);

    // Intermediate wires for connecting stages (2-parallel paths)
    wire [WIDTH-1:0] input_real_stage_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_real_stage_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_imag_stage_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] input_imag_stage_1 [0:STAGE_NUM-1];

    wire [WIDTH-1:0] stage_output_real_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_real_1 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_imag_0 [0:STAGE_NUM-1];
    wire [WIDTH-1:0] stage_output_imag_1 [0:STAGE_NUM-1];

    wire enable_stage [0:STAGE_NUM];

    // Initialization: Map top-level inputs to the first stage wires
    assign input_real_stage_0[0] = input_real_0;
    assign input_real_stage_1[0] = input_real_1;
    assign input_imag_stage_0[0] = input_imag_0;
    assign input_imag_stage_1[0] = input_imag_1;

    assign enable_stage[0] = input_en;
    
    // Final Output assignments
    assign output_en     = enable_stage[STAGE_NUM];
    assign output_real_0 = stage_output_real_0[STAGE_NUM-1];
    assign output_real_1 = stage_output_real_1[STAGE_NUM-1];
    assign output_imag_0 = stage_output_imag_0[STAGE_NUM-1];
    assign output_imag_1 = stage_output_imag_1[STAGE_NUM-1];

    genvar i;
    generate
        for (i = 0; i < STAGE_NUM; i = i + 1) begin : gen_stages
            // Instantiate the Radix-2 SDF Unit
            SdfUnit2_fast #(
                .WIDTH(WIDTH),
                .STAGE_NUM(i + 1),
                .Num_of_samples(Num_of_samples)
            ) stage_inst (
                .clock(clock),
                .reset(reset),
                .input_en(enable_stage[i]),
                .input_real_0(input_real_stage_0[i]),
                .input_real_1(input_real_stage_1[i]),
                .input_imag_0(input_imag_stage_0[i]),
                .input_imag_1(input_imag_stage_1[i]),
                .output_en(enable_stage[i + 1]),
                .output_real_0(stage_output_real_0[i]),
                .output_real_1(stage_output_real_1[i]),
                .output_imag_0(stage_output_imag_0[i]),
                .output_imag_1(stage_output_imag_1[i])
            );

            // Connect output of stage i to input of stage i + 1
            if (i < STAGE_NUM - 1) begin
                assign input_real_stage_0[i + 1] = stage_output_real_0[i];
                assign input_real_stage_1[i + 1] = stage_output_real_1[i];
                assign input_imag_stage_0[i + 1] = stage_output_imag_0[i];
                assign input_imag_stage_1[i + 1] = stage_output_imag_1[i];
            end
        end
    endgenerate
    
endmodule


