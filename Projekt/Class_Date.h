#pragma once

#ifndef CLASS_DATE_H
#define CLASS_DATE_H
#pragma warning(disable : 4996)
#include <iostream>
#include <time.h>
#include "klasy.h"

using namespace std;

/**Klasa generuj¹ca i przechowuj¹ca datê*/
class Date
{ 
public:
	char date[30];
	
	/**Konstruktor domyœlny*/
	Date() {};
	
	/**Funkcja generuj¹ca datê
	@return datê tytpu string*/
	string getDate();
};
#endif

