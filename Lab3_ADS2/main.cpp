//
//  main.cpp
//  Lab3
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include "MergeSort.hpp"
#include <string>

int main(int argc, const char * argv[]) {
    MergeSort m;
    int arr[6] = {2, 3, 1, 4,6,5};
    int sizeOfArray = sizeof(arr) /sizeof(arr[0]);

    cout << "Before being sorted: " << endl;
    m.print(arr, sizeOfArray);
    m.mergeSort(arr, 0, sizeOfArray-1);
    
    cout << "After being sorted: " << endl;
    m.print(arr, sizeOfArray);
    
    return 0;
}
