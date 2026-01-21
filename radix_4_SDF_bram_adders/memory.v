// `timescale 1ns / 1ps


// module memory #(
//     parameter WIDTH = 32,
//     parameter DEPTH = 16, 
//     parameter stage_num_bits = 1
// )(
//     input clock,
//     input reset,
//     input [stage_num_bits:0] stride_segment_counter,
//     input [stage_num_bits:0] butterfly_op_counter,
//     input [stage_num_bits+1:0] mem_counter,
//     input [stage_num_bits+1:0] mem_counter_read,
//     input [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3,
//     input [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3,
//     output [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3,
//     output [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3
// );
//     localparam inter_offset_size = $clog2(DEPTH);
//     localparam intra_offset_size = inter_offset_size - 2;
//     localparam vertical_offset_1 = 1 << intra_offset_size;
//     localparam vertical_offset_2 = 2 << intra_offset_size;
//     localparam vertical_offset_3 = 3 << intra_offset_size;
    

//     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
//     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
//     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
//     (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

//     wire [inter_offset_size:0] offset;

//     reg [inter_offset_size+1:0] address_0, address_1, address_2, address_3;

//     reg [2*WIDTH-1:0] output_0, output_1, output_2, output_3;


//     if(DEPTH > 4) begin : gen_memory_module
//         always@(posedge clock) begin 
//             if(reset) begin
//                 output_0 <= 0;
//                 output_1 <= 0;
//                 output_2 <= 0;
//                 output_3 <= 0;
//                 address_0 <= 0;
//                 address_1 <= 0;
//                 address_2 <= 0;
//                 address_3 <= 0;
//             end else begin
//                 if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b00) begin
//                     mem_A[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_B[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_C[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_D[mem_counter] <= {input_real_3, input_imag_3};
//                 end 
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b01) begin
//                     mem_A[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_B[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_C[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_D[mem_counter] <= {input_real_2, input_imag_2};
//                 end 
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b10) begin
//                     mem_A[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_B[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_C[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_D[mem_counter] <= {input_real_1, input_imag_1};
//                 end
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b11) begin
//                     mem_A[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_B[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_C[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_D[mem_counter] <= {input_real_0, input_imag_0};
//                 end

//                 if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b00) begin
//                     output_0 <= mem_A[address_0];
//                     output_1 <= mem_B[address_1];
//                     output_2 <= mem_C[address_2];
//                     output_3 <= mem_D[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b01) begin
//                     output_0 <= mem_B[address_0];
//                     output_1 <= mem_C[address_1];
//                     output_2 <= mem_D[address_2];
//                     output_3 <= mem_A[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b10) begin
//                     output_0 <= mem_C[address_0];
//                     output_1 <= mem_D[address_1];
//                     output_2 <= mem_A[address_2];
//                     output_3 <= mem_B[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b11) begin
//                     output_0 <= mem_D[address_0];
//                     output_1 <= mem_A[address_1];
//                     output_2 <= mem_B[address_2];
//                     output_3 <= mem_C[address_3];
//                 end
//             end

//             address_0 <= offset + butterfly_op_counter[stage_num_bits-2:0];
//             address_1 <= offset + vertical_offset_1 + butterfly_op_counter[stage_num_bits-2:0];
//             address_2 <= offset + vertical_offset_2 + butterfly_op_counter[stage_num_bits-2:0];
//             address_3 <= offset + vertical_offset_3 + butterfly_op_counter[stage_num_bits-2:0];

//         end
//     end else begin : gen_memory_module_small_depth
//         always@(posedge clock) begin 
//             if(reset) begin
//                 output_0 <= 0;
//                 output_1 <= 0;
//                 output_2 <= 0;
//                 output_3 <= 0;
//             end else begin
//                 if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b00) begin
//                     mem_A[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_B[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_C[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_D[mem_counter] <= {input_real_3, input_imag_3};
//                 end 
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b01) begin
//                     mem_A[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_B[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_C[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_D[mem_counter] <= {input_real_2, input_imag_2};
//                 end 
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b10) begin
//                     mem_A[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_B[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_C[mem_counter] <= {input_real_0, input_imag_0};
//                     mem_D[mem_counter] <= {input_real_1, input_imag_1};
//                 end
//                 else if(stride_segment_counter[stage_num_bits:stage_num_bits-1] == 2'b11) begin
//                     mem_A[mem_counter] <= {input_real_1, input_imag_1};
//                     mem_B[mem_counter] <= {input_real_2, input_imag_2};
//                     mem_C[mem_counter] <= {input_real_3, input_imag_3};
//                     mem_D[mem_counter] <= {input_real_0, input_imag_0};
//                 end

//                 if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b00) begin
//                     output_0 <= mem_A[address_0];
//                     output_1 <= mem_B[address_1];
//                     output_2 <= mem_C[address_2];
//                     output_3 <= mem_D[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b01) begin
//                     output_0 <= mem_B[address_0];
//                     output_1 <= mem_C[address_1];
//                     output_2 <= mem_D[address_2];
//                     output_3 <= mem_A[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b10) begin
//                     output_0 <= mem_C[address_0];
//                     output_1 <= mem_D[address_1];
//                     output_2 <= mem_A[address_2];
//                     output_3 <= mem_B[address_3];
//                 end
//                 else if(butterfly_op_counter[stage_num_bits:stage_num_bits-1] == 2'b11) begin
//                     output_0 <= mem_D[address_0];
//                     output_1 <= mem_A[address_1];
//                     output_2 <= mem_B[address_2];
//                     output_3 <= mem_C[address_3];
//                 end
//             end 
//             address_0 <= offset;
//             address_1 <= offset + vertical_offset_1;
//             address_2 <= offset + vertical_offset_2;
//             address_3 <= offset + vertical_offset_3;
//         end
//     end

//     assign output_real_0 = output_0[2*WIDTH-1:WIDTH];
//     assign output_imag_0 = output_0[WIDTH-1:0];
//     assign output_real_1 = output_1[2*WIDTH-1:WIDTH];
//     assign output_imag_1 = output_1[WIDTH-1:0];
//     assign output_real_2 = output_2[2*WIDTH-1:WIDTH];
//     assign output_imag_2 = output_2[WIDTH-1:0];
//     assign output_real_3 = output_3[2*WIDTH-1:WIDTH];
//     assign output_imag_3 = output_3[WIDTH-1:0];

//     assign offset = (mem_counter_read[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};

// endmodule

`timescale 1ns / 1ps

module memory #(
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

    // =========================================================
    // Memory Declaration (Block RAM inferred via attribute)
    // =========================================================
    // (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    // (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    // (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    // (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    wire [inter_offset_size:0] offset;
    
    // Final Output Registers
    reg [2*WIDTH-1:0] output_0, output_1, output_2, output_3;

    reg [inter_offset_size+1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;

    wire [inter_offset_size+1:0] position_count;
    
    generate
        if (DEPTH > 4) begin
            assign position_count = butterfly_op_counter[stage_num_bits-2:0];
        end else begin
            assign position_count = 0;
        end
    endgenerate

    wire [inter_offset_size+1:0] next_addr0 = offset + position_count;
    wire [inter_offset_size+1:0] next_addr1 = offset + vertical_offset_1 + position_count;
    wire [inter_offset_size+1:0] next_addr2 = offset + vertical_offset_2 + position_count;
    wire [inter_offset_size+1:0] next_addr3 = offset + vertical_offset_3 + position_count;

    // --- Pipeline Stage 2 Signals: Read Data ---
    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;

    // --- Pipeline Control: Delay the Op Counter to match Data Latency ---
    reg [stage_num_bits:0] pipe1_op, pipe2_op; 

    always@(posedge clock) begin 
        if(reset) begin
            output_0 <= 0; output_1 <= 0; output_2 <= 0; output_3 <= 0;
            pipe_rdata_A <= 0; pipe_rdata_B <= 0; pipe_rdata_C <= 0; pipe_rdata_D <= 0;
            ea_addr_A <= 0; ea_addr_B <= 0; ea_addr_C <= 0; ea_addr_D <= 0;
            pipe1_op <= 0; pipe2_op <= 0;
        end else begin
            // -----------------------------------------------------
            // WRITE OPERATION (Standard)
            // -----------------------------------------------------
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

            // -----------------------------------------------------
            // READ STAGE 1: Address Scheduling & Pre-Muxing
            // -----------------------------------------------------
            pipe1_op <= butterfly_op_counter;

            // Determine which address each memory needs to read based on rotation
            case (butterfly_op_counter[stage_num_bits:stage_num_bits-1])
                2'b00: ea_addr_A <= next_addr0; 
                2'b01: ea_addr_A <= next_addr3;
                2'b10: ea_addr_A <= next_addr2;
                2'b11: ea_addr_A <= next_addr1;
            endcase

            case (butterfly_op_counter[stage_num_bits:stage_num_bits-1])
                2'b00: ea_addr_B <= next_addr1;
                2'b01: ea_addr_B <= next_addr0;
                2'b10: ea_addr_B <= next_addr3;
                2'b11: ea_addr_B <= next_addr2;
            endcase

            case (butterfly_op_counter[stage_num_bits:stage_num_bits-1])
                2'b00: ea_addr_C <= next_addr2;
                2'b01: ea_addr_C <= next_addr1;
                2'b10: ea_addr_C <= next_addr0;
                2'b11: ea_addr_C <= next_addr3;
            endcase

            case (butterfly_op_counter[stage_num_bits:stage_num_bits-1])
                2'b00: ea_addr_D <= next_addr3;
                2'b01: ea_addr_D <= next_addr2;
                2'b10: ea_addr_D <= next_addr1;
                2'b11: ea_addr_D <= next_addr0;
            endcase

            // -----------------------------------------------------
            // READ STAGE 2: Clean Memory Read
            // -----------------------------------------------------
            pipe2_op <= pipe1_op; // Propagate control signal
            
            pipe_rdata_A <= mem_A[ea_addr_A];
            pipe_rdata_B <= mem_B[ea_addr_B];
            pipe_rdata_C <= mem_C[ea_addr_C];
            pipe_rdata_D <= mem_D[ea_addr_D];

            // -----------------------------------------------------
            // READ STAGE 3: Data Alignment (Output Mux)
            // -----------------------------------------------------
            if(pipe2_op[stage_num_bits:stage_num_bits-1] == 2'b00) begin
                output_0 <= pipe_rdata_A;
                output_1 <= pipe_rdata_B;
                output_2 <= pipe_rdata_C;
                output_3 <= pipe_rdata_D;
            end
            else if(pipe2_op[stage_num_bits:stage_num_bits-1] == 2'b01) begin
                output_0 <= pipe_rdata_B;
                output_1 <= pipe_rdata_C;
                output_2 <= pipe_rdata_D;
                output_3 <= pipe_rdata_A;
            end
            else if(pipe2_op[stage_num_bits:stage_num_bits-1] == 2'b10) begin
                output_0 <= pipe_rdata_C;
                output_1 <= pipe_rdata_D;
                output_2 <= pipe_rdata_A;
                output_3 <= pipe_rdata_B;
            end
            else if(pipe2_op[stage_num_bits:stage_num_bits-1] == 2'b11) begin
                output_0 <= pipe_rdata_D;
                output_1 <= pipe_rdata_A;
                output_2 <= pipe_rdata_B;
                output_3 <= pipe_rdata_C;
            end
        end 
    end

    assign output_real_0 = output_0[2*WIDTH-1:WIDTH];
    assign output_imag_0 = output_0[WIDTH-1:0];
    assign output_real_1 = output_1[2*WIDTH-1:WIDTH];
    assign output_imag_1 = output_1[WIDTH-1:0];
    assign output_real_2 = output_2[2*WIDTH-1:WIDTH];
    assign output_imag_2 = output_2[WIDTH-1:0];
    assign output_real_3 = output_3[2*WIDTH-1:WIDTH];
    assign output_imag_3 = output_3[WIDTH-1:0];

    assign offset = (mem_counter_read[stage_num_bits+1] == 0) ? {(inter_offset_size+1){1'b0}} : {1'b1, {(inter_offset_size){1'b0}}};

endmodule