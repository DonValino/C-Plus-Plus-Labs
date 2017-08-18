#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "CityNode.h"
#include "City.h"

using namespace std;

class CityBST
{
private:
	CityNode* root;
	void add(CityNode* newNode, CityNode* root);
	bool find(string cityName, CityNode* root);
	void preOrder(CityNode* root);
	void inOrder(CityNode* root);
	void postOrder(CityNode* root);
	bool isLeaf(CityNode* root);
	int height(CityNode* root);
	CityNode* findMin(CityNode* root);
	CityNode* deleteNode(string name, std::pair <double, string> longtitudeIn, std::pair <double, string> latitudeIn, CityNode* root);
	void printAllRecordsWithinAGivenDistance(std::pair <double, string> minlongtitudeIn, std::pair <double, string> minlatitudeIn, std::pair <double, string> maxlongtitudeIn, std::pair <double, string> maxlatitudeIn, CityNode* root);
public:
	CityBST();
	~CityBST();
	void add(City data);
	bool find(string cityName);
	void preOrder();
	void inOrder();
	void postOrder();
	int height();
	void deleteNode(string name, std::pair <double, string> longtitudeIn, std::pair <double, string> latitudeIn);
	void printAllRecordsWithinAGivenDistance(std::pair <double, string> minlongtitudeIn, std::pair <double, string> minlatitudeIn, std::pair <double, string> maxlongtitudeIn, std::pair <double, string> maxlatitudeIn);
};

