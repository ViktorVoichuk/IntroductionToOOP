//IntroductionToOOP

#include <iostream>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------------\n"

//Создавая структуру или класс мы создаем новый тип данных
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		//x = -2;	//must be a modieble l-value
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++()//Префиксный инкремент
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)//Постфиксный инкремент
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	//				Methods:
	double distance(const Point& other)const
	{
		//this - этот
		//other - другой
		///////////////////////
		//this - эта точка
		//other - та точка
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//other.x *= 100;
		//this->x *= 100;
		return distance;
	}
	void print()const
	{
		cout << this << ":X = " << x << "\tY = " << y << endl;
	}

};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
	//Функция sqrt() возвращает квадратный корень принятого числа
}

Point operator+(const Point& left, const Point& right)//Через функции.
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
Point operator-(const Point& left, const Point& right)//Через конструктор
{
	Point result
	(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}
Point operator/(const Point& left, const Point& right)
{
	return Point
	(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}
bool operator==(const Point& left, const Point& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
	{
		return true;
	}
	else
	{
		return false;
	}*/
}

#define STRUCT_POINT
#define DISTANCE_CHECK
#define CONSTRUCTORS_CHECK
#define ASSIGNMENT_CHECK
#define ARITHMETICAL_OPERATORS_CHECK


void main()
{
	setlocale(LC_ALL, "");

#ifndef STRUCT_POINT
	cout << "Hello OOP" << endl;
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
	//Создание объекта 'A' структуры 'Point'
	//Создание экземпляра 'A' структуры 'Point'

	cout << sizeof(A) << endl;
	cout << sizeof(Point) << endl;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//Pointer to 'A'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifndef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK

#ifndef CONSTRUCTORS_CHECK
	/*for (int i = 0; i < 10; i++)
{
	cout << i << "\t";
}*/
//cout << i << "\t";

	Point A;	//Default constructor
	A.print();

	Point B = 5;
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;	//Copy constructor
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifndef ASSIGNMENT_CHECK
	//Point A(2, 3);	//Constructor
//Point B;		//Default constructor
//B = A;			//Copy assignment
//B.print();

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

#ifndef ARITHMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();

	Point C = A + B;
	C.print();

	C = A - B;
	C.print();

	C = A * B;
	C.print();

	C = A / B;
	C.print();

	C++;
	C.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	//cout << (2 == 3) << endl;
	cout << (Point(2, 3) == Point(2, 3)) << endl;
}

/*
------------------------------------------------
.  - Оператор прямого доступа (Point operator)
	 Используется для доступа к полям объекта по имени объекта.
-> - Оператор косвенного доступа (Arrow operator)
	 Используется для доступа к полям объекта по адресу объекта.
------------------------------------------------
*/

/*
------------------------------------------------
			OOP concepts
1. Инкапсуляция (Encapsulation) - это сокрытие определенной части класса от внешнего мира;
	Модификаторы доступа:
		private:	закрытые поля, к ним можно получить доступ только внутри класса;
		public:		открытые поля, к ним можно получить доступ откуда угодно;
		protected:	защищенные поля. Этот модификатор доступа используется только при наследовании.
					protected-поля доступны внутри нашего класса, и его дочерних классов.

		get/set-методы позволяеют получить доступ к закрытым переменным в классе.
		get (взять, получить) методы	- открывают доступ к закрытым переменным на чтение,
										  т.е., позволяют ВЗЯТЬ(ПОЛУЧИТЬ) значение закрытой переменной;
		set (задать, установить) методы - открывают доступ к закрытым переменным на запись,
										  т.е., позволяют задать значения закрытых переменных.
										  Кроме того, set-методы обеспечиваю фильтрацию данных,
										  т.е., предотвращают попадание некорректных значений
										  в переменные члены класса.

2. Наследование (Inheritance);
3. Полиморфизм  (Polymorphism);
------------------------------------------------
*/

/*
------------------------------------------------
1. Constructor - это метод, который создает объект, а именно,
   выделяет память под объект, и инициализирует его поля при создании;
	-с параметрами;
	-без параметров;
	-конструктор по умолчанию (Default constructor);
	-конструктор копирования;
		Побитовое копирование	(Deep copy);
		Повехностное копирование(Shallow copy); Debug assertion failed
	-конструктор переноса;
2. ~Destructor  - это метод, который уничтожает объект по завершении его времени жизни.
3. Assignment operator;
------------------------------------------------
*/

/*
------------------------------------------------
			Operators overloading rules:
1. Перегрузить можно только существующие операторы,
   создавать новые операторы невозможно.
   Например:
	+  - перегружается;
	++ - перегружается;
	%  - перегружается;
	%% - НЕ перегружается;
2. Не все существующие операторы можно перегрузить,
   НЕ перегружаются:
	?: - Conditional Ternary operator;
	:: - Scope operator (Оператор разрешения видимости);
	.  - Оператор прямого доступа (Point operator);
	.* - Pointer to member selection;
	#  - Preprocessor convert to string;
	## - Preprocessor concatenate;
3. Перегруженные операторы сохраняют приоритет;
4. Переопределить поведение операторов над встроенными типами данных НЕВОЗМОЖНО;
------------------------------------------------
	operator@
------------------------------------------------
*/