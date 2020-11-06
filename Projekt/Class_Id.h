#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <time.h>
#include <random>
using namespace std;

class Id
{ // id wykonawcy i id zadania
	int WykId;
public:

	char* generate()
	{
		time_t rawtime;
		struct tm * timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		

		char id [18];
		srand(time(NULL));
		for (int i = 0; i < 5; i++)
		{
			id[i] = rand() % 10;
		} 

		strftime(id, 13,"%g%m%j%H%M%S", timeinfo);
		return &id[18];
	}
};
