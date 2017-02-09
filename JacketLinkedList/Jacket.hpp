//
//  Jacket.hpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef Jacket_hpp
#define Jacket_hpp
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>
class Jacket
{
    friend class JacketNode;
    friend class JacketList;
    friend istream& operator>>(istream& inputStream,Jacket& jack);
private:
    string make;
    double size;
public:
    Jacket(string make,double size);
    Jacket();
    string getMake();
    double getSize();
    
    void display();
    
};

#endif /* Jacket_hpp */
