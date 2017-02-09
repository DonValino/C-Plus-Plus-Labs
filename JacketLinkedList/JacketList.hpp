//
//  JacketList.hpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef JacketList_hpp
#define JacketList_hpp
#include "JacketNode.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include <stdio.h>

class JacketList
{
private:
    JacketNode *head;
public:
    JacketList();
    JacketList(const JacketList& jack);
    ~JacketList();
    void addFront(string make,double size);
    void addEnd(string make,double size);
    void deleteMostRecent();
    void deleteNodeAtSpecificLocation(string make);
    Jacket findNodeAtSpecificLocation(string make);
    void alterNodeAtSpecificLocation(string make);
    void display();
    void clear();
    
    const JacketList operator=(const JacketList& jack);
};
#endif /* JacketList_hpp */
