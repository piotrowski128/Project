//for Class_Date.h

#include <iostream>
#include <time.h>
#include "Class_Date.h"

using namespace std;


string Date::getDate()
{
	time_t czas = time(0);
	tm* data = localtime(&czas);

	strftime(date, sizeof date, "%F; %X", data);
	string DATE(date);
	return DATE;
}
