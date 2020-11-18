#pragma once
#ifndef CLASS_TASK_H
#define CLASS_TASK_H
#include <iostream>
#include "klasy.h"


using namespace std;
/**Klasa Task - zawiera list� jednokierunkow� zawieraj�c�: nazw�, id, piorytet zadania a tak�e dat� dodania*/
class Task :public Id, Date {
	
public:
	typedef struct listaZadan
	{
		string nazwa, id, data;
		int priorytet;
		listaZadan *next;
	}*ptr;
	ptr root;
	ptr curr;
	ptr temp;

	/**Konstruktor domy�lny*/
	Task();

	/**Funkcja dodaje nowy element do listy
	@param nazwa - nazwa zadania
	@param priorytet - priorytet zadania
	*/
	void add(string nazwa, int priorytet);

	/**Funkcja dodaje nowy element do listy z wczytanego pliku
	@param nazwa - nazwa zadania
	@param priorytet - priorytet zadania
	@param data - data utworzenia zadania
	@param id - id zadania
	*/
	void addTaskFromFile(string nazwa, int priorytet,string data,string id);

	/**Funkcja usuwa element z listy
	@param nazwa - nazwa zadania
	*/
	void delet(string nazwa);
	
	/**Funkcja wyswietla elementy listy na standardowym strumieniu wyjsciowym*/
	void printCout();

	/**Funkcja wczytuje elementy listy do podanego pliku
	@param file - adres pliku, do kt�rego wczytywane s� dane
	*/
	void printFile(ofstream & file);

	/**Funkcja wyszukuje zadanie z listy 
	@param nazwa - nazwa zadania
	@return 1 w przypadku kiedy element zostanie odnaleziony. W innym przypadku 0
	*/
	int search(string nazwa);
};
#endif