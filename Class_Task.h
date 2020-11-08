#pragma once
#include <iostream>
#include "klasy.h"
using namespace std;

class Task :public Id,Date {
	// zarz¹dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
	// przechowuje dane o zadaniu : Nazwê zadania, nazwê projektu, ile osób uczestniczy w zadaniu, priorytet a tak¿e datê rozpoczêcia
public:
	typedef struct listaZadan
	{
		string nazwa;
		int priorytet;
		char* id; char* data[30];
		listaZadan *next;
	}*ptr;
	ptr root;
	ptr curr;
	ptr temp;


	Task();

	void add(string nazwa, int priorytet);
	void delet(string nazwa);
	void printl();

	listaZadan* searcH(string nazwa)
	{
		listaZadan* k = nullptr;
		temp = root;
		curr = root;
		while (curr->next != nullptr && curr->nazwa != nazwa) {

			temp = curr;
			curr = curr->next;
		}
		if (curr == nullptr) {
			return 0;
		}
		else {
			k = curr;
			return k;
		}
	}
};

Task::Task() {
	root = nullptr;
	curr = nullptr;
	temp = nullptr;
}

void Task::add(string nazwa, int i) {

	ptr n = new listaZadan;
	n->next = nullptr;
	n->priorytet = i;
	n->nazwa = nazwa;

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

void Task::delet(string nazwa)
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

void Task::printl() {
	curr = root;
	while (curr != nullptr) {
		cout << "wartosc: " << curr->priorytet << ", " << curr->nazwa << endl;
		curr = curr->next;
	}
}

