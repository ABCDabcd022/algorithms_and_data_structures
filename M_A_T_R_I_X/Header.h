#pragma once
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

template <class ValType>
class TVector
{
protected:
    ValType* pVector;
    int Size;       // размер вектора
    int StartIndex; // индекс первого элемента вектора
public:
    TVector(int s = 10, int si = 0);
    TVector(const TVector& v);                // конструктор копирования
    ~TVector();
    int GetSize() { return Size; } // размер вектора
    int GetStartIndex() { return StartIndex; } // индекс первого элемента
    ValType& operator[](int pos);             // доступ
    bool operator==(const TVector& v) const;  // сравнение
    bool operator!=(const TVector& v) const;  // сравнение
    TVector& operator=(const TVector& v);     // присваивание

    
    TVector  operator+(const ValType& val);   // прибавить число
    TVector  operator-(const ValType& val);   // вычесть число
    TVector  operator*(const ValType& val);   // умножить на число

    TVector  operator+(const TVector& v);     // сложение
    TVector  operator-(const TVector& v);     // вычитание
    ValType  operator*(const TVector& v);     // скалярное произведение

    friend istream& operator>>(istream& in, TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            in >> v.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TVector& v)
    {
        for (int i = 0; i < v.Size; i++)
            out << setw(4) << v.pVector[i] << " ";
        return out;
    }
};

template <class ValType>
TVector<ValType>::TVector(int s, int si) : Size(s), StartIndex(si)
{
    if ((s < 0) || (s > MAX_VECTOR_SIZE) || (si < 0) || (si >= MAX_VECTOR_SIZE))
        throw "Error";
    pVector = new ValType[s];
} 

template <class ValType> //конструктор копирования
TVector<ValType>::TVector(const TVector<ValType>& v)
{
    Size = v.Size;
    StartIndex = v.StartIndex;
    pVector = new ValType[Size];
    for (int i = 0; i < Size; i++)
        pVector[i] = v.pVector[i];
} 

template <class ValType>
TVector<ValType>::~TVector()
{
    delete[] pVector;
} 
template <class ValType> // доступ
ValType& TVector<ValType>::operator[](int pos)
{
    if (pos < StartIndex || pos >= StartIndex + Size)
        throw "Error";
    return pVector[pos - StartIndex];
} 

template <class ValType> // сравнение
bool TVector<ValType>::operator==(const TVector& v) const
{
    if ((Size != v.Size) || (StartIndex != v.StartIndex))
        return false;
    for (int i = 0; i < Size; i++)
        if (pVector[i] != v.pVector[i])
            return false;
    return true;
} 

template <class ValType> // сравнение
bool TVector<ValType>::operator!=(const TVector& v) const
{
    return !(*this == v);
} 

template <class ValType> // присваивание
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
    if (this != &v)
    {
        if (Size != v.Size)
        {
            delete[] pVector;
            pVector = new ValType[v.Size];
            Size = v.Size;
            StartIndex = v.StartIndex;
            for (int i = 0; i < Size; i++)
                pVector[i] = v.pVector[i];
        }
        return *this;
    }
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] + val;
    return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] - val;
    return tmp;
} 

template <class ValType> 
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] * val;
    return tmp;
} 

template <class ValType> // сложение
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
    TVector<ValType> tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] + v.pVector[i];
    return tmp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // вычитание
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
    TVector<ValType>  tmp(Size, StartIndex);
    for (int i = 0; i < Size; i++)
        tmp.pVector[i] = pVector[i] - v.pVector[i];
    return tmp;
} 

template <class ValType> // скалярное произведение
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
    if (Size != v.Size)
        throw "Error";
    ValType tmp = {};
    for (int i = 0; i < Size; i++)
        tmp += pVector[i] * v.pVector[i];
    return tmp;
} 


// Верхнетреугольная матрица
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
    TMatrix(int s = 10);
    TMatrix(const TMatrix& mt);                    // копирование
    TMatrix(const TVector<TVector<ValType> >& mt); // преобразование типа
    bool operator==(const TMatrix& mt) const;      // сравнение
    bool operator!=(const TMatrix& mt) const;      // сравнение
    TMatrix& operator= (const TMatrix& mt);        // присваивание
    TMatrix  operator+ (const TMatrix& mt);        // сложение
    TMatrix  operator- (const TMatrix& mt);        // вычитание
    TMatrix operator* (const TMatrix& mt);         // умножение

    // ввод / вывод
    friend istream& operator>>(istream& in, TMatrix& mt)
    {
        for (int i = 0; i < mt.Size; i++)
            in >> mt.pVector[i];
        return in;
    }
    friend ostream& operator<<(ostream& out, const TMatrix& mt)
    {

        for (int i = 0; i < mt.Size; i++)
        {
            for (int j = 0; j < i; ++j)cout << setw(4) << 0 << " ";
            out << mt.pVector[i] << endl;
        }
        return out;
    }
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
    if ((s < 1) || (s > MAX_MATRIX_SIZE))
        throw "Error";
    for (int i = 0; i < this->Size; i++)
        this->pVector[i] = TVector<ValType>(this->Size - i, i);
} 

template <class ValType> // конструктор копирования
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
    TVector<TVector<ValType> >(mt) {}


template <class ValType> // конструктор преобразования типа
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
    TVector<TVector<ValType> >(mt) {}


template <class ValType> // сравнение
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
    if (&mt == this)
        return true;
    if (this->Size != mt.Size)
        return false;
    for (int i = 0; i < this->Size; i++)
        if (this->pVector[i] != mt.pVector[i])
            return false;
    return true;
} 

template <class ValType> // сравнение
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
    return !(*this == mt);
} 

template <class ValType> // присваивание
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
    if (this == &mt)
        return *this;
    TVector<ValType>* tmp = new TVector<ValType>[mt.Size];
    this->Size = mt.Size;
    delete[] this->pVector;
    this->pVector = tmp;
    for (int i = 0; i < this->Size; i++)
        this->pVector[i] = mt.pVector[i];
    return *this;

} 

template <class ValType> // сложение
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{

    return TVector<TVector<ValType>>::operator+(mt);

} 

template <class ValType> // вычитание
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{

    return TVector<TVector<ValType> >::operator-(mt);

} 

#endif
