#include <iostream>
#include <string>
#include "City.h"
#include "Roadmap.h"
using namespace std;

Roadmap* AutoGenerateItinerary() {
	Roadmap* newMap = new Roadmap;
	//name, zip, pop, yelp
	City* temp1 = new City("Portland", 97015, 300000, 4.1);
	newMap->InsertCity(temp1);
	City* temp2 = new City("Salem", 97035, 80000, 3.7);
	newMap->InsertCity(temp2);
	City* temp3 = new City("Bend", 97621, 100000, 4.8);
	newMap->InsertCity(temp3);
	City* temp4 = new City("Ashland", 97200, 35000, 4.3);
	newMap->InsertCity(temp4);
  delete temp1;
  delete temp2;
  delete temp3;
  delete temp4;
	return newMap;
}

void Menu(int& input) {
	std::cout << "\nPlease select an option from below: \n";
	std::cout << "{0} Create Itinerary\n";
	std::cout << "{1} Add city to itinerary\n";
	std::cout << "{2} Remove city from itinerary\n";
	std::cout << "{3} Find the city with the lowest population on your itinerary\n";
	std::cout << "{4} Find the city with the greatest population on your itinerary\n";
	std::cout << "{5} Print current itinerary\n";
	std::cout << "{6} Autogenerate Oregon Itinerary\n";
	std::cout << "{7} Exit\n";
	std::cin >> input;
}

int main() {
	Roadmap* itinerary = new Roadmap();
	int input = -1;
	while (input != 7) {
		Menu(input);
		switch (input) {
		case 0: {
			delete itinerary;
			itinerary = new Roadmap();
			std::cout << "Itinerary created.\n";
			input = -1;
			break;
		}
		case 1: {
			itinerary->CreateCity();
			input = -1;
			break;
		}
		case 2: {
			itinerary->RemoveCity();
			input = -1;
			break;
		}
		case 3: {
			std::cout << "The city with the lowest population on your itinerary is: \n";
			City* tempMin = itinerary->FindCityWithMinPop();
			tempMin->PrintCity();
			input = -1;
			break;
		}
		case 4: {
			std::cout << "The city with the highest population on your itinerary is :\n";
			City* tempMax = itinerary->FindCityWithMaxPop();
			tempMax->PrintCity();
			input = -1;
			break;
		}
		case 5: {
			itinerary->PrintItinerary();
			input = -1;
			break;
		}
		case 6: {
			delete itinerary;
			itinerary = AutoGenerateItinerary();
			input = -1;
			break;
		}
		case 7: {
			std::cout << "Goodbye!\n";
      delete itinerary;
			return 0;
		}
		}
	}
}
