#include <iostream>
//#define COMMENTS_DEBUG

using namespace std;
class String
{
	int size;   //Размер строки в байтах
	char* str;  //Адрес строки в динамической памяти
public:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
#ifndef COMMENTS_DEBUG
		cout << "DefaultConstructor:\t" << this << endl;
#endif // !COMMENTS_DEBUG
	}
	~String()
	{
		delete[] this->str;
#ifndef COMMENTS_DEBUG
		cout << "Destructor:\t\t" << this << endl;
#endif // !COMMENTS_DEBUG
	}

	//			Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");

	String str;
	str.print();


}