//Home Work!

//#define HW1
#ifndef HW1
#include <iostream>
#include <math.h> //�������������� ����������
#include <iomanip>

using namespace std;

class Point //������� ����� Point
{
	//������� ���� ������
	double x;
	double y;

public:
	//������� ������������ � ������ ������
	Point()//����������� �� ���������
	{
		this->x = 0;
		this->y = 0;
	};
	Point(double x, double y)//����������� � �����������
	{
		this->x = x;
		this->y = y;
	}
	//������� � ������� ��� ������
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
	//����� ������ ��� �������� ���������� ����� �������
	double Distance(Point& object)
	{
		return sqrt(pow((this->x - object.x), 2) + pow((this->y - object.y), 2));
	}
};

//������� ��� �������� ���������� ����� �������
double Distance(Point& object1, Point& object2)
{
	return sqrt(pow((object1.GetX() - object2.GetX()), 2) + pow((object1.GetY() - object2.GetY()), 2));
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Point A;//������� ������ � ������ Point
	A.SetX(2);//��������� ���� �
	A.SetY(2);//��������� ���� Y

	Point B(3, 3);//������� ������ B ������ Point (���������� ����� ����� �����������)

	//cout.precision(3);
	cout << A.Distance(B) << endl;//������� ��������� ���������� ����� ����� ������
	cout << Distance(A, B) << endl;//������� ��������� ���������� ����� �������

	system("pause");



	return 0;
}
#endif // HW1


