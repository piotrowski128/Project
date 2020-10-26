#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
using namespace std; using namespace sf;

class Project
{ //w tej klasie bêdzie istnieæ nazwa projektu a inne potrzebne informacje bêd¹ dostarczone poprzez klasy pochodne
	string ProjectName;
};
class Task : public Project
{// zarz¹dzanie zadaniami: szukanie, usuwanie, dodawanie, zmiana  wykonawcy
// przechowuje dane o zadaniu : Nazwê zadania, nazwê projektu, ile osób uczestniczy w zadaniu, priorytet a tak¿e datê rozpoczêcia
public:
	string TaskName;

	void search(); //wyszukiwanie zadania
	void Delete(); // usuwanie zadania
	void add(); // dodawanie zadania
	void ChangeWorker(); // zmiana pracownika wykonuj¹cego zadanie
};
class Person
{ //lista z zadaniami w klasie osoba
//Przechowuje dane o osobie: imiê, nazwisko, iloœæ projektów, w których bierze udzia³, zadania, nad którymi dana osoba pracuje
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
{ //móg³by przechowywaæ dane o zadaniach (np. o priorytecie 4 s¹ takie a takie zadania)

};


#endif