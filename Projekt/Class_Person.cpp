#include <iostream>
#include "Class_Person.h"
using namespace std;

Person::Person() {
	root = nullptr;
	curr = nullptr;
	temp = nullptr;
}

void Person::addPerson(string imie, string nazwisko) {

	ptrlis n = new listaOsob;
	n->next = nullptr;
	n->ptr = nullptr;
	n->Name = imie;
	n->Surname = nazwisko;
	n->id = getId();

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

void Person::addPersonFromFile(string imie, string nazwisko, string id) {

	ptrlis n = new listaOsob;
	n->next = nullptr;
	n->ptr = nullptr;
	n->Name = imie;
	n->Surname = nazwisko;
	n->id = id;

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
int Person::addToTask(string imie, string nazwisko, string nazwa) {

	ptrzad n = new zadaniaOsoby;
	n->next = nullptr;
	n->nazwa = nazwa;
	temp = root;
	curr = root;

	string iD = search(imie, nazwisko);

	while (curr->next != nullptr)
	{
		if (curr->id == iD)
		{
			c = curr->ptr;

			while (c != nullptr)
			{
				c = c->next;
			}
			c = n;


			return 1;
		}
		else
		{
			temp = curr;
			curr = curr->next;
		}

	}
	if (curr->id == iD)
	{
		c = curr->ptr;

		while (c != nullptr)
		{
			c = c->next;
		}

		c = n;

		return 1;
	}
	else
		return 0;

}

void Person::delTask(string imie, string nazwisko, string nazwa)
{
	ptrzad del = nullptr;
	temp = root;
	curr = root;

	while (curr != nullptr)
	{
		if (curr->Name == imie || curr->Surname == nazwisko)
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
				break;
			}
			else {
				del = c;
				c = c->next;
				t->next = c;
				delete del;
				cout << "DELLeted\n";
			}
		}
		else
		{
			temp = curr;
			curr = curr->next;
		}
	}
	if (curr->Name == imie || curr->Surname == nazwisko)
	{
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
	}
	else cout << "Nie ma takiej osoby!" << endl;

}

void Person::printCout() {
	curr = root;

	cout << "Imie i nazwisko:\n";
	while (curr != nullptr) {
		cout << "- " << curr->Name << " " << curr->Surname << "; " << curr->id << ";";
		c = curr->ptr;
		while (c != nullptr)
		{
			cout << c->nazwa << ",";
			c = c->next;
		}
		cout << endl;
		curr = curr->next;
	}
}

void Person::printfile(ofstream& file) {
	curr = root;
	while (curr != nullptr) {
		file << curr->Name << ";" << curr->Surname << ";" << curr->id << ";";
		c = curr->ptr;
		while (c != nullptr)
		{
			file << c->nazwa << ",";
			c = c->next;
		}
		file << endl;
		curr = curr->next;
	}
}

string Person::search(string imie, string nazwisko)
{
	string niema("0");
	temp = root;
	curr = root;

	while (curr->next != nullptr)
	{
		if (curr->Surname == nazwisko && curr->Name == imie)
			return curr->id;
		else
		{
			temp = curr;
			curr = curr->next;
		}
	}
	if (curr->Surname == nazwisko && curr->Name == imie)
		return curr->id;
	else
		return niema;
}
