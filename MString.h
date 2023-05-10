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
	MString();                      // ���������� �� ���������
	MString(int _leng);             // ���������� �������������
	MString(const MString& cms);     // ���������� �����������
	MString(const char* cstr);      // ���������� �������������� ����
	~MString();                     // ����������

	

	MString& operator=(const MString& _str);  // �������� ������������
	MString& operator+=(const MString& _str); // �������� + ������������
	MString operator+(MString& _str);   // �������� �����������
	bool operator==(const MString& t)const;      // �������� ���������
	char& operator[](int index);            // �������� ����������

	friend istream& operator>>(istream& stream, MString& _str); // ����
	friend ostream& operator<<(ostream& stream, MString& _str); // �����
	//friend MString operator+(const char* cstr, const MString& _str);

};
