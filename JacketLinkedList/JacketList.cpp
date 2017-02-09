//
//  JacketList.cpp
//  JacketLinkedList
//
//  Created by Jake Valino on 19/11/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include "JacketList.hpp"
#include <iostream>
#include <string>
using namespace std;

//Default Constructor
JacketList::JacketList()
:head(NULL)
{
    
}


//Copy Constructor
JacketList::JacketList(const JacketList& jack)
{
    if(this != &jack)
    {
        JacketNode *origPtr = jack.head,*copyPtr = NULL;
        while(origPtr != NULL)
        {
            if(head == NULL)
            {
                head = copyPtr = new JacketNode(origPtr->j.make,origPtr->j.size);
            }else{
                copyPtr->next = new JacketNode(origPtr->j.make,origPtr->j.size);
                copyPtr = copyPtr->next;
            }
            origPtr = origPtr->next;
        }
    }
}

//Clear Method
void JacketList::clear()
{
    JacketNode *tempPtr = head;
    while(tempPtr != NULL)
    {
        tempPtr = tempPtr->next;
        delete head;
        head = tempPtr;
    }
}

//Overloaded Assigment Operator
const JacketList JacketList::operator=(const JacketList& jack)
{
    if(this != &jack)
    {
        if(head != NULL)
        {
            clear();
        }
        JacketNode *origPtr = jack.head,*copyPtr = NULL;
        while(origPtr != NULL)
        {
            if(head == NULL)
            {
                head = copyPtr = new JacketNode(origPtr->j.make,origPtr->j.size);
            }else{
                copyPtr->next = new JacketNode(origPtr->j.make,origPtr->j.size);
                copyPtr = copyPtr->next;
            }
            origPtr = origPtr->next;
        }
    }
    return *this;
}



//Deconstructor
JacketList::~JacketList()
{
    JacketNode *tempPtr = head;
    while(head)
    {
        tempPtr = tempPtr->next;
        delete head;
        head = tempPtr;
    }
}


//Add a node to the front of the list
void JacketList::addFront(string make,double size)
{
    JacketNode *newNode = new JacketNode(make,size);
    newNode->next = head;
    head = newNode;
}

//Add a node to the end of the list
void JacketList::addEnd(string make,double size)
{
    JacketNode *newNode = new JacketNode(make,size);
    JacketNode *tempPtr = head;
    if(!head)
    {
        head = newNode;
    }else{
        for(tempPtr = head;tempPtr->next;tempPtr=tempPtr->next);
        tempPtr->next = newNode;
    }
}


//Delete the most recent node (i.e. the head)
void JacketList::deleteMostRecent()
{
     JacketNode *tempPtr = head;
    tempPtr = tempPtr->next;
    delete head;
    head = tempPtr;
}

//Delelte a node in a specific location in the list
void JacketList::deleteNodeAtSpecificLocation(string make)
{
    JacketNode *leadPtr = head,*trailPtr = NULL;
    if(head->j.make == make)
    {
        leadPtr = leadPtr->next;
        delete head;
        head = leadPtr;
    }else{
        while(leadPtr != NULL && leadPtr->j.make != make)
        {
            trailPtr = leadPtr;
            leadPtr = leadPtr->next;
        }
        if(leadPtr == NULL)
        {
            return;
        }else{
            trailPtr->next = leadPtr->next;
            delete leadPtr;
        }
    }
}

//Alter Node at a specific Location
void JacketList::alterNodeAtSpecificLocation(string make)
{
    JacketNode *leadPtr = head,*trailPtr = NULL;
    string makeIn = "";
    double sizeIn = 0;
    if(head->j.make == make)
    {
        cout << "Enter Make:\n";
        cin >> makeIn;
        cout << "Enter Size:\n";
        cin >> sizeIn;
        head->j.make = makeIn;
        head->j.size = sizeIn;
    }else{
        while(leadPtr != NULL && leadPtr->j.make != make)
        {
            trailPtr = leadPtr;
            leadPtr = leadPtr->next;
        }
        if(leadPtr == NULL)
        {
            cout << "Node note found";
        }else{
            cout << "Enter Make:\n";
            cin >> makeIn;
            cout << "Enter Size:\n";
            cin >> sizeIn;
            leadPtr->j.make = makeIn;
            leadPtr->j.size = sizeIn;
        }
    }
}

//Method to display the nodes in the list
void JacketList::display()
{
    JacketNode *tempPtr = head;
    while(tempPtr != NULL)
    {
        cout << "Make is: " << tempPtr->j.make << endl << "Size is: " << tempPtr->j.size << endl;
        tempPtr =tempPtr->next;
    }
}


//Find a node at specific location
Jacket JacketList::findNodeAtSpecificLocation(string make)
{
    JacketNode *leadPtr = head,*trailPtr = NULL,*node = NULL;
    if(head->j.make == make)
    {
        node = head;
    }else{
        while(leadPtr != NULL && leadPtr->j.make != make)
        {
            trailPtr = leadPtr;
            leadPtr = leadPtr->next;
        }
        if(leadPtr == NULL)
        {
            cout << "Node note found";
        }else{
            node = leadPtr;
        }
    }
    Jacket *jack = new Jacket(node->j.make,node->j.size);
    return *jack;
}



