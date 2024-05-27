//Home Work!

//#define HW1
#ifndef HW1
#include <iostream>
#include <math.h> //Математическая библиотека
#include <iomanip>

using namespace std;

class Point //Создаем класс Point
{
	//Создаем поля Класса
	double x;
	double y;

public:
	//Создаем конструкторы и методы класса
	Point()//Конструктор по умолчанию
	{
		this->x = 0;
		this->y = 0;
	};
	Point(double x, double y)//Конструктор с параметрами
	{
		this->x = x;
		this->y = y;
	}
	//Геттеры и Сеттеры для класса
	double GetX()const
	{
		return this->x;
	}
	double GetY()const
	{
		return this->y;
	}
	void SetX(double x)
	{
		this->x = x;
	}
	void SetY(double y)
	{
		this->y = y;
	}
	//Метод класса для подсчета расстояния между точками
	double Distance(Point& object)
	{
		return sqrt(pow((this->x - object.x), 2) + pow((this->y - object.y), 2));
	}
};

//Функция для подсчета расстояния между точками
double Distance(Point& object1, Point& object2)
{
	return sqrt(pow((object1.GetX() - object2.GetX()), 2) + pow((object1.GetY() - object2.GetY()), 2));
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Point A;//Создаем объект А класса Point
	A.SetX(2);//Заполняем поле Х
	A.SetY(2);//Заполняем поле Y

	Point B(3, 3);//Создаем объект B класса Point (заполнение полей через конструктор)

	//cout.precision(3);
	cout << A.Distance(B) << endl;//Выводим резудьтат вычисления через метод класса
	cout << Distance(A, B) << endl;//Выводим результат вычисления через функцию

	system("pause");



	return 0;
}
#endif // HW1


