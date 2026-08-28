`timescale 1ps/1ps

(* use_dsp = "no" *)
module ComplexMultiplier #(
    parameter WIDTH     = 16,
    // Tw_WIDTH must match the bit_width the keys were encoded at (9).
    parameter Tw_WIDTH  = 9,
    parameter PROD      = WIDTH + Tw_WIDTH,
    parameter KEY_WIDTH = 14
)(
    input clock,
    input signed [WIDTH-1:0] a_re, a_im,
    input signed [WIDTH-1:0] b_re, b_im,
    // CSHM keys, not twiddle values
    input [KEY_WIDTH-1:0] w0re, w0im, w1re, w1im,
    output reg signed [PROD:0] out_a_re, out_a_im,
    output reg signed [PROD:0] out_b_re, out_b_im
);

    // cshm_2_keys produces WIDTH+Tw_WIDTH-bit products. Kept as its own
    // localparam so this still lines up if the caller overrides PROD with
    // something wider than the natural product width.
    localparam CP = WIDTH + Tw_WIDTH;

    // ---- Channel A: (a_re + j*a_im) * W0 --------------------------------
    wire signed [CP-1:0] a_r_out0, a_r_out1;   // a_re*w0re, a_re*w0im
    wire signed [CP-1:0] a_i_out0, a_i_out1;   // a_im*w0re, a_im*w0im

    cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_aR (
        .clock(clock), .a(a_re), .key0(w0re), .key1(w0im),
        .out0(a_r_out0), .out1(a_r_out1)
    );
    cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_aI (
        .clock(clock), .a(a_im), .key0(w0re), .key1(w0im),
        .out0(a_i_out0), .out1(a_i_out1)
    );

    // ---- Channel B: (b_re + j*b_im) * W1 --------------------------------
    wire signed [CP-1:0] b_r_out0, b_r_out1;   // b_re*w1re, b_re*w1im
    wire signed [CP-1:0] b_i_out0, b_i_out1;   // b_im*w1re, b_im*w1im

    cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_bR (
        .clock(clock), .a(b_re), .key0(w1re), .key1(w1im),
        .out0(b_r_out0), .out1(b_r_out1)
    );
    cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_bI (
        .clock(clock), .a(b_im), .key0(w1re), .key1(w1im),
        .out0(b_i_out0), .out1(b_i_out1)
    );

    // ---- Registered combine (matches the original's final add/sub stage) -
    // Operands are CP bits and the outputs are PROD+1 bits; both sides are
    // signed, so the assignment sign-extends rather than zero-fills.
    always @(posedge clock) begin
        out_a_re <= $signed(a_r_out0) - $signed(a_i_out1);
        out_a_im <= $signed(a_r_out1) + $signed(a_i_out0);

        out_b_re <= $signed(b_r_out0) - $signed(b_i_out1);
        out_b_im <= $signed(b_r_out1) + $signed(b_i_out0);
    end

endmodule