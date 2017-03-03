//
//  main.cpp
//  3BP2
//
//  Created by Jake Valino on 20/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include "BTChars.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    BinaryTree tree;
    
    tree.add('a');
    tree.add('b');
    tree.add('d');
    
    tree.add('e');
    tree.add('f');
    
    cout << "Height is: " << tree.height() << endl;
        cout << "Verifying if char 'f' exist: " << endl;
    if(tree.find('f') == 1)
    {
        cout << "Char 'f' exist" << endl;
    }else
    {
        cout << "Char 'f' does not exist" << endl;
    }
    
    cout << "Pre-Order Traversal to print all char values: " << endl;
    
    tree.preOrder();
    
    cout << endl;
    
    
    
    return 0;
}
