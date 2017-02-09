//
//  Deque.hpp
//  Lab9b
//
//  Created by Jake Valino on 10/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef Deque_hpp
#define Deque_hpp
#include <iostream>
#include <string>
#include "DequeFull.hpp"
#include "DequeEmpty.hpp"

using namespace std;
#include <stdio.h>
class Deque
{
private:
    int num;
    int head;
    int tail;
    int *v;
    int sizeOfVector;
    int index;
    int indexFront;
public:
    Deque();
    bool isEmpty();
    bool isFull();
    void insertFront(int in);
    int removeFront(int & out);
    void insertBack(int in);
    int removeBack(int & out);
    
    int getHead();
    int *getv();
    
    void display();
    
};

#endif /* Deque_hpp */
