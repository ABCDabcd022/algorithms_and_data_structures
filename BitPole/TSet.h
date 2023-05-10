#include "TBitField.h"
#pragma once
class TSet
{
	int MaxPower;
	TBitField BitField;
public:
	TSet(int n);
	TSet(const TSet& s);
	TSet(const TBitField& bf);
	operator TBitField();
	void InsElem(const int Elem);
	void DelElem(const int Elem);
	int IsMember(const int Elem);

	int operator == (const TSet& s);
	TSet& operator = (const TSet& s);
	TSet operator + (int Elem);
	TSet operator - (int Elem);
	TSet operator + (const TSet& s);
	TSet operator * (const TSet& s);
	TSet operator~();

	friend ostream& operator << (ostream& os, const TSet& s);
};

