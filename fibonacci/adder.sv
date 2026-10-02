`default_nettype none
// 16 bit adder
// Adds two 16 bit two's complement numbers together
// has cout, overflow, zero, negative flags
module adder (
  input logic [15:0] A,
  input logic [15:0] B,
  input logic cin,

  output logic [15:0] sum,
  output logic cout,
  output logic overflow,
  output logic zero,
  output logic negative);

  
  assign {cout, sum} = A + B + cin; // add
  assign zero = (sum == 0); // magcmp 0
  assign negative = (sum[15] & 1); // compare msb for two's complement
  // two positive A + B = negative sum
  // don't have to worry about subtraction for now? (let's just do it later)
  assign overflow = (A[15] & B[15] & ~sum[15]) | (~A[15] & ~B[15] & sum[15]);

endmodule : adder
