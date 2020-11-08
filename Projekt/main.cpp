#pragma warning(disable : 4996)
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <crtdbg.h>

#include "klasy.h"

using namespace std;
int main() {
	string s1, s2, s3; 
	
	ifstream plik1("Project.txt");
	getline(plik1, s1);
	Project project(s1);
	plik1.close();

	Person p;
	ifstream plik2("Person.txt");
	while (getline(plik2, s2))
	{


	}
	plik2.close();

	Task tas;
	ifstream plik3("Task.txt");
	while (getline(plik3, s3))
	{
		char* nazwa = NULL, data = NULL; int prior = 0;
		char * str = new char[s3.length() + 1];
		strcpy(str, s3.c_str());
	}
	plik3.close();

	//MENU
	
	Menu0(s1,&tas, p);
		
		



	
	cout << "Szkoda ze musimy sie pozegnac :,( \n";




	
	return 0;
}