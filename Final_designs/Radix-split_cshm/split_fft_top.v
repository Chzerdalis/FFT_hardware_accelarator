`timescale 1ns/1ps

`include "twiddle_pkg.vh"

module split_fft_top #(
    parameter WIDTH = 17,
    parameter Tw_WIDTH = 9,
    parameter N = 256,
    parameter input_pipeline_bram = 1,
    parameter output_pipeline_bram = 1,
    parameter KEY_WIDTH = 14,
    parameter Bram = 0
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
    localparam FS_WIDTH = Tw_WIDTH + 2;   // First-stage internal width
    localparam SS_WIDTH = Tw_WIDTH + 4;   // Second-stage internal width

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

    wire [FS_WIDTH-1:0] fs_out_real_0, fs_out_real_1, fs_out_real_2, fs_out_real_3;
    wire [FS_WIDTH-1:0] fs_out_imag_0, fs_out_imag_1, fs_out_imag_2, fs_out_imag_3;

    Split_radix_FirstStage #(
        .WIDTH(FS_WIDTH),
        .Num_of_samples(N),
        .Bram(Bram),
        .output_pipeline_bram(output_pipeline_bram)
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
        .output_real_0(fs_out_real_0),
        .output_imag_0(fs_out_imag_0),
        .output_real_1(fs_out_real_1),
        .output_imag_1(fs_out_imag_1),
        .output_real_2(fs_out_real_2),
        .output_imag_2(fs_out_imag_2),
        .output_real_3(fs_out_real_3),
        .output_imag_3(fs_out_imag_3)
    );

    // Sign-extend the first stage's FS_WIDTH-bit outputs up to the
    // WIDTH-bit stage buses (implicit port-connection widening zero-fills
    // instead, which corrupts negative values).
    assign stage_output_real_0[0] = {{(WIDTH-FS_WIDTH){fs_out_real_0[FS_WIDTH-1]}}, fs_out_real_0};
    assign stage_output_imag_0[0] = {{(WIDTH-FS_WIDTH){fs_out_imag_0[FS_WIDTH-1]}}, fs_out_imag_0};
    assign stage_output_real_1[0] = {{(WIDTH-FS_WIDTH){fs_out_real_1[FS_WIDTH-1]}}, fs_out_real_1};
    assign stage_output_imag_1[0] = {{(WIDTH-FS_WIDTH){fs_out_imag_1[FS_WIDTH-1]}}, fs_out_imag_1};
    assign stage_output_real_2[0] = {{(WIDTH-FS_WIDTH){fs_out_real_2[FS_WIDTH-1]}}, fs_out_real_2};
    assign stage_output_imag_2[0] = {{(WIDTH-FS_WIDTH){fs_out_imag_2[FS_WIDTH-1]}}, fs_out_imag_2};
    assign stage_output_real_3[0] = {{(WIDTH-FS_WIDTH){fs_out_real_3[FS_WIDTH-1]}}, fs_out_real_3};
    assign stage_output_imag_3[0] = {{(WIDTH-FS_WIDTH){fs_out_imag_3[FS_WIDTH-1]}}, fs_out_imag_3};

    assign input_real_stage_0[1] = stage_output_real_0[0];    
    assign input_real_stage_1[1] = stage_output_real_1[0];
    assign input_real_stage_2[1] = stage_output_real_2[0];
    assign input_real_stage_3[1] = stage_output_real_3[0];

    assign input_imag_stage_0[1] = stage_output_imag_0[0];
    assign input_imag_stage_1[1] = stage_output_imag_1[0];
    assign input_imag_stage_2[1] = stage_output_imag_2[0];
    assign input_imag_stage_3[1] = stage_output_imag_3[0];

    wire [SS_WIDTH-1:0] ss_out_real_0, ss_out_real_1, ss_out_real_2, ss_out_real_3;
    wire [SS_WIDTH-1:0] ss_out_imag_0, ss_out_imag_1, ss_out_imag_2, ss_out_imag_3;

    Split_radix_SecondStage #(
        .WIDTH(SS_WIDTH),
        .Tw_WIDTH(Tw_WIDTH),
        .Num_of_samples(N),
        .KEY_WIDTH(KEY_WIDTH),
        .Bram(Bram),
        .output_pipeline_bram(output_pipeline_bram),
        .input_pipeline_bram(input_pipeline_bram),
        .twiddle_file_real_1(`GET_REAL_FILE_1(1)),
        .twiddle_file_imag_1(`GET_IMAG_FILE_1(1)),
        .twiddle_file_real_2(`GET_REAL_FILE_2(1)),
        .twiddle_file_imag_2(`GET_IMAG_FILE_2(1))
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
        .output_real_0(ss_out_real_0),
        .output_imag_0(ss_out_imag_0),
        .output_real_1(ss_out_real_1),
        .output_imag_1(ss_out_imag_1),
        .output_real_2(ss_out_real_2),
        .output_imag_2(ss_out_imag_2),
        .output_real_3(ss_out_real_3),
        .output_imag_3(ss_out_imag_3)
    );

    // Sign-extend the second stage's SS_WIDTH-bit outputs up to the
    // WIDTH-bit stage buses (same reasoning as the first stage above).
    assign stage_output_real_0[1] = {{(WIDTH-SS_WIDTH){ss_out_real_0[SS_WIDTH-1]}}, ss_out_real_0};
    assign stage_output_imag_0[1] = {{(WIDTH-SS_WIDTH){ss_out_imag_0[SS_WIDTH-1]}}, ss_out_imag_0};
    assign stage_output_real_1[1] = {{(WIDTH-SS_WIDTH){ss_out_real_1[SS_WIDTH-1]}}, ss_out_real_1};
    assign stage_output_imag_1[1] = {{(WIDTH-SS_WIDTH){ss_out_imag_1[SS_WIDTH-1]}}, ss_out_imag_1};
    assign stage_output_real_2[1] = {{(WIDTH-SS_WIDTH){ss_out_real_2[SS_WIDTH-1]}}, ss_out_real_2};
    assign stage_output_imag_2[1] = {{(WIDTH-SS_WIDTH){ss_out_imag_2[SS_WIDTH-1]}}, ss_out_imag_2};
    assign stage_output_real_3[1] = {{(WIDTH-SS_WIDTH){ss_out_real_3[SS_WIDTH-1]}}, ss_out_real_3};
    assign stage_output_imag_3[1] = {{(WIDTH-SS_WIDTH){ss_out_imag_3[SS_WIDTH-1]}}, ss_out_imag_3};

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
                .Tw_WIDTH(Tw_WIDTH),
                .Num_of_samples(N),
                .STAGE_NUM(i+1),
                .input_pipeline_bram(input_pipeline_bram),
                .output_pipeline_bram(output_pipeline_bram),
                .KEY_WIDTH(KEY_WIDTH),
                .Bram(Bram),
                .twiddle_file_real_1(`GET_REAL_FILE_1(i)),
                .twiddle_file_imag_1(`GET_IMAG_FILE_1(i)),
                .twiddle_file_real_2(`GET_REAL_FILE_2(i)),
                .twiddle_file_imag_2(`GET_IMAG_FILE_2(i))
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
        .Tw_WIDTH(Tw_WIDTH),
        .Num_of_samples(N),
        .STAGE_NUM(STAGE_NUM - 1),
        .KEY_WIDTH(KEY_WIDTH),
        .twiddle_file_real_1(`GET_REAL_FILE_1(STAGE_NUM - 2)),
        .twiddle_file_imag_1(`GET_IMAG_FILE_1(STAGE_NUM - 2)),
        .twiddle_file_real_2(`GET_REAL_FILE_2(STAGE_NUM - 2)),
        .twiddle_file_imag_2(`GET_IMAG_FILE_2(STAGE_NUM - 2))
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
        .Tw_WIDTH(Tw_WIDTH),
        .Num_of_samples(N),
        .STAGE_NUM(STAGE_NUM),
        .KEY_WIDTH(KEY_WIDTH),
        .twiddle_file_real_1(`GET_REAL_FILE_1(STAGE_NUM - 1)),
        .twiddle_file_imag_1(`GET_IMAG_FILE_1(STAGE_NUM - 1)),
        .twiddle_file_real_2(`GET_REAL_FILE_2(STAGE_NUM - 1)),
        .twiddle_file_imag_2(`GET_IMAG_FILE_2(STAGE_NUM - 1))
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