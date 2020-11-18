#pragma once
#ifndef CLASS_PERSON_H
#define CLASS_PERSON_H
#include <iostream>
#include "klasy.h"

using namespace std;

/**Klasa Task - zawiera dwie listy jednokierunkowe. w jednej z nich jest imiê, nazwisko i id osoby a tak¿e wskaŸnik do drugiej listy.
W drugiej liœcie jest tylko nazwa zadania*/
class Person : private Id, Date {
	
public:
	typedef struct zadaniaOsoby
	{
		string nazwa;
		zadaniaOsoby* next;
	}*ptrzad;
	ptrzad p;
	ptrzad c;
	ptrzad t;

	typedef struct listaOsob
	{	
		string Name, Surname, id;
		zadaniaOsoby* ptr;
		listaOsob* next;
	}* ptrlis;
	ptrlis root;
	ptrlis curr;
	ptrlis temp;

	/**konstruktor domyœlny*/
	Person();

	/**Funkcja dodaje now¹ osobê do projektu
	@param imie - imiê osoby
	@param nazwisko - nazwisko osoby
	*/
	void addPerson(string imie, string nazwisko);

	/**Funkcja dodaje osobê z pliku
	@param imie - imiê osoby
	@param nazwisko - nazwisko osoby
	@param id - id osoby
	*/
	void addPersonFromFile(string imie, string nazwisko, string id);

	/**Funkcja przydziela osobê do zadania
	@param imie - imiê osoby
	@param nazwisko - nazwisko osoby
	@param nazwa - nazwa zadania
	*/
	int addToTask(string imie, string nazwisko, string nazwa);

	/**Funkcja wyszukuje osobê w systemie
	@param imie - imiê osoby
	@param nazwisko - nazwisko osoby
	*/
	string search(string imie, string nazwisko);

	/**Funkcja usuwa osobê od zadania
	@param imie - imiê osoby
	@param nazwisko - nazwisko osoby
	@param nazwa - nazwa zadania
	*/
	void delTask(string imie, string nazwisko, string nazwa);

	/**Funkcja wyswietla elementy listy na standardowym strumieniu wyjsciowym*/
	void printCout();

	/**Funkcja wczytuje elementy listy do podanego pliku
	@param file - adres pliku, do którego wczytywane s¹ dane
	*/
	void printfile(ofstream& file);

};

/** Klasa Manager - klasa pochodna klasy Person*/
class Manager : public Person
{
public:
	
	void endProject(int& i)
	{
		i = 1;
	}
};

#endif