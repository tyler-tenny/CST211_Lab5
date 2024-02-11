#include "City.h"
#include <iostream>
#include <string>
using namespace std;

City::City(string name, int zipcode, int population, double yelpRating) {
	cityName = name;
	cityZipCode = zipcode;
	cityPopulation = population;
	cityYelpRating = yelpRating;

	nextCity = nullptr;
	prevCity = nullptr;
}

City* City::InsertCity(City* newCity) {
	if (nextCity) {
		nextCity->InsertCity(newCity);
	}
	else {
		nextCity = newCity;
		newCity->prevCity = this;
	}
	return newCity;
}

City* City::RemoveCity(string& removeName) {
	City* nameBaseCase = nullptr;
	if (removeName == cityName) {
		if (prevCity) prevCity->nextCity = nextCity;
		if (nextCity) nextCity->prevCity = prevCity;
		nameBaseCase = this;
	}
	else {
		if (nextCity) nameBaseCase = nextCity->RemoveCity(removeName);
	}
	return nameBaseCase;
}

City* City::FindCityWithMinPop(City* curCity, City* curMin) {
	//check against base case
	if (curMin->cityPopulation > curCity->cityPopulation) {
		curMin = curCity;
	}
	//if we arent at the end, traverse again
	if (curCity->nextCity) {
		curMin = nextCity->FindCityWithMinPop(nextCity, curMin);
	}
	return curMin;
}

City* City::FindCityWithMaxPop(City* curCity, City* curMax) {
	//check against base case
	if (curMax->cityPopulation < curCity->cityPopulation) {
		curMax = curCity;
	}
	//if we arent at the end, traverse again
	if (curCity->nextCity) {
		curMax = nextCity->FindCityWithMaxPop(nextCity, curMax);
	}
	return curMax;
}

void City::PrintCity() {
	std::cout << cityName << "\n";
	std::cout << "     Zipcode: " << cityZipCode << "\n";
	std::cout << "     City Population: " << cityPopulation << "\n";
	std::cout << "     City Yelp Rating: " << cityYelpRating << "\n";
}