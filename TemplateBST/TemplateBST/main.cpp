#include <string>
#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BinaryTree<int> tree;

	tree.add(5);
	tree.add(3);
	tree.add(7);

	cout << "Height Of The Tree: " << tree.height() << endl;

	if (tree.find(3) == true)
	{
		cout << "Node 3 Exist " << endl;
	}

	tree.deleteNode(3);

	cout << "Node 3 Deleted" << endl;

	if (!tree.find(3) == true)
	{
		cout << "Node 3 doesn't Exist " << endl;
	}

	tree.inOrder();
	system("pause");
	return 0;
}