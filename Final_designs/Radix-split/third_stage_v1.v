`timescale 1ns / 1ps

module Split_radix_ThirdStage_ #(
    parameter WIDTH = 16, // Data Bit Lenght
    parameter Num_of_samples = 256, //How many inputs
    parameter STAGE_NUM = 2
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
    localparam stage_num_bits = $clog2(Num_of_samples/(4 * 2**(STAGE_NUM-2))) - 1;
    localparam step_size = Num_of_samples/(2**(STAGE_NUM-2));
    localparam sn = stage_num_bits + 3;
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;
    localparam Depth = step_size/(4*2); //step size / 4 banks / 2

    reg [stage_num_bits+1:0] butterfly_op_counter;
    reg [stage_num_bits+1:0] stride_segment_counter; //Here stride segment counter and butterfly are combined with mem_counter and mem_counter_read to save registers
    reg step_mode_in, step_mode_out, step_count_in, step_count_out;

    //registers for counters
    reg [stage_num_bits:0] butterfly_op_counter_reg, butterfly_op_counter_reg_reg, butterfly_op_counter_reg_reg_reg;
    reg outmode, outmode_reg, outmode_reg_reg, outmode_reg_reg_reg, outmode_reg_reg_reg_reg, outmode_reg_reg_reg_reg_reg;
    reg [stage_num_bits:0] stride_segment_counter_reg, stride_segment_counter_reg_reg, stride_segment_counter_reg_reg_reg;
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
    
//    (* rom_style = "block" *) reg [WIDTH/2 - 1:0] w_real [0:Num_of_samples/2-1];
//    (* rom_style = "block" *) reg [WIDTH/2 - 1:0] w_imag [0:Num_of_samples/2-1];
    
    wire [$clog2(Num_of_samples)-1:0] twiddle_index_0, twiddle_index_1 ;
    reg [$clog2(Num_of_samples)-1:0] twiddle_index_0_r, twiddle_index_1_r;

    initial begin
        // $readmemh(twiddle_file_real_1, w_real_1);
        // $readmemh(twiddle_file_imag_1, w_imag_1);

        // $readmemh(twiddle_file_real_2, w_real_2);
        // $readmemh(twiddle_file_imag_2, w_imag_2);
        
        // $readmemh(twiddle_file_real_3, w_real_3);
        // $readmemh(twiddle_file_imag_3, w_imag_3);

        $readmemh("../Data/f_twiddle_real_1.mem", w_real);
        $readmemh("../Data/f_twiddle_imag_1.mem", w_imag);
    end

    generate
        //Manage counters, Control logic for memory and butterfly operation enable signals
        if(step_size > 16) begin : gen_input_logic 
            always @(posedge clock) begin
                if (reset) begin
                    stride_segment_counter <= {1'b1, {(stage_num_bits+1){1'b0}}};
                    butterfly_op_counter <= {1'b1, {(stage_num_bits+1){1'b0}}};
                    butterfly_op_counter_en <= 1'b0;
                    flush_count <= 0;
                    step_mode_in <= 1'b0;
                    step_mode_out <= 1'b0;
                    step_count_in <= 1'b1;
                    step_count_out <= 1'b1;
                end else begin
                    if(input_en) begin
                        if(stride_segment_counter[stage_num_bits:0] == {1'b0, {(stage_num_bits+1-2){1'b1}}, 1'b0} && butterfly_op_counter_en == 0) begin
                            butterfly_op_counter_en <= 1'b1;
                            butterfly_op_counter <= butterfly_op_counter;
                            flush_count <= Num_of_samples/4 - 1;
                        //This helps with the right placement of values in memory 
                        end else if(butterfly_op_counter == {1'b0, {(stage_num_bits+1){1'b1}}} && step_mode_out == 1'b1) begin
                            butterfly_op_counter <= butterfly_op_counter ^ {1'b0, {(stage_num_bits+1){1'b1}}};
                            butterfly_op_counter_en <= 1'b1;
                            flush_count <= flush_count - 1'b1;
                        end else if (butterfly_op_counter_en) begin
                            butterfly_op_counter <= butterfly_op_counter + 1'b1;
                            butterfly_op_counter_en <= 1'b1;
                            flush_count <= flush_count - 1'b1;
                        end else begin
                            butterfly_op_counter <= butterfly_op_counter;
                            butterfly_op_counter_en <= 1'b0;
                            flush_count <= flush_count;
                        end

                        //This helps with the right placement of values in memory 
                        if(stride_segment_counter == {1'b0, {(stage_num_bits+1){1'b1}}} && step_mode_in == 1'b1) begin
                            stride_segment_counter <= stride_segment_counter ^ {1'b0, {(stage_num_bits+1){1'b1}}};
                        end else begin
                            stride_segment_counter <= stride_segment_counter + 1'b1;
                        end

                        if(flush_count == 0) begin
                            //Have to reset to the initial state 
                        end else begin
                            //Nothing 
                        end
                    
                    end else begin
                        if (flush_count == 0) begin
                            butterfly_op_counter <= {1'b1, {(stage_num_bits+1){1'b0}}};
                            stride_segment_counter <= {1'b1, {(stage_num_bits+1){1'b0}}};
                            butterfly_op_counter_en <= 1'b0;
                            flush_count <= flush_count;
                        end else begin
                            butterfly_op_counter <= butterfly_op_counter + 1'b1;
                            stride_segment_counter <= stride_segment_counter;
                            butterfly_op_counter_en <= butterfly_op_counter_en;
                            flush_count <= flush_count - 1'b1;
                        end
                    end

                   
                    //Measures halfs since step one is half step size and step 2 is step size
                    if(stride_segment_counter[stage_num_bits:0] == {(stage_num_bits+1){1'b1}} && step_mode_in == 1'b0) begin
                        step_count_in <= 1'b1;
                        if(step_count_in == 1'b1) begin
                            step_mode_in <= 1'b1;
                            step_count_in <= 1'b0;
                        end
                    end else if(stride_segment_counter[stage_num_bits:0] == {(stage_num_bits+1){1'b1}} && step_mode_in == 1'b1) begin
                        step_mode_in <= 1'b0;
                    end else begin
                        step_mode_in <= step_mode_in;
                    end

                    if(butterfly_op_counter[stage_num_bits:0] == {(stage_num_bits+1){1'b1}} && step_mode_out == 1'b0 && butterfly_op_counter_en == 1'b1) begin
                        step_count_out <= 1'b1;
                        if(step_count_out == 1'b1) begin
                            step_mode_out <= 1'b1;
                            step_count_out <= 1'b0;
                        end
                    end else if(butterfly_op_counter[stage_num_bits:0] == {(stage_num_bits+1){1'b1}} && step_mode_out == 1'b1 && butterfly_op_counter_en == 1'b1) begin
                        step_mode_out <= 1'b0;
                    end else begin
                        step_mode_out <= step_mode_out;
                    end
                end
            end
        end
    endgenerate


    memory_third_stage #(
        .WIDTH(WIDTH),
        .DEPTH(Depth),
        .stage_num_bits(stage_num_bits)
    ) memory_inst (
        .clock(clock),
        .reset(reset),
        .stride_segment_counter(stride_segment_counter),
        .butterfly_op_counter(butterfly_op_counter),
        .step_mode_in(step_mode_in),
        .step_mode_out(step_mode_out),
        .input_real_0(input_real_0), .input_imag_0(input_imag_0),
        .input_real_1(input_real_1), .input_imag_1(input_imag_1),
        .input_real_2(input_real_2), .input_imag_2(input_imag_2),
        .input_real_3(input_real_3), .input_imag_3(input_imag_3),
        .output_real_0(output_real_0), .output_imag_0(output_imag_0),
        .output_real_1(output_real_1), .output_imag_1(output_imag_1),
        .output_real_2(output_real_2), .output_imag_2(output_imag_2),
        .output_real_3(output_real_3), .output_imag_3(output_imag_3)
    );

endmodule