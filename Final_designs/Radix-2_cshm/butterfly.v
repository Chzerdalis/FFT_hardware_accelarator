`timescale 1ns/1ps

(* use_dsp = "no" *)
module butterfly_radix_2_pipelined #(
    parameter WIDTH     = 32,
    // Tw_WIDTH is still the twiddle's numeric width: it sets the output
    // scaling in scale_product and the stage-1 pass-through shift. It must
    // match the bit_width the keys were encoded at (9).
    parameter Tw_WIDTH  = 9,
    parameter KEY_WIDTH = 14,
    parameter stage_num = 1
)(
    input                          clock,
    input                          reset,
    input                          start,
    input  signed [WIDTH-1:0]      ar, ai, br, bi,
    input  [KEY_WIDTH-1:0]         wr, wi,     // CSHM keys, not twiddle values
    output reg signed [WIDTH-1:0]  out1r, out1i, out2r, out2i,
    output wire                    done
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
    // Twiddle multiply
    // ------------------------------------------------------------
    wire signed [PROD-1:0] mr_full, mi_full;
    reg  signed [WIDTH-1:0] mr_reg, mi_reg;

    generate
        if (stage_num != 1) begin : stage_gen
            wire signed [PROD-1:0] r_out0, r_out1;   // br*wr, br*wi
            wire signed [PROD-1:0] i_out0, i_out1;   // bi*wr, bi*wi

            // Real-operand products
            cshm_2_keys #(
                .WIDTH(WIDTH),
                .Tw_WIDTH(Tw_WIDTH)
            ) u_cshm_r (
                .clock (clock),
                .a     (br),
                .key0  (wr),
                .key1  (wi),
                .out0  (r_out0),
                .out1  (r_out1)
            );

            // Imag-operand products (same keys)
            cshm_2_keys #(
                .WIDTH(WIDTH),
                .Tw_WIDTH(Tw_WIDTH)
            ) u_cshm_i (
                .clock (clock),
                .a     (bi),
                .key0  (wr),
                .key1  (wi),
                .out0  (i_out0),
                .out1  (i_out1)
            );

            // Combinational combine, so the multiply latency stays at
            // CSHM_LATENCY and mr_full/mi_full remain wires exactly as in
            // the original butterfly.
            assign mr_full = r_out0 - i_out1;   // br*wr - bi*wi
            assign mi_full = r_out1 + i_out0;   // br*wi + bi*wr
        end else begin : stage_1
            // Stage 1 has no twiddle multiply: pass b through with the same
            // scaling the multiply would have applied.
            assign mr_full = {{TW{br[WIDTH-1]}}, br} << (Tw_WIDTH - 1);
            assign mi_full = {{TW{bi[WIDTH-1]}}, bi} << (Tw_WIDTH - 1);
        end
    endgenerate

    // ------------------------------------------------------------
    // Matching delays for the a operand and the done strobe
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

    delay_reg_reset #(
        .WIDTH(1),
        .DELAY(delay_mult + 1 + 1)
    ) u_delay_start (
        .clock(clock),
        .reset(reset),
        .data_in(start),
        .data_out(done)
    );

    // ------------------------------------------------------------
    // Scale and combine
    // ------------------------------------------------------------
    always @(posedge clock) begin
        mr_reg <= scale_product(mr_full);
        mi_reg <= scale_product(mi_full);

        out1r <= ar_delayed + mr_reg;
        out1i <= ai_delayed + mi_reg;

        out2r <= ar_delayed - mr_reg;
        out2i <= ai_delayed - mi_reg;
    end

endmodule