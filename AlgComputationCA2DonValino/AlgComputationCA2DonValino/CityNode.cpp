#include "CityNode.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "city.h"
#include <map>

using namespace std;

// Tree Node Constructor
CityNode::CityNode(City dataIn)
	:data
	(dataIn)
{
	leftPtr = nullptr;
	rightPtr = nullptr;
}

CityNode::~CityNode()
{
	leftPtr = nullptr;
	rightPtr = nullptr;
}

// isLeaf method - Check if this node is a leaf node with left & right pointer == nullptr
bool CityNode::isLeaf()
{
	if (leftPtr == nullptr && rightPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
