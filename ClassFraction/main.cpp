#include<iostream>
#define Comments_debug

using namespace std;


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
	Fraction(int integer)
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
	Fraction& operator*=(Fraction other)
	{
		this->to_improper();
		other.to_improper();
		this->numerator = this->numerator * other.numerator;
		this->denominator = this->denominator * other.denominator;
		this->to_proper();
		return *this;
	}
	Fraction& operator/=(Fraction other)
	{
		return *this *= other.inverted();
	}
	friend void operator<<(ostream& object, const Fraction& other)
	{
		if (other.integer)object << other.get_integer();
		if (other.numerator)
		{
			if (other.integer)object << "(";
			object << other.numerator << "/" << other.denominator;
			if (other.integer)object << ")";
		}
		else if (other.integer == 0) object << 0;
		cout << endl;
	}
	friend istream& operator>>(istream& object, Fraction& other)
	{
		cout << "Enter integer: ";
		object >> other.integer;

		cout << "Enter numerator: ";
		object >> other.numerator;

		cout << "Enter denominator: ";
		object >> other.denominator;

		return object;
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
	void reduction()
	{
		int num = this->numerator, denom = this->denominator, vrem;
		if (num < denom)
		{
			int temp = num;
			num = denom;
			denom = temp;
		}
		while (vrem = num % denom)
		{
			num = denom;
			denom = vrem;
		}
		this->numerator = this->numerator / denom;
		this->denominator = this->denominator / denom;
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
	).to_proper();
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
	left.reduction();
	right.reduction();
	return ((left.get_numerator() == right.get_numerator()) && (left.get_denominator() == right.get_denominator()));
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) > (right.get_numerator() / right.get_denominator()));
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return ((left.get_numerator() / left.get_denominator()) < (right.get_numerator() / right.get_denominator()));
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return (left > right || left == right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return (left < right || left == right);
}



//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "ru");

#ifdef CONSTRUCTORS_CHECK
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

	double a = 2;
	double b = 3;
	double c = a * b;

	Fraction A;(2, 3, 4);
	cin >> A;
	A.print();
	cout << A;

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
	A.print();
	cout << "Operator /= :\t";
	A /= B;
	A.print();

	A.print();
	B.print();
}