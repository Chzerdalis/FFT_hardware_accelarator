module tb_third_stage();

    parameter WIDTH = 16;
    parameter Num_of_samples = 64;

    reg clock;
    reg reset;
    reg input_en;
    reg [WIDTH-1:0] input_real_0, input_real_1, input_real_2, input_real_3;
    reg [WIDTH-1:0] input_imag_0, input_imag_1, input_imag_2, input_imag_3;
    wire output_en, output_en_1;
    wire step_mode_output, step_mode_output_1;
    wire [WIDTH-1:0] output_real_0, output_real_1, output_real_2, output_real_3;
    wire [WIDTH-1:0] output_imag_0, output_imag_1, output_imag_2, output_imag_3;
    wire [WIDTH-1:0] output_real_0_2, output_real_1_2, output_real_2_2, output_real_3_2;
    wire [WIDTH-1:0] output_imag_0_2, output_imag_1_2, output_imag_2_2, output_imag_3_2;

    reg [WIDTH-1:0] inputs_real [0:Num_of_samples - 1];
    reg [WIDTH-1:0] inputs_imag [0:Num_of_samples - 1];

    reg [WIDTH-1:0] output_real [0:Num_of_samples - 1];
    reg [WIDTH-1:0] output_imag [0:Num_of_samples - 1];

    integer output_count = 0;

    Split_radix_ThirdStage #(
        .WIDTH(WIDTH),
        .Num_of_samples(Num_of_samples),
        .STAGE_NUM(3),
        .SIMPLE_MULT(1)
    ) dut (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .step_mode(1'b0),
        .input_real_0(input_real_0),
        .input_real_1(input_real_1),
        .input_real_2(input_real_2),
        .input_real_3(input_real_3),
        .input_imag_0(input_imag_0),
        .input_imag_1(input_imag_1),
        .input_imag_2(input_imag_2),
        .input_imag_3(input_imag_3),
        .output_en(output_en),
        .step_mode_output(step_mode_output),
        .output_real_0(output_real_0),
        .output_real_1(output_real_1),
        .output_real_2(output_real_2),
        .output_real_3(output_real_3),
        .output_imag_0(output_imag_0),
        .output_imag_1(output_imag_1),
        .output_imag_2(output_imag_2),
        .output_imag_3(output_imag_3)
    );

    Split_radix_ThirdStage #(
        .WIDTH(WIDTH),
        .Num_of_samples(Num_of_samples),
        .STAGE_NUM(3),
        .SIMPLE_MULT(0)
    ) dut2 (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .step_mode(1'b0),
        .input_real_0(input_real_0),
        .input_real_1(input_real_1),
        .input_real_2(input_real_2),
        .input_real_3(input_real_3),
        .input_imag_0(input_imag_0),
        .input_imag_1(input_imag_1),
        .input_imag_2(input_imag_2),
        .input_imag_3(input_imag_3),
        .output_en(output_en_1),
        .step_mode_output(step_mode_output_1),
        .output_real_0(output_real_0_2),
        .output_real_1(output_real_1_2),
        .output_real_2(output_real_2_2),
        .output_real_3(output_real_3_2),
        .output_imag_0(output_imag_0_2),
        .output_imag_1(output_imag_1_2),
        .output_imag_2(output_imag_2_2),
        .output_imag_3(output_imag_3_2)
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
        // Apply reset
        reset = 1;
        #10;
        @ (posedge clock);
        reset = 0;
        #100
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
        #10000;
        $finish;
    end

    integer idx; 

    initial begin
        $dumpfile("tb_third_stage.vcd");
        $dumpvars(0, tb_third_stage);


        for (idx = 0; idx < (2 * 4); idx = idx + 1) begin
            $dumpvars(0, dut.memory_inst.mem_A[idx]);
            $dumpvars(0, dut.memory_inst.mem_B[idx]);
            $dumpvars(0, dut.memory_inst.mem_C[idx]);
            $dumpvars(0, dut.memory_inst.mem_D[idx]);
        end
    end
endmodule