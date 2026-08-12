`timescale 1ns/1ps

// module butterfly #(
//     parameter   WIDTH = 32
// )(
//     input signed [WIDTH-1:0] ar, ai, br, bi,
//     input signed [WIDTH/2-1:0] wr, wi,
//     output signed [WIDTH-1:0] out1r, out1i, out2r, out2i
// );
//     wire signed [2*WIDTH-1:0] mr = br * wr - bi * wi;
//     wire signed [2*WIDTH-1:0] mi = br * wi + bi * wr;

//     assign out1r = ar + mr[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
//     assign out1i = ai + mi[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
//     assign out2r = ar - mr[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
//     assign out2i = ai - mi[WIDTH/2 + WIDTH-2 : WIDTH/2-1];
// endmodule


// module butterfly_radix_2_pipelined_og #(
//     parameter WIDTH = 32
// )(  
//     input clock,
//     input reset,
//     input start,
//     input signed [WIDTH-1:0] ar, ai, br, bi,
//     input signed [WIDTH/2-1:0] wr, wi,
//     output reg signed [WIDTH-1:0] out1r, out1i, out2r, out2i,
//     output reg done
// );  
//     localparam TW = WIDTH/2;
//     localparam PROD = WIDTH + TW;

//     //Input registers
//     reg signed [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg;
//     reg signed [WIDTH/2-1:0] wr_reg, wi_reg;
//     reg start_1;

//     //Multiplication registers
//     reg signed [PROD-1:0] mr_1_reg, mi_1_reg, mr_2_reg, mi_2_reg;
//     reg signed [WIDTH-1:0] ar_reg_2, ai_reg_2;
//     reg start_2;

//     //Product additions registers
//     reg signed [PROD-1:0] mr_reg, mi_reg;
//     reg signed [WIDTH-1:0] ar_reg_3, ai_reg_3;
//     reg start_3;
    
//     //Do one multiplication in one clock cycle per datapath
//     wire signed [PROD-1:0] mr_1 = br_reg * wr_reg;
//     wire signed [PROD-1:0] mi_1 = br_reg * wi_reg;
//     wire signed [PROD-1:0] mr_2 = bi_reg * wi_reg;
//     wire signed [PROD-1:0] mi_2 = bi_reg * wr_reg;

//     //Do the product additions
//     wire signed [PROD-1:0] mr = mr_1_reg - mr_2_reg;
//     wire signed [PROD-1:0] mi = mi_1_reg + mi_2_reg;

//     //Output registers
//     wire signed [WIDTH-1:0] out1r_reg = ar_reg_3 + mr_reg[PROD-2 : TW-1];
//     wire signed [WIDTH-1:0] out1i_reg = ai_reg_3 + mi_reg[PROD-2 : TW-1];
//     wire signed [WIDTH-1:0] out2r_reg = ar_reg_3 - mr_reg[PROD-2 : TW-1];
//     wire signed [WIDTH-1:0] out2i_reg = ai_reg_3 - mi_reg[PROD-2 : TW-1];

//     always@(posedge clock) begin
//         if (reset) begin
//             ar_reg <= 0; ai_reg <= 0; br_reg <= 0; bi_reg <= 0;
//             wr_reg <= 0; wi_reg <= 0;
//             start_1 <= 0;

//             mr_1_reg <= 0; mi_1_reg <= 0; mr_2_reg <= 0; mi_2_reg <= 0;
//             ar_reg_2 <= 0; ai_reg_2 <= 0;
//             start_2 <= 0;

//             mr_reg <= 0; mi_reg <= 0;
//             ar_reg_3 <= 0; ai_reg_3 <= 0;
//             start_3 <= 0;

//             out1i <= 0; out1r <= 0; out2i <= 0; out2r <= 0;
//             done <= 0;
//         end else begin
//             //Stage 1: Register inputs and start signal
//             ar_reg <= ar; ai_reg <= ai; br_reg <= br; bi_reg <= bi;
//             wr_reg <= wr; wi_reg <= wi;
//             start_1 <= start;
//             //Stage 2: Register multiplication results and stage 1 registers
//             mr_1_reg <= mr_1; mi_1_reg <= mi_1; mr_2_reg <= mr_2; mi_2_reg <= mi_2;
//             ar_reg_2 <= ar_reg; ai_reg_2 <= ai_reg;
//             start_2 <= start_1;
//             //Stage 3: Register product additions results and stage 2 registers
//             mr_reg <= mr; mi_reg <= mi;
//             ar_reg_3 <= ar_reg_2; ai_reg_3 <= ai_reg_2;
//             start_3 <= start_2;
//             //Stage 4: Register outputs and stage 3 registers
//             out1r <= out1r_reg; out1i <= out1i_reg; out2r <= out2r_reg; out2i <= out2i_reg;
//             done <= start_3;
//         end
//     end
// endmodule 

module butterfly_radix_2_pipelined #(
    parameter WIDTH = 32,
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
    input  signed [WIDTH/2-1:0] wr, wi,
    output reg signed [WIDTH-1:0] out1r, out1i, out2r, out2i,
    output reg                  done
);  
    localparam TW = WIDTH/2;
    localparam PROD = WIDTH + TW;
    localparam CarrySavedelay_simple = (WIDTH/2 + (WIDTH/2 + WIDTH)/CHUNK + 2);
    localparam CarrySavedelay_cheap = (WIDTH/2 + (WIDTH/2 + WIDTH)/CHUNK + 3);
    localparam delay_mult = (stage_num != 1) ? ((Fast_DSP == 1) ? 3 : 2) + (SimpleMult == 1 ? 0 : 1) + 
    (carry_save == 1 ? (SimpleMult == 1 ? CarrySavedelay_simple : CarrySavedelay_cheap) : 0) : 0;
    

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

    generate
        if(stage_num != 1) begin : stage_gen
            if (SimpleMult) begin : simple_mult
                SimpleMult #(
                    .WIDTH(WIDTH),
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
                assign mr_full = br << (WIDTH-1)/2;
                assign mi_full = bi << (WIDTH-1)/2;
        end
    endgenerate

    reg [WIDTH-1:0] ar_delayed, ai_delayed;

    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(delay_mult)
    ) u_delay_a (
        .clock(clock),
        .data_in(ar),
        .data_out(ar_delayed)
    );

    delay_reg #(
        .WIDTH(WIDTH),
        .DELAY(delay_mult)
    ) u_delay_ai (
        .clock(clock),
        .data_in(ai),
        .data_out(ai_delayed)
    );


    delay_reg_reset #(
        .WIDTH(1),
        .DELAY(delay_mult+1)
    ) u_delay_start (
        .clock(clock),
        .reset(reset),
        .data_in(start),
        .data_out(done)
    );


    always @(posedge clock) begin
        out1r <= ar_delayed + scale_product(mr_full);
        out1i <= ai_delayed + scale_product(mi_full);
        
        out2r <= ar_delayed - scale_product(mr_full);
        out2i <= ai_delayed - scale_product(mi_full);
    end

endmodule

module SimpleMult #(
    parameter WIDTH = 16,
    parameter PROD = 32,
    parameter Fast_DSP = 1,
    parameter carry_save = 1,
    parameter CHUNK = 8
)(
    input clock,
    input signed[WIDTH-1:0] a_re, a_im,
    input signed [WIDTH/2 -1:0] w0re, w0im,
    output reg signed[PROD:0] out_a_re, out_a_im
);

    generate
        if (Fast_DSP) begin : fast_dsp
            reg signed [PROD-1:0]    rr_a_s1, ri_a_s1;
            reg signed [WIDTH-1:0]   a_im_s1;
            reg signed [WIDTH/2-1:0] w0re_s1, w0im_s1;

            reg signed [PROD-1:0]    rr_a_s2, ri_a_s2, ii_a_s2, ir_a_s2;

            always @(posedge clock) begin
                // Stage 1 //
                // Channel A
                rr_a_s1 <= a_re * w0re;
                ri_a_s1 <= a_re * w0im;
                
                a_im_s1 <= a_im;
                w0re_s1 <= w0re;
                w0im_s1 <= w0im;

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
                wire signed[PROD-1:0] rr_a, ii_a, ri_a, ir_a;

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2),
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

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2),
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

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2),
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

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2),
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

module CheapMult #(
    parameter WIDTH = 16,
    parameter PROD  = 32,
    parameter Fast_DSP = 1,
    parameter carry_save = 1,
    parameter CHUNK = 8
)(
    input  clock,
    input  signed [WIDTH-1:0]   a_re, a_im,
    input  signed [WIDTH/2-1:0] w0re, w0im,
    output reg signed [PROD:0] out_a_re, out_a_im
);
    generate 
        if (Fast_DSP) begin : fast_dsp
            reg signed [WIDTH:0]     sum_a_s1;
            reg signed [WIDTH/2:0]   sum_w0_s1, diff_w0_s1;

            reg signed [WIDTH-1:0]   a_re_s1, a_im_s1;
            reg signed [WIDTH/2-1:0] w0re_s1;

            reg signed [PROD:0]      k1_a_s2, k2_a_s2;
            
            reg signed [WIDTH-1:0]   a_im_s2;
            reg signed [WIDTH/2:0]   sum_w0_s2;

            reg signed [PROD:0]      k1_a_s3, k2_a_s3, k3_a_s3;


            always @(posedge clock) begin
                // Stage 1 //
                // Channel A
                sum_a_s1   <= a_re + a_im;
                sum_w0_s1  <= w0re + w0im;
                diff_w0_s1 <= w0im - w0re;
                a_re_s1    <= a_re;
                a_im_s1    <= a_im;
                w0re_s1    <= w0re;

                // Stage 2 //
                // Channel A
                k1_a_s2   <= w0re_s1 * sum_a_s1;
                k2_a_s2   <= a_re_s1 * diff_w0_s1;
                
                a_im_s2   <= a_im_s1;
                sum_w0_s2 <= sum_w0_s1;

                // Stage 3 //
                // Channel A
                k3_a_s3 <= a_im_s2 * sum_w0_s2;
                
                k1_a_s3 <= k1_a_s2;
                k2_a_s3 <= k2_a_s2;

                // Stage 4 //
                // Channel A
                out_a_re <= k1_a_s3 - k3_a_s3;
                out_a_im <= k1_a_s3 + k2_a_s3;
            end
        end else begin : slow_dsp
            if(carry_save) begin : carry_save_mult
                reg signed [WIDTH:0]   sum_a_in;
                reg signed [WIDTH/2:0] sum_w0_in;
                reg signed [WIDTH/2:0] diff_w0_in;

                reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                reg signed [WIDTH/2-1:0] w0re_d;

                wire signed [PROD:0] k1_a, k2_a, k3_a;
                reg signed [PROD:0] k1_a_reg;

                Carry_mult #(
                    .A_WIDTH(WIDTH+1),
                    .B_WIDTH(WIDTH/2),
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

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2 + 1),
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

                Carry_mult #(
                    .A_WIDTH(WIDTH),
                    .B_WIDTH(WIDTH/2 + 1),
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
                reg signed [WIDTH:0]   sum_a_in;
                reg signed [WIDTH/2:0] sum_w0_in;
                reg signed [WIDTH/2:0] diff_w0_in;

                reg signed [WIDTH-1:0]   a_re_d, a_im_d;
                reg signed [WIDTH/2-1:0] w0re_d;

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