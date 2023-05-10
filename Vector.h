#include <fstream> 
#include <iostream>
using namespace std;
#pragma once
const int maxsize = 5;
class Vector
{
	double* arr;
	int size = maxsize;

public:
	Vector();        //  онстуктор по умолчанию
	explicit Vector(int size);    //  онстуктор инициализатор
	Vector(int size, double val);   //  онстуктор инициализатор
	Vector(int  size, double* val); //  онстуктор инициализатор
	Vector(const Vector& vec);      //  онстуктор копировани€
	~Vector();                      // ƒеструктор
	// вывод на консоль
	void outPut(const char* name);
	void outPut(const char* name) const;

	// ѕерегрузка операций
	double& operator[](int index);       // дл€ чтени€ и записи
	const double& operator[](int index) const; // только дл€ чтени€ в константных методах и объектах

	Vector& operator=(const Vector& vec); // операци€ присваивани€
	Vector  operator+(const Vector& vec); // операци€ суммировани€
	Vector  operator-(const Vector& vec); // операци€ суммировани€
	double  operator*(const Vector& vec); // операци€ скал€рного произведени€
	friend Vector  operator*(double d, const Vector& vec); // операци€ умножени€ действительного на вектор
	friend ostream& operator<<(ostream& stream, const Vector& vec); // вывод в поток
	friend istream& operator>>(istream& stream, Vector& vec); // ввод из потока
};






