//
//  main.cpp
//  Lab2
//
//  Created by Jake Valino on 30/01/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include <iostream>
#include <string>
#include "TemplateLab.hpp"
using namespace std;

// Swap Pass By Value
template <class jake>
void swap(jake a, jake b){
    jake temp;
    temp = a;
    a = b;
    b = temp;
    
    cout << "a: " << a << "\nb: " << b << endl << endl;
}

// Swap Pass By Reference
template <class jake>
void swapR(jake& a, jake& b){
    jake temp;
    temp = a;
    a = b;
    b = temp;
    
    cout << "a: " << a << "\nb: " << b << endl;
}

// Swap Pass By Address
template <class jake>
void swapA(jake *a, jake *b){
    jake temp;
    temp = a;
    a = b;
    b = temp;
    
    cout << "a: " << a << "\nb: " << b << endl;
}



// Multiples Template Method
template <class WhatKind>
void multiples(WhatKind& sum, WhatKind x,int n){
    sum = 1;

    for(int i = 0 ; i <= n; i = i+1)
    {
        sum +=(i*x);
    }
}

// init Template Method
template <class T1, class T2>
T1 init (T1 num1, T1 num2, T2& start){
    T2 s = 1;
    start = s;
    
    T1 sum = num1 + num2;
    return sum;
}

// QuickSort Algorithm
template<typename T>
T* quicksort(T* array, T left, T right)
{
    int index = partiton(array, left, right);
    
    if(left < index - 1)
    {
        quicksort(array,left,index -1);
    }
    
    if(index < right)
    {
        quicksort(array,index,right);
    }
    
    return array;
    
}

void print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

int partition(int *arr, const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = arr[mid];
    // move the mid point value to the front.
    std::swap(arr[mid],arr[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && arr[i] <= pivot) {
            i++;
        }
        
        while(i <= j && arr[j] > pivot) {
            j--;
        }
        
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i - 1],arr[left]);
    return i - 1;
}

// QuickSort Algorithm
template<typename T>
void quicksort(T *arr, const int left, const int right, const int sz){
    
    if (left >= right) {
        return;
    }
    
    
    int part = partition(arr, left, right);
    std::cout << "QSC:" << left << "," << right << " part=" << part << "\n";
    print (arr, sz);

    quicksort(arr, left, part - 1, sz);
    quicksort(arr, part + 1, right, sz);
}

int main(int argc, const char * argv[]) {
    
                                        // Q1
    // Pass By Value integer
    cout << "Pass By Value integer" << endl;
    swap(2,1);
    
    // Pass By Value float
    cout << "Pass By Value float" << endl;
    swap(0.2,0.1);

    // Pass By Reference
    int a = 2;
    int b = 1;
    cout << "Pass By Reference" << endl;
    swapR(a,b);
    
    // Pass By Address
    cout << "Pass By Address" << endl;
    int *x;
    int *y;
    x = &b;
    y = &a;
    swapR(x,y);
    
    cout << endl << endl << endl << endl;
    
    
                                    // Q2
    // Multiples Template Method
    cout << "Multiples Template Method" << endl;
    int sum;
    multiples(sum, 10, 2);
    cout << "SUM: " << sum << endl << endl;
    
    
                                    // Q3
    // Multiples Template Method
    cout << "init Template Method" << endl;
    int start;
    cout << init(1.1,2.2,start) << endl;
    cout << "Start: " << start << endl << endl << endl << endl << endl << endl;
    
    // QuickSort Algorithm
    int arr[6] = {2, 3, 1, 4,6,5};
    int sz = sizeof(arr)/sizeof(arr[0]);
    print(arr, sz);
    quicksort(arr, 0, sz - 1, sz);
    print(arr, sz);
    
    return 0;
}
