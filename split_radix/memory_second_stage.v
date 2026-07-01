`timescale 1ns / 1ps

module memory_second_stage_1 #(
   parameter WIDTH = 16,
   parameter DEPTH = 256, 
   parameter stage_num_bits = 9
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
   localparam position_num_bits = (inter_offset_size - 2) ? (inter_offset_size - 2) : 0; //
   localparam muxing_num_bits = (DEPTH > 4) ? (position_num_bits) : 0; //We need at least 1 bit for the muxing even if there is only one position
   localparam vertical_offset_1 = 1;
   localparam vertical_offset_2 = 2;
   localparam vertical_offset_3 = 3;

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

   wire [muxing_num_bits-1:0] position_count;

   wire [inter_offset_size+1:0] write_addr, read_addr;
 
   //This is usefull to calculate the read address for stages > 2
   //For the 1st stage there is no memory 
   //For the 2nd stage position count is not needed to calculate the read address
   generate
       if (DEPTH > 4) begin
           assign position_count = butterfly_op_counter[position_num_bits-1:0];
       end else begin
           assign position_count = 0;
       end
   endgenerate

   //Read adreess calculation 
   wire [inter_offset_size+1:0] next_addr0;
   wire [inter_offset_size+1:0] next_addr1;
   wire [inter_offset_size+1:0] next_addr2;
   wire [inter_offset_size+1:0] next_addr3;

   if(DEPTH < 4) begin : special_addresses_for_16_point_fft
       assign next_addr0 = offset;
       assign next_addr1 = offset + 1'b1;
   end else begin
       assign next_addr0 = offset + (position_count<<2);
       assign next_addr1 = offset + vertical_offset_1 + (position_count<<2);
       assign next_addr2 = offset + vertical_offset_2 + (position_count<<2);
       assign next_addr3 = offset + vertical_offset_3 + (position_count<<2);
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

   //Write address is like this since we write the first 24(32-the ones that go straight through) values in the first 16 slots 
   //and the second 24(32-the ones that go straight through) in the other 16 
   assign write_addr = {mem_counter[stage_num_bits+1], mem_counter[stage_num_bits-1:0]};

   assign read_addr = {mem_counter_read[stage_num_bits+1], mem_counter_read[stage_num_bits-1:0]};

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
               //For thge second stage we overwrite the data that go to the butterfly after the half of the values have been writen
               //At this time the 2 inputs can go direclty to the butt but the two can be saved since two old values will be read from the memory
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
               //Read stage 1 calculate the effective address before memory read
               //To easy the jod of the synthsys tools and maximize frequency

               pipe1_op <= butterfly_op_counter; //Register the read muxing signal 

               //Determine which address each memory needs to read
               if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                   case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                       2'b00: ea_addr_A <= next_addr0; 
                       2'b01: ea_addr_A <= next_addr3;
                       2'b10: ea_addr_A <= next_addr2;
                       2'b11: ea_addr_A <= next_addr1;
                   endcase

                   case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                       2'b00: ea_addr_B <= next_addr1;
                       2'b01: ea_addr_B <= next_addr0;
                       2'b10: ea_addr_B <= next_addr3;
                       2'b11: ea_addr_B <= next_addr2;
                   endcase

                   case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                       2'b00: ea_addr_C <= next_addr2;
                       2'b01: ea_addr_C <= next_addr1;
                       2'b10: ea_addr_C <= next_addr0;
                       2'b11: ea_addr_C <= next_addr3;
                   endcase

                   case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                       2'b00: ea_addr_D <= next_addr3;
                       2'b01: ea_addr_D <= next_addr2;
                       2'b10: ea_addr_D <= next_addr1;
                       2'b11: ea_addr_D <= next_addr0;
                   endcase
               end else begin
                   ea_addr_A <= read_addr;
                   ea_addr_B <= read_addr;
                   ea_addr_C <= read_addr;
                   ea_addr_D <= read_addr;
               end

               //Read stage 2 read from memory and store in pipe registers 
               pipe2_op <= pipe1_op;  //Register the read muxing signal 
                
               pipe_rdata_A <= mem_A[ea_addr_A];
               pipe_rdata_B <= mem_B[ea_addr_B];
               pipe_rdata_C <= mem_C[ea_addr_C];
               pipe_rdata_D <= mem_D[ea_addr_D];

               //Read stage 3 output muxing
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
           end 
       end
   end else begin
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
               //For thge second stage we overwrite the data that go to the butterfly after the half of the values have been writen
               //At this time the 2 inputs can go direclty to the butt but the two can be saved since two old values will be read from the memory
               if(stride_segment_counter[stage_num_bits] == 1'b0) begin
                   if(stride_segment_counter[0] == 1'b0) begin
                       mem_A[write_addr] <= {input_real_0, input_imag_0};
                       mem_B[write_addr] <= {input_real_3, input_imag_3};
                       mem_C[write_addr] <= {input_real_1, input_imag_1};
                       mem_D[write_addr] <= {input_real_2, input_imag_2};
                   end 
                   else if(stride_segment_counter[0] == 1'b1) begin
                       mem_A[write_addr] <= {input_real_2, input_imag_2};
                       mem_B[write_addr] <= {input_real_0, input_imag_0};
                       mem_C[write_addr] <= {input_real_3, input_imag_3};
                       mem_D[write_addr] <= {input_real_1, input_imag_1};
                   end 
               end else begin
                   if(stride_segment_counter[0] == 1'b0) begin
                       mem_A[write_addr] <= mem_A[write_addr];
                       mem_B[write_addr] <= mem_B[write_addr];
                       mem_C[write_addr] <= {input_real_0, input_imag_0};
                       mem_D[write_addr] <= {input_real_3, input_imag_3};
                   end 
                   else if(stride_segment_counter[0] == 1'b1) begin
                       mem_A[write_addr] <= {input_real_3, input_imag_3};
                       mem_B[write_addr] <= mem_B[write_addr];
                       mem_C[write_addr] <= mem_C[write_addr];
                       mem_D[write_addr] <= {input_real_0, input_imag_0};
                   end
               end
               //Read stage 1 calculate the effective address before memory read
               //To easy the jod of the synthsys tools and maximize frequency

               pipe1_op <= butterfly_op_counter; //Register the read muxing signal 

               //Determine which address each memory needs to read
               if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                   case (butterfly_op_counter[0])
                       1'b0: ea_addr_A <= next_addr0; 
                       1'b1: ea_addr_A <= next_addr1;
                   endcase

                   case (butterfly_op_counter[0])
                       1'b0: ea_addr_B <= next_addr1;
                       1'b1: ea_addr_B <= next_addr0;
                   endcase

                   case (butterfly_op_counter[0])
                        1'b0: ea_addr_C <= next_addr0;
                        1'b1: ea_addr_C <= next_addr1;
                   endcase

                   case (butterfly_op_counter[0])
                       1'b0: ea_addr_D <= next_addr1;
                       1'b1: ea_addr_D <= next_addr0;
                   endcase
               end else begin
                   ea_addr_A <= read_addr;
                   ea_addr_B <= read_addr;
                   ea_addr_C <= read_addr;
                   ea_addr_D <= read_addr;
               end

               //Read stage 2 read from memory and store in pipe registers 
               pipe2_op <= pipe1_op;  //Register the read muxing signal 
                
               pipe_rdata_A <= mem_A[ea_addr_A];
               pipe_rdata_B <= mem_B[ea_addr_B];
               pipe_rdata_C <= mem_C[ea_addr_C];
               pipe_rdata_D <= mem_D[ea_addr_D];

               //Read stage 3 output muxing
               if(pipe2_op[stage_num_bits] == 1'b0) begin
                   if(pipe2_op[0] == 1'b0) begin
                       output_0 <= pipe_rdata_A;
                       output_1 <= pipe_rdata_C;
                       output_2 <= pipe_rdata_B;
                       output_3 <= pipe_rdata_D;
                   end
                   else if(pipe2_op[0] == 1'b1) begin
                       output_0 <= pipe_rdata_B;
                       output_1 <= pipe_rdata_D;
                       output_2 <= pipe_rdata_C;
                       output_3 <= pipe_rdata_A;
                   end
               end else begin
                   if(pipe2_op[0] == 1'b0) begin
                       output_0 <= pipe_rdata_A;
                       output_1 <= pipe_rdata_B;
                       output_2 <= pipe_rdata_C;
                       output_3 <= pipe_rdata_D;
                   end
                   else if(pipe2_op[0] == 1'b1) begin
                       output_0 <= pipe_rdata_B;
                       output_1 <= pipe_rdata_C;
                       output_2 <= pipe_rdata_D;
                       output_3 <= pipe_rdata_A;
                   end
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

`timescale 1ns / 1ps

module memory_second_stage #(
    parameter WIDTH = 16,
    parameter DEPTH = 8, 
    parameter stage_num_bits = 8
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
    localparam position_num_bits = (inter_offset_size - 2) ? (inter_offset_size - 2) : 0; 
    localparam muxing_num_bits = (DEPTH > 4) ? (position_num_bits) : 0; 
    localparam vertical_offset_1 = 1;
    localparam vertical_offset_2 = 2;
    localparam vertical_offset_3 = 3;

    // Force strict BRAM Inference
//    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
//    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
//    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
//    (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];
    
    (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

//    reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
//    reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    wire [inter_offset_size:0] offset;
    
    // Final Output Registers
    reg [2*WIDTH-1:0] output_0, output_1, output_2, output_3;
    reg [inter_offset_size+1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;
    wire [muxing_num_bits-1:0] position_count;
    wire [inter_offset_size+1:0] write_addr, read_addr;
 
    generate
        if (DEPTH > 4) begin
            assign position_count = butterfly_op_counter[position_num_bits-1:0];
        end else begin
            assign position_count = 0;
        end
    endgenerate

    // Read address calculation 
    wire [inter_offset_size+1:0] next_addr0;
    wire [inter_offset_size+1:0] next_addr1;
    wire [inter_offset_size+1:0] next_addr2;
    wire [inter_offset_size+1:0] next_addr3;

    generate 
        if(DEPTH < 4) begin : special_addresses_for_16_point_fft
            assign next_addr0 = offset;
            assign next_addr1 = offset + 1'b1;
        end else begin : normal_addresses
            assign next_addr0 = offset + (position_count<<2);
            assign next_addr1 = offset + vertical_offset_1 + (position_count<<2);
            assign next_addr2 = offset + vertical_offset_2 + (position_count<<2);
            assign next_addr3 = offset + vertical_offset_3 + (position_count<<2);
        end
    endgenerate

    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;
    reg [stage_num_bits:0] pipe1_op, pipe2_op; 

    assign offset = (mem_counter_read[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};
    assign write_addr = {mem_counter[stage_num_bits+1], mem_counter[stage_num_bits-1:0]};
    assign read_addr = {mem_counter_read[stage_num_bits+1], mem_counter_read[stage_num_bits-1:0]};

    // Shorthand data buses to clean up the multiplexer logic
    wire [2*WIDTH-1:0] in0 = {input_real_0, input_imag_0};
    wire [2*WIDTH-1:0] in1 = {input_real_1, input_imag_1};
    wire [2*WIDTH-1:0] in2 = {input_real_2, input_imag_2};
    wire [2*WIDTH-1:0] in3 = {input_real_3, input_imag_3};

    // Explicit Write Enables and Data Inputs for perfect BRAM mapping
    reg we_A, we_B, we_C, we_D;
    reg [2*WIDTH-1:0] din_A, din_B, din_C, din_D;

    generate
        if(DEPTH >= 4) begin : gen_logic_geq_4
            always @(*) begin
                // Default assigns prevent inferred latches
                we_A = 1'b0; we_B = 1'b0; we_C = 1'b0; we_D = 1'b0;
                din_A = 0; din_B = 0; din_C = 0; din_D = 0;

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
            end
        end else begin : gen_logic_lt_4
            always @(*) begin
                // Default assigns prevent inferred latches
                we_A = 1'b0; we_B = 1'b0; we_C = 1'b0; we_D = 1'b0;
                din_A = 0; din_B = 0; din_C = 0; din_D = 0;

                if(stride_segment_counter[stage_num_bits] == 1'b0) begin
                    we_A = 1'b1; we_B = 1'b1; we_C = 1'b1; we_D = 1'b1;
                    case(stride_segment_counter[0])
                        1'b0: begin din_A = in0; din_B = in3; din_C = in1; din_D = in2; end
                        1'b1: begin din_A = in2; din_B = in0; din_C = in3; din_D = in1; end
                    endcase
                end else begin
                    case(stride_segment_counter[0])
                        1'b0: begin we_C = 1'b1; din_C = in0; we_D = 1'b1; din_D = in3; end
                        1'b1: begin we_A = 1'b1; din_A = in3; we_D = 1'b1; din_D = in0; end
                    endcase
                end
            end
        end
    endgenerate

    // Main Clocked Process 
    always @(posedge clock) begin 
        if(reset) begin
            output_0 <= 0; output_1 <= 0; output_2 <= 0; output_3 <= 0;
            pipe_rdata_A <= 0; pipe_rdata_B <= 0; pipe_rdata_C <= 0; pipe_rdata_D <= 0;
            ea_addr_A <= 0; ea_addr_B <= 0; ea_addr_C <= 0; ea_addr_D <= 0;
            pipe1_op <= 0; pipe2_op <= 0;
        end else begin
            
            // --- THE PERFECT BRAM WRITE TEMPLATE ---
            // Because the complex MUX logic is outside, Vivado maps these instantly.
            if (we_A) mem_A[write_addr] <= din_A;
            if (we_B) mem_B[write_addr] <= din_B;
            if (we_C) mem_C[write_addr] <= din_C;
            if (we_D) mem_D[write_addr] <= din_D;

            // --- STAGE 1: Calculate Read Address ---
            pipe1_op <= butterfly_op_counter; 

            if(DEPTH >= 4) begin
                if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                    case (butterfly_op_counter[muxing_num_bits+1:muxing_num_bits])
                        2'b00: begin ea_addr_A <= next_addr0; ea_addr_B <= next_addr1; ea_addr_C <= next_addr2; ea_addr_D <= next_addr3; end
                        2'b01: begin ea_addr_A <= next_addr3; ea_addr_B <= next_addr0; ea_addr_C <= next_addr1; ea_addr_D <= next_addr2; end
                        2'b10: begin ea_addr_A <= next_addr2; ea_addr_B <= next_addr3; ea_addr_C <= next_addr0; ea_addr_D <= next_addr1; end
                        2'b11: begin ea_addr_A <= next_addr1; ea_addr_B <= next_addr2; ea_addr_C <= next_addr3; ea_addr_D <= next_addr0; end
                    endcase
                end else begin
                    ea_addr_A <= read_addr; ea_addr_B <= read_addr; ea_addr_C <= read_addr; ea_addr_D <= read_addr;
                end
            end else begin
                if(butterfly_op_counter[stage_num_bits] == 1'b1) begin
                    case (butterfly_op_counter[0])
                        1'b0: begin ea_addr_A <= next_addr0; ea_addr_B <= next_addr1; ea_addr_C <= next_addr0; ea_addr_D <= next_addr1; end
                        1'b1: begin ea_addr_A <= next_addr1; ea_addr_B <= next_addr0; ea_addr_C <= next_addr1; ea_addr_D <= next_addr0; end
                    endcase
                end else begin
                    ea_addr_A <= read_addr; ea_addr_B <= read_addr; ea_addr_C <= read_addr; ea_addr_D <= read_addr;
                end
            end

            // --- STAGE 2: Memory Read to Pipe ---
            pipe2_op <= pipe1_op; 
            pipe_rdata_A <= mem_A[ea_addr_A];
            pipe_rdata_B <= mem_B[ea_addr_B];
            pipe_rdata_C <= mem_C[ea_addr_C];
            pipe_rdata_D <= mem_D[ea_addr_D];

            // --- STAGE 3: Output Muxing ---
            if(DEPTH >= 4) begin
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
                if(pipe2_op[stage_num_bits] == 1'b0) begin
                    case(pipe2_op[0])
                        1'b0: begin output_0 <= pipe_rdata_A; output_1 <= pipe_rdata_C; output_2 <= pipe_rdata_B; output_3 <= pipe_rdata_D; end
                        1'b1: begin output_0 <= pipe_rdata_B; output_1 <= pipe_rdata_D; output_2 <= pipe_rdata_C; output_3 <= pipe_rdata_A; end
                    endcase
                end else begin
                    case(pipe2_op[0])
                        1'b0: begin output_0 <= pipe_rdata_A; output_1 <= pipe_rdata_B; output_2 <= pipe_rdata_C; output_3 <= pipe_rdata_D; end
                        1'b1: begin output_0 <= pipe_rdata_B; output_1 <= pipe_rdata_C; output_2 <= pipe_rdata_D; output_3 <= pipe_rdata_A; end
                    endcase
                end
            end
        end 
    end

    // Split data into real and imaginary parts
    assign output_real_0 = output_0[2*WIDTH-1:WIDTH]; assign output_imag_0 = output_0[WIDTH-1:0];
    assign output_real_1 = output_1[2*WIDTH-1:WIDTH]; assign output_imag_1 = output_1[WIDTH-1:0];
    assign output_real_2 = output_2[2*WIDTH-1:WIDTH]; assign output_imag_2 = output_2[WIDTH-1:0];
    assign output_real_3 = output_3[2*WIDTH-1:WIDTH]; assign output_imag_3 = output_3[WIDTH-1:0];

endmodule