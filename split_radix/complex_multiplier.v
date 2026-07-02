`timescale 1ps/1ps

module ComplexMultiplier #(
    parameter WIDTH = 16,
    parameter PROD = 32,
    parameter SIMPLE_MULT = 1
)(  
    input clock,
    input signed [WIDTH-1:0] a_re, a_im,
    input signed [WIDTH-1:0] b_re, b_im,
    input signed [WIDTH/2 -1:0] w0re, w0im, w1re, w1im,
    output signed[PROD:0] out_a_re, out_a_im,
    output signed[PROD:0] out_b_re, out_b_im
);  

    generate
        if (SIMPLE_MULT) begin
            SimpleMult #(
                .WIDTH(WIDTH),
                .PROD(PROD)
            ) simple_mult_inst (
                .clock(clock),
                .a_re(a_re),
                .a_im(a_im),
                .b_re(b_re),
                .b_im(b_im),
                .w0re(w0re),
                .w0im(w0im),
                .w1re(w1re),
                .w1im(w1im),
                .out_a_re(out_a_re),
                .out_a_im(out_a_im),
                .out_b_re(out_b_re),
                .out_b_im(out_b_im)
            );
        end else begin
            CheapMult #(
                .WIDTH(WIDTH),
                .PROD(PROD)
            ) cheap_mult_inst (
                .clock(clock),
                .a_re(a_re),
                .a_im(a_im),
                .b_re(b_re),
                .b_im(b_im),
                .w0re(w0re),
                .w0im(w0im),
                .w1re(w1re),
                .w1im(w1im),
                .out_a_re(out_a_re),
                .out_a_im(out_a_im),
                .out_b_re(out_b_re),
                .out_b_im(out_b_im)
            );
        end
    endgenerate

endmodule


module SimpleMult #(
    parameter WIDTH = 16,
    parameter PROD = 32
)(
    input clock,
    input signed[WIDTH-1:0] a_re, a_im,
    input signed[WIDTH-1:0] b_re, b_im,
    input signed [WIDTH/2 -1:0] w0re, w0im, w1re, w1im,
    output reg signed[PROD:0] out_a_re, out_a_im,
    output reg signed[PROD:0] out_b_re, out_b_im
);
    reg signed[PROD-1:0] rr_a, ii_a, ri_a, ir_a;
    reg signed[PROD-1:0] rr_b, ii_b, ri_b, ir_b;

    always@(posedge clock) begin
        rr_a <= a_re * w0re;
        ii_a <= a_im * w0im;
        ri_a <= a_re * w0im;
        ir_a <= a_im * w0re;

        rr_b <= b_re * w1re;
        ii_b <= b_im * w1im;
        ri_b <= b_re * w1im;
        ir_b <= b_im * w1re;

        out_a_re <= rr_a - ii_a;
        out_a_im <= ri_a + ir_a;
        out_b_re <= rr_b - ii_b;
        out_b_im <= ri_b + ir_b;
    end
endmodule

module CheapMult #(
    parameter WIDTH = 16,
    parameter PROD  = 32
)(
    input  clock,
    input  signed [WIDTH-1:0]   a_re, a_im,
    input  signed [WIDTH-1:0]   b_re, b_im,
    input  signed [WIDTH/2-1:0] w0re, w0im, w1re, w1im,
    output reg signed [PROD:0] out_a_re, out_a_im,
    output reg signed [PROD:0] out_b_re, out_b_im
);

    reg signed [WIDTH:0]   sum_a_in;
    reg signed [WIDTH/2:0] sum_w0_in;
    reg signed [WIDTH/2:0] diff_w0_in;

    reg signed [WIDTH:0]   sum_b_in;
    reg signed [WIDTH/2:0] sum_w1_in;
    reg signed [WIDTH/2:0] diff_w1_in;

    reg signed [PROD:0] k1_a, k2_a, k3_a;
    reg signed [PROD:0] k1_b, k2_b, k3_b;

    always @(posedge clock) begin
        sum_a_in <= a_re + a_im;
        sum_w0_in <= w0re + w0im;
        diff_w0_in <= w0im - w0re;
        sum_b_in <= b_re + b_im;
        sum_w1_in <= w1re + w1im;
        diff_w1_in <= w1im - w1re;

        k1_a <= w0re * sum_a_in;
        k2_a <= a_re * diff_w0_in;
        k3_a <= a_im * sum_w0_in;

        k1_b <= w1re * sum_b_in;
        k2_b <= b_re * diff_w1_in;
        k3_b <= b_im * sum_w1_in;

        out_a_re <= k1_a - k3_a;
        out_a_im <= k1_a + k2_a;

        out_b_re <= k1_b - k3_b;
        out_b_im <= k1_b + k2_b;
    end
    
endmodule