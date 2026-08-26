`timescale 1ns/1ps

// `ifdef NO_DSP
//     `define DSP_ATTR (* use_dsp = "no" *)
// `else
//     `define DSP_ATTR (* use_dsp = "yes" *)
// `endif

// module butterfly_radix4_pipeline #(
//     parameter WIDTH = 16,
//     parameter Tw_WIDTH = 16
// ) (
//     input                  clock,
//     input                  reset,
//     input                  start,
//     input  signed [WIDTH-1:0] ar, ai,
//     input  signed [WIDTH-1:0] br, bi,
//     input  signed [WIDTH-1:0] cr, ci,
//     input  signed [WIDTH-1:0] dr, di,

//     // Twiddle width is assumed to be Tw_WIDTH
//     input  signed [Tw_WIDTH-1:0] w0r, w0i,
//     input  signed [Tw_WIDTH-1:0] w1r, w1i,
//     input  signed [Tw_WIDTH-1:0] w2r, w2i,

//     output reg signed [WIDTH-1:0] out1r, out1i,
//     output reg signed [WIDTH-1:0] out2r, out2i,
//     output reg signed [WIDTH-1:0] out3r, out3i,
//     output reg signed [WIDTH-1:0] out4r, out4i,
//     output reg                  done
// );
//     localparam TW = Tw_WIDTH;
//     localparam PROD = WIDTH + TW; // product width when multiplying data*twiddle
    
//     //Original registers
//     reg start_reg_0, start_reg_1, start_reg_2, start_reg_3;
//     reg signed [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg, cr_reg, ci_reg, dr_reg, di_reg;
//     reg signed [Tw_WIDTH-1:0] w0r_reg, w0i_reg, w1r_reg, w1i_reg, w2r_reg, w2i_reg;
//     reg signed [WIDTH-1:0] ar_reg_0, ai_reg_0;
//     reg signed [WIDTH-1:0] ar_reg_1, ai_reg_1;
//     reg signed [PROD-1:0] m0r_reg, m0i_reg, m1r_reg, m1i_reg, m2r_reg, m2i_reg;
//     reg signed [PROD-1:0] mul_m0r_reg_1, mul_m0i_reg_1, mul_m1r_reg_1, mul_m1i_reg_1, mul_m2r_reg_1, mul_m2i_reg_1;
//     reg signed [PROD-1:0] mul_m0r_reg_2, mul_m0i_reg_2, mul_m1r_reg_2, mul_m1i_reg_2, mul_m2r_reg_2, mul_m2i_reg_2;
//     reg signed [WIDTH-1:0] t0r_reg, t0i_reg, t1r_reg, t1i_reg, t2r_reg, t2i_reg, t3r_reg, t3i_reg;

//     //Do one multimplication per clock cycle per dedicated data path
//     wire signed [PROD-1:0] mul_m0r_1 = br_reg * w0r_reg;
//     wire signed [PROD-1:0] mul_m0i_1 = br_reg * w0i_reg;
//     wire signed [PROD-1:0] mul_m1r_1 = cr_reg * w1r_reg;
//     wire signed [PROD-1:0] mul_m1i_1 = cr_reg * w1i_reg;
//     wire signed [PROD-1:0] mul_m2r_1 = dr_reg * w2r_reg;
//     wire signed [PROD-1:0] mul_m2i_1 = dr_reg * w2i_reg;

//     wire signed [PROD-1:0] mul_m0r_2 = bi_reg * w0i_reg;
//     wire signed [PROD-1:0] mul_m0i_2 = bi_reg * w0r_reg;
//     wire signed [PROD-1:0] mul_m1r_2 = ci_reg * w1i_reg;
//     wire signed [PROD-1:0] mul_m1i_2 = ci_reg * w1r_reg;
//     wire signed [PROD-1:0] mul_m2r_2 = di_reg * w2i_reg;
//     wire signed [PROD-1:0] mul_m2i_2 = di_reg * w2r_reg;

//     //One addition/subtraction per clock cycle per data path to find m0, m1, m2
//     wire signed [PROD-1:0] m0r = mul_m0r_reg_1 - mul_m0r_reg_2;
//     wire signed [PROD-1:0] m0i = mul_m0i_reg_1 + mul_m0i_reg_2;

//     wire signed [PROD-1:0] m1r = mul_m1r_reg_1 - mul_m1r_reg_2;
//     wire signed [PROD-1:0] m1i = mul_m1i_reg_1 + mul_m1i_reg_2;

//     wire signed [PROD-1:0] m2r = mul_m2r_reg_1 - mul_m2r_reg_2;
//     wire signed [PROD-1:0] m2i = mul_m2i_reg_1 + mul_m2i_reg_2;

//     //One addition/subtraction per clock cycle per data path to find t0, t1, t2, t3
//     wire signed [WIDTH-1:0] t0r = ar_reg_1 + m1r_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t0i = ai_reg_1 + m1i_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t1r = ar_reg_1 - m1r_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t1i = ai_reg_1 - m1i_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t2r = m0r_reg[PROD-2:TW-1] + m2r_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t2i = m0i_reg[PROD-2:TW-1] + m2i_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t3r = m0r_reg[PROD-2:TW-1] - m2r_reg[PROD-2:TW-1];
//     wire signed [WIDTH-1:0] t3i = m0i_reg[PROD-2:TW-1] - m2i_reg[PROD-2:TW-1];

//     // Output assignments
//     wire signed [WIDTH-1:0] out1r_reg = t0r_reg + t2r_reg;
//     wire signed [WIDTH-1:0] out1i_reg = t0i_reg + t2i_reg;
//     wire signed [WIDTH-1:0] out2r_reg = t1r_reg + t3i_reg;
//     wire signed [WIDTH-1:0] out2i_reg = t1i_reg - t3r_reg;
//     wire signed [WIDTH-1:0] out3r_reg = t0r_reg - t2r_reg;
//     wire signed [WIDTH-1:0] out3i_reg = t0i_reg - t2i_reg;
//     wire signed [WIDTH-1:0] out4r_reg = t1r_reg - t3i_reg;
//     wire signed [WIDTH-1:0] out4i_reg = t1i_reg + t3r_reg;


//     always @(posedge clock) begin
//         if (reset) begin
//             //Input registers
//             ar_reg <= 0; ai_reg <= 0; br_reg <= 0; bi_reg <= 0;
//             cr_reg <= 0; ci_reg <= 0; dr_reg <= 0; di_reg <= 0;
//             w0r_reg <= 0; w0i_reg <= 0;
//             w1r_reg <= 0; w1i_reg <= 0;
//             w2r_reg <= 0; w2i_reg <= 0;
//             start_reg_0 <= 0;
//             //First pipeline stage registers
//             mul_m0r_reg_1 <= 0;  mul_m0i_reg_1 <= 0;
//             mul_m1r_reg_1 <= 0;  mul_m1i_reg_1 <= 0;
//             mul_m2r_reg_1 <= 0;  mul_m2i_reg_1 <= 0; 
//             mul_m0r_reg_2 <= 0;  mul_m0i_reg_2 <= 0; 
//             mul_m1r_reg_2 <= 0;  mul_m1i_reg_2 <= 0;
//             mul_m2r_reg_2 <= 0;  mul_m2i_reg_2 <= 0;
//             ar_reg_0 <= 0; ai_reg_0 <= 0;
//             start_reg_1 <= 0;
//             //Second pipeline stage registers
//             m0i_reg <= 0; m0r_reg <= 0;
//             m1i_reg <= 0; m1r_reg <= 0;
//             m2i_reg <= 0; m2r_reg <= 0;
//             ar_reg_1 <= 0; ai_reg_1 <= 0;
//             start_reg_2 <= 0;
//             //Third pipeline stage registers
//             t0r_reg <= 0; t0i_reg <= 0;
//             t1r_reg <= 0; t1i_reg <= 0;
//             t2r_reg <= 0; t2i_reg <= 0;
//             t3r_reg <= 0; t3i_reg <= 0;
//             start_reg_3 <= 0;
//             //Output registers
//             out1r <= 0; out1i <= 0;
//             out2r <= 0; out2i <= 0;
//             out3r <= 0; out3i <= 0;
//             out4r <= 0; out4i <= 0;
//             done <= 0;
//         end else begin
//             ar_reg <= ar; ai_reg <= ai; br_reg <= br; bi_reg <= bi;
//             cr_reg <= cr; ci_reg <= ci; dr_reg <= dr; di_reg <= di;
//             w0r_reg <= w0r; w0i_reg <= w0i;
//             w1r_reg <= w1r; w1i_reg <= w1i;
//             w2r_reg <= w2r; w2i_reg <= w2i;
//             start_reg_0 <= start;

//             mul_m0r_reg_1 <= mul_m0r_1; mul_m0i_reg_1 <= mul_m0i_1;
//             mul_m1r_reg_1 <= mul_m1r_1; mul_m1i_reg_1 <= mul_m1i_1;
//             mul_m2r_reg_1 <= mul_m2r_1; mul_m2i_reg_1 <= mul_m2i_1;
//             mul_m0r_reg_2 <= mul_m0r_2; mul_m0i_reg_2 <= mul_m0i_2;
//             mul_m1r_reg_2 <= mul_m1r_2; mul_m1i_reg_2 <= mul_m1i_2;
//             mul_m2r_reg_2 <= mul_m2r_2; mul_m2i_reg_2 <= mul_m2i_2;
//             ar_reg_0 <= ar_reg; ai_reg_0 <= ai_reg;
//             start_reg_1 <= start_reg_0;

//             m0i_reg <= m0i; m0r_reg <= m0r;
//             m1i_reg <= m1i; m1r_reg <= m1r;
//             m2i_reg <= m2i; m2r_reg <= m2r;
//             ar_reg_1 <= ar_reg_0; ai_reg_1 <= ai_reg_0;
//             start_reg_2 <= start_reg_1;

//             t0r_reg <= t0r; t0i_reg <= t0i;
//             t1r_reg <= t1r; t1i_reg <= t1i;
//             t2r_reg <= t2r; t2i_reg <= t2i;
//             t3r_reg <= t3r; t3i_reg <= t3i;
//             start_reg_3 <= start_reg_2;

//             out1r <= out1r_reg; out1i <= out1i_reg;
//             out2r <= out2r_reg; out2i <= out2i_reg;
//             out3r <= out3r_reg; out3i <= out3i_reg;
//             out4r <= out4r_reg; out4i <= out4i_reg;
//             done <= start_reg_3;
//         end
//     end
// endmodule

`timescale 1ns/1ps

// ===========================================================================
// Radix-4 butterfly, self-contained.
//
// Contains:
//   butterfly_radix4_pipeline  - radix-4 butterfly with the same option set
//                                as butterfly_radix_2_pipelined
//   SimpleMult                 - copied verbatim from the radix-2 file
//   CheapMult                  - copied verbatim from the radix-2 file
//
// The complex multiply (the product differences/sums) happens INSIDE
// SimpleMult / CheapMult, exactly as in radix-2 -- the butterfly just takes
// out_a_re / out_a_im from each multiplier.
//
// Radix-4 needs THREE complex multiplies (b*W0, c*W1, d*W2). They run in
// parallel with identical parameters, so they are latency matched and
// delay_mult is the same expression as radix-2.
//
// Pipeline after the multiplier:
//     scale reg (1) + t stage (1) + output stage (1) = 3
// versus radix-2's scale (1) + output (1) = 2, so:
//     A path delay = delay_mult + 1
//     done  delay  = delay_mult + 3
//
// NOTE: SimpleMult/CheapMult drive out_a_re/out_a_im as [PROD:0] while the
// m*_full wires here are [PROD-1:0] -- the same one-bit truncation that
// exists in the radix-2 file. Kept as-is so radix-4 matches radix-2.
//
// Datapath registers are not reset; only the done pipeline is.
// ===========================================================================

`ifdef NO_DSP
    `define DSP_ATTR (* use_dsp = "no" *)
`else
    `define DSP_ATTR (* use_dsp = "yes" *)
`endif

module butterfly_radix4_pipeline #(
    parameter WIDTH      = 32,
    parameter Tw_WIDTH   = 16,
    parameter SimpleMult = 0,
    parameter Fast_DSP   = 0,
    parameter stage_num  = 1,
    parameter carry_save = 0,
    parameter CHUNK      = 8
)(
    input                  clock,
    input                  reset,
    input                  start,

    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    // Twiddle width is assumed to be Tw_WIDTH
    input  signed [Tw_WIDTH-1:0] w0r, w0i,
    input  signed [Tw_WIDTH-1:0] w1r, w1i,
    input  signed [Tw_WIDTH-1:0] w2r, w2i,

    output reg signed [WIDTH-1:0] out1r, out1i,
    output reg signed [WIDTH-1:0] out2r, out2i,
    output reg signed [WIDTH-1:0] out3r, out3i,
    output reg signed [WIDTH-1:0] out4r, out4i,
    output wire                  done
);

    localparam TW   = Tw_WIDTH;
    localparam PROD = WIDTH + TW;

    localparam CarrySavedelay_simple = (Tw_WIDTH + (Tw_WIDTH + WIDTH - 1)/CHUNK + 2);
    localparam CarrySavedelay_cheap  = (Tw_WIDTH + 1 + (Tw_WIDTH + 1 + WIDTH - 1)/CHUNK + 2);

    localparam delay_mult = (stage_num != 1) ? ((Fast_DSP == 1) ? 4 : 2) + (SimpleMult == 1 ? 0 : 1) +
    (carry_save == 1 ? (SimpleMult == 1 ? CarrySavedelay_simple : CarrySavedelay_cheap) : 0) : 0;

    function signed [WIDTH-1:0] scale_product;
        input signed [PROD-1:0] x;
        reg signed [PROD-1:0] rounded_x;
        begin
            //rounded_x = x + (1 << (TW - 2));
            scale_product = $signed(x[PROD-2:TW-1]);
        end
    endfunction

    // ------------------------------------------------------------
    // Three complex multipliers: b*W0, c*W1, d*W2
    // ------------------------------------------------------------
    wire signed [PROD-1:0] m0r_full, m0i_full;
    wire signed [PROD-1:0] m1r_full, m1i_full;
    wire signed [PROD-1:0] m2r_full, m2i_full;

    generate
        if (stage_num != 1) begin : stage_gen
            if (SimpleMult) begin : simple_mult

                SimpleMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul0 (
                    .clock(clock),
                    .a_re(br), .a_im(bi),
                    .w0re(w0r), .w0im(w0i),
                    .out_a_re(m0r_full), .out_a_im(m0i_full)
                );

                SimpleMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul1 (
                    .clock(clock),
                    .a_re(cr), .a_im(ci),
                    .w0re(w1r), .w0im(w1i),
                    .out_a_re(m1r_full), .out_a_im(m1i_full)
                );

                SimpleMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul2 (
                    .clock(clock),
                    .a_re(dr), .a_im(di),
                    .w0re(w2r), .w0im(w2i),
                    .out_a_re(m2r_full), .out_a_im(m2i_full)
                );

            end else begin : cheap_mult

                CheapMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul0 (
                    .clock(clock),
                    .a_re(br), .a_im(bi),
                    .w0re(w0r), .w0im(w0i),
                    .out_a_re(m0r_full), .out_a_im(m0i_full)
                );

                CheapMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul1 (
                    .clock(clock),
                    .a_re(cr), .a_im(ci),
                    .w0re(w1r), .w0im(w1i),
                    .out_a_re(m1r_full), .out_a_im(m1i_full)
                );

                CheapMult #(
                    .WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH), .PROD(PROD),
                    .Fast_DSP(Fast_DSP), .carry_save(carry_save), .CHUNK(CHUNK)
                ) u_cmul2 (
                    .clock(clock),
                    .a_re(dr), .a_im(di),
                    .w0re(w2r), .w0im(w2i),
                    .out_a_re(m2r_full), .out_a_im(m2i_full)
                );

            end
        //end
        end else begin : stage_1

            // At stage 1 every twiddle is 1 + 0j, so each complex multiply is
            // an identity. Sign-extend into the product format so that
            // scale_product() recovers the original operand exactly.
            assign m0r_full = {{TW{br[WIDTH-1]}}, br} << (Tw_WIDTH - 1);
            assign m0i_full = {{TW{bi[WIDTH-1]}}, bi} << (Tw_WIDTH - 1);

            assign m1r_full = {{TW{cr[WIDTH-1]}}, cr} << (Tw_WIDTH - 1);
            assign m1i_full = {{TW{ci[WIDTH-1]}}, ci} << (Tw_WIDTH - 1);

            assign m2r_full = {{TW{dr[WIDTH-1]}}, dr} << (Tw_WIDTH - 1);
            assign m2i_full = {{TW{di[WIDTH-1]}}, di} << (Tw_WIDTH - 1);

        end
    endgenerate

    // ------------------------------------------------------------
    // A path delay: multiply latency + the scale register stage
    // ------------------------------------------------------------
    wire [WIDTH-1:0] ar_delayed, ai_delayed;

    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(delay_mult + 1)
    ) u_delay_a (
        .clock(clock),
        .data_in(ar),
        .data_out(ar_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(delay_mult + 1)
    ) u_delay_ai (
        .clock(clock),
        .data_in(ai),
        .data_out(ai_delayed)
    );

    // done: multiply + scale reg + t stage + output stage
    delay_reg_reset #(
        .WIDTH(1),
        .DELAY(delay_mult + 1 + 1 + 1)
    ) u_delay_start (
        .clock(clock),
        .reset(reset),
        .data_in(start),
        .data_out(done)
    );

    // ------------------------------------------------------------
    // Scaled product registers
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] m0r_reg, m0i_reg;
    reg signed [WIDTH-1:0] m1r_reg, m1i_reg;
    reg signed [WIDTH-1:0] m2r_reg, m2i_reg;

    // ------------------------------------------------------------
    // Radix-4 intermediate registers
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] t0r_reg, t0i_reg;
    reg signed [WIDTH-1:0] t1r_reg, t1i_reg;
    reg signed [WIDTH-1:0] t2r_reg, t2i_reg;
    reg signed [WIDTH-1:0] t3r_reg, t3i_reg;

    // ------------------------------------------------------------
    // Datapath: no reset
    // ------------------------------------------------------------
    always @(posedge clock) begin
        // Scale register stage
        m0r_reg <= scale_product(m0r_full);
        m0i_reg <= scale_product(m0i_full);

        m1r_reg <= scale_product(m1r_full);
        m1i_reg <= scale_product(m1i_full);

        m2r_reg <= scale_product(m2r_full);
        m2i_reg <= scale_product(m2i_full);

        // t stage
        t0r_reg <= ar_delayed + m1r_reg;
        t0i_reg <= ai_delayed + m1i_reg;

        t1r_reg <= ar_delayed - m1r_reg;
        t1i_reg <= ai_delayed - m1i_reg;

        t2r_reg <= m0r_reg + m2r_reg;
        t2i_reg <= m0i_reg + m2i_reg;

        t3r_reg <= m0r_reg - m2r_reg;
        t3i_reg <= m0i_reg - m2i_reg;

        // Output stage
        out1r <= t0r_reg + t2r_reg;
        out1i <= t0i_reg + t2i_reg;

        out2r <= t1r_reg + t3i_reg;
        out2i <= t1i_reg - t3r_reg;

        out3r <= t0r_reg - t2r_reg;
        out3i <= t0i_reg - t2i_reg;

        out4r <= t1r_reg - t3i_reg;
        out4i <= t1i_reg + t3r_reg;
    end

endmodule


`DSP_ATTR
module SimpleMult #(
    parameter WIDTH = 16,
    parameter Tw_WIDTH = 8,
    parameter PROD = 32,
    parameter Fast_DSP = 1,
    parameter carry_save = 1,
    parameter CHUNK = 8
)(
    input clock,
    input signed[WIDTH-1:0] a_re, a_im,
    input signed [Tw_WIDTH -1:0] w0re, w0im,
    output reg signed[PROD:0] out_a_re, out_a_im
);

    generate
        if (Fast_DSP) begin : fast_dsp
            reg signed [PROD-1:0]    rr_a_s1, ri_a_s1;
            reg signed [WIDTH-1:0]   a_im_s1;
            reg signed [Tw_WIDTH-1:0] w0re_s1, w0im_s1;
            reg signed [Tw_WIDTH-1:0]   w0_re_reg, w0_im_reg;
            reg signed [WIDTH-1:0] a_re_reg, a_im_reg;


            reg signed [PROD-1:0]    rr_a_s2, ri_a_s2; 
            reg signed [PROD-1:0] ii_a_s2, ir_a_s2;

            always @(posedge clock) begin
                w0_re_reg <= w0re;
                w0_im_reg <= w0im;
                a_re_reg <= a_re;
                a_im_reg <= a_im;

                // Stage 1 //
                // Channel A
                rr_a_s1 <= a_re_reg * w0_re_reg;
                ri_a_s1 <= a_re_reg * w0_im_reg;
                
                a_im_s1 <= a_im_reg;
                w0re_s1 <= w0_re_reg;
                w0im_s1 <= w0_im_reg;

                // Stage 2 //
                // Channel A
                rr_a_s2 <= rr_a_s1;
                ri_a_s2 <= ri_a_s1;
                
                ii_a_s2 <= a_im_s1 * w0im_s1;
                ir_a_s2 <= a_im_s1 * w0re_s1;

                // Stage 3 //
                // Channel A
                out_a_re <= rr_a_s2 - ii_a_s2;
                out_a_im <= ri_a_s2 + ir_a_s2;
            end
        end else begin : slow_dsp
            if(carry_save) begin : carry_save_mult
                (* use_dsp = "no" *) wire signed[PROD-1:0] rr_a, ii_a, ri_a, ir_a;

                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH),
                    .CHUNK(CHUNK)
                ) u_carry_mult_1 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_re),
                    .b(w0re),
                    .product(rr_a),
                    .done()
                );

                (* use_dsp = "no" *)
                 Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH),
                    .CHUNK(CHUNK)
                ) u_carry_mult_2 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_im),
                    .b(w0im),
                    .product(ii_a),
                    .done()
                );

                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH),
                    .CHUNK(CHUNK)
                ) u_carry_mult_3 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_re),
                    .b(w0im),
                    .product(ri_a),
                    .done()
                );

                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH),
                    .CHUNK(CHUNK)
                ) u_carry_mult_4 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_im),
                    .b(w0re),
                    .product(ir_a),
                    .done()
                );

                always@(posedge clock) begin
                    out_a_re <= rr_a - ii_a;
                    out_a_im <= ri_a + ir_a;
                end
            end else begin : no_carry_save_mult
                reg signed[PROD-1:0] rr_a, ii_a, ri_a, ir_a;

                always@(posedge clock) begin
                    rr_a <= a_re * w0re;
                    ii_a <= a_im * w0im;
                    ri_a <= a_re * w0im;
                    ir_a <= a_im * w0re;

                    out_a_re <= rr_a - ii_a;
                    out_a_im <= ri_a + ir_a;
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
    parameter carry_save = 1,
    parameter CHUNK = 8
)(
    input  clock,
    input  signed [WIDTH-1:0]   a_re, a_im,
    input  signed [Tw_WIDTH-1:0] w0re, w0im,
    output reg signed [PROD:0] out_a_re, out_a_im
);
    generate 
        if (Fast_DSP) begin : fast_dsp
            (* use_dsp = "no" *) reg signed [WIDTH:0]     sum_a_s1;
            (* use_dsp = "no" *) reg signed [Tw_WIDTH:0]   sum_w0_s1, diff_w0_s1;

            reg signed [WIDTH-1:0]   a_re_s1, a_im_s1;
            reg signed [Tw_WIDTH-1:0] w0re_s1;

            reg signed [PROD:0]      k1_a_s2, k2_a_s2;
            
            reg signed [WIDTH-1:0]   a_im_s2;
            reg signed [Tw_WIDTH:0]   sum_w0_s2;

            reg signed [PROD:0]      k1_a_s3, k2_a_s3, k3_a_s3;
            reg signed [PROD:0] out_a_im_reg;
            reg signed [Tw_WIDTH-1:0]   w0_re_reg, w0_im_reg;
            reg signed [WIDTH-1:0] a_re_reg, a_im_reg;


            always @(posedge clock) begin
                w0_re_reg <= w0re;
                w0_im_reg <= w0im;
                a_re_reg <= a_re;
                a_im_reg <= a_im;

                // Stage 1 //
                // Channel A
                sum_a_s1   <= a_re_reg + a_im_reg;
                sum_w0_s1  <= w0_re_reg + w0_im_reg;
                diff_w0_s1 <= w0_im_reg - w0_re_reg;
                a_re_s1    <= a_re_reg;
                a_im_s1    <= a_im_reg;
                w0re_s1    <= w0_re_reg;

                // Stage 2 //
                // Channel A
                k1_a_s2   <= w0re_s1 * sum_a_s1;
                k2_a_s2   <= a_re_s1 * diff_w0_s1;
                
                a_im_s2   <= a_im_s1;
                sum_w0_s2 <= sum_w0_s1;

                // Stage 3 //
                // Channel A
                k3_a_s3 <= a_im_s2 * sum_w0_s2;
                
                out_a_im_reg <= k1_a_s2 + k2_a_s2;
                k1_a_s3 <= k1_a_s2;

                // Stage 4 //
                // Channel A
                out_a_re <= k1_a_s3 - k3_a_s3;
                out_a_im <= out_a_im_reg;
            end
        end else begin : slow_dsp
            if(carry_save) begin : carry_save_mult
                (* use_dsp = "no" *) reg signed [WIDTH:0]   sum_a_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] sum_w0_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] diff_w0_in;

                (* use_dsp = "no" *) reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH-1:0] w0re_d;

                (* use_dsp = "no" *) wire signed [PROD:0] k1_a, k2_a, k3_a;
                (* use_dsp = "no" *) reg signed [PROD:0] k1_a_reg;
                
                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH+1),
                    .B_WIDTH(Tw_WIDTH),
                    .CHUNK(CHUNK)
                ) u_carry_mult_1 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(sum_a_in),
                    .b(w0re_d),
                    .product(k1_a),
                    .done()
                );
                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH + 1),
                    .CHUNK(CHUNK)
                ) u_carry_mult_2 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_re_d),
                    .b(diff_w0_in),
                    .product(k2_a),
                    .done()
                );
                (* use_dsp = "no" *)
                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(Tw_WIDTH + 1),
                    .CHUNK(CHUNK)
                ) u_carry_mult_3 (
                    .clock(clock),
                    .reset(1'b0),
                    .start(1'b1),
                    .a(a_im_d),
                    .b(sum_w0_in),
                    .product(k3_a),
                    .done()
                );

                always @(posedge clock) begin
                    sum_a_in <= a_re + a_im;
                    sum_w0_in <= w0re + w0im;
                    diff_w0_in <= w0im - w0re;
                    a_re_d <= a_re;
                    a_im_d <= a_im;
                    w0re_d <= w0re;
                    
                    k1_a_reg <= k1_a;

                    out_a_re <= k1_a_reg - k3_a;
                    out_a_im <= k1_a_reg + k2_a;
                end
            end else begin : no_carry_save_mult
                (* use_dsp = "no" *) reg signed [WIDTH:0]   sum_a_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] sum_w0_in;
                (* use_dsp = "no" *) reg signed [Tw_WIDTH:0] diff_w0_in;

                reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                reg signed [Tw_WIDTH-1:0] w0re_d;

                reg signed [PROD:0] k1_a, k2_a, k3_a;

                always @(posedge clock) begin
                    sum_a_in <= a_re + a_im;
                    sum_w0_in <= w0re + w0im;
                    diff_w0_in <= w0im - w0re;
                    a_re_d <= a_re;
                    a_im_d <= a_im;
                    w0re_d <= w0re;

                    k1_a <= w0re_d * sum_a_in;
                    k2_a <= a_re_d * diff_w0_in;
                    k3_a <= a_im_d * sum_w0_in;

                    out_a_re <= k1_a - k3_a;
                    out_a_im <= k1_a + k2_a;
                end
            end
        end
    endgenerate
endmodule