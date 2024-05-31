#include<iostream>
using namespace std;

class MyString
{
private:
	char* str;//символы, которые мы передали в объект.
	int length;

public:

	MyString()//конструктор без параметров
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char* str)//конструктор с параметрами
	{
		length = strlen(str);//длинна строки
		this->str = new char[length + 1] {};// создаем динамический массив где будет храниться наша строка +1 для \0

		for (int i = 0; i < length; i++)// копируем символы строки в массив
		{
			this->str[i] = str[i];
		}
	}

	~MyString()
	{
		delete[] this->str;
	}

	MyString(const MyString& other)// конструктор копирования
	{
		length = strlen(other.str);
		this->str = new char[length + 1] {};

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
	}

	MyString& operator =(const MyString& other)// оператор копирования
	{
		if (this == &other)return *this;
		delete[] str;
		
		length = strlen(other.str);
		this->str = new char[length + 1] {};

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		return *this;
	}

	MyString operator+(const MyString& other)// сложение строк
	{
		MyString newStr;//временный объект

		//количество символов в обеих строках
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 2] {};// место под новую строку

		//копируем данные из 2х строк в новую строку
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		newStr.str[i] = ' ';
		i++;
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		return newStr;
	}

	void Print()
	{
		cout << str;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");

	MyString str("Hello");
	str = str;
	MyString str2("World");
	MyString str3;
	str3 = str + str2;

	str3.Print();
	cout << endl << endl;

	system("pause");
	return 0;
}