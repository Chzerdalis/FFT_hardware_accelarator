`timescale 1ps/1ps

module tb_radix2_top();

    parameter WIDTH = 16;
    parameter Num_of_samples = 1024;
    parameter MAX_FILE_SAMPLES = 100000; 
    parameter SimpleMult = 0;
    parameter Fast_DSP = 0;
    parameter carry_save = 0;
    parameter Bram = 0;

    reg clock;
    reg reset;
    reg input_en;
    
    // Radix-2 only uses 2 parallel inputs/outputs
    reg [WIDTH-1:0] input_real_0, input_real_1;
    reg [WIDTH-1:0] input_imag_0, input_imag_1;
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1;
    wire [WIDTH-1:0] output_imag_0, output_imag_1;

    // Array size doubled to hold 2 windows (512 samples total) for ping-pong output
    reg [WIDTH-1:0] output_real [0:(2*Num_of_samples) - 1];
    reg [WIDTH-1:0] output_imag [0:(2*Num_of_samples) - 1];

    // Arrays to hold the file data loaded at time 0
    reg signed [WIDTH-1:0] file_real_data [0:MAX_FILE_SAMPLES - 1];
    reg signed [WIDTH-1:0] file_imag_data [0:MAX_FILE_SAMPLES - 1];
    integer total_samples_read = 0;

    integer output_count = 0;

    // Instantiate Radix-2 Top Module
    fft_top #(
        .WIDTH(WIDTH),
        .Num_of_samples(Num_of_samples),
        .SimpleMult(SimpleMult),
        .Fast_DSP(Fast_DSP),
        .carry_save(carry_save),
        .Bram(Bram)
    ) dut (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .input_real_0(input_real_0),
        .input_real_1(input_real_1),
        .input_imag_0(input_imag_0),
        .input_imag_1(input_imag_1),
        .output_en(output_en),
        .output_real_0(output_real_0),
        .output_real_1(output_real_1),
        .output_imag_0(output_imag_0),
        .output_imag_1(output_imag_1)
    );

    initial begin
        // Initialize clock
        clock = 0;
        forever #5 clock = ~clock; // 10 time units clock period
    end

    // File IO variables
    integer in_file_id;
    integer out_file_id;
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

        // Read line by line until EOF or max capacity
        while (!$feof(in_file_id) && total_samples_read < MAX_FILE_SAMPLES) begin
            // Format is: Imaginary Real
            scan_count = $fscanf(in_file_id, "%d %d", t_i, t_r);
            if (scan_count == 2) begin
                file_imag_data[total_samples_read] = t_r;
                file_real_data[total_samples_read] = t_i;
                total_samples_read = total_samples_read + 1;
            end
        end
        
        i=0;
        while(i<total_samples_read) begin
            //$display("Loaded Sample %0d: Imag = %d, Real = %d", i, file_imag_data[i], file_real_data[i]);
            i=i+1;
        end

        $fclose(in_file_id);
        //$display("Loaded %0d samples from input file into memory.", total_samples_read);
    end

    // ---------------------------------------------------------
    // 2. Feed data to the FFT and open Output File
    // ---------------------------------------------------------
    initial begin
        // Open the output text file
        out_file_id = $fopen("../Data/fft_output.txt", "w");
        if (out_file_id == 0) begin
            $display("ERROR: Could not create fft_output.txt.");
            $finish;
        end

        // Initialize inputs
        input_en <= 0;
        input_real_0 <= 0; input_imag_0 <= 0;
        input_real_1 <= 0; input_imag_1 <= 0;
        #5;
        
        // Apply reset
        reset = 1;
        #10;
        @ (posedge clock);
        reset <= 0;
        #100;
        
        // Enable input and stream from memory arrays
        input_en <= 1;
        
        // Loop through the pre-loaded arrays, 2 samples at a time
        for (i = 0; i < total_samples_read; i = i + 2) begin
            input_real_0 <= file_real_data[i+0];
            input_imag_0 <= file_imag_data[i+0];
            input_real_1 <= file_real_data[i+1];
            input_imag_1 <= file_imag_data[i+1];
            
            #10; // Wait 1 clock cycle to feed the next 2 samples
        end
        
        input_en <= 0;
        $display("Finished streaming data to FFT. Waiting for outputs to flush...");
        
        // Wait enough time for the final FFT windows to compute and flush out
        #(MAX_FILE_SAMPLES * 10);
        
        $fclose(out_file_id);
        $display("Simulation complete. Outputs saved to fft_output.txt.");
        $finish;
    end

    // initial begin
    //     $dumpfile("tb_radix2_top.vcd");
    //     $dumpvars(0, tb_radix2_top);
    // end

    // ---------------------------------------------------------
    // 3. Ping-Pong Output Capturing and File Writing
    // ---------------------------------------------------------
    
    integer k, t = 0;
    
    // Variables for ping-pong buffer index management
    reg frame_ready = 0;
    integer window_count = 0;
    integer write_offset = 0; 
    integer print_offset = 0; 

    // Capture the outputs continuously using a ping-pong offset
    always @(posedge clock) begin
        if (reset) begin
            output_count <= 0;
            write_offset <= 0;
            frame_ready <= 0;
        end else begin
            frame_ready <= 0; // Default: clear trigger
            
            if (output_en) begin
                // Write into the array using the base write_offset (2 samples at a time)
                output_real[write_offset + output_count + 0] <= output_real_0;
                output_imag[write_offset + output_count + 0] <= output_imag_0;
                
                output_real[write_offset + output_count + Num_of_samples/2] <= output_real_1;
                output_imag[write_offset + output_count + Num_of_samples/2] <= output_imag_1;
                
                // If we hit the end of the 256-sample window
                if (output_count == (Num_of_samples/2 - 1)) begin
                    output_count <= 0;
                    
                    // Lock in the current offset for the print block
                    print_offset <= write_offset;
                    
                    // Toggle the write offset between 0 and 256 for the next cycle
                    if (write_offset == 0) begin
                        write_offset <= Num_of_samples;
                    end else begin
                        write_offset <= 0;
                    end
                    
                    frame_ready <= 1; // Trigger print
                end else begin
                    output_count <= output_count + 1;
                end
            end
        end
    end

    // Print the captured array safely on POSEDGE reading from the print_offset
    always @(posedge clock) begin
        if (frame_ready) begin
            window_count = window_count + 1;
            
            for (k = 0; k < Num_of_samples; k = k + 1) begin
                // Write raw data sequentially to the text file (Real Imaginary)
                $fdisplay(out_file_id, "%d %d", 
                          $signed(output_real[print_offset + k]), 
                          $signed(output_imag[print_offset + k]));
            end
        end
    end

    integer file_id;
    
    // Variables for both counters
    reg input_en_d = 0;
    reg output_en_d = 0;
    
    reg counting_latency = 0;
    integer t_latency = 0;
    
    reg counting_active = 0;
    integer t_active = 0;

    // Open the file at the very beginning of the simulation
    initial begin
        // "w" opens it in write mode (overwrites the file each time you run the sim)
        // Use "a" (append) if you want to keep old results
        file_id = $fopen("../Data/latencies.txt", "w"); 
        
        if (file_id == 0) begin
            $display("Error: Could not open latencies file.");
            $finish;
        end
    end

    always @(posedge clock) begin
        // 1. Keep track of previous states
        input_en_d  <= input_en;
        output_en_d <= output_en;

        // =========================================================
        // METRIC 1: Latency (Input Fall to Output Rise)
        // =========================================================
        if (input_en_d && !input_en) begin
            counting_latency <= 1;
            t_latency <= 1; 
        end
        else if (counting_latency && !output_en) begin
            t_latency <= t_latency + 1;
        end

        if (!output_en_d && output_en) begin
            counting_latency <= 0;
            // Write to file instead of console
            $fdisplay(file_id, "%0d", t_latency);
        end

        // =========================================================
        // METRIC 2: Total Active Time (Input Rise to Output Fall)
        // =========================================================
        if (!input_en_d && input_en) begin
            counting_active <= 1;
            t_active <= 1; 
        end
        else if (counting_active) begin
            t_active <= t_active + 1;
        end

        if (output_en_d && !output_en) begin
            counting_active <= 0;
            // Write to file instead of console
            $fdisplay(file_id, "%0d", t_active);
        end
    end
endmodule