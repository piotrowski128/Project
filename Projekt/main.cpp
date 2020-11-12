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
	string s1, s2, s3; Person p; Task tas; Project project; int czyKoniec=0;
	
	//pobieranie danych z pliku Project i dodawanie do klasy Project+
	ifstream plik1("Project.txt");
	getline(plik1, s1);

	string nazwaProjektu = s1.substr(0, s1.find_first_of(";"));
	s1.erase(0, s1.find_first_of(";") + 1);

	string managerProjektu = s1.substr(0, s1.find_first_of(";"));
	s1.erase(0, s1.find_first_of(";") + 1);

	project.projectData(nazwaProjektu, managerProjektu);
	
	plik1.close();

	//Pobieranie danych z pliku Task i dodawanie do klasy Task
	ifstream plik3("Task.txt");
	while (getline(plik3, s3))
	{
		int priorytet = 0;

		//pobieranie nazwy zadania
		string nazwa = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);

		//pobieranie id zadania
		string id = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);
		
		//pobieranie priorytetu
		string prior = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);
		char* str2 = new char[prior.length() + 1];
		strcpy(str2, prior.c_str()); 
		priorytet = atoi(str2);
		
		//pobieranie daty
		string data = s3.substr(0, s3.find_first_of(","));
		s3.erase(0, s3.find_first_of(",") + 1);
		
		tas.addTaskFromFile(nazwa,priorytet,data,id);
	}
	plik3.close();

	//Pobieranie danych z pliku Person i dodawanie do klasy Person
	ifstream plik2("Person.txt");
	while (getline(plik2, s2))
	{
		//pobieranie imienia i nazwiska
		string name = s2.substr(0, s2.find_first_of(";"));
		s2.erase(0, s2.find_first_of(";") + 1);
		string surname = s2.substr(0, s2.find_first_of(";"));
		s2.erase(0, s2.find_first_of(";") + 1);

		//pobieranie id
		string id = s2.substr(0, s2.find_first_of(";"));
		s2.erase(0, s2.find_first_of(";") + 1);

		p.addPersonFromFile(name, surname, id);

		//dodawanie zadan do listy w klasie Person
		size_t found = s2.find_first_of(",");
		while (found != string::npos)
		{
			string zad = s2.substr(0, s2.find_first_of(","));
			p.addToTask(name, surname, zad);
			s2.erase(0, s2.find_first_of(",") + 1);
			found = s2.find_first_of(",");
		}
		
	}
	plik2.close();

	//Menu
	Menu0(&project, &tas, &p, &czyKoniec);
	
	//Po wyjsciu z menu -> zakonczenie dzialania programu
	
	

	cout << "Szkoda ze musimy sie pozegnac :,( \n";

	if (czyKoniec == 1)
	{
		//tworzenie nazwy dla pliku nazwa_projektu.txt
		project.ProjectName.push_back('.');
		project.ProjectName.push_back('t');
		project.ProjectName.push_back('x');
		project.ProjectName.push_back('t');
		
		//czyszczenie wszystkich plików
		ofstream clear1;
		clear1.open("Project.txt", ofstream::out | ofstream::trunc);
		clear1.close();

		ofstream clear2;
		clear2.open("Task.txt", ofstream::out | ofstream::trunc);
		clear2.close();

		ofstream clear3;
		clear3.open("Person.txt", ofstream::out | ofstream::trunc);
		clear3.close();

		//tworzenie pliku nazwa_projektu.txt i zapisywanie dancyh z projektu
		ofstream collect;
		collect.open(project.ProjectName, ios::out);
		
		collect << "PROJEKT ZAKONCZONY!" << endl;
		collect << "projekt: '" << project.ProjectName << "' pod przewodnictwem managera: " << project.managerProjektu << endl;

		collect << "\n\n\n\nDANE Z PROJEKTU:\nOSOBY I ICH ZADANIA" << endl;
		p.printfile(collect);
		collect << "\nZADANIA" << endl;
		tas.printFile(collect);

		collect.close();

	}
	else {
		
	/*	ofstream clear1;
		clear1.open("Project.txt", ios::app | ofstream::trunc);
		clear1.close();
		clear1.open("Project.txt", ofstream::out);
		clear1 << project.ProjectName << ";" << project.managerProjektu << ";";
		clear1.close();

		ofstream clear2;
		clear2.open("Task.txt", ofstream::out | ofstream::trunc);
		clear2.close();
		clear2.open("Task.txt", ofstream::out);
		tas.printFile(clear2);
		clear2.close();

		ofstream clear3;
		clear3.open("Person.txt", ofstream::out | ofstream::trunc);
		clear3.close();
		clear3.open("Person.txt", ofstream::out);
		p.printfile(clear3);
		clear3.close();*/

		p.destroy();
	}

	return 0;
}