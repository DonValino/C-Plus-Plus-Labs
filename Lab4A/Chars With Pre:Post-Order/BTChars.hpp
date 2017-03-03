//
//  BTChars.hpp
//  Lab3b
//
//  Created by Jake Valino on 20/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#ifndef BTChars_hpp
#define BTChars_hpp
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

#include <stdio.h>

// Class Node
class TreeNode
{
    friend class BinaryTree;
    
private:
    char data;
    TreeNode* leftPtr;
    TreeNode* rightPtr;
    
public:
    TreeNode(char dataIn);
};

// BinaryTree Class
class BinaryTree
{
private:
    TreeNode* root;
    void add(TreeNode* newNode, TreeNode* root);
    int height(TreeNode* root);
    bool isLeaf(TreeNode* root);
    bool find(char dataIn, TreeNode* root);
    void preOder(TreeNode* root);
    void postOrder(TreeNode* root);
public:
    BinaryTree();
    ~BinaryTree();
    void add(char data);
    int height();
    bool find(char dataIn);
    void preOrder();
    void postOrder();
};

#endif /* BTChars_hpp */
