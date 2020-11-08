#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <time.h>
using namespace std;
class Date
{ //klasa daty i godziny
public:
	char date[30];
public:
	Date() {};
	
	void getDate()
	{
		time_t czas = time(0);
		tm* data = localtime(&czas);
		strftime(date, sizeof date, "%F,%X", data);
	}
};