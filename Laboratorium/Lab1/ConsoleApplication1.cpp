

#include <iostream>
#include "pch.h"
#include "bib.h"

using namespace std;
int main()
{
	LiczbaZespolona l1;
	LiczbaZespolona l2(5);
	LiczbaZespolona l3(5, 10);
	LiczbaZespolona l4(l3);

	cout << "licznik: " << LiczbaZespolona::licznik << endl;





	return 0;
}
