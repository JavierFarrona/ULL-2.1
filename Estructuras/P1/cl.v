/// Celda lógica

module cl(output wire out, input wire a, b, input wire [1:0] S);
  /// Cables de salidas
  wire and_out, or_out, xor_out, not_out;

  /// Operaciones
  and and1 (and_out, a, b);
  or or1 (or_out, a, b);
  xor xor1 (xor_out, a, b);
  not not1 (not_out, a);

  /// Multiplexor para selecionar
  mux4_1 mux (out, and_out, or_out, xor_out, not_out, S);

endmodule
