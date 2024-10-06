/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Computabilidad y Algoritmia
 * Práctica 12: Divide y vencerás
 *
 * @author Esther M. Quintero (alu0101434780@ull.edu.es)
 * @date 01 Ene 2023
 * @brief Archivo: BigInt.cc
 *        Contiene la implementación de la clase Multiplicacion
 * 
 * @details 
 *    01/01/2023 - Creación del fichero
 *    02/01/2023 - Arreglos en el estilo
 *    02/01/2023 - Arreglos en la sobrecarga del >>
 */

#include "BigInt.h"


/** 
 *  @brief Constructor
 *  @param[in] num String con el número
 *  @return No devuelve nada
 */
BigInt::BigInt(string& num) {
	digits_ = "";
	int n = num.size();
	for (int i = n - 1; i >= 0; i--) {
		if(!isdigit(num[i])) throw("ERROR");
		char pp = num[i]  - '0';
		digits_.push_back(pp);
	}
}

// BigInt::BigInt(string& num) {
// 	digits_ = "";
// 	int n = num.size();
// 	for (int i = n - 1; i >= 0; i--) {
// 		if(!isdigit(num[i])) throw("ERROR");
// 		digits_.push_back(num[i] - '0');
// 	}
// }

/** 
 *  @brief Constructor
 *  @param[in] num Unsigned long long con el número
 *  @return No devuelve nada
 */
BigInt::BigInt(unsigned long long num) {
	do {
		digits_.push_back(num % 10);
		num /= 10;
	} while (num);
}

/** 
 *  @brief Constructor
 *  @param[in] s Char con el número
 *  @return No devuelve nada
 */
BigInt::BigInt(const char *num) {
	digits_ = "";
	for (int i = strlen(num) - 1; i >= 0; i--) {
		if(!isdigit(num[i])) throw("ERROR");
		digits_.push_back(num[i] - '0');
	}
}

/** 
 *  @brief Comprueba si está vacío
 *  @param[in] a Número para comprobar
 *  @return True si está vacío, false si no
 */
bool Null(const BigInt& num) {
	if (num.digits_.size() == 1 && num.digits_[0] == 0) return true;
	return false;
}

/** 
 *  @brief Sobrecarga del operador []
 *  @param[in] index Índice al que se quiere acceder
 *  @return Valor del índice
 */
int BigInt::operator[](const int index) const {
	if (digits_.size() <= index || index < 0) throw("ERROR");
	return digits_[index];
}

/** 
 *  @brief Sobrecarga del operador <
 *  @param[in] index Índice al que se quiere acceder
 *  @return Valor del índice
 */
bool operator<(const BigInt& num1, const BigInt& num2) {
	int length1 = Length(num1), length2 = Length(num2);
	if(length1 != length2) return length1 < length2;
	while(length1--)
		if(num1.digits_[length1] != num2.digits_[length1]) 
			return num1.digits_[length1] < num2.digits_[length1];
	return false;
}

/** 
 *  @brief Sobrecarga del operador =
 *  @param[in] num Número al que se quiere igualar
 *  @return Referencia al número
 */
BigInt& BigInt::operator=(const BigInt& num) {
	digits_ = num.digits_;
	return *this;
}

/** 
 *  @brief Sobrecarga del operador ++
 *  @return Referencia al número
 */
BigInt& BigInt::operator++() {
	int i, size = digits_.size();
	for (i = 0; (i < size) && (digits_[i] == 9); i++) digits_[i] = 0;
	if (i == size) digits_.push_back(1);
	else digits_[i]++;
	return *this;
}

/** 
 *  @brief Sobrecarga del operador ++
 *  @param[in] temp 
 *  @return Número con el ++
 */
BigInt BigInt::operator++(int temp) {
	BigInt aux;
	aux = *this;
	++(*this);
	return aux;
}

/** 
 *  @brief Sobrecarga del operador --
 *  @return Referencia al número
 */
BigInt& BigInt::operator--() {
	if (digits_[0] == 0 && digits_.size() == 1) throw("UNDERFLOW");
	int i, size = digits_.size();
	for (i = 0; digits_[i] == 0 && i < size; i++) digits_[i] = 9;
	digits_[i]--;
	if(size > 1 && digits_[size - 1] == 0) digits_.pop_back();
	return *this;
}

/** 
 *  @brief Sobrecarga del operador --
 *  @param[in] temp 
 *  @return Número con el --
 */
BigInt BigInt::operator--(int temp) {
	BigInt aux;
	aux = *this;
	--(*this);
	return aux;
}

/** 
 *  @brief Sobrecarga del operador +=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 += num2
 */
BigInt& operator+=(BigInt& num1, const BigInt& num2) {
	int t = 0, s, i;
	int n = Length(num1), m = Length(num2);
	if (m > n) num1.digits_.append(m - n, 0);
	n = Length(num1);
	for (i = 0; i < n; i++) {
		if (i < m) s = (num1.digits_[i] + num2.digits_[i]) + t;
		else s = num1.digits_[i] + t;
		t = s / 10;
		num1.digits_[i] = (s % 10);
	}
	if (t) num1.digits_.push_back(t);
	return num1;
}

/** 
 *  @brief Sobrecarga del operador +
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 + num2
 */
BigInt operator+(const BigInt& num1, const BigInt& num2) {
	BigInt temp;
	temp = num1;
	temp += num2;
	return temp;
}

/** 
 *  @brief Sobrecarga del operador -=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 -= num2
 */
BigInt &operator-=(BigInt& num1, const BigInt& num2) {
	if (num1 < num2)
		throw("UNDERFLOW");
	int n = Length(num1), m = Length(num2);
	int i, t = 0, s;
	for (i = 0; i < n; i++) {
		if (i < m) s = num1.digits_[i] - num2.digits_[i]+ t;
		else s = num1.digits_[i]+ t;
		if (s < 0) s += 10, t = -1;
		else t = 0;
		num1.digits_[i] = s;
	}
	while (n > 1 && num1.digits_[n - 1] == 0)
		num1.digits_.pop_back(),
		n--;
	return num1;
}

/** 
 *  @brief Sobrecarga del operador -
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 - num2
 */
BigInt operator-(const BigInt& num1, const BigInt& num2) {
	BigInt temp;
	temp = num1;
	temp -= num2;
	return temp;
}

/** 
 *  @brief Sobrecarga del operador *=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 *= num2
 */
BigInt& operator*=(BigInt& num1, const BigInt& num2) {
	if (Null(num1) || Null(num2)) {
		num1 = BigInt();
		return num1;
	}
	int n = num1.digits_.size(), m = num2.digits_.size();
	vector<int> v(n + m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			v[i + j] += (num1.digits_[i] ) * (num2.digits_[j]);
		}
	n += m;
	num1.digits_.resize(v.size());
	for (int s, i = 0, t = 0; i < n; i++) {
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
		num1.digits_[i] = v[i] ;
	}
	for (int i = n - 1; i >= 1 && !v[i]; i--) num1.digits_.pop_back();
	return num1;
}

/** 
 *  @brief Sobrecarga del operador *
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 * num2
 */
BigInt operator*(const BigInt& num1, const BigInt& num2) {
	BigInt temp;
	temp = num1;
	temp *= num2;
	return temp;
}

/** 
 *  @brief Sobrecarga del operador /=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 /= num2
 */
BigInt& operator/=(BigInt& num1, const BigInt& num2) {
	if (Null(num2)) throw("Arithmetic Error: Division By 0");
	if (num1 < num2){
		num1 = BigInt();
		return num1;
	}
	if (num1 == num2) {
		num1 = BigInt(1);
		return num1;
	}
	int i, lgcat = 0, cc;
	int n = Length(num1), m = Length(num2);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + num1.digits_[i] < num2; i--){
		t *= 10;
		t += num1.digits_[i] ;
	}
	for (; i >= 0; i--) {
		t = t * 10 + num1.digits_[i];
		for (cc = 9; cc * num2 > t; cc--);
		t -= cc * num2;
		cat[lgcat++] = cc;
	}
	num1.digits_.resize(cat.size());
	for (i = 0; i < lgcat; i++) num1.digits_[i] = cat[lgcat - i - 1];
	num1.digits_.resize(lgcat);
	return num1;
}

/** 
 *  @brief Sobrecarga del operador /
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 / num2
 */
BigInt operator/(const BigInt& num1, const BigInt& num2) {
	BigInt temp;
	temp = num1;
	temp /= num2;
	return temp;
}

/** 
 *  @brief Sobrecarga del operador %=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 %= num2
 */
BigInt& operator%=(BigInt& num1, const BigInt& num2) {
	if (Null(num2)) throw("Arithmetic Error: Division By 0");
	if (num1 < num2) return num1;
	if (num1 == num2) {
		num1 = BigInt();
		return num1;
	}
	int i, lgcat = 0, cc;
	int n = Length(num1), m = Length(num2);
	vector<int> cat(n, 0);
	BigInt t;
	for (i = n - 1; t * 10 + num1.digits_[i] < num2; i--){
		t *= 10;
		t += num1.digits_[i];
	}
	for (; i >= 0; i--) {
		t = t * 10 + num1.digits_[i];
		for (cc = 9; cc * num2 > t; cc--);
		t -= cc * num2;
		cat[lgcat++] = cc;
	}
	num1 = t;
	return num1;
}

/** 
 *  @brief Sobrecarga del operador %
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 % num2
 */
BigInt operator%(const BigInt& num1, const BigInt& num2) {
	BigInt temp;
	temp = num1;
	temp %= num2;
	return temp;
}

/** 
 *  @brief Sobrecarga del operador ^=
 *  @param[out] num1 
 *  @param[in] num2 
 *  @return num1 ^= num2
 */
BigInt& operator^=(BigInt& num1, const BigInt& num2) {
	BigInt Exponent, Base(num1);
	Exponent = num2;
	num1 = 1;
	while (!Null(Exponent)) {
		if (Exponent[0] & 1) num1 *= Base;
		Base *= Base;
		divide_by_2(Exponent);
	}
	return num1;
}

/** 
 *  @brief Sobrecarga del operador ^
 *  @param[in] num1 
 *  @param[in] num2 
 *  @return num1 ^ num2
 */
BigInt operator^(BigInt& num1, BigInt& num2) {
	BigInt temp(num1);
	temp ^= num2;
	return temp;
}

/** 
 *  @brief Divide a la mitad el número
 *  @param[out] num
 *  @return void
 */
void divide_by_2(BigInt& num) {
	int add = 0;
	for (int i = num.digits_.size() - 1; i >= 0; i--){
		int digit = (num.digits_[i] >> 1) + add;
		add = ((num.digits_[i] & 1) * 5);
		num.digits_[i] = digit;
	}
	while(num.digits_.size() > 1 && !num.digits_.back()) num.digits_.pop_back();
}

/** 
 *  @brief Calcula la raíz cuadrada del número
 *  @param[out] num
 *  @return Raíz cuadrada de num
 */
BigInt sqrt(BigInt& num) {
	BigInt left(1), right(num), v(1), mid, prod;
	divide_by_2(right);
	while (left <= right) {
		mid += left;
		mid += right;
		divide_by_2(mid);
		prod = (mid * mid);
		if (prod <= num) {
			v = mid;
			++mid;
			left = mid;
		} else {
			--mid;
			right = mid;
		}
		mid = BigInt();
	}
	return v;
}

/** 
 *  @brief Sobrecarga del operador >>
 *  @param[in] in
 *  @param[in] num
 */
istream& operator>>(istream& in, BigInt& num) {
	string str;
	in >> str;
	BigInt bigint(str);
	num = bigint;
	return in;
}

/** 
 *  @brief Sobrecarga del operador <<
 *  @param[in] out
 *  @param[in] num
 */
ostream& operator<<(ostream& out, const BigInt& num) {
	for (int i = num.digits_.size() - 1; i >= 0; i--) out << (short)num.digits_[i];
	return out;
}