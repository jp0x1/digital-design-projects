`default_nettype none
// Module for SPI controller
// Make FSM for SPI protocol to receive
// data from the ADC
module spi_con (
  input logic clk, // system clk
              rst_n, // reset
  input logic [7:0] data_in, // data to send
  input logic trigger, // start data transaction
  input logic cipo, // controller in, peripheral out

  output logic [7:0] data_out, // data received
  output logic data_valid, // high when output data present
  output logic copi, // controller in, peripheral out
  output logic dclk, // data clk
  output logic cs_n // chip select is active low
  );
  // state enum
  // https://learn.sparkfun.com/tutorials/serial-peripheral-interface-spi/all
  // IDLE, LOAD, TRANSMIT, DONE
  enum logic [1:0] {IDLE=2'b00, 
                    LOAD=2'b01, 
                    TRANSMIT=2'b10, 
                    DONE=2'b11} state, next_state;
  // wires
  
  // next state generator
  always_comb begin
    case (state)
      IDLE: next_state = LOAD;
      LOAD: next_state = TRANSMIT;
      TRANSMIT: next_state = DONE;
      DONE: next_state = IDLE;
      default: next_state = IDLE;
    endcase   
  end
  // registers for state, buffer, idk
  always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
      state <= IDLE;
    end else begin
      // need to probably buffer this with a counter
      state <= next_state;
    end
  end

  // output combinational logic
  always_comb begin
    
  end

endmodule