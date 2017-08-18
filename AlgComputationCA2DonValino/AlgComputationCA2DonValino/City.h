#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>      // std::pair, std::make_pair

using namespace std;

// Don Valino - X00112730

class City
{
	friend ostream& operator<<(ostream &os, City &t);
private:
	string name;
	std::pair <double, string> latitude;
	std::pair <double, string> longitutde;
	int population;
	double averageTemperature;
public:
	City(string nameIn, std::pair <double, string> latitudeIn, std::pair <double, string> longitutdeIn, int populationIn, double averageTemperature);
	~City();
	string getName();
	std::pair <double, string> getLatitutde();
	std::pair <double, string> getLongtitude();
};

