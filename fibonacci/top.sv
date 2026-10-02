module ChipInterface (
    input  logic       CLK100MHZ, // Pin W5
    input  logic       btnC,      // Pin U18 (Center button)
    output logic [6:0] seg,       // Pins W7, W6, U8, V8, U5, V5, U7
    output logic       dp,        // Pin V7 (Decimal point)
    output logic [3:0] an         // Pins U2, U4, V4, W4 (Anodes)
);

    // Basys 3 buttons are active-high (1 when pressed).
    // System expects rst_n (active-low, 0 to reset), so invert it:
    logic rst_n;
    assign rst_n = ~btnC;

    // The 7-segment display on the Basys3 is active-low.
    // Setting dp to 1 keeps the decimal point turned off.
    assign dp = 1'b1;

    // Instantiate your System module
    System system (
        .clk   (CLK100MHZ),
        .rst_n (rst_n),
        .val   (seg),
        .an    (an)
    );

endmodule 

module System 
  (input logic clk,
   input logic rst_n,
   output logic [6:0] val,
   output logic [3:0] an);

  logic [15:0] f;
  Fibonacci fib (.*);
  SevenSegControl sevensegfull (.clk, 
                                .rst_n, 
                                .val(f), 
                                .cat(val), 
                                .an);

endmodule