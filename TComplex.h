#include <fstream>
#include <iostream>
#pragma once
using namespace std;
class TComplex
{
private:
	float Re;
	float Im;
public:
	TComplex();
	TComplex(float _Re, float _Im);
	TComplex(const TComplex& copy);
	TComplex(float q);

	float GetRe();
	float GetIm();

	void SetRe(float re);
	void SetIm(float im);

	void Print();
	TComplex Add(const TComplex& op2);
	TComplex Sub(const TComplex& su);
	TComplex Mult(const TComplex& mult);
	TComplex Divi(const TComplex& d);

	TComplex operator + (const TComplex& op2);
	TComplex operator - (const TComplex& su);
	TComplex operator * (const TComplex& mult);
	TComplex operator / (const TComplex& d);

	bool operator==(const TComplex& c);
	bool operator!=(const TComplex& c);

	~TComplex();

	TComplex& operator = (const TComplex& c);

	TComplex& operator ++ ();
	TComplex operator ++ (int);

	friend std::ostream& operator<<(ostream& stream, const TComplex& c);
	friend std::istream& operator>>(istream& stream, TComplex& c);

	friend TComplex operator*(float d, const TComplex& c);
};


