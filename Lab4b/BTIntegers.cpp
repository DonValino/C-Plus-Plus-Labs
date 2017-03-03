//
//  BTIntegers.cpp
//  Lab3b
//
//  Created by Jake Valino on 20/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.

// REFERENCE: http://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/

// REFERENCE: http://www.geeksforgeeks.org/root-to-leaf-path-sum-equal-to-a-given-number/

// REFERENCE: https://github.com/VitSalis/Algorithms/blob/master/data-structures/Binary-Trees/isBSTver1/isbst.cpp

#include "BTIntegers.hpp"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// TreeNode class Constructor
TreeNode::TreeNode(int dataIn)
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

void BinaryTree::add(int dataIn)
{
    // Initialize a new Treenode instance
    TreeNode* newNode = new TreeNode(dataIn);
    
    // Check if there isn't a root
    if (root == nullptr) {
        root = newNode;
    }else
    {
        add(newNode, root);
    }
}

void BinaryTree::add(TreeNode* newNode, TreeNode* root)
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


int BinaryTree::height()
{
    return height(root);
}

bool BinaryTree::isLeaf(TreeNode* root) {
    
    if (root != nullptr)
        return (root->leftPtr == nullptr && root->rightPtr == nullptr) ? false : true;
    return 0;
}

int BinaryTree::height(TreeNode * root)
{
    if(root == nullptr)
    {
        return -1;
    }else if(isLeaf(root->leftPtr), isLeaf(root->rightPtr))
    {
        return 1;
    }else
    {
        return 1 + std::max(height(root->leftPtr), height(root->rightPtr));
    }
    
    return 0;
}
// Public method - calls the private method
bool BinaryTree::hasPathSum(int sum)
{
    return hasPathSum(root, sum);
}

/* Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.*/
bool BinaryTree::hasPathSum(TreeNode* root, int sum)
{
    // If we run out of the tree, return true
    if(root == nullptr)
    {
        return (sum == 0);
    }else
    {
        // Check Subtrees
        
        bool ans = 0;
        
        int subSum = sum - root->data;
        
        // We reach a leaf node and sum becomes 0 then true
        if(subSum == 0 && root->leftPtr == nullptr && root->rightPtr == nullptr)
        {
            return 1;
        }
        
        if(root->leftPtr)
            ans = ans || hasPathSum(root->leftPtr, subSum);
        if(root->rightPtr)
            ans = ans || hasPathSum(root->rightPtr, subSum);
        
        return ans;
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

// Method to print the path
void BinaryTree::printArray(int num[], int len)
{
    int i;
    for (i=0; i < len; i++) {
        cout << num[i] << ", ";
    }
    cout << endl;
}

// Public method - calls the private method
void BinaryTree::printPaths()
{
    printPaths(root);
}

void BinaryTree::printPaths(TreeNode* root)
{
    // Creating an array to store all of the possible paths of the array
    int path[1000];
    // calling the recusive functions
    printPathsRecur(root, path, 0);
}

//Recursive helper function
void BinaryTree::printPathsRecur(TreeNode *root, int path[], int pathLen)
{
    // If the tree is empty, exit this method
    if(root == nullptr)
    {
        return;
    }
    // append the root node to the array
    path[pathLen] = root->data;
    pathLen++;
    
    // Its a leaf, so print the path that lead to here
    if(root->leftPtr == nullptr && root->rightPtr == nullptr)
    {
        printArray(path, pathLen);
    }else
    {
        // Try Other Subtrees
        printPathsRecur(root->leftPtr, path, pathLen);
        printPathsRecur(root->rightPtr, path, pathLen);
    }
    
}

// Returns the minimum data value found in that tree
int BinaryTree::minValue()
{
    return minValue(root);
}



int BinaryTree::minValue(TreeNode* root)
{
    if(root->leftPtr == nullptr)
    {
        return (root->data);
    }
    
    return (minValue(root->leftPtr));
}


// Returns the maximum data value found in that tree
int BinaryTree::maxValue()
{
    return maxValue(root);
}


int BinaryTree::maxValue(TreeNode* root)
{
    if(root->rightPtr == nullptr)
    {
        return (root->data);
    }
    
    return (maxValue(root->rightPtr));
}


//  returns true if a tree is a binary search tree and false otherwise - inefficient version
int BinaryTree::isBST()
{
    return isBST(root);
}

int BinaryTree::isBST(TreeNode* root)
{
    if(root == NULL)
    {
        return true;
    }
    
    if(root->leftPtr != nullptr && maxValue(root->leftPtr) > root->data)
    {
        return false;
    }
    
    if(root->rightPtr != nullptr && minValue(root->rightPtr) <= root->data)
    {
        return false;
    }
    
    if(isBST(root->leftPtr) == true && isBST(root->rightPtr) == true)
    {
        return true;
    }else
    {
        return false;
    }
}



//  returns true if a tree is a binary search tree and false otherwise - efficient version
int BinaryTree::isBST2()
{
    return isBST(root);
}

int BinaryTree::isBST2(TreeNode *root)
{
  return isBSTRecur(root, INT_MIN, INT_MAX);
}


// utility helper function  that traverses down the tree keeping track of the
// narrowing min and max allowed values as it goes, looking at each node only once.

int BinaryTree::isBSTRecur(TreeNode* root, int min, int max)
{
    if(root == nullptr)
    {
        return true;
    }
    
    int left, right;
    
    if(root->data >= min && root->data <= max)
    {
        left = isBSTRecur(root->leftPtr, min, max);
        right = isBSTRecur(root->rightPtr, min, max);
    }else
    {
        return false;
    }
    
    if(left == true && right == true)
    {
        return true;
    }else
    {
        return false;
    }
}






















