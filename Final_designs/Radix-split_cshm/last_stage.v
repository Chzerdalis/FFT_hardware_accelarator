`timescale 1ns / 1ps

module Split_radix_Last_stage #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Tw_WIDTH = 8,
    parameter Num_of_samples = 256, //How many inputs
    parameter STAGE_NUM = 3, //Stage number of the FFT
    parameter KEY_WIDTH = 14,
    parameter   twiddle_file_real_1 = "../Data/f_twiddle_real.mem",
    parameter   twiddle_file_imag_1 = "../Data/f_twiddle_imag.mem",
    parameter   twiddle_file_real_2 = "../Data/f_twiddle_real.mem",
    parameter   twiddle_file_imag_2 = "../Data/f_twiddle_imag.mem"
)(
    input                   clock,       //  System Clock
    input                   reset,        //  Active High Asynchronous Reset
    input                   input_en,    //  Input Data Enable
    input                   step_mode, //  Step Mode Input
    input       [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,  //  Input Data (Real)
    input       [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,  //  Input Data (Imag)
    output reg              output_en,  //  Output Data Enable
    output reg  [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3,  //  Output Data (Real)
    output reg  [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3   //  Output Data (Imag)
);
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    localparam TW = Tw_WIDTH;
    localparam PROD = WIDTH + TW;
    localparam Delay_mult = 6; 
    localparam twiddle_size = 2;

    wire butterfly_op_counter;
    wire stride_segment_counter, butterfly_op_counter_output; //Here stride segment counter and butterfly are combined with mem_counter and mem_counter_read to save registers
    wire step_mode_in, step_mode_out, butterfly_op_counter_en;
    wire stride_segment_counter_mem, butterfly_op_counter_mem;
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
    wire signed [KEY_WIDTH - 1:0] w0re, w0i, w1re, w1i;
    reg signed  [KEY_WIDTH - 1:0] w0re_reg, w0i_reg, w1re_reg, w1i_reg;

    (* ram_style = "distributed" *) reg [KEY_WIDTH - 1:0] w_real_1 [0:twiddle_size-1];
    (* ram_style = "distributed" *) reg [KEY_WIDTH - 1:0] w_imag_1 [0:twiddle_size-1];
    (* ram_style = "distributed" *) reg [KEY_WIDTH - 1:0] w_real_2 [0:twiddle_size-1];
    (* ram_style = "distributed" *) reg [KEY_WIDTH - 1:0] w_imag_2 [0:twiddle_size-1];
    
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1 ;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_r, twiddle_index_1_r;

    initial begin
        $readmemh(twiddle_file_real_1, w_real_1);
        $readmemh(twiddle_file_imag_1, w_imag_1);

        $readmemh(twiddle_file_real_2, w_real_2);
        $readmemh(twiddle_file_imag_2, w_imag_2);
    end

    control_unit_fsm_last_stage #(
        .Num_of_samples(Num_of_samples),
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

    assign twiddle_index_0 = (stride_segment_counter);

    // assign twiddle_index_0 = (stride_segment_counter << (STAGE_NUM - 2));
    // assign twiddle_index_1 = ((stride_segment_counter << 1) + stride_segment_counter) << (STAGE_NUM - 2);

    assign w0re = w_real_1[twiddle_index_0_r];
    assign w0i = w_imag_1[twiddle_index_0_r];
    assign w1re = w_real_2[twiddle_index_0_r];
    assign w1i = w_imag_2[twiddle_index_0_r];

    ComplexMultiplier #(
        .WIDTH(WIDTH),
        .Tw_WIDTH(Tw_WIDTH),
        .PROD(PROD),
        .KEY_WIDTH(KEY_WIDTH)
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
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_1_step_0 (
        .clock(clock), .data_in(input_real_1), .data_out(input_real_1_butt_step_0)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_1_step_0 (
        .clock(clock), .data_in(input_imag_1), .data_out(input_imag_1_butt_step_0)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_2_step_0 (
        .clock(clock), .data_in(input_real_2), .data_out(input_real_2_butt_step_0)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_2_step_0 (
        .clock(clock), .data_in(input_imag_2), .data_out(input_imag_2_butt_step_0)
    );

    //Delays for butterfly step 1

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_r_0_step_1 (
        .clock(clock), .data_in(input_real_0), .data_out(input_real_0_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_i_0_step_1 (
        .clock(clock), .data_in(input_imag_0), .data_out(input_imag_0_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_1_step_1 (
        .clock(clock), .data_in(input_real_1), .data_out(input_real_1_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_1_step_1 (
        .clock(clock), .data_in(input_imag_1), .data_out(input_imag_1_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_r_2_step_1 (
        .clock(clock), .data_in(input_real_2), .data_out(input_real_2_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nomul_i_2_step_1 (
        .clock(clock), .data_in(input_imag_2), .data_out(input_imag_2_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_r_3_step_1 (
        .clock(clock), .data_in(input_real_3), .data_out(input_real_3_butt_step_1)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_nouml_i_3_step_1 (
        .clock(clock), .data_in(input_imag_3), .data_out(input_imag_3_butt_step_1)
    );

    assign x0_re = (step_mode_out == 0) ? input_real_1_butt_step_0 : input_real_0_butt_step_1;
    assign x0_im = (step_mode_out == 0) ? input_imag_1_butt_step_0 : input_imag_0_butt_step_1;
    assign x1_re = (step_mode_out == 0) ? input_real_1 : input_real_1_butt_step_1;
    assign x1_im = (step_mode_out == 0) ? input_imag_1 : input_imag_1_butt_step_1;
    assign x2_re = (step_mode_out == 0) ? input_real_2_butt_step_0 : input_real_2_butt_step_1;
    assign x2_im = (step_mode_out == 0) ? input_imag_2_butt_step_0 : input_imag_2_butt_step_1;
    assign x3_re = (step_mode_out == 0) ? input_real_2 : input_real_3_butt_step_1;
    assign x3_im = (step_mode_out == 0) ? input_imag_2 : input_imag_3_butt_step_1;

    assign start_butterfly = butterfly_op_counter_en;

    wire [WIDTH-1:0] mult_out_1_r_upper, mult_out_2_r_upper, mult_out_3_r_upper, mult_out_4_r_upper;
    wire [WIDTH-1:0] mult_out_1_i_upper, mult_out_2_i_upper, mult_out_3_i_upper, mult_out_4_i_upper;

    wire [WIDTH-1:0] mult_out_1_r_lower, mult_out_2_r_lower, mult_out_3_r_lower, mult_out_4_r_lower;
    wire [WIDTH-1:0] mult_out_1_i_lower, mult_out_2_i_lower, mult_out_3_i_lower, mult_out_4_i_lower;

    wire [WIDTH-1:0] mult_out_1_r, mult_out_2_r, mult_out_3_r, mult_out_4_r;
    wire [WIDTH-1:0] mult_out_1_i, mult_out_2_i, mult_out_3_i, mult_out_4_i;

    //Multiplier delays
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_upper (
        .clock(clock), .data_in(mulr_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_r_upper)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_i_upper (
        .clock(clock), .data_in(muli_0[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_i_upper)
    );

    assign mult_out_2_r_upper = mulr_0[PROD-2:PROD-WIDTH-1];
    assign mult_out_2_i_upper = muli_0[PROD-2:PROD-WIDTH-1];

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_lower (
        .clock(clock), .data_in(mulr_3[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_r_lower)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(1)
    ) delay_mult_1_i_lower (
        .clock(clock), .data_in(muli_3[PROD-2:PROD-WIDTH-1]), .data_out(mult_out_1_i_lower)
    );

    assign mult_out_2_r_lower = mulr_3[PROD-2:PROD-WIDTH-1];
    assign mult_out_2_i_lower = muli_3[PROD-2:PROD-WIDTH-1];

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

    wire signed[WIDTH-1:0] y0_re_delayed, y0_im_delayed, y1_re_delayed, y1_im_delayed, y2_re_delayed, y2_im_delayed, y3_re_delayed, y3_im_delayed;
    wire butterfly_out_ready_delayed;

    //Butterflyoutput delays
    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_1 (
        .clock(clock), .data_in(y0_re), .data_out(y0_re_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_2 (
        .clock(clock), .data_in(y0_im), .data_out(y0_im_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_3 (
        .clock(clock), .data_in(y1_re), .data_out(y1_re_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_4 (
        .clock(clock), .data_in(y1_im), .data_out(y1_im_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_5 (
        .clock(clock), .data_in(y2_re), .data_out(y2_re_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_6 (
        .clock(clock), .data_in(y2_im), .data_out(y2_im_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_7 (
        .clock(clock), .data_in(y3_re), .data_out(y3_re_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_8 (
        .clock(clock), .data_in(y3_im), .data_out(y3_im_delayed)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(Delay_mult - 2)
    ) delay_butterfly_out_ready (
        .clock(clock), .reset(reset), .data_in(butterfly_out_ready), .data_out(butterfly_out_ready_delayed)
    );

    //Final counter and step mode delays

    delay_reg_reset #(
        .WIDTH(1), .DELAY(3 + Delay_mult - 2)
    ) delay_step_mode_out_output (
        .clock(clock), .reset(reset), .data_in(step_mode_out), .data_out(step_mode_out_output)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(3 + Delay_mult - 2)
    ) delay_butterfly_op_counter (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter), .data_out(butterfly_op_counter_output)
    );

    //Last additions
    wire signed [WIDTH-1:0] add_0_0_re, add_0_1_re, add_1_0_re, add_1_1_re;
    wire signed [WIDTH-1:0] add_0_0_im, add_0_1_im, add_1_0_im, add_1_1_im;
    wire signed [WIDTH-1:0] res_0_0_re, res_0_1_re, res_1_0_re, res_1_1_re;
    wire signed [WIDTH-1:0] res_0_0_im, res_0_1_im, res_1_0_im, res_1_1_im;
    wire signed [WIDTH-1:0] y0_re_dede, y0_im_dede, y3_re_dede, y3_im_dede;
    wire step_mode_out_final, butterfly_op_counter_final;

    assign add_0_0_re = (step_mode_out_output == 0 && butterfly_op_counter_output == 1) ? mult_out_1_r_upper : y1_re_delayed;
    assign add_0_0_im = (step_mode_out_output == 0 && butterfly_op_counter_output == 1) ? mult_out_1_i_upper : y1_im_delayed;
    assign add_0_1_re = (step_mode_out_output == 0 && butterfly_op_counter_output == 1) ? mult_out_2_r_upper : y2_re_delayed;
    assign add_0_1_im = (step_mode_out_output == 0 && butterfly_op_counter_output == 1) ? mult_out_2_i_upper : y2_im_delayed;

    assign add_1_0_re = mult_out_1_r_lower;
    assign add_1_0_im = mult_out_1_i_lower;
    assign add_1_1_re = mult_out_2_r_lower;
    assign add_1_1_im = mult_out_2_i_lower;

    assign res_0_0_re = add_0_0_re + add_0_1_re;
    assign res_0_0_im = add_0_0_im + add_0_1_im;
    assign res_0_1_re = add_0_0_re - add_0_1_re;
    assign res_0_1_im = add_0_0_im - add_0_1_im;

    assign res_1_0_re = add_1_0_re + add_1_1_re;
    assign res_1_0_im = add_1_0_im + add_1_1_im;
    assign res_1_1_re = add_1_0_re - add_1_1_re;
    assign res_1_1_im = add_1_0_im - add_1_1_im;

    //******************
    //Might need them for pipelining, but for now they are not needed, if do also add one cycle to the butterfly_out_ready

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_res_0_0_re (
    //     .clock(clock), .data_in(y0_re_delayed), .data_out(y0_re_dede)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_res_0_0_im (
    //     .clock(clock), .data_in(y0_im_delayed), .data_out(y0_im_dede)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_res_1_1_re (
    //     .clock(clock), .data_in(y3_re_delayed), .data_out(y3_re_dede)
    // );

    // delay_reg #(
    //     .WIDTH(WIDTH), .DELAY(1)
    // ) delay_res_1_1_im (
    //     .clock(clock), .data_in(y3_im_delayed), .data_out(y3_im_dede)
    // );

    // delay_reg_reset #(
    //     .WIDTH(1), .DELAY(1)
    // ) delay_butterfly_out_ready_final (
    //     .clock(clock), .reset(reset), .data_in(step_mode_out_output), .data_out(step_mode_out_final)
    // );

    // delay_reg_reset #(
    //     .WIDTH(1), .DELAY(1)
    // ) delay_butterfly_out_ready_final_2 (
    //     .clock(clock), .reset(reset), .data_in(butterfly_op_counter_output), .data_out(butterfly_op_counter_final)
    // );

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

        if(step_mode_out_output == 0 && butterfly_op_counter_output == 1) begin
            output_real_0 <= res_0_0_re;
            output_imag_0 <= res_0_0_im;
            output_real_1 <= res_0_1_re;
            output_imag_1 <= res_0_1_im;
            output_real_2 <= res_1_0_re;
            output_imag_2 <= res_1_0_im;
            output_real_3 <= res_1_1_re;
            output_imag_3 <= res_1_1_im;
        end else begin
            output_real_2 <= y0_re_delayed;
            output_imag_2 <= y0_im_delayed;
            output_real_0 <= res_0_0_re;
            output_imag_0 <= res_0_0_im;
            output_real_1 <= res_0_1_re;
            output_imag_1 <= res_0_1_im;
            output_real_3 <= y3_re_delayed;
            output_imag_3 <= y3_im_delayed;
        end

        output_en <= butterfly_out_ready_delayed;
    end
endmodule