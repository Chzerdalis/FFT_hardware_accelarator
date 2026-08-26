`timescale 1ns / 1ps

`ifdef NO_BRAM
    `define BRAM_ATTR (* ram_style = "distributed" *)
`else
    `define BRAM_ATTR (* ram_style = "block" *)
`endif

module memory #(
    parameter WIDTH = 16,
    parameter DEPTH = 1024,
    parameter stage_num_bits = 9,
    parameter output_pipeline_bram = 0,
    parameter Bram = 1
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

    // Split memory into 4 different banks so each one has 2 ports
    // (1 read, 1 write). This helps the tools use BRAMs when the arrays
    // are large enough.

    `BRAM_ATTR reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
    `BRAM_ATTR reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
    `BRAM_ATTR reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
    `BRAM_ATTR reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];

    generate
        if (Bram) begin : gen_bram
            (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
            (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
            (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
            (* ram_style = "block" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];
        end else begin : gen_reg
            (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_A [0:2*DEPTH-1];
            (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_B [0:2*DEPTH-1];
            (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_C [0:2*DEPTH-1];
            (* ram_style = "distributed" *) reg [2*WIDTH-1:0] mem_D [0:2*DEPTH-1];
        end
    endgenerate

    wire [inter_offset_size:0] offset;

    // Final Output Registers
    reg [2*WIDTH-1:0] output_0, output_1, output_2, output_3;

    reg [inter_offset_size+1:0] ea_addr_A, ea_addr_B, ea_addr_C, ea_addr_D;

    wire [inter_offset_size+1:0] position_count;

    // Useful to calculate the read address for stages > 2.
    // For the 1st stage there is no memory.
    // For the 2nd stage position_count is not needed for the read address.
    generate
        if (DEPTH > 4) begin : gen_pos_count
            assign position_count = butterfly_op_counter[stage_num_bits-2:0];
        end else begin : gen_no_pos_count
            assign position_count = 0;
        end
    endgenerate

    // Read address calculation
    wire [inter_offset_size+1:0] next_addr0 = offset + position_count;
    wire [inter_offset_size+1:0] next_addr1 = offset + vertical_offset_1 + position_count;
    wire [inter_offset_size+1:0] next_addr2 = offset + vertical_offset_2 + position_count;
    wire [inter_offset_size+1:0] next_addr3 = offset + vertical_offset_3 + position_count;

    // Registers holding data out of memory before output muxing
    reg [2*WIDTH-1:0] pipe_rdata_A, pipe_rdata_B, pipe_rdata_C, pipe_rdata_D;

    // Registers delaying the select signal for output muxing
    reg [stage_num_bits:0] pipe1_op, pipe2_op;

    // Offset to move to the second half of the memory while new data is
    // written into the first half. Needed because the read and write
    // patterns differ: with a single half, new data would overwrite old
    // data that has not been read yet.
    assign offset = (mem_counter_read[stage_num_bits+1] == 0) ?
                    {(inter_offset_size+1){1'b0}} :
                    {1'b1, {(inter_offset_size){1'b0}}};

    // -----------------------------------------------------------------
    // Common pipeline: writes, address calculation, and BRAM read.
    // Identical for both variants.
    // -----------------------------------------------------------------
    always @(posedge clock) begin
        // -------------------------------------------------------
        // Write input data into memory depending on the stride
        // segment we are currently in.
        // -------------------------------------------------------
        case (stride_segment_counter[stage_num_bits:stage_num_bits-1])
            2'b00: begin
                mem_A[mem_counter] <= {input_real_0, input_imag_0};
                mem_B[mem_counter] <= {input_real_1, input_imag_1};
                mem_C[mem_counter] <= {input_real_2, input_imag_2};
                mem_D[mem_counter] <= {input_real_3, input_imag_3};
            end
            2'b01: begin
                mem_A[mem_counter] <= {input_real_3, input_imag_3};
                mem_B[mem_counter] <= {input_real_0, input_imag_0};
                mem_C[mem_counter] <= {input_real_1, input_imag_1};
                mem_D[mem_counter] <= {input_real_2, input_imag_2};
            end
            2'b10: begin
                mem_A[mem_counter] <= {input_real_2, input_imag_2};
                mem_B[mem_counter] <= {input_real_3, input_imag_3};
                mem_C[mem_counter] <= {input_real_0, input_imag_0};
                mem_D[mem_counter] <= {input_real_1, input_imag_1};
            end
            2'b11: begin
                mem_A[mem_counter] <= {input_real_1, input_imag_1};
                mem_B[mem_counter] <= {input_real_2, input_imag_2};
                mem_C[mem_counter] <= {input_real_3, input_imag_3};
                mem_D[mem_counter] <= {input_real_0, input_imag_0};
            end
        endcase

        // -------------------------------------------------------
        // Read stage 1: calculate the effective address before the
        // memory read, to ease the job of the synthesis tools and
        // maximize frequency.
        // -------------------------------------------------------
        pipe1_op <= butterfly_op_counter; // Register the read muxing signal

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

        // -------------------------------------------------------
        // Read stage 2: read from memory into the pipe registers
        // -------------------------------------------------------
        pipe2_op <= pipe1_op; // Register the read muxing signal

        pipe_rdata_A <= mem_A[ea_addr_A];
        pipe_rdata_B <= mem_B[ea_addr_B];
        pipe_rdata_C <= mem_C[ea_addr_C];
        pipe_rdata_D <= mem_D[ea_addr_D];
    end

    // -----------------------------------------------------------------
    // Output stage: with or without the extra BRAM output pipeline
    // -----------------------------------------------------------------
    generate
        if (output_pipeline_bram) begin : gen_pipelined_out

            // Extra register stage after the BRAM read-data registers
            reg [2*WIDTH-1:0] mux_data_A, mux_data_B, mux_data_C, mux_data_D;
            reg [stage_num_bits:0] pipe3_op;

            always @(posedge clock) begin
                // ---------------------------------------------------
                // Read stage 3: extra register after the BRAM read.
                // ---------------------------------------------------
                pipe3_op <= pipe2_op;

                mux_data_A <= pipe_rdata_A;
                mux_data_B <= pipe_rdata_B;
                mux_data_C <= pipe_rdata_C;
                mux_data_D <= pipe_rdata_D;

                // ---------------------------------------------------
                // Read stage 4: output rotation mux, fed from the
                // mux_data_* registers rather than directly from the
                // BRAM read registers.
                // ---------------------------------------------------
                case (pipe3_op[stage_num_bits:stage_num_bits-1])
                    2'b00: begin
                        output_0 <= mux_data_A;
                        output_1 <= mux_data_B;
                        output_2 <= mux_data_C;
                        output_3 <= mux_data_D;
                    end
                    2'b01: begin
                        output_0 <= mux_data_B;
                        output_1 <= mux_data_C;
                        output_2 <= mux_data_D;
                        output_3 <= mux_data_A;
                    end
                    2'b10: begin
                        output_0 <= mux_data_C;
                        output_1 <= mux_data_D;
                        output_2 <= mux_data_A;
                        output_3 <= mux_data_B;
                    end
                    2'b11: begin
                        output_0 <= mux_data_D;
                        output_1 <= mux_data_A;
                        output_2 <= mux_data_B;
                        output_3 <= mux_data_C;
                    end
                endcase
            end

        end else begin : gen_direct_out

            always @(posedge clock) begin
                // ---------------------------------------------------
                // Read stage 3: output muxing straight from the BRAM
                // read registers.
                // ---------------------------------------------------
                case (pipe2_op[stage_num_bits:stage_num_bits-1])
                    2'b00: begin
                        output_0 <= pipe_rdata_A;
                        output_1 <= pipe_rdata_B;
                        output_2 <= pipe_rdata_C;
                        output_3 <= pipe_rdata_D;
                    end
                    2'b01: begin
                        output_0 <= pipe_rdata_B;
                        output_1 <= pipe_rdata_C;
                        output_2 <= pipe_rdata_D;
                        output_3 <= pipe_rdata_A;
                    end
                    2'b10: begin
                        output_0 <= pipe_rdata_C;
                        output_1 <= pipe_rdata_D;
                        output_2 <= pipe_rdata_A;
                        output_3 <= pipe_rdata_B;
                    end
                    2'b11: begin
                        output_0 <= pipe_rdata_D;
                        output_1 <= pipe_rdata_A;
                        output_2 <= pipe_rdata_B;
                        output_3 <= pipe_rdata_C;
                    end
                endcase
            end

        end
    endgenerate

    // Split data into real and imaginary parts
    assign output_real_0 = output_0[2*WIDTH-1:WIDTH];
    assign output_imag_0 = output_0[WIDTH-1:0];
    assign output_real_1 = output_1[2*WIDTH-1:WIDTH];
    assign output_imag_1 = output_1[WIDTH-1:0];
    assign output_real_2 = output_2[2*WIDTH-1:WIDTH];
    assign output_imag_2 = output_2[WIDTH-1:0];
    assign output_real_3 = output_3[2*WIDTH-1:WIDTH];
    assign output_imag_3 = output_3[WIDTH-1:0];

endmodule