#pragma once

#ifndef CLASS_DATE_H
#define CLASS_DATE_H
#pragma warning(disable : 4996)
#include <iostream>
#include <time.h>
#include "klasy.h"

using namespace std;

/**Klasa generuj�ca i przechowuj�ca dat�*/
class Date
{ 
public:
	char date[30];
	
	/**Konstruktor domy�lny*/
	Date() {};
	
	/**Funkcja generuj�ca dat�
	@return dat� tytpu string*/
	string getDate();
};
#endif

