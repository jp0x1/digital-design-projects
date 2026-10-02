`default_nettype none
// GEMINI FULLY MADE THIS TESTBENCH BTW
module clock_maker (output logic clk);
  initial begin
    clk = 1'b0;
    forever #10 clk = ~clk; // 50 MHz simulation clock (20ns period)
  end
endmodule : clock_maker

module fibonacci_test ();
  // Wires for DUT interfacing
  logic        clk;
  logic        rst_n;
  logic [15:0] f;

  // Test tracking & golden model variables
  logic [4:0]  i_test; 
  int          dec_n1, dec_n2, dec_sum; // Software decimal trackers
  logic [15:0] f_test;                  // Expected BCD output
  int          errors;

  // 1. Instantiate clock
  clock_maker clk_test (.*);

  // 2. Instantiate DUT with COUNT_PERIOD = 0 so it doesn't wait 100,000,000 cycles!
  Fibonacci #(.COUNT_PERIOD(0)) DUT (
      .clk   (clk),
      .rst_n (rst_n),
      .f     (f)
  );
  
  initial begin
    errors = 0;
    // Note: %04h prints BCD values exactly as readable decimal numbers!
    $monitor($time,, "DUT BCD f: %04h | Expected BCD: %04h", f, f_test);

    // 1. Reset Sequence
    rst_n = 1'b0;
    repeat (2) @(posedge clk);
    #1;
    rst_n = 1'b1;

    // Seeds matching hardware reset state (F_1 = 1, F_0 = 0)
    dec_n1 = 1;
    dec_n2 = 0;
    f_test = 16'h0001;

    // Wait 1 cycle for FSM transition: START (00) -> CHECK (01)
    @(posedge clk);

    // 2. Loop through exactly 19 additions to reach F(20) = 6765
    for (i_test = 5'd1; i_test <= 5'd19; i_test++) begin
      // Calculate next Fibonacci number in software decimal
      dec_sum = dec_n1 + dec_n2;
      dec_n2  = dec_n1;
      dec_n1  = dec_sum;

      // Convert the decimal sum to BCD format for comparison
      f_test = {4'((dec_sum / 1000) % 10),
                4'((dec_sum / 100)  % 10),
                4'((dec_sum / 10)   % 10),
                4'(dec_sum % 10)};

      // Hardware takes 2 clock cycles: CHECK (01) -> CALC (10) -> CHECK (01)
      @(posedge clk); // moves into CALC
      @(posedge clk); // latches BCD sum into f_n1 and returns to CHECK
      #1;             // sample post-clock after signals settle

      if (f !== f_test) begin
        $display("[Time %0t] MISMATCH at Step %0d! Expected %04h, Got %04h", 
                 $time, i_test, f_test, f);
        errors++;
      end else begin
        $display("[Time %0t] MATCH Step %0d: F(%0d) = %04h (Dec: %0d)", 
                 $time, i_test, i_test + 1, f, dec_sum);
      end
    end

    // 3. Test wrap-around from DONE (11) back to START (00)
    @(posedge clk); // CHECK (01) -> DONE (11)
    @(posedge clk); // DONE (11)  -> START (00)
    @(posedge clk); // START (00) -> CHECK (01)
    #1;
    if (f !== 16'h0001) begin
      $display("[Time %0t] Wrap-around failed! Expected f = 0001 in START, Got %04h", $time, f);
      errors++;
    end else begin
      $display("[Time %0t] Wrap-around SUCCESS! Reset to f = %04h", $time, f);
    end

    // 4. Final Summary
    $display("--------------------------------------------------");
    if (errors == 0) begin
      $display(">> ALL BCD TESTS PASSED SUCCESSFULLY! (0 errors) <<");
    end else begin
      $display(">> SIMULATION FAILED with %0d error(s). <<", errors);
    end
    $display("--------------------------------------------------");

    $finish;
  end

endmodule : fibonacci_test