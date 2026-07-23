`timescale 1ns/1ps

module butterfly #(
    parameter   WIDTH = 32
)(
    input signed [WIDTH-1:0] ar, ai, br, bi,
    input signed [WIDTH/2-1:0] wr, wi,
    output signed [WIDTH-1:0] out1r, out1i, out2r, out2i
);
    wire signed [2*WIDTH-1:0] mr = br * wr - bi * wi;
    wire signed [2*WIDTH-1:0] mi = br * wi + bi * wr;

    assign out1r = ar + mr[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
    assign out1i = ai + mi[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
    assign out2r = ar - mr[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
    assign out2i = ai - mi[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
endmodule


module butterfly_radix_2_pipelined #(
    parameter WIDTH = 32
)(  
    input clock,
    input reset,
    input start,
    input signed [WIDTH-1:0] ar, ai, br, bi,
    input signed [WIDTH/2-1:0] wr, wi,
    output reg signed [WIDTH-1:0] out1r, out1i, out2r, out2i,
    output reg done
);  
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;

    //Input registers
    reg signed [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg;
    reg signed [WIDTH/2-1:0] wr_reg, wi_reg;
    reg start_1;

    //Multiplication registers
    reg signed [PROD-1:0] mr_1_reg, mi_1_reg, mr_2_reg, mi_2_reg;
    reg signed [WIDTH-1:0] ar_reg_2, ai_reg_2;
    reg start_2;

    //Product additions registers
    reg signed [PROD-1:0] mr_reg, mi_reg;
    reg signed [WIDTH-1:0] ar_reg_3, ai_reg_3;
    reg start_3;
    
    //Do one multiplication in one clock cycle per datapath
    wire signed [PROD-1:0] mr_1 = br_reg * wr_reg;
    wire signed [PROD-1:0] mi_1 = br_reg * wi_reg;
    wire signed [PROD-1:0] mr_2 = bi_reg * wi_reg;
    wire signed [PROD-1:0] mi_2 = bi_reg * wr_reg;

    //Do the product additions
    wire signed [PROD-1:0] mr = mr_1_reg - mr_2_reg;
    wire signed [PROD-1:0] mi = mi_1_reg + mi_2_reg;

    //Output registers
    wire signed [WIDTH-1:0] out1r_reg = ar_reg_3 + mr_reg[PROD-2 : TW-1];
    wire signed [WIDTH-1:0] out1i_reg = ai_reg_3 + mi_reg[PROD-2 : TW-1];
    wire signed [WIDTH-1:0] out2r_reg = ar_reg_3 - mr_reg[PROD-2 : TW-1];
    wire signed [WIDTH-1:0] out2i_reg = ai_reg_3 - mi_reg[PROD-2 : TW-1];

    always@(posedge clock) begin
        if (reset) begin
            ar_reg <= 0; ai_reg <= 0; br_reg <= 0; bi_reg <= 0;
            wr_reg <= 0; wi_reg <= 0;
            start_1 <= 0;

            mr_1_reg <= 0; mi_1_reg <= 0; mr_2_reg <= 0; mi_2_reg <= 0;
            ar_reg_2 <= 0; ai_reg_2 <= 0;
            start_2 <= 0;

            mr_reg <= 0; mi_reg <= 0;
            ar_reg_3 <= 0; ai_reg_3 <= 0;
            start_3 <= 0;

            out1i <= 0; out1r <= 0; out2i <= 0; out2r <= 0;
            done <= 0;
        end else begin
            //Stage 1: Register inputs and start signal
            ar_reg <= ar; ai_reg <= ai; br_reg <= br; bi_reg <= bi;
            wr_reg <= wr; wi_reg <= wi;
            start_1 <= start;
            //Stage 2: Register multiplication results and stage 1 registers
            mr_1_reg <= mr_1; mi_1_reg <= mi_1; mr_2_reg <= mr_2; mi_2_reg <= mi_2;
            ar_reg_2 <= ar_reg; ai_reg_2 <= ai_reg;
            start_2 <= start_1;
            //Stage 3: Register product additions results and stage 2 registers
            mr_reg <= mr; mi_reg <= mi;
            ar_reg_3 <= ar_reg_2; ai_reg_3 <= ai_reg_2;
            start_3 <= start_2;
            //Stage 4: Register outputs and stage 3 registers
            out1r <= out1r_reg; out1i <= out1i_reg; out2r <= out2r_reg; out2i <= out2i_reg;
            done <= start_3;
        end
    end

endmodule 

module butterfly_radix_2_pipelined_casc #(
    parameter WIDTH = 32
)(  
    input                  clock,
    input                  reset,
    input                  start,
    input  signed [WIDTH-1:0]   ar, ai, br, bi,
    input  signed [WIDTH/2-1:0] wr, wi,
    output reg signed [WIDTH-1:0] out1r, out1i, out2r, out2i,
    output reg                  done
);  
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;

    function signed [WIDTH-1:0] scale_product;
        input signed [PROD-1:0] x;
        begin
            scale_product = $signed(x[PROD-2:TW-1]);
        end
    endfunction

    // ------------------------------------------------------------
    // Complex Multiplier Instantiation (4 cycle latency)
    // ------------------------------------------------------------
    wire signed [PROD-1:0] mr_full, mi_full;

    complex_mult_2dsp_pipelined #(
        .WIDTH(WIDTH),
        .TW(TW),
        .PROD(PROD)
    ) u_cmul (
        .clock(clock),
        .xr(br),
        .xi(bi),
        .wr(wr),
        .wi(wi),
        .yr(mr_full),
        .yi(mi_full)
    );

    // ------------------------------------------------------------
    // Registered scaled products (1 cycle latency)
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] mr_s_reg, mi_s_reg;

    // ------------------------------------------------------------
    // Delay path for A 
    // Synchronizes the A inputs with the multiplier's pipeline
    // ------------------------------------------------------------
    reg signed [WIDTH-1:0] ar_d0, ai_d0;
    reg signed [WIDTH-1:0] ar_d1, ai_d1;
    reg signed [WIDTH-1:0] ar_d2, ai_d2;
    reg signed [WIDTH-1:0] ar_d3, ai_d3;
    reg signed [WIDTH-1:0] ar_d4, ai_d4;

    // New latency:
    // complex multiplier = 4 cycles (internal pipeline)
    // scaled product reg = 1 cycle
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
            out1r      <= 0;
            out1i      <= 0;
            out2r      <= 0;
            out2i      <= 0;
        end else begin
            valid_pipe <= {valid_pipe[4:0], start};
            done       <= valid_pipe[5];
            
            // --------------------------------------------------------
            // Datapath: Delay A path
            // --------------------------------------------------------
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
            // Datapath: Scale register stage
            // --------------------------------------------------------
            mr_s_reg <= scale_product(mr_full);
            mi_s_reg <= scale_product(mi_full);

            // --------------------------------------------------------
            // Final Radix-2 output stage (Butterfly Add/Sub)
            // --------------------------------------------------------
            out1r <= ar_d4 + mr_s_reg;
            out1i <= ai_d4 + mi_s_reg;
            
            out2r <= ar_d4 - mr_s_reg;
            out2i <= ai_d4 - mi_s_reg;
        end
    end

endmodule


// ------------------------------------------------------------
// Reused DSP Pipelined Multiplier
// ------------------------------------------------------------
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
    // ------------------------------------------------------------
    reg signed [PROD-1:0] real_prod_a_s2;
    reg signed [PROD-1:0] imag_prod_a_s2;

    (* use_dsp = "yes" *) reg signed [PROD-1:0] real_prod_b_s2;
    (* use_dsp = "yes" *) reg signed [PROD-1:0] imag_prod_b_s2;

    // ------------------------------------------------------------
    // Stage 3:
    // Final complex multiply add/sub.
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