/// Complemento a 1

module compl1(output wire [3:0] Out, input wire [3:0] Inp, input wire cpl);
  /// Hace el complemento cuando cpl es 1
  xor xor0(Out[0], Inp[0], cpl);
  xor xor1(Out[1], Inp[1], cpl);
  xor xor2(Out[2], Inp[2], cpl);
  xor xor3(Out[3], Inp[3], cpl);

endmodule