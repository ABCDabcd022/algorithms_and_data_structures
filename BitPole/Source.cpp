#include <iostream>
#include <clocale>
#include "TBitField.h"
#include "TSet.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
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
	cout << "Значение бита №3:" << endl;
	cout << a.GetBit(3) << '\n';
	cout << "Значение бита №4:" << endl;
	cout << a.GetBit(4) << '\n';
	a.ClrBit(3);
	cout << "Бит №3 обнулён:" << endl;
	cout << a << '\n';
	
	TSet A(a);
	A = A + 8;
	TSet B(b);
	B = B + 9;
	cout << "Множество A:" << endl;
	cout << A << '\n';
	cout << "Множество B:" << endl;
	cout << B << '\n';
	cout << "A + B:" << endl;
	cout << A + B << '\n';
	cout << "A * B:" << endl;
	cout << A * B << '\n';
	cout << "~B:" << endl;
	cout << ~B << '\n';
}
