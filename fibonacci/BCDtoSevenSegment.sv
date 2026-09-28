module BCDtoSevenSegment (
    input  logic [3:0] number,
    output logic [6:0] segment
);

  always_comb begin
    case (number)
      4'd0: segment = 7'b011_1111;
      4'd1: segment = 7'b000_0110;
      4'd2: segment = 7'b101_1011;
      4'd3: segment = 7'b100_1111;
      4'd4: segment = 7'b110_0110;
      4'd5: segment = 7'b110_1101;
      4'd6: segment = 7'b111_1101;
      4'd7: segment = 7'b000_0111;
      4'd8: segment = 7'b111_1111;
      4'd9: segment = 7'b110_0111;
      4'd10: segment = 7'b111_0111;
      4'd11: segment = 7'b111_1100;
      4'd12: segment = 7'b011_1001;
      4'd13: segment = 7'b101_1110;
      4'd14: segment = 7'b111_1001;
      4'd15: segment = 7'b111_0001;
      default: segment = 7'b000_0000;
    endcase
  end

endmodule
