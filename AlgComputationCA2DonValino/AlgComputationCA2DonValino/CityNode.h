#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "City.h"


using namespace std;

class CityNode
{
	friend class CityBST;
private:
	City data;
	CityNode* leftPtr;
	CityNode* rightPtr;

public:
	CityNode(City dataIn);
	~CityNode();
	bool isLeaf();
};

