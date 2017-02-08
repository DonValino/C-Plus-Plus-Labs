//
//  Sort.hpp
//  Lab3Practice
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp
#include <iostream>
#include <string>

using namespace std;
#include <stdio.h>
class Sort
{
public:
    Sort();
    void mergeSort(int *array,int *temp, int left, int right);
    void merge(int *array,int *temp,int left, int mid, int right);
    void print(int *a, int n);
};

#endif /* Sort_hpp */
