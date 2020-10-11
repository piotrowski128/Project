#pragma once
#ifndef  BIB_H
#define BIB_H
#include <iostream>
using namespace std;
class LiczbaZespolona
{
	int IM, RE;

public:
	void set();
	void get();
	
	LiczbaZespolona();
	LiczbaZespolona(int re);
	LiczbaZespolona(int re, int im);
	LiczbaZespolona(const LiczbaZespolona & liczba);
	~LiczbaZespolona();
	
	static int licznik;
};

class Array
{
	int** liczba;
	int a, b;

public:

	Array(int x, int y);
	Array(Array&& tablica) noexcept;
	
	Array& operator = (Array&& tablica) noexcept
	{
		swap(a, tablica.a);
		swap(b, tablica.b);
		swap(liczba, tablica.liczba);
		return*this;
	}

	~Array();
};

void LiczbaZespolona::set()
{
	cout<<"Realis: ";cin>>RE;
	cout<<"\nImaginaris: ";cin>>IM; cout<<endl;
}

inline void LiczbaZespolona::get()
{
	cout << "realis: " << RE << ", imaginaris: " << IM << endl;
}

LiczbaZespolona::LiczbaZespolona()
{
	RE=0; IM=0;
	cout<<"Wywolany zostal konstruktor bezargumentowy. domyslne wartosci: Realis: 0, Imaginaris: 0"<<endl;
	licznik++;
}
LiczbaZespolona::LiczbaZespolona(int re)
{
	RE=re; IM=re;
	cout<<"Wywolany zostal konstruktor jednoargumentowy. domyslne wartosci: Realis = Imaginaris"<<endl;
	licznik++;
}
LiczbaZespolona::LiczbaZespolona(int re, int im)
{
	RE=re; IM=im;
	cout<<"Wywolany zostal konstruktor wieloargumentowy"<<endl;
	licznik++;
}
LiczbaZespolona::LiczbaZespolona(const LiczbaZespolona & liczba) : RE(liczba.RE), IM(liczba.IM)
{
	cout<<"Wywolany zostal konstruktor kopiujacy"<<endl;
	licznik++;
}
LiczbaZespolona::~LiczbaZespolona()
{
	cout<<"Wywolany zostal destruktor"<<endl;
	licznik--;
}

Array::Array(int x, int y)
{
	liczba = new int* [a];
	for (int i = 0; i < a; i++)
	{
		liczba[i] = new int[b];
	}
}
Array::Array(Array&& tablica)
{
	for (int i = 0; i < tablica.b; i++)
	{
		tablica.liczba[i] = nullptr;
		tablica.liczba = nullptr;
	}
}

void swap(Array& a, Array& b)
{
	Array k = move(a);
	a = move(b);
	b = move(k);
}

Array::~Array()
{
	cout << "Destruktor" << endl;
}
#endif // ! BIB_H

































