`timescale 1ns / 1ps

module tb_control_unit_last_stage();

    // ----------------------------------------------------
    // 1. Parameters
    // ----------------------------------------------------
    // Kept identical to the module's default parameters
    parameter Num_of_samples = 256;
    parameter STAGE_NUM = 5;

    localparam stage_num_bits = $clog2(Num_of_samples/(4 * 2**(STAGE_NUM-2))) - 1;
    localparam step_size = Num_of_samples/(2**(STAGE_NUM-2));
    localparam Num_of_samples_bits = $clog2(Num_of_samples/4);
    // ----------------------------------------------------
    // 2. Signals
    // ----------------------------------------------------
    // Inputs (declared as reg to drive them in initial block)
    reg clock;
    reg reset;
    reg input_en;

    // Outputs (declared as wire to connect to module)
    wire step_mode_in;
    wire step_mode_out;
    wire  stride_segment_counter;
    wire  butterfly_op_counter;
    wire butterfly_op_counter_en;

    // ----------------------------------------------------
    // 3. Module Instantiation (UUT - Unit Under Test)
    // ----------------------------------------------------
    control_unit_fsm_last_stage #(
        .Num_of_samples(Num_of_samples),
        .Num_of_samples_bits(Num_of_samples_bits)
    ) uut (
        .clock(clock),
        .reset(reset),
        .input_en(input_en),
        .step_mode_in(step_mode_in),
        .step_mode_out(step_mode_out),
        .stride_segment_counter(stride_segment_counter),
        .butterfly_op_counter(butterfly_op_counter),
        .butterfly_op_counter_en(butterfly_op_counter_en)
    );

    // ----------------------------------------------------
    // 4. Clock Generation
    // ----------------------------------------------------
    // 10ns clock period (100 MHz)
    always #5 clock = ~clock;

    // ----------------------------------------------------
    // 5. Stimulus Generation
    // ----------------------------------------------------
    initial begin
        $dumpfile("tb_fsm_last_stage.vcd");
        $dumpvars(0, tb_control_unit_last_stage);

        // Initialize all inputs to known states
        clock = 0;
        reset = 1;
        input_en = 0;

        #20;
        reset = 0;
    
        #100;

        input_en = 1;

        #2560;

        input_en = 0;

        $display("Time %0t: Simulation Complete.", $time);

        #500
        $finish;
    end

endmodule