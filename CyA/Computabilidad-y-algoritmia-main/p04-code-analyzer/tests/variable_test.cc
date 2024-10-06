/// Programa para probar la clase "variable"

#include <iostream>
#include <string>
#include "../variable.cc"

int main() {
  // std::string text = "int number{0};" ;
  // std::string text_2 = "int wawawa = 37;" ;
  // std::string text_3 = "int coso(80);" ;
  // std::string text_4 = "double blabala(4.5);" ;
  // std::string text_5 = "double ajaja;" ;
  // std::string text_6 = "int chucha = -4;" ;
  // std::string text_7 = "int *p = coso;" ;
  // std::string text_8 = "std::string textito = 'coso de string'" ;
  // std::string text_9 = "string textito = 'coso de string'" ;
  std::string text_10 = " variable = algo * otro";
  int line = 4;
  // Variable var1(line, text);
  // std::cout << var1 << std::endl;  
  // Variable var2(line, text_2);
  // std::cout << var2 << std::endl;  
  // Variable var3(line, text_3);
  // std::cout << var3 << std::endl;  
  // Variable var4(line, text_4);
  // std::cout << var4 << std::endl; 
  // Variable var5(line, text_5);
  // std::cout << var5 << std::endl;  
  // Variable var6(line, text_6);
  // std::cout << var6 << std::endl;  
  // Variable var7(line, text_7);
  // // std::cout << var7 << std::endl;  
  // Variable var8(line, text_8);
  // std::cout << var8 << std::endl;
  Variable var10(line, text_10);
  std::cout << var10 << std::endl;
  return 0; 
}