`timescale 1ns / 1ps

module memory_first_stage #(
    parameter WIDTH = 32,
    parameter DEPTH = 16, 
    parameter stage_num_bits = 1
)(
    input clock,
    input reset,
    input [stage_num_bits:0] stride_segment_counter,
    input [stage_num_bits:0] butterfly_op_counter,
    input [stage_num_bits+1:0] mem_counter,
    input [stage_num_bits+1:0] mem_counter_read,
    input [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,
    input [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,
    output [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3,
    output [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3
);

    localparam inter_offset_size = $clog2(DEPTH);
    localparam intra_offset_size = inter_offset_size - 2;
    localparam vertical_offset_1 = 1 << intra_offset_size;
    localparam vertical_offset_2 = 2 << intra_offset_size;
    localparam vertical_offset_3 = 3 << intra_offset_size;

    //Normally for big ennough memories the synthesis tool will use block rams
     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    //Split memory into 4 different banks in order for each one to have 2 ports 
    //1 read and one write this help the tools use brams when the arrays are large enough
//    reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    wire [inter_offset_size:0] offset;
    
    // Final Output Registers
    reg [2*WIDTH-1:0] output_0, output_1, output_2, output_3;

    reg [inter_offset_size+1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;

    wire [inter_offset_size+1:0] position_count;
    
    //This is usefull to calculate the read address for stages > 2
    //For the 1st stage there is no memory 
    //For the 2nd stage position count is not needed to calculate the read address
    generate
        if (DEPTH > 4) begin
            assign position_count = butterfly_op_counter[stage_num_bits:2];
        end else begin
            assign position_count = 0;
        end
    endgenerate

    //Read adreess calculation 
    wire [inter_offset_size+1:0] next_addr0;
    wire [inter_offset_size+1:0] next_addr1;
    wire [inter_offset_size+1:0] next_addr2;
    wire [inter_offset_size+1:0] next_addr3;

    if(DEPTH < 4) begin : special_addresses_for_8_point_fft
        assign next_addr0 = offset;
        assign next_addr1 = offset + 1'b1;
        assign next_addr2 = offset;
        assign next_addr3 = offset + 1'b1;
    end else begin
        assign next_addr0 = offset + position_count;
        assign next_addr1 = offset + vertical_offset_1 + position_count;
        assign next_addr2 = offset + vertical_offset_2 + position_count;
        assign next_addr3 = offset + vertical_offset_3 + position_count;
    end

    //Note for later
    //In order to facilitate the different input pattern in this first_radix_slit_stage we have the interchange 
    //position_count with butterfly_op_counter[stage_num_bits:stage_num_bits-1] so the access is correct.

    //Registers to hold data out of memory before output muxing
    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;

    //Registers to delay the select signal for output muxing
    reg [stage_num_bits:0] pipe1_op, pipe2_op; 

    //Calculate the offset that is needed in order to go to the second part of the memory 
    //While in the first part new data is written
    //This is needed beacause the read and write patters are different and is we had only one part
    //While new data would have be written old data that hadnt be read yet would be overwritten
    //Theoretically is the pattern was the same we wouldnt need two parts
    assign offset = (mem_counter_read[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};



    if(DEPTH >= 4) begin : memory_logic
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
                //Write input data in memory depending on the stide sigment we are currently in.
                if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b00) begin
                    mem_A[mem_counter] <= {input_real_0, input_imag_0};
                    mem_B[mem_counter] <= {input_real_1, input_imag_1};
                    mem_C[mem_counter] <= {input_real_2, input_imag_2};
                    mem_D[mem_counter] <= {input_real_3, input_imag_3};
                end 
                else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b01) begin
                    mem_A[mem_counter] <= {input_real_3, input_imag_3};
                    mem_B[mem_counter] <= {input_real_0, input_imag_0};
                    mem_C[mem_counter] <= {input_real_1, input_imag_1};
                    mem_D[mem_counter] <= {input_real_2, input_imag_2};
                end 
                else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b10) begin
                    mem_A[mem_counter] <= {input_real_2, input_imag_2};
                    mem_B[mem_counter] <= {input_real_3, input_imag_3};
                    mem_C[mem_counter] <= {input_real_0, input_imag_0};
                    mem_D[mem_counter] <= {input_real_1, input_imag_1};
                end
                else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b11) begin
                    mem_A[mem_counter] <= {input_real_1, input_imag_1};
                    mem_B[mem_counter] <= {input_real_2, input_imag_2};
                    mem_C[mem_counter] <= {input_real_3, input_imag_3};
                    mem_D[mem_counter] <= {input_real_0, input_imag_0};
                end

                //Read stage 1 calculate the effective address before memory read
                //To easy the jod of the synthsys tools and maximize frequency

                pipe1_op <= butterfly_op_counter; //Register the read muxing signal 

                // Determine which address each memory needs to read
                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_A <= next_addr0; 
                    2'b01: ea_addr_A <= next_addr3;
                    2'b10: ea_addr_A <= next_addr2;
                    2'b11: ea_addr_A <= next_addr1;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_B <= next_addr1;
                    2'b01: ea_addr_B <= next_addr0;
                    2'b10: ea_addr_B <= next_addr3;
                    2'b11: ea_addr_B <= next_addr2;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_C <= next_addr2;
                    2'b01: ea_addr_C <= next_addr1;
                    2'b10: ea_addr_C <= next_addr0;
                    2'b11: ea_addr_C <= next_addr3;
                endcase

                case (butterfly_op_counter[1:0])
                    2'b00: ea_addr_D <= next_addr3;
                    2'b01: ea_addr_D <= next_addr2;
                    2'b10: ea_addr_D <= next_addr1;
                    2'b11: ea_addr_D <= next_addr0;
                endcase

                //Read stage 2 read from memory and store in pipe registers 
                pipe2_op <= pipe1_op;  //Register the read muxing signal 
                
                pipe_rdata_A <= mem_A[ea_addr_A];
                pipe_rdata_B <= mem_B[ea_addr_B];
                pipe_rdata_C <= mem_C[ea_addr_C];
                pipe_rdata_D <= mem_D[ea_addr_D];

                //Read stage 3 output muxing
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
    end else begin : no_memory_logic
        //This memory accomodates the 8 point 1st stage split radix fft
        //It inpus data in the same logic but multiplexes the output differently and has a different read address calculation logic
        //1st iter              //Hole memory
        // A  B  C  D             A  B  C  D
        // 0     2                0  1  2  3
        //    4     6             7  4  5  6

        //2nd iter
        // A  B  C  D
        //    1     3
        // 7     5
        
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
                //Write input data in memory depending on the stide sigment we are currently in.
                if(stride_segment_counter == 1'b0) begin
                    mem_A[mem_counter] <= {input_real_0, input_imag_0};
                    mem_B[mem_counter] <= {input_real_1, input_imag_1};
                    mem_C[mem_counter] <= {input_real_2, input_imag_2};
                    mem_D[mem_counter] <= {input_real_3, input_imag_3};
                end 
                else begin
                    mem_A[mem_counter] <= {input_real_3, input_imag_3};
                    mem_B[mem_counter] <= {input_real_0, input_imag_0};
                    mem_C[mem_counter] <= {input_real_1, input_imag_1};
                    mem_D[mem_counter] <= {input_real_2, input_imag_2};
                end

                //Read stage 1 calculate the effective address before memory read
                //To easy the jod of the synthsys tools and maximize frequency

                pipe1_op <= butterfly_op_counter; //Register the read muxing signal 

                // Determine which address each memory needs to read
                case (butterfly_op_counter)
                    1'b0: ea_addr_A <= next_addr0; 
                    1'b1: ea_addr_A <= next_addr3;
                endcase

                case (butterfly_op_counter)
                    1'b0: ea_addr_B <= next_addr1;
                    1'b1: ea_addr_B <= next_addr0;
                endcase

                case (butterfly_op_counter)
                    1'b0: ea_addr_C <= next_addr2;
                    1'b1: ea_addr_C <= next_addr1;
                endcase

                case (butterfly_op_counter)
                    1'b0: ea_addr_D <= next_addr3;
                    1'b1: ea_addr_D <= next_addr2;
                endcase

                //Read stage 2 read from memory and store in pipe registers 
                pipe2_op <= pipe1_op;  //Register the read muxing signal 
                
                pipe_rdata_A <= mem_A[ea_addr_A];
                pipe_rdata_B <= mem_B[ea_addr_B];
                pipe_rdata_C <= mem_C[ea_addr_C];
                pipe_rdata_D <= mem_D[ea_addr_D];

                //Read stage 3 output muxing
                if(pipe2_op == 1'b0) begin
                    output_0 <= pipe_rdata_A;
                    output_1 <= pipe_rdata_C;
                    output_2 <= pipe_rdata_B;
                    output_3 <= pipe_rdata_D;
                end
                else begin
                    output_0 <= pipe_rdata_B;
                    output_1 <= pipe_rdata_D;
                    output_2 <= pipe_rdata_C;
                    output_3 <= pipe_rdata_A;
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