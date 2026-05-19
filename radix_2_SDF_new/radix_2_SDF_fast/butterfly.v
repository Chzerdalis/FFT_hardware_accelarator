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