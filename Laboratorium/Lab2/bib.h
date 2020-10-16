#pragma once
#ifndef  BIB_H
#define BIB_H
#include <iostream>

using namespace std;
class LiczbaZespolona
{
public:
	typedef float real;
	 int IM, RE;
	 int it = 1;
	
	LiczbaZespolona();
	LiczbaZespolona(int re, int im);
	LiczbaZespolona(LiczbaZespolona & l);
	LiczbaZespolona& operator+=(LiczbaZespolona & lz)
	{
		RE += lz.RE;
		IM += lz.IM;
		cout << "NEW RE: " << RE << "\nNEW IM: " << IM << endl;
		return*this;
	}
	LiczbaZespolona& operator+=(float fl);
	LiczbaZespolona& operator+(const LiczbaZespolona &l1);
	LiczbaZespolona& operator-(const LiczbaZespolona &l1);
	int operator[](const int x);
	LiczbaZespolona& operator!=(LiczbaZespolona &l1);
	LiczbaZespolona& operator=(LiczbaZespolona &l);
	LiczbaZespolona& operator==(const LiczbaZespolona &l);
	LiczbaZespolona& operator()(real fl1, real fl2);
	~LiczbaZespolona();

};

LiczbaZespolona::LiczbaZespolona()
{
	RE=0; IM=0;
}
LiczbaZespolona::LiczbaZespolona(int re, int im)
{
	RE=re; IM=im;
}
LiczbaZespolona::LiczbaZespolona(LiczbaZespolona &l): IM(l.IM), RE(l.RE)
{
	cout << "copied"<<endl;
}
LiczbaZespolona::~LiczbaZespolona()
{
	cout << "Destruction brings us joy" << endl;
}

LiczbaZespolona& operator+(const LiczbaZespolona& l1, const LiczbaZespolona& l2)
{
	LiczbaZespolona l(l1.RE + l2.RE, l1.IM + l2.IM);
	return l;
}

LiczbaZespolona & LiczbaZespolona::operator+(const LiczbaZespolona &l1)
{
	LiczbaZespolona l(this->RE + l1.RE, this->IM + l1.IM);
	return l;
}

LiczbaZespolona& operator-(const LiczbaZespolona &l1,const LiczbaZespolona &l2)
{
	LiczbaZespolona l(l1.RE - l2.RE, l1.IM - l2.IM);
	return l;
}

LiczbaZespolona& LiczbaZespolona::operator-(const LiczbaZespolona &l1)
{
	LiczbaZespolona l(this->RE - l1.RE, this->IM - l1.IM);
	return l;
}
int LiczbaZespolona::operator[](const int x)
{
	if (x == 1)
		return RE;
	else return IM;
}
LiczbaZespolona& LiczbaZespolona::operator!=(LiczbaZespolona &l1)
{
	if (this->RE == l1.RE && this->IM == l1.IM)
		cout << "liczby sa takie same\n";
	else 
		cout << "liczby nie sa takie same\n";
	return *this;
}
istream& operator >> (istream& stream, LiczbaZespolona & l)
{
	stream >> l.RE >> l.IM;
	return stream;
}

ostream&operator << (ostream& stream,const LiczbaZespolona & l)
{
	stream << l.RE <<" + "<< l.IM<<"i";
	return stream;
}
LiczbaZespolona& LiczbaZespolona::operator=(LiczbaZespolona& l)
{
	RE = l.RE;
	IM = l.IM;
	cout << "did it\n";
	return *this;
}
LiczbaZespolona& LiczbaZespolona::operator==(const LiczbaZespolona& l)
{
	if (l.RE == l.IM)
		cout << "Liczby faktycznie sa takie same\n";
	else
		cout << "Liczby jednak nie sa takie same\n";

	return *this;
}
LiczbaZespolona& operator++(LiczbaZespolona & l)
{
	l.RE += 1;
	return;
}

LiczbaZespolona& LiczbaZespolona::operator+=(float fl)
{
	this->RE += fl;
	return*this;
}

LiczbaZespolona& LiczbaZespolona::operator()(real fl1, real fl2)
{
	this->RE = fl1;
	this->IM = fl2;
	return *this;
}
#endif































