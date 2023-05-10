#include <iostream>
#include <cstring>

using namespace std;

#include "MString.h"

MString::MString()       //  онстуктор по умолчанию
{
	leng = 1;
	str = new char[leng];
	str[0] = '\0';
	//cout << " * онстуктор по умолчанию выполнен*" << endl;
}

MString::MString(int _leng) //  онстуктор инициализатор
{
	leng = _leng + 1;
	str = new char[leng];
	str[0] = '\0';
	//cout << " * онстуктор инициализатор выполнен*" << endl;
}

MString::MString(const MString& cms)  //  онстуктор копировани€
{
	leng = cms.leng;
	str = new char[leng];
	strcpy(str, cms.str);
	//cout << " * онстуктор копировани€ выполнен*" << endl;
}

MString::MString(const char* cstr) //  онстуктор преобразовани€ типа
{
	leng = strlen(cstr) + 1;
	str = new char[leng];
	strcpy(str, cstr);
	//cout << " * онстуктор преобразовани€ типа выполнен*" << endl;
}

MString::~MString()  // ƒеструктор
{
	if (leng)
		delete[]str;
	leng = 0;
	//cout << " *ƒеструктор выполнен*" << endl;
}

char& MString::operator[](int index)  // операци€ индексации
{
	if ((index < leng) && (index >= 0))
		return str[index];
	else
		return str[0];
}

MString MString::operator+(MString& _str)  //  перегрузка суммировани€
{
	int size;
	int k = 0;
	int s = 0;
	size = _str.leng + leng - 1;
	MString tmp(size);
	for (int i = 0; str[i] != '\0'; i++)
	{
		tmp[i] = str[i];
		k++;
	}
	for (int i = 0; _str[i] != '\0'; i++)
	{
		tmp[k + i] = _str[i];
		s = k + i;
	}
	tmp[s + 1] = '\0';
	//cout << " *перегрузка суммировани€ выполнена*" << endl;
	return tmp;
}

istream& operator>>(istream& stream, MString& _str)  // перегрузка ввода
{
	char* word;
	word = new char[500];
	cout << "Ќапишите слово:" << endl;
	stream >> word;
	_str.leng = strlen(word);
	_str = new char[_str.leng];

	for (int i = 0; i < _str.leng; i++)
		_str[i] = word[i];

	//cout << " *перегрузка ввода выполнена*" << endl;
	return stream;
}

ostream& operator<<(ostream& stream, MString& _str) // перегрузка вывода
{
	for (int i = 0; _str[i] != '\0'; i++)
		stream << _str[i];
	cout << endl;
	//cout << " *перегрузка вывода выполнена*" << endl;
	return stream;
}

MString& MString::operator=(const MString& _str) // операци€ присваивани€
{
	if (this != &_str)
	{
		if (leng != 0)
			delete[]str;
		leng = _str.leng;
		str = new char[_str.leng];
		strcpy(str,_str.str); //!!!
			
	}
	//cout << " *перегрузка присваивани€ выполнена*" << endl;
	return *this;
}

bool MString::operator== (const MString& t) const  // операци€ сравнени€
{
	return leng == t.leng && strcmp(str, t.str) == 0;
}

MString& MString::operator+=(const MString& _str)
{
	int newLength = leng + _str.leng;
	char* newStr = new char[newLength + 1];
	strcpy(newStr, str);
	strcat(newStr, _str.str);
	delete[] str;
	str = newStr;
	leng = newLength;
	//cout << " *перегрузка += выполнена*" << endl;
	return *this;
}
