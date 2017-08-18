#pragma once
#include <iostream>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

// TreeNode Class
template<typename T>
class TreeNode {

	template<class T>friend class BinaryTree;

private:
	TreeNode<T> *left;
	T data;
	TreeNode<T> *right;

public:
	TreeNode(T data);
	~TreeNode();
};

template<typename T>
inline TreeNode<T>::TreeNode(T data) : left(NULL), data(data), right(NULL)
{
}

template<typename T>
inline TreeNode<T>::~TreeNode()
{
	delete left;
	data = NULL;
	delete right;
} 


// BinaryTree Class
template<typename T>
class BinaryTree {

private:

	TreeNode<T> *root;
	void add(TreeNode<T> *node, TreeNode<T> *root);
	int height(TreeNode<T> *root);
	void InOrderTransversal(TreeNode<T> *root);
	void postOrder(TreeNode<T> * root);

public:
	BinaryTree();
	~BinaryTree();

	void add(T data);
	int height();
	void sort();
	void postOrder();
};

template<typename T>
BinaryTree<T>::BinaryTree() : root(NULL)
{
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	delete root;
}

template<typename T>
void BinaryTree<T>::add(T data)
{
	TreeNode<T> *node = new TreeNode<T>(data);
	if (root == NULL) {
		root = node;
		return;
	}
	else {
		add(node, root);
	}
}

template<typename T>
void BinaryTree<T>::add(TreeNode<T> *node, TreeNode<T> *root)
{
	if (node->data < root->data) {
		if (root->left == NULL) {
			root->left = node;
		}
		else {
			add(node, root->left);
		}
	}
	else if (node->data > root->data) {
		if (root->right == NULL) {
			root->right = node;
		}
		else {
			add(node, root->right);
		}
	}
}

template<typename T>
int BinaryTree<T>::height(TreeNode<T> *root)
{
	if (root == NULL) {
		return -1;
	}
	else {
		return 1 + max(height(root->left), height(root->right));
	}
}

template<typename T>
void BinaryTree<T>::InOrderTransversal(TreeNode<T> *root)
{
	if (root != NULL) {
		InOrderTransversal(root->left);
		cout << root->data << endl;
		InOrderTransversal(root->right);
	}
}

template<typename T>
void BinaryTree<T>::postOrder()
{
	postOrder(root);
}

template<typename T>
void BinaryTree<T>::postOrder(TreeNode<T>* root)
{
	if (root != nullptr) {

		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->data;
	}
}


template<typename T>
int BinaryTree<T>::height()
{
	return height(root);
}

template<typename T>
void BinaryTree<T>::sort()
{
	InOrderTransversal(root);
}