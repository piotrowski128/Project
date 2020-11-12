#pragma once

#include <iostream>
using namespace std;
class Project 
{ //w tej klasie bêdzie istnieæ nazwa projektu a inne potrzebne informacje bêd¹ dostarczone poprzez klasy pochodne
  // powinna byc te¿ tablica wskaŸników do zadañ
public:
	string ProjectName;
	string managerProjektu;

	Project() {};
	void projectData(string s, string manager)
	{
		ProjectName = s;
		managerProjektu = manager;
	}

};