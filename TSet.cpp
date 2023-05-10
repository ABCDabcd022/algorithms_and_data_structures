#include "TSet.h"
#include <iostream>

TSet::TSet(int n) : MaxPower(n), BitField(n) {}
TSet::TSet(const TSet& s) : MaxPower(s.MaxPower), BitField(s.BitField) {}
TSet::TSet(const TBitField& bf) : MaxPower(bf.GetBitlen()), BitField(bf) {}

TSet::operator TBitField()
{
	TBitField temp(BitField);
	return temp;
}

void TSet::InsElem(const int Elem)
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem)
{
	BitField.ClrBit(Elem);
}

int TSet::IsMember(const int Elem)
{
	return BitField.GetBit(Elem);;
}

int TSet::operator==(const TSet& s)
{
	if (MaxPower == s.MaxPower)
	{
		int q = 1;
		int m = BitField.GetMemlen();
		for (int i = 0; i < m; i++)
		{
			q = (BitField.GetpMem(i) == s.BitField.GetpMem(i));
			if (q == 0) return 0;
		}
		return 1;
	}
	else return 0;
}

TSet& TSet::operator=(const TSet& s)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

TSet TSet::operator+(int Elem)
{
	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(int Elem)
{
	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator+(const TSet& s)
{
	int a, b, c;
	if (MaxPower > s.MaxPower)
	{
		a = MaxPower;
	}
	else
	{
		a = s.MaxPower;
	}

	TSet res(a);

	if (MaxPower > s.MaxPower)
	{
		b = s.BitField.GetMemlen();
		for (int i = 0; i < b; i++)
		{
			res.BitField.SetpMem(i, (BitField.GetpMem(i) | s.BitField.GetpMem(i)));
		}
		c = BitField.GetMemlen();
		for (int i = b; i < c; i++)
		{
			res.BitField.SetpMem(i, BitField.GetpMem(i));
		}
	}
	else
	{
		b = BitField.GetMemlen();
		for (int i = 0; i < b; i++)
		{
			res.BitField.SetpMem(i, (BitField.GetpMem(i) | s.BitField.GetpMem(i)));
		}
		c = s.BitField.GetMemlen();
		for (int i = b; i < c; i++)
		{
			res.BitField.SetpMem(i, s.BitField.GetpMem(i));
		}
	}
	return res;
}

TSet TSet::operator*(const TSet& s)
{
	int a, b, c;
	if (MaxPower > s.MaxPower)
	{
		a = MaxPower;
	}
	else
	{
		a = s.MaxPower;
	}

	TSet res(a);

	if (MaxPower > s.MaxPower)
	{
		b = s.BitField.GetMemlen();
		for (int i = 0; i < b; i++)
		{
			res.BitField.SetpMem(i, (BitField.GetpMem(i) & s.BitField.GetpMem(i)));
		}
		c = BitField.GetMemlen();
		for (int i = b; i < c; i++)
		{
			res.BitField.SetpMem(i, 0);
		}
	}
	else
	{
		b = BitField.GetMemlen();
		for (int i = 0; i < b; i++)
		{
			res.BitField.SetpMem(i, (BitField.GetpMem(i) & s.BitField.GetpMem(i)));
		}
		c = s.BitField.GetMemlen();
		for (int i = b; i < c; i++)
		{
			res.BitField.SetpMem(i, 0);
		}
	}
	return res;
}

TSet TSet::operator~()
{
	int a = MaxPower;
	TSet res(a);
	int b = BitField.GetMemlen();
	for (int i = 0; i < b; i++)
	{
		res.BitField.SetpMem(i, ~BitField.GetpMem(i));
	}
	return res;
}

ostream& operator<<(ostream& os, const TSet& s)
{
	int q = 0;
	int a = s.BitField.GetBitlen();
	for (int i = 0; i < a; i++)
	{
		if (s.BitField.GetBit(i))
		{
			os << i << ' ';
			q = q + 1;
		}
	}
	if (q == 0)
	{
		os << "пустое множество";
	}
	return os;
}

std::istream& operator>>(istream& stream, TSet& s)
{
	int a = s.BitField.GetBitlen();
	int b = -2;


	do
	{
		stream >> b;
		s.BitField.SetBit(b);
	} while (b != -1);
	if (b == -1) return stream;

}



