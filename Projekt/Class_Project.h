#pragma once
#include <iostream>
#include "klasy.h"
using namespace std;

/**Klasa zawieraj¹ca dane dot. projektu: nazwê projektu a tak¿e imie i nazwisko managera*/
class Project 
{ 
public:
	string ProjectName;
	string managerProjektu;

	/**konstruktor domyœlny*/
	Project() {};

	/**Funkcja dodaje dane projektu do programu
	@param s - nazwa projektu
	@param manager - imiê i nazwisko managera */
	void projectData(string s, string manager);

};