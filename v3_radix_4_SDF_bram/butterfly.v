`timescale 1ns/1ps

module butterfly_radix4_pipeline #(
    parameter WIDTH = 16
) (
    input                  clock,
    input                  reset,
    input                  start,
    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    // Twiddle width is assumed to be WIDTH/2
    input  signed [WIDTH/2-1:0] w0r, w0i,
    input  signed [WIDTH/2-1:0] w1r, w1i,
    input  signed [WIDTH/2-1:0] w2r, w2i,

    output reg signed [WIDTH-1:0] out1r, out1i,
    output reg signed [WIDTH-1:0] out2r, out2i,
    output reg signed [WIDTH-1:0] out3r, out3i,
    output reg signed [WIDTH-1:0] out4r, out4i,
    output reg                  done
);
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW; // product width when multiplying data*twiddle
    
    //Original registers
    reg start_reg_0, start_reg_1, start_reg_2, start_reg_3;
    reg signed [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg, cr_reg, ci_reg, dr_reg, di_reg;
    reg signed [WIDTH/2-1:0] w0r_reg, w0i_reg, w1r_reg, w1i_reg, w2r_reg, w2i_reg;
    reg signed [WIDTH-1:0] ar_reg_0, ai_reg_0;
    reg signed [WIDTH-1:0] ar_reg_1, ai_reg_1;
    reg signed [PROD-1:0] m0r_reg, m0i_reg, m1r_reg, m1i_reg, m2r_reg, m2i_reg;
    reg signed [PROD-1:0] mul_m0r_reg_1, mul_m0i_reg_1, mul_m1r_reg_1, mul_m1i_reg_1, mul_m2r_reg_1, mul_m2i_reg_1;
    reg signed [PROD-1:0] mul_m0r_reg_2, mul_m0i_reg_2, mul_m1r_reg_2, mul_m1i_reg_2, mul_m2r_reg_2, mul_m2i_reg_2;
    reg signed [WIDTH-1:0] t0r_reg, t0i_reg, t1r_reg, t1i_reg, t2r_reg, t2i_reg, t3r_reg, t3i_reg;

    //Do one multimplication per clock cycle per dedicated data path
    wire signed [PROD-1:0] mul_m0r_1 = br_reg * w0r_reg;
    wire signed [PROD-1:0] mul_m0i_1 = br_reg * w0i_reg;
    wire signed [PROD-1:0] mul_m1r_1 = cr_reg * w1r_reg;
    wire signed [PROD-1:0] mul_m1i_1 = cr_reg * w1i_reg;
    wire signed [PROD-1:0] mul_m2r_1 = dr_reg * w2r_reg;
    wire signed [PROD-1:0] mul_m2i_1 = dr_reg * w2i_reg;

    wire signed [PROD-1:0] mul_m0r_2 = bi_reg * w0i_reg;
    wire signed [PROD-1:0] mul_m0i_2 = bi_reg * w0r_reg;
    wire signed [PROD-1:0] mul_m1r_2 = ci_reg * w1i_reg;
    wire signed [PROD-1:0] mul_m1i_2 = ci_reg * w1r_reg;
    wire signed [PROD-1:0] mul_m2r_2 = di_reg * w2i_reg;
    wire signed [PROD-1:0] mul_m2i_2 = di_reg * w2r_reg;

    //One addition/subtraction per clock cycle per data path to find m0, m1, m2
    wire signed [PROD-1:0] m0r = mul_m0r_reg_1 - mul_m0r_reg_2;
    wire signed [PROD-1:0] m0i = mul_m0i_reg_1 + mul_m0i_reg_2;

    wire signed [PROD-1:0] m1r = mul_m1r_reg_1 - mul_m1r_reg_2;
    wire signed [PROD-1:0] m1i = mul_m1i_reg_1 + mul_m1i_reg_2;

    wire signed [PROD-1:0] m2r = mul_m2r_reg_1 - mul_m2r_reg_2;
    wire signed [PROD-1:0] m2i = mul_m2i_reg_1 + mul_m2i_reg_2;

    //One addition/subtraction per clock cycle per data path to find t0, t1, t2, t3
    wire signed [WIDTH-1:0] t0r = ar_reg_1 + m1r_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t0i = ai_reg_1 + m1i_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t1r = ar_reg_1 - m1r_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t1i = ai_reg_1 - m1i_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t2r = m0r_reg[PROD-2:TW-1] + m2r_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t2i = m0i_reg[PROD-2:TW-1] + m2i_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t3r = m0r_reg[PROD-2:TW-1] - m2r_reg[PROD-2:TW-1];
    wire signed [WIDTH-1:0] t3i = m0i_reg[PROD-2:TW-1] - m2i_reg[PROD-2:TW-1];

    // Output assignments
    wire signed [WIDTH-1:0] out1r_reg = t0r_reg + t2r_reg;
    wire signed [WIDTH-1:0] out1i_reg = t0i_reg + t2i_reg;
    wire signed [WIDTH-1:0] out2r_reg = t1r_reg + t3i_reg;
    wire signed [WIDTH-1:0] out2i_reg = t1i_reg - t3r_reg;
    wire signed [WIDTH-1:0] out3r_reg = t0r_reg - t2r_reg;
    wire signed [WIDTH-1:0] out3i_reg = t0i_reg - t2i_reg;
    wire signed [WIDTH-1:0] out4r_reg = t1r_reg - t3i_reg;
    wire signed [WIDTH-1:0] out4i_reg = t1i_reg + t3r_reg;


    always @(posedge clock) begin
        if (reset) begin
            //Input registers
            ar_reg <= 0; ai_reg <= 0; br_reg <= 0; bi_reg <= 0;
            cr_reg <= 0; ci_reg <= 0; dr_reg <= 0; di_reg <= 0;
            w0r_reg <= 0; w0i_reg <= 0;
            w1r_reg <= 0; w1i_reg <= 0;
            w2r_reg <= 0; w2i_reg <= 0;
            start_reg_0 <= 0;
            //First pipeline stage registers
            mul_m0r_reg_1 <= 0;  mul_m0i_reg_1 <= 0;
            mul_m1r_reg_1 <= 0;  mul_m1i_reg_1 <= 0;
            mul_m2r_reg_1 <= 0;  mul_m2i_reg_1 <= 0; 
            mul_m0r_reg_2 <= 0;  mul_m0i_reg_2 <= 0; 
            mul_m1r_reg_2 <= 0;  mul_m1i_reg_2 <= 0;
            mul_m2r_reg_2 <= 0;  mul_m2i_reg_2 <= 0;
            ar_reg_0 <= 0; ai_reg_0 <= 0;
            start_reg_1 <= 0;
            //Second pipeline stage registers
            m0i_reg <= 0; m0r_reg <= 0;
            m1i_reg <= 0; m1r_reg <= 0;
            m2i_reg <= 0; m2r_reg <= 0;
            ar_reg_1 <= 0; ai_reg_1 <= 0;
            start_reg_2 <= 0;
            //Third pipeline stage registers
            t0r_reg <= 0; t0i_reg <= 0;
            t1r_reg <= 0; t1i_reg <= 0;
            t2r_reg <= 0; t2i_reg <= 0;
            t3r_reg <= 0; t3i_reg <= 0;
            start_reg_3 <= 0;
            //Output registers
            out1r <= 0; out1i <= 0;
            out2r <= 0; out2i <= 0;
            out3r <= 0; out3i <= 0;
            out4r <= 0; out4i <= 0;
            done <= 0;
        end else begin
            ar_reg <= ar; ai_reg <= ai; br_reg <= br; bi_reg <= bi;
            cr_reg <= cr; ci_reg <= ci; dr_reg <= dr; di_reg <= di;
            w0r_reg <= w0r; w0i_reg <= w0i;
            w1r_reg <= w1r; w1i_reg <= w1i;
            w2r_reg <= w2r; w2i_reg <= w2i;
            start_reg_0 <= start;

            mul_m0r_reg_1 <= mul_m0r_1; mul_m0i_reg_1 <= mul_m0i_1;
            mul_m1r_reg_1 <= mul_m1r_1; mul_m1i_reg_1 <= mul_m1i_1;
            mul_m2r_reg_1 <= mul_m2r_1; mul_m2i_reg_1 <= mul_m2i_1;
            mul_m0r_reg_2 <= mul_m0r_2; mul_m0i_reg_2 <= mul_m0i_2;
            mul_m1r_reg_2 <= mul_m1r_2; mul_m1i_reg_2 <= mul_m1i_2;
            mul_m2r_reg_2 <= mul_m2r_2; mul_m2i_reg_2 <= mul_m2i_2;
            ar_reg_0 <= ar_reg; ai_reg_0 <= ai_reg;
            start_reg_1 <= start_reg_0;

            m0i_reg <= m0i; m0r_reg <= m0r;
            m1i_reg <= m1i; m1r_reg <= m1r;
            m2i_reg <= m2i; m2r_reg <= m2r;
            ar_reg_1 <= ar_reg_0; ai_reg_1 <= ai_reg_0;
            start_reg_2 <= start_reg_1;

            t0r_reg <= t0r; t0i_reg <= t0i;
            t1r_reg <= t1r; t1i_reg <= t1i;
            t2r_reg <= t2r; t2i_reg <= t2i;
            t3r_reg <= t3r; t3i_reg <= t3i;
            start_reg_3 <= start_reg_2;

            out1r <= out1r_reg; out1i <= out1i_reg;
            out2r <= out2r_reg; out2i <= out2i_reg;
            out3r <= out3r_reg; out3i <= out3i_reg;
            out4r <= out4r_reg; out4i <= out4i_reg;
            done <= start_reg_3;
        end
    end
endmodule

// ============================================================
// Complex multiplier using 2 DSPs per real/imag result:
//
// real = xr*wr - xi*wi
// imag = xr*wi + xi*wr
//
// Important:
// The second product is delayed by one cycle so the DSP can use
// its internal MREG/PREG pipeline.
// ============================================================
//(* use_dsp = "yes", keep_hierarchy = "yes" *)
(* use_dsp = "yes" *)
module complex_mult_2dsp_pipelined #(
    parameter WIDTH = 16,
    parameter TW    = 8,
    parameter PROD  = WIDTH + TW
)(
    input  wire clock,

    input  wire signed [WIDTH-1:0] xr,
    input  wire signed [WIDTH-1:0] xi,
    input  wire signed [TW-1:0]    wr,
    input  wire signed [TW-1:0]    wi,

    output reg  signed [PROD-1:0]  yr,
    output reg  signed [PROD-1:0]  yi
);

    // ------------------------------------------------------------
    // Stage 0: input registers
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] xr_s0;
    reg signed [WIDTH-1:0] xi_s0;
    reg signed [TW-1:0]    wr_s0;
    reg signed [TW-1:0]    wi_s0;

    // ------------------------------------------------------------
    // Stage 1:
    // First products:
    //   real first product = xr*wr
    //   imag first product = xr*wi
    //
    // Also delay xi/wr/wi for the second DSP stage.
    // ------------------------------------------------------------
    (* use_dsp = "yes" *) reg signed [PROD-1:0] real_prod_a_s1;
    (* use_dsp = "yes" *) reg signed [PROD-1:0] imag_prod_a_s1;

    reg signed [WIDTH-1:0] xi_s1;
    reg signed [TW-1:0]    wr_s1;
    reg signed [TW-1:0]    wi_s1;

    // ------------------------------------------------------------
    // Stage 2:
    // Second products:
    //   real second product = xi*wi
    //   imag second product = xi*wr
    //
    // Also delay first products to align.
    // ------------------------------------------------------------
    reg signed [PROD-1:0] real_prod_a_s2;
    reg signed [PROD-1:0] imag_prod_a_s2;

    (* use_dsp = "yes" *) reg signed [PROD-1:0] real_prod_b_s2;
    (* use_dsp = "yes" *) reg signed [PROD-1:0] imag_prod_b_s2;

    // ------------------------------------------------------------
    // Stage 3:
    // Final complex multiply add/sub.
    // Vivado should try to keep this in the second DSP ALU/PREG.
    // ------------------------------------------------------------
    always @(posedge clock) begin
        // Stage 0
        xr_s0 <= xr;
        xi_s0 <= xi;
        wr_s0 <= wr;
        wi_s0 <= wi;

        // Stage 1
        real_prod_a_s1 <= xr_s0 * wr_s0;
        imag_prod_a_s1 <= xr_s0 * wi_s0;

        xi_s1 <= xi_s0;
        wr_s1 <= wr_s0;
        wi_s1 <= wi_s0;

        // Stage 2
        real_prod_a_s2 <= real_prod_a_s1;
        imag_prod_a_s2 <= imag_prod_a_s1;

        real_prod_b_s2 <= xi_s1 * wi_s1;
        imag_prod_b_s2 <= xi_s1 * wr_s1;

        // Stage 3
        yr <= real_prod_a_s2 - real_prod_b_s2;
        yi <= imag_prod_a_s2 + imag_prod_b_s2;
    end

endmodule


// ============================================================
// Optimized radix-4 butterfly
// ============================================================
//This cascades correcly the Dsps 
module butterfly_radix4_pipeline_2dsp_fast #(
    parameter WIDTH = 16
)(
    input                  clock,
    input                  reset,
    input                  start,

    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    input  signed [WIDTH/2-1:0] w0r, w0i,
    input  signed [WIDTH/2-1:0] w1r, w1i,
    input  signed [WIDTH/2-1:0] w2r, w2i,

    output reg signed [WIDTH-1:0] out1r, out1i,
    output reg signed [WIDTH-1:0] out2r, out2i,
    output reg signed [WIDTH-1:0] out3r, out3i,
    output reg signed [WIDTH-1:0] out4r, out4i,
    output reg                   done
);

    localparam TW   = WIDTH / 2;
    localparam PROD = WIDTH + TW;

    function signed [WIDTH-1:0] scale_product;
        input signed [PROD-1:0] x;
        begin
            scale_product = $signed(x[PROD-2:TW-1]);
        end
    endfunction

    wire signed [PROD-1:0] m0r_full, m0i_full;
    wire signed [PROD-1:0] m1r_full, m1i_full;
    wire signed [PROD-1:0] m2r_full, m2i_full;

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul0 (
        .clock(clock),
        .xr(br),
        .xi(bi),
        .wr(w0r),
        .wi(w0i),
        .yr(m0r_full),
        .yi(m0i_full)
    );

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul1 (
        .clock(clock),
        .xr(cr),
        .xi(ci),
        .wr(w1r),
        .wi(w1i),
        .yr(m1r_full),
        .yi(m1i_full)
    );

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul2 (
        .clock(clock),
        .xr(dr),
        .xi(di),
        .wr(w2r),
        .wi(w2i),
        .yr(m2r_full),
        .yi(m2i_full)
    );

    // ------------------------------------------------------------
    // Registered scaled products
    // This is the stage I forgot before.
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] m0r_s_reg, m0i_s_reg;
    reg signed [WIDTH-1:0] m1r_s_reg, m1i_s_reg;
    reg signed [WIDTH-1:0] m2r_s_reg, m2i_s_reg;

    // ------------------------------------------------------------
    // Delay A path.
    //
    // Extra scale register stage means A needs one more delay.
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] ar_d0, ai_d0;
    reg signed [WIDTH-1:0] ar_d1, ai_d1;
    reg signed [WIDTH-1:0] ar_d2, ai_d2;
    reg signed [WIDTH-1:0] ar_d3, ai_d3;
    reg signed [WIDTH-1:0] ar_d4, ai_d4;

    // ------------------------------------------------------------
    // Butterfly intermediate registers
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] t0r, t0i;
    reg signed [WIDTH-1:0] t1r, t1i;
    reg signed [WIDTH-1:0] t2r, t2i;
    reg signed [WIDTH-1:0] t3r, t3i;

    // New latency:
    // complex multiplier = 3 cycles
    // scaled product reg = 1 cycle
    // t stage            = 1 cycle
    // output stage       = 1 cycle
    //
    // total = 6 cycles
    reg [5:0] valid_pipe;

    always @(posedge clock) begin
        // --------------------------------------------------------
        // Reset only control
        // --------------------------------------------------------
        if (reset) begin
            valid_pipe <= 6'b000000;
            done       <= 1'b0;
        end else begin
            valid_pipe <= {valid_pipe[4:0], start};
            done       <= valid_pipe[5];
        end

        // --------------------------------------------------------
        // Datapath: no reset
        // --------------------------------------------------------

        // Delay A path
        ar_d0 <= ar;
        ai_d0 <= ai;

        ar_d1 <= ar_d0;
        ai_d1 <= ai_d0;

        ar_d2 <= ar_d1;
        ai_d2 <= ai_d1;

        ar_d3 <= ar_d2;
        ai_d3 <= ai_d2;

        ar_d4 <= ar_d3;
        ai_d4 <= ai_d3;

        // --------------------------------------------------------
        // Scale register stage
        // --------------------------------------------------------
        m0r_s_reg <= scale_product(m0r_full);
        m0i_s_reg <= scale_product(m0i_full);

        m1r_s_reg <= scale_product(m1r_full);
        m1i_s_reg <= scale_product(m1i_full);

        m2r_s_reg <= scale_product(m2r_full);
        m2i_s_reg <= scale_product(m2i_full);

        // --------------------------------------------------------
        // Radix-4 intermediate stage
        // Now uses registered scaled products.
        // --------------------------------------------------------
        t0r <= ar_d4 + m1r_s_reg;
        t0i <= ai_d4 + m1i_s_reg;

        t1r <= ar_d4 - m1r_s_reg;
        t1i <= ai_d4 - m1i_s_reg;

        t2r <= m0r_s_reg + m2r_s_reg;
        t2i <= m0i_s_reg + m2i_s_reg;

        t3r <= m0r_s_reg - m2r_s_reg;
        t3i <= m0i_s_reg - m2i_s_reg;

        // --------------------------------------------------------
        // Final radix-4 output stage
        // --------------------------------------------------------
        out1r <= t0r + t2r;
        out1i <= t0i + t2i;

        out2r <= t1r + t3i;
        out2i <= t1i - t3r;

        out3r <= t0r - t2r;
        out3i <= t0i - t2i;

        out4r <= t1r - t3i;
        out4i <= t1i + t3r;
    end

endmodule

//This adds extra registers on the input 
//No noticable change
module butterfly_radix4_pipeline_2dsp_fast_extra_input_pipeline #(
    parameter WIDTH = 16
)(
    input                  clock,
    input                  reset,
    input                  start,

    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    input  signed [WIDTH/2-1:0] w0r, w0i,
    input  signed [WIDTH/2-1:0] w1r, w1i,
    input  signed [WIDTH/2-1:0] w2r, w2i,

    output reg signed [WIDTH-1:0] out1r, out1i,
    output reg signed [WIDTH-1:0] out2r, out2i,
    output reg signed [WIDTH-1:0] out3r, out3i,
    output reg signed [WIDTH-1:0] out4r, out4i,
    output reg                   done
);

    localparam TW   = WIDTH / 2;
    localparam PROD = WIDTH + TW;

    function signed [WIDTH-1:0] scale_product;
        input signed [PROD-1:0] x;
        begin
            scale_product = $signed(x[PROD-2:TW-1]);
        end
    endfunction

    // ============================================================
    // NEW EXTERNAL INPUT REGISTERS
    // These force a real pipeline cut before the DSP path.
    // ============================================================

//    (* dont_touch = "true", shreg_extract = "no" *)
    reg signed [WIDTH-1:0] ar_reg, ai_reg;

    reg signed [WIDTH-1:0] br_reg, bi_reg;

    reg signed [WIDTH-1:0] cr_reg, ci_reg;

    reg signed [WIDTH-1:0] dr_reg, di_reg;

    reg signed [TW-1:0] w0r_reg, w0i_reg;

    reg signed [TW-1:0] w1r_reg, w1i_reg;

    reg signed [TW-1:0] w2r_reg, w2i_reg;

    // ============================================================
    // Complex multiplier outputs
    // ============================================================

    wire signed [PROD-1:0] m0r_full, m0i_full;
    wire signed [PROD-1:0] m1r_full, m1i_full;
    wire signed [PROD-1:0] m2r_full, m2i_full;

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul0 (
        .clock(clock),
        .xr(br_reg),
        .xi(bi_reg),
        .wr(w0r_reg),
        .wi(w0i_reg),
        .yr(m0r_full),
        .yi(m0i_full)
    );

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul1 (
        .clock(clock),
        .xr(cr_reg),
        .xi(ci_reg),
        .wr(w1r_reg),
        .wi(w1i_reg),
        .yr(m1r_full),
        .yi(m1i_full)
    );

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul2 (
        .clock(clock),
        .xr(dr_reg),
        .xi(di_reg),
        .wr(w2r_reg),
        .wi(w2i_reg),
        .yr(m2r_full),
        .yi(m2i_full)
    );

    // ============================================================
    // Scale registers
    // ============================================================

    reg signed [WIDTH-1:0] m0r_s_reg, m0i_s_reg;
    reg signed [WIDTH-1:0] m1r_s_reg, m1i_s_reg;
    reg signed [WIDTH-1:0] m2r_s_reg, m2i_s_reg;

    // ============================================================
    // Delay A path
    //
    // ar_reg/ai_reg is the new input register.
    // Then ar_d0..ar_d4 align A with the complex multiplier outputs.
    // ============================================================

    reg signed [WIDTH-1:0] ar_d0, ai_d0;
    reg signed [WIDTH-1:0] ar_d1, ai_d1;
    reg signed [WIDTH-1:0] ar_d2, ai_d2;
    reg signed [WIDTH-1:0] ar_d3, ai_d3;
    reg signed [WIDTH-1:0] ar_d4, ai_d4;

    // ============================================================
    // Butterfly intermediate registers
    // ============================================================

    reg signed [WIDTH-1:0] t0r, t0i;
    reg signed [WIDTH-1:0] t1r, t1i;
    reg signed [WIDTH-1:0] t2r, t2i;
    reg signed [WIDTH-1:0] t3r, t3i;

    // ============================================================
    // Valid pipeline
    //
    // external input register  = 1 cycle
    // complex multiplier       = 3 cycles
    // scale register           = 1 cycle
    // t stage                  = 1 cycle
    // output stage             = 1 cycle
    //
    // total latency            = 7 cycles
    // ============================================================

    reg [6:0] valid_pipe;

    always @(posedge clock) begin
        // --------------------------------------------------------
        // Reset only control
        // --------------------------------------------------------
        if (reset) begin
            valid_pipe <= 7'b0;
            done       <= 1'b0;
        end else begin
            valid_pipe <= {valid_pipe[5:0], start};
            done       <= valid_pipe[6];
        end

        // --------------------------------------------------------
        // External input register stage
        // No reset on datapath registers.
        // --------------------------------------------------------

        ar_reg <= ar;
        ai_reg <= ai;

        br_reg <= br;
        bi_reg <= bi;

        cr_reg <= cr;
        ci_reg <= ci;

        dr_reg <= dr;
        di_reg <= di;

        w0r_reg <= w0r;
        w0i_reg <= w0i;

        w1r_reg <= w1r;
        w1i_reg <= w1i;

        w2r_reg <= w2r;
        w2i_reg <= w2i;

        // --------------------------------------------------------
        // A-path delay
        // --------------------------------------------------------

        ar_d0 <= ar_reg;
        ai_d0 <= ai_reg;

        ar_d1 <= ar_d0;
        ai_d1 <= ai_d0;

        ar_d2 <= ar_d1;
        ai_d2 <= ai_d1;

        ar_d3 <= ar_d2;
        ai_d3 <= ai_d2;

        ar_d4 <= ar_d3;
        ai_d4 <= ai_d3;

        // --------------------------------------------------------
        // Scale complex multiplier outputs
        // --------------------------------------------------------

        m0r_s_reg <= scale_product(m0r_full);
        m0i_s_reg <= scale_product(m0i_full);

        m1r_s_reg <= scale_product(m1r_full);
        m1i_s_reg <= scale_product(m1i_full);

        m2r_s_reg <= scale_product(m2r_full);
        m2i_s_reg <= scale_product(m2i_full);

        // --------------------------------------------------------
        // Radix-4 intermediate stage
        // --------------------------------------------------------

        t0r <= ar_d4 + m1r_s_reg;
        t0i <= ai_d4 + m1i_s_reg;

        t1r <= ar_d4 - m1r_s_reg;
        t1i <= ai_d4 - m1i_s_reg;

        t2r <= m0r_s_reg + m2r_s_reg;
        t2i <= m0i_s_reg + m2i_s_reg;

        t3r <= m0r_s_reg - m2r_s_reg;
        t3i <= m0i_s_reg - m2i_s_reg;

        // --------------------------------------------------------
        // Final output stage
        // --------------------------------------------------------

        out1r <= t0r + t2r;
        out1i <= t0i + t2i;

        out2r <= t1r + t3i;
        out2i <= t1i - t3r;

        out3r <= t0r - t2r;
        out3i <= t0i - t2i;

        out4r <= t1r - t3i;
        out4i <= t1i + t3r;
    end

endmodule

