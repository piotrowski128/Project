#pragma once
#include <iostream>
using namespace std;




class Person : private Id {
	// zarz¹dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
	// przechowuje dane o zadaniu : Nazwê zadania, nazwê projektu, ile osób uczestniczy w zadaniu, priorytet a tak¿e datê rozpoczêcia
	typedef struct zadaniaOsoby
	{
		string nazwa;
		int priorytet;
		zadaniaOsoby* next;
	}*ptrzad;
	ptrzad p;
	ptrzad c;
	ptrzad t;

	typedef struct listaOsob
	{
		string Name, Surname;
		zadaniaOsoby* ptr;
		listaOsob* next;
	}* ptrlis;
	ptrlis root;
	ptrlis curr;
	ptrlis temp;

	
public:
	Person();

	void addPerson(string imie, string nazwisko);
	void addTask(string imie, string nazwisko, string nazwa, int priorytet);

	void search(string nazwa);
	void delet(string nazwa);
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
void Person::addTask(string imie, string nazwisko, string nazwa, int priorytet) {
	
	temp = root;
	while ((root->Name != imie || root->Surname != nazwisko) && temp->next != nullptr)
	{
		curr = temp;
		temp = temp->next;
	}
	if (root != nullptr) {

		ptrzad n = new zadaniaOsoby;
		n->next = nullptr;
		n->nazwa = nazwa;
		n->priorytet = priorytet;

		t = p;
		while (c->next != nullptr)
		{
			c = t;
			t = t->next;
		}
		curr->ptr = n;
	}
	

	
	else {
		root = n;
	}
}

void Person::delet(string nazwa)
{
	ptr del = nullptr;
	temp = root;
	curr = root;
	while (curr != nullptr && curr->nazwa != nazwa) {

		temp = curr;
		curr = curr->next;
	}
	if (curr == nullptr) {
		cout << "ni ma\n";
		delete del;
	}
	else {
		del = curr;
		curr = curr->next;
		temp->next = curr;
		delete del;
		cout << "DELLeted\n";
	}

}

void Person::printl() {
	curr = root;
	while (curr != nullptr) {
		cout << "wartosc: " << curr->priorytet << ", " << curr->nazwa << endl;
		curr = curr->next;
	}
}

void Person::search(string nazwa)
{
	ptr k = nullptr;
	temp = root;
	curr = root;
	while (curr->next != nullptr && curr->nazwa != nazwa) {

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