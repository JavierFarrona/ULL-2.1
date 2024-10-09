/// Full Adder
/// Con concatenación

module fa(output wire c_out, sum, input wire a, b, c_in);
  /// Asignación: c_out | suma
  ///             [1]     [0]
  assign {c_out, sum} = a + b + c_in;

endmodule