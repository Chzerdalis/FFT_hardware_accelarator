`timescale 1ns / 1ps

module Split_radix_SecondStage #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Num_of_samples = 256, //How many inputs
    parameter SIMPLE_MULT = 1
)(
    input                   clock,       //  System Clock
    input                   reset,        //  Active High Asynchronous Reset
    input                   input_en,    //  Input Data Enable
    input       [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,  //  Input Data (Real)
    input       [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,  //  Input Data (Imag)
    output reg              output_en,  //  Output Data Enable
    output reg  [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3,  //  Output Data (Real)
    output reg  [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3   //  Output Data (Imag)
);

    localparam Depth = Num_of_samples/8;
    localparam stage_num_bits = $clog2(Num_of_samples/4) - 1;
    localparam sn = stage_num_bits + 3;
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;
    localparam Delay_mult = (SIMPLE_MULT == 1) ? 2 : 3;

    //Wires needed for stages > 1
    //Counters to calculate the twiddle factors and manage the delay buffers
    reg [stage_num_bits+1:0] butterfly_op_counter;
    reg [stage_num_bits+1:0] stride_segment_counter;
    reg butterfly_op_counter_en;

    wire [stage_num_bits+1:0] stride_segment_counter_mem, butterfly_op_counter_mem;
    wire butterfly_op_counter_output;


    wire signed [PROD:0] mulr_0, muli_0, mulr_3, muli_3; 
    wire signed [WIDTH-1:0] input_real_1_nomul, input_imag_1_nomul, input_real_2_nomul, input_imag_2_nomul;
    wire signed [WIDTH-1:0] input_real_1_butt, input_imag_1_butt, input_real_2_butt, input_imag_2_butt;
    reg [WIDTH-1:0] input_real_0_mem, input_real_3_mem;
    reg [WIDTH-1:0] input_imag_0_mem, input_imag_3_mem;

    //Counter to flush the pipeline at the end of the data
    reg [Num_of_samples_bits-1:0] flush_count;
    reg start_out;

    //Memoryoutput wires
    wire [WIDTH-1:0] mem_out_real_0, mem_out_imag_0;
    wire [WIDTH-1:0] mem_out_real_1, mem_out_imag_1;
    wire [WIDTH-1:0] mem_out_real_2, mem_out_imag_2;
    wire [WIDTH-1:0] mem_out_real_3, mem_out_imag_3;

    wire [WIDTH-1:0] mem_out_real_0_output, mem_out_imag_0_output;
    wire [WIDTH-1:0] mem_out_real_1_output, mem_out_imag_1_output;
    wire [WIDTH-1:0] mem_out_real_2_output, mem_out_imag_2_output;
    wire [WIDTH-1:0] mem_out_real_3_output, mem_out_imag_3_output;

    //end wires for stages > 1

    //Registers for multiplication and stalling before memory
    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    reg signed [WIDTH-1:0] input_real_0_rr, input_real_1_rr, input_real_2_rr, input_real_3_rr;
    reg signed [WIDTH-1:0] input_imag_0_rr, input_imag_1_rr, input_imag_2_rr, input_imag_3_rr;

    reg  start_butterfly_r;


    //Wires for butterfly inputs and outputs
    wire [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;
    wire [WIDTH-1:0] x2_re, x2_im, y2_re, y2_im;
    wire [WIDTH-1:0] x3_re, x3_im, y3_re, y3_im;
    wire butterfly_out_ready, start_butterfly;

    // Twiddle wires
    wire signed [WIDTH/2 - 1:0] w0re, w0i, w1re, w1i;
    reg signed  [WIDTH/2 - 1:0] w0re_reg, w0i_reg, w1re_reg, w1i_reg;

    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples-1];
    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples-1];
    
//    (* rom_style = "block" *) reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples/2-1];
//    (* rom_style = "block" *) reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples/2-1];
    
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

    //Manage counters, Control logic for memory and butterfly operation enable signals
    if(Num_of_samples > 16) begin : gen_input_logic 
        always @(posedge clock) begin
            if (reset) begin
                stride_segment_counter <= {(sn-1){1'b0}};
                butterfly_op_counter <= {(sn-1){1'b0}};
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    if(stride_segment_counter[stage_num_bits:0] == {1'b0, {(sn-4){1'b1}}, 1'b0} && butterfly_op_counter_en == 0) begin
                        butterfly_op_counter_en <= 1'b1;
                        butterfly_op_counter <= butterfly_op_counter;
                        flush_count <= Num_of_samples/4 - 1;
                    end else if (butterfly_op_counter_en) begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter;
                        butterfly_op_counter_en <= 1'b0;
                        flush_count <= flush_count;
                    end

                    stride_segment_counter <= stride_segment_counter + 1'b1;
                end else begin
                    if (flush_count == 0) begin
                        butterfly_op_counter <= {(sn-1){1'b0}};
                        stride_segment_counter <= {(sn-1){1'b0}};
                        butterfly_op_counter_en <= 1'b0;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        butterfly_op_counter_en <= butterfly_op_counter_en;
                        flush_count <= flush_count - 1'b1;
                    end
                end
            end
        end
    end else begin
        //This logic is for a 16 point second stage, the memory is also custom for this
        always @(posedge clock) begin
            if (reset) begin
                stride_segment_counter <= {(sn-1){1'b0}};
                butterfly_op_counter <= {(sn-1){1'b0}};
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    //Butterfly enable starts one cycle earlier than usual
                    //To avoid corraption of data in memory duo to overwrite
                    if(stride_segment_counter[stage_num_bits:0] == 2'b00 && butterfly_op_counter_en == 0) begin
                        butterfly_op_counter_en <= 1'b1;
                        butterfly_op_counter <= butterfly_op_counter;
                        flush_count <= Num_of_samples/4 - 1;
                    end else if (butterfly_op_counter_en) begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter;
                        butterfly_op_counter_en <= 1'b0;
                        flush_count <= flush_count;
                    end

                    stride_segment_counter <= stride_segment_counter + 1'b1;
                end else begin
                    if (flush_count == 0) begin
                        butterfly_op_counter <= {(sn-1){1'b0}};
                        stride_segment_counter <= {(sn-1){1'b0}};
                        butterfly_op_counter_en <= 1'b0;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        butterfly_op_counter_en <= butterfly_op_counter_en;
                        flush_count <= flush_count - 1'b1;
                    end
                end
            end
        end
    end

    //Calculating twiddle index
    assign twiddle_index_0 = (stride_segment_counter[stage_num_bits:0]);
    assign twiddle_index_1 = ((stride_segment_counter[stage_num_bits:0]<<1) + stride_segment_counter[stage_num_bits:0]);

    //Next pipeline feching the twiddle factors from ROM
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

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult + 1)
    ) delay_nomul_r_1 (
        .clock(clock), .data_in(input_real_1_rr), .data_out(input_real_1_nomul)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult + 1)
    ) delay_nomul_i_1 (
        .clock(clock), .data_in(input_imag_1_rr), .data_out(input_imag_1_nomul)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult + 1)
    ) delay_nomul_r_2 (
        .clock(clock), .data_in(input_real_2_rr), .data_out(input_real_2_nomul)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(Delay_mult + 1)
    ) delay_nomul_i_2 (
        .clock(clock), .data_in(input_imag_2_rr), .data_out(input_imag_2_nomul)
    );

    delay_reg_reset #(
        .WIDTH(stage_num_bits+2), .DELAY(Delay_mult+3)
    ) delay_stride_seg (
        .clock(clock), .reset(reset), .data_in(stride_segment_counter), .data_out(stride_segment_counter_mem)
    );

    delay_reg_reset #(
        .WIDTH(stage_num_bits+2), .DELAY(Delay_mult+3)
    ) delay_butterfly_op (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter), .data_out(butterfly_op_counter_mem)
    );


    //Na afaireseis ta mem
    memory_second_stage #(
        .WIDTH(WIDTH),
        .DEPTH(Depth),
        .stage_num_bits(stage_num_bits)
    ) mem (
        .clock(clock),
        .reset(reset),
        .stride_segment_counter(stride_segment_counter_mem[stage_num_bits:0]),
        .butterfly_op_counter(butterfly_op_counter_mem[stage_num_bits:0]),
        .mem_counter(stride_segment_counter_mem),
        .mem_counter_read(butterfly_op_counter_mem),
        .input_real_0(input_real_0_mem), .input_imag_0(input_imag_0_mem),
        .input_real_1(input_real_1_nomul), .input_imag_1(input_imag_1_nomul),
        .input_real_2(input_real_2_nomul), .input_imag_2(input_imag_2_nomul),
        .input_real_3(input_real_3_mem), .input_imag_3(input_imag_3_mem),
        .output_real_0(mem_out_real_0), .output_imag_0(mem_out_imag_0),
        .output_real_1(mem_out_real_1), .output_imag_1(mem_out_imag_1),
        .output_real_2(mem_out_real_2), .output_imag_2(mem_out_imag_2),
        .output_real_3(mem_out_real_3), .output_imag_3(mem_out_imag_3)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_pass_thought_r_1 (
        .clock(clock), .data_in(input_real_1_nomul), .data_out(input_real_1_butt)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_pass_thought_i_1 (
        .clock(clock), .data_in(input_imag_1_nomul), .data_out(input_imag_1_butt)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_pass_thought_r_2 (
        .clock(clock), .data_in(input_real_2_nomul), .data_out(input_real_2_butt)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(2)
    ) delay_pass_thought_i_2 (
        .clock(clock), .data_in(input_imag_2_nomul), .data_out(input_imag_2_butt)
    );

    //Manage butterfly inputs based on stage number
    assign x0_re =  mem_out_real_1;
    assign x0_im =  mem_out_imag_1;
    assign x1_re =  input_real_1_butt;
    assign x1_im =  input_imag_1_butt;
    assign x2_re =  mem_out_real_3;
    assign x2_im =  mem_out_imag_3;
    assign x3_re =  input_real_2_butt;
    assign x3_im =  input_imag_2_butt;

     delay_reg_reset #(
        .WIDTH(1), .DELAY(Delay_mult+3+3)
    ) delay_butt_en (
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter_en), .data_out(start_butterfly)
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

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_r_0 (
        .clock(clock), .data_in(mem_out_real_0), .data_out(mem_out_real_0_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_i_0 (
        .clock(clock), .data_in(mem_out_imag_0), .data_out(mem_out_imag_0_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_r_1 (
        .clock(clock), .data_in(mem_out_real_1), .data_out(mem_out_real_1_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_i_1 (
        .clock(clock), .data_in(mem_out_imag_1), .data_out(mem_out_imag_1_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_r_2 (
        .clock(clock), .data_in(mem_out_real_2), .data_out(mem_out_real_2_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_i_2 (
        .clock(clock), .data_in(mem_out_imag_2), .data_out(mem_out_imag_2_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_r_3 (
        .clock(clock), .data_in(mem_out_real_3), .data_out(mem_out_real_3_output)
    );

    delay_reg #(
        .WIDTH(WIDTH), .DELAY(3)
    ) delay_pass_thought_mem_out_i_3 (
        .clock(clock), .data_in(mem_out_imag_3), .data_out(mem_out_imag_3_output)
    );

    delay_reg_reset #(
        .WIDTH(1), .DELAY(3+3)
    ) delay_butt_op_count_output(
        .clock(clock), .reset(reset), .data_in(butterfly_op_counter_mem[stage_num_bits]), .data_out(butterfly_op_counter_output)
    );


    always @(posedge clock) begin
        twiddle_index_0_r <= twiddle_index_0;
        twiddle_index_1_r <= twiddle_index_1;
        w0re_reg <= w0re;
        w0i_reg <= w0i;
        w1re_reg <= w1re;
        w1i_reg <= w1i;
        input_real_0_r <= input_real_0;
        input_real_1_r <= input_real_1;
        input_real_2_r <= input_real_2;
        input_real_3_r <= input_real_3;
        input_imag_0_r <= input_imag_0;
        input_imag_1_r <= input_imag_1;
        input_imag_2_r <= input_imag_2;
        input_imag_3_r <= input_imag_3;
        input_real_0_rr <= input_real_0_r;
        input_imag_0_rr <= input_imag_0_r;
        input_real_1_rr <= input_real_1_r;
        input_imag_1_rr <= input_imag_1_r;
        input_real_2_rr <= input_real_2_r;
        input_imag_2_rr <= input_imag_2_r;
        input_real_3_rr <= input_real_3_r;
        input_imag_3_rr <= input_imag_3_r;
        input_real_0_mem <= mulr_0[PROD-2:PROD-WIDTH-1];
        input_imag_0_mem <= muli_0[PROD-2:PROD-WIDTH-1];
        input_real_3_mem <= mulr_3[PROD-2:PROD-WIDTH-1];
        input_imag_3_mem <= muli_3[PROD-2:PROD-WIDTH-1];

        if(butterfly_op_counter_output) begin
            output_real_0 <= mem_out_real_0_output;
            output_imag_0 <= mem_out_imag_0_output;
            output_real_1 <= mem_out_real_1_output;
            output_imag_1 <= mem_out_imag_1_output;
            output_real_2 <= mem_out_real_2_output;
            output_imag_2 <= mem_out_imag_2_output;
            output_real_3 <= mem_out_real_3_output;
            output_imag_3 <= mem_out_imag_3_output;
        end else begin
            output_real_0 <= y0_re;
            output_imag_0 <= y0_im;
            output_real_1 <= y1_re;
            output_imag_1 <= y1_im;
            output_real_2 <= y2_re;
            output_imag_2 <= y2_im;
            output_real_3 <= y3_re;
            output_imag_3 <= y3_im;
        end

        output_en <= butterfly_out_ready;
    end
endmodule