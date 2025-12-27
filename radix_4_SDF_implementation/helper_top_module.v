`timescale 1ns/1ps

module helper_top_module #(
    parameter WIDTH = 16,
    parameter Num_of_samples = 256
)(
    input                   clock,
    input                   reset,
    input                   input_en,
    input       [WIDTH-1:0] input_real_0,
    input       [WIDTH-1:0] input_real_1,
    input       [WIDTH-1:0] input_real_2,
    input       [WIDTH-1:0] input_real_3,
    output                  output_en,
    output      [WIDTH-1:0] output_real_0,
    output      [WIDTH-1:0] output_real_1,
    output      [WIDTH-1:0] output_real_2,
    output      [WIDTH-1:0] output_real_3
);
    
wire [WIDTH-1:0] in_im;
wire [WIDTH-1:0] out_im_0, out_im_1, out_im_2, out_im_3;
assign in_im = 0;


fft_top #(
    .WIDTH(WIDTH),
    .Num_of_samples(Num_of_samples)
) fft_inst (
    .clock(clock),
    .reset(reset),
    .input_en(input_en),
    .input_real_0(input_real_0),
    .input_real_1(input_real_1),
    .input_real_2(input_real_2),
    .input_real_3(input_real_3),
    .input_imag_0(in_im),
    .input_imag_1(in_im),
    .input_imag_2(in_im),
    .input_imag_3(in_im),
    .output_en(output_en),
    .output_real_0(output_real_0),
    .output_real_1(output_real_1),
    .output_real_2(output_real_2),
    .output_real_3(output_real_3),
    .output_imag_0(out_im_0),
    .output_imag_1(out_im_1),
    .output_imag_2(out_im_2),
    .output_imag_3(out_im_3)
);

endmodule