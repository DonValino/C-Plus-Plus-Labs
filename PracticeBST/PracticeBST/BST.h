#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// Don Valino X00112730

// TreeNode Class Declaration
template<typename T>
class TreeNode
{
	template<class T> friend class BST;
private:
	T data;
	TreeNode<T>* leftPtr;
	TreeNode<T>* rightPtr;
public:
	TreeNode(T dataIn);
	~TreeNode();
};
//////////////////////////////

// TreeNode Class Implementation

// Constructor
template<typename T>
TreeNode<T>::TreeNode(T dataIn)
{
	data = dataIn;
	leftPtr = nullptr;
	rightPtr = nullptr;
}

// Destructor
template<typename T>
TreeNode<T>::~TreeNode()
{
	data = NULL;
	delete leftPtr;
	delete rightPtr;
}
////////////////////////////////////////////

// BST Class Declaration
template<typename T>
class BST
{
private:
	TreeNode<T>* root;
	void add(TreeNode<T>* newNode, TreeNode<T>* root);
	bool find(T dataIn, TreeNode<T>* root);
	bool isLeaf(TreeNode<T>* root);
	int height(TreeNode<T>* root);
	bool isBST(TreeNode<T>* root);
	bool isBSTRecur(TreeNode<T>* root, int min, int max);
	bool hasPathSum(T sum, TreeNode<T>* root);
	void preOrder(TreeNode<T>* root);
	void inOrder(TreeNode<T>* root);
	void postOrder(TreeNode<T>* root);

	TreeNode<T>* findMin(TreeNode<T>* root);
	TreeNode<T>* deleteNode(T dataIn, TreeNode<T>* root);

public:
	BST();
	~BST();
	void add(T dataIn);
	bool find(T dataIn);
	int height();
	bool isBST();
	bool hasPathSum(T sum);
	void preOrder();
	void inOrder();
	void postOrder();

	void deleteNode(T dataIn);
};
/////////////////////////////////////////////////////////////////

// BST Class Implementation

// Constructor
template<typename T>
BST<T>::BST()
	:root(nullptr)
{

}

// Destructor
template<typename T>
BST<T>::~BST()
{
	delete root->leftPtr;
	delete root->rightPtr;
}

// add Method - Public
// Add A New Node to the Binary Search Tree
template<typename T>
void BST<T>::add(T dataIn)
{
	// Making A new TreeNode object
	TreeNode<T>* newNode = new TreeNode<T>(dataIn);

	if (root == nullptr)
	{
		// if BST Is Empty
		root = newNode;
	}
	else
	{
		// Recursively determine the correct position to add the node
		add(newNode, root);
	}
}

// add Method - Private
template<typename T>
void BST<T>::add(TreeNode<T>* newNode, TreeNode<T>* root)
{
	if (newNode->data < root->data)
	{
		if (root->leftPtr == nullptr)
		{
			root->leftPtr = newNode;
		}
		else
		{
			add(newNode, root->leftPtr);
		}
	}
	else if (root->rightPtr == nullptr)
	{
		root->rightPtr = newNode;
	}
	else
	{
		add(newNode, root->rightPtr);
	}
}


// Find Method - Public
// Check if a node with a specific value exist in the tree
template<typename T>
bool BST<T>::find(T dataIn)
{
	return find(dataIn, root);
}

// Find Method - Private
template<typename T>
bool BST<T>::find(T dataIn, TreeNode<T>* root)
{
	if (root != nullptr)
	{
		if (root->data == dataIn)
		{
			return true;
		}
		else if (dataIn < root->data)
		{
			return find(dataIn, root->leftPtr);
		}
		else
		{
			return find(dataIn, root->rightPtr);
		}
	}
	else
	{
		return false;
	}
}

// isLeaf Method - Private
// Determine whether a node is a leaf node
template<typename T>
bool BST<T>::isLeaf(TreeNode<T>* root)
{
	if (root != nullptr)
		return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;
	return false;
}

// height Method - Public
// Returns the height of the tree
template<typename T>
int BST<T>::height()
{
	return height(root);
}

// height Method - Private
template<typename T>
int BST<T>::height(TreeNode<T>* root)
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

// isBst Method - Public
// Determine whether the tree is a Bindary Search Tree
template<typename T>
bool BST<T>::isBST()
{
	return isBST(root);
}

// isBst Method - Private
template<typename T>
bool BST<T>::isBST(TreeNode<T>* root)
{
	return isBSTRecur(root, INT_MIN, INT_MAX);
}

// isBst Method - Private
template<typename T>
bool BST<T>::isBSTRecur(TreeNode<T>* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->data < min || root->data > max) return (false);

	return isBSTRecur(root->leftPtr, min, root->data) && isBSTRecur(root->rightPtr, root->data + 1, max);
}

// hasPathSum Method - Public
// Determine whether a path exist with the specified sum
template<typename T>
bool BST<T>::hasPathSum(T sum)
{
	return hasPathSum(sum, root);
}

// hasPathSum Method - Private
template<typename T>
bool BST<T>::hasPathSum(T sum, TreeNode<T>* root)
{
	if (root == nullptr)
	{
		return false;
	}
	else
	{
		bool ans = false;

		int subSum = sum - root->data;

		if (subSum == 0 && root->leftPtr == nullptr && root->rightPtr == nullptr)
		{
			ans = 1;
		}

		if (root->leftPtr)
			ans = ans || hasPathSum(sum, root->leftPtr);
		if (root->rightPtr)
			ans = ans || hasPathSum(sum, root->rightPtr);
	}
}

// findMin Method -- Private
template<typename T>
TreeNode<T>* BST<T>::findMin(TreeNode<T>* root)
{
	while (root->leftPtr != nullptr)
	{
		root = root->leftPtr;
	}

	return root;
}

// deleteNode Method - Public
// delete a node with a specific value
template<typename T>
void BST<T>::deleteNode(T dataIn)
{
	deleteNode(dataIn, root);
}

// deleteNode Method - Private
template<typename T>
TreeNode<T>* BST<T>::deleteNode(T dataIn, TreeNode<T>* root)
{
	if (root != nullptr)
	{
		if (dataIn < root->data)
		{
			root->leftPtr = deleteNode(dataIn, root->leftPtr);
		}
		else if (dataIn > root->data)
		{
			root->rightPtr = deleteNode(dataIn, root->rightPtr);
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
				TreeNode<T>* temp = root;
				root = root->rightPtr;
				delete temp;
			}
			else if (isLeaf(root->rightPtr))
			{
				TreeNode<T>* temp = root;
				root = root->leftPtr;
				delete temp;
			}
			else
			{
				TreeNode<T>* temp = findMin(root->rightPtr);
				root->data = temp->data;
				root->rightPtr = deleteNode(temp->data, root->rightPtr);
			}
		}
	}

	return root;
}


// Traversals

// Public Methods - Traversals
template<typename T>
void BST<T>::preOrder()
{
	preOrder(root);
}
template<typename T>
void BST<T>::inOrder()
{
	inOrder(root);
}
template<typename T>
void BST<T>::postOrder()
{
	postOrder(root);
}
///////////////////////////////////
// Private Methods - Traversals

template<typename T>
void BST<T>::preOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		cout << root->data;
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}

template<typename T>
void BST<T>::inOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		inOrder(root->leftPtr);
		cout << root->data;
		inOrder(root->rightPtr);
	}
}

template<typename T>
void BST<T>::postOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		postOrder(root->leftPtr);
		postOrder(root->rightPtr);
		postOrder
	}
}
////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////