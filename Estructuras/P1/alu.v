module alu(
    output wire [3:0] R,           // Resultado de la operación
    output wire zero, carry, sign, // Flags
    input wire [3:0] A, B,         // Operandos A y B
    input wire c_in,               // Carry de entrada
    input wire [2:0] Op            // Operación a realizar
);

    // Señales intermedias
    wire [3:0] AMod, BMod, logic_out, sum_out;
    wire c_out;

    // Preprocesamiento de A y B
    preprocess PREP(.AMod(AMod), .BMod(BMod), .A(A), .B(B), .Op(Op));

    // Suma de AMod y BMod
    sum4 SUM(.S(sum_out), .c_out(c_out), .A(AMod), .B(BMod), .c_in(c_in));

    // Operaciones lógicas
    ul4 UL(.Out(logic_out), .A(A), .B(B), .S(Op[1:0])); // Operaciones lógicas seleccionadas por Op[1:0]

    // Selección del resultado final
    mux2_4 MUX(.Out(R), .A(sum_out), .B(logic_out), .s(Op[2]));

    // Flags de la ALU
    assign carry = (Op == 3'b001 || Op == 3'b010) ? c_out : 1'b0;  // Solo en operaciones aritméticas
    assign zero  = (R == 4'b0000) ? 1'b1 : 1'b0;                   // Zero flag se activa si el resultado es 0000
    assign sign  = R[3];                                           // Sign flag toma el bit más significativo del resultado


endmodule
