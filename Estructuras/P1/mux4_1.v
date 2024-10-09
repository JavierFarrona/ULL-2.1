/// Multiplexor 4 a 1 con entradas de 1 bit

module mux4_1(output reg out, input wire a, b, c, d, input wire [1:0] S);

  /// Lista de sensibilidad
  always @(a or b or c or d or S) 

  /// No hace falta begin y end porque el always contiene una sola sentencia, el case
    case (S)  
      /// Dos bits en binario            
      2'b00: out = a;
      2'b01: out = b;
      2'b10: out = c;
      2'b11: out = d;

      default: out = 'bx; /// Desconocido en cualquier otro caso     
    endcase

endmodule
