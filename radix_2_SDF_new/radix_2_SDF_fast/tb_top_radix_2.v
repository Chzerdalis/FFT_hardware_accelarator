`timescale 1ns/1ps  

module tb_top;
    parameter WIDTH = 32;
    parameter Num_of_samples = 256;
    parameter Num_of_windows = 1;

    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1;
    reg [WIDTH-1:0] input_imag_0, input_imag_1;
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1;
    wire [WIDTH-1:0] output_imag_0, output_imag_1;

    reg [WIDTH-1:0] output_real_fast [0:Num_of_samples*Num_of_windows-1];
    reg [WIDTH-1:0] output_imag_fast [0:Num_of_samples*Num_of_windows-1];
    reg signed [WIDTH-1:0] gen_input_real [0:Num_of_samples*Num_of_windows-1];
    reg signed [WIDTH-1:0] gen_input_imag [0:Num_of_samples*Num_of_windows-1];

    fft_top #(
        .WIDTH(WIDTH),
        .Num_of_samples(Num_of_samples)
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

    integer i;
    integer fd;
    integer output_count = 0;
    integer window_count = 0;

    initial begin
        clock = 0;
        forever #5 clock = ~clock; 
    end

    initial begin
        if (Num_of_windows > 1) begin: large_dataset
            if (Num_of_windows == 3 && Num_of_samples == 64 && WIDTH == 32) begin
                `include "gen_data/large_dataset_3x64_32bit_Random1.vh"
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
        input_en = 0;
        // Apply reset
        reset = 1;
        #100;
        @ (posedge clock);
        reset = 0;
        #10;

        if(Num_of_windows > 1) begin
            input_en <= 1;
            for (i = 0; i < Num_of_samples*Num_of_windows; i = i + 2) begin
                input_real_0 <= gen_input_real[i];
                input_imag_0 <= gen_input_imag[i];
                input_real_1 <= gen_input_real[i + 1];
                input_imag_1 <= gen_input_imag[i + 1];
                #10;
            end
            input_en <= 0;
        end else begin
            input_en <= 1;
            for (i = 0; i < Num_of_samples; i = i + 2) begin
                input_real_0 <= gen_input_real[i];
                input_imag_0 <= 0;
                input_real_1 <= gen_input_real[i + 1];
                input_imag_1 <= 0;
                #10;
            end
            input_en <= 0;
        end
        #4000;

        fd = $fopen("Outputs.txt", "w");


        for(i = 0; i < Num_of_samples*Num_of_windows; i = i + 1) begin
            $display("Output Index %d: Real = %d, Imag = %d", i, $signed(output_real_fast[i]), $signed(output_imag_fast[i]));
            $fdisplay(fd, "%d %d", $signed(output_real_fast[i]), $signed(output_imag_fast[i]));
        end

        $finish;

    end

    initial begin
        $dumpfile("tb_top_fft.vcd");
        $dumpvars(0, tb_top);
    end

    always @(posedge clock) begin
        if (output_en) begin
            output_real_fast[output_count] = output_real_0;
            output_real_fast[output_count + Num_of_samples/2] = output_real_1;

            output_imag_fast[output_count] = output_imag_0;
            output_imag_fast[output_count + Num_of_samples/2] = output_imag_1;
            
            if(output_count == (Num_of_samples/2 - 1) + window_count*Num_of_samples) begin
                window_count = window_count + 1;
                output_count = Num_of_samples*window_count;
            end else begin
                output_count = output_count + 1;
            end
        end
    end
endmodule