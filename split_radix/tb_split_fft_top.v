// module tb_split_fft_top();

//     parameter WIDTH = 16;
//     parameter Num_of_samples = 64;

//     reg clock;
//     reg reset;
//     reg input_en;
//     reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
//     reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
//     wire output_en;
//     wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
//     wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;

//     reg [WIDTH-1:0] inputs_real [0:Num_of_samples - 1];
//     reg [WIDTH-1:0] inputs_imag [0:Num_of_samples - 1];

//     // Array size doubled to hold 2 windows (128 samples total)
//     reg [WIDTH-1:0] output_real [0:(2*Num_of_samples) - 1];
//     reg [WIDTH-1:0] output_imag [0:(2*Num_of_samples) - 1];

//     integer output_count = 0;

//     split_fft_top #(
//         .WIDTH(WIDTH),
//         .N(Num_of_samples)
//     ) dut (
//         .clock(clock),
//         .reset(reset),
//         .input_en(input_en),
//         .input_real_0(input_real_0),
//         .input_real_1(input_real_1),
//         .input_real_2(input_real_2),
//         .input_real_3(input_real_3),
//         .input_imag_0(input_imag_0),
//         .input_imag_1(input_imag_1),
//         .input_imag_2(input_imag_2),
//         .input_imag_3(input_imag_3),
//         .output_en(output_en),
//         .output_real_0(output_real_0),
//         .output_real_1(output_real_1),
//         .output_real_2(output_real_2),
//         .output_real_3(output_real_3),
//         .output_imag_0(output_imag_0),
//         .output_imag_1(output_imag_1),
//         .output_imag_2(output_imag_2),
//         .output_imag_3(output_imag_3)
//     );

//     integer i;

//     initial begin
//         // Initialize clock
//         clock = 0;
//         forever #5 clock = ~clock; // 10 time units clock period
//     end

//     initial begin
//         // Initialize inputs
//         input_en = 0;
//         #5;
//         // Apply reset
//         reset = 1;
//         #10;
//         @ (posedge clock);
//         reset = 0;
//         #100;
        
//         // Enable input for FIRST window
//         input_en <= 1;
//         for (i = 0; i < Num_of_samples; i = i + 4) begin
//             input_real_0 <= 4*i+0;
//             input_imag_0 <= 4*i+0;
//             input_real_1 <= 4*i+1;
//             input_imag_1 <= 4*i+1;
//             input_real_2 <= 4*i+2;
//             input_imag_2 <= 4*i+2;
//             input_real_3 <= 4*i+3;
//             input_imag_3 <= 4*i+3;
//             #10;
//         end
        
//         // Second streaming window immediately following
//         for (i = 0; i < Num_of_samples; i = i + 4) begin
//             input_real_0 <= 8*i+0;
//             input_imag_0 <= 8*i+0;
//             input_real_1 <= 8*i+1;
//             input_imag_1 <= 8*i+1;
//             input_real_2 <= 8*i+2;
//             input_imag_2 <= 8*i+2;
//             input_real_3 <= 8*i+3;
//             input_imag_3 <= 8*i+3;
//             #10;
//         end
        
//         input_en <= 0;
//         #10000;
//         $finish;
//     end

//     initial begin
//         $dumpfile("tb_split_fft_top.vcd");
//         $dumpvars(0, tb_split_fft_top);
//     end

//     // ---------------------------------------------------------
//     // Ping-Pong Output Capturing and Bit-Reversed Printing
//     // ---------------------------------------------------------
    
//     reg [5:0] normal_idx;
//     reg [5:0] rev_idx;
//     integer k;
    
//     // Variables for ping-pong buffer index management
//     reg frame_ready = 0;
//     integer window_count = 0;
//     integer write_offset = 0; // Correction index for writing (0 or 64)
//     integer print_offset = 0; // Correction index for printing (0 or 64)

//     // 1. Capture the outputs continuously using a ping-pong offset
//     always @(posedge clock) begin
//         if (reset) begin
//             output_count <= 0;
//             write_offset <= 0;
//             frame_ready <= 0;
//         end else begin
//             frame_ready <= 0; // Default: clear trigger
            
//             if (output_en) begin
//                 // Write into the array using the base write_offset
//                 output_real[write_offset + output_count + 0] <= output_real_0;
//                 output_imag[write_offset + output_count + 0] <= output_imag_0;
                
//                 output_real[write_offset + output_count + 1] <= output_real_1;
//                 output_imag[write_offset + output_count + 1] <= output_imag_1;
                
//                 output_real[write_offset + output_count + 2] <= output_real_2;
//                 output_imag[write_offset + output_count + 2] <= output_imag_2;
                
//                 output_real[write_offset + output_count + 3] <= output_real_3;
//                 output_imag[write_offset + output_count + 3] <= output_imag_3;
                
//                 // If we hit the end of the 64-sample window
//                 if (output_count == (Num_of_samples - 4)) begin
//                     output_count <= 0;
                    
//                     // Lock in the current offset for the print block
//                     print_offset <= write_offset;
                    
//                     // Toggle the write offset between 0 and 64 for the next cycle
//                     if (write_offset == 0) begin
//                         write_offset <= Num_of_samples;
//                     end else begin
//                         write_offset <= 0;
//                     end
                    
//                     frame_ready <= 1; // Trigger print
//                 end else begin
//                     output_count <= output_count + 4;
//                 end
//             end
//         end
//     end

//     // 2. Print the captured array safely on POSEDGE reading from the print_offset
//     always @(posedge clock) begin
//         if (frame_ready) begin
//             window_count = window_count + 1;
            
//             $display("========================================");
//             $display("   BIT-REVERSED FFT OUTPUTS: WINDOW %0d ", window_count);
//             $display("   (Reading from internal offset: %0d)", print_offset);
//             $display("========================================");
            
//             for (k = 0; k < Num_of_samples; k = k + 1) begin
//                 normal_idx = k;
//                 // Reverse the 6 bits (since 64 samples = 6 bit index)
//                 rev_idx = {normal_idx[0], normal_idx[1], normal_idx[2], normal_idx[3], normal_idx[4], normal_idx[5]};
                
//                 // Fetch using the locked print_offset + bit-reversed index
//                 $display("Output Index: %2d | Bit-Reversed Fetch (Idx %2d): Real = %d, Imag = %d", 
//                          normal_idx, rev_idx, 
//                          $signed(output_real[print_offset + rev_idx]), 
//                          $signed(output_imag[print_offset + rev_idx]));
//             end
            
//             $display("========================================");
//         end
//     end

// endmodule

`timescale 1ps/1ps

module tb_split_fft_top();

    parameter WIDTH = 16;
    parameter Num_of_samples = 256;
    parameter MAX_FILE_SAMPLES = 100000; // Adjust if your file has more than 4096 lines

    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;

    // Array size doubled to hold 2 windows (128 samples total) for ping-pong output
    reg [WIDTH-1:0] output_real [0:(2*Num_of_samples) - 1];
    reg [WIDTH-1:0] output_imag [0:(2*Num_of_samples) - 1];

    // Arrays to hold the file data loaded at time 0
    reg signed [WIDTH-1:0] file_real_data [0:MAX_FILE_SAMPLES - 1];
    reg signed [WIDTH-1:0] file_imag_data [0:MAX_FILE_SAMPLES - 1];
    integer total_samples_read = 0;

    integer output_count = 0;

    split_fft_top #(
        .WIDTH(WIDTH),
        .N(Num_of_samples),
        .SIMPLE_MULT(1),
        .input_pipeline_bram(1),   ///0 input ans 1 output not implemented functionality
        .output_pipeline_bram(1),
        .Fast_DSP(1)
    ) dut (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .input_real_0(input_real_0),
        .input_real_1(input_real_1),
        .input_real_2(input_real_2),
        .input_real_3(input_real_3),
        .input_imag_0(input_imag_0),
        .input_imag_1(input_imag_1),
        .input_imag_2(input_imag_2),
        .input_imag_3(input_imag_3),
        .output_en(output_en),
        .output_real_0(output_real_0),
        .output_real_1(output_real_1),
        .output_real_2(output_real_2),
        .output_real_3(output_real_3),
        .output_imag_0(output_imag_0),
        .output_imag_1(output_imag_1),
        .output_imag_2(output_imag_2),
        .output_imag_3(output_imag_3)
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
        in_file_id = $fopen("input_data.txt", "r");
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
            $display("Loaded Sample %0d: Imag = %d, Real = %d", i, file_imag_data[i], file_real_data[i]);
            i=i+1;
        end

        $fclose(in_file_id);
        $display("Loaded %0d samples from input file into memory.", total_samples_read);
    end

    // ---------------------------------------------------------
    // 2. Feed data to the FFT and open Output File
    // ---------------------------------------------------------
    initial begin
        // Open the output text file
        out_file_id = $fopen("fft_output.txt", "w");
        if (out_file_id == 0) begin
            $display("ERROR: Could not create fft_output.txt.");
            $finish;
        end

        // Initialize inputs
        input_en <= 0;
        input_real_0 <= 0; input_imag_0 <= 0;
        input_real_1 <= 0; input_imag_1 <= 0;
        input_real_2 <= 0; input_imag_2 <= 0;
        input_real_3 <= 0; input_imag_3 <= 0;
        #5;
        
        // Apply reset
        reset = 1;
        #10;
        @ (posedge clock);
        reset <= 0;
        #100;
        
        // Enable input and stream from memory arrays
        input_en <= 1;
        
        // Loop through the pre-loaded arrays, 4 samples at a time
        for (i = 0; i < total_samples_read; i = i + 4) begin
            input_real_0 <= file_real_data[i+0];
            input_imag_0 <= file_imag_data[i+0];
            input_real_1 <= file_real_data[i+1];
            input_imag_1 <= file_imag_data[i+1];
            input_real_2 <= file_real_data[i+2];
            input_imag_2 <= file_imag_data[i+2];
            input_real_3 <= file_real_data[i+3];
            input_imag_3 <= file_imag_data[i+3];
            
            #10; // Wait 1 clock cycle to feed the next 4 samples
        end
        
        input_en <= 0;
        $display("Finished streaming data to FFT. Waiting for outputs to flush...");
        
        // Wait enough time for the final FFT windows to compute and flush out
        #20000; 
        
        $fclose(out_file_id);
        $display("Simulation complete. Outputs saved to fft_output.txt.");
        $finish;
    end

    initial begin
        $dumpfile("tb_split_fft_top.vcd");
        $dumpvars(0, tb_split_fft_top);
    end

    // ---------------------------------------------------------
    // 3. Ping-Pong Output Capturing and File Writing
    // ---------------------------------------------------------
    
    reg [7:0] normal_idx;
    reg [7:0] rev_idx;
    integer k;
    
    // Variables for ping-pong buffer index management
    reg frame_ready = 0;
    integer window_count = 0;
    integer write_offset = 0; // Correction index for writing (0 or 64)
    integer print_offset = 0; // Correction index for printing (0 or 64)

    // Capture the outputs continuously using a ping-pong offset
    always @(posedge clock) begin
        if (reset) begin
            output_count <= 0;
            write_offset <= 0;
            frame_ready <= 0;
        end else begin
            frame_ready <= 0; // Default: clear trigger
            
            if (output_en) begin
                // Write into the array using the base write_offset
                output_real[write_offset + output_count + 0] <= output_real_0;
                output_imag[write_offset + output_count + 0] <= output_imag_0;
                
                output_real[write_offset + output_count + 1] <= output_real_1;
                output_imag[write_offset + output_count + 1] <= output_imag_1;
                
                output_real[write_offset + output_count + 2] <= output_real_2;
                output_imag[write_offset + output_count + 2] <= output_imag_2;
                
                output_real[write_offset + output_count + 3] <= output_real_3;
                output_imag[write_offset + output_count + 3] <= output_imag_3;
                
                // If we hit the end of the 64-sample window
                if (output_count == (Num_of_samples - 4)) begin
                    output_count <= 0;
                    
                    // Lock in the current offset for the print block
                    print_offset <= write_offset;
                    
                    // Toggle the write offset between 0 and 64 for the next cycle
                    if (write_offset == 0) begin
                        write_offset <= Num_of_samples;
                    end else begin
                        write_offset <= 0;
                    end
                    
                    frame_ready <= 1; // Trigger print
                end else begin
                    output_count <= output_count + 4;
                end
            end
        end
    end

    // Print the captured array safely on POSEDGE reading from the print_offset
    always @(posedge clock) begin
        if (frame_ready) begin
            window_count = window_count + 1;
            
            // $display("========================================");
            // $display("   WRITING WINDOW %0d TO FILE...", window_count);
            // $display("========================================");
            
            for (k = 0; k < Num_of_samples; k = k + 1) begin
                normal_idx = k;
                // Reverse the 6 bits (since 64 samples = 6 bit index)
                rev_idx = {normal_idx[0], normal_idx[1], normal_idx[2], normal_idx[3], normal_idx[4], normal_idx[5], normal_idx[6], normal_idx[7]};
                
                // 1. Display formatted output to the console for monitoring
                // $display("Idx: %2d | Rev: %2d | Imag = %d, Real = %d", 
                //          normal_idx, rev_idx, 
                //          $signed(output_imag[print_offset + rev_idx]), 
                //          $signed(output_real[print_offset + rev_idx]));

                // 2. Write raw data to the text file (Imaginary Real)
                $fdisplay(out_file_id, "%d %d", 
                          $signed(output_real[print_offset + rev_idx]), 
                          $signed(output_imag[print_offset + rev_idx]));
            end
        end
    end

endmodule