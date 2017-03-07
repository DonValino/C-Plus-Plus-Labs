#include <iostream>
#include <string>
#include <algorithm>
#include "BSTTemplate.h"
using namespace std;

int main()
{
	// New Binary Tree Object
	BST<int> tree;
	tree.add(5);
	tree.add(4);
	tree.add(6);

	// Checking if this tree is a BST
	if (tree.isBST() == true)
	{
		cout << "This tree is a BST" << endl;
	}
	else
	{
		cout << "This tree is not a BST" << endl;
	}

	// Finding if a value exist in a tree
	if (tree.find(3) == true)
	{
		cout << "The value '3' exist in the tree" << endl;
	}
	else
	{
		cout << "The value '3' does not exist in the tree" << endl;
	}

	// Finding the height of the Tree
	cout << "Height Of The Tree" << endl;
	cout << tree.height() << endl;

	// Traversals

	cout << "Pre-Order:" << endl;
	tree.preOrder();
	cout << endl;

	cout << "In-Order:" << endl;
	tree.inOrder();
	cout << endl;

	cout << "Post-Order:" << endl;
	tree.postOrder();
	cout << endl;

	system("pause");
	return 0;
}