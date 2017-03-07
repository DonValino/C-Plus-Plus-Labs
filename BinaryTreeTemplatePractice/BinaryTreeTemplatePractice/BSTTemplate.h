#pragma once
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Don Valino X00112730

// Tree Node Class Declaration
template<typename T>
class TreeNode
{
	template<class T> friend class BST;
private:
	T data;
	TreeNode* leftPtr;
	TreeNode* rightPtr;
public:
	TreeNode(T dataIn);
	~TreeNode();

};

// Tree Node Class Implementation

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
	leftPtr = nullptr;
	rightPtr = nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// BST Class Declaration

template<typename T>
class BST
{
private:
	TreeNode<T>* root;
	void add(TreeNode<T>* newNode, TreeNode<T>* root);
	bool find(T dataIn, TreeNode<T>* root);
	void postOrder(TreeNode<T>* root);
	void inOrder(TreeNode<T>* root);
	void preOrder(TreeNode<T>* root);
	int max(TreeNode<T>* root);
	int min(TreeNode<T>* root);
	bool isBST(TreeNode<T>* root);
	bool isBSTRecur(TreeNode<T>* root, int min, int max);
	bool isLeaf(TreeNode<T>* root);
	int height(TreeNode<T>* root);
public:
	BST();
	~BST();
	void add(T dataIn);
	bool find(T dataIn);
	void postOrder();
	void inOrder();
	void preOrder();
	int min();
	int max();
	bool isBST();
	int height();
};


// BST Class Implementation

// Constructor
template<typename T>
BST<T>::BST()
	:root(NULL)
{

}

// Destructor
template<typename T>
BST<T>::~BST()
{
	delete root->leftPtr;
	delete root->rightPtr;
}


// Add Method - Public Method
template<typename T>
void BST<T>::add(T dataIn)
{
	// Making a new Node
	TreeNode<T>* newNode = new TreeNode<T>(dataIn);

	if (root == nullptr)
	{
		root = newNode;
	}
	else
	{
		// Calling the private method of add which will recursively check where to add the node
		add(newNode, root);
	}
}

// Add Method - Private Method
template<typename T>
void BST<T>::add(TreeNode<T>* newNode, TreeNode<T>* root)
{
	if (newNode->data < root->data)
	{
		if (root->leftPtr == nullptr)
		{
			// Add to left pointer if this is the leaf node
			root->leftPtr = newNode;
		}
		else
		{
			// Recusively check to get to the leaf node
			add(newNode, root->leftPtr);
		}
	}
	else if (root->rightPtr == nullptr)
	{
		// Add to right pointer if this is the leaf node
		root->rightPtr = newNode;
	}
	else
	{
		// Recusively check to get to the leaf node
		add(newNode, root->rightPtr);
	}
}


// Find Method - Public Method
template<typename T>
bool BST<T>::find(T dataIn)
{
	return find(dataIn, root);
}

// Find Method - Private Method
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

// isLeaf method - Public
template<typename T>
bool BST<T>::isLeaf(TreeNode<T>* root)
{
	if (root != nullptr)
		return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;
	return 0;
}

// height method - Public
template<typename T>
int BST<T>::height()
{
	return height(root);
}

// height method - PRivate
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
		return 1 + std::max(height(root->leftPtr),height(root->rightPtr));
	}
}

// Pre Order- Public Method
template<typename T>
void BST<T>::preOrder()
{
	// Calling the private method of In-Order which will recursively display the BST data in In-Order
	preOrder(root);
}

// Pre Order- Private Method
template<typename T>
void BST<T>::preOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		cout << root->data << ", ";
		preOrder(root->leftPtr);
		preOrder(root->rightPtr);
	}
}

// In-Order - Public Method
template<typename T>
void BST<T>::inOrder()
{
	// Calling the private method of In-Order which will recursively display the BST data in In-Order
	inOrder(root);
}

// In-Order - Private Method
template<typename T>
void BST<T>::inOrder(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		inOrder(root->leftPtr);
		cout << root->data << ", ";
		inOrder(root->rightPtr);
	}
}

// Post Order - Public Method
template<typename T>
void BST<T>::postOrder()
{
	// Calling the private method of postOrder which will recursively display the BST data in Post Order
	postOrder(root);
}

// Post Order - Private Method
template<typename T>
void BST<T>::postOrder(TreeNode<T>* root)
{
	if (root != nullptr) {

		postOrder(root->leftPtr);
		postOrder(root->rightPtr);
		std::cout << root->data << ", ";
	}
}

// Max - Public Method
template<typename T>
int BST<T>::max()
{
	return max(root);
}

// Max - Private Method
template<typename T>
int BST<T>::max(TreeNode<T>* root)
{
	if (root->rightPtr == nullptr)
	{
		return root->data
	}

	return (max(root->rightPtr));
}


// Min - Public Method
template<typename T>
int BST<T>::min()
{
	return min(root);
}

// Min - Private Method
template<typename T>
int BST<T>::min(TreeNode<T>* root)
{
	if (root->leftPtr == nullptr)
	{
		return root->data
	}

	return(min(root->leftPtr));
}

//  returns true if a tree is a binary search tree and false otherwise - efficient version
template<typename T>
bool BST<T>::isBST()
{
	return isBST(root);
}

template<typename T>
bool BST<T>::isBST(TreeNode<T> *root)
{
	return isBSTRecur(root, INT_MIN, INT_MAX);
}


// utility helper function  that traverses down the tree keeping track of the
// narrowing min and max allowed values as it goes, looking at each node only once. - Stanford University source
template<typename T>
bool BST<T>::isBSTRecur(TreeNode<T>* root, int min, int max)
{
	if (root == nullptr)
	{
		return true;
	}
	// min/max constraint is violated and therefore returns false
	if (root->data < min || root->data > max) return (false);

	// checking subtrees recursively
	return isBSTRecur(root->leftPtr, min, root->data) && isBSTRecur(root->rightPtr, root->data + 1, max);
}