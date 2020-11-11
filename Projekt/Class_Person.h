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
		string nazwa;
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
	void addToTask(string imie, string nazwisko, string nazwa);

	char* search(string imie, string nazwisko);
	void delTask(string imie, string nazwisko, string nazwa);
	void printcout();
	void printfile();

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
void Person::addToTask(string imie, string nazwisko, string nazwa) {
	
	
		ptrzad n = new zadaniaOsoby;
		temp = root;
		char* ts = 0;

		ts = search(imie, nazwisko);
		while (ts!=temp->id && temp->next != nullptr)
		{
			curr = temp;
			temp = temp->next;
		}
		if (root != nullptr) {

			n->next = nullptr;
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

void Person::delTask(string imie, string nazwisko, string nazwa)
{
	ptrzad del = nullptr;
	temp = root;
	curr = root;

	while (curr->Name != imie || curr->Surname != nazwisko)
	{
		if (curr != nullptr)
		{
			temp = curr;
			curr = curr->next;
		}
		else break;
		
	}
	if (curr != nullptr)
	{
		t = curr->ptr;
		c = curr->ptr;
		while (c != nullptr && c->nazwa != nazwa) {

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
	else cout << "Nie ma takiej osoby!" << endl;
	

}

void Person::printcout() {
	curr = root;
	c = p;
	cout << "Imie i nazwisko:\n";
	while (curr != nullptr) {
		cout << curr->Name << " " << curr->Surname << ":";
		while (c != nullptr)
		{
			cout << c->nazwa << ",";
			c = c->next;
		}
		cout << endl;
		curr = curr->next;
	}
}

void Person::printfile() {
	curr = root;
	c = p;
	while (curr != nullptr) {
		cout << curr->Name << ";" << curr->Surname << ";";
		while (c != nullptr)
		{
			cout << c->nazwa << ",";
			c = c->next;
		}
		cout << endl;
		curr = curr->next;
	}
}

char* Person::search(string imie, string nazwisko)
{
	temp = root;
	curr = root;
	while (curr->next != nullptr && (curr->Name != imie || curr->Surname !=nazwisko)) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == nullptr) {
		return 0;
	}
	else {
		return curr->id;
	}
}