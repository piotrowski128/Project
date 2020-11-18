#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "Class_Id.h"

using namespace std;

string Id::getId()
{
	time_t czas = time(0);
	tm* data = localtime(&czas);

	strftime(id, 13, "%y%m%d%H%M%S", data);

	string ID(id);
	return ID;
}