#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "klasy.h"

using namespace std;

/**Klasa tworz¹ca i przechowuj¹ca numer id zarówno dla zadañ jak i pracowników*/
class Id
{ 
protected:
	char id[13];
	
	/**konstruktor domyœlny*/
	Id() {};

	/**Funkcja generuje numer id
	@return id typu string*/
	string getId();
};
