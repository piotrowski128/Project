#pragma once
#ifndef CLASS_PERSON_H
#define CLASS_PERSON_H
#include <iostream>
#include "klasy.h"

using namespace std;

/**Klasa Task - zawiera dwie listy jednokierunkowe. w jednej z nich jest imi�, nazwisko i id osoby a tak�e wska�nik do drugiej listy.
W drugiej li�cie jest tylko nazwa zadania*/
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

	/**konstruktor domy�lny*/
	Person();

	/**Funkcja dodaje now� osob� do projektu
	@param imie - imi� osoby
	@param nazwisko - nazwisko osoby
	*/
	void addPerson(string imie, string nazwisko);

	/**Funkcja dodaje osob� z pliku
	@param imie - imi� osoby
	@param nazwisko - nazwisko osoby
	@param id - id osoby
	*/
	void addPersonFromFile(string imie, string nazwisko, string id);

	/**Funkcja przydziela osob� do zadania
	@param imie - imi� osoby
	@param nazwisko - nazwisko osoby
	@param nazwa - nazwa zadania
	*/
	int addToTask(string imie, string nazwisko, string nazwa);

	/**Funkcja wyszukuje osob� w systemie
	@param imie - imi� osoby
	@param nazwisko - nazwisko osoby
	*/
	string search(string imie, string nazwisko);

	/**Funkcja usuwa osob� od zadania
	@param imie - imi� osoby
	@param nazwisko - nazwisko osoby
	@param nazwa - nazwa zadania
	*/
	void delTask(string imie, string nazwisko, string nazwa);

	/**Funkcja wyswietla elementy listy na standardowym strumieniu wyjsciowym*/
	void printCout();

	/**Funkcja wczytuje elementy listy do podanego pliku
	@param file - adres pliku, do kt�rego wczytywane s� dane
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