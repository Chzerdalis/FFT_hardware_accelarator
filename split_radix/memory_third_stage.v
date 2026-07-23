`timescale 1ns / 1ps

module memory_third_stage_1 #(
    parameter WIDTH = 16,
    parameter DEPTH = 8, 
    parameter stage_num_bits = 8
)(
    input clock,
    input reset,
    input [stage_num_bits+1:0] stride_segment_counter,
    input [stage_num_bits+1:0] butterfly_op_counter,
    input step_mode_in,
    input step_mode_out,
    input [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,
    input [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,
    output [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3,
    output [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3
);
    //Both types mem
    localparam inter_offset_size = $clog2(DEPTH); 
    //for mul
    localparam position_num_bits = (inter_offset_size - 2) ? (inter_offset_size - 2) : 0; 
    localparam muxing_num_bits = (DEPTH > 4) ? (position_num_bits) : 0; 
    localparam vertical_offset_1_mul = 1;
    localparam vertical_offset_2_mul = 2;
    localparam vertical_offset_3_mul = 3;
    //no mul
    localparam intra_offset_size = inter_offset_size - 2; 
    localparam vertical_offset_1_no_mul = 1 << intra_offset_size;
    localparam vertical_offset_2_no_mul = 2 << intra_offset_size;
    localparam vertical_offset_3_no_mul = 3 << intra_offset_size;
    localparam stage_num_bits_no_mul = stage_num_bits - 1;

    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

//        (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
//        (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
//        (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
//        (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    //    reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    //    reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    //    reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    //    reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];


    wire [inter_offset_size:0] offset; //Both
    wire [inter_offset_size:0] offset_no_mul;
    
    // Final Output Registers
    reg  [2*WIDTH-1:0] output_0, output_1, output_2, output_3;
    reg  [inter_offset_size + 1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;
    wire [muxing_num_bits-1:0] position_count_mul;
    wire [inter_offset_size+1:0] position_count_no_mul;

    // Write read addresses for mul/stage 2 memory
    wire [inter_offset_size+1:0] write_addr, read_addr, write_addr_no_mul;

    assign write_addr = {stride_segment_counter[stage_num_bits+1], stride_segment_counter[stage_num_bits-1:0]};

    assign read_addr = {butterfly_op_counter[stage_num_bits+1], butterfly_op_counter[stage_num_bits-1:0]};

    assign write_addr_no_mul = {stride_segment_counter[stage_num_bits+1]^stride_segment_counter[stage_num_bits], stride_segment_counter[stage_num_bits-1:0]};

    generate
       if (DEPTH > 4) begin
           assign position_count_mul = butterfly_op_counter[position_num_bits-1:0];
           assign position_count_no_mul = butterfly_op_counter[stage_num_bits_no_mul:2];
       end else begin
           assign position_count_mul = 0;
           assign position_count_no_mul = 0;
       end
    endgenerate

    //Read adreess calculation 
    wire [inter_offset_size:0] next_addr0_mul, next_addr0_no_mul;
    wire [inter_offset_size:0] next_addr1_mul, next_addr1_no_mul;
    wire [inter_offset_size:0] next_addr2_mul, next_addr2_no_mul;
    wire [inter_offset_size:0] next_addr3_mul, next_addr3_no_mul;

    generate
        if(DEPTH < 4) begin : special_addresses_for_16_mul__8_no_mul__point_fft
            assign next_addr0_mul= offset;
            assign next_addr1_mul = offset + 1'b1;
            assign next_addr0_no_mul = offset;
            assign next_addr1_no_mul = offset + 1'b1;
            assign next_addr2_no_mul = offset;
            assign next_addr3_no_mul = offset + 1'b1;
        end else begin
            assign next_addr0_mul = offset + (position_count_mul<<2);
            assign next_addr1_mul = offset + vertical_offset_1_mul + (position_count_mul<<2);
            assign next_addr2_mul = offset + vertical_offset_2_mul + (position_count_mul<<2);
            assign next_addr3_mul = offset + vertical_offset_3_mul + (position_count_mul<<2);
            assign next_addr0_no_mul = offset_no_mul + position_count_no_mul;
            assign next_addr1_no_mul = offset_no_mul + vertical_offset_1_no_mul + position_count_no_mul;
            assign next_addr2_no_mul = offset_no_mul + vertical_offset_2_no_mul + position_count_no_mul;
            assign next_addr3_no_mul = offset_no_mul + vertical_offset_3_no_mul + position_count_no_mul;
        end
    endgenerate

    //Registers to hold data out of memory before output muxing
    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;

    //Registers to delay the select signal for output muxing
    reg [stage_num_bits+1:0] pipe1_op, pipe2_op; 
    reg step_mode_out_reg;

    assign offset = (butterfly_op_counter[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};
    assign offset_no_mul = (butterfly_op_counter[stage_num_bits_no_mul+1]^butterfly_op_counter[stage_num_bits_no_mul+2] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};

    always@(posedge clock) begin 
        if(reset) begin
            output_0 <= 0; 
            output_1 <= 0; 
            output_2 <= 0; 
            output_3 <= 0;
            pipe_rdata_A <= 0; 
            pipe_rdata_B <= 0; 
            pipe_rdata_C <= 0; 
            pipe_rdata_D <= 0;
            ea_addr_A <= 0; 
            ea_addr_B <= 0; 
            ea_addr_C <= 0; 
            ea_addr_D <= 0;
            pipe1_op <= 0; 
            pipe2_op <= 0;
        end else begin
            if(step_mode_in == 1'b0) begin
                if(stride_segment_counter[stage_num_bits] == 1'b0) begin
                    if(stride_segment_counter[1:0] == 2'b00) begin
                        mem_A[write_addr] <= {input_real_0, input_imag_0};
                        mem_B[write_addr] <= {input_real_1, input_imag_1};
                        mem_C[write_addr] <= {input_real_3, input_imag_3};
                        mem_D[write_addr] <= {input_real_2, input_imag_2};
                    end 
                    else if(stride_segment_counter[1:0] == 2'b01) begin
                        mem_A[write_addr] <= {input_real_2, input_imag_2};
                        mem_B[write_addr] <= {input_real_0, input_imag_0};
                        mem_C[write_addr] <= {input_real_1, input_imag_1};
                        mem_D[write_addr] <= {input_real_3, input_imag_3};
                    end 
                    else if(stride_segment_counter[1:0] == 2'b10) begin
                        mem_A[write_addr] <= {input_real_3, input_imag_3};
                        mem_B[write_addr] <= {input_real_2, input_imag_2};
                        mem_C[write_addr] <= {input_real_0, input_imag_0};
                        mem_D[write_addr] <= {input_real_1, input_imag_1};
                    end
                    else if(stride_segment_counter[1:0] == 2'b11) begin
                        mem_A[write_addr] <= {input_real_1, input_imag_1};
                        mem_B[write_addr] <= {input_real_3, input_imag_3};
                        mem_C[write_addr] <= {input_real_2, input_imag_2};
                        mem_D[write_addr] <= {input_real_0, input_imag_0};
                    end
                end else begin
                    if(stride_segment_counter[1:0] == 2'b00) begin
                        //mem_A[write_addr] <= mem_A[write_addr];
                        mem_B[write_addr] <= {input_real_0, input_imag_0};
                        //mem_C[write_addr] <= mem_C[write_addr];
                        mem_D[write_addr] <= {input_real_3, input_imag_3};
                    end 
                    else if(stride_segment_counter[1:0] == 2'b01) begin
                        mem_A[write_addr] <= {input_real_3, input_imag_3};
                        //mem_B[write_addr] <= mem_B[write_addr];
                        mem_C[write_addr] <= {input_real_0, input_imag_0};
                        //mem_D[write_addr] <= mem_D[write_addr];
                    end 
                    else if(stride_segment_counter[1:0] == 2'b10) begin
                        //mem_A[write_addr] <= mem_A[write_addr];
                        mem_B[write_addr] <= {input_real_3, input_imag_3};
                        //mem_C[write_addr] <= mem_C[write_addr];
                        mem_D[write_addr] <= {input_real_0, input_imag_0};
                    end
                    else if(stride_segment_counter[1:0] == 2'b11) begin
                        mem_A[write_addr] <= {input_real_0, input_imag_0};
                        //mem_B[write_addr] <= mem_B[write_addr];
                        mem_C[write_addr] <= {input_real_3, input_imag_3};
                        //mem_D[write_addr] <= mem_D[write_addr];
                    end
                end
            end else begin
                if(stride_segment_counter[stage_num_bits_no_mul:stage_num_bits_no_mul-1] == 2'b00) begin
                    mem_A[write_addr_no_mul] <= {input_real_0, input_imag_0};
                    mem_B[write_addr_no_mul] <= {input_real_1, input_imag_1};
                    mem_C[write_addr_no_mul] <= {input_real_2, input_imag_2};
                    mem_D[write_addr_no_mul] <= {input_real_3, input_imag_3};
                end 
                else if(stride_segment_counter[stage_num_bits_no_mul:stage_num_bits_no_mul-1] == 2'b01) begin
                    mem_A[write_addr_no_mul] <= {input_real_3, input_imag_3};
                    mem_B[write_addr_no_mul] <= {input_real_0, input_imag_0};
                    mem_C[write_addr_no_mul] <= {input_real_1, input_imag_1};
                    mem_D[write_addr_no_mul] <= {input_real_2, input_imag_2};
                end 
                else if(stride_segment_counter[stage_num_bits_no_mul:stage_num_bits_no_mul-1] == 2'b10) begin
                    mem_A[write_addr_no_mul] <= {input_real_2, input_imag_2};
                    mem_B[write_addr_no_mul] <= {input_real_3, input_imag_3};
                    mem_C[write_addr_no_mul] <= {input_real_0, input_imag_0};
                    mem_D[write_addr_no_mul] <= {input_real_1, input_imag_1};
                end
                else if(stride_segment_counter[stage_num_bits_no_mul:stage_num_bits_no_mul-1] == 2'b11) begin
                    mem_A[write_addr_no_mul] <= {input_real_1, input_imag_1};
                    mem_B[write_addr_no_mul] <= {input_real_2, input_imag_2};
                    mem_C[write_addr_no_mul] <= {input_real_3, input_imag_3};
                    mem_D[write_addr_no_mul] <= {input_real_0, input_imag_0};
                end
            end

            pipe1_op <= butterfly_op_counter;

            if(step_mode_out == 1'b0) begin
                if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: ea_addr_A <= next_addr0_mul; 
                        2'b01: ea_addr_A <= next_addr3_mul;
                        2'b10: ea_addr_A <= next_addr2_mul;
                        2'b11: ea_addr_A <= next_addr1_mul;
                    endcase

                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: ea_addr_B <= next_addr1_mul;
                        2'b01: ea_addr_B <= next_addr0_mul;
                        2'b10: ea_addr_B <= next_addr3_mul;
                        2'b11: ea_addr_B <= next_addr2_mul;
                    endcase

                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: ea_addr_C <= next_addr2_mul;
                        2'b01: ea_addr_C <= next_addr1_mul;
                        2'b10: ea_addr_C <= next_addr0_mul;
                        2'b11: ea_addr_C <= next_addr3_mul;
                    endcase

                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: ea_addr_D <= next_addr3_mul;
                        2'b01: ea_addr_D <= next_addr2_mul;
                        2'b10: ea_addr_D <= next_addr1_mul;
                        2'b11: ea_addr_D <= next_addr0_mul;
                    endcase
                end else begin
                    ea_addr_A <= read_addr;
                    ea_addr_B <= read_addr;
                    ea_addr_C <= read_addr;
                    ea_addr_D <= read_addr;
                end
            end else begin
                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_A <= next_addr0_no_mul; 
                    2'b01: ea_addr_A <= next_addr3_no_mul;
                    2'b10: ea_addr_A <= next_addr2_no_mul;
                    2'b11: ea_addr_A <= next_addr1_no_mul;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_B <= next_addr1_no_mul;
                    2'b01: ea_addr_B <= next_addr0_no_mul;
                    2'b10: ea_addr_B <= next_addr3_no_mul;
                    2'b11: ea_addr_B <= next_addr2_no_mul;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_C <= next_addr2_no_mul;
                    2'b01: ea_addr_C <= next_addr1_no_mul;
                    2'b10: ea_addr_C <= next_addr0_no_mul;
                    2'b11: ea_addr_C <= next_addr3_no_mul;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_D <= next_addr3_no_mul;
                    2'b01: ea_addr_D <= next_addr2_no_mul;
                    2'b10: ea_addr_D <= next_addr1_no_mul;
                    2'b11: ea_addr_D <= next_addr0_no_mul;
                endcase
            end

            pipe2_op <= pipe1_op;
            step_mode_out_reg <= step_mode_out;

            pipe_rdata_A <= mem_A[ea_addr_A];
            pipe_rdata_B <= mem_B[ea_addr_B];
            pipe_rdata_C <= mem_C[ea_addr_C];
            pipe_rdata_D <= mem_D[ea_addr_D];

            if(step_mode_out_reg == 1'b0) begin
                if(pipe2_op[stage_num_bits] == 1'b0) begin
                    if(pipe2_op[1:0] == 2'b00) begin
                        output_0 <= pipe_rdata_A;
                        output_1 <= pipe_rdata_B;
                        output_2 <= pipe_rdata_C;
                        output_3 <= pipe_rdata_D;
                    end
                    else if(pipe2_op[1:0] == 2'b01) begin
                        output_0 <= pipe_rdata_B;
                        output_1 <= pipe_rdata_C;
                        output_2 <= pipe_rdata_D;
                        output_3 <= pipe_rdata_A;
                    end
                    else if(pipe2_op[1:0] == 2'b10) begin
                        output_0 <= pipe_rdata_C;
                        output_1 <= pipe_rdata_D;
                        output_2 <= pipe_rdata_A;
                        output_3 <= pipe_rdata_B;
                    end
                    else if(pipe2_op[1:0] == 2'b11) begin
                        output_0 <= pipe_rdata_D;
                        output_1 <= pipe_rdata_A;
                        output_2 <= pipe_rdata_B;
                        output_3 <= pipe_rdata_C;
                    end
                end else begin
                    if(pipe2_op[muxing_num_bits+1:muxing_num_bits] == 2'b00) begin
                        output_0 <= pipe_rdata_A;
                        output_1 <= pipe_rdata_B;
                        output_2 <= pipe_rdata_C;
                        output_3 <= pipe_rdata_D;
                    end
                    else if(pipe2_op[muxing_num_bits+1:muxing_num_bits] == 2'b01) begin
                        output_0 <= pipe_rdata_B;
                        output_1 <= pipe_rdata_C;
                        output_2 <= pipe_rdata_D;
                        output_3 <= pipe_rdata_A;
                    end
                    else if(pipe2_op[muxing_num_bits+1:muxing_num_bits] == 2'b10) begin
                        output_0 <= pipe_rdata_C;
                        output_1 <= pipe_rdata_D;
                        output_2 <= pipe_rdata_A;
                        output_3 <= pipe_rdata_B;
                    end
                    else if(pipe2_op[muxing_num_bits+1:muxing_num_bits] == 2'b11) begin
                        output_0 <= pipe_rdata_D;
                        output_1 <= pipe_rdata_A;
                        output_2 <= pipe_rdata_B;
                        output_3 <= pipe_rdata_C;
                    end
                end 
            end else begin
                if(pipe2_op[1:0] == 2'b00) begin
                    output_0 <= pipe_rdata_A;
                    output_1 <= pipe_rdata_B;
                    output_2 <= pipe_rdata_C;
                    output_3 <= pipe_rdata_D;
                end
                else if(pipe2_op[1:0] == 2'b01) begin
                    output_0 <= pipe_rdata_B;
                    output_1 <= pipe_rdata_C;
                    output_2 <= pipe_rdata_D;
                    output_3 <= pipe_rdata_A;
                end
                else if(pipe2_op[1:0] == 2'b10) begin
                    output_0 <= pipe_rdata_C;
                    output_1 <= pipe_rdata_D;
                    output_2 <= pipe_rdata_A;
                    output_3 <= pipe_rdata_B;
                end
                else if(pipe2_op[1:0] == 2'b11) begin
                    output_0 <= pipe_rdata_D;
                    output_1 <= pipe_rdata_A;
                    output_2 <= pipe_rdata_B;
                    output_3 <= pipe_rdata_C;
                end
            end
        end
    end

    //split data into real and imaginary parts
    assign output_real_0 = output_0[2*WIDTH-1:WIDTH];
    assign output_imag_0 = output_0[WIDTH-1:0];
    assign output_real_1 = output_1[2*WIDTH-1:WIDTH];
    assign output_imag_1 = output_1[WIDTH-1:0];
    assign output_real_2 = output_2[2*WIDTH-1:WIDTH];
    assign output_imag_2 = output_2[WIDTH-1:0];
    assign output_real_3 = output_3[2*WIDTH-1:WIDTH];
    assign output_imag_3 = output_3[WIDTH-1:0];
endmodule

module memory_third_stage #(
    parameter WIDTH = 16,
    parameter DEPTH = 8, 
    parameter stage_num_bits = 8
)(
    input clock,
    input reset,
    input [stage_num_bits+1:0] stride_segment_counter,
    input [stage_num_bits+1:0] butterfly_op_counter,
    input step_mode_in,
    input step_mode_out,
    input [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,
    input [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,
    output [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3,
    output [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3
);

    // Both types mem
    localparam inter_offset_size = $clog2(DEPTH); 
    
    // For mul
    localparam position_num_bits = (inter_offset_size - 2) ? (inter_offset_size - 2) : 0; 
    localparam muxing_num_bits = (DEPTH > 4) ? (position_num_bits) : 0; 
    localparam vertical_offset_1_mul = 1;
    localparam vertical_offset_2_mul = 2;
    localparam vertical_offset_3_mul = 3;
    
    // No mul
    localparam intra_offset_size = inter_offset_size - 2; 
    localparam vertical_offset_1_no_mul = 1 << intra_offset_size;
    localparam vertical_offset_2_no_mul = 2 << intra_offset_size;
    localparam vertical_offset_3_no_mul = 3 << intra_offset_size;
    localparam stage_num_bits_no_mul = stage_num_bits - 1;

    // Force strict BRAM Inference
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    wire [inter_offset_size:0] offset; 
    wire [inter_offset_size:0] offset_no_mul;
    
    // Final Output Registers
    reg  [2*WIDTH-1:0] output_0, output_1, output_2, output_3;
    reg  [inter_offset_size + 1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;
    wire [muxing_num_bits-1:0] position_count_mul;
    wire [inter_offset_size+1:0] position_count_no_mul;

    // Write read addresses for mul/stage 2 memory
    wire [inter_offset_size+1:0] write_addr, read_addr, write_addr_no_mul;

    assign write_addr = {stride_segment_counter[stage_num_bits+1], stride_segment_counter[stage_num_bits-1:0]};
    assign read_addr = {butterfly_op_counter[stage_num_bits+1], butterfly_op_counter[stage_num_bits-1:0]};
    assign write_addr_no_mul = {stride_segment_counter[stage_num_bits+1]^stride_segment_counter[stage_num_bits], stride_segment_counter[stage_num_bits-1:0]};

    // Determine target write address based on step_mode_in
    wire [inter_offset_size+1:0] current_write_addr = (step_mode_in == 1'b0) ? write_addr : write_addr_no_mul;

    generate
       if (DEPTH > 4) begin
           assign position_count_mul = butterfly_op_counter[position_num_bits-1:0];
           assign position_count_no_mul = butterfly_op_counter[stage_num_bits_no_mul:2];
       end else begin
           assign position_count_mul = 0;
           assign position_count_no_mul = 0;
       end
    endgenerate

    // Read address calculation 
    wire [inter_offset_size:0] next_addr0_mul, next_addr0_no_mul;
    wire [inter_offset_size:0] next_addr1_mul, next_addr1_no_mul;
    wire [inter_offset_size:0] next_addr2_mul, next_addr2_no_mul;
    wire [inter_offset_size:0] next_addr3_mul, next_addr3_no_mul;

    generate
        if(DEPTH < 4) begin : special_addresses_for_16_mul__8_no_mul__point_fft
            assign next_addr0_mul= offset;
            assign next_addr1_mul = offset + 1'b1;
            assign next_addr0_no_mul = offset;
            assign next_addr1_no_mul = offset + 1'b1;
            assign next_addr2_no_mul = offset;
            assign next_addr3_no_mul = offset + 1'b1;
        end else begin : normal_addresses
            assign next_addr0_mul = offset + (position_count_mul<<2);
            assign next_addr1_mul = offset + vertical_offset_1_mul + (position_count_mul<<2);
            assign next_addr2_mul = offset + vertical_offset_2_mul + (position_count_mul<<2);
            assign next_addr3_mul = offset + vertical_offset_3_mul + (position_count_mul<<2);
            assign next_addr0_no_mul = offset_no_mul + position_count_no_mul;
            assign next_addr1_no_mul = offset_no_mul + vertical_offset_1_no_mul + position_count_no_mul;
            assign next_addr2_no_mul = offset_no_mul + vertical_offset_2_no_mul + position_count_no_mul;
            assign next_addr3_no_mul = offset_no_mul + vertical_offset_3_no_mul + position_count_no_mul;
        end
    endgenerate

    // Registers to hold data out of memory before output muxing
    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;

    // Registers to delay the select signal for output muxing
    reg [stage_num_bits+1:0] pipe1_op, pipe2_op; 
    reg step_mode_out_reg;

    assign offset = (butterfly_op_counter[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};
    assign offset_no_mul = (butterfly_op_counter[stage_num_bits_no_mul+1]^butterfly_op_counter[stage_num_bits_no_mul+2] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};

    // Shorthand data buses for cleaner combinational logic mapping
    wire [2*WIDTH-1:0] in0 = {input_real_0, input_imag_0};
    wire [2*WIDTH-1:0] in1 = {input_real_1, input_imag_1};
    wire [2*WIDTH-1:0] in2 = {input_real_2, input_imag_2};
    wire [2*WIDTH-1:0] in3 = {input_real_3, input_imag_3};

    // Explicit Write Enables and Data Inputs
    reg we_A, we_B, we_C, we_D;
    reg [2*WIDTH-1:0] din_A, din_B, din_C, din_D;

    // --- COMBINATIONAL WRITE LOGIC FOR BRAM INFERENCE ---
    always @(*) begin
        // Default assigns to prevent latches
        we_A = 1'b0; we_B = 1'b0; we_C = 1'b0; we_D = 1'b0;
        din_A = 0; din_B = 0; din_C = 0; din_D = 0;

        if(step_mode_in == 1'b0) begin
            if(stride_segment_counter[stage_num_bits] == 1'b0) begin
                we_A = 1'b1; we_B = 1'b1; we_C = 1'b1; we_D = 1'b1;
                case(stride_segment_counter[1:0])
                    2'b00: begin din_A = in0; din_B = in1; din_C = in3; din_D = in2; end
                    2'b01: begin din_A = in2; din_B = in0; din_C = in1; din_D = in3; end
                    2'b10: begin din_A = in3; din_B = in2; din_C = in0; din_D = in1; end
                    2'b11: begin din_A = in1; din_B = in3; din_C = in2; din_D = in0; end
                endcase
            end else begin
                case(stride_segment_counter[1:0])
                    2'b00: begin we_B = 1'b1; din_B = in0; we_D = 1'b1; din_D = in3; end
                    2'b01: begin we_A = 1'b1; din_A = in3; we_C = 1'b1; din_C = in0; end
                    2'b10: begin we_B = 1'b1; din_B = in3; we_D = 1'b1; din_D = in0; end
                    2'b11: begin we_A = 1'b1; din_A = in0; we_C = 1'b1; din_C = in3; end
                endcase
            end
        end else begin
            we_A = 1'b1; we_B = 1'b1; we_C = 1'b1; we_D = 1'b1;
            case(stride_segment_counter[stage_num_bits_no_mul:stage_num_bits_no_mul-1])
                2'b00: begin din_A = in0; din_B = in1; din_C = in2; din_D = in3; end
                2'b01: begin din_A = in3; din_B = in0; din_C = in1; din_D = in2; end
                2'b10: begin din_A = in2; din_B = in3; din_C = in0; din_D = in1; end
                2'b11: begin din_A = in1; din_B = in2; din_C = in3; din_D = in0; end
            endcase
        end
    end

    // --- MAIN CLOCKED PROCESS ---
    always@(posedge clock) begin 
        if(reset) begin
            output_0 <= 0; output_1 <= 0; output_2 <= 0; output_3 <= 0;
            pipe_rdata_A <= 0; pipe_rdata_B <= 0; pipe_rdata_C <= 0; pipe_rdata_D <= 0;
            ea_addr_A <= 0; ea_addr_B <= 0; ea_addr_C <= 0; ea_addr_D <= 0;
            pipe1_op <= 0; pipe2_op <= 0;
            step_mode_out_reg <= 0;
        end else begin
            // --- PERFECT BRAM WRITE TEMPLATE ---
            if (we_A) mem_A[current_write_addr] <= din_A;
            if (we_B) mem_B[current_write_addr] <= din_B;
            if (we_C) mem_C[current_write_addr] <= din_C;
            if (we_D) mem_D[current_write_addr] <= din_D;

            // --- STAGE 1: Calculate Read Address ---
            pipe1_op <= butterfly_op_counter;

            if(step_mode_out == 1'b0) begin
                if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: begin ea_addr_A <= next_addr0_mul; ea_addr_B <= next_addr1_mul; ea_addr_C <= next_addr2_mul; ea_addr_D <= next_addr3_mul; end
                        2'b01: begin ea_addr_A <= next_addr3_mul; ea_addr_B <= next_addr0_mul; ea_addr_C <= next_addr1_mul; ea_addr_D <= next_addr2_mul; end
                        2'b10: begin ea_addr_A <= next_addr2_mul; ea_addr_B <= next_addr3_mul; ea_addr_C <= next_addr0_mul; ea_addr_D <= next_addr1_mul; end
                        2'b11: begin ea_addr_A <= next_addr1_mul; ea_addr_B <= next_addr2_mul; ea_addr_C <= next_addr3_mul; ea_addr_D <= next_addr0_mul; end
                    endcase
                end else begin
                    ea_addr_A <= read_addr; ea_addr_B <= read_addr; ea_addr_C <= read_addr; ea_addr_D <= read_addr;
                end
            end else begin
                case (butterfly_op_counter[1:0])
                    2'b00: begin ea_addr_A <= next_addr0_no_mul; ea_addr_B <= next_addr1_no_mul; ea_addr_C <= next_addr2_no_mul; ea_addr_D <= next_addr3_no_mul; end
                    2'b01: begin ea_addr_A <= next_addr3_no_mul; ea_addr_B <= next_addr0_no_mul; ea_addr_C <= next_addr1_no_mul; ea_addr_D <= next_addr2_no_mul; end
                    2'b10: begin ea_addr_A <= next_addr2_no_mul; ea_addr_B <= next_addr3_no_mul; ea_addr_C <= next_addr0_no_mul; ea_addr_D <= next_addr1_no_mul; end
                    2'b11: begin ea_addr_A <= next_addr1_no_mul; ea_addr_B <= next_addr2_no_mul; ea_addr_C <= next_addr3_no_mul; ea_addr_D <= next_addr0_no_mul; end
                endcase
            end

            // --- STAGE 2: Memory Read to Pipe ---
            pipe2_op <= pipe1_op;
            step_mode_out_reg <= step_mode_out;

            pipe_rdata_A <= mem_A[ea_addr_A];
            pipe_rdata_B <= mem_B[ea_addr_B];
            pipe_rdata_C <= mem_C[ea_addr_C];
            pipe_rdata_D <= mem_D[ea_addr_D];

            // --- STAGE 3: Output Muxing ---
            if(step_mode_out_reg == 1'b0) begin
                if(pipe2_op[stage_num_bits] == 1'b0) begin
                    case(pipe2_op[1:0])
                        2'b00: begin output_0 <= pipe_rdata_A; output_1 <= pipe_rdata_B; output_2 <= pipe_rdata_C; output_3 <= pipe_rdata_D; end
                        2'b01: begin output_0 <= pipe_rdata_B; output_1 <= pipe_rdata_C; output_2 <= pipe_rdata_D; output_3 <= pipe_rdata_A; end
                        2'b10: begin output_0 <= pipe_rdata_C; output_1 <= pipe_rdata_D; output_2 <= pipe_rdata_A; output_3 <= pipe_rdata_B; end
                        2'b11: begin output_0 <= pipe_rdata_D; output_1 <= pipe_rdata_A; output_2 <= pipe_rdata_B; output_3 <= pipe_rdata_C; end
                    endcase
                end else begin
                    case(pipe2_op[muxing_num_bits+1:muxing_num_bits])
                        2'b00: begin output_0 <= pipe_rdata_A; output_1 <= pipe_rdata_B; output_2 <= pipe_rdata_C; output_3 <= pipe_rdata_D; end
                        2'b01: begin output_0 <= pipe_rdata_B; output_1 <= pipe_rdata_C; output_2 <= pipe_rdata_D; output_3 <= pipe_rdata_A; end
                        2'b10: begin output_0 <= pipe_rdata_C; output_1 <= pipe_rdata_D; output_2 <= pipe_rdata_A; output_3 <= pipe_rdata_B; end
                        2'b11: begin output_0 <= pipe_rdata_D; output_1 <= pipe_rdata_A; output_2 <= pipe_rdata_B; output_3 <= pipe_rdata_C; end
                    endcase
                end 
            end else begin
                case(pipe2_op[1:0])
                    2'b00: begin output_0 <= pipe_rdata_A; output_1 <= pipe_rdata_B; output_2 <= pipe_rdata_C; output_3 <= pipe_rdata_D; end
                    2'b01: begin output_0 <= pipe_rdata_B; output_1 <= pipe_rdata_C; output_2 <= pipe_rdata_D; output_3 <= pipe_rdata_A; end
                    2'b10: begin output_0 <= pipe_rdata_C; output_1 <= pipe_rdata_D; output_2 <= pipe_rdata_A; output_3 <= pipe_rdata_B; end
                    2'b11: begin output_0 <= pipe_rdata_D; output_1 <= pipe_rdata_A; output_2 <= pipe_rdata_B; output_3 <= pipe_rdata_C; end
                endcase
            end
        end
    end

    // Split data into real and imaginary parts
    assign output_real_0 = output_0[2*WIDTH-1:WIDTH]; assign output_imag_0 = output_0[WIDTH-1:0];
    assign output_real_1 = output_1[2*WIDTH-1:WIDTH]; assign output_imag_1 = output_1[WIDTH-1:0];
    assign output_real_2 = output_2[2*WIDTH-1:WIDTH]; assign output_imag_2 = output_2[WIDTH-1:0];
    assign output_real_3 = output_3[2*WIDTH-1:WIDTH]; assign output_imag_3 = output_3[WIDTH-1:0];

endmodule