`timescale 1ns / 1ps

module Split_radix_secToLast_stage #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Num_of_samples = 256, //How many inputs
    parameter STAGE_NUM = 3, //Stage number of the FFT
    parameter SIMPLE_MULT = 1
)(
    input                   clock,       //  System Clock
    input                   reset,        //  Active High Asynchronous Reset
    input                   input_en,    //  Input Data Enable
    input                   step_mode, //  Step Mode Input
    input       [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,  //  Input Data (Real)
    input       [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,  //  Input Data (Imag)
    output reg              output_en,  //  Output Data Enable
    output reg  [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3,  //  Output Data (Real)
    output reg  [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3,   //  Output Data (Imag)
    output reg              step_mode_output
);
    localparam stage_num_bits = 2 - 1;
    localparam step_size = 16;
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;
    localparam Delay_mult = (SIMPLE_MULT == 1) ? 2 : 3; //Delay for the multiplier output, if simple mult is used then delay is 1, else delay is 2

    wire [stage_num_bits+1:0] butterfly_op_counter;
    wire [stage_num_bits+1:0] stride_segment_counter, butterfly_op_counter_output; //Here stride segment counter and butterfly are combined with mem_counter and mem_counter_read to save registers
    wire step_mode_in, step_mode_out, butterfly_op_counter_en;
    wire [stage_num_bits+1:0] stride_segment_counter_mem, butterfly_op_counter_mem;
    wire step_mode_in_mem, step_mode_out_mem, step_mode_out_butt, step_mode_out_output;

    wire signed [PROD:0] mulr_0, muli_0, mulr_3, muli_3; 
    wire signed [WIDTH-1:0] input_real_1_butt_step_0, input_imag_1_butt_step_0, input_real_2_butt_step_0, input_imag_2_butt_step_0;

    wire signed [WIDTH-1:0] input_real_1_butt_step_1, input_imag_1_butt_step_1, input_real_2_butt_step_1, input_imag_2_butt_step_1;
    wire signed [WIDTH-1:0] input_real_0_butt_step_1, input_imag_0_butt_step_1, input_real_3_butt_step_1, input_imag_3_butt_step_1;

    wire signed [WIDTH-1:0] input_real_1_butt_step_12, input_imag_1_butt_step_12, input_real_2_butt_step_12, input_imag_2_butt_step_12;
    wire signed [WIDTH-1:0] input_real_0_butt_step_12, input_imag_0_butt_step_12, input_real_3_butt_step_12, input_imag_3_butt_step_12;


    //Registers for multiplication and stalling before memory
    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    reg signed [WIDTH-1:0] input_real_0_rr, input_real_1_rr, input_real_2_rr, input_real_3_rr;
    reg signed [WIDTH-1:0] input_imag_0_rr, input_imag_1_rr, input_imag_2_rr, input_imag_3_rr;
    reg [WIDTH-1:0] input_real_0_mem, input_real_3_mem;
    reg [WIDTH-1:0] input_imag_0_mem, input_imag_3_mem;

    //Wires for butterfly inputs and outputs
    wire signed [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire signed [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;
    wire signed [WIDTH-1:0] x2_re, x2_im, y2_re, y2_im;
    wire signed [WIDTH-1:0] x3_re, x3_im, y3_re, y3_im;
    wire butterfly_out_ready, start_butterfly;

    // Twiddle wires
    wire signed [WIDTH/2 - 1:0] w0re, w0i, w1re, w1i;
    reg signed  [WIDTH/2 - 1:0] w0re_reg, w0i_reg, w1re_reg, w1i_reg;

    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples-1];
    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples-1];
    
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1 ;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_r, twiddle_index_1_r;

    generate
        if (Num_of_samples == 16) begin : gen_twiddle_16
            if(WIDTH == 32) begin : gen_twiddle_16_16bit
                initial begin
                    `include "gen_data/f_twiddle_16_16bit.vh"
                end
            end else if(WIDTH == 24) begin : gen_twiddle_16_24bit
                initial begin
                    `include "gen_data/f_twiddle_16_12bit.vh"
                end
            end else if(WIDTH == 16) begin : gen_twiddle_16_8bit
                initial begin
                    `include "gen_data/f_twiddle_16_8bit.vh"
                end
            end else if(WIDTH == 18) begin : gen_twiddle_16_9bit
                initial begin
                    `include "gen_data/f_twiddle_16_9bit.vh"
                end
            end
        end else if (Num_of_samples == 64) begin : gen_twiddle_64
            if(WIDTH == 32) begin : gen_twiddle_64_16bit
                initial begin
                    `include "gen_data/f_twiddle_64_16bit.vh"
                end
            end else if(WIDTH == 24) begin : gen_twiddle_64_12bit
                initial begin
                    `include "gen_data/f_twiddle_64_12bit.vh"
                end
            end else if(WIDTH == 16) begin : gen_twiddle_64_8bit
                initial begin
                    `include "gen_data/f_twiddle_64_8bit.vh"
                end
            end else if(WIDTH == 18) begin : gen_twiddle_64_9bit
                initial begin
                    `include "gen_data/f_twiddle_64_9bit.vh"
                end
            end
        end else if (Num_of_samples == 256) begin : gen_twiddle_256
            if(WIDTH == 32) begin : gen_twiddle_256_16bit
                initial begin
                    `include "gen_data/f_twiddle_256_16bit.vh"
                end
            end else if(WIDTH == 24) begin : gen_twiddle_256_12bit
                initial begin
                    `include "gen_data/f_twiddle_256_12bit.vh"
                end
            end else if(WIDTH == 16) begin : gen_twiddle_256_8bit
                initial begin
                    `include "gen_data/f_twiddle_256_8bit.vh"
                end
            end else if(WIDTH == 18) begin : gen_twiddle_256_9bit
                initial begin
                    `include "gen_data/f_twiddle_256_9bit.vh"
                end
            end
        end else if (Num_of_samples == 1024) begin : gen_twiddle_1024
            if(WIDTH == 32) begin : gen_twiddle_1024_16bit
                initial begin
                    `include "gen_data/f_twiddle_1024_16bit.vh"
                end
            end else if(WIDTH == 24) begin : gen_twiddle_1024_12bit
                initial begin
                    `include "gen_data/f_twiddle_1024_12bit.vh"
                end
            end else if(WIDTH == 16) begin : gen_twiddle_1024_8bit
                initial begin
                    `include "gen_data/f_twiddle_1024_8bit.vh"
                end
            end else if(WIDTH == 18) begin : gen_twiddle_1024_9bit
                initial begin
                    `include "gen_data/f_twiddle_1024_9bit.vh"
                end
            end
        end
    endgenerate

    control_unit_fsm_3rd_stage #(
        .stage_num_bits(stage_num_bits),
        .Num_of_samples(Num_of_samples),
        .step_size(step_size),
        .Num_of_samples_bits(Num_of_samples_bits)
    ) control_unit (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .step_mode_input(step_mode),
        .step_mode_in(step_mode_in),
        .step_mode_out(step_mode_out),
        .stride_segment_counter(stride_segment_counter),
        .butterfly_op_counter(butterfly_op_counter),
        .butterfly_op_counter_en(butterfly_op_counter_en)
    );

    assign twiddle_index_0 = (stride_segment_counter[stage_num_bits:0] << (STAGE_NUM - 2));
    assign twiddle_index_1 = ((stride_segment_counter[stage_num_bits:0] << 1) + stride_segment_counter[stage_num_bits:0]) << (STAGE_NUM - 2);

    assign w0re = w_real[twiddle_index_0_r];
    assign w0i = w_imag[twiddle_index_0_r];
    assign w1re = w_real[twiddle_index_1_r];
    assign w1i = w_imag[twiddle_index_1_r];

    ComplexMultiplier #(
        .WIDTH(WIDTH),
        .PROD(PROD),
        .SIMPLE_MULT(SIMPLE_MULT)
    ) complex_multiplier (
        .clock(clock),
        .a_re(input_real_0_rr), .a_im(input_imag_0_rr),
        .b_re(input_real_3_rr), .b_im(input_imag_3_rr),
        .w0re(w0re_reg), .w0im(w0i_reg),
        .w1re(w1re_reg), .w1im(w1i_reg),
        .out_a_re(mulr_0), .out_a_im(muli_0),
        .out_b_re(mulr_3), .out_b_im(muli_3)
    );


    //Delays for butterfly of step 0
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_nomul_r_1_step_0 (
        .clock(clock), .data_in(input_real_1), .data_out(input_real_1_butt_step_0)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_nomul_i_1_step_0 (
        .clock(clock), .data_in(input_imag_1), .data_out(input_imag_1_butt_step_0)
    );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_r_2_step_0 (
    //     .clock(clock), .data_in(input_real_2), .data_out(input_real_2_butt_step_0)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_i_2_step_0 (
    //     .clock(clock), .data_in(input_imag_2), .data_out(input_imag_2_butt_step_0)
    // );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_2_step_0 (
        .clock(clock), .data_in(input_real_2_butt_step_12), .data_out(input_real_2_butt_step_0)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_2_step_0 (
        .clock(clock), .data_in(input_imag_2_butt_step_12), .data_out(input_imag_2_butt_step_0)
    );

    //Delays for butterfly step 1

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_r_0_step_1 (
        .clock(clock), .data_in(input_real_0_butt_step_12), .data_out(input_real_0_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_i_0_step_1 (
        .clock(clock), .data_in(input_imag_0_butt_step_12), .data_out(input_imag_0_butt_step_1)
    );
    
    //This comment is the code the intuitive way before optimization
    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nouml_r_0_step_1 (
    //     .clock(clock), .data_in(input_real_0), .data_out(input_real_0_butt_step_1)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nouml_i_0_step_1 (
    //     .clock(clock), .data_in(input_imag_0), .data_out(input_imag_0_butt_step_1)
    // );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_1_step_1 (
        .clock(clock), .data_in(input_real_1_butt_step_0), .data_out(input_real_1_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_1_step_1 (
        .clock(clock), .data_in(input_imag_1_butt_step_0), .data_out(input_imag_1_butt_step_1)
    );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_nomul_r_1_step_1 (
    //     .clock(clock), .data_in(input_real_1), .data_out(input_real_1_butt_step_1)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_nomul_i_1_step_1 (
    //     .clock(clock), .data_in(input_imag_1), .data_out(input_imag_1_butt_step_1)
    // );

    assign input_real_2_butt_step_1 = input_real_2_butt_step_0;
    assign input_imag_2_butt_step_1 = input_imag_2_butt_step_0;

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_r_2_step_1 (
    //     .clock(clock), .data_in(input_real_2), .data_out(input_real_2_butt_step_1)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_i_2_step_1 (
    //     .clock(clock), .data_in(input_imag_2), .data_out(input_imag_2_butt_step_1)
    // );


    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_r_3_step_1 (
        .clock(clock), .data_in(input_real_3_butt_step_12), .data_out(input_real_3_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_i_3_step_1 (
        .clock(clock), .data_in(input_imag_3_butt_step_12), .data_out(input_imag_3_butt_step_1)
    );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_nouml_r_3_step_1 (
    //     .clock(clock), .data_in(input_real_3), .data_out(input_real_3_butt_step_1)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_nouml_i_3_step_1 (
    //     .clock(clock), .data_in(input_imag_3), .data_out(input_imag_3_butt_step_1)
    // );
    
    ///Second input of step 1 butterfly
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_r_0_step_12 (
        .clock(clock), .data_in(input_real_0), .data_out(input_real_0_butt_step_12)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_i_0_step_12 (
        .clock(clock), .data_in(input_imag_0), .data_out(input_imag_0_butt_step_12)
    );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_r_1_step_12 (
    //     .clock(clock), .data_in(input_real_1), .data_out(input_real_1_butt_step_12)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_nomul_i_1_step_12 (
    //     .clock(clock), .data_in(input_imag_1), .data_out(input_imag_1_butt_step_12)
    // );

    assign input_real_1_butt_step_12 = input_real_1_butt_step_0;
    assign input_imag_1_butt_step_12 = input_imag_1_butt_step_0;

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_2_step_12 (
        .clock(clock), .data_in(input_real_2), .data_out(input_real_2_butt_step_12)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_2_step_12 (
        .clock(clock), .data_in(input_imag_2), .data_out(input_imag_2_butt_step_12)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_nouml_r_3_step_12 (
        .clock(clock), .data_in(input_real_3), .data_out(input_real_3_butt_step_12)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_nouml_i_3_step_12 (
        .clock(clock), .data_in(input_imag_3), .data_out(input_imag_3_butt_step_12)
    );

    delay_reg_reset #(
        .WIDTH(stage_num_bits+2), .DELAY(1)
    ) delay_butterfly_op (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter), .data_out(butterfly_op_counter_mem)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(1)
    ) delay_step_mode_out (
        .clock(clock), .reset(reset), .data_in(step_mode_out), .data_out(step_mode_out_mem)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(1)
    ) delay_butt_en (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter_en), .data_out(start_butterfly)
    );

    wire signed [WIDTH-1:0] in_butte_step_1_0_real, in_butte_step_1_0_imag, in_butte_step_1_1_real, in_butte_step_1_1_imag;
    wire signed [WIDTH-1:0] in_butte_step_1_2_real, in_butte_step_1_2_imag, in_butte_step_1_3_real, in_butte_step_1_3_imag;


    assign in_butte_step_1_0_real = (butterfly_op_counter_mem[0] == 0) ? input_real_0_butt_step_1 : input_real_1_butt_step_1;
    assign in_butte_step_1_0_imag = (butterfly_op_counter_mem[0] == 0) ? input_imag_0_butt_step_1 : input_imag_1_butt_step_1;
    assign in_butte_step_1_1_real = (butterfly_op_counter_mem[0] == 0) ? input_real_2_butt_step_1 : input_real_3_butt_step_1;
    assign in_butte_step_1_1_imag = (butterfly_op_counter_mem[0] == 0) ? input_imag_2_butt_step_1 : input_imag_3_butt_step_1;
    assign in_butte_step_1_2_real = (butterfly_op_counter_mem[0] == 0) ? input_real_0_butt_step_12 : input_real_1_butt_step_12;
    assign in_butte_step_1_2_imag = (butterfly_op_counter_mem[0] == 0) ? input_imag_0_butt_step_12 : input_imag_1_butt_step_12;
    assign in_butte_step_1_3_real = (butterfly_op_counter_mem[0] == 0) ? input_real_2_butt_step_12 : input_real_3_butt_step_12;
    assign in_butte_step_1_3_imag = (butterfly_op_counter_mem[0] == 0) ? input_imag_2_butt_step_12 : input_imag_3_butt_step_12;

    assign x0_re = (step_mode_out_mem == 0) ? input_real_1_butt_step_0 : in_butte_step_1_0_real;
    assign x0_im = (step_mode_out_mem == 0) ? input_imag_1_butt_step_0 : in_butte_step_1_0_imag;
    assign x1_re = (step_mode_out_mem == 0) ? input_real_1 : in_butte_step_1_1_real;
    assign x1_im = (step_mode_out_mem == 0) ? input_imag_1 : in_butte_step_1_1_imag;
    assign x2_re = (step_mode_out_mem == 0) ? input_real_2_butt_step_0 : in_butte_step_1_2_real;
    assign x2_im = (step_mode_out_mem == 0) ? input_imag_2_butt_step_0 : in_butte_step_1_2_imag;
    assign x3_re = (step_mode_out_mem == 0) ? input_real_2 : in_butte_step_1_3_real;
    assign x3_im = (step_mode_out_mem == 0) ? input_imag_2 : in_butte_step_1_3_imag;

    wire [WIDTH-1:0] mult_out_1_r_upper, mult_out_2_r_upper, mult_out_3_r_upper, mult_out_4_r_upper;
    wire [WIDTH-1:0] mult_out_1_i_upper, mult_out_2_i_upper, mult_out_3_i_upper, mult_out_4_i_upper;

    wire [WIDTH-1:0] mult_out_1_r_lower, mult_out_2_r_lower, mult_out_3_r_lower, mult_out_4_r_lower;
    wire [WIDTH-1:0] mult_out_1_i_lower, mult_out_2_i_lower, mult_out_3_i_lower, mult_out_4_i_lower;

    wire [WIDTH-1:0] mult_out_1_r, mult_out_2_r, mult_out_3_r, mult_out_4_r;
    wire [WIDTH-1:0] mult_out_1_i, mult_out_2_i, mult_out_3_i, mult_out_4_i;

    //Multiplier delays before optimization
    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_mult_1_upper (
    //     .clock(clock), .data_in(mulr_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_r_upper)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(3)
    // ) delay_mult_1_i_upper (
    //     .clock(clock), .data_in(muli_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_i_upper)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_mult_2_upper (
    //     .clock(clock), .data_in(mulr_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_2_r_upper)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(2)
    // ) delay_mult_2_i_upper (
    //     .clock(clock), .data_in(muli_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_2_i_upper)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_mult_3_upper (
    //     .clock(clock), .data_in(mulr_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_3_r_upper)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_mult_3_i_upper (
    //     .clock(clock), .data_in(muli_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_3_i_upper)
    // );

    // assign mult_out_4_r_upper = mulr_0[PROD-2:PROD-WIDTH-1];
    // assign mult_out_4_i_upper = muli_0[PROD-2:PROD-WIDTH-1];

    //After optimization
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_upper (
        .clock(clock), .data_in(mult_out_2_r_upper), .data_out(mult_out_1_r_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_i_upper (
        .clock(clock), .data_in(mult_out_2_i_upper), .data_out(mult_out_1_i_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_2_upper (
        .clock(clock), .data_in(mult_out_3_r_upper), .data_out(mult_out_2_r_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_2_i_upper (
        .clock(clock), .data_in(mult_out_3_i_upper), .data_out(mult_out_2_i_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_3_upper (
        .clock(clock), .data_in(mulr_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_3_r_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_3_i_upper (
        .clock(clock), .data_in(muli_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_3_i_upper)
    );

    assign mult_out_4_r_upper = mulr_0[PROD-2:PROD-WIDTH-1];
    assign mult_out_4_i_upper = muli_0[PROD-2:PROD-WIDTH-1];

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_lower (
        .clock(clock), .data_in(mult_out_2_r_lower), .data_out(mult_out_1_r_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_2_lower (
        .clock(clock), .data_in(mult_out_3_r_lower), .data_out(mult_out_2_r_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_3_lower (
        .clock(clock), .data_in(mult_out_4_r_lower), .data_out(mult_out_3_r_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_4_lower (
        .clock(clock), .data_in(mulr_3[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_4_r_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_i_lower (
        .clock(clock), .data_in(mult_out_2_i_lower), .data_out(mult_out_1_i_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_2_i_lower (
        .clock(clock), .data_in(mult_out_3_i_lower), .data_out(mult_out_2_i_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_3_i_lower (
        .clock(clock), .data_in(mult_out_4_i_lower), .data_out(mult_out_3_i_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_4_i_lower (
        .clock(clock), .data_in(muli_3[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_4_i_lower)
    );

    butterfly_complex_core #(
        .WIDTH(WIDTH)
    ) b4 (
        .clock(clock), .reset(reset),
        .ar(x0_re), .ai(x0_im),
        .br(x1_re), .bi(x1_im),
        .cr(x2_re), .ci(x2_im),
        .dr(x3_re), .di(x3_im),
        .out1r(y0_re), .out1i(y0_im),
        .out2r(y1_re), .out2i(y1_im),
        .out3r(y2_re), .out3i(y2_im),
        .out4r(y3_re), .out4i(y3_im),
        .start(start_butterfly),
        .done(butterfly_out_ready)
    );

    wire [WIDTH-1:0] y0_re_de, y0_im_de, y1_re_de, y1_im_de, y2_re_de, y2_im_de, y3_re_de, y3_im_de;
    wire butterfly_out_ready_de;

    //Multiplier delay for butterfly outputs
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y0_re (
        .clock(clock), .data_in(y0_re), .data_out(y0_re_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y0_im (
        .clock(clock), .data_in(y0_im), .data_out(y0_im_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y1_re (
        .clock(clock), .data_in(y1_re), .data_out(y1_re_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y1_im (
        .clock(clock), .data_in(y1_im), .data_out(y1_im_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y2_re (
        .clock(clock), .data_in(y2_re), .data_out(y2_re_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y2_im (
        .clock(clock), .data_in(y2_im), .data_out(y2_im_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y3_re (
        .clock(clock), .data_in(y3_re), .data_out(y3_re_de)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult-2)
    ) delay_y3_im (
        .clock(clock), .data_in(y3_im), .data_out(y3_im_de)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(Delay_mult-2)
    ) delay_butterfly_out_ready (
        .clock(clock), .reset(reset), .data_in(butterfly_out_ready), .data_out(butterfly_out_ready_de)
    );

    //Final counter and step mode delays
    delay_reg_reset #(
        .WIDTH(stage_num_bits+2), .DELAY(3 + (Delay_mult - 2))
    ) delay_butterfly_op_output (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter_mem), .data_out(butterfly_op_counter_output)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(3 + (Delay_mult - 2))
    ) delay_step_mode_out_output (
        .clock(clock), .reset(reset), .data_in(step_mode_out_mem), .data_out(step_mode_out_output)
    );

    always @(posedge clock) begin
        twiddle_index_0_r <= twiddle_index_0;
        twiddle_index_1_r <= twiddle_index_1;
        w0i_reg <= w0i;
        w0re_reg <= w0re;
        w1i_reg <= w1i;
        w1re_reg <= w1re;
        input_real_0_r <= input_real_0;
        input_real_3_r <= input_real_3;
        input_imag_0_r <= input_imag_0;
        input_imag_3_r <= input_imag_3;
        input_real_0_rr <= input_real_0_r;
        input_imag_0_rr <= input_imag_0_r;
        input_real_3_rr <= input_real_3_r;
        input_imag_3_rr <= input_imag_3_r;

        if(step_mode_out_output == 0 && butterfly_op_counter_output[stage_num_bits] == 1) begin
            if(butterfly_op_counter_output[0] == 0) begin
                output_real_0 <= mult_out_1_r_upper;
                output_imag_0 <= mult_out_1_i_upper;
                output_real_1 <= mult_out_2_r_upper;
                output_imag_1 <= mult_out_2_i_upper;
                output_real_2 <= mult_out_3_r_upper;
                output_imag_2 <= mult_out_3_i_upper;
                output_real_3 <= mult_out_4_r_upper;
                output_imag_3 <= mult_out_4_i_upper;
            end else begin
                output_real_0 <= mult_out_1_r_lower;
                output_imag_0 <= mult_out_1_i_lower;
                output_real_1 <= mult_out_2_r_lower;
                output_imag_1 <= mult_out_2_i_lower;
                output_real_2 <= mult_out_3_r_lower;
                output_imag_2 <= mult_out_3_i_lower;
                output_real_3 <= mult_out_4_r_lower;
                output_imag_3 <= mult_out_4_i_lower;
            end
        end else begin
            output_real_0 <= y0_re_de;
            output_imag_0 <= y0_im_de;
            output_real_1 <= y1_re_de;
            output_imag_1 <= y1_im_de;
            output_real_2 <= y2_re_de;
            output_imag_2 <= y2_im_de;
            output_real_3 <= y3_re_de;
            output_imag_3 <= y3_im_de;
        end
        step_mode_output <= step_mode_out_output;

        if(reset) begin
            output_en <= 0;
        end else begin
            output_en <= butterfly_out_ready_de;
        end
    end
endmodule