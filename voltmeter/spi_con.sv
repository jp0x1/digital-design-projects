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
  logic [2:0] bit_count; // 8 bits
  logic [7:0] tx_buffer;
  logic [7:0] rx_buffer;
  logic [31:0] counter; // counter to simulate baud rate

  // constants
  logic [31:0] full_data_period = 32'd100; // 100 cycle delay?
  logic [31:0] half_data_period = 32'd50; // 50 cycle delay?
  // registers for state, buffer, idk
  always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
      state <= IDLE;
      tx_buffer <= 8'b0;
      rx_buffer <= 8'b0;
      bit_count <= 3'b0;
      counter <= 32'b0;
      copi <= 0;
      dclk <= 0;
    end else begin
      // need to probably buffer this with a counter
      if (state == LOAD) begin
        tx_buffer <= data_in;
        rx_buffer <= 8'b0;
        bit_count <= 3'b0;
        counter <= 32'b0;
        copi <= data_in[7];
      end
      else if (state == TRANSMIT) begin
        if (counter == full_data_period - 1) begin // rising edge of dclk
          dclk <= 0; // toggle the data clock(?) aka fake clock
          copi <= tx_buffer[6]; // Drive current MSB out to SPI bus
          tx_buffer <= {tx_buffer[6:0], 1'b0}; // Shift left
          counter <= 32'b0;
          bit_count <= bit_count + 1;
        end
        else if (counter == half_data_period) begin // falling edge of dclk
          dclk <= 1; // toggle the data clock(?) aka fake clock
          rx_buffer <= {rx_buffer[6:0], cipo};
          counter <= counter + 1;
        end
        else begin
          counter <= counter + 1;
        end
      end
      state <= next_state;
    end
  end
  // next state generator
  always_comb begin
    case (state)
      IDLE: begin
        next_state = (trigger) ? LOAD : IDLE;
      end
      LOAD: begin
        next_state = TRANSMIT;
      end
      TRANSMIT: begin
        next_state = (bit_count == 3'd7 &&
                      counter == full_data_period-1) ? DONE : TRANSMIT; 
      end
      DONE: begin
        next_state = IDLE;
      end 
      default: next_state = IDLE;
    endcase   
  end
  // output combinational logic
  // dclk and copi and cipo are not included, as they are dynamically changed 
  // decided to use buffers for rx and tx, and just fully "burst" output
  always_comb begin
    case (state)
      IDLE: begin
        data_valid = 0;
        data_out = 8'b0;
        cs_n = 1; // keep cs high to disable
      end
      LOAD: begin
        data_valid = 0;
        data_out = 8'b0;
        cs_n = 0;
      end
      TRANSMIT: begin
        data_valid = 0;
        data_out = 8'b0;
        cs_n = 0;
      end
      DONE: begin
        data_valid = 1;
        data_out = rx_buffer;
        cs_n = 1; // keep cs (enable?) asserted, 
      end
      default: begin
        data_valid = 0;
        data_out = 8'b0;
        cs_n = 1; // keep cs high to disable
      end
    endcase
  end

endmodule