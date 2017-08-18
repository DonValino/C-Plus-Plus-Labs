#pragma once
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// <-- TreeNode Class -->
template<typename T>
class TreeNode
{
	template<class T>friend class BinaryTree;
private:
	T data;
	TreeNode* leftPtr;
	TreeNode* rightPtr;
public:
	TreeNode(T dataIn);
	~TreeNode();
};

// Constructor
template<typename T>
TreeNode<T>::TreeNode(T dataIn)
{
	data = dataIn;
	leftPtr = nullptr;
	rightPtr = nullptr;
}

//Destructor
template<typename T>
TreeNode<T>::~TreeNode()
{
	data = NULL;
	delete leftPtr;
	delete rightPtr;
}

// <-- BinaryTree Class -->
template<typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
	void add(TreeNode<T>* newNode, TreeNode<T>* root);
	bool find(T dataIn, TreeNode<T>* root);
	TreeNode<T>* deleteNode(T dataIn, TreeNode<T>* root);
	TreeNode<T>* findMin(TreeNode<T>* root);
	void preOrder(TreeNode<T>* root);
	void inOrder(TreeNode<T>* root);
	void postOrder(TreeNode<T>* root);
	int height(TreeNode<T> *root);
	int isLeaf(TreeNode<T> *root);

public:
	BinaryTree();
	~BinaryTree();
	void add(T dataIn);
	bool find(T dataIn);
	void deleteNode(T dataIn);
	void preOrder();
	void inOrder();
	void postOrder();
	int height();

};


// Constructor
template<typename T>
BinaryTree<T>::BinaryTree() : root(nullptr)
{

}

// Destructor
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete root->leftPtr;
	delete root->rightPtr;
}

// Add Method
template<typename T>
void BinaryTree<T>::add(T dataIn)
{
	TreeNode<T>* newNode = new TreeNode<T>(dataIn);

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		add(newNode, root);
	}
}

template<typename T>
void BinaryTree<T>::add(TreeNode<T>* newNode, TreeNode<T>* root)
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

// Find A Node If it exist (True / False)
template<typename T>
bool BinaryTree<T>::find(T dataIn)
{
	return find(dataIn, root);
}

template<typename T>
bool BinaryTree<T>::find(T dataIn, TreeNode<T>* root)
{
	if (root != nullptr)
	{
		if (dataIn == root->data)
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


// Delete A Node From The Tree
template<typename T>
void BinaryTree<T>::deleteNode(T dataIn)
{
	deleteNode(dataIn, root);
}

template<typename T>
TreeNode<T>* BinaryTree<T>::deleteNode(T dataIn, TreeNode<T>* root)
{
	if (root != nullptr) {
		if (dataIn < root->data) {
			root->leftPtr = deleteNode(dataIn, root->leftPtr);
		}
		else if (dataIn > root->data) {
			root->rightPtr = deleteNode(dataIn, root->rightPtr);
		}
		else {
			if (isLeaf(root->leftPtr) && isLeaf(root->rightPtr)) {
				delete root;
				root = nullptr;
			}
			else if (isLeaf(root->leftPtr)) {
				TreeNode<T>* temp = root;
				root = root->rightPtr;
				delete temp;
			}
			else if (isLeaf(root->rightPtr)) {
				TreeNode<T>* temp = root;
				root = root->leftPtr;
				delete temp;
			}
			else {
				TreeNode<T>* temp = findMin(root->rightPtr);
				root->data = temp->data;
				root->rightPtr = deleteNode(temp->data, root->rightPtr);
			}
		}
	}

	return root;
}

// Find Minimum node
template<typename T>
TreeNode<T>* BinaryTree<T>::findMin(TreeNode<T>* root)
{
	if (root->leftPtr == nullptr)
	{
		TreeNode<T>* node = new TreeNode<T>(root->data);
		return (node);
	}

	return (findMin(root->leftPtr));
}

// Pre-Order Traversal

template<typename T>
void BinaryTree<T>::preOrder()
{
	preOrder(root);
}

template<typename T>
void BinaryTree<T>::preOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		cout << root->data << endl;
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}


// In-Order Traversal

template<typename T>
void BinaryTree<T>::inOrder()
{
	inOrder(root);
}

template<typename T>
void BinaryTree<T>::inOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		preOrder(root->leftPtr);
		cout << root->data << endl;
		preOrder(root->rightPtr);
	}
}


// Post-Order Traversal

template<typename T>
void BinaryTree<T>::postOrder()
{
	postOrder(root);
}

template<typename T>
void BinaryTree<T>::postOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		postOrder(root->leftPtr);
		postOrder(root->rightPtr);
		cout << root->data << endl;
	}
}

// Checking If It Is A Leaf node
template<typename T>
int  BinaryTree<T>::isLeaf(TreeNode<T> *root)
{
	if (root != nullptr)
		return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;
	return 0;
}

// Height Of The BinaryTree
template<typename T>
int BinaryTree<T>::height()
{
	return height(root);
}

template<typename T>
int BinaryTree<T>::height(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return -1;
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
