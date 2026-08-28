`timescale 1ns / 1ps

module tb_memory;

    // --- Parameter Overrides ---
    parameter WIDTH = 16;             // Reduced width for clean hex data tracing
    parameter DEPTH = 2;             // Set to 4 to match stage_num_bits = 1 sizing
    parameter stage_num_bits = 1;      //Determined by the num of samples

    // --- Testbench Signals ---
    reg clock;
    reg reset;
    reg [stage_num_bits:0] stride_segment_counter;
    reg [stage_num_bits:0] butterfly_op_counter;
    reg [stage_num_bits+1:0] mem_counter;
    reg [stage_num_bits+1:0] mem_counter_read;
    
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;

    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;

    wire [WIDTH-1:0] output_real_0_f, output_real_1_f, output_real_2_f, output_real_3_f;
    wire [WIDTH-1:0] output_imag_0_f, output_imag_1_f, output_imag_2_f, output_imag_3_f;

    // --- Unit Under Test (UUT) Instantiation ---
    memory_second_stage #(
        .WIDTH(WIDTH),
        .DEPTH(DEPTH),
        .stage_num_bits(stage_num_bits)
    ) uut (
        .clock(clock),
        .reset(reset),
        .stride_segment_counter(stride_segment_counter),
        .butterfly_op_counter(butterfly_op_counter),
        .mem_counter(mem_counter),
        .mem_counter_read(mem_counter_read),
        .input_real_0(input_real_0), .input_real_1(input_real_1), .input_real_2(input_real_2), .input_real_3(input_real_3),
        .input_imag_0(input_imag_0), .input_imag_1(input_imag_1), .input_imag_2(input_imag_2), .input_imag_3(input_imag_3),
        .output_real_0(output_real_0), .output_real_1(output_real_1), .output_real_2(output_real_2), .output_real_3(output_real_3),
        .output_imag_0(output_imag_0), .output_imag_1(output_imag_1), .output_imag_2(output_imag_2), .output_imag_3(output_imag_3)
    );

    memory_second_stage_1 #(
        .WIDTH(WIDTH),
        .DEPTH(DEPTH),
        .stage_num_bits(stage_num_bits)
    ) uut_2 (
        .clock(clock),
        .reset(reset),
        .stride_segment_counter(stride_segment_counter),
        .butterfly_op_counter(butterfly_op_counter),
        .mem_counter(mem_counter),
        .mem_counter_read(mem_counter_read),
        .input_real_0(input_real_0), .input_real_1(input_real_1), .input_real_2(input_real_2), .input_real_3(input_real_3),
        .input_imag_0(input_imag_0), .input_imag_1(input_imag_1), .input_imag_2(input_imag_2), .input_imag_3(input_imag_3),
        .output_real_0(output_real_0_f), .output_real_1(output_real_1_f), .output_real_2(output_real_2_f), .output_real_3(output_real_3_f),
        .output_imag_0(output_imag_0_f), .output_imag_1(output_imag_1_f), .output_imag_2(output_imag_2_f), .output_imag_3(output_imag_3_f)
    );

    // --- Clock Generator (100MHz / 10ns period) ---
    always #5 clock = ~clock;

    // --- Loop Variable ---
    integer i, x = 0;

    // --- Stimulus Setup ---
    initial begin
        // Initialize all inputs
        clock = 1;
        reset = 1;
        stride_segment_counter = 0;
        butterfly_op_counter = 0;
        mem_counter = 0;
        mem_counter_read = 0;
        input_real_0 = 0; input_real_1 = 0; input_real_2 = 0; input_real_3 = 0;
        input_imag_0 = 0; input_imag_1 = 0; input_imag_2 = 0; input_imag_3 = 0;

        // Release Reset
        #20;
        reset = 0;
        #10;

        // =================================================================
        // PHASE 1: Write Routine (Stride Segment 2'b00)
        // =================================================================
        $display("[TB INFO] Starting Memory Write Phase...");
        stride_segment_counter <= 2'b00; 
        
        for (i = 0; i < 4*DEPTH; i = i + 1) begin
            // Generate easily trackable data: Real=0x1X, 0x2X... Imag=butterfly_op_counter0xAX, 0xBX...
            input_real_0 <= i*4+0;  input_imag_0 <= i*4+0;
            input_real_1 <= i*4+1;  input_imag_1 <= i*4+1;
            input_real_2 <= i*4+2;  input_imag_2 <= i*4+2;
            input_real_3 <= i*4+3;  input_imag_3 <= i*4+3;
            #10;
            stride_segment_counter <= stride_segment_counter + 1; // Increment to test different segment patterns
            if(stride_segment_counter >= 1'b1 || x == 1) begin
                butterfly_op_counter <= butterfly_op_counter + 1; // Reset memory counter at the end of each segment
                mem_counter_read <= mem_counter_read + 1; // Increment read counter to test different read patterns
                x = 1;
            end
            mem_counter <= mem_counter + 1; // Increment memory counter for next write
        end

        // Clear inputs after writing
        input_real_0 <= 0; input_imag_0 <= 0;
        input_real_1 <= 1; input_imag_1 <= 1;
        input_real_2 <= 2; input_imag_2 <= 2;
        input_real_3 <= 3; input_imag_3 <= 3;
        #10;

        // =================================================================
        // PHASE 2: Read Pipelined Routine
        // =================================================================
        $display("[TB INFO] Starting Memory Read Phase...");

        for (i = 0; i < 4*DEPTH; i = i + 1) begin
            #10;
            butterfly_op_counter <= butterfly_op_counter + 1; // Increment to test different read patterns
            mem_counter_read <= mem_counter_read + 1; // Increment to read next address
        end
        
        // Flush pipeline (The design has a 3-cycle read latency)
        butterfly_op_counter <= 0;
        #30;

        $display("[TB INFO] Simulation Complete.");
        $finish;
    end

    // --- Output Monitor ---
    initial begin
        $monitor("Reset=%b | Buf_Op=%b | Out0=(R:%d,I:%d) | Out1=(R:%d,I:%d) | Out2=(R:%d,I:%d) | Out3=(R:%d,I:%d)",
                 reset, butterfly_op_counter, 
                 output_real_0, output_imag_0, 
                 output_real_1, output_imag_1, 
                 output_real_2, output_imag_2, 
                 output_real_3, output_imag_3);

        $monitor("Reset=%b | Buf_Op=%b | Out0_f=(R:%d,I:%d) | Out1_f=(R:%d,I:%d) | Out2_f=(R:%d,I:%d) | Out3_f=(R:%d,I:%d)",
                 reset, butterfly_op_counter, 
                 output_real_0_f, output_imag_0_f, 
                 output_real_1_f, output_imag_1_f, 
                 output_real_2_f, output_imag_2_f, 
                 output_real_3_f, output_imag_3_f);
    end

    always @(posedge clock) begin
        if(output_real_0 == output_real_0_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 0");
        end
        if(output_real_1 == output_real_1_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 1");
        end
        if(output_real_2 == output_real_2_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 2");
        end
        if(output_real_3 == output_real_3_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 3");
        end
        if(output_imag_0 == output_imag_0_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 4");
        end
        if(output_imag_1 == output_imag_1_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 5");
        end
        if(output_imag_2 == output_imag_2_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 6");
        end
        if(output_imag_3 == output_imag_3_f) begin
            $display("Success");
        end else begin
            $display("FAIL: Time=%0t | 7");
        end
    end

    // --- Waveform Generation and Memory Dumping ---
    integer idx; // Loop variable for tracking memory array indices

    initial begin
        // Specify the name of the VCD file
        $dumpfile("memory_simulation.vcd");
        
        // Dump all standard scalar/vector signals in the testbench scope
        $dumpvars(0, tb_memory);
        
        // Explicitly loop through and dump every element of the 2D arrays
        // Since your memory size is [0:2*DEPTH-1], we loop up to (2*DEPTH)
        for (idx = 0; idx < (2 * DEPTH); idx = idx + 1) begin
            $dumpvars(0, uut.mem_A[idx]);
            $dumpvars(0, uut.mem_B[idx]);
            $dumpvars(0, uut.mem_C[idx]);
            $dumpvars(0, uut.mem_D[idx]);
        end
    end

endmodule