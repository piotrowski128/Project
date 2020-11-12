#pragma once
#include <iostream>
#include "klasy.h"
using namespace std;

class Task :public Id, Date {
	// zarz¹dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
	// przechowuje dane o zadaniu : Nazwê zadania, nazwê projektu, ile osób uczestniczy w zadaniu, priorytet a tak¿e datê rozpoczêcia
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


	Task();

	void add(string nazwa, int priorytet);
	void addTaskFromFile(string nazwa, int priorytet,string data,string id);
	void delet(string nazwa);
	void printCout();
	void printFile(ofstream & file);

	int search(string nazwa);
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
	n->id = Id::getId();
	n->data = Date::getDate();

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

void Task::addTaskFromFile(string nazwa, int i, string data, string id) {

	ptr n = new listaZadan;
	n->next = nullptr;
	n->priorytet = i;
	n->nazwa = nazwa;
	n->id = id;
	n->data = data;
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
int Task::search(string nazwa)
{
	temp = root;
 	curr = root;
	while (curr != nullptr && curr->nazwa != nazwa) {

		temp = curr;
		curr = curr->next;
	}
	if (curr == nullptr)
		return 0;
	else
		return 1;
}

void Task::printCout() {
	curr = root;
	cout << "\nDANE WYSWIETLANE W NASTEPUJACYM FORMACIE:\n";
	cout << "nazwa: id, [priorytet] ==data==\n\n" << endl;
	while (curr != nullptr) {
		cout << curr->nazwa<<": "<< curr->id << ", ["<<curr->priorytet<<"] =="<<curr->data<<"==" << endl;
		curr = curr->next;
	}
}
void Task::printFile(ofstream & file)
{
	curr = root;

	while (curr != nullptr) {
		file << curr->nazwa << "," << curr->id << "," << curr->priorytet << "," << curr->data << "," << endl;
		curr = curr->next;
	}
}

