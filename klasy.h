#pragma once
#ifndef KLASY_H
#define KLASY_H
#include "Class_Date.h"
#include "Class_Id.h"
#include "Class_Project.h"
#include "Class_Person.h"
#include "Class_Task.h"
#include "funkcje.cpp"



void Menu11(Task& t)
{
	string nazwa; int priorytet;

	cout << "aby dodac zadanie bedziesz musial podac mi 2 rzeczy: nazwe i stopien priorytetu." << endl;
	cout << "Podaj nazwe zadania: "; std::cin >> nazwa; cout << endl;
	cout << "Podaj priorytet zadania 1-4 (1-najwy¿szy): "; std::cin >> priorytet; cout << endl;
	
	t.add(nazwa, priorytet);
}

void Menu12(Task& t)
{
	string nazwa;
	cout << "wpisz teraz jego nazwe (tylko sie nie pomyl ;)): "; cin >> nazwa;
	t.searcH(nazwa);
}

void Menu13(Task& t)
{
	cout << "oto twoja lista zadan. Mam nadzieje ze sie podoba :)" << endl;
	t.printl();
}

void Menu1(Task& tas)
{
	int menu = 4;
	while (menu != 0)
	{

		cout << "\nmozesz je:\n[1] Dodawac\n[2] Edytowac\n[3] Przejrzec\n\n[0] Wyjdz\n"; std::cin >> menu;
		if (menu == 0) return;
		else if (menu == 1)
			Menu11(tas);
		else if (menu == 2)
			Menu12(tas);
		else if (menu == 3)
			Menu13(tas);
		else cout << "mozesz wybrac 1, 2 albo 3 -,- ehhh....\n"; cout << endl;
	}
}

void Menu2()
{
	int menu = 4;

	while (menu != 0)
	{
		cout << "\nwybrales projekt? wiesz, zawsze mozesz zmienic zdanie...\n";
		cout << "[1] Zakoncz projekt i dodaj nowy\n[0] Wyjdz\n"; std::cin >> menu;
		if (menu == 0)
			return;
		else if (menu == 1)
		{
			cout << "Mimo ze wybrales opcje 'Zakoncz projekt' to nic nie szkodzi, potrzebne dane i tak beda zapisane :)" << endl;
			// tu odwolanie do wszystkich klas o pobranie danych: zadania, osoby itp.
		}
		else cout << "mozesz wybrac 1, 2 albo 3 -,- ehhh.... ";
	}
}


void Menu3(Person p)
{
	int menu = 4;

	while (menu != 0)
	{
		cout << "Wybrales opcje edycji osob. Mozesz:\n[1] Dodawac osoby do zadan\n[2] Usuwac osoby od zadan\n[0] wyjscie" << endl; cin >> menu;
		if (menu == 1)
		{

		}
		else if (menu == 2)
		{

		}
		else if (menu == 0)
			return;
		else cout << "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";
	}
}

void Menu0(string s1, Task* tas, Person p)
{
	int menu = 5;


	cout << "Program do organizacji dzialan w projekcie" << endl;
	cout << "Obecny projekt: " << s1 << "\n\n\n";
	cout << "Co chcesz zrobic? mozesz:\n[1] Przejsc do zadan\n[2] Przejsc do projektu \n[3] Edytowac osoby\n"; std::cin >> menu; cout << endl;


	if (menu == 1)
		Menu1(*tas);
	else if (menu == 2)
		Menu2();
	else if (menu == 3)
		Menu3(p);
	else if (menu == 0)
		return;
	else cout << "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";

}

#endif