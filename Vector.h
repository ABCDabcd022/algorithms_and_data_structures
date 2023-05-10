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
	Vector();        // ���������� �� ���������
	explicit Vector(int size);    // ���������� �������������
	Vector(int size, double val);   // ���������� �������������
	Vector(int  size, double* val); // ���������� �������������
	Vector(const Vector& vec);      // ���������� �����������
	~Vector();                      // ����������
	// ����� �� �������
	void outPut(const char* name);
	void outPut(const char* name) const;

	// ���������� ��������
	double& operator[](int index);       // ��� ������ � ������
	const double& operator[](int index) const; // ������ ��� ������ � ����������� ������� � ��������

	Vector& operator=(const Vector& vec); // �������� ������������
	Vector  operator+(const Vector& vec); // �������� ������������
	Vector  operator-(const Vector& vec); // �������� ������������
	double  operator*(const Vector& vec); // �������� ���������� ������������
	friend Vector  operator*(double d, const Vector& vec); // �������� ��������� ��������������� �� ������
	friend ostream& operator<<(ostream& stream, const Vector& vec); // ����� � �����
	friend istream& operator>>(istream& stream, Vector& vec); // ���� �� ������
};






