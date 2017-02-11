//
//  QuickSort.cpp
//  QuickSort
//
//  Created by Jake Valino on 11/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include "QuickSort.hpp"

// Constructor
QuickSort::QuickSort()
{
    
}
// print method
void QuickSort::print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}