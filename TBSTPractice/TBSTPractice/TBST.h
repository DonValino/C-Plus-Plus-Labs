#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// TreeNode Declaration
template<typename T>
class TreeNode
{
	template<class T> friend class TBST;
private:
	T data;
	TreeNode<T>* leftPtr;
	TreeNode<T>* rightPtr;
public:
	TreeNode(T dataIn);
	~TreeNode();
};
///////////////////////

// TreeNode Implementation
// Constructor
template<typename T>
TreeNode<T>::TreeNode(T dataIn)
{
	data = dataIn;
}

// Destructor
template<typename T>
TreeNode<T>::~TreeNode()
{
	data = NULL;
	delete leftPtr;
	delete rightPtr;
}




// BinaryTree Declaration
template<typename T>
class TBST
{
private:
	TreeNode<T>* root;
	void add(TreeNode<T>* newNode, TreeNode<T>* root);
	void preOrder(TreeNode<T>* root);
	void inOrder(TreeNode<T>* root);
	void postOrder(TreeNode<T>* root);
	bool find(T dataIn, TreeNode<T>* root);
	int isLeaf(TreeNode<T>* root);
	int height(TreeNode<T>* root);
	bool isBST(TreeNode<T>* root);
	bool isBSTRecur(TreeNode<T>* root, int min, int max);
public:
	TBST();
	~TBST();
	void add(T dataIn);
	void preOrder();
	void inOrder();
	void postOrder();
	bool find(T dataIn);
	int height();
	bool isBST();
	
};
////////////////////////////

// BinaryTree Implementation
// Constructor
template<typename T>
TBST<T>::TBST()
	:root(nullptr)
{

}

// Destructor
template<typename T>
TBST<T>::~TBST()
{
	delete root->leftPtr;
	delete root->rightPtr;
}

// Add Method - Public
template<typename T>
void TBST<T>::add(T dataIn)
{
	TreeNode<T>* newNOde = new TreeNode<T>(dataIn);

	if (root == nullptr)
	{
		root = newNOde;
	}
	else
	{
		add(newNOde,root);
	}
}

// Add Method - Private
template<typename T>
void TBST<T>::add(TreeNode<T>* newNode, TreeNode<T>* root)
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
		add(newNode,root->rightPtr);
	}
}

// Pre-Order Traversal - Public
template<typename T>
void TBST<T>::preOrder()
{
	preOrder(root);
}

// Pre-Order Traversal - Public
template<typename T>
void TBST<T>::preOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		cout << root->data << ", ";
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}

// In-Order Traversal - Public
template<typename T>
void TBST<T>::inOrder()
{
	inOrder(root);
}

// In-Order Traversal - Public
template<typename T>
void TBST<T>::inOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		inOrder(root->leftPtr);
		cout << root->data << ", ";
		inOrder(root->rightPtr);
	}
}

// Post-Order Traversal - Public
template<typename T>
void TBST<T>::postOrder()
{
	postOrder(root);
}

// Post-Order Traversal - Public
template<typename T>
void TBST<T>::postOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		postOrder(root->leftPtr);
		postOrder(root->rightPtr);
		cout << root->data << ", ";
	}
}

// Find Method - Public
template<typename T>
bool TBST<T>::find(T dataIn)
{
	return find(dataIn, root);
}

// Find Method - Private
template<typename T>
bool TBST<T>::find(T dataIn, TreeNode<T>* root)
{
	if (root != nullptr)
	{
		if (root->data == dataIn)
		{
			return true;
		}
		else if (dataIn < root->data)
		{
			find(dataIn, root->leftPtr);
		}
		else
		{
			find(dataIn, root->rightPtr);
		}
	}
	else
	{
		return false;
	}
	return false;
}

// IsLeaf To check if a node is a leaf node - Private
template<typename T>
int TBST<T>::isLeaf(TreeNode<T>* root)
{
	if (root != nullptr)
		return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;

	return 0;
}

// Height Method -  Public
template<typename T>
int TBST<T>::height()
{
	return height(root);
}

// Height Method -  Private
template<typename T>
int TBST<T>::height(TreeNode<T>* root)
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

//isBST check if its a bindary tree - Public
template<typename T>
bool TBST<T>::isBST()
{
	return isBST(root);
}

//isBST check if its a bindary tree - Private
template<typename T>
bool TBST<T>::isBST(TreeNode<T>* root)
{
	return isBSTRecur(root, INT_MIN, INT_MAX);
}

// isBSTRecur helper method - Private
template<typename T>
bool TBST<T>::isBSTRecur(TreeNode<T>* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->data < min || root->data > max) return (false);

	return isBSTRecur(root->leftPtr, min, root->data) && isBSTRecur(root->rightPtr, root->data + 1, max);
}