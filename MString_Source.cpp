#include <iostream>
#include <cstring>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>
using namespace std;

#include "MString.h"

// _CRT_SECURE_NO_WARNINGS
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MString a1;
	MString a2;
	MString a3;
	MString a4;
	MString a5;

	cin >> a1;
	cin >> a2;
	cout << endl;

	cout << a1;
	cout << a2;
	cout << endl;

	cout << "a3=a1+a2" << endl;
	a3 = a1 + a2;
	cout << a3;
	cout << endl;

	cout << "Зададим две строки для сравнения" << endl;
	cin >> a4;
	cin >> a5;
	cout << "0-разные, 1-одинаковые" << endl;
	cout << (a4 == a5) << endl;
	cout << endl;

	cout << "Операция += для двух предыдущих строк:" << endl;
	a4 += a5;
	cout << a4 << endl;

	cout << a4[3];

	//cin.get();
	//cin.get();
	return 0;
}