#include "Header.h"
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	Polinom A;
	Polinom B;
	//pMonom a = new Monom(10, 10);
	//pMonom a1 = new Monom(10, 10);
	
	//b.Input();
	//A.Insert(a);
	//A.Insert(a1);
	//cout << endl;
	cout << "Ââîä A:" << endl;
	cin >> A;
	//cout << endl;
	cout << A;
	cout << endl;
	//Polinom C(A);
	//cout << C << endl;
	cout << "Ââîä B:" << endl;
	cin >> B;
	//cout << endl;
	cout << B;
	cout << endl;
	cout << endl;
	cout << A << endl;
	cout << '+' << endl;
	cout << B << endl;
	cout << '=' << endl;
	Polinom Q = A + B;
	cout << Q << endl;
	cout << endl;
	cout << endl;
	//cout << A + B << endl;
	//A+=B;
	//cout << A << endl;

	cout << A << endl;
	cout << "+= " << endl;
	cout << B << endl;
	cout << "A = " << endl;
	A+=B;
	cout << A << endl;
	cout << "Â = " << endl;
	cout << B << endl;

	return 0;
}
