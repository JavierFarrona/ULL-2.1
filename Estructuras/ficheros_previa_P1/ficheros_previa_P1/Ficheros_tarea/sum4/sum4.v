//Sumador de 4 bits 
module sum4(output wire[3:0] S, output wire c_out, input wire[3:0] A, input wire[3:0] B, input wire c_in);
	// Contenido
	wire[3:0] sum1;

	wire c1, c2, c3;

	fa_vr fa1(sum1[0], c1, A[0], B[0], c_in);

	fa_vr fa2(sum1[1], c2, A[1], B[1], c1);

	fa_vr fa3(sum1[2], c3, A[2], B[2], c2);

	fa_vr fa4(sum1[3], c_out, A[3], B[3], c3);
	
	assign S = sum1;

endmodule

