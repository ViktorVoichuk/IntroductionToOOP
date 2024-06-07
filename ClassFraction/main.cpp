#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define Comments_debug
#define delimetr		"_______________________________________________________________"
#define double_delimetr "==============================================================="

using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:

	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
#ifndef Comments_debug
		cout << "DefaultConstructor:\t" << this << endl;
#endif // Comments_debug

	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
#ifndef Comments_debug
		cout << "1ArgConstructor:\t" << this << endl;
#endif // Comments_debug
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifndef Comments_debug
		cout << "Constructor:\t\t" << this << endl;
#endif // Comments_debug
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
#ifndef Comments_debug
		cout << "Constructor:\t\t" << this << endl;
#endif // Comments_debug
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifndef Comments_debug
		cout << "CopyConstrcutor:\t" << this << endl;
#endif // Comments_debug
	}
	~Fraction()
	{
#ifndef Comments_debug
		cout << "Destructor:\t\t" << this << endl;
#endif // Comments
	}

	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifndef Comments_debug
		cout << "CopyAssignment:\t\t" << this << endl;
#endif // Comments_debug
		return *this;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	Fraction& operator+=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;
		this->to_proper();
		return *this;
	}
	Fraction& operator-=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		this->denominator = this->denominator * other.denominator;
		this->to_proper();
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//				Type=cast operators:
	explicit operator int()
	{
		return integer;
	}

	//				Methods:
	Fraction& to_proper()// Выделение целой части
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()// перевод в дробь
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction inverted()const// переворот дроби
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
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
	void reduction()
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
	void print()const
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
};

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
//std::istream& operator>>(std::istream& is, Fraction& obj)
//{
//	int integer, numerator, denominator;
//	cout << "Fill in object" << endl;
//	cout << "Enter integer: ";
//	is >> integer;
//
//	cout << "Enter numerator: ";
//	is >> numerator;
//
//	cout << "Enter denominator: ";
//	is >> denominator;
//
//	obj.set_integer(integer);
//	obj.set_numerator(numerator);
//	obj.set_denominator(denominator);
//
//	return is;
//}
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
	case 2: obj = Fraction(number[0],number[1]); break;
	case 3: obj = Fraction(number[0],number[1],number[2]); break;
	}

	return is;
}

#define CONSTRUCTORS_CHECK
#define ARITHMETICAL_OPERATORS_CHECK
#define COMPARISON_OPERATORS_CHECK
#define STREAM_CHECK
#define TIPE_CONVERSIONS_BASICS
#define CONVEERSIONS_FROM_OTHER_TO_CLASS
#define CONVEERSIONS_FROM_CLASS_TO_OTHER
#define CONVERSIONS_TASK_1
#define CONVERSIONS_TASK_2

void main()
{
	setlocale(LC_ALL, "ru");

#ifndef CONSTRUCTORS_CHECK
	Fraction A;		//Default constructor
	A.print();

	Fraction B = 5;	//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifndef ARITHMETICAL_OPERATORS_CHECK

	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction A(2, 3, 4);
	//cin >> A;
	A.print();
	//cout << A;

	Fraction B(3, 4, 5);
	B.print();

	cout << "Operator == :\t";
	cout << (A == B) << endl;

	cout << "Operator != :\t";
	cout << (A != B) << endl;

	cout << "Operator > :\t";
	cout << (A > B) << endl;

	cout << "Operator < :\t";
	cout << (A < B) << endl;

	cout << "Operator >= :\t";
	cout << (A >= B) << endl;

	cout << "Operator <= :\t";
	cout << (A <= B) << endl;

	cout << "Operator + :\t";
	Fraction C = A + B;
	C.print();
	cout << "Operator - :\t";
	C = A - B;
	C.print();
	cout << "Operator * :\t";
	C = A * B;
	C.print();
	cout << "Operator / :\t";
	C = A / B;
	C.print();
	cout << "Operator -- :\t";
	C--;
	C.print();
	cout << "Operator ++ :\t";
	C++;
	C.print();
	cout << "Operator += :\t";
	A += B;
	A.print();
	cout << "Operator -= :\t";
	A -= B;
	A.print();
	cout << "Operator *= :\t";
	A *= B;
	//A.reduction();
	A.print();
	cout << "Operator /= :\t";
	A /= B;
	//A.reduction();
	A.print();

	A.print();
	B.print();
#endif // !ARITHMETICAL_OPERATORS_CHECK

#ifndef COMPARISON_OPERATORS_CHECK
	cout << (2 == 3) << endl;
	cout << (Fraction(1, 2) == Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
	cout << (Fraction(1, 3) > Fraction(5, 11)) << endl;
	cout << (Fraction(1, 3) < Fraction(5, 11)) << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 10)) << endl;
	cout << (Fraction(1, 3) >= Fraction(5, 11)) << endl;
#endif // !COMPARISON_OPERATORS_CHECK

#ifndef STREAM_CHECK
	Fraction A(2, 3, 4);

	cin >> A;

	cout << A << endl;
#endif // !STREAM_CHECK

#ifndef TIPE_CONVERSIONS_BASICS
	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more
	int c = b;		//Converse from more to less withaut dataloss
	int d = 2.5;	//Cinverse from more to less with data loss

#endif // !TIPE_CONVERSIONS_BASICS

#ifndef CONVEERSIONS_FROM_OTHER_TO_CLASS

	Fraction A = (Fraction)5; //Convertation from 'int' to 'Fraction'
	//Single-Argument constructor
	cout << A << endl;

	cout << double_delimetr << endl;
	Fraction B; //defaul constructor

	cout << delimetr << endl;

	B = Fraction(8);		//Convertation from 'int' to 'Fraction'
	//Single-Argument constructor
	//Copy assignment
	cout << B << endl;

	cout << double_delimetr << endl;
#endif // !CONVEERSIONS_FROM_OTHER_TO_CLASS

#ifndef CONVERSIONS_TASK_1
	Fraction A(2, 3, 4);
	cout << A << endl;

	int a = (int)A;
	double a = A;

	cout << a << endl;
#endif // !CONVERSIONS_TASK_1

#ifndef CONVERSIONS_TASK_2
	Fraction B = 2.75;
	cout << B << endl;
#endif // !CONVERSIONS_TASK_2

}


