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


/**Funkcja wyœwietla menu, w którym mo¿na dodaæ nowe zadanie 
@param t adres zmiennej "t" typu Task
*/
void Menu11(Task& t);

/**Funkcja wyœwietla menu, w którym mo¿na wyœwietliæ wszystkie zadania w systemie
@param t adres zmiennej "t" typu Task
*/
void Menu12(Task& t);

/**Funkcja wyœwietla menu, w którym mo¿na wybraæ czy dodaæ nowe zadanie lub przejrzeæ istniej¹ce
@param tas adres zmiennej "tas" typu Task
*/
void Menu1(Task& tas);

/**Funkcja wyœwietla menu, w którym mo¿na wybraæ czy zakoñczyæ projekt. Mo¿na wybraæ opcjê jedynie z poziomu managera
@param manager adres zmiennej "manager" typu Manager
@param koniec adres zmiennej "koniec" typu int, potrzebna do zakoñczenia projektu
*/
void Menu2(int &koniec, Manager* manager);

/**Funkcja wyœwietla menu, w którym mo¿na przypisaæ osobê do istniej¹cego zadania
@param p adres zmiennej "p" typu Person
@param ta adres zmiennej "ta" typu Task, potrzebny do wyszukania czy istnieje dane zadanie w systemie
*/
void Menu31(Person &p, Task& ta);

/**Funkcja wyœwietla menu, w którym mo¿na usun¹æ przypisanie osoby od istniej¹cego zadania
@param p adres zmiennej "p" typu Person
@param tas adres zmiennej "tas" typu Task
*/
void Menu32(Person &p, Task &tas);

/**Funkcja wyœwietla menu, w którym mo¿na dodaæ now¹ osobê do projektu
@param p adres zmiennej "p" typu Person
*/
void Menu33(Person &p);

/**Funkcja wyœwietla menu, w którym mo¿na wybraæ czy przypisaæ osobê do zadania, od³¹czyæ od zadania lub dodaæ osobê do projektu
@param p adres zmiennej "p" typu Person
@param tas adres zmiennej "tas" typu Task
*/
void Menu3(Person &p, Task &tas);

/**Funkcja wyœwietla g³ówne menu
@param pro wskaŸnik na zmienn¹ "pro" typu Project
@param tas wskaŸnik na zmienn¹ "tas" typu Task
@param p wskaŸnik na zmienn¹ "p" typu Person
@param manager wskaŸnik na zmienn¹ "manager" typu Manager
@param koniec wskaŸnik na zmienn¹ "koniec" typu int - definiuje czy zakoñæzyæ projekt
@param czyManager wskaŸnik na zmienn¹ "czyManager" typu int - okreœla dostêp do niektórych elementów programu
@param imie przekazuje imiê osoby u¿ywaj¹cej programu
@param nazwisko przekazuje nazwisko osoby u¿ywaj¹cej programu
*/
void Menu0(Project* pro, Task* tas, Person *p, Manager* manager, int* koniec, int* czyManager, string imie, string nazwisko);

#endif