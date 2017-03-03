//
//  BTChars.cpp
//  Lab3b
//
//  Created by Jake Valino on 20/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include "BTChars.hpp"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// TreeNode class Constructor
TreeNode::TreeNode(char dataIn)
{
    data = dataIn;
    leftPtr = nullptr;
    rightPtr = nullptr;
}

// BinaryTree class default constructor - root node is initially null
BinaryTree::BinaryTree()
:root(nullptr)
{
    
}

// BinaryTree class destructor
BinaryTree::~BinaryTree()
{
    delete root->leftPtr;
    delete root->rightPtr;
}

//Add
void BinaryTree::add(char data)
{
    TreeNode* newNode = new TreeNode(data);
    
    if(root == nullptr)
    {
        root = newNode;
    }else
    {
        add(newNode, root);
    }
}
// Add - Recusion
void BinaryTree::add(TreeNode *newNode, TreeNode *root)
{
    if(newNode->data < root->data)
    {
        if(root->leftPtr == nullptr)
        {
            root->leftPtr = newNode;
        }else
        {
            add(newNode, root->leftPtr);
        }
    }else if(root->rightPtr == nullptr)
    {
        root->rightPtr = newNode;
    }else
    {
        add(newNode, root->rightPtr);
    }
}

// Check if its a leaf node
bool BinaryTree::isLeaf(TreeNode* root)
{
    if(root != nullptr)
        return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false:true;
    return 5;
}

// Height
int BinaryTree::height()
{
    return height(root);
}


// Height
int BinaryTree::height(TreeNode *root)
{
    if(root == nullptr)
    {
        return -1;
    }else if(isLeaf(root->leftPtr) , isLeaf(root->rightPtr))
    {
        return 1;
    }else
    {
        return 1 + std::max(height(root->leftPtr), height(root->rightPtr) );
    }
}

// Find
bool BinaryTree::find(char dataIn)
{
    return find(dataIn, root);
}


// Find - Recusion
bool BinaryTree::find(char dataIn, TreeNode* root)
{
    if (root != nullptr) {
        if(dataIn == root->data)
        {
            return true;
        }else if(dataIn < root->data)
        {
            return find(dataIn, root->leftPtr);
        }else
        {
            return find(dataIn, root->rightPtr);
        }
    }else
    {
        return false;
    }
}

// Pre-Order Traversal
void BinaryTree::preOrder()
{
    preOder(root);
}

// Pre-Order Traversal - Resursion
void BinaryTree::preOder(TreeNode *root)
{
    if (root != nullptr) {
        cout << root->data;
        preOder(root->leftPtr);
        preOder(root->rightPtr);
    }
}


// Post Order Traversal
void BinaryTree::postOrder() {
    postOrder(root);
}

// Post Order Traversal - Resursion
void BinaryTree::postOrder(TreeNode* root) {
    
    if (root != nullptr) {
        
        postOrder(root->leftPtr);
        postOrder(root->rightPtr);
        std::cout << root->data;
    }
}


