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
    wire start_reg_inside_adders;
    reg signed [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg, cr_reg, ci_reg, dr_reg, di_reg;
    reg signed [WIDTH/2-1:0] w0r_reg, w0i_reg, w1r_reg, w1i_reg, w2r_reg, w2i_reg;
    reg signed [WIDTH-1:0] ar_reg_0, ai_reg_0;
    reg signed [WIDTH-1:0] ar_reg_1, ai_reg_1;
    reg signed [PROD-1:0] m0r_reg, m0i_reg, m1r_reg, m1i_reg, m2r_reg, m2i_reg;
    reg signed [PROD-1:0] mul_m0r_reg_1, mul_m0i_reg_1, mul_m1r_reg_1, mul_m1i_reg_1, mul_m2r_reg_1, mul_m2i_reg_1;
    reg signed [PROD-1:0] mul_m0r_reg_2, mul_m0i_reg_2, mul_m1r_reg_2, mul_m1i_reg_2, mul_m2r_reg_2, mul_m2i_reg_2;
    reg signed [WIDTH-1:0] t0r_reg, t0i_reg, t1r_reg, t1i_reg, t2r_reg, t2i_reg, t3r_reg, t3i_reg;
    reg signed [WIDTH-1:0] ar_reg_array [0:7];
    reg signed [WIDTH-1:0] ai_reg_array [0:7];

    integer j;

    wire signed [PROD-1:0] mul_m0r_1; 
    wire signed [PROD-1:0] mul_m0i_1;
    wire signed [PROD-1:0] mul_m1r_1;
    wire signed [PROD-1:0] mul_m1i_1;
    wire signed [PROD-1:0] mul_m2r_1;
    wire signed [PROD-1:0] mul_m2i_1;

    wire signed [PROD-1:0] mul_m0r_2;
    wire signed [PROD-1:0] mul_m0i_2;   
    wire signed [PROD-1:0] mul_m1r_2;
    wire signed [PROD-1:0] mul_m1i_2;
    wire signed [PROD-1:0] mul_m2r_2;
    wire signed [PROD-1:0] mul_m2i_2;

    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm0r  (.clock(clock), .reset(reset), .a(br_reg), .b(w0r_reg), .product(mul_m0r_1), .start(start_reg_0), .done(start_reg_inside_adders));
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm0i  (.clock(clock), .reset(reset), .a(br_reg), .b(w0i_reg), .product(mul_m0i_1), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm1r  (.clock(clock), .reset(reset), .a(cr_reg), .b(w1r_reg), .product(mul_m1r_1), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm1i  (.clock(clock), .reset(reset), .a(cr_reg), .b(w1i_reg), .product(mul_m1i_1), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm2r  (.clock(clock), .reset(reset), .a(dr_reg), .b(w2r_reg), .product(mul_m2r_1), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm2i  (.clock(clock), .reset(reset), .a(dr_reg), .b(w2i_reg), .product(mul_m2i_1), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm0r_2(.clock(clock), .reset(reset), .a(bi_reg), .b(w0i_reg), .product(mul_m0r_2), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm0i_2(.clock(clock), .reset(reset), .a(bi_reg), .b(w0r_reg), .product(mul_m0i_2), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm1r_2(.clock(clock), .reset(reset), .a(ci_reg), .b(w1i_reg), .product(mul_m1r_2), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm1i_2(.clock(clock), .reset(reset), .a(ci_reg), .b(w1r_reg), .product(mul_m1i_2), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm2r_2(.clock(clock), .reset(reset), .a(di_reg), .b(w2i_reg), .product(mul_m2r_2), .start(start_reg_0), .done());
    multiplier_sythesis_2 #(.WIDTH(WIDTH)) pm2i_2(.clock(clock), .reset(reset), .a(di_reg), .b(w2r_reg), .product(mul_m2i_2), .start(start_reg_0), .done());
////////////////////////////////

    //One addition/subtraction per clock cycle per data path to find m0, m1, m2
    wire signed [PROD-1:0] m0r = mul_m0r_reg_1 - mul_m0r_reg_2;
    wire signed [PROD-1:0] m0i = mul_m0i_reg_1 + mul_m0i_reg_2;

    wire signed [PROD-1:0] m1r = mul_m1r_reg_1 - mul_m1r_reg_2;
    wire signed [PROD-1:0] m1i = mul_m1i_reg_1 + mul_m1i_reg_2;

    wire signed [PROD-1:0] m2r = mul_m2r_reg_1 - mul_m2r_reg_2;
    wire signed [PROD-1:0] m2i = mul_m2i_reg_1 + mul_m2i_reg_2;

    //ADD ar_registers

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
            //Added wait for the result of the adders
            for (j = 0; j < 8; j = j + 1) begin
                ar_reg_array[j] <= 0;
                ai_reg_array[j] <= 0;
            end

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
            start_reg_1 <= start_reg_inside_adders;

            ar_reg_array[0] <= ar_reg_0;
            ai_reg_array[0] <= ai_reg_0;

            for (j = 1; j < 8; j = j + 1) begin
                ar_reg_array[j] <= ar_reg_array[j - 1];
                ai_reg_array[j] <= ai_reg_array[j - 1];
            end

            ar_reg_1 <= ar_reg_array[7];
            ai_reg_1 <= ai_reg_array[7];

            m0i_reg <= m0i; m0r_reg <= m0r;
            m1i_reg <= m1i; m1r_reg <= m1r;
            m2i_reg <= m2i; m2r_reg <= m2r;
            //ar_reg_1 <= ar_reg_0; ai_reg_1 <= ai_reg_0;
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

