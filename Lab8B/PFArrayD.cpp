//
//  PFArrayD.cpp
//  Lab8B
//
//  Created by Jake Valino on 07/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#include "PFArrayD.hpp"
#include <string>
#include <iostream>

using namespace std;
//Default Constructor
PFArrayD::PFArrayD() :capacity(50), used(0)
{
    a = new double[capacity];
}

//Constructor
PFArrayD::PFArrayD(int size) : capacity(size), used(0)
{
    a = new double[capacity];
}
//Add a new Element to array
void PFArrayD::addElement(double element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArrayD.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

//Find an element in array
double& PFArrayD::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArrayD.\n";
        exit(0);
    }
    return a[index];
}

//Overloaded assignment operator=
PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
    if (capacity != rightSide.capacity)
    {
        delete[] a;
        a = new double[rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];
    return *this;
}

//Destructor
PFArrayD::~PFArrayD()
{
    delete [] a;
}

//Sec
void PFArrayD::showPFArrayD()
{
    PFArrayD p;
    for(int i = 0; i < used;i++)
    {
        p.a[i] = a[i];
    }
    cout << "The first value is: "
    << p.a[0] << endl;
}

//Destructor is called twice in this method but we're passing in/doing a shallow copy of the *a object that points to an array. The value of pointer is copied but are both pointing to the same address location.The first time it is called, it successfully deletes the array the pointer points to. The second time it's called. The pointer is pointing to a dangling value and it causes error. (You need a deep copy / pass in a reference)
