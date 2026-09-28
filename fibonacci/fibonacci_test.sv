// GEMINI ASSISTED TESTBENCH
`default_nettype none
module clock_maker
  (output logic clk);
  initial begin
    clk = 1;
    forever #10 clk = ~clk; // $finish somewhere else
  end
endmodule : clock_maker

module fibonacci_test ();
  // wires for testing
  logic clk;
  logic rst_n;
  logic [15:0] f;

  logic [4:0] i_test; 
  logic [15:0] n1_fib_test, 
               n2_fib_test;

  logic [15:0] f_test;
  // clk module
  clock_maker clk_test (.*);
  // dut
  fibonacci DUT (.*);
  
  // test DUT answers
  // go through number of fibonacci numbers
  initial begin
    $monitor ($time,, "DUT f: %0d | Test Model: %0d", f, f_test);

    // 1. Reset DUT synchronously
    rst_n = 1'b0;
    repeat (2) @(posedge clk);
    #1;
    rst_n = 1'b1;

    // Golden model seeds matching hardware reset state
    n1_fib_test = 16'd1;
    n2_fib_test = 16'd0;

    // Wait 1 cycle for FSM to move from START (00) -> CHECK (01)
    @(posedge clk);

    // 2. Loop through 20 iterations
    for (i_test = 5'd1; i_test <= 5'd20; i_test++) begin
      // Advance golden model
      f_test      = n1_fib_test + n2_fib_test;
      n2_fib_test = n1_fib_test;
      n1_fib_test = f_test;

      // Hardware takes 2 clock cycles: CHECK -> CALC -> CHECK
      @(posedge clk); // moves into CALC
      @(posedge clk); // latches sum and returns to CHECK
      #1;             // sample post-clock

      if (f !== f_test) begin
        $display("[Time %0t] MISMATCH at Step %0d! Expected %0d, Got %0d", 
                 $time, i_test, f_test, f);
      end else begin
        $display("[Time %0t] MATCH Step %0d: F(%0d) = %0d", 
                 $time, i_test, i_test + 1, f);
      end
    end

    // 3. Test wrap-around from DONE (11) back to START (00)
    @(posedge clk); // CHECK -> DONE
    @(posedge clk); // DONE -> START
    #1;
    if (f !== 16'd1) begin
      $display("[Time %0t] Wrap-around failed! Expected f=1 in START, Got %0d", $time, f);
    end else begin
      $display("[Time %0t] Wrap-around SUCCESS!", $time);
    end

    $finish;
  end


endmodule : fibonacci_test
