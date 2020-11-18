#pragma once
#ifndef KLASY_H
#define KLASY_H
#include <iostream>

#include "Class_Date.h"
#include "Class_Id.h"
#include "Class_Project.h"
#include "Class_Person.h"
#include "Class_Task.h"

#include "Class_Date.cpp"
#include "Class_Id.cpp"
#include "Class_Task.cpp"
#include "Class_Person.cpp"
#include "Class_Project.cpp"

#include "klasy.cpp"


/**Funkcja wy�wietla menu, w kt�rym mo�na doda� nowe zadanie 
@param t adres zmiennej "t" typu Task
*/
void Menu11(Task& t);

/**Funkcja wy�wietla menu, w kt�rym mo�na wy�wietli� wszystkie zadania w systemie
@param t adres zmiennej "t" typu Task
*/
void Menu12(Task& t);

/**Funkcja wy�wietla menu, w kt�rym mo�na wybra� czy doda� nowe zadanie lub przejrze� istniej�ce
@param tas adres zmiennej "tas" typu Task
*/
void Menu1(Task& tas);

/**Funkcja wy�wietla menu, w kt�rym mo�na wybra� czy zako�czy� projekt. Mo�na wybra� opcj� jedynie z poziomu managera
@param manager adres zmiennej "manager" typu Manager
@param koniec adres zmiennej "koniec" typu int, potrzebna do zako�czenia projektu
*/
void Menu2(int &koniec, Manager* manager);

/**Funkcja wy�wietla menu, w kt�rym mo�na przypisa� osob� do istniej�cego zadania
@param p adres zmiennej "p" typu Person
@param ta adres zmiennej "ta" typu Task, potrzebny do wyszukania czy istnieje dane zadanie w systemie
*/
void Menu31(Person &p, Task& ta);

/**Funkcja wy�wietla menu, w kt�rym mo�na usun�� przypisanie osoby od istniej�cego zadania
@param p adres zmiennej "p" typu Person
@param tas adres zmiennej "tas" typu Task
*/
void Menu32(Person &p, Task &tas);

/**Funkcja wy�wietla menu, w kt�rym mo�na doda� now� osob� do projektu
@param p adres zmiennej "p" typu Person
*/
void Menu33(Person &p);

/**Funkcja wy�wietla menu, w kt�rym mo�na wybra� czy przypisa� osob� do zadania, od��czy� od zadania lub doda� osob� do projektu
@param p adres zmiennej "p" typu Person
@param tas adres zmiennej "tas" typu Task
*/
void Menu3(Person &p, Task &tas);

/**Funkcja wy�wietla g��wne menu
@param pro wska�nik na zmienn� "pro" typu Project
@param tas wska�nik na zmienn� "tas" typu Task
@param p wska�nik na zmienn� "p" typu Person
@param manager wska�nik na zmienn� "manager" typu Manager
@param koniec wska�nik na zmienn� "koniec" typu int - definiuje czy zako��zy� projekt
@param czyManager wska�nik na zmienn� "czyManager" typu int - okre�la dost�p do niekt�rych element�w programu
@param imie przekazuje imi� osoby u�ywaj�cej programu
@param nazwisko przekazuje nazwisko osoby u�ywaj�cej programu
*/
void Menu0(Project* pro, Task* tas, Person *p, Manager* manager, int* koniec, int* czyManager, string imie, string nazwisko);

#endif