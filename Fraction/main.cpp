#define _CRT_SECURE_NO_WARNINGS

#include "Fraction.h";


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

	//int a = (int)A;
	double a = (double)A;

	cout << a << endl;
#endif // !CONVERSIONS_TASK_1

#ifndef CONVERSIONS_TASK_2
	Fraction B = 2.75;
	cout << B << endl;
#endif // !CONVERSIONS_TASK_2

}
