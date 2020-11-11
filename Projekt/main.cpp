#pragma warning(disable : 4996)
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <crtdbg.h>

#include "klasy.h"

using namespace std;
int main() {
	string s1, s2, s3; Person p; Task tas; int czyKoniec=0;
	
	ifstream plik1("Project.txt");
	getline(plik1, s1);
	Project project(s1);
	plik1.close();

	ifstream plik3("Task.txt");
	while (getline(plik3, s3))
	{

		string nazwa = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);
		
		string id = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);

		string prior = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);

		string data = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);


	}
	plik3.close();

	ifstream plik2("Person.txt");
	while (getline(plik2, s2))
	{
		string name = s2.substr(0, s2.find_first_of(";"));
		s2.erase(0, s2.find_first_of(";") + 1);
		string surname = s2.substr(0, s2.find_first_of(";"));
		s2.erase(0, s2.find_first_of(";") + 1);
		p.addPerson(name, surname);

		size_t found = s2.find_first_of(",");
		while (found != string::npos)
		{
			string zad = s2.substr(0, s2.find_first_of(","));
			//p.addToTask(name, surname, zad, &tas);
			s2.erase(0, s2.find_first_of(",") + 1);
			found = s2.find_first_of(",");
		}
		
	}
	plik2.close();
	
	Menu0(s1, &tas, &p, &czyKoniec);
	
	cout << "Szkoda ze musimy sie pozegnac :,( \n";

	if (czyKoniec == 1)
	{
	
	}
	else {



	}

	
	return 0;
}