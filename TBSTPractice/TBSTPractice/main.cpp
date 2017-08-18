#include <iostream>
#include <algorithm>
#include <string>
#include "TBST.h"

using namespace std;

int main()
{

	TBST<int> tree;
	tree.add(1);
	tree.add(2);
	tree.add(3);

	tree.preOrder();
	cout << endl;

	tree.inOrder();
	cout << endl;

	tree.postOrder();
	cout << endl;

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

	system("pause");

	return 0;
}