module bcdAdd
  (input   logic  [3:0]  A,  B,
   input   logic         cin,
   output  logic  [3:0]  sum,
   output  logic         cout);

  logic [4:0] my_sum;

  assign sum = my_sum[3:0];
  // use the + 6 trick to wrap-around
  always_comb  begin
    my_sum  =  A  +  B  +  cin;
    cout  =  0;
    if  (my_sum  >  9)  begin
      my_sum  =  my_sum  +  6;
      cout  =  1;
    end
  end
  
endmodule: bcdAdd

// Add two 16-bit bcd numbers to have the bcd display
// decimal values instead of hex
module BcdAdder16 (
    input  logic [15:0] A, B,
    output logic [15:0] sum
);

    logic c1, c2, c3, c4;

    // Ones digit (bits 3:0)
    bcdAdd add0 (.A(A[3:0]),   .B(B[3:0]),   .cin(1'b0), .sum(sum[3:0]),   .cout(c1));

    // Tens digit (bits 7:4)
    bcdAdd add1 (.A(A[7:4]),   .B(B[7:4]),   .cin(c1),   .sum(sum[7:4]),   .cout(c2));

    // Hundreds digit (bits 11:8)
    bcdAdd add2 (.A(A[11:8]),  .B(B[11:8]),  .cin(c2),   .sum(sum[11:8]),  .cout(c3));

    // Thousands digit (bits 15:12)
    bcdAdd add3 (.A(A[15:12]), .B(B[15:12]), .cin(c3),   .sum(sum[15:12]), .cout(c4));

endmodule