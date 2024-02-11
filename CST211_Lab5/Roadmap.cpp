#include "Roadmap.h"
#include <iostream>
#include <string>
using namespace std;
#pragma once

Roadmap::Roadmap() {
	head = nullptr;
	tail = nullptr;
}

void Roadmap::InsertCity(City* newCity) {
	if (!head) {
		head = newCity;
		tail = newCity;
	}
	else {
		tail = head->InsertCity(newCity);
	}
}

void Roadmap::RemoveCity() {
	if (!head) {
		std::cout << "List empty.\n";
	}
	else {
		string input;
		std::cout << "Please enter the name of the city you would like to remove: ";
		std::cin >> input;
		City* temp = head->RemoveCity(input);
		if (!temp) {
			std::cout << "City " << input << "not found.\n";
		}
		else {
			if (temp->cityName == head->cityName) {
				head = head->nextCity;
			}
			else if (temp->cityName == tail->cityName) {
				tail = tail->prevCity;
			}
			delete temp;
		}
	}
}

City* Roadmap::CreateCity() {
	City* newCity;

	string name;
	std::cout << "Please enter a city name string: ";
	std::cin >> name;

	int zipcode;
	std::cout << "Please enter a zip code: ";
	std::cin >> zipcode;

	int pop;
	std::cout << "Please enter the population: ";
	std::cin >> pop;

	double yelpRating;
	std::cout << "Please enter the yelp rating: ";
	std::cin >> yelpRating;

	newCity = new City(name, zipcode, pop, yelpRating);
	InsertCity(newCity);
	return newCity;
}

City* Roadmap::FindCityWithMinPop() {
	City* result = nullptr;
	if (!head) {
		std::cout << "List is empty. \n";
	}
	else {
		result = head->FindCityWithMinPop(head, head);
	}
	return result;
}

City* Roadmap::FindCityWithMaxPop() {
	City* result = nullptr;
	if (!head) {
		std::cout << "List is empty. \n";
	}
	else {
		result = head->FindCityWithMaxPop(head, head);
	}
	return result;
}

void Roadmap::PrintItinerary() {
	City* curCity = head;
	std::cout << "----------\n";
	std::cout << "ITINERARY: \n";
	if (head) {
		int i = 0;
		while (curCity->nextCity) {
			std::cout << ++i << ": ";
			curCity->PrintCity();
			curCity = curCity->nextCity;
		}
		curCity;
		std::cout << ++i << ": "; 
		curCity->PrintCity();
	}
}

Roadmap::~Roadmap() {
	City* cur = head;
	while (cur) {
		City* temp = cur;
		cur = cur->nextCity;
		delete temp;
	}
}