

#include <iostream>
#include "pch.h"
#include "bib.h"

using namespace std;
int main()
{
	LiczbaZespolona l1;
	LiczbaZespolona l2(5,7);
	LiczbaZespolona l3(5, 10);
	l2 += l2;

	l1 = l2 + l3;
	cout <<"l1=l2+l2: "<< l1.RE << " AND AND " << l1.IM << endl;

	LiczbaZespolona l4;
	l4 = l3 - l2;
	cout <<"l4=l3-l2: "<< l4.RE << " UND " << l4.IM << endl;
	cout << "l4[1]: "<< l4[1] <<", l4[0]: "<< l4[0] << endl;
	
	LiczbaZespolona l5(3, 3);
	LiczbaZespolona l6(l5);
	cout << "Operator !=\nl5!=l4\n";
	l5 != l4;
	cout << "l5!=l6\n";
	l5 != l6;
	LiczbaZespolona l7;
	cin >> l7;
	cout <<"\n\n"<< l7<<"\n\n";
	return 0;
}
