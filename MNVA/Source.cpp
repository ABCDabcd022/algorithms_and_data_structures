#include <iostream>
#include <clocale>
#include "TBitField.h"
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	/* 
	TBitField a(10);
	a.SetBit(1);
	a.SetBit(3);
	a.SetBit(5);
	a.SetBit(7);
	a.SetBit(9);
	a.SetBit(30);
	cout << a << '\n';
	TBitField b(100);

	cout << b << '\n';
	cout << "�������� ���� �3:" << endl;
	cout << a.GetBit(3) << '\n';
	cout << "�������� ���� �4:" << endl;
	cout << a.GetBit(4) << '\n';
	a.ClrBit(3);
	cout << "��� �3 ������:" << endl;
	cout << a << '\n';

	TSet A(a);
	A = A + 8;
	TSet B(b);
	B = B + 10;
	cout << "��������� A:" << endl;
	cout << A << '\n';
	TBitField aa(A);
	cout << aa;
	cout << "��������� B:" << endl;
	cout << B << '\n';
	cout << "A + B:" << endl;
	cout << A + B << '\n';
	cout << "A * B:" << endl;
	cout << A * B << '\n';
	cout << "~B:" << endl;
	cout << ~B << '\n';
	TSet C(40);
	cout << "������� ���������" << '\n';
	cin >> C;
	cout << C << '\n';
	*/

	TSet A(10);
	cout << "������� A." << endl;
	cin >> A;
	cout << A << endl;

	TSet B(10);
	cout << "������� B." << endl;
	cin >> B;
	cout << B << endl;

	cout << "�����������:" << endl;
	cout << "A + B:" << endl;
	cout << A + B << '\n';
	cout << "�����������:" << endl;
	cout << "A * B:" << endl;
	cout << A * B << '\n';
	cout << "����������:" << endl;
	cout << "~A:" << endl;
	cout << ~A << '\n';
	cout << "����������:" << endl;
	cout << "~B:" << endl;
	cout << ~B << '\n';

	TBitField a(A);
	cout << a << endl;
	
	TBitField b(B);
	cout << b << endl;

	TSet A1(a);
	cout << A1 << endl;

	TSet B1(b);
	cout << B1 << endl;
}
