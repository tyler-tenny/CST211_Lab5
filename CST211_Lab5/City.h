#include <iostream>
using namespace std;
#include <string>
#pragma once

class City {
public:
	string cityName;
	int cityZipCode;
	int cityPopulation;
	double cityYelpRating;
	City* nextCity;
	City* prevCity;

	City(string, int, int, double);
	City* InsertCity(City*);
	City* RemoveCity(string&);
	City* FindCityWithMinPop(City*, City*);
	City* FindCityWithMaxPop(City*, City*);
	void PrintCity();
};
