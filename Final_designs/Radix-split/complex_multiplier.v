`timescale 1ps/1ps

`ifdef NO_DSP
    `define DSP_ATTR (* use_dsp = "no" *)
`else
    `define DSP_ATTR (* use_dsp = "yes" *)
`endif

module ComplexMultiplier #(
    parameter WIDTH = 16,
    parameter Tw_WIDTH = 8,
    parameter PROD = 32,
    parameter SIMPLE_MULT = 1,
    parameter Fast_DSP = 0,
    parameter carry_save = 0,
    parameter CHUNK = 8
)(  
    input clock,
    input signed [WIDTH-1:0] a_re, a_im,
    input signed [WIDTH-1:0] b_re, b_im,
    input signed [Tw_WIDTH -1:0] w0re, w0im, w1re, w1im,
    output signed[PROD:0] out_a_re, out_a_im,
    output signed[PROD:0] out_b_re, out_b_im
);  

    generate
        if (SIMPLE_MULT) begin
            SimpleMult #(
                .WIDTH(WIDTH),
                .Tw_WIDTH(Tw_WIDTH),
                .PROD(PROD),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .CHUNK(CHUNK)
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
                .Tw_WIDTH(Tw_WIDTH),
                .PROD(PROD),
                .Fast_DSP(Fast_DSP),
                .carry_save(carry_save),
                .CHUNK(CHUNK)
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


`DSP_ATTR
module SimpleMult #(
    parameter WIDTH = 16,
    parameter Tw_WIDTH = 8,
    parameter PROD = 32,
    parameter Fast_DSP = 1,
    parameter carry_save = 0,
    parameter CHUNK = 8
)(
    input clock,
    input signed[WIDTH-1:0] a_re, a_im,
    input signed[WIDTH-1:0] b_re, b_im,
    input signed [Tw_WIDTH -1:0] w0re, w0im, w1re, w1im,
    output reg signed[PROD:0] out_a_re, out_a_im,
    output reg signed[PROD:0] out_b_re, out_b_im
);

    generate
        if (Fast_DSP) begin : fast_dsp
            reg signed [PROD-1:0]    rr_a_s1, ri_a_s1;
            reg signed [PROD-1:0]    rr_b_s1, ri_b_s1;
            reg signed [WIDTH-1:0]   a_im_s1, b_im_s1;
            reg signed [Tw_WIDTH-1:0] w0re_s1, w0im_s1, w1re_s1, w1im_s1;

            reg signed [PROD-1:0]    rr_a_s2, ri_a_s2, ii_a_s2, ir_a_s2;
            reg signed [PROD-1:0]    rr_b_s2, ri_b_s2, ii_b_s2, ir_b_s2;

            always @(posedge clock) begin
                // Stage 1 //
                // Channel A
                rr_a_s1 <= a_re * w0re;
                ri_a_s1 <= a_re * w0im;
                
                a_im_s1 <= a_im;
                w0re_s1 <= w0re;
                w0im_s1 <= w0im;
                // Channel B
                rr_b_s1 <= b_re * w1re;
                ri_b_s1 <= b_re * w1im;
                
                b_im_s1 <= b_im;
                w1re_s1 <= w1re;
                w1im_s1 <= w1im;

                // Stage 2 //
                // Channel A
                rr_a_s2 <= rr_a_s1;
                ri_a_s2 <= ri_a_s1;
                
                ii_a_s2 <= a_im_s1 * w0im_s1;
                ir_a_s2 <= a_im_s1 * w0re_s1;
                // Channel B
                rr_b_s2 <= rr_b_s1;
                ri_b_s2 <= ri_b_s1;
                
                ii_b_s2 <= b_im_s1 * w1im_s1;
                ir_b_s2 <= b_im_s1 * w1re_s1;

                // Stage 3 //
                // Channel A
                out_a_re <= rr_a_s2 - ii_a_s2;
                out_a_im <= ri_a_s2 + ir_a_s2;
                // Channel B
                out_b_re <= rr_b_s2 - ii_b_s2;
                out_b_im <= ri_b_s2 + ir_b_s2;
            end
        end else begin : slow_dsp
            if(carry_save) begin : carry_save_mult
                (* use_dsp = "no" *) wire signed[PROD-1:0] rr_a, ii_a, ri_a, ir_a;
                (* use_dsp = "no" *) wire signed[PROD-1:0] rr_b, ii_b, ri_b, ir_b;

                // Channel A Multipliers
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_rr_a (.clock(clock), .reset(1'b0), .start(1'b1), .a(a_re), .b(w0re), .product(rr_a), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ii_a (.clock(clock), .reset(1'b0), .start(1'b1), .a(a_im), .b(w0im), .product(ii_a), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ri_a (.clock(clock), .reset(1'b0), .start(1'b1), .a(a_re), .b(w0im), .product(ri_a), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ir_a (.clock(clock), .reset(1'b0), .start(1'b1), .a(a_im), .b(w0re), .product(ir_a), .done());

                // Channel B Multipliers
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_rr_b (.clock(clock), .reset(1'b0), .start(1'b1), .a(b_re), .b(w1re), .product(rr_b), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ii_b (.clock(clock), .reset(1'b0), .start(1'b1), .a(b_im), .b(w1im), .product(ii_b), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ri_b (.clock(clock), .reset(1'b0), .start(1'b1), .a(b_re), .b(w1im), .product(ri_b), .done());
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_ir_b (.clock(clock), .reset(1'b0), .start(1'b1), .a(b_im), .b(w1re), .product(ir_b), .done());

                always@(posedge clock) begin
                    out_a_re <= rr_a - ii_a;
                    out_a_im <= ri_a + ir_a;
                    out_b_re <= rr_b - ii_b;
                    out_b_im <= ri_b + ir_b;
                end
            end else begin : no_carry_save_mult
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
            end
        end
    endgenerate
endmodule

`DSP_ATTR
module CheapMult #(
    parameter WIDTH = 16,
    parameter Tw_WIDTH = 8,
    parameter PROD  = 32,
    parameter Fast_DSP = 1,
    parameter carry_save = 0,
    parameter CHUNK = 8
)(
    input  clock,
    input  signed [WIDTH-1:0]   a_re, a_im,
    input  signed [WIDTH-1:0]   b_re, b_im,
    input  signed [Tw_WIDTH-1:0] w0re, w0im, w1re, w1im,
    output reg signed [PROD:0] out_a_re, out_a_im,
    output reg signed [PROD:0] out_b_re, out_b_im
);
    generate 
        if (Fast_DSP) begin : fast_dsp
            (* use_dsp = "no" *) reg signed [WIDTH:0]     sum_a_s1, sum_b_s1;
            (* use_dsp = "no" *) reg signed [Tw_WIDTH:0]   sum_w0_s1, diff_w0_s1;
            (* use_dsp = "no" *) reg signed [Tw_WIDTH:0]   sum_w1_s1, diff_w1_s1;

            reg signed [WIDTH-1:0]   a_re_s1, a_im_s1;
            reg signed [WIDTH-1:0]   b_re_s1, b_im_s1;
            reg signed [Tw_WIDTH-1:0] w0re_s1, w1re_s1;

            reg signed [PROD:0]      k1_a_s2, k2_a_s2;
            reg signed [PROD:0]      k1_b_s2, k2_b_s2;
            
            reg signed [WIDTH-1:0]   a_im_s2, b_im_s2;
            reg signed [Tw_WIDTH:0]   sum_w0_s2, sum_w1_s2;

            reg signed [PROD:0]      k1_a_s3, k2_a_s3, k3_a_s3;
            reg signed [PROD:0]      k1_b_s3, k2_b_s3, k3_b_s3;
            reg signed [PROD:0] out_a_im_reg;
            reg signed [PROD:0] out_b_im_reg;


            always @(posedge clock) begin
                // Stage 1 //
                // Channel A
                sum_a_s1   <= a_re + a_im;
                sum_w0_s1  <= w0re + w0im;
                diff_w0_s1 <= w0im - w0re;
                a_re_s1    <= a_re;
                a_im_s1    <= a_im;
                w0re_s1    <= w0re;
                // Channel B
                sum_b_s1   <= b_re + b_im;
                sum_w1_s1  <= w1re + w1im;
                diff_w1_s1 <= w1im - w1re;
                b_re_s1    <= b_re;
                b_im_s1    <= b_im;
                w1re_s1    <= w1re;

                // Stage 2 //
                // Channel A
                k1_a_s2   <= w0re_s1 * sum_a_s1;
                k2_a_s2   <= a_re_s1 * diff_w0_s1;
                
                a_im_s2   <= a_im_s1;
                sum_w0_s2 <= sum_w0_s1;
                // Channel B
                k1_b_s2   <= w1re_s1 * sum_b_s1;
                k2_b_s2   <= b_re_s1 * diff_w1_s1;
                
                b_im_s2   <= b_im_s1;
                sum_w1_s2 <= sum_w1_s1;

                // Stage 3 //
                // Channel A
                k3_a_s3 <= a_im_s2 * sum_w0_s2;
                
                k1_a_s3 <= k1_a_s2;
                // k2_a_s3 <= k2_a_s2;
                out_a_im_reg <= k1_a_s2 + k2_a_s2;
                // Channel B
                k3_b_s3 <= b_im_s2 * sum_w1_s2;
                
                k1_b_s3 <= k1_b_s2;
                // k2_b_s3 <= k2_b_s2;
                out_b_im_reg <= k1_b_s2 + k2_b_s2;

                // Stage 4 //
                // Channel A
                out_a_re <= k1_a_s3 - k3_a_s3;
                out_a_im <= out_a_im_reg;
                // Channel B
                out_b_re <= k1_b_s3 - k3_b_s3;
                out_b_im <= out_b_im_reg;
            end
        end else begin : slow_dsp
            if(carry_save) begin : carry_save_mult
                (* use_dsp = "no" *) reg signed [WIDTH:0]   sum_a_in, sum_b_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] sum_w0_in, diff_w0_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] sum_w1_in, diff_w1_in;

                (* use_dsp = "no" *) reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                (* use_dsp = "no" *) reg signed [WIDTH-1:0]   b_re_d, b_im_d;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH-1:0] w0re_d, w1re_d;

                (* use_dsp = "no" *) wire signed [PROD:0] k1_a, k2_a, k3_a;
                (* use_dsp = "no" *) wire signed [PROD:0] k1_b, k2_b, k3_b;
                (* use_dsp = "no" *) reg signed [PROD:0] k1_a_reg, k1_b_reg;

                // Channel A Carry_mults
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH+1), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_k1_a (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(sum_a_in), .b(w0re_d), .product(k1_a), .done()
                );
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH+1), .CHUNK(CHUNK)) u_cm_k2_a (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(a_re_d), .b(diff_w0_in), .product(k2_a), .done()
                );
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH+1), .CHUNK(CHUNK)) u_cm_k3_a (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(a_im_d), .b(sum_w0_in), .product(k3_a), .done()
                );

                // Channel B Carry_mults
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH+1), .B_WIDTH(Tw_WIDTH), .CHUNK(CHUNK)) u_cm_k1_b (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(sum_b_in), .b(w1re_d), .product(k1_b), .done()
                );
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH+1), .CHUNK(CHUNK)) u_cm_k2_b (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(b_re_d), .b(diff_w1_in), .product(k2_b), .done()
                );
                (* use_dsp = "no" *) Carry_mult #(.A_WIDTH(WIDTH), .B_WIDTH(Tw_WIDTH+1), .CHUNK(CHUNK)) u_cm_k3_b (
                    .clock(clock), .reset(1'b0), .start(1'b1), .a(b_im_d), .b(sum_w1_in), .product(k3_b), .done()
                );

                always @(posedge clock) begin
                    sum_a_in <= a_re + a_im;
                    sum_w0_in <= w0re + w0im;
                    diff_w0_in <= w0im - w0re;
                    
                    sum_b_in <= b_re + b_im;
                    sum_w1_in <= w1re + w1im;
                    diff_w1_in <= w1im - w1re;

                    a_re_d <= a_re;
                    a_im_d <= a_im;
                    w0re_d <= w0re;

                    b_re_d <= b_re;
                    b_im_d <= b_im;
                    w1re_d <= w1re;

                    k1_a_reg <= k1_a;
                    k1_b_reg <= k1_b;

                    out_a_re <= k1_a_reg - k3_a;
                    out_a_im <= k1_a_reg + k2_a;

                    out_b_re <= k1_b_reg - k3_b;
                    out_b_im <= k1_b_reg + k2_b;
                end
            end else begin : no_carry_save_mult
                (* use_dsp = "no" *) reg signed [WIDTH:0]   sum_a_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] sum_w0_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] diff_w0_in;

                reg signed [WIDTH:0]   sum_b_in;
                reg signed [Tw_WIDTH:0] sum_w1_in;
                reg signed [Tw_WIDTH:0] diff_w1_in;

                reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                reg signed [WIDTH-1:0]   b_re_d, b_im_d;
                reg signed [Tw_WIDTH-1:0] w0re_d;
                reg signed [Tw_WIDTH-1:0] w1re_d;

                reg signed [PROD:0] k1_a, k2_a, k3_a;
                reg signed [PROD:0] k1_b, k2_b, k3_b;

                always @(posedge clock) begin
                    sum_a_in <= a_re + a_im;
                    sum_w0_in <= w0re + w0im;
                    diff_w0_in <= w0im - w0re;
                    
                    sum_b_in <= b_re + b_im;
                    sum_w1_in <= w1re + w1im;
                    diff_w1_in <= w1im - w1re;
                    
                    a_re_d <= a_re;
                    a_im_d <= a_im;
                    w0re_d <= w0re;
                    
                    b_re_d <= b_re;
                    b_im_d <= b_im;
                    w1re_d <= w1re;

                    k1_a <= w0re_d * sum_a_in;
                    k2_a <= a_re_d * diff_w0_in;
                    k3_a <= a_im_d * sum_w0_in;

                    k1_b <= w1re_d * sum_b_in;
                    k2_b <= b_re_d * diff_w1_in;
                    k3_b <= b_im_d * sum_w1_in;

                    out_a_re <= k1_a - k3_a;
                    out_a_im <= k1_a + k2_a;
                    out_b_re <= k1_b - k3_b;
                    out_b_im <= k1_b + k2_b;
                end
            end
        end
    endgenerate
endmodule