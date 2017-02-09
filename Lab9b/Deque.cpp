//
//  Deque.cpp
//  Lab9b
//
//  Created by Jake Valino on 10/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include "Deque.hpp"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Deque::Deque()
{
    v = new int[10];
    sizeOfVector = 10;
    for(int i =0; i < sizeOfVector;i++)
    {
        v[i] = 0;
    }
    if(v == NULL)
    {
        cout << "Error: Insufficient Memory.\n";
    }
    head = 1;
    tail = 1;
}


//Check if the vector array is empty
bool Deque::isEmpty()
{
    bool isItEmpty = true;
    for(int i =0; i < sizeOfVector;i++)
    {
        if (v[i] > 0) {
            isItEmpty = false;
        }
    }
    return isItEmpty;
    
}

//Check if the vector array is full
bool Deque::isFull()
{
    if (head - tail == 1) {
        return true;
    }else{
        return false;
    }
}


//Insert to the back of the queue
void Deque::insertBack(int in)
{
    DequeFull d;
    DequeEmpty emp;
    bool inserted = false;
    try {
    if (isEmpty()) {
        v[1] = in;
        tail = 1;
        inserted = true;
        throw emp;
    }else if(isFull())
    {
        int oldSize = sizeOfVector;
        int newSize = sizeOfVector * 2;
        sizeOfVector = newSize;
        int *pNewInt = new int[newSize];
        if(pNewInt == NULL)
        {
            exit(0);
        }
        for(int i =0;i < newSize;i++)
        {
            pNewInt[i] = 0;
        }
        
        for(int i =0;i < newSize;i++)
        {
            
           if(i <= (oldSize-1))
           {
               pNewInt[(oldSize-1) + i] = v[i];
               tail = (oldSize-2) + i;
           }
        }
        delete v;
        v = NULL;
        v = pNewInt;
        pNewInt = NULL;
        head = oldSize - 1;
        v[tail + 1] = in;
        tail = tail + 1;
        inserted = true;
        throw d;
    }else
    {
        if (tail == (sizeOfVector-1)) {
            tail = 0;
            v[0] = in;
            inserted = true;
        }else{
            v[tail + 1] = in;
            tail = tail + 1;
            inserted = true;
        }
    }
    } catch (DequeEmpty d) {
        cout << d.what();
    }catch (DequeFull d) {
        cout << d.what();
    }
}

//Insert to the front of the queue
void Deque::insertFront(int in)
{
    DequeFull d;
    DequeEmpty emp;
    bool inserted = false;
    try {
    if (isEmpty()) {
        v[1] = in;
        tail = 1;
        inserted = true;
        throw emp;
    }else if(isFull())
    {
        int oldSize = sizeOfVector;
        int newSize = sizeOfVector * 2;
        sizeOfVector = newSize;
        int *pNewInt = new int[newSize];
        if(pNewInt == NULL)
        {
            exit(0);
        }
        for(int i =0;i < newSize;i++)
        {
            pNewInt[i] = 0;
        }
        
        for(int i =0;i < newSize;i++)
        {
            
            if(i <= (oldSize-1))
            {
                pNewInt[(oldSize-1) + i] = v[i];
                tail = (oldSize-2) + i;
            }
        }
        delete v;
        v = NULL;
        v = pNewInt;
        pNewInt = NULL;
        head = oldSize - 1;
        v[head - 1] = in;
        head = head - 1;
        inserted = true;
        throw d;
    }else{
        if (head == 0) {
            head = (sizeOfVector-1);
            v[head] = in;
            inserted = true;
        }else{
            v[head - 1] = in;
            head = head - 1;
            inserted = true;
        }
    }
    } catch (DequeEmpty d) {
        cout << d.what();
    }catch (DequeFull d) {
        cout << d.what();
    }
}

//Remove from the back of the circular array;
int Deque::removeBack(int & out)
{
    DequeEmpty d;
    int isRemoved = 0;
    try {
    if (isEmpty()) {
        out = 0;
        /*cout << "Array is empty"*/
        throw d;
    }else{
        for(int i =0;i < sizeOfVector;i++)
        {
            if (v[i] == out && (v[i] == v[tail])) {
                isRemoved = v[i];
                v[i] = 0;
                if (tail == 0) {
                    tail = sizeOfVector -1;
                }else{
                tail = tail -1;
                }
                /*isRemoved = true;*/
            }
        }
        /*if (isRemoved == false) {
            cout << "Error: Index provided is either out of bound or is not the value of the tail";
        }*/
    }
    } catch (DequeEmpty d) {
        cout << d.what();
    }
    
    return isRemoved;
}

//Remove from the front of the circular array;
int Deque::removeFront(int & out)
{
    DequeEmpty d;
    int isRemoved = 0;
    try {
    if (isEmpty()) {
        out = 0;
        /*cout << "Array is empty"*/
        throw d;
    }else{
        for(int i =0;i < sizeOfVector;i++)
        {
            if (v[i] == out && (v[i] == v[head])) {
                isRemoved = v[i];
                v[i] = 0;
                if (head == sizeOfVector-1) {
                    head = 0;
                }else{
                    head = head + 1;
                }
                /*isRemoved = true;*/
            }
        }
        /*if (isRemoved == false) {
            cout << "Error: Index provided is either out of bound or is not the value of the head";
        }*/
    }
    } catch (DequeEmpty d) {
        cout << d.what();
    }
    
    return isRemoved;
}

//Get the head
int Deque::getHead()
{
    return head;
}


//Get the arrar v
int * Deque::getv()
{
    return v;
}
//Display the content of the queue
void Deque::display()
{
    for(int i =0; i < sizeOfVector;i++)
    {
        cout << "Value at index: " << (i) << " is: " << v[i] << endl;
    }
}







