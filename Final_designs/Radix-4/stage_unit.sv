`timescale 1ns / 1ps


module SdfUnit4_fast #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Tw_WIDTH = 16,
    parameter STAGE_NUM = 4, //Butterfly Stage
    parameter Num_of_samples = 256, //How many inputs
    parameter output_pipeline_bram = 0,
    parameter Bram = 1,
    parameter SimpleMult = 1,
    parameter Fast_DSP = 0,
    parameter carry_save = 1,
    parameter   twiddle_file_real_1 = "../Data/f_twiddle_real.mem",
    parameter   twiddle_file_imag_1 = "../Data/f_twiddle_imag.mem",
    parameter   twiddle_file_real_2 = "../Data/f_twiddle_real.mem",
    parameter   twiddle_file_imag_2 = "../Data/f_twiddle_imag.mem",
    parameter   twiddle_file_real_3 = "../Data/f_twiddle_real.mem",
    parameter   twiddle_file_imag_3 = "../Data/f_twiddle_imag.mem"
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
    localparam twiddle_array_size = 1 << (2*(STAGE_NUM-1));
    localparam mem_delay = (output_pipeline_bram == 0) ? 3 : 4; //Memory delay for the output pipeline, 2 cycles for LUTRAM and 3 cycles for BRAM


    //Wires needed for stages > 1
    //Counters to calculate the twiddle factors and manage the delay buffers
    reg [stage_num_bits+1:0] butterfly_op_counter;
    reg [stage_num_bits+1:0] stride_segment_counter;
    wire [stage_num_bits+1:0] butterfly_op_counter_de;
    reg  [stage_num_bits+1:0] butterfly_op_counter_reg;
    reg [stage_num_bits+1:0] stride_segment_counter_reg;
    reg butterfly_op_counter_en;
    reg stride_segment_counter_en;

    //Counter to flush the pipeline at the end of the data
    reg [Num_of_samples_bits-1:0] flush_count;

    //Memory output wires
    wire [WIDTH-1:0] delay_out_real_0, delay_out_imag_0;
    wire [WIDTH-1:0] delay_out_real_1, delay_out_imag_1;
    wire [WIDTH-1:0] delay_out_real_2, delay_out_imag_2;
    wire [WIDTH-1:0] delay_out_real_3, delay_out_imag_3;
    //end wires for stages > 1

    reg [WIDTH-1:0] input_real_0_r, input_real_1_r, input_real_2_r, input_real_3_r;
    reg [WIDTH-1:0] input_imag_0_r, input_imag_1_r, input_imag_2_r, input_imag_3_r;
    wire [WIDTH-1:0] input_real_0_de, input_imag_0_de;
    reg start_butterfly_r;
    wire butterfly_op_counter_en_de;

    wire butterfly_out_ready, start_butterfly;

    //(* use_dsp = "yes" *) wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1, twiddle_index_2;
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0;
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0_de;


    wire [WIDTH-1:0] x0_re, x0_im, y0_re, y0_im;
    wire [WIDTH-1:0] x1_re, x1_im, y1_re, y1_im;
    wire [WIDTH-1:0] x2_re, x2_im, y2_re, y2_im;
    wire [WIDTH-1:0] x3_re, x3_im, y3_re, y3_im;

    wire [Tw_WIDTH - 1:0] w0re, w0i, w1re, w1i, w2re, w2i;

    //Us edistributed RAM for twiddle factors to maximize frequency 
    //Else the tools might use block rams that have longer access times
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_real_1 [0:twiddle_array_size-1];
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_imag_1 [0:twiddle_array_size-1];
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_real_2 [0:twiddle_array_size-1];
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_imag_2 [0:twiddle_array_size-1];
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_real_3 [0:twiddle_array_size-1];
    (* ram_style = "distributed" *) reg [Tw_WIDTH - 1:0] w_imag_3 [0:twiddle_array_size-1];

    // reg [Tw_WIDTH - 1:0] w_real [0:Num_of_samples-1];
    // reg [Tw_WIDTH - 1:0] w_imag [0:Num_of_samples-1];

    //Include the correct twiddle factors depending on size of FFT and data width
    initial begin
        $readmemh(twiddle_file_real_1, w_real_1);
        $readmemh(twiddle_file_imag_1, w_imag_1);

        $readmemh(twiddle_file_real_2, w_real_2);
        $readmemh(twiddle_file_imag_2, w_imag_2);
        
        $readmemh(twiddle_file_real_3, w_real_3);
        $readmemh(twiddle_file_imag_3, w_imag_3);

        // $readmemh("../Data/f_twiddle_real_1.mem", w_real);
        // $readmemh("../Data/f_twiddle_imag_1.mem", w_imag);
    end

    //Manage counters
    if (STAGE_NUM > 1) begin : gen_input_logic
        always @(posedge clock) begin
            if (reset) begin
                stride_segment_counter <= {(sn-1){1'b0}};
                butterfly_op_counter <= {(sn-1){1'b0}};
                butterfly_op_counter_en <= 1'b0;
                flush_count <= 0;
            end else begin
                if(input_en) begin
                    if(stride_segment_counter[stage_num_bits:0] == {2'b10, {(sn-4){1'b1}}} && butterfly_op_counter_en == 0) begin
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

    //Manage twiddle factors based on stage number
    assign twiddle_index_0 = (STAGE_NUM == 1) ? 3'b0 : (butterfly_op_counter_reg[stage_num_bits:0]);


    //Assign twiddle factors
    assign w0re = w_real_1[twiddle_index_0_de];
    assign w0i = w_imag_1[twiddle_index_0_de];
    assign w1re = w_real_2[twiddle_index_0_de];
    assign w1i = w_imag_2[twiddle_index_0_de];
    assign w2re = w_real_3[twiddle_index_0_de];
    assign w2i = w_imag_3[twiddle_index_0_de];

    //Manage butterfly inputs based on stage number
    assign x0_re = (STAGE_NUM == 1) ? input_real_0_r : delay_out_real_0;
    assign x0_im = (STAGE_NUM == 1) ? input_imag_0_r : delay_out_imag_0;

    assign x1_re = (STAGE_NUM == 1) ? input_real_1_r : delay_out_real_1;
    assign x1_im = (STAGE_NUM == 1) ? input_imag_1_r : delay_out_imag_1;
    assign x2_re = (STAGE_NUM == 1) ? input_real_2_r : delay_out_real_2;
    assign x2_im = (STAGE_NUM == 1) ? input_imag_2_r : delay_out_imag_2;

    if(STAGE_NUM > 1) begin : gen_4th_butterfly_input
        assign x3_re = (butterfly_op_counter_de[sn-3:sn-4] == 2'b00) ? input_real_0_de : delay_out_real_3;
        assign x3_im = (butterfly_op_counter_de[sn-3:sn-4] == 2'b00) ? input_imag_0_de : delay_out_imag_3;
    end else begin
        assign x3_re = input_real_3_r;
        assign x3_im = input_imag_3_r;
    end

    assign start_butterfly = (STAGE_NUM == 1) ? input_en : butterfly_op_counter_en_de;

    butterfly_radix4_pipeline #(
        .WIDTH(WIDTH),
        .Tw_WIDTH(Tw_WIDTH),
        .SimpleMult(SimpleMult),
        .Fast_DSP(Fast_DSP),
        .carry_save(carry_save),
        .stage_num(STAGE_NUM)
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
            .stage_num_bits(stage_num_bits),
            .Bram(Bram),
            .output_pipeline_bram(output_pipeline_bram)
        ) mem (
            .clock(clock),
            .reset(reset),
            .stride_segment_counter(stride_segment_counter_reg[stage_num_bits:0]),
            .butterfly_op_counter(butterfly_op_counter_reg[stage_num_bits:0]),
            .mem_counter(stride_segment_counter_reg),
            .mem_counter_read(butterfly_op_counter_reg),
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

    delay_reg_reset #(
        .WIDTH(stage_num_bits+2),
        .DELAY(mem_delay)
    ) u_delay_butterfly_op_counter_reg(
        .clock(clock),
        .reset(reset),
        .data_in(butterfly_op_counter_reg),
        .data_out(butterfly_op_counter_de)
    );

    delay_reg #(
        .WIDTH($clog2(Num_of_samples)),
        .DELAY(mem_delay)
    ) u_delay_twiddle_index_0 (
        .clock(clock),
        .data_in(twiddle_index_0),
        .data_out(twiddle_index_0_de)
    );


    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(mem_delay)
    ) u_delay_input_real_0_r (
        .clock(clock),
        .data_in(input_real_0_r),
        .data_out(input_real_0_de)
    );

    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(mem_delay)
    ) u_delay_input_imag_0_r (
        .clock(clock),
        .data_in(input_imag_0_r),
        .data_out(input_imag_0_de)
    );

    delay_reg_reset #(
        .WIDTH(1),
        .DELAY(mem_delay)
    ) u_delay_butterfly_op_counter_en (
        .clock(clock),
        .reset(reset),
        .data_in(butterfly_op_counter_en),
        .data_out(butterfly_op_counter_en_de)
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
            butterfly_op_counter_reg <= {(stage_num_bits+2){1'b0}};
            stride_segment_counter_reg <= {(stage_num_bits+1){1'b0}};
        end else begin
            butterfly_op_counter_reg <= butterfly_op_counter;
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
            start_butterfly_r <= {(stage_num_bits+1){1'b0}};
        end else begin
            input_real_0_r <= input_real_0;
            input_real_1_r <= input_real_1;
            input_real_2_r <= input_real_2;
            input_real_3_r <= input_real_3;
            input_imag_0_r <= input_imag_0;
            input_imag_1_r <= input_imag_1;
            input_imag_2_r <= input_imag_2;
            input_imag_3_r <= input_imag_3;
            start_butterfly_r <= start_butterfly;
        end
    end

endmodule