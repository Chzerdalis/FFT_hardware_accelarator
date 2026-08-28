`timescale 1ns/1ps

module tb_butterfly_compare();

    parameter WIDTH = 32;
    
    // Inputs
    reg clock;
    reg reset;
    reg start;
    reg signed [WIDTH-1:0] ar, ai, br, bi;
    reg signed [WIDTH/2-1:0] wr, wi;

    // Outputs from Combinational Module
    wire signed [WIDTH-1:0] c_out1r, c_out1i, c_out2r, c_out2i;
    
    // Outputs from Pipelined Module
    wire signed [WIDTH-1:0] p_out1r, p_out1i, p_out2r, p_out2i;
    wire done;

    // 1. Instantiate Combinational Module
    butterfly #(WIDTH) dut_comb (
        .ar(ar), .ai(ai), .br(br), .bi(bi),
        .wr(wr), .wi(wi),
        .out1r(c_out1r), .out1i(c_out1i), .out2r(c_out2r), .out2i(c_out2i)
    );

    // 2. Instantiate Pipelined Module
    butterfly_radix_2_pipelined #(WIDTH) dut_pipe (
        .clock(clock),
        .reset(reset),
        .start(start),
        .ar(ar), .ai(ai), .br(br), .bi(bi),
        .wr(wr), .wi(wi),
        .out1r(p_out1r), .out1i(p_out1i), .out2r(p_out2r), .out2i(p_out2i),
        .done(done)
    );

    // Clock Generation (100MHz)
    always #5 clock = ~clock;

    initial begin
        // Initialize signals
        clock = 0;
        reset = 1;
        start = 0;
        ar = 0; ai = 0; br = 0; bi = 0;
        wr = 0; wi = 0;

        // Reset Pulse
        #20 reset = 0;
        #10;

        // Test Case 1: Simple integers
        // Note: Inputs are signed. Twiddle factors are WIDTH/2.
        send_data(32'd100, 32'd50, 32'd20, 32'd10, 16'd1, 16'd0);
        
        // Test Case 2: Negative values
        send_data(32'd1000, -32'd500, 32'd200, -32'd100, 16'h7FFF, 16'h0000);

        // Test Case 3: Complex twiddle factor
        send_data(32'd5000, 32'd2000, 32'd1000, 32'd1000, 16'd100, 16'd100);

        #100;
        $display("\nSimulation Finished.");
        $finish;
    end

    // Task to send data and wait for completion
    task send_data(
        input signed [WIDTH-1:0] i_ar, i_ai, i_br, i_bi,
        input signed [WIDTH/2-1:0] i_wr, i_wi
    );
    begin
        @(posedge clock);
        ar = i_ar; ai = i_ai; br = i_br; bi = i_bi;
        wr = i_wr; wi = i_wi;
        start = 1;
        
        @(posedge clock);
        start = 0; // De-assert start after one cycle

        // Wait for the pipelined module to finish (4 cycles later)
        wait(done);
        
        // Give it one tiny delta for the output registers to update
        #1; 
        
        $display("--- Comparison at Time %t ---", $time);
        if ((c_out1r === p_out1r) && (c_out1i === p_out1i) && 
            (c_out2r === p_out2r) && (c_out2i === p_out2i)) begin
            $display("SUCCESS: Results Match!");
            $display("Comb: out1=(%d, %d) out2=(%d, %d)", c_out1r, c_out1i, c_out2r, c_out2i);
            $display("Pipe: out1=(%d, %d) out2=(%d, %d)", p_out1r, p_out1i, p_out2r, p_out2i);
        end else begin
            $display("FAILURE: Mismatch Detected!");
            $display("Comb: out1=(%d, %d) out2=(%d, %d)", c_out1r, c_out1i, c_out2r, c_out2i);
            $display("Pipe: out1=(%d, %d) out2=(%d, %d)", p_out1r, p_out1i, p_out2r, p_out2i);
        end
    end
    endtask

endmodule