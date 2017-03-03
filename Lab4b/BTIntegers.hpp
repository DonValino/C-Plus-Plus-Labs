//
//  BTIntegers.hpp
//  Lab3b
//
//  Created by Jake Valino on 20/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#ifndef BTIntegers_hpp
#define BTIntegers_hpp
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

// Node Class
class TreeNode
{
    friend class BinaryTree;
private:
    int data;
    TreeNode* leftPtr;
    TreeNode* rightPtr;
    
public:
    TreeNode(int dataIn);
    
};

class BinaryTree {
    
private:
    TreeNode* root;
    void add(TreeNode* newNode, TreeNode* root);
    int height(TreeNode* root);
    bool isLeaf(TreeNode* root);
    bool hasPathSum(TreeNode* root, int sum);
    void preOder(TreeNode* root);
    void postOrder(TreeNode* root);
    void printPaths(TreeNode* root);
    void printPathsRecur(TreeNode* root, int path[], int pathLen);
    void printArray(int num[], int len);
    int minValue(TreeNode* root);
    int maxValue(TreeNode* root);
    int isBST(TreeNode* root);
    int isBST2(TreeNode* root);
    int isBSTRecur(TreeNode* root, int min, int max);
    
public:
    BinaryTree();
    ~BinaryTree();
    void add(int toAdd);
    int height();
    bool hasPathSum(int sum);
    void preOrder();
    void postOrder();
    void printPaths();
    int minValue();
    int maxValue();
    int isBST();
    int isBST2();
};
#endif /* BTIntegers_hpp */
