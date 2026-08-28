`timescale 1ns/1ps

module DelayBuffer #(
    parameter   DEPTH = 32,
    parameter   WIDTH = 32,
    parameter   Bram = 1
)(
    input               clock,  
    input   [WIDTH-1:0] input_real,
    input   [WIDTH-1:0] input_imag,  
    output  [WIDTH-1:0] out_real, 
    output  [WIDTH-1:0] out_imag   
);

    reg [WIDTH-1:0] buf_re[0:DEPTH-1];
    reg [WIDTH-1:0] buf_im[0:DEPTH-1];

    generate
        if (Bram) begin : gen_bram
            (* srl_style = "block" *) reg [WIDTH-1:0] buf_re[0:DEPTH-1];
            (* srl_style = "block" *) reg [WIDTH-1:0] buf_im[0:DEPTH-1];
        end
    endgenerate

    // Use genvar instead of integer
    genvar i;
    generate
        for (i = 1; i < DEPTH; i = i + 1) begin : shift_loop
            always @(posedge clock) begin
                buf_re[i] <= buf_re[i-1];
                buf_im[i] <= buf_im[i-1];
            end
        end
    endgenerate

    // The first element gets its data directly from the input
    always @(posedge clock) begin
        buf_re[0] <= input_real;
        buf_im[0] <= input_imag; 
    end

    assign  out_real = buf_re[DEPTH-1];
    assign  out_imag = buf_im[DEPTH-1];

endmodule