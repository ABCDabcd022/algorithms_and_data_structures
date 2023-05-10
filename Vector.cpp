#include <iostream>
#include <fstream>
using namespace std;
//extern std::ofstream cout;

#include "Vector.h"

// ���������� �� ���������
Vector::Vector()
{
	size = 3;
	arr = new double[3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = 0;
	}
}
// ���������� ������������� 1
Vector::Vector(int  size1)
{
	arr = new double[size1];
	size = size1;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}
// ���������� ������������� 2
Vector::Vector(int  size1, double* val)
{
	size = size1;
	arr = new double[size];
	for (int i = 0; i < size; i++)
		arr[i] = val[i];
}
// ���������� ������������� 3
Vector::Vector(int  size1, double val)
{
	size = size1;
	arr = new double[size];
	for (int i = 0; i < size; i++)
		arr[i] = val;
}
// ���������� �����������
Vector::Vector(const Vector& vec) {
	size = vec.size;
	arr = new double[size];
	for (int i = 0; i < size; ++i)
		arr[i] = vec.arr[i];
}
// ����������
Vector::~Vector() {
	if (size != NULL)
	{
		delete[] arr;
		size = 0;
	}
}
// ����� �� �������
void Vector::outPut(const char* name) {
	cout << name << ": ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ",\t";
	cout << endl;
}

void Vector::outPut(const char* name) const {
	cout << name << ": ";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ",\t";
	cout << endl;
}

// ���������� ��������

// ��� ������ � ������
double& Vector::operator[](int index) {
	if (index < 0 || index >= size)
		abort(); // �������������� ���������� ���������
	return arr[index];
}

// ������ ��� ������ � ����������� ������� � ��������
const double& Vector::operator[](int index) const {
	if (index < 0 || index >= size)
		abort(); // �������������� ���������� ���������
	return arr[index];
}

// �������� ������������	
Vector& Vector::operator=(const Vector& vec) {
	if (this != &vec) { // �� ���� ����������� ���� ����!
		if (size != vec.size)
		{
			delete[] arr;
			size = vec.size;
			arr = new double[size];
		}
		for (int i = 0; i < size; ++i)
			arr[i] = vec.arr[i];
	}
	return *this;
}

// �������� ������������
Vector  Vector::operator+(const Vector& vec) 
{
	if (size != vec.size)
	{
		if (size > vec.size)
		{
			Vector res(size);
			for (int i = 0; i < vec.size; i++)
				res.arr[i] = arr[i] + vec.arr[i];
			for (int j = vec.size; j < size; j++)
				res.arr[j] = arr[j];

			return res;
		}

		if (vec.size > size)
		{
			Vector res(vec.size);
			for (int i = 0; i < size; i++)
				res.arr[i] = arr[i] + vec.arr[i];
			for (int j = size; j < vec.size; j++)
				res.arr[j] = vec.arr[j];

			return res;
		}
	}
	else
	{
		Vector res(size);
		for (int i = 0; i < size; ++i)
			res.arr[i] = arr[i] + vec.arr[i];
		return res;
	}
}

Vector  Vector::operator-(const Vector& vec) 
{
	if (size != vec.size)
	{
		if (size > vec.size)
		{
			Vector res(size);
			for (int i = 0; i < vec.size; i++)
				res.arr[i] = arr[i] - vec.arr[i];
			for (int j = vec.size; j < size; j++)
				res.arr[j] = (-1) * arr[j];

			return res;
		}

		if (vec.size > size)
		{
			Vector res(vec.size);
			for (int i = 0; i < size; i++)
				res.arr[i] = arr[i] - vec.arr[i];
			for (int j = size; j < vec.size; j++)
				res.arr[j] = (-1) * vec.arr[j];

			return res;
		}
	}
	else
	{
		Vector res(size);
		for (int i = 0; i < size; ++i)
			res.arr[i] = arr[i] - vec.arr[i];
		return res;
	}
}

// �������� ���������� ������������
double  Vector::operator*(const Vector& vec) 
{
		if (size != vec.size)
		{
			if (size > vec.size)
			{
				double res = 0.0;
				for (int i = 0; i < vec.size; i++)
					res += arr[i] * vec.arr[i];
				return res;
			}
			if (vec.size > size)
			{
				double res = 0.0;
				for (int i = 0; i < size; i++)
					res += arr[i] * vec.arr[i];
				return res;
			}
		}
		else
		{
			double res = 0.0;
			for (int i = 0; i < size; ++i)
				res += arr[i] * vec.arr[i];
			return res;
		}
}

// �������� ��������� ��������������� �� ������
Vector  operator*(double d, const Vector& vec) 
{
	Vector res(vec.size);
	for (int i = 0; i < vec.size; ++i)
		res.arr[i] = d * vec.arr[i];
	return res;
}

// ����� � �����
ostream& operator<<(ostream& stream, const Vector& vec) 
{
	stream <<" ";
	for (int i = 0; i < vec.size; ++i)
		stream << vec.arr[i] << " ";

	return stream;
}

// ���� �� ������
istream& operator>>(istream& stream, Vector& vec) 
{
	int strCount;
	cout << "������� ���������� ���������." << endl;
	stream >> strCount;
	if (strCount < 0)
	{
		strCount = strCount * (-1);
	}

	if (vec.size != strCount)
	{
		if (vec.arr != NULL)
			delete[] vec.arr;
		vec.size = strCount;
		vec.arr = new double[strCount];
	}
	for (int i = 0; i < vec.size; i++)
	{
		stream >> vec.arr[i];
	}
	return stream;

}


