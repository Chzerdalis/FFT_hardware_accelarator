`timescale 1ns / 1ps

module butterfly_complex_core #(
    parameter WIDTH = 16
)(
    input                 clock,
    input                 reset,
    input                 start,
    // Complex Inputs
    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    // Output 0: (X0 - X2) - j(X1 - X3)
    output reg signed [WIDTH-1:0] out1r, out1i,
    
    // Output 1: X0 + X2
    output reg signed [WIDTH-1:0]   out2r, out2i,
    
    // Output 2: X1 + X3
    output reg signed [WIDTH-1:0]   out3r, out3i,
    
    // Output 3: (X0 - X2) + j(X1 - X3)
    output reg signed [WIDTH-1:0] out4r, out4i,
    output reg done
);
    reg [WIDTH-1:0] ar_reg, ai_reg, br_reg, bi_reg, cr_reg, ci_reg, dr_reg, di_reg;
    reg start_reg_0, start_reg_1;
    reg [WIDTH-1:0] diff02_im_reg, diff02_re_reg, diff13_re_reg, diff13_im_reg;
    reg [WIDTH-1:0] y2_re_reg, y2_im_reg, y3_re_reg, y3_im_reg;


    //First pipeline stage: Register inputs
    //difference for first and fourth outputs
    wire signed [WIDTH-1:0] diff02_re = ar_reg - cr_reg;
    wire signed [WIDTH-1:0] diff02_im = ai_reg - ci_reg;
    
    wire signed [WIDTH-1:0] diff13_re = br_reg - dr_reg;
    wire signed [WIDTH-1:0] diff13_im = bi_reg - di_reg;
    // Branch 1: y1 = X0 + X2
    wire signed [WIDTH-1:0] y2_re = ar_reg + cr_reg;
    wire signed [WIDTH-1:0] y2_im = ai_reg + ci_reg;

    // Branch 2: y2 = X1 + X3
    wire signed [WIDTH-1:0] y3_re = br_reg + dr_reg;
    wire signed [WIDTH-1:0] y3_im = bi_reg + di_reg;
    // Branch 0: y0 = (X0 - X2) - j(X1 - X3)
    // Substitution: (diff02_re + j*diff02_im) - j(diff13_re + j*diff13_im)
    // Logic: (diff02_re + diff13_im) + j(diff02_im - diff13_re)
    wire signed [WIDTH-1:0] y1_re = diff02_re_reg + diff13_im_reg;
    wire signed [WIDTH-1:0] y1_im = diff02_im_reg - diff13_re_reg;

    // Branch 3: y3 = (X0 - X2) + j(X1 - X3)
    // Substitution: (diff02_re + j*diff02_im) + j(diff13_re + j*diff13_im)
    // Logic: (diff02_re - diff13_im) + j(diff02_im + diff13_re)
    wire signed [WIDTH-1:0] y4_re = diff02_re_reg - diff13_im_reg;
    wire signed [WIDTH-1:0] y4_im = diff02_im_reg + diff13_re_reg;


    always @(posedge clock) begin
        if (reset) begin
            ar_reg <= 0; ai_reg <= 0; 
            br_reg <= 0; bi_reg <= 0; 
            cr_reg <= 0; ci_reg <= 0; 
            dr_reg <= 0; di_reg <= 0;
            start_reg_0 <= 0; 

            diff02_re_reg <= 0; 
            diff02_im_reg <= 0; 
            diff13_re_reg <= 0; 
            diff13_im_reg <= 0;
            y2_re_reg <= 0; 
            y2_im_reg <= 0; 
            y3_re_reg <= 0; 
            y3_im_reg <= 0;
            start_reg_1 <= 0; 

            out1r <= 0; out1i <= 0;
            out2r <= 0; out2i <= 0;
            out3r <= 0; out3i <= 0;
            out4r <= 0; out4i <= 0;
            done <= 0;
        end else begin
            ar_reg <= ar; ai_reg <= ai; 
            br_reg <= br; bi_reg <= bi; 
            cr_reg <= cr; ci_reg <= ci; 
            dr_reg <= dr; di_reg <= di;
            start_reg_0 <= start;

            diff02_re_reg <= diff02_re;
            diff02_im_reg <= diff02_im;
            diff13_re_reg <= diff13_re;
            diff13_im_reg <= diff13_im;
            y2_re_reg <= y2_re;
            y2_im_reg <= y2_im;
            y3_re_reg <= y3_re;
            y3_im_reg <= y3_im;
            start_reg_1 <= start_reg_0;

            out1r <= y1_re; out1i <= y1_im;
            out2r <= y2_re_reg; out2i <= y2_im_reg;
            out3r <= y3_re_reg; out3i <= y3_im_reg;
            out4r <= y4_re; out4i <= y4_im;
            done <= start_reg_1;
        end
    end

endmodule

`timescale 1ns / 1ps

module butterfly_complex_core_reduced #(
    parameter WIDTH = 16
)(
    input                 clock,
    input                 reset,
    input                 start,
    // Complex Inputs
    input  signed [WIDTH-1:0] ar, ai,
    input  signed [WIDTH-1:0] br, bi,
    input  signed [WIDTH-1:0] cr, ci,
    input  signed [WIDTH-1:0] dr, di,

    // Output 0: (X0 - X2) - j(X1 - X3)
    output reg signed [WIDTH-1:0] out1r, out1i,
    
    // Output 1: X0 + X2
    output reg signed [WIDTH-1:0] out2r, out2i,
    
    // Output 2: X1 + X3
    output reg signed [WIDTH-1:0] out3r, out3i,
    
    // Output 3: (X0 - X2) + j(X1 - X3)
    output reg signed [WIDTH-1:0] out4r, out4i,
    output reg done
);

    // -----------------------------------------
    // Pipeline Registers
    // -----------------------------------------
    reg start_reg;
    reg signed [WIDTH-1:0] diff02_re_reg, diff02_im_reg, diff13_re_reg, diff13_im_reg;
    reg signed [WIDTH-1:0] y2_re_reg, y2_im_reg, y3_re_reg, y3_im_reg;

    // -----------------------------------------
    // Combinational Logic (Reads directly from inputs)
    // -----------------------------------------
    // differences for first and fourth outputs
    wire signed [WIDTH-1:0] diff02_re = ar - cr;
    wire signed [WIDTH-1:0] diff02_im = ai - ci;
    
    wire signed [WIDTH-1:0] diff13_re = br - dr;
    wire signed [WIDTH-1:0] diff13_im = bi - di;
    
    // Branch 1: y1 = X0 + X2
    wire signed [WIDTH-1:0] y2_re = ar + cr;
    wire signed [WIDTH-1:0] y2_im = ai + ci;

    // Branch 2: y2 = X1 + X3
    wire signed [WIDTH-1:0] y3_re = br + dr;
    wire signed [WIDTH-1:0] y3_im = bi + di;

    // -----------------------------------------
    // Combinational Logic (Reads from Stage 1 regs)
    // -----------------------------------------
    // Branch 0: y0 = (X0 - X2) - j(X1 - X3)
    // Logic: (diff02_re + diff13_im) + j(diff02_im - diff13_re)
    wire signed [WIDTH-1:0] y1_re = diff02_re_reg + diff13_im_reg;
    wire signed [WIDTH-1:0] y1_im = diff02_im_reg - diff13_re_reg;

    // Branch 3: y3 = (X0 - X2) + j(X1 - X3)
    // Logic: (diff02_re - diff13_im) + j(diff02_im + diff13_re)
    wire signed [WIDTH-1:0] y4_re = diff02_re_reg - diff13_im_reg;
    wire signed [WIDTH-1:0] y4_im = diff02_im_reg + diff13_re_reg;


    always @(posedge clock) begin
        if (reset) begin
            diff02_re_reg <= 0; 
            diff02_im_reg <= 0; 
            diff13_re_reg <= 0; 
            diff13_im_reg <= 0;
            y2_re_reg <= 0; 
            y2_im_reg <= 0; 
            y3_re_reg <= 0; 
            y3_im_reg <= 0;
            start_reg <= 0; 

            out1r <= 0; out1i <= 0;
            out2r <= 0; out2i <= 0;
            out3r <= 0; out3i <= 0;
            out4r <= 0; out4i <= 0;
            done <= 0;
        end else begin
            // Stage 1: Register the first wave of additions/subtractions
            diff02_re_reg <= diff02_re;
            diff02_im_reg <= diff02_im;
            diff13_re_reg <= diff13_re;
            diff13_im_reg <= diff13_im;
            
            y2_re_reg <= y2_re;
            y2_im_reg <= y2_im;
            y3_re_reg <= y3_re;
            y3_im_reg <= y3_im;
            
            start_reg <= start;

            // Stage 2: Final outputs
            out1r <= y1_re; 
            out1i <= y1_im;
            out2r <= y2_re_reg; 
            out2i <= y2_im_reg;
            out3r <= y3_re_reg; 
            out3i <= y3_im_reg;
            out4r <= y4_re; 
            out4i <= y4_im;
            done <= start_reg;
        end
    end

endmodule