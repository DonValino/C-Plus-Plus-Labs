#include <iostream>
#include "TreeNode.h"
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	BinaryTree<char> tree;
	tree.add('a');
	tree.add('b');
	tree.add('c');
	tree.add('d');

	tree.postOrder();
	system("pause");
}
