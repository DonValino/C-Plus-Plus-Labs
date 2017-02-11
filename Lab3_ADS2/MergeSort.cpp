//
//  MergeSort.cpp
//  Lab3
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include "MergeSort.hpp"
#include <string>
#include <iostream>

// Default Constructor
MergeSort::MergeSort()
{
    
}

// print method
void MergeSort::print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

// mergeSort method
void MergeSort::mergeSort(int arrayToSort[], int startIndex, int lengthToSort)
{
    // Mid Index of the array. Will be used split array into to parts.
    int mid = 0;
    
    if(startIndex < lengthToSort)
    {
        mid = (startIndex + lengthToSort) / 2;
        
        // Left side of the array
        mergeSort(arrayToSort, startIndex, mid);
        
        // right side of the array
        mergeSort(arrayToSort, mid+1, lengthToSort);
        
        // Once array is broken into individual pieces, begin the sort and merge process.
        merge(arrayToSort, startIndex, lengthToSort);
    }
}

// merge method
void MergeSort::merge(int arraySortedInTwoHalves[], int startIndex,int length)
{
    // Size of the current array passed in
    int sizeOfArray = (length - startIndex) + 1;
    
    // Temporary Pointer that will hold copies of the newly sorted array.
    int *temp = new int[sizeOfArray];
    
    // First element of the left array
    int left = startIndex;
    // Last element of the left array
    int mid = (startIndex + length) / 2;
    
    // First element of the right array
    int right = mid + 1;
    
    // Index to be used for the temp[] array
    int i = 0;
    
    // Merging th left and right array in accending order to the temp[] array.
    while ((left <= mid) && (right <= length)) {
        
        if(arraySortedInTwoHalves[left] < arraySortedInTwoHalves[right])
        {
            temp[i] = arraySortedInTwoHalves[left];
            i++;
            left++;
        }else
        {
            temp[i] = arraySortedInTwoHalves[right];
            i++;
            right++;
        }
    }
    
    // If there are still elements inside the left array and merge is already completed, just add it to end of temp[] array
    while (left <= mid) {
        temp[i++] = arraySortedInTwoHalves[left++];
        i++;
        left++;
    }
    
    // If there are still elements inside the right array and merge is already completed, just add it to end of temp[] array
    while (right <= length) {
        temp[i++] = arraySortedInTwoHalves[right++];
        i++;
        right++;
    }
    
    // Copy temp array content to the original "array"
    for(int i = 0; i < sizeOfArray;i++)
    {
        arraySortedInTwoHalves[startIndex + i] = temp[i];
    }
    
    // Delete temp[] pointer
    delete []temp;
    
}


















