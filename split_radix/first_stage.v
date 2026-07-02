`timescale 1ns / 1ps

module Split_radix_FirstStage #(
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

    localparam Depth = Num_of_samples/4;
    //localparam Stride = 1 << (2*STAGE_NUM); 
    localparam stage_num_bits = $clog2(Num_of_samples/4) - 1;
    localparam sn = stage_num_bits + 3;
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);

    //Wires needed for stages > 1
    //Counters to calculate the twiddle factors and manage the delay buffers
    reg [stage_num_bits:0] butterfly_op_counter;
    reg [stage_num_bits:0] stride_segment_counter;
    reg [stage_num_bits+1:0] mem_counter, mem_counter_reg;
    reg [stage_num_bits+1:0] mem_counter_read, mem_counter_read_reg;
    reg [stage_num_bits:0] butterfly_op_counter_reg, butterfly_op_counter_reg_reg, butterfly_op_counter_reg_reg_reg, butterfly_op_counter_reg_reg_reg_reg;
    reg [stage_num_bits:0] stride_segment_counter_reg;
    reg butterfly_op_counter_en;

    //Counter to flush the pipeline at the end of the data
    reg [Num_of_samples_bits-1:0] flush_count;

    //Memoryoutput wires
    wire [WIDTH-1:0] delay_out_real_0, delay_out_imag_0;
    wire [WIDTH-1:0] delay_out_real_1, delay_out_imag_1;
    wire [WIDTH-1:0] delay_out_real_2, delay_out_imag_2;
    wire [WIDTH-1:0] delay_out_real_3, delay_out_imag_3;
    //end wires for stages > 1

    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    reg [WIDTH-1:0] input_real_0_rr, input_imag_0_rr, input_real_0_rrr, input_imag_0_rrr, input_real_0_rrrr, input_imag_0_rrrr;
    reg input_en_r, butterfly_op_counter_en_r, start_butterfly_r, butterfly_op_counter_en_rr, butterfly_op_counter_en_rrr;

    wire butterfly_out_ready, start_butterfly;

    wire [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;
    wire [WIDTH-1:0] x2_re, x2_im, y2_re, y2_im;
    wire [WIDTH-1:0] x3_re, x3_im, y3_re, y3_im;

    //Manage counters, Control logic for memory and butterfly operation enable signals
    if(Num_of_samples > 8) begin : gen_input_logic 
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

    //Manage butterfly inputs based on stage number
    assign x0_re =  delay_out_real_0;
    assign x0_im =  delay_out_imag_0;
    assign x1_re =  delay_out_real_1;
    assign x1_im =  delay_out_imag_1;
    assign x2_re =  delay_out_real_2;
    assign x2_im =  delay_out_imag_2;
    assign x3_re =  delay_out_real_3;
    assign x3_im =  delay_out_imag_3;

    assign start_butterfly = butterfly_op_counter_en_rrr;

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
        .start(start_butterfly_r),
        .done(butterfly_out_ready)
    );

    memory_first_stage #(
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
        end else begin
            butterfly_op_counter_reg <= butterfly_op_counter;
            butterfly_op_counter_reg_reg <= butterfly_op_counter_reg;
            butterfly_op_counter_reg_reg_reg <= butterfly_op_counter_reg_reg;
            butterfly_op_counter_reg_reg_reg_reg <= butterfly_op_counter_reg_reg_reg;
            stride_segment_counter_reg <= stride_segment_counter;
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