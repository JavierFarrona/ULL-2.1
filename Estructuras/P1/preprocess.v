module preprocess(output wire [3:0] AMod, BMod, input wire [3:0] A, B, input wire [2:0] Op);

    wire add1, op1_A, op2_B, cpl;
    wire [3:0] AComp, BComp;

    // Control de señales
    assign add1  = (Op == 3'b001);                   // Sumar 1 para el complemento a 2
    assign op1_A = (Op == 3'b000);                   // Identidad de A
    assign op2_B = (Op == 3'b010);                   // Suma A + B
    assign cpl   = (Op == 3'b100);                   // Negativo de A

    // Complemento a 1 si es necesario
    compl1 COMP_A(AComp, A, cpl);

    // Selección de AMod usando mux2_4
    mux2_4 MUX_A(AMod, AComp, A, op1_A);  // Si op1_A es 1, pasa A sin modificar

    // B debe ser ignorado en identidad (Op = 000)
    assign BMod = (Op == 3'b000) ? 4'b0000 : B;  // En identidad, BMod debe ser 0000

endmodule
