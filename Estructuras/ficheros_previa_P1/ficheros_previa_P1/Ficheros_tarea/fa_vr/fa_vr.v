//Sumador completo (full-adder) de tres entradas de 1 bit realizado a partir de puertas l�gicas 

module fa_vr(output wire sum, output wire c_out, input wire a, input wire b, input wire c_in);

  //declaracion de se�ales internas
  wire sum1, c1, sum2, c2;

  ha_vr ha1(sum1, c1, a, b);

  ha_vr ha2(sum2, c2, sum1, c_in);

  assign sum = sum2;  

  or or1(c_out, c1, c2);
  
endmodule

