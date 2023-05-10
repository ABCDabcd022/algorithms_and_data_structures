#include "TBitField.h"

int TBitField::GetMemIndex(const int n) const
{
	return n >> 5;
}

TELEM TBitField::GetMemMask(const int n) const
{
	return 1 << (n & 31);
}

void TBitField::SetBit(const int n)
{
	if ((n > -1) && (n < Bitlen))
		pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n)
{
	if ((n > -1) && (n < Bitlen))
		pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const
{
	if ((n > -1) && (n < Bitlen))
	{
		if ((pMem[GetMemIndex(n)] & GetMemMask(n)) > 0)
		{
			return 1;
		}
	}
	return 0;
}

TBitField::TBitField(int len)
{
	Bitlen = len;
	Memlen = (len + 31) >> 5;
	pMem = new TELEM[Memlen];
	if (pMem != nullptr)
	{
		for (int i = 0; i < Memlen; i++)
			pMem[i] = 0;
	}
}

TBitField::TBitField(const TBitField& bf)
{
	Bitlen = bf.Bitlen;
	Memlen = bf.Memlen;
	pMem = new TELEM[Memlen];
	if (pMem != nullptr)
		for (int i = 0; i < Memlen; i++)
			pMem[i] = bf.pMem[i];
}

TBitField& TBitField::operator=(const TBitField& bf)
{
	Bitlen = bf.Bitlen;
	if (Memlen != bf.Memlen)
	{
		Memlen = bf.Memlen;
		if (pMem != nullptr) delete[] pMem;
		pMem = new TELEM[Memlen];
	}
	if (pMem != nullptr)
		for (int i = 0; i < Memlen; i++)
			pMem[i] = bf.pMem[i];
	return *this;
}

int TBitField::GetBitlen() const
{
	return Bitlen;
}

int TBitField::GetMemlen() const
{
	return Memlen;
}

int TBitField::GetpMem(const int n) const
{
	if ((n < 0) || (n > (Memlen - 1))) 
	{
		return 0;
	}
	else return pMem[n];
}

void TBitField::SetpMem(const int n, const int q)
{
	if ((n < 0) || (n > (Memlen - 1))) {}
	else pMem[n] = q;
}

TBitField::~TBitField()
{
	delete[] pMem;
}

ostream& operator<<(ostream& os, const TBitField& bf)
{
	for (int i = 0; i < bf.Bitlen; i++)
	{
		if (bf.GetBit(i))
			os << '1';
		else	os << '0';
	}
	return os;
}
