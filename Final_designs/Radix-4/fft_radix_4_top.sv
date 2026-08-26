`timescale 1ns/1ps

`include "twiddle_pkg.vh"

module fft_top #(
    parameter WIDTH = 11,
    parameter Tw_WIDTH = 9,
    parameter Num_of_samples = 256,
    parameter output_pipeline_bram = 1,
    parameter Bram = 0,
    parameter SimpleMult = 1,
    parameter Fast_DSP = 0,
    parameter carry_save = 1,
    parameter bit_growth = 1,
    
    // Radix-4 has log4(N) stages
    parameter STAGE_NUM = $clog2(Num_of_samples)/$clog2(4),
    
    // Threshold logic adapted for 2-bits per stage growth
    parameter Max_stage_num = (bit_growth == 1) ? ((WIDTH > Tw_WIDTH) ? (WIDTH - Tw_WIDTH)/2 : 0) : STAGE_NUM,
    parameter Current_bits_stages = (STAGE_NUM - Max_stage_num > 0) ? (Max_stage_num) : STAGE_NUM,
    parameter bit_growth_stages = (STAGE_NUM - Max_stage_num > 0) ? (STAGE_NUM - Max_stage_num) : 0,
    
    // Max width increases by 2 bits per growth stage
    parameter Max_width = WIDTH + (2 * bit_growth_stages)
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
    output  [Max_width-1:0] output_real_0,
    output  [Max_width-1:0] output_real_1,
    output  [Max_width-1:0] output_real_2,
    output  [Max_width-1:0] output_real_3,
    output  [Max_width-1:0] output_imag_0,
    output  [Max_width-1:0] output_imag_1,
    output  [Max_width-1:0] output_imag_2,
    output  [Max_width-1:0] output_imag_3
);

    // =========================================================================
    // Block 1: Stages WITHOUT Bit Growth (Fixed WIDTH)
    // =========================================================================
    wire [WIDTH-1:0] input_real_stage_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_real_stage_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_real_stage_2 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_real_stage_3 [0:Current_bits_stages-1];

    wire [WIDTH-1:0] input_imag_stage_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_imag_stage_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_imag_stage_2 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_imag_stage_3 [0:Current_bits_stages-1];

    wire [WIDTH-1:0] stage_output_real_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_real_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_real_2 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_real_3 [0:Current_bits_stages-1];

    wire [WIDTH-1:0] stage_output_imag_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_imag_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_imag_2 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_imag_3 [0:Current_bits_stages-1];

    wire enable_stage [0:Current_bits_stages];

    // Initialization for Stage 0
    assign input_real_stage_0[0] = input_real_0;
    assign input_real_stage_1[0] = input_real_1;
    assign input_real_stage_2[0] = input_real_2;
    assign input_real_stage_3[0] = input_real_3;

    assign input_imag_stage_0[0] = input_imag_0;
    assign input_imag_stage_1[0] = input_imag_1;
    assign input_imag_stage_2[0] = input_imag_2;
    assign input_imag_stage_3[0] = input_imag_3;

    assign enable_stage[0] = input_en;

    genvar i;
    generate
        for (i = 0; i < Current_bits_stages; i = i + 1) begin : gen_stages
            SdfUnit4_fast #(
                .WIDTH(WIDTH),
                .Tw_WIDTH(Tw_WIDTH),
                .STAGE_NUM(i + 1),
                .Num_of_samples(Num_of_samples),
                .output_pipeline_bram(output_pipeline_bram),
                .Bram(Bram),
                .SimpleMult(SimpleMult),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .twiddle_file_real_1(`GET_REAL_FILE_1(i)),
                .twiddle_file_imag_1(`GET_IMAG_FILE_1(i)),
                .twiddle_file_real_2(`GET_REAL_FILE_2(i)),
                .twiddle_file_imag_2(`GET_IMAG_FILE_2(i)),
                .twiddle_file_real_3(`GET_REAL_FILE_3(i)),
                .twiddle_file_imag_3(`GET_IMAG_FILE_3(i))
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

            // Forward connections to next non-growth stage
            if (i < Current_bits_stages - 1) begin
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

    // =========================================================================
    // Block 2: Stages WITH Bit Growth (+2 Bits per stage)
    // =========================================================================
    wire [Max_width-1:0] input_real_stage_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_real_stage_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_real_stage_2_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_real_stage_3_m [0:bit_growth_stages-1];

    wire [Max_width-1:0] input_imag_stage_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_imag_stage_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_imag_stage_2_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_imag_stage_3_m [0:bit_growth_stages-1];

    wire [Max_width-1:0] stage_output_real_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_real_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_real_2_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_real_3_m [0:bit_growth_stages-1];

    wire [Max_width-1:0] stage_output_imag_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_imag_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_imag_2_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_imag_3_m [0:bit_growth_stages-1];

    wire enable_stage_m [0:bit_growth_stages];

    // Bridge the gap: 2-bit sign extension from the last non-growth stage
    assign input_real_stage_0_m[0] = {{2{stage_output_real_0[Current_bits_stages-1][WIDTH-1]}}, stage_output_real_0[Current_bits_stages-1]};
    assign input_real_stage_1_m[0] = {{2{stage_output_real_1[Current_bits_stages-1][WIDTH-1]}}, stage_output_real_1[Current_bits_stages-1]};
    assign input_real_stage_2_m[0] = {{2{stage_output_real_2[Current_bits_stages-1][WIDTH-1]}}, stage_output_real_2[Current_bits_stages-1]};
    assign input_real_stage_3_m[0] = {{2{stage_output_real_3[Current_bits_stages-1][WIDTH-1]}}, stage_output_real_3[Current_bits_stages-1]};

    assign input_imag_stage_0_m[0] = {{2{stage_output_imag_0[Current_bits_stages-1][WIDTH-1]}}, stage_output_imag_0[Current_bits_stages-1]};
    assign input_imag_stage_1_m[0] = {{2{stage_output_imag_1[Current_bits_stages-1][WIDTH-1]}}, stage_output_imag_1[Current_bits_stages-1]};
    assign input_imag_stage_2_m[0] = {{2{stage_output_imag_2[Current_bits_stages-1][WIDTH-1]}}, stage_output_imag_2[Current_bits_stages-1]};
    assign input_imag_stage_3_m[0] = {{2{stage_output_imag_3[Current_bits_stages-1][WIDTH-1]}}, stage_output_imag_3[Current_bits_stages-1]};

    assign enable_stage_m[0] = enable_stage[Current_bits_stages];

    generate
        for (i = 0; i < bit_growth_stages; i = i + 1) begin : gen_stages_2
            
            // Radix-4 grows by 2 bits each stage
            localparam STAGE_W = WIDTH + 2 * (i + 1);

            wire [STAGE_W-1:0] temp_out_r0;
            wire [STAGE_W-1:0] temp_out_r1;
            wire [STAGE_W-1:0] temp_out_r2;
            wire [STAGE_W-1:0] temp_out_r3;

            wire [STAGE_W-1:0] temp_out_i0;
            wire [STAGE_W-1:0] temp_out_i1;
            wire [STAGE_W-1:0] temp_out_i2;
            wire [STAGE_W-1:0] temp_out_i3;

            SdfUnit4_fast #(
                .WIDTH(STAGE_W),
                .Tw_WIDTH(Tw_WIDTH),
                .STAGE_NUM(i + 1 + Current_bits_stages),
                .Num_of_samples(Num_of_samples),
                .output_pipeline_bram(output_pipeline_bram),
                .Bram(Bram),
                .SimpleMult(SimpleMult),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .twiddle_file_real_1(`GET_REAL_FILE_1(i + Current_bits_stages)),
                .twiddle_file_imag_1(`GET_IMAG_FILE_1(i + Current_bits_stages)),
                .twiddle_file_real_2(`GET_REAL_FILE_2(i + Current_bits_stages)),
                .twiddle_file_imag_2(`GET_IMAG_FILE_2(i + Current_bits_stages)),
                .twiddle_file_real_3(`GET_REAL_FILE_3(i + Current_bits_stages)),
                .twiddle_file_imag_3(`GET_IMAG_FILE_3(i + Current_bits_stages))
            ) stage_inst (
                .clock(clock),
                .reset(reset),
                .input_en(enable_stage_m[i]),
                
                // Slice Max_width array down to the actual stage width requirement
                .input_real_0(input_real_stage_0_m[i][STAGE_W-1:0]),
                .input_real_1(input_real_stage_1_m[i][STAGE_W-1:0]),
                .input_real_2(input_real_stage_2_m[i][STAGE_W-1:0]),
                .input_real_3(input_real_stage_3_m[i][STAGE_W-1:0]),
                
                .input_imag_0(input_imag_stage_0_m[i][STAGE_W-1:0]),
                .input_imag_1(input_imag_stage_1_m[i][STAGE_W-1:0]),
                .input_imag_2(input_imag_stage_2_m[i][STAGE_W-1:0]),
                .input_imag_3(input_imag_stage_3_m[i][STAGE_W-1:0]),
                
                .output_en(enable_stage_m[i + 1]),
                
                .output_real_0(temp_out_r0),
                .output_real_1(temp_out_r1),
                .output_real_2(temp_out_r2),
                .output_real_3(temp_out_r3),
                
                .output_imag_0(temp_out_i0),
                .output_imag_1(temp_out_i1),
                .output_imag_2(temp_out_i2),
                .output_imag_3(temp_out_i3)
            );

            // Assign exactly fitted output wires up to the uniform Max_width internal routing array
            assign stage_output_real_0_m[i] = temp_out_r0;
            assign stage_output_real_1_m[i] = temp_out_r1;
            assign stage_output_real_2_m[i] = temp_out_r2;
            assign stage_output_real_3_m[i] = temp_out_r3;

            assign stage_output_imag_0_m[i] = temp_out_i0;
            assign stage_output_imag_1_m[i] = temp_out_i1;
            assign stage_output_imag_2_m[i] = temp_out_i2;
            assign stage_output_imag_3_m[i] = temp_out_i3;

            // Prepare inputs for next growth stage by sign-extending the current output by 2 bits
            if (i < bit_growth_stages - 1) begin
                assign input_real_stage_0_m[i + 1] = {{2{temp_out_r0[STAGE_W-1]}}, temp_out_r0};
                assign input_real_stage_1_m[i + 1] = {{2{temp_out_r1[STAGE_W-1]}}, temp_out_r1};
                assign input_real_stage_2_m[i + 1] = {{2{temp_out_r2[STAGE_W-1]}}, temp_out_r2};
                assign input_real_stage_3_m[i + 1] = {{2{temp_out_r3[STAGE_W-1]}}, temp_out_r3};

                assign input_imag_stage_0_m[i + 1] = {{2{temp_out_i0[STAGE_W-1]}}, temp_out_i0};
                assign input_imag_stage_1_m[i + 1] = {{2{temp_out_i1[STAGE_W-1]}}, temp_out_i1};
                assign input_imag_stage_2_m[i + 1] = {{2{temp_out_i2[STAGE_W-1]}}, temp_out_i2};
                assign input_imag_stage_3_m[i + 1] = {{2{temp_out_i3[STAGE_W-1]}}, temp_out_i3};
            end
        end
    endgenerate

    // =========================================================================
    // Output Multiplexing
    // =========================================================================
    generate
        if(bit_growth_stages == 0) begin
            // Fallback for cases where bit growth is 0 or disabled
            assign output_en     = enable_stage[STAGE_NUM];
            
            assign output_real_0 = stage_output_real_0[STAGE_NUM-1];
            assign output_real_1 = stage_output_real_1[STAGE_NUM-1];
            assign output_real_2 = stage_output_real_2[STAGE_NUM-1];
            assign output_real_3 = stage_output_real_3[STAGE_NUM-1];
            
            assign output_imag_0 = stage_output_imag_0[STAGE_NUM-1];
            assign output_imag_1 = stage_output_imag_1[STAGE_NUM-1];
            assign output_imag_2 = stage_output_imag_2[STAGE_NUM-1];
            assign output_imag_3 = stage_output_imag_3[STAGE_NUM-1];
        end else begin
            // Standard route pulling from the grown path
            assign output_en     = enable_stage_m[bit_growth_stages];
            
            assign output_real_0 = stage_output_real_0_m[bit_growth_stages-1];
            assign output_real_1 = stage_output_real_1_m[bit_growth_stages-1];
            assign output_real_2 = stage_output_real_2_m[bit_growth_stages-1];
            assign output_real_3 = stage_output_real_3_m[bit_growth_stages-1];
            
            assign output_imag_0 = stage_output_imag_0_m[bit_growth_stages-1];
            assign output_imag_1 = stage_output_imag_1_m[bit_growth_stages-1];
            assign output_imag_2 = stage_output_imag_2_m[bit_growth_stages-1];
            assign output_imag_3 = stage_output_imag_3_m[bit_growth_stages-1];
        end
    endgenerate
    
endmodule