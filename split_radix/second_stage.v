`timescale 1ns / 1ps

module Split_radix_SecondStage #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Num_of_samples = 1024 //How many inputs
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
    //localparam Stride = 1 << (2*STAGE_NUM); 
    localparam stage_num_bits = $clog2(Num_of_samples/4) - 1;
    localparam sn = stage_num_bits + 3;
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;

    //Wires needed for stages > 1
    //Counters to calculate the twiddle factors and manage the delay buffers
    reg [stage_num_bits:0] butterfly_op_counter;
    reg [stage_num_bits:0] stride_segment_counter;
    reg [stage_num_bits+1:0] mem_counter;
    reg [stage_num_bits+1:0] mem_counter_read;

    //registers for counters
    reg [stage_num_bits:0] butterfly_op_counter_reg, butterfly_op_counter_reg_reg, butterfly_op_counter_reg_reg_reg;
    reg outmode, outmode_reg, outmode_reg_reg, outmode_reg_reg_reg, outmode_reg_reg_reg_reg, outmode_reg_reg_reg_reg_reg;
    reg [stage_num_bits:0] stride_segment_counter_reg, stride_segment_counter_reg_reg, stride_segment_counter_reg_reg_reg;
    reg [stage_num_bits+1:0] mem_counter_reg, mem_counter_reg_reg, mem_counter_reg_reg_reg;
    reg [stage_num_bits+1:0] mem_counter_read_reg, mem_counter_read_reg_reg, mem_counter_read_reg_reg_reg;
    reg butterfly_op_counter_en, butterfly_op_counter_en_r, butterfly_op_counter_en_rr, butterfly_op_counter_en_rrr,
    butterfly_op_counter_en_rrrr, butterfly_op_counter_en_rrrrr, butterfly_op_counter_en_rrrrrr;

    //Counter to flush the pipeline at the end of the data
    reg [Num_of_samples_bits-1:0] flush_count;
    reg start_out;

    //Memoryoutput wires
    wire [WIDTH-1:0] delay_out_real_0, delay_out_imag_0;
    wire [WIDTH-1:0] delay_out_real_1, delay_out_imag_1;
    wire [WIDTH-1:0] delay_out_real_2, delay_out_imag_2;
    wire [WIDTH-1:0] delay_out_real_3, delay_out_imag_3;

    reg [WIDTH-1:0] delay_out_real_0_r, delay_out_imag_0_r;
    reg [WIDTH-1:0] delay_out_real_1_r, delay_out_imag_1_r;
    reg [WIDTH-1:0] delay_out_real_2_r, delay_out_imag_2_r;
    reg [WIDTH-1:0] delay_out_real_3_r, delay_out_imag_3_r;

    reg [WIDTH-1:0] delay_out_real_0_rr, delay_out_imag_0_rr;
    reg [WIDTH-1:0] delay_out_real_1_rr, delay_out_imag_1_rr;
    reg [WIDTH-1:0] delay_out_real_2_rr, delay_out_imag_2_rr;
    reg [WIDTH-1:0] delay_out_real_3_rr, delay_out_imag_3_rr;

    reg [WIDTH-1:0] delay_out_real_0_rrr, delay_out_imag_0_rrr;
    reg [WIDTH-1:0] delay_out_real_1_rrr, delay_out_imag_1_rrr;
    reg [WIDTH-1:0] delay_out_real_2_rrr, delay_out_imag_2_rrr;
    reg [WIDTH-1:0] delay_out_real_3_rrr, delay_out_imag_3_rrr;
    //end wires for stages > 1

    //Registers for multiplication and stalling before memory
    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    reg signed [WIDTH-1:0] input_real_0_rr, input_real_1_rr, input_real_2_rr, input_real_3_rr;
    reg signed [WIDTH-1:0] input_imag_0_rr, input_imag_1_rr, input_imag_2_rr, input_imag_3_rr;
    reg [WIDTH-1:0] input_real_0_rrr_mult, input_real_1_rrr_mult, input_real_2_rrr_mult, input_real_3_rrr_mult;
    reg [WIDTH-1:0] input_imag_0_rrr_mult, input_imag_1_rrr_mult, input_imag_2_rrr_mult, input_imag_3_rrr_mult;
    reg [WIDTH-1:0] input_real_1_rrr_mult_r, input_real_2_rrr_mult_r;
    reg [WIDTH-1:0] input_imag_1_rrr_mult_r, input_imag_2_rrr_mult_r;
    reg [WIDTH-1:0] input_real_1_rrr_mult_rr, input_real_2_rrr_mult_rr;
    reg [WIDTH-1:0] input_imag_1_rrr_mult_rr, input_imag_2_rrr_mult_rr;
    reg [WIDTH-1:0] input_real_1_rrr_mult_rrr, input_real_2_rrr_mult_rrr;
    reg [WIDTH-1:0] input_imag_1_rrr_mult_rrr, input_imag_2_rrr_mult_rrr;

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
                stride_segment_counter <= {(sn-2){1'b0}};
                butterfly_op_counter <= {(sn-2){1'b0}};
                mem_counter_read <= {(sn-1){1'b0}};
                mem_counter <= {(sn-1){1'b0}};
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    if(stride_segment_counter == {1'b0, {(sn-4){1'b1}}, 1'b0} && butterfly_op_counter_en == 0) begin
                        butterfly_op_counter_en <= 1'b1;
                        butterfly_op_counter <= butterfly_op_counter;
                        mem_counter_read <= mem_counter_read;
                        flush_count <= Num_of_samples/4 - 1;
                    end else if (butterfly_op_counter_en) begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        mem_counter_read <= mem_counter_read + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter;
                        mem_counter_read <= mem_counter_read;
                        butterfly_op_counter_en <= 1'b0;
                        flush_count <= flush_count;
                    end

                    stride_segment_counter <= stride_segment_counter + 1'b1;
                    mem_counter <= mem_counter + 1'b1;
                end else begin
                    if (flush_count == 0) begin
                        butterfly_op_counter <= {(sn-2){1'b0}};
                        mem_counter_read <= {(sn-1){1'b0}};
                        stride_segment_counter <= {(sn-2){1'b0}};
                        mem_counter <= {(sn-1){1'b0}};
                        butterfly_op_counter_en <= 1'b0;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        mem_counter_read <= mem_counter_read + 1'b1;
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        mem_counter <= mem_counter + 1'b1;
                        butterfly_op_counter_en <= butterfly_op_counter_en;
                        flush_count <= flush_count - 1'b1;
                    end
                end
            end
        end
    end else begin
        //This logic is for a 8 point first stage, the memory is also custom for this
        always @(posedge clock) begin
            if (reset) begin
                stride_segment_counter <= {(sn-2){1'b0}};
                butterfly_op_counter <= {(sn-2){1'b0}};
                mem_counter_read <= {(sn-1){1'b0}};
                mem_counter <= {(sn-1){1'b0}};
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    if(stride_segment_counter == 1'b0 && butterfly_op_counter_en == 0) begin
                        butterfly_op_counter_en <= 1'b1;
                        butterfly_op_counter <= butterfly_op_counter;
                        mem_counter_read <= mem_counter_read;
                        flush_count <= Num_of_samples/4 - 1;
                    end else if (butterfly_op_counter_en) begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        mem_counter_read <= mem_counter_read + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter;
                        mem_counter_read <= mem_counter_read;
                        butterfly_op_counter_en <= 1'b0;
                        flush_count <= flush_count;
                    end

                    stride_segment_counter <= stride_segment_counter + 1'b1;
                    mem_counter <= mem_counter + 1'b1;
                end else begin
                    if (flush_count == 0) begin
                        butterfly_op_counter <= {(sn-2){1'b0}};
                        mem_counter_read <= {(sn-1){1'b0}};
                        stride_segment_counter <= {(sn-2){1'b0}};
                        mem_counter <= {(sn-1){1'b0}};
                        butterfly_op_counter_en <= 1'b0;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        mem_counter_read <= mem_counter_read + 1'b1;
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        mem_counter <= mem_counter + 1'b1;
                        butterfly_op_counter_en <= butterfly_op_counter_en;
                        flush_count <= flush_count - 1'b1;
                    end
                end
            end
        end
    end

    //Calculating twiddle index
    assign twiddle_index_0 = (stride_segment_counter);
    assign twiddle_index_1 = ((stride_segment_counter<<1) + stride_segment_counter);

    //Next pipeline feching the twiddle factors from ROM
    assign w0re = w_real[twiddle_index_0_r];
    assign w0i = w_imag[twiddle_index_0_r];
    assign w1re = w_real[twiddle_index_1_r];
    assign w1i = w_imag[twiddle_index_1_r];

    //
    //Clasical way to do the complex multiplication would require 4 multipliers and 2 adders per butterfly input
    //

    //Next pipeline stage for multiplication
    // --- 4 Multiplications for Input 0 ---
    wire signed [PROD-1:0] rr_0 = input_real_0_rr * w0re_reg; // Real * Real
    wire signed [PROD-1:0] ii_0 = input_imag_0_rr * w0i_reg;  // Imag * Imag
    wire signed [PROD-1:0] ri_0 = input_real_0_rr * w0i_reg;  // Real * Imag
    wire signed [PROD-1:0] ir_0 = input_imag_0_rr * w0re_reg; // Imag * Real

    wire signed [PROD-1:0] rr_3 = input_real_3_rr * w1re_reg; // Real * Real
    wire signed [PROD-1:0] ii_3 = input_imag_3_rr * w1i_reg;  // Imag * Imag
    wire signed [PROD-1:0] ri_3 = input_real_3_rr * w1i_reg;  // Real * Imag
    wire signed [PROD-1:0] ir_3 = input_imag_3_rr * w1re_reg; // Imag * Real

    // --- Final Addition/Subtraction ---
    // Note: You need 1 extra bit (PROD) to prevent overflow during addition!
    wire signed [PROD:0] mulr_0 = rr_0 - ii_0; 
    wire signed [PROD:0] muli_0 = ri_0 + ir_0;

    wire signed [PROD:0] mulr_3 = rr_3 - ii_3;
    wire signed [PROD:0] muli_3 = ri_3 + ir_3;

    //
    //This way to do the complex multiplication would require 3 multipliers and 5 adders per butterfly input and one more pipeline
    //

    // //Trick to use less DSPs but more additions:
    // // Pre-calculate sums/differences of the inputs (cheap in logic)
    // wire signed [WIDTH:0] sum_twiddle_0 = w0re_reg + w0i_reg;
    // wire signed [WIDTH:0] sum_input_0   = input_real_0_rr + input_imag_0_rr;
    // wire signed [WIDTH:0] diff_input_0  = input_real_0_rr - input_imag_0_rr;

    // // Use only 3 Multipliers (DSP slices)
    // wire signed [PROD:0] k1_0 = w0re_reg * sum_input_0;
    // wire signed [PROD:0] k2_0 = input_real_0_rr * (w0i_reg - w0re_reg); // Twiddle diff can be pre-calculated!
    // wire signed [PROD:0] k3_0 = input_imag_0_rr * sum_twiddle_0;

    // // Final Outputs
    // wire signed [PROD+1:0] mulr_0 = k1_0 - k3_0;
    // wire signed [PROD+1:0] muli_0 = k1_0 + k2_0;

    // wire signed [WIDTH:0] sum_twiddle_1 = w1re_reg + w1i_reg;
    // wire signed [WIDTH:0] sum_input_1   = input_real_3_rr + input_imag_3_rr;
    // wire signed [WIDTH:0] diff_input_1  = input_real_3_rr - input_imag_3_rr;

    // // Use only 3 Multipliers (DSP slices)
    // wire signed [PROD:0] k1_1 = w1re_reg * sum_input_1;
    // wire signed [PROD:0] k2_1 = input_real_3_rr * (w1i_reg - w1re_reg); // Twiddle diff can be pre-calculated!
    // wire signed [PROD:0] k3_1 = input_imag_3_rr * sum_twiddle_1;

    // // Final Outputs
    // wire signed [PROD+1:0] mulr_3 = k1_1 - k3_1;
    // wire signed [PROD+1:0] muli_3 = k1_1 + k2_1;



    //Manage butterfly inputs based on stage number
    assign x0_re =  delay_out_real_1;
    assign x0_im =  delay_out_imag_1;
    assign x1_re =  input_real_1_rrr_mult_rr;
    assign x1_im =  input_imag_1_rrr_mult_rr;
    assign x2_re =  delay_out_real_3;
    assign x2_im =  delay_out_imag_3;
    assign x3_re =  input_real_2_rrr_mult_rr;
    assign x3_im =  input_imag_2_rrr_mult_rr;

    assign start_butterfly = butterfly_op_counter_en_rrrrrr;

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

    memory_second_stage #(
        .WIDTH(WIDTH),
        .DEPTH(Depth),
        .stage_num_bits(stage_num_bits)
    ) mem (
        .clock(clock),
        .reset(reset),
        .stride_segment_counter(stride_segment_counter_reg_reg_reg),
        .butterfly_op_counter(butterfly_op_counter_reg_reg_reg),
        .mem_counter(mem_counter_reg_reg_reg),
        .mem_counter_read(mem_counter_read_reg_reg_reg),
        .input_real_0(input_real_0_rrr_mult), .input_imag_0(input_imag_0_rrr_mult),
        .input_real_1(input_real_1_rrr_mult), .input_imag_1(input_imag_1_rrr_mult),
        .input_real_2(input_real_2_rrr_mult), .input_imag_2(input_imag_2_rrr_mult),
        .input_real_3(input_real_3_rrr_mult), .input_imag_3(input_imag_3_rrr_mult),
        .output_real_0(delay_out_real_0), .output_imag_0(delay_out_imag_0),
        .output_real_1(delay_out_real_1), .output_imag_1(delay_out_imag_1),
        .output_real_2(delay_out_real_2), .output_imag_2(delay_out_imag_2),
        .output_real_3(delay_out_real_3), .output_imag_3(delay_out_imag_3)
    );

    always @(posedge clock) begin
        if (reset) begin
            output_en <= 1'b0;
            output_real_0 <= {WIDTH{1'b0}};
            output_imag_0 <= {WIDTH{1'b0}};
            output_real_1 <= {WIDTH{1'b0}};
            output_imag_1 <= {WIDTH{1'b0}};
            output_real_2 <= {WIDTH{1'b0}};
            output_imag_2 <= {WIDTH{1'b0}};
            output_real_3 <= {WIDTH{1'b0}};
            output_imag_3 <= {WIDTH{1'b0}};
        end else begin
            if(butterfly_out_ready) begin
                output_en <= 1'b1;
            end else begin
                output_en <= 1'b0;
            end
            if(outmode_reg_reg_reg_reg_reg) begin
                output_real_0 <= delay_out_real_0_rrr;
                output_imag_0 <= delay_out_imag_0_rrr;
                output_real_1 <= delay_out_real_1_rrr;
                output_imag_1 <= delay_out_imag_1_rrr;
                output_real_2 <= delay_out_real_2_rrr;
                output_imag_2 <= delay_out_imag_2_rrr;
                output_real_3 <= delay_out_real_3_rrr;
                output_imag_3 <= delay_out_imag_3_rrr;
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
        end
    end
    
    always @(posedge clock) begin
        if (reset) begin
            butterfly_op_counter_reg <= {(stage_num_bits+1){1'b0}};
            butterfly_op_counter_reg_reg <= {(stage_num_bits+1){1'b0}};
            butterfly_op_counter_reg_reg_reg <= {(stage_num_bits+1){1'b0}};
            stride_segment_counter_reg <= {(stage_num_bits+1){1'b0}};
            stride_segment_counter_reg_reg <= {(stage_num_bits+1){1'b0}};
            stride_segment_counter_reg_reg_reg <= {(stage_num_bits+1){1'b0}};
            mem_counter_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_reg_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_reg_reg_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_read_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_read_reg_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_read_reg_reg_reg <= {(stage_num_bits+2){1'b0}};
        end else begin
            butterfly_op_counter_reg <= butterfly_op_counter;
            butterfly_op_counter_reg_reg <= butterfly_op_counter_reg;
            butterfly_op_counter_reg_reg_reg <= butterfly_op_counter_reg_reg;
            stride_segment_counter_reg <= stride_segment_counter;
            stride_segment_counter_reg_reg <= stride_segment_counter_reg;
            stride_segment_counter_reg_reg_reg <= stride_segment_counter_reg_reg;
            mem_counter_reg <= mem_counter;
            mem_counter_reg_reg <= mem_counter_reg;
            mem_counter_reg_reg_reg <= mem_counter_reg_reg;
            mem_counter_read_reg <= mem_counter_read;
            mem_counter_read_reg_reg <= mem_counter_read_reg;
            mem_counter_read_reg_reg_reg <= mem_counter_read_reg_reg;
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            input_real_0_r <= {WIDTH{1'b0}};
            input_real_1_r <= {WIDTH{1'b0}};
            input_real_2_r <= {WIDTH{1'b0}};
            input_real_3_r <= {WIDTH{1'b0}};
            input_imag_0_r <= {WIDTH{1'b0}};
            input_imag_1_r <= {WIDTH{1'b0}};
            input_imag_2_r <= {WIDTH{1'b0}};
            input_imag_3_r <= {WIDTH{1'b0}};
            input_real_0_rr <= {WIDTH{1'b0}};
            input_imag_0_rr <= {WIDTH{1'b0}};
            input_real_1_rr <= {WIDTH{1'b0}};
            input_imag_1_rr <= {WIDTH{1'b0}};
            input_real_2_rr <= {WIDTH{1'b0}};
            input_imag_2_rr <= {WIDTH{1'b0}};
            input_real_3_rr <= {WIDTH{1'b0}};
            input_imag_3_rr <= {WIDTH{1'b0}};
            input_real_0_rrr_mult <= {WIDTH{1'b0}};
            input_imag_0_rrr_mult <= {WIDTH{1'b0}};
            input_real_1_rrr_mult <= {WIDTH{1'b0}};
            input_imag_1_rrr_mult <= {WIDTH{1'b0}};
            input_real_2_rrr_mult <= {WIDTH{1'b0}};
            input_imag_2_rrr_mult <= {WIDTH{1'b0}};
            input_real_3_rrr_mult <= {WIDTH{1'b0}};
            input_imag_3_rrr_mult <= {WIDTH{1'b0}};
            input_imag_1_rrr_mult_r <= {WIDTH{1'b0}};
            input_real_1_rrr_mult_r <= {WIDTH{1'b0}};
            input_imag_2_rrr_mult_r <= {WIDTH{1'b0}};
            input_real_2_rrr_mult_r <= {WIDTH{1'b0}};
            input_imag_1_rrr_mult_rr <= {WIDTH{1'b0}};
            input_real_1_rrr_mult_rr <= {WIDTH{1'b0}};
            input_imag_2_rrr_mult_rr <= {WIDTH{1'b0}};
            input_real_2_rrr_mult_rr <= {WIDTH{1'b0}};
            input_imag_1_rrr_mult_rrr <= {WIDTH{1'b0}};
            input_real_1_rrr_mult_rrr <= {WIDTH{1'b0}};
            input_imag_2_rrr_mult_rrr <= {WIDTH{1'b0}};
            input_real_2_rrr_mult_rrr <= {WIDTH{1'b0}};

            twiddle_index_0_r <= {($clog2(Num_of_samples)){1'b0}};
            twiddle_index_1_r <= {($clog2(Num_of_samples)){1'b0}};

            w0re_reg <= {WIDTH/2{1'b0}};
            w0i_reg <= {WIDTH/2{1'b0}};
            w1re_reg <= {WIDTH/2{1'b0}};
            w1i_reg <= {WIDTH/2{1'b0}};

            outmode <= 1'b0;
            outmode_reg <= 1'b0;
            outmode_reg_reg <= 1'b0;
            outmode_reg_reg_reg <= 1'b0;
            outmode_reg_reg_reg_reg <= 1'b0;
            outmode_reg_reg_reg_reg_reg <= 1'b0;

            butterfly_op_counter_en_r <= 1'b0;
            butterfly_op_counter_en_rr <= 1'b0;
            butterfly_op_counter_en_rrr <= 1'b0;
            butterfly_op_counter_en_rrrr <= 1'b0;
            butterfly_op_counter_en_rrrrr <= 1'b0;
            butterfly_op_counter_en_rrrrrr <= 1'b0;

            delay_out_real_0_r <= {WIDTH{1'b0}};
            delay_out_imag_0_r <= {WIDTH{1'b0}};
            delay_out_real_1_r <= {WIDTH{1'b0}};
            delay_out_imag_1_r <= {WIDTH{1'b0}};
            delay_out_real_2_r <= {WIDTH{1'b0}};
            delay_out_imag_2_r <= {WIDTH{1'b0}};    
            delay_out_real_3_r <= {WIDTH{1'b0}};
            delay_out_imag_3_r <= {WIDTH{1'b0}};
            delay_out_real_0_rr <= {WIDTH{1'b0}};
            delay_out_imag_0_rr <= {WIDTH{1'b0}};
            delay_out_real_1_rr <= {WIDTH{1'b0}};
            delay_out_imag_1_rr <= {WIDTH{1'b0}};
            delay_out_real_2_rr <= {WIDTH{1'b0}};
            delay_out_imag_2_rr <= {WIDTH{1'b0}};
            delay_out_real_3_rr <= {WIDTH{1'b0}};
            delay_out_imag_3_rr <= {WIDTH{1'b0}};
            delay_out_real_0_rrr <= {WIDTH{1'b0}};
            delay_out_imag_0_rrr <= {WIDTH{1'b0}};
            delay_out_real_1_rrr <= {WIDTH{1'b0}};
            delay_out_imag_1_rrr <= {WIDTH{1'b0}};
            delay_out_real_2_rrr <= {WIDTH{1'b0}};
            delay_out_imag_2_rrr <= {WIDTH{1'b0}};
            delay_out_real_3_rrr <= {WIDTH{1'b0}};
            delay_out_imag_3_rrr <= {WIDTH{1'b0}};
        end else begin
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
            input_real_0_rrr_mult <= mulr_0[PROD-2:PROD-WIDTH-1];
            input_imag_0_rrr_mult <= muli_0[PROD-2:PROD-WIDTH-1];
            input_real_1_rrr_mult <= input_real_1_rr;
            input_imag_1_rrr_mult <= input_imag_1_rr;
            input_real_2_rrr_mult <= input_real_2_rr;
            input_imag_2_rrr_mult <= input_imag_2_rr;
            input_real_3_rrr_mult <= mulr_3[PROD-2:PROD-WIDTH-1];
            input_imag_3_rrr_mult <= muli_3[PROD-2:PROD-WIDTH-1];
            input_real_1_rrr_mult_r <= input_real_1_rrr_mult;
            input_imag_1_rrr_mult_r <= input_imag_1_rrr_mult;
            input_real_2_rrr_mult_r <= input_real_2_rrr_mult;
            input_imag_2_rrr_mult_r <= input_imag_2_rrr_mult;
            input_real_1_rrr_mult_rr <= input_real_1_rrr_mult_r;
            input_imag_1_rrr_mult_rr <= input_imag_1_rrr_mult_r;
            input_real_2_rrr_mult_rr <= input_real_2_rrr_mult_r;
            input_imag_2_rrr_mult_rr <= input_imag_2_rrr_mult_r;
            input_real_1_rrr_mult_rrr <= input_real_1_rrr_mult_rr;
            input_imag_1_rrr_mult_rrr <= input_imag_1_rrr_mult_rr;
            input_real_2_rrr_mult_rrr <= input_real_2_rrr_mult_rr;
            input_imag_2_rrr_mult_rrr <= input_imag_2_rrr_mult_rr;

            twiddle_index_0_r <= twiddle_index_0;
            twiddle_index_1_r <= twiddle_index_1;

            w0re_reg <= w0re;
            w0i_reg <= w0i;
            w1re_reg <= w1re;
            w1i_reg <= w1i;

            outmode <= butterfly_op_counter_reg_reg_reg[stage_num_bits];
            outmode_reg <= outmode;
            outmode_reg_reg <= outmode_reg;
            outmode_reg_reg_reg <= outmode_reg_reg;
            outmode_reg_reg_reg_reg <= outmode_reg_reg_reg;
            outmode_reg_reg_reg_reg_reg <= outmode_reg_reg_reg_reg;

            butterfly_op_counter_en_r <= butterfly_op_counter_en;
            butterfly_op_counter_en_rr <= butterfly_op_counter_en_r;
            butterfly_op_counter_en_rrr <= butterfly_op_counter_en_rr;
            butterfly_op_counter_en_rrrr <= butterfly_op_counter_en_rrr;
            butterfly_op_counter_en_rrrrr <= butterfly_op_counter_en_rrrr;
            butterfly_op_counter_en_rrrrrr <= butterfly_op_counter_en_rrrrr;

            delay_out_real_0_r <= delay_out_real_0;
            delay_out_imag_0_r <= delay_out_imag_0;
            delay_out_real_1_r <= delay_out_real_1;
            delay_out_imag_1_r <= delay_out_imag_1;
            delay_out_real_2_r <= delay_out_real_2;
            delay_out_imag_2_r <= delay_out_imag_2;    
            delay_out_real_3_r <= delay_out_real_3;
            delay_out_imag_3_r <= delay_out_imag_3;
            delay_out_real_0_rr <= delay_out_real_0_r;
            delay_out_imag_0_rr <= delay_out_imag_0_r;
            delay_out_real_1_rr <= delay_out_real_1_r;
            delay_out_imag_1_rr <= delay_out_imag_1_r;
            delay_out_real_2_rr <= delay_out_real_2_r;
            delay_out_imag_2_rr <= delay_out_imag_2_r;
            delay_out_real_3_rr <= delay_out_real_3_r;
            delay_out_imag_3_rr <= delay_out_imag_3_r;
            delay_out_real_0_rrr <= delay_out_real_0_rr;
            delay_out_imag_0_rrr <= delay_out_imag_0_rr;
            delay_out_real_1_rrr <= delay_out_real_1_rr;
            delay_out_imag_1_rrr <= delay_out_imag_1_rr;
            delay_out_real_2_rrr <= delay_out_real_2_rr;
            delay_out_imag_2_rrr <= delay_out_imag_2_rr;    
            delay_out_real_3_rrr <= delay_out_real_3_rr;
            delay_out_imag_3_rrr <= delay_out_imag_3_rr;
        end
    end

endmodule