`timescale 1ps/1ps

module control_unit_fsm_last_stage #(
    parameter Num_of_samples = 256,
    parameter Num_of_samples_bits = 8
)(
    input clock,
    input reset,
    input input_en,
    input step_mode_input,
    output reg step_mode_in,
    output reg step_mode_out,
    output reg stride_segment_counter,
    output reg butterfly_op_counter,
    output reg butterfly_op_counter_en
);

    // State encoding
    localparam IDLE = 3'b000;
    localparam FILL = 3'b001;
    localparam PROCESSING = 3'b010;
    localparam RESTART_OUT_COUNT = 3'b011;
    localparam RESTART_IN_COUNT = 3'b100;
    localparam FLUSH = 3'b101;

    reg [2:0] state;
    reg step_count_in, step_count_out;
    reg [Num_of_samples_bits-1:0] flush_count, input_count;

    // State transition logic
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            stride_segment_counter  <= 0;
            butterfly_op_counter    <= 0;
            butterfly_op_counter_en <= 1'b0;
            flush_count             <= 0;
            step_mode_in            <= 1'b0;
            step_mode_out           <= 1'b0;
            step_count_in           <= 1'b1;
            step_count_out          <= 1'b1;
            input_count             <= 0;
        end else begin
            case (state)
                IDLE: begin
                    stride_segment_counter  <= 0;
                    butterfly_op_counter    <= 0;
                    butterfly_op_counter_en <= 1'b0;
                    step_mode_in            <= 1'b0;
                    step_mode_out           <= 1'b0;
                    step_count_in           <= 1'b0;
                    step_count_out          <= 1'b1;
                    flush_count             <= 0;
                    input_count             <= 0;

                    if (input_en) begin
                        state <= FILL;
                        stride_segment_counter <= stride_segment_counter + 1'b1;
                        input_count <= input_count + 1'b1; 
                        state <= PROCESSING;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                       
                    end else begin
                        state <= state;
                    end
                end
                PROCESSING: begin
                    if(!input_en) begin
                        if(flush_count == 0) begin
                            state <= IDLE;
                            butterfly_op_counter_en <= 1'b0;
                        end else begin
                            state <= FLUSH;
                            butterfly_op_counter_en <= 1'b1;
                        end
                        stride_segment_counter  <= stride_segment_counter;
                        input_count <= input_count;
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;
                        flush_count <= flush_count - 1'b1;
                        step_mode_out <= step_mode_out;
                        step_mode_in <= step_mode_in;
                        step_count_in <= step_count_in;
                        step_count_out <= step_count_out;
                    end else begin
                        input_count <= input_count + 1'b1;
                        butterfly_op_counter_en <= 1'b1;
                        flush_count <= flush_count - 1'b1;
                        step_mode_out <= step_mode_out;
                        step_mode_in <= step_mode_in;
                        step_count_in <= step_count_in;
                        step_count_out <= step_count_out;

                        if(step_mode_input == 1'b0) begin
                            if(stride_segment_counter && step_mode_in == 1'b0) begin
                                step_mode_in <= 1'b1;
                            end else if(stride_segment_counter && step_mode_in == 1'b1) begin
                                step_mode_in <= 1'b0;
                            end

                            if(butterfly_op_counter && step_mode_out == 1'b0) begin
                                step_count_out <= 1'b1;
                                if(step_count_out == 1'b1) begin
                                    step_mode_out <= 1'b1;
                                    step_count_out <= 1'b1;
                                end
                            end else if(butterfly_op_counter && step_mode_out == 1'b1) begin
                                step_mode_out <= 1'b0;
                            end 
                        end else begin
                            step_mode_in <= step_mode_in; 
                            if(butterfly_op_counter && step_mode_out == 1'b1) begin
                                step_mode_out <= 1'b0;
                            end 
                            step_count_out <= 0;
                        end
                        // if(stride_segment_counter && step_mode_in == 1'b0) begin
                        //     step_count_in <= 1'b1;
                        //     if(step_count_in == 1'b1) begin
                        //         step_mode_in <= 1'b1;
                        //         step_count_in <= 1'b0;
                        //     end
                        // end else if(stride_segment_counter && step_mode_in == 1'b1) begin
                        //     step_mode_in <= 1'b0;
                        // end 

                        // if(butterfly_op_counter && step_mode_out == 1'b0) begin
                        //     step_count_out <= 1'b1;
                        //     if(step_count_out == 1'b1) begin
                        //         step_mode_out <= 1'b1;
                        //         step_count_out <= 1'b0;
                        //     end
                        // end else if(butterfly_op_counter && step_mode_out == 1'b1) begin
                        //     step_mode_out <= 1'b0;
                        // end 

                        //Always increament there is no memory 
                        //we dont need the correction of the addresses
                        stride_segment_counter  <= stride_segment_counter + 1'b1;
                        
                        butterfly_op_counter <= butterfly_op_counter + 1'b1;

                        // if(input_count == { {(Num_of_samples_bits-1){1'b1}}, 1'b0 }) begin
                        //     state <= RESTART_IN_COUNT;
                        // end else if(flush_count == 1) begin
                        //     state <= RESTART_OUT_COUNT;
                        // end
                    end
                end
                RESTART_IN_COUNT: begin
                    stride_segment_counter  <= stride_segment_counter + 1'b1;
                    input_count <= input_count + 1'b1;
                    butterfly_op_counter <= butterfly_op_counter + 1'b1;
                    butterfly_op_counter_en <= 1'b1;
                    flush_count <= flush_count - 1'b1;
                    step_mode_out <= step_mode_out;
                    step_mode_in <= 1'b0;
                    step_count_in <= 1'b1;
                    step_count_out <= step_count_out;

                    if(!input_en) begin
                        if(flush_count == 0) begin
                            state <= IDLE;
                            butterfly_op_counter_en <= 1'b0;
                        end else begin
                            state <= FLUSH;
                        end
                    end else if (flush_count == 1) begin
                        state <= RESTART_OUT_COUNT;
                    end else begin
                        state <= PROCESSING;
                    end
                end
                RESTART_OUT_COUNT: begin
                    stride_segment_counter <= stride_segment_counter + 1'b1;
                    input_count <= input_count + 1'b1;
                    
                    butterfly_op_counter <= butterfly_op_counter + 1'b1;

                    butterfly_op_counter_en <= 1'b1;
                    flush_count <= flush_count - 1'b1;
                    step_mode_out <= 1'b0;
                    step_mode_in <= step_mode_in;
                    step_count_in <= step_count_in;
                    step_count_out <= 1'b1;
                    
                    if(!input_en) begin
                        if(flush_count == 0) begin
                            state <= IDLE;
                            butterfly_op_counter_en <= 1'b0;
                        end else begin
                            state <= FLUSH;
                        end
                    end else begin
                        state <= PROCESSING;
                    end
                    
                end
                FLUSH: begin
                    stride_segment_counter  <= stride_segment_counter;
                    input_count <= input_count;
                    butterfly_op_counter <= butterfly_op_counter + 1'b1;
                    flush_count <= flush_count - 1'b1;
                    step_mode_out <= step_mode_out;
                    step_mode_in <= step_mode_in;
                    step_count_in <= step_count_in;
                    step_count_out <= step_count_out;

                    //If the input is disabled correclty the output step_mode 
                    //will not change until the flush_count is 0.

                    if(flush_count == 0) begin
                        state <= IDLE;
                        butterfly_op_counter_en <= 1'b0;
                    end else begin
                        state <= state;
                        butterfly_op_counter_en <= 1'b1;
                    end
                end
            endcase
        end
    end
endmodule