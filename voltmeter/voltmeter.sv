// Wrapper module for the voltmeter
// Measures voltage from 12-bit MAX3008 ADC
// Gives 7 segment value for voltage
// Only integer values for now, but decimal support may be added later
module voltmeter (
  input logic clk,
  input logic rst_n,

);

  // wires
  logic [7:0] buffer;
  // state enum
  enum logic [1:0] {IDLE=2'b00, SAMPLE=2'b01, AVERAGE=2'b10, DONE=2'b11} state, next_state;
  // instantiate spi controller module
  spi_con adc ();
  // take a couple of samples (probably like 5?)
  always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin
      
    end else begin
      state <= next_state;
    end
  end
  // use binary to bcd decoder to convert

endmodule