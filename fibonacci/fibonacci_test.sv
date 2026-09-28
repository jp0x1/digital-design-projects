// GEMINI ASSISTED TESTBENCH
`default_nettype none

module clock_maker (output logic clk);
  initial begin
    clk = 1'b0;
    forever #10 clk = ~clk;
  end
endmodule : clock_maker

module fibonacci_test ();
  // Wires for DUT interfacing
  logic        clk;
  logic        rst_n;
  logic [15:0] f;

  // Test tracking & golden model registers
  logic [4:0]  i_test; 
  logic [15:0] n1_fib_test, n2_fib_test;
  logic [15:0] f_test;
  int          errors;

  // Module instantiations
  clock_maker clk_test (.*);
  fibonacci   DUT      (.*);
  
  initial begin
    errors = 0;
    $monitor($time,, "DUT f: %0d | Test Model: %0d", f, f_test);

    // 1. Synchronous Reset Sequence
    rst_n = 1'b0;
    repeat (2) @(posedge clk);
    #1;
    rst_n = 1'b1;

    // Seeds matching hardware reset state (F_1 = 1, F_0 = 0)
    n1_fib_test = 16'd1;
    n2_fib_test = 16'd0;
    f_test      = 16'd1;

    // Wait 1 cycle for FSM to transition: START (00) -> CHECK (01)
    @(posedge clk);

    // 2. Loop through exactly 19 additions to reach F(20) = 6765
    for (i_test = 5'd1; i_test <= 5'd19; i_test++) begin
      // Advance golden software model
      f_test      = n1_fib_test + n2_fib_test;
      n2_fib_test = n1_fib_test;
      n1_fib_test = f_test;

      // Hardware takes 2 clock cycles: CHECK (01) -> CALC (10) -> CHECK (01)
      @(posedge clk); // moves into CALC
      @(posedge clk); // latches sum into f_n1 and returns to CHECK
      #1;             // sample post-clock after signals settle

      if (f !== f_test) begin
        $display("[Time %0t] MISMATCH at Step %0d! Expected %0d, Got %0d", 
                 $time, i_test, f_test, f);
        errors++;
      end else begin
        $display("[Time %0t] MATCH Step %0d: F(%0d) = %0d", 
                 $time, i_test, i_test + 1, f);
      end
    end

    // 3. Test wrap-around from DONE (11) back to START (00)
    @(posedge clk); // CHECK (01) -> DONE (11)
    @(posedge clk); // DONE (11)  -> START (00) (evaluates next_f_n1 = 1)
    @(posedge clk); // START (00) -> CHECK (01) (latches f_n1 <= 1)
    #1;
    if (f !== 16'd1) begin
      $display("[Time %0t] Wrap-around failed! Expected f = 1 in START, Got %0d", $time, f);
      errors++;
    end else begin
      $display("[Time %0t] Wrap-around SUCCESS! Reset to f = %0d", $time, f);
    end

    // 4. Final Verification Summary
    $display("--------------------------------------------------");
    if (errors == 0) begin
      $display(">> ALL TESTS PASSED SUCCESSFULLY! (0 errors) <<");
    end else begin
      $display(">> SIMULATION FAILED with %0d error(s). <<", errors);
    end
    $display("--------------------------------------------------");

    $finish;
  end

endmodule : fibonacci_test