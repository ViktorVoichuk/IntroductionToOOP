#include <iostream>

using namespace std;
#define delimiter "___________________________________________________________________________"

class Fraction
{
	int numerator; //Делимое
	int denominator; //Делитель
	int whole_part; //Целая часть

	void reduction()//Метод сокращения
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
	void wholepart()//Метод выделяющий целую часть
	{
		if (numerator > denominator)
		{
			whole_part = numerator / denominator;
			this->numerator = numerator - denominator * whole_part;
		}
	}  
public:
	//				Constructors:
	Fraction() //Конструктор по умолчанию
	{
		numerator = denominator = 1;
		whole_part = 0;
		reduction();
		wholepart();
		cout << "DefaultConstructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator) //Конструктор с параметрами
	{
		this->numerator = numerator;
		this->denominator = denominator;
		this->whole_part = 0;
		reduction();
		wholepart();
		cout << "Constructor:\t\t\t" << this << endl;
	}
	Fraction(const Fraction& other)// Конструктор копирования
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		this->whole_part = 0;
		reduction();
		wholepart();
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~Fraction()// Деструктор
	{
		cout << "Destructor:\t\t\t" << this << endl;
	}
	//				Operators:
	Fraction& operator=(const Fraction& other) //Оператор копирования
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
	Fraction operator++(int)//Постфиксный инкремент
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

//				Overloaded Operators:
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