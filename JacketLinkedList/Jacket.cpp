//
//  Jacket.cpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include "Jacket.hpp"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Jacket::Jacket(string makeIn,double sizeIn)
{
    make = makeIn;
    size = sizeIn;
}

//Default Constructor
Jacket::Jacket()
{
    make = "";
    size = 0;
}

//Getter Methods
string Jacket::getMake()
{
    return make;
}


double Jacket::getSize()
{
    return size;
}

istream& operator>>(istream& inputStream,Jacket& jack)
{
    inputStream >> jack.make;
    inputStream >> jack.size;
    return inputStream;
}

void Jacket::display()
{
    cout << "Make: " << make << "\nSize: " << size << endl;
}


