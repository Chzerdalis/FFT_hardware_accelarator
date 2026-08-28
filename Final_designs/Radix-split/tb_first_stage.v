`timescale 1ns/1ps

module tb_first_stage();

    parameter WIDTH = 16;
    parameter Num_of_samples = 64;

    reg clock;
    reg reset;
    reg input_en, input_en_1;
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
    wire output_en, output_en_1;
    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;
    wire [WIDTH-1:0] output_real_0_b;
    wire [WIDTH-1:0] output_imag_0_b;

    reg [WIDTH-1:0] inputs_real [0:Num_of_samples - 1];
    reg [WIDTH-1:0] inputs_imag [0:Num_of_samples - 1];

    reg [WIDTH-1:0] output_real_fast [0:Num_of_samples - 1];
    reg [WIDTH-1:0] output_imag_fast [0:Num_of_samples - 1];
    reg [WIDTH-1:0] output_real [0:Num_of_samples - 1];
    reg [WIDTH-1:0] output_imag [0:Num_of_samples - 1];

    integer output_count = 0;

    Split_radix_FirstStage #(
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

    integer i;

    initial begin
        // Initialize clock
        clock = 0;
        forever #5 clock = ~clock; // 10 time units clock period
    end

    initial begin
        // Initialize inputs
        input_en = 0;
        #5;
        input_en_1 = 0;
        // Apply reset
        reset = 1;
        #10;
        @ (posedge clock);
        reset = 0;
        #10

        // Enable input
        input_en <= 1;
        for (i = 0; i < 64; i = i + 4) begin
            input_real_0 <= 4*i+0;
            input_imag_0 <= 4*i+0;
            input_real_1 <= 4*i+1;
            input_imag_1 <= 4*i+1;
            input_real_2 <= 4*i+2;
            input_imag_2 <= 4*i+2;
            input_real_3 <= 4*i+3;
            input_imag_3 <= 4*i+3;
            #10;
        end
        for (i = 0; i < 64; i = i + 4) begin
            input_real_0 <= 4*i+0;
            input_imag_0 <= 4*i+0;
            input_real_1 <= 4*i+1;
            input_imag_1 <= 4*i+1;
            input_real_2 <= 4*i+2;
            input_imag_2 <= 4*i+2;
            input_real_3 <= 4*i+3;
            input_imag_3 <= 4*i+3;
            #10;
        end
        input_en <= 0;

        #10;
        input_en_1 <= 1;
        for (i = 0; i < 16; i = i + 1) begin
            input_real_0 <= inputs_real[i];
            input_imag_0 <= inputs_imag[i];
            #10;
        end
        input_en_1 <= 0;

        // Wait for output
        #200;

        for(i = 0; i < Num_of_samples; i = i + 1) begin
            if(output_real_fast[i] == output_real[i]) begin
                $display("%d Okey real\n", i);
            end else begin
               $display("%d NOkey real\n", i);
            end
            if(output_imag_fast[i] == output_imag[i]) begin
                $display("%d Okey imag\n", i);
            end else begin
               $display("%d NOkey imag\n", i);
            end
        end

        // Disable input
        $finish;
    end
    initial begin
        $dumpfile("tb_first_stage.vcd");
        $dumpvars(0, tb_first_stage);
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
            output_count = output_count + 1;
        end
    end
endmodule
