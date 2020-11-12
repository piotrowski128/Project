#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
using namespace std;

class Id
{ // id wykonawcy i id zadania
protected:

	char id[13];
	
	Id() {};

	string getId()
	{
		time_t czas = time(0);
		tm* data = localtime(&czas);
		
		strftime(id,13,"%y%m%d%H%M%S",data);

		string ID(id);
		return ID;
	}
};
