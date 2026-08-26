`timescale 1ns/1ps

`include "twiddle_pkg.vh"

module fft_top #(
    parameter WIDTH = 11,
    parameter Tw_WIDTH = 9,
    parameter Num_of_samples = 256,
    parameter SimpleMult = 1,
    parameter Fast_DSP = 0,
    parameter carry_save = 1,
    parameter Bram = 0,
    parameter bit_growth = 1,
    parameter STAGE_NUM = $clog2(Num_of_samples),
    parameter Max_stage_num = (bit_growth == 1) ? (WIDTH - Tw_WIDTH) : STAGE_NUM,
    parameter Current_bits_stages = (STAGE_NUM - Max_stage_num > 0) ? (Max_stage_num) : STAGE_NUM,
    parameter bit_growth_stages = (STAGE_NUM - Max_stage_num > 0) ? (STAGE_NUM - Max_stage_num) : 0,
    parameter Max_width = WIDTH + bit_growth_stages
)(
    input                   clock,
    input                   reset,
    input                   input_en,
    input       [WIDTH-1:0] input_real_0,
    input       [WIDTH-1:0] input_real_1,
    input       [WIDTH-1:0] input_imag_0,
    input       [WIDTH-1:0] input_imag_1,
    output                  output_en,
    output      [Max_width-1:0] output_real_0,
    output      [Max_width-1:0] output_real_1,
    output      [Max_width-1:0] output_imag_0,
    output      [Max_width-1:0] output_imag_1
);
    
    // Intermediate wires for connecting stages (2-parallel paths)
    wire [WIDTH-1:0] input_real_stage_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_real_stage_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_imag_stage_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] input_imag_stage_1 [0:Current_bits_stages-1];

    wire [WIDTH-1:0] stage_output_real_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_real_1 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_imag_0 [0:Current_bits_stages-1];
    wire [WIDTH-1:0] stage_output_imag_1 [0:Current_bits_stages-1];

    wire enable_stage [0:Current_bits_stages];

    // Initialization: Map top-level inputs to the first stage wires
    assign input_real_stage_0[0] = input_real_0;
    assign input_real_stage_1[0] = input_real_1;
    assign input_imag_stage_0[0] = input_imag_0;
    assign input_imag_stage_1[0] = input_imag_1;

    assign enable_stage[0] = input_en;

    genvar i;
    generate

        for (i = 0; i < Current_bits_stages; i = i + 1) begin : gen_stages
            // Instantiate the Radix-2 SDF Unit
            SdfUnit2_fast #(
                .WIDTH(WIDTH),
                .Tw_WIDTH(Tw_WIDTH),
                .STAGE_NUM(i + 1),
                .Num_of_samples(Num_of_samples),
                .twiddle_file_real(`GET_REAL_FILE(i)),
                .twiddle_file_imag(`GET_IMAG_FILE(i)),
                // .twiddle_file_real(twiddle_pkg::get_real_file(i)),
                // .twiddle_file_imag(twiddle_pkg::get_imag_file(i)),
                .SimpleMult(SimpleMult),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .Bram(Bram)
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
            if (i < Current_bits_stages - 1) begin
                assign input_real_stage_0[i + 1] = stage_output_real_0[i];
                assign input_real_stage_1[i + 1] = stage_output_real_1[i];
                assign input_imag_stage_0[i + 1] = stage_output_imag_0[i];
                assign input_imag_stage_1[i + 1] = stage_output_imag_1[i];
            end
        end
    endgenerate

    wire [Max_width-1:0] input_real_stage_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_real_stage_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_imag_stage_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] input_imag_stage_1_m [0:bit_growth_stages-1];

    wire [Max_width-1:0] stage_output_real_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_real_1_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_imag_0_m [0:bit_growth_stages-1];
    wire [Max_width-1:0] stage_output_imag_1_m [0:bit_growth_stages-1];

    wire enable_stage_m [0:bit_growth_stages];

    // Initialization: Map top-level inputs to the first stage wires
    assign input_real_stage_0_m[0] = {stage_output_real_0[Current_bits_stages-1][WIDTH-1], stage_output_real_0[Current_bits_stages-1]};
    assign input_real_stage_1_m[0] = {stage_output_real_1[Current_bits_stages-1][WIDTH-1], stage_output_real_1[Current_bits_stages-1]};
    assign input_imag_stage_0_m[0] = {stage_output_imag_0[Current_bits_stages-1][WIDTH-1], stage_output_imag_0[Current_bits_stages-1]};
    assign input_imag_stage_1_m[0] = {stage_output_imag_1[Current_bits_stages-1][WIDTH-1], stage_output_imag_1[Current_bits_stages-1]};

    assign enable_stage_m[0] = enable_stage[Current_bits_stages];

    generate
        for (i = 0; i < bit_growth_stages; i = i + 1) begin : gen_stages_2
            
            // 1. Calculate exact width for this iteration
            localparam STAGE_W = WIDTH + 1 * (i + 1);
            //localparam STAGE_TW_W = Tw_WIDTH +  1 * (i + 1);

            // 2. Create intermediate wires that PERFECTLY match the module's output width
            wire [STAGE_W-1:0] temp_out_r0;
            wire [STAGE_W-1:0] temp_out_r1;
            wire [STAGE_W-1:0] temp_out_i0;
            wire [STAGE_W-1:0] temp_out_i1;

            // Instantiate the Radix-2 SDF Unit
            SdfUnit2_fast #(
                .WIDTH(STAGE_W),
                .Tw_WIDTH(Tw_WIDTH),
                .STAGE_NUM(i + 1 + Current_bits_stages),
                .Num_of_samples(Num_of_samples),
                .twiddle_file_real(`GET_REAL_FILE(i + Current_bits_stages)),
                .twiddle_file_imag(`GET_IMAG_FILE(i + Current_bits_stages)),
                // .twiddle_file_real(twiddle_pkg::get_real_file(i + Current_bits_stages)),
                // .twiddle_file_imag(twiddle_pkg::get_imag_file(i + Current_bits_stages)),
                .SimpleMult(SimpleMult),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .Bram(Bram)
            ) stage_inst (
                .clock(clock),
                .reset(reset),
                .input_en(enable_stage_m[i]),
                
                // Input slicing works fine
                .input_real_0(input_real_stage_0_m[i][STAGE_W-1:0]),
                .input_real_1(input_real_stage_1_m[i][STAGE_W-1:0]),
                .input_imag_0(input_imag_stage_0_m[i][STAGE_W-1:0]),
                .input_imag_1(input_imag_stage_1_m[i][STAGE_W-1:0]),
                
                .output_en(enable_stage_m[i + 1]),
                
                // 3. Connect outputs to the perfectly sized temp wires
                .output_real_0(temp_out_r0),
                .output_real_1(temp_out_r1),
                .output_imag_0(temp_out_i0),
                .output_imag_1(temp_out_i1)
            );

            // 4. Safely assign the temp wires up to the Max_width arrays (Verilator can handle this safely)
            assign stage_output_real_0_m[i] = temp_out_r0;
            assign stage_output_real_1_m[i] = temp_out_r1;
            assign stage_output_imag_0_m[i] = temp_out_i0;
            assign stage_output_imag_1_m[i] = temp_out_i1;

            // 5. Connect output of stage i to input of stage i + 1 using the temp wires
            if (i < bit_growth_stages - 1) begin
                assign input_real_stage_0_m[i + 1] = {temp_out_r0[STAGE_W-1], temp_out_r0};
                assign input_real_stage_1_m[i + 1] = {temp_out_r1[STAGE_W-1], temp_out_r1};
                assign input_imag_stage_0_m[i + 1] = {temp_out_i0[STAGE_W-1], temp_out_i0};
                assign input_imag_stage_1_m[i + 1] = {temp_out_i1[STAGE_W-1], temp_out_i1};
            end
        end
    endgenerate

    generate
        if(bit_growth_stages == 0) begin
            assign output_en     = enable_stage[STAGE_NUM];
            assign output_real_0 = stage_output_real_0[STAGE_NUM-1];
            assign output_real_1 = stage_output_real_1[STAGE_NUM-1];
            assign output_imag_0 = stage_output_imag_0[STAGE_NUM-1];
            assign output_imag_1 = stage_output_imag_1[STAGE_NUM-1];
        end else begin
            assign output_en     = enable_stage_m[bit_growth_stages];
            assign output_real_0 = stage_output_real_0_m[bit_growth_stages-1];
            assign output_real_1 = stage_output_real_1_m[bit_growth_stages-1];
            assign output_imag_0 = stage_output_imag_0_m[bit_growth_stages-1];
            assign output_imag_1 = stage_output_imag_1_m[bit_growth_stages-1];
        end
    endgenerate
    
endmodule


