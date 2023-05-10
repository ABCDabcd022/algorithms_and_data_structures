#include <iostream>
#include "TComplex.h"
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	float q = 10;

	TComplex a;
	TComplex b(2, 2);
	TComplex c(b);
	TComplex d(q);

	int w;
	cout << "Если хотите ввести число, нажмите 1." << endl;
	cin >> w;
	if (w == 1)
	{
		TComplex a1;
		cin >> a1;
		cout << a1 << endl;
	}

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << endl;

	cout << b << '+' << c << '=' << b.Add(c) << endl;
	cout << b << '-' << c << '=' << b.Sub(c) << endl;
	cout << b << '*' << c << '=' << b.Mult(c) << endl;
	cout << b << '/' << c << '=' << b.Divi(c) << endl;

	cout << endl;

	cout << b << '+' << c << '=' << b + c << endl;
	cout << b << '-' << c << '=' << b - c << endl;
	cout << b << '*' << c << '=' << b * c << endl;
	cout << b << '/' << c << '=' << b / c << endl;

	cout << endl;

	cout << 100 << '*' << c << '=' << 100 * c << endl;
	cout << c << '*' << 100 << '=' << c * 100 << endl;

	cout << endl;

	if (b == c)
	{
		cout << b <<  " == ? " << c << endl;
		cout << "Да. Равны " << endl;
		cout << b << "=" << c << endl;
	}
	if (b != a)
	{
		cout << b << " == ? " << a << endl;
		cout << "Нет. Не равны " << endl;
		cout << b << "!=" << a << endl;
	}
	cout << endl;

	TComplex e;
	e = c++;
	cout << e << endl;
	e = ++c;
	cout << e << endl;

	cout << endl;

	c = c;
	a = b;

	return 0;
}
