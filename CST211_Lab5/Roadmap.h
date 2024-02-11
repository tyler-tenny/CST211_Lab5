#include <iostream>
#include <string>
#include "City.h"
using namespace std;
#pragma once

class Roadmap {
public:
	Roadmap();
	City* head;
	City* tail;

	void InsertCity(City*);
	City* CreateCity();
	void RemoveCity();
	City* FindCityWithMinPop();
	City* FindCityWithMaxPop();
	void PrintItinerary();

	~Roadmap();
};