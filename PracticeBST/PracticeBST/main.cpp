#include <iostream>
#include <string>
#include <algorithm>
#include "BST.h"

using namespace std;

int main()
{
	BST<int> tree;

	tree.add(5);
	tree.add(6);
	tree.add(4);
	tree.add(9);
	tree.add(11);

	// In-Order Traversal
	tree.inOrder();
	cout << endl;

	// Checking if this is a BST
	if (tree.isBST() == true)
	{
		cout << "This is a BST" << endl;
	}
	else
	{
		cout << "This is not a BST" << endl;
	}

	// Checking if the node 5 exist
	if (tree.find(5) == true)
	{
		cout << "The Node with the value 5 exist" << endl;
	}
	else
	{
		cout << "The Node with the value 5 does not exist" << endl;
	}

	// Checking if a path exist for the value 11
	if (tree.hasPathSum(11) == true)
	{
		cout << "A Path exist for the value 11" << endl;
	}
	else
	{
		cout << "A Path does not exist for the value 11" << endl;
	}

	// Trying to delete the node with value 11
	tree.deleteNode(11);

	// Redisplaying the data - inOrder
	tree.inOrder();

	system("pause");
	return 0;
}

