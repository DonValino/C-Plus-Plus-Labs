#include "City.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Constructor
City::City(string nameIn, std::pair <double, string> latitudeIn, std::pair <double, string> longitutdeIn, int populationIn, double averageTemperatureIn)
{
	name = nameIn;
	latitude = latitudeIn;
	longitutde = longitutdeIn;
	population = populationIn;
	averageTemperature = averageTemperatureIn;
}

// Destructor
City::~City()
{
	name = "";
	averageTemperature = 0;
}

string City::getName()
{
	return name;
}

// Return The Latitutde Of The City
std::pair<double, string> City::getLatitutde()
{
	return latitude;
}

// Return The Longtitude Of The City
std::pair<double, string> City::getLongtitude()
{
	return longitutde;
}

// Overloading the insertion operator (<<) to output a city
ostream& operator<<(ostream &os, City &t) {

	cout << "Name: " << t.name << "\nLongitutde: " << t.longitutde.first << "* " << t.longitutde.second << "\nLatitutde: " << t.latitude.first << "* " << t.latitude.second << "\nPopulation: " << t.population << "\nAverage Temperature: " << t.averageTemperature << endl;
	return os;
}
