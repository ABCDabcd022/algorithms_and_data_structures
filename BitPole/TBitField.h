#include <ostream>
#pragma once
using namespace std;
typedef unsigned int TELEM;
class TBitField
{
	int Bitlen;
	TELEM* pMem;
	int Memlen;
	int GetMemIndex(const int n)const;
	TELEM GetMemMask(const int n)const;
public:
	TBitField(int len);
	TBitField(const TBitField& bf);
	void SetBit(const int n);
	void ClrBit(const int n);
	int GetBit(const int n)const;
	friend ostream& operator << (ostream& os, const TBitField& bf);
	TBitField& operator=(const TBitField& bf);
	int GetBitlen()const;
	int GetMemlen()const;
	int GetpMem(const int n)const;
	void SetpMem(const int n, const int q);
	~TBitField();
};