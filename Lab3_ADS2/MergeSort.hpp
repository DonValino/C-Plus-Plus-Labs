//
//  MergeSort.hpp
//  Lab3
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp
#include <string>
#include <iostream>
using namespace std;
#include <stdio.h>
class MergeSort
{
public:
    MergeSort();
    void mergeSort(int arrayToSort[], int startIndex, int lengthToSort);
    void merge(int arraySortedInTwoHalves[], int startIndex,int lenght);
    void print(int *a, int n);
};
#endif /* MergeSort_hpp */
