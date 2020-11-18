#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "klasy.h"

using namespace std;

/**Klasa tworz�ca i przechowuj�ca numer id zar�wno dla zada� jak i pracownik�w*/
class Id
{ 
protected:
	char id[13];
	
	/**konstruktor domy�lny*/
	Id() {};

	/**Funkcja generuje numer id
	@return id typu string*/
	string getId();
};
