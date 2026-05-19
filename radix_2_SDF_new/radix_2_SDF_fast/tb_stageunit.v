`timescale 1ns / 1ps

module SdfUnit2_fast_tb;

    // Parameters
    parameter WIDTH = 32;
    parameter STAGE_NUM = 3;       // Testing Stage 4
    parameter Num_of_samples = 16;
    parameter CLK_PERIOD = 10;

    // Inputs
    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1;
    reg [WIDTH-1:0] input_imag_0, input_imag_1;

    // Outputs
    wire output_en;
    wire [WIDTH-1:0] output_real_0, output_real_1;
    wire [WIDTH-1:0] output_imag_0, output_imag_1;

    // Instantiate the Unit Under Test (UUT)
    SdfUnit2_fast #(
        .WIDTH(WIDTH),
        .STAGE_NUM(STAGE_NUM),
        .Num_of_samples(Num_of_samples)
    ) uut (
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

    // Clock Generation
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end

    // Stimulus
    initial begin
        $display("Simulation Finished");
        $dumpfile("tb_stageunit.vcd");
        $dumpvars(0, SdfUnit2_fast_tb);
        $dumpvars(0, uut);

        // Initialize Inputs
        reset = 1;
        input_en = 0;
        input_real_0 = 0; input_real_1 = 0;
        input_imag_0 = 0; input_imag_1 = 0;

        // Wait for global reset
        #(CLK_PERIOD * 5);
        reset = 0;
        #(CLK_PERIOD * 2);

        @(posedge clock);
        input_en <= 1;
        input_real_0 <= 'd1;
        input_imag_0 <= 'd1;
        input_real_1 <= 'd9;
        input_imag_1 <= 'd9;

        @(posedge clock);
        input_real_0 <= 'd3;
        input_imag_0 <= 'd3;
        input_real_1 <= 'd11;
        input_imag_1 <= 'd11;

        @(posedge clock);
        input_real_0 <= 'd5;
        input_imag_0 <= 'd5;
        input_real_1 <= 'd13;
        input_imag_1 <= 'd13;

        @(posedge clock);
        input_real_0 <= 'd7;
        input_imag_0 <= 'd7;
        input_real_1 <= 'd15;
        input_imag_1 <= 'd15;

        @(posedge clock);
        input_real_0 <= 'd2;
        input_imag_0 <= 'd2;
        input_real_1 <= 'd10;
        input_imag_1 <= 'd10;

        @(posedge clock);
        input_real_0 <= 'd4;
        input_imag_0 <= 'd4;
        input_real_1 <= 'd12;
        input_imag_1 <= 'd12;

        @(posedge clock);
        input_real_0 <= 'd6;
        input_imag_0 <= 'd6;
        input_real_1 <= 'd14;
        input_imag_1 <= 'd14;

        @(posedge clock);
        input_real_0 <= 'd8;
        input_imag_0 <= 'd8;
        input_real_1 <= 'd16;
        input_imag_1 <= 'd16;

        @(posedge clock);
        // Stop input to allow the SDF pipeline to flush/process
        input_en <= 0;
        
        // Wait for processing to complete
        #(CLK_PERIOD * 50);
        // for (integer i = 0; i < 2; i = i + 1) begin
        //     $dumpvars(0, db0.buf_re[i]);
        //     $dumpvars(0, db0.buf_im[i]);
        // end

        #10;
        $finish;
    end

    // Monitor Outputs
    initial begin
        $monitor("Time: %t | OutEn: %b | Out0: (%h + j%h) | Out1: (%h + j%h)", 
                 $time, output_en, output_real_0, output_imag_0, output_real_1, output_imag_1);
    end

endmodule