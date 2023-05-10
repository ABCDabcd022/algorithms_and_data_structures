#include <iostream>
#include <fstream>
#include "TComplex.h"

using namespace std;

TComplex::TComplex()
{
	Re = 0;
	Im = 0;
	//cout << "Конструктор по умолчанию." << endl;
}

TComplex::TComplex(float _Re, float _Im)
{
	Re = _Re;
	Im = _Im;
	//cout << "Конструктор инициализации." << endl;
}

TComplex::TComplex(const TComplex& copy)
{
	Re = copy.Re;
	Im = copy.Im;
	//cout << "Конструктор копирования." << endl;
}

TComplex::TComplex(float q)
{
	Re = q;
	Im = 0;
	//cout << "Конструктор преобразования типа." << endl;
}

float TComplex::GetRe()
{
	return Re;
}

float TComplex::GetIm()
{
	return Im;
}

void TComplex::SetRe(float re)
{
	Re = re;
}

void TComplex::SetIm(float im)
{
	Im = im;
}

void TComplex::Print()
{
	if (Re != 0)
	{
		cout << Re;
		if (Im > 0)
		{
			cout << "+" << Im << "i";
		}
		if (Im < 0)
		{
			cout << Im << "i";
		}
		cout << endl;
	}
	if ((Re == 0) && (Im == 0))
	{
		cout << "0" << endl;
	}
}

TComplex TComplex::Add(const TComplex& op2)
{
	TComplex res;
	res.Re = Re + op2.Re;
	res.Im = Im + op2.Im;
	return res;
}

TComplex TComplex::Sub(const TComplex& su)
{
	TComplex res;
	res.Re = Re - su.Re;
	res.Im = Im - su.Im;
	return res;
}

TComplex TComplex::Mult(const TComplex& mult)
{
	TComplex res;
	res.Re = Re * (mult.Re) - Im * (mult.Im);
	res.Im = Re * (mult.Im) + Im * (mult.Re);
	return res;
}

TComplex TComplex::Divi(const TComplex& d)
{
	if (((d.Re) * (d.Re) - (d.Im) * (d.Im)) == 0)
	{
		TComplex res;
		res.Re = (Re * (d.Re) + Im * (d.Im)) / ((d.Re) * (d.Re) + (d.Im) * (d.Im));
		res.Im = (Im * (d.Re) - Re * (d.Im)) / ((d.Re) * (d.Re) + (d.Im) * (d.Im));
		return res;
	}
	else
	{
		cout << "На ноль не делится" << endl;
		return 0; // ??
	}
}

TComplex TComplex::operator + (const TComplex& op2)
{
	TComplex res;
	res.Re = Re + op2.Re;
	res.Im = Im + op2.Im;
	return res;
}

TComplex TComplex::operator - (const TComplex& su)
{
	TComplex res;
	res.Re = Re - su.Re;
	res.Im = Im - su.Im;
	return res;
}

TComplex TComplex::operator * (const TComplex& mult)
{
	TComplex res;
	res.Re = Re * (mult.Re) - Im * (mult.Im);
	res.Im = Re * (mult.Im) + Im * (mult.Re);
	return res;
}

TComplex TComplex::operator / (const TComplex& d)
{
	if (((d.Re) * (d.Re) - (d.Im) * (d.Im)) == 0)
	{
		TComplex res;
		res.Re = (Re * (d.Re) + Im * (d.Im)) / ((d.Re) * (d.Re) + (d.Im) * (d.Im));
		res.Im = (Im * (d.Re) - Re * (d.Im)) / ((d.Re) * (d.Re) + (d.Im) * (d.Im));
		return res;
	}
	else
	{
		cout << "На ноль не делится" << endl;
		return 0; // ??
	}
}

bool TComplex::operator==(const TComplex& c)
{
	return Re == c.Re && Im == c.Im;
}

bool TComplex::operator!=(const TComplex& c)
{
	return Re != c.Re && Im != c.Im;
}

TComplex::~TComplex()
{
	//cout << "ДЕСТРУКТОР" << endl;
	Re = 0.0;
	Im = 0.0;
}

TComplex& TComplex::operator=(const TComplex& c)
{
	if (this != &c)
	{
		Re = c.Re;
		Im = c.Im;
	}
	return *this;
}

TComplex& TComplex::operator++()
{
	Re = Re + 1;
	Im = Im + 1;
	return *this;
}

TComplex TComplex::operator++(int)
{
	TComplex res(*this);
	this->operator++();
	return res;
}

TComplex operator*(float d, const TComplex& c)
{
	return TComplex(d * c.Re, d * c.Im);
}

ostream& operator<<(ostream& stream, const TComplex& c) 
{
	TComplex q(c);
	float re = q.GetRe();
	float im = q.GetIm();
	if ((re != 0) && (im != 0)) {
		stream << '(' << re << "+" << im << "i" << ')';
	}
	else if ((re == 0) && (im != 0)) {
		stream << im << "i";
	}
	else if ((re != 0) && (im == 0)) {
		stream << re;
	}
	else if ((re == 0) && (im == 0)) {
		stream << "0";
	};

	return stream;
}

istream& operator>>(istream& stream, TComplex& c) {
	float q, w;
	stream >> q >> w;
	c.SetRe(q);
	c.SetIm(w);
	return stream;
}



