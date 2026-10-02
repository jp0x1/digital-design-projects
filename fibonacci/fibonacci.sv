`default_nettype none

// module to compute fibonacci numbers up to the 4th digit on
// the seven segment displays on basys3, then wrap back around
module Fibonacci #(parameter COUNT_PERIOD = 50_000_000)
  (input  logic clk,
   input  logic rst_n,
   output logic [15:0] f);
  
  // counter to delay 
  logic [31:0] delay_counter;

  // limit of 20 fibonacci numbers for BCD
  logic [4:0] n,
              new_n;

  logic [1:0] state; // state: START, CHECK, CALC, DONE
  logic [1:0] next_state;
  // logic ready, done; // flags  check and transition
  // // one computation overflows past 2^13 or 12th bit(?)
  // logic overflow_12; 

  // f_{n-1} and f_{n-2} registers?
  logic [15:0] f_n1,
               f_n2,
               next_f_n1,
               next_f_n2,
               adder_sum;

  // next state combinational logic
  // determine the transition to the next state
  
  BcdAdder16 alu (
      .A   (f_n1),
      .B   (f_n2),
      .sum (adder_sum)
  );

  always_comb begin
    case (state)
      2'b00 : begin // start
        next_f_n1 = 16'b1;
        next_f_n2 = 16'b0;
        new_n = 5'b0;
        next_state = 2'b01;
      end
      2'b01 : begin // check
        // if it reached the 20th number, go to done
        // else move on to calc
        next_f_n1 = f_n1;
        next_f_n2 = f_n2;
        new_n = n;
        if (n == 5'd19) begin
          next_state = 2'b11;
        end
        else begin
          if (delay_counter == COUNT_PERIOD) begin
            next_state = 2'b10; // simulate a delay?
          end
        end
      end
      2'b10 : begin // calc
        // increment counter
        // generate new fibonacci number
        next_f_n1 = adder_sum;
        next_f_n2 = f_n1;
        new_n = n + 1;
        next_state = 2'b01; // transition back to check
      end
      2'b11 : begin // done
        // hold onto values, but transition back to start
        next_f_n1 = f_n1;
        next_f_n2 = f_n2;
        new_n = n;
        next_state = 2'b00;
      end
      default: begin // default
        // just remain in the same state if error
        next_f_n1 = f_n1;
        next_f_n2 = f_n2;
        new_n = n;
        next_state = state;
      end
    endcase
  end

  always_ff @(posedge clk, negedge rst_n) begin
    if (~rst_n) begin // reset
      state <= 2'b00; // back to start state
      f_n1 <= 16'b1;
      f_n2 <= 16'b0;
      n <= 5'b0;
    end
    // transition to the next state
    else begin
      state <= next_state;
      f_n1 <= next_f_n1;
      f_n2 <= next_f_n2;
      n <= new_n;
    end
  end
  
  // output combinational logic output new fibonacci number
  assign f = f_n1;
  

endmodule : Fibonacci
