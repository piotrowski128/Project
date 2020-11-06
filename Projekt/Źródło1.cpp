#pragma warning(disable : 4996)
#define _CRTDBG_MAP_ALLOC
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <crtdbg.h>

#include "klasy.h"

using namespace std; using namespace sf;
int main() {
	string s1, s2, s3; 
	
	ifstream plik1("Project.txt");
	getline(plik1, s1);
	Project project(s1);
	plik1.close();

	Task tas;
	Task * k;
	k = &tas;
	ifstream plik2("Person.txt");
	while (getline(plik2, s2))
	{


	}
	plik2.close();

	ifstream plik3("Task.txt");
	while (getline(plik3, s3))
	{
		char* nazwa = NULL, data = NULL; int prior = 0;
		char * str = new char[s3.length() + 1];
		strcpy(str, s3.c_str());
		

		
	}
	plik3.close();

	//MENU
	
	
	{
		int menu = 5;
		do
		{
		
		cout << "Program do organizacji dzialan w projekcie" << endl;
		cout << "Obecny projekt: " << s1 << "\n\n\n";
		cout << "Co chcesz zrobic? mozesz:\n[1] Przejsc do zadan\n[2] Przejsc do projektu \n[3] Edytowac osoby\n"; std::cin >> menu; cout << endl;

		
			if (menu == 1)
			{
				int menu1=4;
				
				while (menu1 != 0)
				{
					
					
					cout << "\nmozesz je:\n[1] Dodawac\n[2] Edytowac\n[3] Przejrzec\n\n[0] Wyjdz\n"; std::cin >> menu1;
					if (menu1 == 0) break;
					else if (menu1 == 1)
					{
						
						//dodawanie pracownika do zadania
						cout << "aby dodac zadanie bedziesz musial podac mi 2 rzeczy: nazwe i stopien priorytetu." << endl;
						{
							
							string nazwa; int priorytet;
							cout << "Podaj nazwe zadania: "; std::cin >> nazwa; cout << endl;
							cout << "Podaj priorytet zadania 1-4 (1-najwy¿szy): "; std::cin >> priorytet; cout << endl;
							
							tas.add(nazwa, priorytet);

						}
					}
					else if (menu1 == 2)
					{
						//dodawanie nowego zadania
						string nazwa;
						cout << "wpisz teraz jego nazwe (tylko sie nie pomyl ;)): "; cin >> nazwa;
						tas.search(nazwa);
						
						
					}
					else if (menu1 == 3)
					{
						cout << "oto twoja lista zadan. Mam nadzieje ze sie podoba :)" << endl;
						tas.printl();
					}
					else cout << "mozesz wybrac 1, 2 albo 3 -,- ehhh....\n";cout << endl;
				}
			}
			else if (menu == 2)
			{
				int menu2=4;
				
				while (menu2 != 0)
				{
					cout << "\nwybrales projekt? wiesz, zawsze mozesz zmienic zdanie...\n";
					cout << "[1] Zakoncz projekt\n[0] Wyjdz\n"; std::cin >> menu2;
					if (menu2 == 0)
						break;
					else if (menu2 == 1)
					{
						cout << "Mimo ze wybrales opcje 'Zakoncz projekt' to nic nie szkodzi, potrzebne dane i tak beda zapisane :)" << endl;
						// tu odwolanie do wszystkich klas o pobranie danych: zadania, osoby itp.
					}
					else cout << "mozesz wybrac 1, 2 albo 3 -,- ehhh.... ";
				}
			}
			else if (menu == 3)
			{
				int menu3=4;
				
				while (menu3 != 0)
				{
					cout << "Wybrales opcje edycji osob. Mozesz dodawac [1] lub usuwac [2] osoby z projektu . Aby edytowac przypisanie do zadan przejdz do opcji zadan. \n[0] wyjscie" << endl; cin >> menu3;
					if (menu3 == 1)
					{
						
					}
					else if (menu3 == 2)
					{
						
					}
					else if (menu == 0)
						break;
					else cout<< "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";
				}
			}
			else if (menu == 0) cout << "Szkoda ze musimy sie pozegnac :,( \n";
			else cout << "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";
		} while (menu != 0);
	}



	
	




	
	return 0;
}