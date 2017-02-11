//
//  main.cpp
//  QuickSort
//
//  Created by Jake Valino on 11/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include "QuickSort.hpp"
#include <string>
template <class array>
void quickSort(array *theArray, int first, int last);
template <class arrayToSort>
int quickSortDivide(arrayToSort *theArray, int first, int last);

// QuickSort Method
template <class array>
void quickSort(array *theArray, int first, int last)
{
    int i = 0;
    
    if(first < last)
    {
        i = quickSortDivide(theArray, first, last);
        quickSort(theArray, first, i-1);
        quickSort(theArray, i+1, last);
    }
}

template <class arrayToSort>
int quickSortDivide(arrayToSort *theArray, int first, int last)
{
    int index = first;
    int pivot = theArray[first];
    
    for(int i = first+1;i <= last; i++)
    {
        if(theArray[i] <= pivot)
        {
            index++;
            std::swap(theArray[i], theArray[index]);
        }
    }
    std::swap(theArray[index], theArray[first]);
    return index;
}

int main(int argc, const char * argv[]) {
    QuickSort q;
    int array[6] = {2, 3, 1, 4,6,5};
    int sz = sizeof(array)/sizeof(array[0]);
    q.print(array, sz);
    quickSort(array, 0, sz-1);
    q.print(array, sz);
    
    return 0;
}
