#include "CityBST.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Constructor
CityBST::CityBST()
	:root(NULL)
{

}

// Destructor
CityBST::~CityBST()
{
	delete root->leftPtr;
	delete root->rightPtr;
}

// Add Method - Public Method
void CityBST::add(City data)
{
	CityNode* newNode = new CityNode(data);

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		add(newNode, root);
	}
}

// Add Method - Private Method
void CityBST::add(CityNode * newNode, CityNode * root)
{
	// Storing city based on the name
	if (newNode->data.getName().compare(root->data.getName()) < 0)
	{
		if (root->leftPtr == nullptr)
		{
			// Chcking that there isn't already a city with the same coordinates
			if (root->data.getLatitutde() != newNode->data.getLatitutde() || root->data.getLongtitude() != newNode->data.getLongtitude())
			{
				// Add to left pointer if this is the leaf node
				root->leftPtr = newNode;
			}
			else if (root->data.getLatitutde() == newNode->data.getLatitutde() && root->data.getLongtitude() == newNode->data.getLongtitude())
			{
				cout << "Error, Cannot Insert the city ''" << newNode->data.getName() << "'' In this location.\nReason: No two city can exist with the same coordinates !!" << endl;
				cout << "City that already exist in this location: ''" << root->data.getName() << "''" << endl << endl;
			}
		}
		else
		{
			// Recusively check to get to the leaf node
			add(newNode, root->leftPtr);
		}
	}
	else if (root->rightPtr == nullptr)
	{
		// Chcking that there isn't already a city with the same coordinates
		if (root->data.getLatitutde() != newNode->data.getLatitutde() || root->data.getLongtitude() != newNode->data.getLongtitude())
		{
			// Add to right pointer if this is the leaf node
			root->rightPtr = newNode;
		}
		else if (root->data.getLatitutde() == newNode->data.getLatitutde() && root->data.getLongtitude() == newNode->data.getLongtitude())
		{
			cout << "Error, Cannot Insert the city ''" << newNode->data.getName() << "'' In this location.\nReason: No two city can exist with the same coordinates !!" << endl;
			cout << "City that already exist in this location: ''" << root->data.getName() << "''" << endl << endl;
		}
	}
	else
	{
		// Recusively check to get to the leaf node
		add(newNode, root->rightPtr);
	}
}

// Find Method - Public
// Check if a node with a specific value exist in the tree
bool CityBST::find(string cityName)
{
	return find(cityName, root);
}

// Find Method - Private
bool CityBST::find(string cityName, CityNode * root)
{
	if (root != nullptr)
	{
		if (root->data.getName() == cityName)
		{
			return true;
		}
		else if (cityName.compare(root->data.getName()) < 0)
		{
			return find(cityName, root->leftPtr);
		}
		else
		{
			return find(cityName, root->rightPtr);
		}
	}
	else
	{
		return false;
	}
}

// isLeaf Method - Private
// Determine whether a node is a leaf node
bool CityBST::isLeaf(CityNode * root)
{
	if (root != nullptr)
		return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;
	return false;
}

// height Method - Public
// Returns the height of the tree
int CityBST::height()
{
	return height(root);
}

// height Method - Private
int CityBST::height(CityNode * root)
{
	if (root == nullptr)
	{
		return 0;
	}
	else if (isLeaf(root->leftPtr), isLeaf(root->rightPtr))
	{
		return 1;
	}
	else
	{
		return 1 + std::max(height(root->leftPtr), height(root->rightPtr));
	}
}

// findMin Method - Private
CityNode * CityBST::findMin(CityNode * root)
{
	while (root->leftPtr != nullptr)
	{
		root = root->leftPtr;
	}

	return root;
}

// deleteNode Method - Public
// delete a node with a specific value
void CityBST::deleteNode(string name, std::pair<double, string> longtitudeIn, std::pair<double, string> latitudeIn)
{
	deleteNode(name, longtitudeIn, latitudeIn, root);
}

// deleteNode Method - Private
CityNode * CityBST::deleteNode(string name, std::pair<double, string> longtitudeIn, std::pair<double, string> latitudeIn, CityNode * root)
{
	if (root != nullptr)
	{
		if (name.compare(root->data.getName()) < 0)
		{
			root->leftPtr = deleteNode(name, longtitudeIn, latitudeIn, root->leftPtr);
		}
		else if (name.compare(root->data.getName()) > 0)
		{
			root->rightPtr = deleteNode(name, longtitudeIn, latitudeIn, root->rightPtr);
		}
		else
		{
			if (root->leftPtr == nullptr && root->rightPtr == nullptr)
			{
					delete root;
					root = nullptr;
			}
			else if (isLeaf(root->leftPtr))
			{
				if (root->data.getLongtitude() == longtitudeIn && root->data.getLatitutde() == latitudeIn)
				{

					CityNode* temp = root;
					root = root->rightPtr;
					delete temp;
				}
				else
				{
					// No City Name With Matching Name And Location Found
					cout << "No City with that name or location was found" << endl << endl;
				}
			}
			else if (isLeaf(root->rightPtr))
			{
				if (root->data.getLongtitude() == longtitudeIn && root->data.getLatitutde() == latitudeIn)
				{

					CityNode* temp = root;
					root = root->leftPtr;
					delete temp;
				}
				else
				{
					// No City Name With Matching Name And Location Found
					cout << "No City with that name or location was found" << endl << endl;
				}
			}
			else
			{
				if (root->data.getLongtitude() == longtitudeIn && root->data.getLatitutde() == latitudeIn)
				{
					CityNode* temp = findMin(root->rightPtr);
					root->data = temp->data;
					root->rightPtr = deleteNode(temp->data.getName(), temp->data.getLatitutde(), temp->data.getLongtitude(), root->rightPtr);
				}
				else
				{
					// No City Name With Matching Name And Location Found
					cout << "No City with that name or location was found" << endl << endl;
				}
				
			}
		}
	}

	return root;
}

// Pre-Order Method - Public Method

// Pre-Order Traversal
void CityBST::preOrder()
{
	preOrder(root);
}

// In-Order Traversal
void CityBST::inOrder()
{
	inOrder(root);
}

// Post-Order Traversal
void CityBST::postOrder()
{
	postOrder(root);
}
///////////////////////////////////
// Private Methods - Traversals

void CityBST::preOrder(CityNode * root)
{
	if (root != nullptr)
	{
		cout << root->data << endl;
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}

void CityBST::inOrder(CityNode * root)
{
	if (root != nullptr)
	{
		inOrder(root->leftPtr);
		cout << root->data << endl;
		inOrder(root->rightPtr);
	}
}

void CityBST::postOrder(CityNode * root)
{
	if (root != nullptr)
	{
		postOrder(root->leftPtr);
		postOrder(root->rightPtr);
		cout << root->data << endl;
	}
}

// Print All Records Within A Given Distance - Public
void CityBST::printAllRecordsWithinAGivenDistance(std::pair <double, string> minlongtitudeIn, std::pair <double, string> minlatitudeIn, std::pair <double, string> maxlongtitudeIn, std::pair <double, string> maxlatitudeIn)
{
	printAllRecordsWithinAGivenDistance(minlongtitudeIn, minlatitudeIn, maxlongtitudeIn, maxlatitudeIn, root);
}

// Print All Records Within A Given Distance - Private
void CityBST::printAllRecordsWithinAGivenDistance(std::pair <double, string> minlongtitudeIn, std::pair <double, string> minlatitudeIn, std::pair <double, string> maxlongtitudeIn, std::pair <double, string> maxlatitudeIn, CityNode* root)
{
	// Here we will print all the records within a given distance using In-Order Traversal
	if (root != nullptr)
	{
		printAllRecordsWithinAGivenDistance(minlongtitudeIn, minlatitudeIn, maxlongtitudeIn, maxlatitudeIn, root->leftPtr);
		if (root->data.getLongtitude().first >= minlongtitudeIn.first && root->data.getLongtitude().first <= maxlongtitudeIn.first 
			&& root->data.getLatitutde().first >= minlatitudeIn.first && root->data.getLatitutde().first <= maxlatitudeIn.first)
		{
			cout << root->data << endl;
		}
		printAllRecordsWithinAGivenDistance(minlongtitudeIn, minlatitudeIn, maxlongtitudeIn, maxlatitudeIn, root->rightPtr);
	}

}
