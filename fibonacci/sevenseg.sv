`default_nettype none
module SevenSegControl #(parameter COUNT_PERIOD = 100000)
    (   input wire           clk,
        input wire           rst_n,
        input wire [15:0]    val,
        output logic[6:0]    cat,
        output logic[3:0]    an
    );
    logic [3:0]   segment_state;
    logic [31:0]  segment_counter;
    logic [3:0]   sel_values;
    logic [6:0]   led_out;
 
    //TODO: wire up sel_values (-> x) with your input, val
    //Note that x is a 4 bit input, and val is 32 bits wide
    //Adjust accordingly, based on what you know re. which digits
    //are displayed when...
    always_comb begin
        case (segment_state)
            4'b0001: sel_values = val[3:0];    // Rightmost digit (an[0])
            4'b0010: sel_values = val[7:4];    // Second digit    (an[1])
            4'b0100: sel_values = val[11:8];   // Third digit     (an[2])
            4'b1000: sel_values = val[15:12];  // Leftmost digit  (an[3])
            default: sel_values = 4'b0000;
        endcase
    end
 
    BCDtoSevenSegment mbto7s (.number(sel_values), .segment(led_out));
    assign cat = ~led_out; //<--note this inversion is needed
    assign an = ~segment_state; //note this inversion is needed
 
    always_ff @(posedge clk, negedge rst_n) begin
        if (~rst_n) begin
            segment_state <= 4'b0001;
            segment_counter <= 32'b0;
        end else begin
            if (segment_counter == COUNT_PERIOD) begin
                segment_counter <= 32'd0;
                segment_state <= {segment_state[2:0],segment_state[3]};
            end else begin
                segment_counter <= segment_counter+1;
            end
        end
    end
endmodule // seven_segment_controller