//
//  JacketNode.cpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include "JacketNode.hpp"
#include <iostream>
#include <string>
using namespace std;


//Constructor
JacketNode::JacketNode(string make,double size)
{
    j.make = make;
    j.size = size;
    next = NULL;
}


//Method to display the nodes in the list
void JacketNode::display()
{
    cout << "Make is: " << j.make << endl << "Size is: " << j.size << endl;
}

//Overloaded istream operator>>
/*istream& operator>>(istream& inputStream,JacketNode& jack)
{
    inputStream >> jack.j.make;
    inputStream >> jack.j.getSize();
    
    return inputStream;
    
}*/

const JacketNode JacketNode::operator+(const JacketNode & jack)
{
    j.size = j.size + jack.j.size;
    return *this;
}


