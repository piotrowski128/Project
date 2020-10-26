#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
using namespace std; using namespace sf;

class Project
{ //w tej klasie b�dzie istnie� nazwa projektu a inne potrzebne informacje b�d� dostarczone poprzez klasy pochodne
	string ProjectName;
};
class Task : public Project
{// zarz�dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
// przechowuje dane o zadaniu : Nazw� zadania, nazw� projektu, ile os�b uczestniczy w zadaniu, priorytet a tak�e dat� rozpocz�cia
public:
	string TaskName;

	void search(); //wyszukiwanie zadania
	void Delete(); // usuwanie zadania
	void add(); // dodawanie zadania
	void ChangeWorker(); // zmiana pracownika wykonuj�cego zadanie
};
class Person
{ //lista z zadaniami w klasie osoba
//Przechowuje dane o osobie: imi�, nazwisko, ilo�� projekt�w, w kt�rych bierze udzia�, zadania, nad kt�rymi dana osoba pracuje
public:
	string Name, Surname, Tasks;
	int ProjectsCount;
};

class Date : public Task, Project, Person
{ //klasa daty i godziny
public:
	string date;
	void getDate();
};
class Id : public Task, Person 
{ // id wykonawcy i id zadania

};
class Priority: public Person
{ //m�g�by przechowywa� dane o zadaniach (np. o priorytecie 4 s� takie a takie zadania)

};


#endif