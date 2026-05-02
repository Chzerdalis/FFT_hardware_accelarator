`timescale 1ns/1ps

module tb_top;
    parameter WIDTH = 16;
    parameter Num_of_samples = 256;
    parameter Num_of_windows = 1;

    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;

    reg [WIDTH-1:0] output_real_fast [0:Num_of_windows*Num_of_samples-1];
    reg [WIDTH-1:0] output_imag_fast [0:Num_of_windows*Num_of_samples-1];
    reg signed [WIDTH-1:0] gen_input_real [0:Num_of_windows*Num_of_samples-1];
    reg signed [WIDTH-1:0] gen_input_imag [0:Num_of_windows*Num_of_samples-1];

    integer output_count = 0;
    integer window_count = 0;

    fft_top #(
        .WIDTH(WIDTH),
        .Num_of_samples(Num_of_samples)
    ) uut (
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

    integer output_count_b = 0;

    integer i, fd;

    initial begin
        // Initialize clock
        clock = 0;
        forever #5 clock = ~clock; // 10 time units clock period
    end

    initial begin
        if (Num_of_windows > 1) begin: large_dataset
            if (Num_of_windows == 20 && Num_of_samples == 256 && WIDTH == 16) begin
                `include "gen_data/large_dataset_20x256_16bit_Random0.vh"
            end
        end else begin: single_window_dataset
            if (Num_of_samples == 16) begin
                if(WIDTH == 16) begin
                    `include "gen_data/f_input_rev_16_16bit.vh"
                end else if(WIDTH == 18) begin
                    `include "gen_data/f_input_rev_16_18bit.vh"
                end
                else if(WIDTH == 24) begin
                    `include "gen_data/f_input_rev_16_24bit.vh"
                end
                else if(WIDTH == 32) begin
                    `include "gen_data/f_input_rev_16_32bit.vh"
                end
            end else if (Num_of_samples == 64) begin
                if(WIDTH == 16) begin
                    `include "gen_data/f_input_rev_64_16bit.vh"
                end else if(WIDTH == 18) begin
                    `include "gen_data/f_input_rev_64_18bit.vh"
                end else if(WIDTH == 24) begin
                    `include "gen_data/f_input_rev_64_24bit.vh"
                end else if(WIDTH == 32) begin
                    `include "gen_data/f_input_rev_64_32bit.vh"
                end
            end else if (Num_of_samples == 256) begin
                if(WIDTH == 16) begin
                    `include "gen_data/f_input_rev_256_16bit.vh"
                end else if(WIDTH == 18) begin
                    `include "gen_data/f_input_rev_256_18bit.vh"
                end else if(WIDTH == 24) begin
                    `include "gen_data/f_input_rev_256_24bit.vh"
                end else if(WIDTH == 32) begin
                    `include "gen_data/f_input_rev_256_32bit.vh"
                end
            end else if (Num_of_samples == 1024) begin
                if(WIDTH == 16) begin
                    `include "gen_data/f_input_rev_1024_16bit.vh"
                end else if(WIDTH == 18) begin
                    `include "gen_data/f_input_rev_1024_18bit.vh"
                end else if(WIDTH == 24) begin
                    `include "gen_data/f_input_rev_1024_24bit.vh"
                end else if(WIDTH == 32) begin
                    `include "gen_data/f_input_rev_1024_32bit.vh"
                end
            end
        end
    end

    initial begin
        //Initialize cosine table (bit-reversed order)
        // gen_input_real[0]  = 32'sd32768;   // index 0  -> rev4(0)  = 0
        // gen_input_real[4]  = 32'sd30274;   // index 1  -> rev4(1)  = 4
        // gen_input_real[8]  = 32'sd23170;   // index 2  -> rev4(2)  = 8-
        // gen_input_real[12] = 32'sd12540;   // index 3  -> rev4(3)  = 12
        // gen_input_real[1]  = 32'sd0;       // index 4  -> rev4(4)  = 1
        // gen_input_real[5]  = -32'sd12540;  // index 5  -> rev4(5)  = 5
        // gen_input_real[9]  = -32'sd23170;  // index 6  -> rev4(6)  = 9
        // gen_input_real[13] = -32'sd30274;  // index 7  -> rev4(7)  = 13
        // gen_input_real[2]  = -32'sd32768;  // index 8  -> rev4(8)  = 2
        // gen_input_real[6]  = -32'sd30274;  // index 9  -> rev4(9)  = 6
        // gen_input_real[10] = -32'sd23170;  // index 10 -> rev4(10) = 10
        // gen_input_real[14] = -32'sd12540;  // index 11 -> rev4(11) = 14
        // gen_input_real[3]  = 32'sd0;       // index 12 -> rev4(12) = 3
        // gen_input_real[7]  = 32'sd12540;   // index 13 -> rev4(13) = 7
        // gen_input_real[11] = 32'sd23170;   // index 14 -> rev4(14) = 11
        // gen_input_real[15] = 32'sd30274;   // index 15 -> rev4(15) = 15
        
        input_en = 0;
        // Apply reset
        reset = 1;
        #100;
        @ (posedge clock);
        reset = 0;
        #10

        // Enable input
        if(Num_of_windows > 1) begin
            input_en <= 1;
        for (i = 0; i < Num_of_windows*Num_of_samples; i = i + 4) begin
            input_real_0 <= gen_input_real[i];
            input_imag_0 <= gen_input_imag[i];
            input_real_1 <= gen_input_real[i + 1];
            input_imag_1 <= gen_input_imag[i + 1];
            input_real_2 <= gen_input_real[i + 2];
            input_imag_2 <= gen_input_imag[i + 2];
            input_real_3 <= gen_input_real[i + 3];
            input_imag_3 <= gen_input_imag[i + 3];
            #10;
        end
        input_en <= 0;
        end else begin
            input_en <= 1;
        for (i = 0; i < Num_of_windows*Num_of_samples; i = i + 4) begin
            input_real_0 <= gen_input_real[i];
            input_imag_0 <= 0;
            input_real_1 <= gen_input_real[i + 1];
            input_imag_1 <= 0;
            input_real_2 <= gen_input_real[i + 2];
            input_imag_2 <= 0;
            input_real_3 <= gen_input_real[i + 3];
            input_imag_3 <= 0;
            #10;
        end
        input_en <= 0;
        end

        // Wait for output
        #3000;

        fd = $fopen("Outputs.txt", "w");

        for(i = 0; i < Num_of_windows*Num_of_samples; i = i + 1) begin
            $display("Output Index %d: Real = %d, Imag = %d", i, $signed(output_real_fast[i]), $signed(output_imag_fast[i]));
            $fdisplay(fd, "%d %d", $signed(output_real_fast[i]), $signed(output_imag_fast[i]));
        end

        // Disable input
        $finish;
    end
    initial begin
        $dumpfile("tb_top_fft.vcd");
        $dumpvars(0, tb_top);
    end

    // Explicitly dump memory arrays element by element in a single initial block
    // to avoid potential simulator issues with generate loops and $dumpvars.
   initial begin
       integer s, j;
       // For STAGE_NUM=4 (N=256), stages 1, 2, 3 have memories.
       // Stage 1: s=1, MEM_DEPTH = 2 * 4^0 = 2
       // Stage 2: s=2, MEM_DEPTH = 2 * 4^1 = 8
       // Stage 3: s=3, MEM_DEPTH = 2 * 4^2 = 32

       // Dump Stage 1 memories (s=1, depth=2)
       //if (Num_of_samples >= 64) begin
           for (j = 0; j < 8; j = j + 1) begin
               $dumpvars(1, tb_top.uut.gen_stages[1].stage_inst.gen_memory.mem.mem_A[j]);
               $dumpvars(1, tb_top.uut.gen_stages[1].stage_inst.gen_memory.mem.mem_B[j]);
               $dumpvars(1, tb_top.uut.gen_stages[1].stage_inst.gen_memory.mem.mem_C[j]);
               $dumpvars(1, tb_top.uut.gen_stages[1].stage_inst.gen_memory.mem.mem_D[j]);
           end
       //end

       // Dump Stage 2 memories (s=2, depth=8)
       //if (Num_of_samples >= 256) begin
           for (j = 0; j < 32; j = j + 1) begin
               $dumpvars(1, tb_top.uut.gen_stages[2].stage_inst.gen_memory.mem.mem_A[j]);
               $dumpvars(1, tb_top.uut.gen_stages[2].stage_inst.gen_memory.mem.mem_B[j]);
               $dumpvars(1, tb_top.uut.gen_stages[2].stage_inst.gen_memory.mem.mem_C[j]);
               $dumpvars(1, tb_top.uut.gen_stages[2].stage_inst.gen_memory.mem.mem_D[j]);
           end
       //end

       // Dump Stage 3 memories (s=3, depth=32)
       //if (Num_of_samples >= 1024) begin
           for (j = 0; j < 64; j = j + 1) begin
               $dumpvars(1, tb_top.uut.gen_stages[3].stage_inst.gen_memory.mem.mem_A[j]);
               $dumpvars(1, tb_top.uut.gen_stages[3].stage_inst.gen_memory.mem.mem_B[j]);
               $dumpvars(1, tb_top.uut.gen_stages[3].stage_inst.gen_memory.mem.mem_C[j]);
               $dumpvars(1, tb_top.uut.gen_stages[3].stage_inst.gen_memory.mem.mem_D[j]);
           end
       //end
   end
    
    always @(posedge clock) begin
        if (output_en) begin
            output_real_fast[output_count] = output_real_0;
            output_real_fast[output_count + Num_of_samples/4] = output_real_1;
            output_real_fast[output_count + Num_of_samples/2] = output_real_2;
            output_real_fast[output_count + 3*Num_of_samples/4] = output_real_3;

            output_imag_fast[output_count] = output_imag_0;
            output_imag_fast[output_count + Num_of_samples/4] = output_imag_1;
            output_imag_fast[output_count + Num_of_samples/2] = output_imag_2;
            output_imag_fast[output_count + 3*Num_of_samples/4] = output_imag_3;
            if(output_count == (Num_of_samples/4 - 1) + window_count*Num_of_samples) begin
                window_count = window_count + 1;
                output_count = Num_of_samples*window_count;
            end else begin
                output_count = output_count + 1;
            end
        end
    end
endmodule
