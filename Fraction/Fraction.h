#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include<iostream>
#define Comments_debug
#define delimetr		"_______________________________________________________________"
#define double_delimetr "==============================================================="
#define CONSTRUCTORS_CHECK
#define ARITHMETICAL_OPERATORS_CHECK
#define COMPARISON_OPERATORS_CHECK
#define STREAM_CHECK
#define TIPE_CONVERSIONS_BASICS
#define CONVEERSIONS_FROM_OTHER_TO_CLASS
#define CONVEERSIONS_FROM_CLASS_TO_OTHER
//#define CONVERSIONS_TASK_1
//#define CONVERSIONS_TASK_2

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

	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				Constructors:
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//				Operators:
	Fraction& operator=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);
	Fraction& operator+=(Fraction other);
	Fraction& operator-=(Fraction other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);

	//				Type=cast operators:
	explicit operator int();
	explicit operator double();

	//				Methods:
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction inverted()const;
	Fraction& reduce();
	void reduction();
	void print()const;
};

//				Overloaded Operators:

Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

std::ostream& operator<<(std::ostream& os, const Fraction& obj);
std::istream& operator>>(std::istream& is, Fraction& obj);