`timescale 1ps/1ps

module delay_reg #(
    parameter WIDTH = 16,
    parameter DELAY = 1
)(
    input clock,
    input signed [WIDTH-1:0] data_in,
    output signed [WIDTH-1:0] data_out
);
    generate
        if(DELAY == 0) begin
            assign data_out = data_in;
        end else begin
            reg signed [WIDTH-1:0] delay_line [0:DELAY-1];
            integer i;

            always @(posedge clock) begin
                delay_line[0] <= data_in;
                for (i = 1; i < DELAY; i = i + 1) begin
                    delay_line[i] <= delay_line[i-1];
                end
                //data_out <= delay_line[DELAY-1];
            end

            assign data_out = delay_line[DELAY-1];
        end
    endgenerate

endmodule

module delay_reg_reset #(
    parameter WIDTH = 16,
    parameter DELAY = 1
)(
    input clock,
    input reset,
    input [WIDTH-1:0] data_in,
    output [WIDTH-1:0] data_out
);
    if(DELAY == 0) begin
        assign data_out = data_in;
    end else begin
        reg [WIDTH-1:0] delay_line [0:DELAY-1];
        integer i;

        always @(posedge clock or posedge reset) begin
            if (reset) begin
                for (i = 0; i < DELAY; i = i + 1) begin
                    delay_line[i] <= 0;
                end
            end else begin
                delay_line[0] <= data_in;
                for (i = 1; i < DELAY; i = i + 1) begin
                    delay_line[i] <= delay_line[i-1];
                end
                //data_out <= delay_line[DELAY-1];
            end
        end

        assign data_out = delay_line[DELAY-1];
    end
endmodule