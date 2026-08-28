`timescale 1ns / 1ps

module tb_butterfly_complex_core();

    parameter WIDTH = 16;
    reg clock;
    reg reset;
    reg start;
    
    // Inputs
    reg signed [WIDTH-1:0] ar, ai, br, bi, cr, ci, dr, di;

    // Outputs
    wire signed [WIDTH+1:0] out1r, out1i;
    wire signed [WIDTH:0]   out2r, out2i;
    wire signed [WIDTH:0]   out3r, out3i;
    wire signed [WIDTH+1:0] out4r, out4i;
    wire done;

    // Instantiate the Unit Under Test (UUT)
    butterfly_complex_core #(.WIDTH(WIDTH)) uut (
        .clock(clock), .reset(reset), .start(start),
        .ar(ar), .ai(ai), .br(br), .bi(bi),
        .cr(cr), .ci(ci), .dr(dr), .di(di),
        .out1r(out1r), .out1i(out1i),
        .out2r(out2r), .out2i(out2i),
        .out3r(out3r), .out3i(out3i),
        .out4r(out4r), .out4i(out4i),
        .done(done)
    );

    // Clock Generation (100MHz)
    always #5 clock = ~clock;

    initial begin
        // --- Initialization ---
        $dumpfile("tb_butterfly.vcd");
        $dumpvars(0, tb_butterfly_complex_core);

        clock = 0;
        reset = 1;
        start = 0;
        {ar, ai, br, bi, cr, ci, dr, di} = 0;

        // --- Reset Sequence ---
        #20 reset = 0;
        #10;

        // --- Test Case 1: Simple Real Additions ---
        // X0=10, X1=0, X2=5, X3=0
        // Expected: out2 (X0+X2) = 15, out3 (X1+X3) = 0
        @(posedge clock);
        start = 1;
        ar = 16'd127; ai = 16'd635;
        br = 16'd254;  bi = 16'd381;
        cr = 16'd381;  ci = 16'd889;
        dr = 16'd508;  di = 16'd127;
        
        @(posedge clock);
        start = 0; // De-assert start after 1 cycle

        // --- Test Case 2: Complex Logic ---
        // X0=8+j2, X1=4+j1, X2=2+j1, X3=1+j1
        // diff02 = (8-2) + j(2-1) = 6 + j1
        // diff13 = (4-1) + j(1-1) = 3 + j0
        // Expected out1: (6+j1) - j(3+j0) = 6 + j1 - j3 = 6 - j2
        // Expected out4: (6+j1) + j(3+j0) = 6 + j1 + j3 = 6 + j4
        @(posedge clock);
        start = 1;
        ar = 16'd8; ai = 16'd2;
        br = 16'd4; bi = 16'd1;
        cr = 16'd2; ci = 16'd1;
        dr = 16'd1; di = 16'd1;
        
        @(posedge clock);
        start = 0;

        // --- Wait for results ---
        // We look for the 'done' signal to trigger our display
        repeat (10) @(posedge clock) begin
            if (done) begin
                $display("--- Result Captured at Time %t ---", $time);
                $display("Out1 (Complex): %d + j(%d)", out1r, out1i);
                $display("Out2 (Sum X0+X2): %d + j(%d)", out2r, out2i);
                $display("Out3 (Sum X1+X3): %d + j(%d)", out3r, out3i);
                $display("Out4 (Complex): %d + j(%d)", out4r, out4i);
                $display("----------------------------------");
            end
        end

        #50 $finish;
    end

endmodule