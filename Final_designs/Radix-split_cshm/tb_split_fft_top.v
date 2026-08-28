`timescale 1ps/1ps

module tb_split_fft_top();

    parameter WIDTH = 16;
    parameter Tw_WIDTH = 8;
    parameter Num_of_samples = 256;
    parameter MAX_FILE_SAMPLES = 100000; // Adjust if your file has more than 4096 lines
    parameter output_pipeline_bram = 1;  // Set to 1 to enable output pipelining
    parameter input_pipeline_bram = 1;   // Set to 1 to enable input pipelining
    parameter KEY_WIDTH = 14;                 // Set to 14 for CSHM keys
    parameter Bram = 0;                  // Set to 1 to enable BRAM

    // Dynamic bit-width calculation for bit reversal
    localparam INDEX_BITS = $clog2(Num_of_samples);

    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;

    // Array size doubled to hold 2 windows for ping-pong output
    reg [WIDTH-1:0] output_real [0:(2*Num_of_samples) - 1];
    reg [WIDTH-1:0] output_imag [0:(2*Num_of_samples) - 1];

    // Arrays to hold the file data loaded at time 0
    reg signed [WIDTH-1:0] file_real_data [0:MAX_FILE_SAMPLES - 1];
    reg signed [WIDTH-1:0] file_imag_data [0:MAX_FILE_SAMPLES - 1];
    integer total_samples_read = 0;
    integer output_count = 0;

    split_fft_top #(
        .WIDTH(WIDTH),
        .Tw_WIDTH(Tw_WIDTH),
        .N(Num_of_samples),
        .input_pipeline_bram(input_pipeline_bram),
        .output_pipeline_bram(output_pipeline_bram),
        .KEY_WIDTH(KEY_WIDTH),
        .Bram(Bram)
    ) dut (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .input_real_0(input_real_0), .input_real_1(input_real_1), .input_real_2(input_real_2), .input_real_3(input_real_3),
        .input_imag_0(input_imag_0), .input_imag_1(input_imag_1), .input_imag_2(input_imag_2), .input_imag_3(input_imag_3),
        .output_en(output_en),
        .output_real_0(output_real_0), .output_real_1(output_real_1), .output_real_2(output_real_2), .output_real_3(output_real_3),
        .output_imag_0(output_imag_0), .output_imag_1(output_imag_1), .output_imag_2(output_imag_2), .output_imag_3(output_imag_3)
    );

    initial begin
        clock = 0;
        forever #5 clock = ~clock; 
    end

    // File IO variables
    integer in_file_id;
    integer out_file_id;
    integer lat_file_id;
    integer scan_count;
    integer t_i, t_r;
    integer i;

    // ---------------------------------------------------------
    // 1. Pre-load the entire input file into memory at time 0
    // ---------------------------------------------------------
    initial begin
        in_file_id = $fopen("../Data/input_data.txt", "r");
        if (in_file_id == 0) begin
            $display("ERROR: Could not open input_data.txt. Please ensure it is in the run directory.");
            $finish;
        end

        while (!$feof(in_file_id) && total_samples_read < MAX_FILE_SAMPLES) begin
            scan_count = $fscanf(in_file_id, "%d %d", t_i, t_r);
            if (scan_count == 2) begin
                file_imag_data[total_samples_read] = t_r;
                file_real_data[total_samples_read] = t_i;
                total_samples_read = total_samples_read + 1;
            end
        end
        $fclose(in_file_id);
        $display("Loaded %0d samples from input file into memory.", total_samples_read);
    end

    // ---------------------------------------------------------
    // 2. Feed data to the FFT and open Output File
    // ---------------------------------------------------------
    initial begin
        out_file_id = $fopen("../Data/fft_output.txt", "w");
        lat_file_id = $fopen("../Data/latencies.txt", "w");
        
        if (out_file_id == 0 || lat_file_id == 0) begin
            $display("ERROR: Could not create output log files.");
            $finish;
        end

        // Initialize inputs
        input_en <= 0;
        input_real_0 <= 0; input_imag_0 <= 0;
        input_real_1 <= 0; input_imag_1 <= 0;
        input_real_2 <= 0; input_imag_2 <= 0;
        input_real_3 <= 0; input_imag_3 <= 0;
        #5;
        
        reset = 1;
        #10;
        @ (posedge clock);
        reset <= 0;
        #100;
        
        input_en <= 1;
        
        for (i = 0; i < total_samples_read; i = i + 4) begin
            input_real_0 <= file_real_data[i+0]; input_imag_0 <= file_imag_data[i+0];
            input_real_1 <= file_real_data[i+1]; input_imag_1 <= file_imag_data[i+1];
            input_real_2 <= file_real_data[i+2]; input_imag_2 <= file_imag_data[i+2];
            input_real_3 <= file_real_data[i+3]; input_imag_3 <= file_imag_data[i+3];
            #10;
        end
        
        input_en <= 0;
        $display("Finished streaming data to FFT. Waiting for outputs to flush...");
        
        #(MAX_FILE_SAMPLES * 10); 
        
        $fclose(out_file_id);
        $fclose(lat_file_id);
        $display("Simulation complete. Outputs saved.");
        $finish;
    end

    initial begin
        $dumpfile("tb_split_fft_top.vcd");
        $dumpvars(0, tb_split_fft_top);
    end

    // ---------------------------------------------------------
    // 3. Latency & Active Time Metric Tracking 
    // ---------------------------------------------------------
    reg input_en_d = 0;
    reg output_en_d = 0;
    reg counting_latency = 0;
    integer t_latency = 0;
    reg counting_active = 0;
    integer t_active = 0;

    always @(posedge clock) begin
        input_en_d  <= input_en;
        output_en_d <= output_en;

        // Metric 1: Latency (Input Fall to Output Rise)
        if (!input_en_d && input_en) begin
            counting_latency <= 1;
            t_latency <= 1;
        end
        else if (counting_latency && !output_en) begin
            t_latency <= t_latency + 1;
        end

        if (!output_en_d && output_en) begin
            counting_latency <= 0;
            $fdisplay(lat_file_id, "%0d", t_latency);
        end

        // Metric 2: Total Active Time (Input Rise to Output Fall)
        if (!input_en_d && input_en) begin
            counting_active <= 1;
            t_active <= 1;
        end
        else if (counting_active) begin
            t_active <= t_active + 1;
        end

        if (output_en_d && !output_en) begin
            counting_active <= 0;
            $fdisplay(lat_file_id, "%0d", t_active);
        end
    end

    // ---------------------------------------------------------
    // 4. Ping-Pong Output Capturing & Dynamic Bit Reversal
    // ---------------------------------------------------------
    reg [31:0] normal_idx;
    reg [31:0] rev_idx;
    integer k;
    reg frame_ready = 0;
    integer window_count = 0;
    integer write_offset = 0;
    integer print_offset = 0;

    // Generalized Bit Reversal Function for ANY power of 2
    function [31:0] bit_reverse;
        input [31:0] val;
        input integer bits;
        integer b;
        begin
            bit_reverse = 0;
            for (b = 0; b < bits; b = b + 1) begin
                bit_reverse[bits - 1 - b] = val[b];
            end
        end
    endfunction

    always @(posedge clock) begin
        if (reset) begin
            output_count <= 0;
            write_offset <= 0;
            frame_ready <= 0;
        end else begin
            frame_ready <= 0; 
            
            if (output_en) begin
                output_real[write_offset + output_count + 0] <= output_real_0;
                output_imag[write_offset + output_count + 0] <= output_imag_0;
                output_real[write_offset + output_count + 1] <= output_real_1;
                output_imag[write_offset + output_count + 1] <= output_imag_1;
                output_real[write_offset + output_count + 2] <= output_real_2;
                output_imag[write_offset + output_count + 2] <= output_imag_2;
                output_real[write_offset + output_count + 3] <= output_real_3;
                output_imag[write_offset + output_count + 3] <= output_imag_3;
                
                if (output_count == (Num_of_samples - 4)) begin
                    output_count <= 0;
                    print_offset <= write_offset;
                    write_offset <= (write_offset == 0) ? Num_of_samples : 0;
                    frame_ready <= 1; 
                end else begin
                    output_count <= output_count + 4;
                end
            end
        end
    end

    always @(posedge clock) begin
        if (frame_ready) begin
            window_count = window_count + 1;
            for (k = 0; k < Num_of_samples; k = k + 1) begin
                normal_idx = k;
                
                // Dynamically reverse the bits using localparam INDEX_BITS
                rev_idx = bit_reverse(normal_idx, INDEX_BITS);
                
                $fdisplay(out_file_id, "%d %d", 
                          $signed(output_real[print_offset + rev_idx]), 
                          $signed(output_imag[print_offset + rev_idx]));
            end
        end
    end

endmodule