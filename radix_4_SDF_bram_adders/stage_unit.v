`timescale 1ns / 1ps

module SdfUnit4_fast #(
    parameter WIDTH = 32, // Data Bit Lenght
    parameter STAGE_NUM = 1, //Butterfly Stage
    parameter Num_of_samples = 16 //How many inputs
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

    localparam sn = 2*STAGE_NUM;
    localparam Depth = 1 << (2*(STAGE_NUM - 1));
    localparam Stride = 1 << (2*STAGE_NUM); 
    localparam stage_num_bits = (STAGE_NUM > 1) ? (sn-3) : 0;
    localparam shift_value = $clog2(Num_of_samples/Stride);
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);

    //Wires needed for stages > 1
    //if (STAGE_NUM > 1) begin : gen_counter_and_flush
        //Counters to calculate the twiddle factors and manage the delay buffers
    reg [stage_num_bits:0] butterfly_op_counter;
    reg [stage_num_bits:0] stride_segment_counter;
    reg [stage_num_bits+1:0] mem_counter, mem_counter_reg;
    reg [stage_num_bits+1:0] mem_counter_read, mem_counter_read_reg;
    reg [stage_num_bits:0] butterfly_op_counter_reg, butterfly_op_counter_reg_reg, butterfly_op_counter_reg_reg_reg, butterfly_op_counter_reg_reg_reg_reg;
    reg [stage_num_bits:0] stride_segment_counter_reg;
    reg butterfly_op_counter_en;
    reg stride_segment_counter_en;

    //Counter to flush the pipeline at the end of the data
    reg [Num_of_samples_bits-1:0] flush_count;
    reg start_out;

    //Delay buffer enable signals
    wire db0_write_en, db0_read_first_en, db0_read_last_en, db0_rotate;
    wire db1_write_en, db1_read_first_en, db1_read_last_en, db1_rotate;
    wire db2_write_en, db2_read_en;
    wire db3_write_en, db3_read_en;

    //Delay buffer input/output wires
    wire [WIDTH-1:0] db0_in_re_0, db0_in_imag_0;
    wire [WIDTH-1:0] db0_in_re_1, db0_in_imag_1;
    wire [WIDTH-1:0] db0_in_re_2, db0_in_imag_2;
    wire [WIDTH-1:0] db0_in_re_3, db0_in_imag_3;

    wire [WIDTH-1:0] db1_in_re_0, db1_in_imag_0;
    wire [WIDTH-1:0] db1_in_re_1, db1_in_imag_1;
    wire [WIDTH-1:0] db1_in_re_2, db1_in_imag_2;
    wire [WIDTH-1:0] db1_in_re_3, db1_in_imag_3;

    wire [WIDTH-1:0] db2_in_re_0, db2_in_imag_0;
    wire [WIDTH-1:0] db2_in_re_1, db2_in_imag_1;
    wire [WIDTH-1:0] db2_in_re_2, db2_in_imag_2;
    wire [WIDTH-1:0] db2_in_re_3, db2_in_imag_3;

    wire [WIDTH-1:0] db3_in_re_1, db3_in_imag_1;
    wire [WIDTH-1:0] db3_in_re_2, db3_in_imag_2;
    wire [WIDTH-1:0] db3_in_re_3, db3_in_imag_3;

    wire [WIDTH-1:0] delay_out_real_0, delay_out_imag_0;
    wire [WIDTH-1:0] delay_out_real_1, delay_out_imag_1;
    wire [WIDTH-1:0] delay_out_real_2, delay_out_imag_2;
    wire [WIDTH-1:0] delay_out_real_3, delay_out_imag_3;
    //end

    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    reg [WIDTH-1:0] input_real_0_rr, input_imag_0_rr, input_real_0_rrr, input_imag_0_rrr, input_real_0_rrrr, input_imag_0_rrrr;
    reg input_en_r, butterfly_op_counter_en_r, start_butterfly_r, butterfly_op_counter_en_rr, butterfly_op_counter_en_rrr;

    wire butterfly_out_ready, start_butterfly;

    //(* use_dsp = "yes" *) wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1, twiddle_index_2;
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1, twiddle_index_2;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_r, twiddle_index_1_r, twiddle_index_2_r;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_rr, twiddle_index_1_rr, twiddle_index_2_rr;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_rrr, twiddle_index_1_rrr, twiddle_index_2_rrr;


    wire [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;
    wire [WIDTH-1:0] x2_re, x2_im, y2_re, y2_im;
    wire [WIDTH-1:0] x3_re, x3_im, y3_re, y3_im;

    wire [WIDTH/2 - 1:0] w0re, w0i, w1re, w1i, w2re, w2i;

    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples-1];
    (* ram_style = "distributed" *) reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples-1];

    // reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples-1];
    // reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples-1];

    //Include the correct twiddle factors depending on size of FFT and data width
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

    //Manage counters
    if (STAGE_NUM > 1) begin : gen_input_logic
        always @(posedge clock) begin
            if (reset) begin
                stride_segment_counter <= {(sn-2){1'b0}};
                butterfly_op_counter <= {(sn-2){1'b0}};
                mem_counter_read <= {(sn-1){1'b0}};
                mem_counter <= {(sn-1){1'b0}};
                stride_segment_counter_en <= 1'b0;
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    if(stride_segment_counter == {2'b10, {(sn-4){1'b1}}} && butterfly_op_counter_en == 0) begin
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
                        butterfly_op_counter <= 1'b0;
                        mem_counter_read <= 1'b0;
                        stride_segment_counter <= 1'b0;
                        mem_counter <= 1'b0;
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

    //Manage twiddle factors based on stage number
    // assign twiddle_index_0 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter * (Num_of_samples/Stride));
    // assign twiddle_index_1 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter * (Num_of_samples/Stride) * 2);
    // assign twiddle_index_2 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter * (Num_of_samples/Stride) * 3);

    assign twiddle_index_0 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter_reg<< shift_value);
    assign twiddle_index_1 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter_reg<< (shift_value + 1));
    assign twiddle_index_2 = (STAGE_NUM == 1) ? 3'b0 : ((butterfly_op_counter_reg<< (shift_value + 1)) + (butterfly_op_counter_reg<< shift_value));
    //assign twiddle_index_2 = (STAGE_NUM == 1) ? 3'b0 : ((butterfly_op_counter_reg << 1)) << shift_value;


    //Assign twiddle factors
    assign w0re = w_real[twiddle_index_0_rrr];
    assign w0i = w_imag[twiddle_index_0_rrr];
    assign w1re = w_real[twiddle_index_1_rrr];
    assign w1i = w_imag[twiddle_index_1_rrr];
    assign w2re = w_real[twiddle_index_2_rrr];
    assign w2i = w_imag[twiddle_index_2_rrr];

    //Manage butterfly inputs based on stage number
    assign x0_re = (STAGE_NUM == 1) ? input_real_0_r : delay_out_real_0;
    assign x0_im = (STAGE_NUM == 1) ? input_imag_0_r : delay_out_imag_0;

    assign x1_re = (STAGE_NUM == 1) ? input_real_1_r : delay_out_real_1;
    assign x1_im = (STAGE_NUM == 1) ? input_imag_1_r : delay_out_imag_1;
    assign x2_re = (STAGE_NUM == 1) ? input_real_2_r : delay_out_real_2;
    assign x2_im = (STAGE_NUM == 1) ? input_imag_2_r : delay_out_imag_2;

    if(STAGE_NUM > 1) begin : gen_4th_butterfly_input
        assign x3_re = (butterfly_op_counter_reg_reg_reg_reg[sn-3:sn-4] == 2'b00) ? input_real_0_rrrr : delay_out_real_3;
        assign x3_im = (butterfly_op_counter_reg_reg_reg_reg[sn-3:sn-4] == 2'b00) ? input_imag_0_rrrr : delay_out_imag_3; 
    end else begin
        assign x3_re = input_real_3_r;
        assign x3_im = input_imag_3_r;
    end

    assign start_butterfly = (STAGE_NUM == 1) ? input_en : butterfly_op_counter_en_rrr;

    butterfly_radix4_pipeline #(
        .WIDTH(WIDTH)
    ) b4 (
        .clock(clock), .reset(reset),
        .ar(x0_re), .ai(x0_im),
        .br(x1_re), .bi(x1_im),
        .cr(x2_re), .ci(x2_im),
        .dr(x3_re), .di(x3_im),
        .w0r(w0re), .w0i(w0i),
        .w1r(w1re), .w1i(w1i),
        .w2r(w2re), .w2i(w2i),
        .out1r(y0_re), .out1i(y0_im),
        .out2r(y1_re), .out2i(y1_im),
        .out3r(y2_re), .out3i(y2_im),
        .out4r(y3_re), .out4i(y3_im),
        .start(start_butterfly_r),
        .done(butterfly_out_ready)
    );

    if(STAGE_NUM > 1) begin : gen_memory
        memory #(
            .WIDTH(WIDTH),
            .DEPTH(Depth),
            .stage_num_bits(stage_num_bits)
        ) mem (
            .clock(clock),
            .reset(reset),
            .stride_segment_counter(stride_segment_counter_reg),
            .butterfly_op_counter(butterfly_op_counter_reg),
            .mem_counter(mem_counter_reg),
            .mem_counter_read(mem_counter_read_reg),
            .input_real_0(input_real_0_r), .input_imag_0(input_imag_0_r),
            .input_real_1(input_real_1_r), .input_imag_1(input_imag_1_r),
            .input_real_2(input_real_2_r), .input_imag_2(input_imag_2_r),
            .input_real_3(input_real_3_r), .input_imag_3(input_imag_3_r),
            .output_real_0(delay_out_real_0), .output_imag_0(delay_out_imag_0),
            .output_real_1(delay_out_real_1), .output_imag_1(delay_out_imag_1),
            .output_real_2(delay_out_real_2), .output_imag_2(delay_out_imag_2),
            .output_real_3(delay_out_real_3), .output_imag_3(delay_out_imag_3)
        );
    end

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
    
    always @(posedge clock) begin
        if (reset) begin
            butterfly_op_counter_reg <= {(stage_num_bits+1){1'b0}};
            butterfly_op_counter_reg_reg <= {(stage_num_bits+1){1'b0}};
            butterfly_op_counter_reg_reg_reg <= {(stage_num_bits+1){1'b0}};
            butterfly_op_counter_reg_reg_reg_reg <= {(stage_num_bits+1){1'b0}};
            stride_segment_counter_reg <= {(stage_num_bits+1){1'b0}};
            twiddle_index_0_r <= {(stage_num_bits+1){1'b0}};
            twiddle_index_1_r <= {(stage_num_bits+1){1'b0}};
            twiddle_index_2_r <= {(stage_num_bits+1){1'b0}};
            twiddle_index_0_rr <= {(stage_num_bits+1){1'b0}};
            twiddle_index_0_rrr <= {(stage_num_bits+1){1'b0}};
            twiddle_index_1_rr <= {(stage_num_bits+1){1'b0}};
            twiddle_index_1_rrr <= {(stage_num_bits+1){1'b0}};
            twiddle_index_2_rr <= {(stage_num_bits+1){1'b0}};
            twiddle_index_2_rrr <= {(stage_num_bits+1){1'b0}};
        end else begin
            butterfly_op_counter_reg <= butterfly_op_counter;
            butterfly_op_counter_reg_reg <= butterfly_op_counter_reg;
            butterfly_op_counter_reg_reg_reg <= butterfly_op_counter_reg_reg;
            butterfly_op_counter_reg_reg_reg_reg <= butterfly_op_counter_reg_reg_reg;
            stride_segment_counter_reg <= stride_segment_counter;
            twiddle_index_0_r <= twiddle_index_0;
            twiddle_index_1_r <= twiddle_index_1;
            twiddle_index_2_r <= twiddle_index_2;
            twiddle_index_0_rr <= twiddle_index_0_r;
            twiddle_index_0_rrr <= twiddle_index_0_rr;
            twiddle_index_1_rr <= twiddle_index_1_r;
            twiddle_index_1_rrr <= twiddle_index_1_rr;
            twiddle_index_2_rr <= twiddle_index_2_r;
            twiddle_index_2_rrr <= twiddle_index_2_rr;
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
            input_real_0_rrr <= {WIDTH{1'b0}};
            input_imag_0_rrr <= {WIDTH{1'b0}};
            input_real_0_rrrr <= {WIDTH{1'b0}};
            input_imag_0_rrrr <= {WIDTH{1'b0}};
            input_en_r <= 1'b0;
            butterfly_op_counter_en_r <= {(stage_num_bits+1){1'b0}};
            start_butterfly_r <= {(stage_num_bits+1){1'b0}};
            mem_counter_reg <= {(stage_num_bits+2){1'b0}};
            mem_counter_read_reg <= {(stage_num_bits+2){1'b0}};
            butterfly_op_counter_en_rr <= 1'b0;
            butterfly_op_counter_en_rrr <= 1'b0;
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
            input_real_0_rrr <= input_real_0_rr;
            input_imag_0_rrr <= input_imag_0_rr;
            input_real_0_rrrr <= input_real_0_rrr;
            input_imag_0_rrrr <= input_imag_0_rrr;
            input_en_r <= input_en;
            butterfly_op_counter_en_r <= butterfly_op_counter_en;
            start_butterfly_r <= start_butterfly;
            butterfly_op_counter_en_rr <= butterfly_op_counter_en_r;
            butterfly_op_counter_en_rrr <= butterfly_op_counter_en_rr;
            mem_counter_reg <= mem_counter;
            mem_counter_read_reg <= mem_counter_read;
        end
    end

endmodule