/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: BigInt.h
 *        Contiene la definición de la clase BigInt
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 *    02/01/2023 - Arreglos en el estilo
 */

#include <bits/stdc++.h>
#include <iostream>

#ifndef BIGINT_H
#define BIGINT_H

using namespace std;

class BigInt {
 private:
	string digits_;

 public:
	/// Constructores
	BigInt(unsigned long long n = 0);
	BigInt(string&);
	BigInt(const char *);
	BigInt(const BigInt& num) { digits_ = num.digits_; }; 

	/// Funciones útiles
	friend void divide_by_2(BigInt&);
	friend bool Null(const BigInt&);
	friend int Length(const BigInt& num) { return num.digits_.size(); };
	int Size() { return digits_.size(); };
	int operator[](const int) const;

	/// Asignación directa
	BigInt& operator=(const BigInt&);

	/// Incrementos y decrementos
	BigInt& operator++();
	BigInt operator++(int temp);
	BigInt& operator--();
	BigInt operator--(int temp);

	/// Sumas y restas
	friend BigInt& operator+=(BigInt&, const BigInt&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt& operator-=(BigInt&, const BigInt&);

	/// Comparaciones 
	friend bool operator==(const BigInt& num1, const BigInt& num2) { return num1.digits_ == num2.digits_; };
	friend bool operator!=(const BigInt& num1, const BigInt& num2) { return !(num1 == num2); };

	friend bool operator>(const BigInt& num1, const BigInt& num2) { return num2 < num1; };
	friend bool operator>=(const BigInt& num1, const BigInt& num2) { return !(num1 < num2); };
	friend bool operator<(const BigInt&, const BigInt& b);
	friend bool operator<=(const BigInt& num1, const BigInt& num2) { return !(num1 > num2); };

	/// Multiplicación y división
	friend BigInt& operator*=(BigInt&, const BigInt&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt& operator/=(BigInt&, const BigInt&);
	friend BigInt operator/(const BigInt&, const BigInt&);

	/// Módulo
	friend BigInt operator%(const BigInt&, const BigInt&);
	friend BigInt& operator%=(BigInt&, const BigInt&);

	/// Potencia
	friend BigInt& operator^=(BigInt&, const BigInt&);
	friend BigInt operator^(BigInt&, const BigInt&);
	
	/// Raíz
	friend BigInt sqrt(BigInt&);

	/// Lectura y escritura
	friend ostream& operator<<(ostream&, const BigInt&);
	friend istream& operator>>(istream&, BigInt&);

};

#endif