#pragma once
#include <iostream>
#include <istream>
using namespace std;
class Monom;
class Polinom;
typedef Monom* pMonom;

class Monom
{
	double coef;
	int pow;
	pMonom pNext;
public:
	Monom(double _coef, int _pow);
	int operator > (const Monom& p);
	int operator == (const Monom& p);
	void Input();
	pMonom GetpNext() { return pNext; };

	friend Polinom;
};

Monom::Monom(double _coef, int _pow)
{
	coef = _coef;
	pow = _pow;
	pNext = nullptr;
}

int Monom::operator>(const Monom& p)
{
	return pow > p.pow;
}

int Monom::operator==(const Monom& p)
{
	return pow == p.pow;
}

inline void Monom::Input()
{
	int px = pow / 100;
	int py = (pow - 100 * px) / 10;
	int pz = pow - 100 * px - 10 * py;
	cout << coef << "x^(" << px << ')';
	cout << "y^(" << py << ')';
	cout << "z^(" << pz << ')';
}



class Polinom
{
	pMonom pFirst;
public:
	Polinom();
	Polinom(const Polinom& p);
	void Del();
	~Polinom();
	pMonom Search(const Monom& m, int& find);
	void Insert(pMonom new_m);
	friend std::istream& operator >> (istream& is, Polinom& p);
	friend ostream& operator << (ostream& os, const Polinom& s);
	Polinom  operator+(const Polinom& p);
	Polinom& operator+=(const Polinom& p);
};

Polinom::Polinom()
{
	pFirst = new Monom(0, -1);
	pFirst->pNext = pFirst;
}

inline Polinom::Polinom(const Polinom& p)
{
	pFirst = new Monom(0, -1);
	pFirst->pNext = pFirst;
	pMonom q = p.pFirst->pNext;
	pMonom w, nm;
	while (q != p.pFirst)
	{
		nm = new Monom(q->coef, q->pow);
		this->Insert(nm);

		w = q->pNext;
		q = w;
	}
}

inline void Polinom::Del()
{
	if (pFirst->pNext != pFirst)
	{
		pMonom tmp = pFirst->pNext;
		pFirst->pNext = tmp->pNext;
		delete tmp;
	}
}

inline Polinom::~Polinom()
{
	while (pFirst->pNext != pFirst)
	{
		this->Del();
	}
	delete pFirst;
}

inline pMonom Polinom::Search(const Monom& m, int& find)
{
	pMonom prew = pFirst;
	pMonom cur = prew->pNext;
	find = 0;

	while (*cur > m)
	{
		prew = cur;
		cur = prew->pNext;
	}
	if (*cur == m) { find = 1; };
	return prew;
}

inline void Polinom::Insert(pMonom new_m)
{
	pMonom car, tmp;
	int find = 0;
	tmp = Search(*new_m, find);
	if (find)
	{
		car = tmp->pNext;
		car->coef += new_m->coef;
		if (car->coef == 0)
		{
			tmp->pNext = car->pNext;
			delete car;
		}
		delete new_m;
	}
	else
	{
		new_m->pNext = tmp->pNext;
		tmp->pNext = new_m;
	}
}


inline Polinom& Polinom::operator+=(const Polinom& p)
{
	pMonom q = p.pFirst->pNext;
	pMonom w, nm, tmp, r, g, pq;
	int find = 0;
	pq = p.pFirst;
	while (q != p.pFirst)
	{
		/*
		nm = new Monom(q->coef, q->pow);
		this->Insert(nm);
		w = q->pNext;
		q = w;
		*/
		tmp = Search(*q, find);
		if (find)
		{
			nm = new Monom(q->coef, q->pow);
			this->Insert(nm);
			w = q->pNext;
			pq = q;
			q = w;
		}
		else
		{
			//r = tmp->pNext;
			//tmp->pNext = q;
			pq->pNext = q->pNext;
			this->Insert(q);
			//q->pNext = r;

			w = pq->pNext;
			//pq = q;
			q = w;
		}
	}
	return *this;
}



inline Polinom Polinom::operator+(const Polinom& p)
{
	Polinom Q;
	//cout << '1'<< Q << endl;
	pMonom q = p.pFirst->pNext;

	pMonom w, nm;
	//cout << "p-" << p << endl;
	while (q != p.pFirst)
	{
		nm = new Monom(q->coef, q->pow);
		Q.Insert(nm);
		
		w = q->pNext;
		q = w;
	}
	//cout << Q << endl;

	q = this->pFirst->pNext;
	
	while (q != this->pFirst)
	{
		nm = new Monom(q->coef, q->pow);
		Q.Insert(nm);
		w = q->pNext;
		q = w;
	}
	//cout << Q << endl;
	return Q;
}


inline std::istream& operator>>(istream& is, Polinom& p)
{
	pMonom new_m;
	double k;
	int px, py, pz, answer = 1;
	while (answer)
	{
		do
		{
			cout << "Введите коэффициент" << endl;
			is >> k;
		} while (k == 0);
		do
		{
			cout << "Введите степень X" << endl;
			is >> px;
		} while ((px < 0) || (px > 9));
		do
		{
			cout << "Введите степень Y" << endl;
			is >> py;
		} while ((py < 0) || (py > 9));
		do
		{
			cout << "Введите степень Z" << endl;
			is >> pz;
		} while ((pz < 0) || (pz > 9));
		new_m = new Monom(k, 100 * px + 10 * py + pz);
		p.Insert(new_m);
		cout << "Продолжить?" << endl;
		is >> answer;
	}
	return is;
}

inline ostream& operator<<(ostream& os, const Polinom& s)
{
	pMonom q = s.pFirst->GetpNext();
	pMonom w = nullptr;
	while (q != s.pFirst)
	{
		q->Input();
		if (q->GetpNext() != s.pFirst)
		{
			cout << '+';
		}
		w = q->GetpNext();
		q = w;
	}
	q = s.pFirst->GetpNext();
	if (q == s.pFirst)
	{
		cout << '0';
	}
	return os;
}

