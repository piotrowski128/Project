#pragma once

#include <iostream>
using namespace std;
class Project 
{ //w tej klasie b�dzie istnie� nazwa projektu a inne potrzebne informacje b�d� dostarczone poprzez klasy pochodne
  // powinna byc te� tablica wska�nik�w do zada�
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