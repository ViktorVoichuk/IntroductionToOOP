#include <iostream>

using namespace std;
#define delimiter "___________________________________________________________________________"

class Fraction
{
	int numerator;
	int denominator;
	int whole_part;

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
	void wholepart()
	{
		if (numerator > denominator)
		{
			whole_part = numerator / denominator;
			this->numerator = numerator - denominator * whole_part;
		}
	}
public:
	//				Constructors:
	Fraction()
	{
		numerator = denominator = 1;
		whole_part = 0;
		reduction();
		wholepart();
		cout << "DefaultConstructor:\t\t" << this << endl;
	}
	Fraction(double numerator, double denominator)
	{
		this->numerator = numerator;
		this->denominator = denominator;
		this->whole_part = 0;
		reduction();
		wholepart();
		cout << "Constructor:\t\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->whole_part = 0;
		reduction();
		wholepart();
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t\t" << this << endl;
	}
	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->whole_part = other.whole_part;
		cout << "CopyAssignment:\t\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()//Префиксный инкремент
	{
		numerator += denominator * whole_part;
		numerator++;
		denominator++;
		whole_part = 0;
		reduction();
		wholepart();
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		numerator += denominator * whole_part;
		numerator++;
		denominator++;
		whole_part = 0;
		reduction();
		wholepart();
		return old;
	}
	//				Methods:
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	int get_wholepart()const
	{
		return whole_part;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	void print()const
	{
		if (numerator == 0)
		{
			cout << "Nasha drob' imeet tcelii vid:\t" << whole_part << endl;
		}
		else if (whole_part > 0)
		{
			cout << "Nasha drob': " << whole_part << " " << numerator << "/" << denominator << endl;
		}
		else
		{
			cout << "Nasha drob': " << numerator << "/" << denominator << endl;
		}
	}
};

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		((left.get_denominator() * left.get_wholepart() + left.get_numerator()) * right.get_denominator()) + ((right.get_denominator() * right.get_wholepart() + right.get_numerator()) * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator-(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		((left.get_denominator() * left.get_wholepart() + left.get_numerator()) * right.get_denominator()) - ((right.get_denominator() * right.get_wholepart() + right.get_numerator()) * left.get_denominator()),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator*(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		(left.get_denominator() * left.get_wholepart() + left.get_numerator()) * (right.get_denominator() * right.get_wholepart() + right.get_numerator()),
		left.get_denominator() * right.get_denominator()
	);
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		(left.get_denominator() * left.get_wholepart() + left.get_numerator()) * (right.get_denominator() * right.get_wholepart() + right.get_numerator()),
		left.get_denominator() * right.get_numerator()
	);
}

void main()
{
	setlocale(LC_ALL, "Russian");

	
	Fraction A(5, 3);
	A.print();

	cout << delimiter << endl;
	Fraction B(4, 8);
	B.print();

	cout << delimiter << endl;
	Fraction C;
	C = A + B;
	C.print();

	cout << delimiter << endl;
	C++;
	C.print();

}