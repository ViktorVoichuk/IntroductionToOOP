#define _CRT_SECURE_NO_WARNINGS

#include "Fraction.h";

//				Overloaded Operators:
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) + (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		(left.get_numerator() * right.get_denominator()) - (right.get_numerator() * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

//Stream - поток
//std - Standard namespase
// :: - Scope operator (Оператор разрешения видимости - позволяет зайти в пространство имен)
// сам по себе :: выводит нас в Globalscope (Глобальное пространство имен)
// namespace (Пространство имен) как папка , а имя, расположенное в нем - как файл
//ostream - output stream (поток вывода)
//istream - input stream (поток ввода)
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	cout << "Введите простую дробь: ";
	const int SIZE = 64;
	char buffer[SIZE]{};
	//is >> buffer;
	is.getline(buffer, SIZE);
	int number[3];
	int n = 0;
	const char delimiters[] = "(/) +";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		// Функция strtok() разделяет строку на токены
		// Функция strtok() изменяет входную строку!!!
		number[n++] = atoi(pch);
	//Функция atoi()- "ASCII string to int" принимает строку и возвращает значение int найденную в этой строке.
	//pch - pointer to character (указатель на символ)
	for (int i = 0; i < n; i++) cout << number[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1: obj = Fraction(number[0]); break;
	case 2: obj = Fraction(number[0], number[1]); break;
	case 3: obj = Fraction(number[0], number[1], number[2]); break;
	}

	return is;
}

int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

//				Constructors:
Fraction::Fraction() :integer(0), numerator(0), denominator(1)
{
#ifndef Comments_debug
	cout << "DefaultConstructor:\t" << this << endl;
#endif // Comments_debug

}
Fraction::Fraction(int integer):Fraction()
{
	this->integer = integer;
#ifndef Comments_debug
	cout << "1ArgConstructorINT:\t" << this << endl;
#endif // Comments_debug
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal * denominator;
	reduce();
#ifndef Comments_debug
	cout << "1ArgConstructorDOUBLE:\t" << this << endl;
#endif // Comments_debug
}
Fraction::Fraction(int numerator, int denominator):Fraction()
{
	this->numerator = numerator;
	this->set_denominator(denominator);
#ifndef Comments_debug
	cout << "Constructor:\t\t" << this << endl;
#endif // Comments_debug
}
Fraction::Fraction(int integer, int numerator, int denominator):Fraction(numerator,denominator)
{
	this->integer = integer;
#ifndef Comments_debug
	cout << "Constructor:\t\t" << this << endl;
#endif // Comments_debug
}
Fraction::Fraction(const Fraction& other):Fraction(other.integer, other.numerator, other.denominator)
{
#ifndef Comments_debug
	cout << "CopyConstrcutor:\t" << this << endl;
#endif // Comments_debug
}
Fraction::~Fraction()
{
#ifndef Comments_debug
	cout << "Destructor:\t\t" << this << endl;
#endif // Comments
}

//				Operators:
Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
#ifndef Comments_debug
	cout << "CopyAssignment:\t\t" << this << endl;
#endif // Comments_debug
	return *this;
}
Fraction& Fraction::operator++()
{
	integer++;
	return *this;
}
Fraction Fraction::operator++(int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction::operator--()
{
	integer--;
	return *this;
}
Fraction Fraction::operator--(int)
{
	Fraction old = *this;
	integer--;
	return old;
}
Fraction& Fraction::operator+=(Fraction other)
{
	this->to_improper();
	other.to_improper();
	this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
	this->denominator = this->denominator * other.denominator;
	this->to_proper();
	return *this;
}
Fraction& Fraction::operator-=(Fraction other)
{
	this->to_improper();
	other.to_improper();
	this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
	this->denominator = this->denominator * other.denominator;
	this->to_proper();
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}

//				Type=cast operators:
Fraction::operator int()
{
	return integer;
}
Fraction::operator double()
{
	this->to_improper();
	return (double(numerator) / denominator);
}

//				Methods:
Fraction& Fraction::to_proper()// Выделение целой части
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction& Fraction::to_improper()// перевод в дробь
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}
Fraction Fraction::inverted() const// переворот дроби
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else more = denominator, less = numerator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more;//CCD-Greatest Common Divesor
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
void Fraction::reduction()
{
	int num = this->numerator, denom = this->denominator, vrem;
	if (num < denom)
	{
		swap(num, denom);
	}
	while (vrem = num % denom)
	{
		num = denom;
		denom = vrem;
	}
	this->numerator /= denom;
	this->denominator /= denom;
}
void Fraction::print() const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer)cout << "(";
		cout << numerator << "/" << denominator;
		if (integer)cout << ")";
	}
	else if (integer == 0) cout << 0;
	cout << endl;
}