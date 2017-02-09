//
//  PFArrayD.hpp
//  Lab8B
//
//  Created by Jake Valino on 07/12/2015.
//  Copyright © 2015 Jake Valino. All rights reserved.
//

#ifndef PFArrayD_hpp
#define PFArrayD_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
class PFArrayD
{
private:
    double *a; //For an array of doubles
    int capacity; //For the size of the array
    int used; //For the number of array positions currently in use
    
public:
    PFArrayD();
    //Initializes with a capacity of 50.
    PFArrayD(int capacityValue);
    void addElement(double element);
    //Precondition: The array is not full.
    //Postcondition: The element has been added.
    bool full() const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray(){ used = 0; }
    //Empties the array.
    double& operator[](int index);
    //Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator =(const PFArrayD& rightSide);
    ~PFArrayD();
    void showPFArrayD();
};
#endif /* PFArrayD_hpp */
