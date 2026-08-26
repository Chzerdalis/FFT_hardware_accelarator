`timescale 1ns/1ps

`ifdef NO_DSP
    `define DSP_ATTR (* use_dsp = "no" *)
`else
    `define DSP_ATTR (* use_dsp = "yes" *)
`endif

module butterfly_radix_2_pipelined #(
    parameter WIDTH = 32,
    parameter Tw_WIDTH = 16,
    parameter SimpleMult = 0,
    parameter Fast_DSP = 0,
    parameter stage_num = 1,
    parameter carry_save = 0,
    parameter CHUNK = 8
)(  
    input                  clock,
    input                  reset,
    input                  start,
    input  signed [WIDTH-1:0]   ar, ai, br, bi,
    input  signed [Tw_WIDTH-1:0] wr, wi,
    output reg signed [WIDTH-1:0] out1r, out1i, out2r, out2i,
    output wire                  done
);  
    localparam TW = Tw_WIDTH;
    localparam PROD = WIDTH + TW;
    localparam CarrySavedelay_simple = (Tw_WIDTH + (Tw_WIDTH + WIDTH - 1)/CHUNK + 2);
    localparam CarrySavedelay_cheap = (Tw_WIDTH + 1 + (Tw_WIDTH + 1 + WIDTH - 1)/CHUNK + 2);
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
    // Complex Multiplier Instantiation (4 cycle latency)
    // ------------------------------------------------------------
    wire signed [PROD-1:0] mr_full, mi_full;
    reg signed  [WIDTH-1:0] mr_reg, mi_reg;

    generate
        if(stage_num != 1) begin : stage_gen
            if (SimpleMult) begin : simple_mult
                SimpleMult #(
                    .WIDTH(WIDTH),
                    .Tw_WIDTH(Tw_WIDTH),
                    .PROD(PROD),
                    .Fast_DSP(Fast_DSP),
                    .carry_save(carry_save),
                    .CHUNK(CHUNK)
                ) u_cmul (
                    .clock(clock),
                    .a_re(br),
                    .a_im(bi),
                    .w0re(wr),
                    .w0im(wi),
                    .out_a_re(mr_full),
                    .out_a_im(mi_full)
                );
            end else begin : cheap_mult
                CheapMult #(
                    .WIDTH(WIDTH),
                    .Tw_WIDTH(Tw_WIDTH),
                    .PROD(PROD),
                    .Fast_DSP(Fast_DSP),
                    .carry_save(carry_save),
                    .CHUNK(CHUNK)
                ) u_cmul (
                    .clock(clock),
                    .a_re(br),
                    .a_im(bi),
                    .w0re(wr),
                    .w0im(wi),
                    .out_a_re(mr_full),
                    .out_a_im(mi_full)
                );
            end
        end else begin : stage_1
                assign mr_full = {{TW{br[WIDTH-1]}}, br } << (Tw_WIDTH - 1);
                assign mi_full = {{TW{bi[WIDTH-1]}}, bi } << (Tw_WIDTH - 1);
        end
    endgenerate

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
        .DELAY(delay_mult+1+1)
    ) u_delay_start (
        .clock(clock),
        .reset(reset),
        .data_in(start),
        .data_out(done)
    );

    
        always @(posedge clock) begin
            mr_reg <= scale_product(mr_full);
            mi_reg <= scale_product(mi_full);

            out1r <= ar_delayed + mr_reg;
            out1i <= ai_delayed + mi_reg;
            
            out2r <= ar_delayed - mr_reg;
            out2i <= ai_delayed - mi_reg;
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