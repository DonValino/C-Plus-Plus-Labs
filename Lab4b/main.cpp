//
//  main.cpp
//  Lab4b
//
//  Created by Jake Valino on 03/03/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include "BTIntegers.hpp"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {

    BinaryTree tree;
    tree.add(5);
    tree.add(4);
    tree.add(6);
    
    if(tree.isBST() == true)
    {
        cout << "This tree is a binary tree" << endl;
    }else
    {
        cout << "This tree is not a binary tree" << endl;
    }
    
    if(tree.isBST2() == true)
    {
        cout << "This tree is a binary tree" << endl;
    }else
    {
        cout << "This tree is not a binary tree" << endl;
    }
    
    return 0;
}
