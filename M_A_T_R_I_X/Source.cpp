#include <iostream>
#include <clocale>
#include "Header.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	int q;
	cout << "������� ������ ������. " << endl;
	do
	{
		cin >> q;
	} while (q <= 0);

		TMatrix<int> A(q);
		TMatrix<int> B(q);
		TMatrix<int> C(q);
		TMatrix<int> D(q);

		cout << "������� ������� �. " << endl;
		cin >> A;
		cout << "������� ������� �. " << endl;
		cin >> B;
		C = A + B;
		D = A - B;

		cout << "Matrix A = " << endl << A << endl;
		cout << "Matrix B = " << endl << B << endl;
		cout << "Matrix C = A + B" << endl << C << endl;
		cout << "Matrix D = A - B" << endl << D << endl;

}
