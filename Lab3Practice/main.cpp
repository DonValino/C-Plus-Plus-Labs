//
//  main.cpp
//  Lab3Practice
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include <string>
#include "Sort.hpp"

int main(int argc, const char * argv[]) {
    int arr[6] = {2, 3, 1, 4,6,5};
    int sizeOfArray = sizeof(arr) /sizeof(arr[0]);
    cout << sizeOfArray -1;
    int temp[sizeOfArray];
    Sort s;
    cout << "Before being sorted: " << endl;
    s.print(arr, sizeOfArray);
    s.mergeSort(arr, temp, 0, sizeOfArray -1);
    cout << "After being sorted: " << endl;
    s.print(arr, sizeOfArray);
    return 0;
}
