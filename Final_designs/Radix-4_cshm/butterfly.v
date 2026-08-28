`timescale 1ns/1ps

(* use_dsp = "no" *)
module butterfly_radix4_pipeline #(
    parameter WIDTH     = 32,
    // Tw_WIDTH is still the twiddle's numeric width: it sets the output
    // scaling in scale_product and the stage-1 pass-through shift. It must
    // match the bit_width the keys were encoded at (9). PROD = WIDTH + 9 = 25
    // for WIDTH=16, which is exactly what the worst-case product needs.
    parameter Tw_WIDTH  = 9,
    parameter KEY_WIDTH = 14,
    parameter stage_num = 1
)(
    input                  clock,
    input                  reset,
    input                  start,

    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    // CSHM keys, not twiddle values
    input  [KEY_WIDTH-1:0] w0r, w0i,
    input  [KEY_WIDTH-1:0] w1r, w1i,
    input  [KEY_WIDTH-1:0] w2r, w2i,

    output reg signed [WIDTH-1:0] out1r, out1i,
    output reg signed [WIDTH-1:0] out2r, out2i,
    output reg signed [WIDTH-1:0] out3r, out3i,
    output reg signed [WIDTH-1:0] out4r, out4i,
    output wire                   done
);

    localparam TW   = Tw_WIDTH;
    localparam PROD = WIDTH + TW;

    // cshm_2_keys latency, in clocks:
    //   1 a_q1/key_q1  2 alphabet/key_q2  3 slot_q3/key_q3
    //   4 shift_out_q4/sign_q4            5 out0/out1
    localparam CSHM_LATENCY = 5;
    localparam delay_mult   = (stage_num != 1) ? CSHM_LATENCY : 0;

    function signed [WIDTH-1:0] scale_product;
        input signed [PROD-1:0] x;
        begin
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

            wire signed [PROD-1:0] b_r_out0, b_r_out1, b_i_out0, b_i_out1;
            wire signed [PROD-1:0] c_r_out0, c_r_out1, c_i_out0, c_i_out1;
            wire signed [PROD-1:0] d_r_out0, d_r_out1, d_i_out0, d_i_out1;

            // ---- b * W0 --------------------------------------------------
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_bR (
                .clock(clock), .a(br), .key0(w0r), .key1(w0i),
                .out0(b_r_out0), .out1(b_r_out1)          // br*w0r, br*w0i
            );
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_bI (
                .clock(clock), .a(bi), .key0(w0r), .key1(w0i),
                .out0(b_i_out0), .out1(b_i_out1)          // bi*w0r, bi*w0i
            );
            assign m0r_full = b_r_out0 - b_i_out1;        // br*w0r - bi*w0i
            assign m0i_full = b_r_out1 + b_i_out0;        // br*w0i + bi*w0r

            // ---- c * W1 --------------------------------------------------
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_cR (
                .clock(clock), .a(cr), .key0(w1r), .key1(w1i),
                .out0(c_r_out0), .out1(c_r_out1)
            );
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_cI (
                .clock(clock), .a(ci), .key0(w1r), .key1(w1i),
                .out0(c_i_out0), .out1(c_i_out1)
            );
            assign m1r_full = c_r_out0 - c_i_out1;
            assign m1i_full = c_r_out1 + c_i_out0;

            // ---- d * W2 --------------------------------------------------
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_dR (
                .clock(clock), .a(dr), .key0(w2r), .key1(w2i),
                .out0(d_r_out0), .out1(d_r_out1)
            );
            cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) u_cshm_dI (
                .clock(clock), .a(di), .key0(w2r), .key1(w2i),
                .out0(d_i_out0), .out1(d_i_out1)
            );
            assign m2r_full = d_r_out0 - d_i_out1;
            assign m2i_full = d_r_out1 + d_i_out0;

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