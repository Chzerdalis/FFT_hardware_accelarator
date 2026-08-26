`timescale 1ns/1ps

module SdfUnit2_fast #(
    parameter   WIDTH = 32, 
    parameter   STAGE_NUM = 1,   
    parameter   Num_of_samples = 16 
)(
    input                   clock,  
    input                   reset,  
    input                   input_en,  
    input       [WIDTH-1:0] input_real_0, input_real_1,  
    input       [WIDTH-1:0] input_imag_0, input_imag_1,  
    output  reg             output_en,  
    output  reg [WIDTH-1:0] output_real_0, output_real_1, 
    output  reg [WIDTH-1:0] output_imag_0, output_imag_1  
);

    localparam stage_num_bits = STAGE_NUM - 2;  
    localparam Num_of_samples_flash = $clog2(Num_of_samples/2);
    localparam Stride = 1 << STAGE_NUM;
    localparam shift_value = $clog2(Num_of_samples/Stride);
    localparam Depth_A = 1 << (STAGE_NUM - 1);
    localparam Depth_B = Depth_A/2;

    reg [stage_num_bits:0] stride_segment_counter;
    reg [stage_num_bits:0] butterfly_op_counter;
    reg [Num_of_samples_flash-1:0] flush_counter;
    reg butterfly_op_counter_en;

    wire [$clog2(Num_of_samples)-1:0] twiddle_index;

    wire [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;

    wire [WIDTH-1:0] delay_in_real_0, delay_in_imag_0, delay_out_real_0, delay_out_imag_0;
    wire [WIDTH-1:0] delay_in_real_1, delay_in_imag_1, delay_out_real_1, delay_out_imag_1;

    wire start_butterfly, butterfly_out_ready;

    wire [WIDTH/2 - 1:0] wr, wi;

    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_real [0: Num_of_samples/2 -1];
    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_imag [0: Num_of_samples/2 -1];

    
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
    

    if (STAGE_NUM > 1) begin : gen_input_logic

    localparam [stage_num_bits:0] HALF_STRIDE_VAL = (1 << stage_num_bits) - 1;

        always @(posedge clock) begin
            if (reset) begin
                butterfly_op_counter <= {stage_num_bits+1{1'b0}};
                stride_segment_counter <= {stage_num_bits+1{1'b0}};
                flush_counter <= {Num_of_samples_flash{1'b0}};
                butterfly_op_counter_en <= 0;
            end else begin
                if(input_en) begin
                    //if(stride_segment_counter == {1'b0, {{stage_num_bits}{1'b1}}} && butterfly_op_counter_en == 0) begin
                    if(stride_segment_counter == HALF_STRIDE_VAL && butterfly_op_counter_en == 0) begin
                        butterfly_op_counter_en <= 1'b1;
                        butterfly_op_counter <= butterfly_op_counter;
                        flush_counter <= Num_of_samples/2 - 1;
                    end else if (butterfly_op_counter_en) begin
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_counter <= flush_counter - 1'b1;
                    end else begin
                        butterfly_op_counter <= butterfly_op_counter;
                        butterfly_op_counter_en <= 1'b0;
                        flush_counter <= flush_counter;
                    end

                    stride_segment_counter <= stride_segment_counter + 1'b1;
                end else begin
                    if(flush_counter == 0) begin
                        butterfly_op_counter <= {stage_num_bits+1{1'b0}};
                        stride_segment_counter <= {stage_num_bits+1{1'b0}};
                        flush_counter <= {Num_of_samples_flash{1'b0}};
                        butterfly_op_counter_en <= 0;
                    end else begin
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_counter <= flush_counter - 1'b1;
                    end 
                end
            end
        end
    end

    assign twiddle_index = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter << shift_value);

    assign wr = w_real[twiddle_index];
    assign wi = w_imag[twiddle_index];

    //When we are in the first half of stride butterfly calculations the inputs comes from buffer 0, then from buffer 1
    assign x0_re = (STAGE_NUM == 1) ? input_real_0 : ((butterfly_op_counter[stage_num_bits]) ? (delay_out_real_1) : (delay_out_real_0));
    assign x0_im = (STAGE_NUM == 1) ? input_imag_0 : ((butterfly_op_counter[stage_num_bits]) ? (delay_out_imag_1) : (delay_out_imag_0));

    //When we are in the first half of stride butterfly calculations the inputs comes from the input port, then from buffer 0
    assign x1_re = (STAGE_NUM == 1) ? input_real_1 : ((butterfly_op_counter[stage_num_bits]) ? (delay_out_real_0) : (input_real_0));
    assign x1_im = (STAGE_NUM == 1) ? input_imag_1 : ((butterfly_op_counter[stage_num_bits]) ? (delay_out_imag_0) : (input_imag_0));

    assign start_butterfly = (STAGE_NUM == 1) ? input_en : butterfly_op_counter_en;

    butterfly_radix_2_pipelined_casc#(
        .WIDTH(WIDTH)
    ) b0 (
        .clock(clock),
        .reset(reset),
        .start(start_butterfly),
        .ar(x0_re), .ai(x0_im),
        .br(x1_re), .bi(x1_im),
        .wr(wr), .wi(wi),
        .out1r(y0_re), .out1i(y0_im),
        .out2r(y1_re), .out2i(y1_im),
        .done(butterfly_out_ready)
    );

    if (STAGE_NUM > 1) begin : gen_delay_buffers
        DelayBuffer #(
            .DEPTH(Depth_B),
            .WIDTH(WIDTH)
        ) db0 (
            .clock(clock),
            .input_real(delay_in_real_0),
            .input_imag(delay_in_imag_0),
            .out_real(delay_out_real_0),
            .out_imag(delay_out_imag_0)
        );

        assign delay_in_real_0 = (stride_segment_counter[stage_num_bits] == 0) ? (input_real_0) : (input_real_1);
        assign delay_in_imag_0 = (stride_segment_counter[stage_num_bits] == 0) ? (input_imag_0) : (input_imag_1);


        DelayBuffer #(
            .DEPTH(Depth_A),
            .WIDTH(WIDTH)
        ) db1 (
            .clock(clock),
            .input_real(delay_in_real_1),
            .input_imag(delay_in_imag_1),
            .out_real(delay_out_real_1),
            .out_imag(delay_out_imag_1)
        );

        assign delay_in_real_1 = input_real_1;
        assign delay_in_imag_1 = input_imag_1;
    end

    always @(posedge clock) begin
        if(reset) begin
            output_real_0 <= {WIDTH{1'b0}};
            output_imag_0 <= {WIDTH{1'b0}};
            output_real_1 <= {WIDTH{1'b0}};
            output_imag_1 <= {WIDTH{1'b0}};
            output_en <= 1'b0;
        end else begin
            if (butterfly_out_ready) begin
                output_en <= 1'b1;
            end else begin
                output_en <= 1'b0;
            end
            output_real_0 <= y0_re;
            output_imag_0 <= y0_im;
            output_real_1 <= y1_re;
            output_imag_1 <= y1_im;
        end
    end
endmodule
