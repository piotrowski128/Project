#pragma once
#include <iostream>
#include "klasy.h"
using namespace std;

/**Klasa zawieraj�ca dane dot. projektu: nazw� projektu a tak�e imie i nazwisko managera*/
class Project 
{ 
public:
	string ProjectName;
	string managerProjektu;

	/**konstruktor domy�lny*/
	Project() {};

	/**Funkcja dodaje dane projektu do programu
	@param s - nazwa projektu
	@param manager - imi� i nazwisko managera */
	void projectData(string s, string manager);

};