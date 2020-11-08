#pragma once
#include <iostream>
#include "klasy.h"
#include "Class_Task.h"
using namespace std;


class Person : private Id, Date {
	// zarz¹dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
	// przechowuje dane o zadaniu : Nazwê zadania, nazwê projektu, ile osób uczestniczy w zadaniu, priorytet a tak¿e datê rozpoczêcia
	typedef struct zadaniaOsoby
	{
		Task::listaZadan* zadanie;
		zadaniaOsoby* next;
	}*ptrzad;
	ptrzad p;
	ptrzad c;
	ptrzad t;

	typedef struct listaOsob
	{	
		string Name, Surname;
		char* id;
		zadaniaOsoby* ptr;
		listaOsob* next;
	}* ptrlis;
	ptrlis root;
	ptrlis curr;
	ptrlis temp;

	
public:
	Person();

	void addPerson(string imie, string nazwisko);
	void addToTask(string imie, string nazwisko, string nazwa, int priorytet, Task* tas);

	void search(string imie, string nazwisko, string nazwa);
	void delTask(string imie, string nazwisko, string nazwa);
	void printl();

};

Person::Person() {
	root = nullptr;
	curr = nullptr;
	temp = nullptr;
}

void Person::addPerson(string imie, string nazwisko) {

	ptrlis n = new listaOsob;
	n->next = nullptr;
	n->ptr = nullptr;
	n->Name= imie;
	n->Surname = nazwisko;
	n->id = generate();

	if (root != nullptr) {

		curr = root;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		root = n;
	}
}
void Person::addToTask(string imie, string nazwisko, string nazwa, int priorytet, Task* tas) {
	Task::listaZadan* tsk = nullptr;
	tsk = tas->searcH(nazwa);
	
	if (tsk!=nullptr)
	{
		ptrzad n = new zadaniaOsoby;
		temp = root;
		while ((root->Name != imie || root->Surname != nazwisko) && temp->next != nullptr)
		{
			curr = temp;
			temp = temp->next;
		}
		if (root != nullptr) {

			n->next = nullptr;
			n->zadanie = tsk;

			t = p;
			while (c->next != nullptr)
			{
				c = t;
				t = t->next;
			}
			curr->ptr = n;
		}
		else {
			p = n;
		}
	}
	else cout << "Przykro mi, aby dodac osobe do zadania musi istniec dane zadanie." << endl;
}

void Person::delTask(string imie, string nazwisko, string nazwa)
{
	ptrzad del = nullptr;
	t = p;
	c = p;
	while (c != nullptr && c->zadanie->nazwa != nazwa) {

		t = c;
		c = c->next;
	}
	if (c == nullptr) {
		cout << "ni ma\n";
		delete del;
	}
	else {
		del = c;
		c = c->next;
		t->next = c;
		delete del;
		cout << "DELLeted\n";
	}

}

void Person::printl() {
	curr = root;
	c = p;
	while (curr != nullptr) {
		cout << "imie i nazwisko: " << curr->Name << " " << curr->Surname << endl;
		while (c != nullptr)
		{
			cout << c->zadanie->nazwa << ", " << c->zadanie->priorytet << endl;
			c = c->next;
		}
		curr = curr->next;
	}
}

void Person::search(string imie, string nazwisko, string nazwa)
{
	ptrlis k = nullptr;
	temp = root;
	curr = root;
	while (curr->next != nullptr && (curr->Name != imie || curr->Surname !=nazwisko)) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == nullptr) {
		cout << "nie udalo sie znalezc :(" << endl;
	}
	else {
		cout << "udalo sie znalezc :)" << endl;
	}
}