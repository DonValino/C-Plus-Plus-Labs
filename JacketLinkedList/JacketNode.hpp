//
//  JacketNode.hpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef JacketNode_hpp
#define JacketNode_hpp
#include <iostream>
#include <string>
#include "Jacket.hpp"
using namespace std;
#include <stdio.h>

class JacketNode
{
    friend class JacketList;
    friend istream& operator>>(istream& inputStream,JacketNode& jack);
private:
    Jacket j;
    JacketNode *next;
public:
    JacketNode(string make,double size);
    void display();
    
    const JacketNode operator+(const JacketNode & jack);
};

#endif /* JacketNode_hpp */
