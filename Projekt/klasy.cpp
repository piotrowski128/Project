#include <iostream>
#include "klasy.h"

using namespace std;
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
	cout << "oto twoja lista zadan. Mam nadzieje ze sie podoba :)" << endl;
	t.printCout();
}

void Menu1(Task& tas)
{
	int menu = 4;
	while (menu != 0)
	{
		cout << "\nmozesz je:\n[1] Dodawac\n[2] Przejrzec\n\n[0] Wyjdz\n"; std::cin >> menu;
		if (menu == 0) return;
		else if (menu == 1)
			Menu11(tas);
		else if (menu == 2)
			Menu12(tas);
		else cout << "mozesz wybrac 1 albo 2 -,- ehhh....\n"; cout << endl;
	}
}

void Menu2(int &koniec, Manager* manager)
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
			manager->endProject(koniec);
		}
		else cout << "mozesz wybrac 1, 2 albo 3 -,- ehhh.... ";
	}
}

void Menu31(Person &p, Task& ta)
{
	string imie, nazwisko, nazwa; int TaskExist = 0;
	cout << "Dodawanie osoby do zadania. Wybierz osobe z bazy danych a nastepnie zadanie. (Wpisz imie, nazwisko i nazwe zadania)" << endl;
	p.printCout();
	cout << endl;
	ta.printCout();
	cout << "\n\n";
	cout << "imie: "; cin >> imie;
	cout << "nazwisko: "; cin >> nazwisko;
	cout << "nazwa zadania: "; cin >> nazwa;

	TaskExist = ta.search(nazwa);

	if (TaskExist == 1)
	{
		p.addToTask(imie, nazwisko, nazwa);
	}
	else cout << "\nNie ma takiego zadania\n\n";

}

void Menu32(Person &p, Task &tas)
{
	string imie, nazwisko, nazwa, rly;
	cout << "LISTA OSOB:\n"; p.printCout(); cout << endl;
	cout << "LISTA ZADAN:\n"; tas.printCout(); cout << "\n\n";
	cout << "imie: "; cin >> imie;
	cout << "nazwisko: "; cin >> nazwisko;
	cout << "nazwa zadania: "; cin >> nazwa;



	p.delTask(imie, nazwisko, nazwa);
}
void Menu33(Person &p)
{
	string imie, nazwisko;
	cout << "Dodawanie osoby. Wpisz jej imie: "; cin >> imie; cout << endl;
	cout << "i nazwisko: "; cin >> nazwisko; cout << endl;
	p.addPerson(imie, nazwisko);
}

void Menu3(Person &p, Task &tas)
{
	int menu = 4;

	while (menu != 0)
	{
		cout << "Wybrales opcje edycji osob. Mozesz:\n[1] Dodawac osoby do zadan\n[2] Usuwac osoby od zadan\n[3] Dodawac osoby do projektu\n[0] wyjscie" << endl; cin >> menu;
		if (menu == 1)
			Menu31(p, tas);
		else if (menu == 2)
			Menu32(p, tas);
		else if (menu == 3)
			Menu33(p);
		else if (menu == 0)
			return;
		else cout << "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";
	}
}

void Menu0(Project* pro, Task* tas, Person *p, Manager* manager, int* koniec, int* czyManager, string imie, string nazwisko)
{
	int menu = 5; string nie("nie.");

	while (menu != 0)
	{
		cout << "Program do organizacji dzialan w projekcie" << endl;
		cout << "Obecny projekt: " << pro->ProjectName << "\nManagerem projektu jest " << pro->managerProjektu << "\n\n\n";
		cout << "Co chcesz zrobic? mozesz:\n[1] Przejsc do zadan\n[2] Przejsc do projektu \n[3] Edytowac osoby\n"; std::cin >> menu; cout << endl;


		if (menu == 1)
			Menu1(*tas);
		else if (menu == 2)
		{
			string idPracownika;
			idPracownika = manager->search(imie, nazwisko);
			if (idPracownika != "0")
				Menu2(*koniec, manager);
			else cout << "nie masz uprawnien!" << endl;
		}
		else if (menu == 3)
			Menu3(*p, *tas);
		else if (menu == 0)
			return;
		else cout << "ojej no co za gapa! nie wiem czy zauwazyles ale mozesz wybrac tylko 1 albo 2...\nNo dobrze, sprobujmy jeszcze raz \n";

	}
}
