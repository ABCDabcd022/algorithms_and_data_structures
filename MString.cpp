#include <iostream>
#include <cstring>

using namespace std;

#include "MString.h"

MString::MString()       // ���������� �� ���������
{
	leng = 1;
	str = new char[leng];
	str[0] = '\0';
	//cout << " *���������� �� ��������� ��������*" << endl;
}

MString::MString(int _leng) // ���������� �������������
{
	leng = _leng + 1;
	str = new char[leng];
	str[0] = '\0';
	//cout << " *���������� ������������� ��������*" << endl;
}

MString::MString(const MString& cms)  // ���������� �����������
{
	leng = cms.leng;
	str = new char[leng];
	strcpy(str, cms.str);
	//cout << " *���������� ����������� ��������*" << endl;
}

MString::MString(const char* cstr) // ���������� �������������� ����
{
	leng = strlen(cstr) + 1;
	str = new char[leng];
	strcpy(str, cstr);
	//cout << " *���������� �������������� ���� ��������*" << endl;
}

MString::~MString()  // ����������
{
	if (leng)
		delete[]str;
	leng = 0;
	//cout << " *���������� ��������*" << endl;
}

char& MString::operator[](int index)  // �������� ����������
{
	if ((index < leng) && (index >= 0))
		return str[index];
	else
		return str[0];
}

MString MString::operator+(MString& _str)  //  ���������� ������������
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
	//cout << " *���������� ������������ ���������*" << endl;
	return tmp;
}

istream& operator>>(istream& stream, MString& _str)  // ���������� �����
{
	char* word;
	word = new char[500];
	cout << "�������� �����:" << endl;
	stream >> word;
	_str.leng = strlen(word);
	_str = new char[_str.leng];

	for (int i = 0; i < _str.leng; i++)
		_str[i] = word[i];

	//cout << " *���������� ����� ���������*" << endl;
	return stream;
}

ostream& operator<<(ostream& stream, MString& _str) // ���������� ������
{
	for (int i = 0; _str[i] != '\0'; i++)
		stream << _str[i];
	cout << endl;
	//cout << " *���������� ������ ���������*" << endl;
	return stream;
}

MString& MString::operator=(const MString& _str) // �������� ������������
{
	if (this != &_str)
	{
		if (leng != 0)
			delete[]str;
		leng = _str.leng;
		str = new char[_str.leng];
		strcpy(str,_str.str); //!!!
			
	}
	//cout << " *���������� ������������ ���������*" << endl;
	return *this;
}

bool MString::operator== (const MString& t) const  // �������� ���������
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
	//cout << " *���������� += ���������*" << endl;
	return *this;
}
