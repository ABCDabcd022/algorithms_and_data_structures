#include <iostream>
#include "Vector.h"
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	float q = 10;
	double val[4] = { 1, 2, 3, 4 };

	Vector a;
	Vector b(4);
	Vector c(4, val);
	Vector d(5, 4);

	int w;
	cout << "Если хотите ввести число, нажмите 1." << endl;
	cin >> w;
	if (w == 1)
	{
		Vector a1;
		cin >> a1;
		cout << "a1 = " << a1 << endl;
		Vector a2;
		a2 = a1;
		cout << "a2 = a1" << endl << endl;
		cout << "a2 = " << a2 << endl;
	}

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << endl;

	cout << c << '+' << d << '=' << d + c << endl;
	cout << c << '-' << d << '=' << c - d << endl;
	cout << "(c;d)" << '=' << d * c << endl;

	cout << endl;

	cout << 100 << '*' << c << '=' << 100 * c << endl;

	cout << endl;

	cout << c[3] << endl;
	cout << c[3]++ << endl;
	cout << c[3] << endl;

	return 0;
}
