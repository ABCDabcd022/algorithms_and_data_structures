#pragma once
#include <fstream> 
#include <cstring>

using namespace std;

class MString
{
private:
	char* str;
	int leng;
public:
	MString();                      // Констуктор по умолчанию
	MString(int _leng);             // Констуктор инициализатор
	MString(const MString& cms);     // Констуктор копирования
	MString(const char* cstr);      // Констуктор преобразования типа
	~MString();                     // Деструктор

	

	MString& operator=(const MString& _str);  // операция присваивания
	MString& operator+=(const MString& _str); // операция + присваивания
	MString operator+(MString& _str);   // операция объединения
	bool operator==(const MString& t)const;      // операция сравнения
	char& operator[](int index);            // операция индексации

	friend istream& operator>>(istream& stream, MString& _str); // ввод
	friend ostream& operator<<(ostream& stream, MString& _str); // вывод
	//friend MString operator+(const char* cstr, const MString& _str);

};
