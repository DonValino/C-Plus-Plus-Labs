//
//  Sort.cpp
//  Lab3Practice
//
//  Created by Jake Valino on 08/02/2017.
//  Copyright © 2017 Jake Valino. All rights reserved.
//

#include "Sort.hpp"
#include <iostream>
#include <string>

// Default Constructor
Sort::Sort()
{
    
}

// print method
void Sort::print(int *a, int n)
{
    int i = 0;
    while(i < n){
        std::cout << a[i] << ",";
        i++;
    }
    std::cout << "\n";
}

// mergeSort Method - contains recursion. breaks the array into individual pieces and calls the merge method to sort and merge them back
void Sort::mergeSort(int *array,int *temp, int left, int right)
{
    int mid;
    // if last element of array is more than first element
    if(right > left)
    {
        mid = (right + left) / 2;
    
        // Sort left side of array
        mergeSort(array, temp, left, mid);
        // Sort right side of array
        mergeSort(array, temp, mid+1, right);
    
        // Once step one is done (i.e. breaking the array into individual pieces, sort and merge them)
        merge(array, temp, left, mid+1, right);
    }
}

// merge Method
void Sort::merge(int *array,int *temp,int left, int mid, int right)
{
    int left_end,num_elements,temp_pos;
    
    left_end = mid-1;
    temp_pos = left;
    num_elements = right - left + 1;
    
    // Check Which element is lower and copy to temp array
    // Increase position of temp array and left/mid index
    while((left <= left_end) && (mid <= right))
    {
        if(array[left] <= array[mid])
        {
            temp[temp_pos] = array[left];
            temp_pos = temp_pos + 1;
            left = left + 1;
        }else{
            temp[temp_pos] = array[mid];
            temp_pos = temp_pos + 1;
            mid = mid + 1;
        }
    }
    
    // If there are remaining content in left array that was not sorted, just add it to the end of temp pointer
    while(left <= left_end)
    {
        temp[temp_pos] = array[left]; // Merging content
        left = left + 1;
        temp_pos = temp_pos + 1;
    }
    
    // If there are remaining content in right array that was not sorted, just add it to the end of temp pointer
    while (mid <= right)
    {
        temp[temp_pos] = array[mid]; // Merging content
        mid = mid + 1;
        temp_pos = temp_pos + 1;
    }
    
    // Copy temp array content to the original "array"
    for(int i = 0; i <= num_elements;i++)
    {
        array[right] = temp[right];
        right = right-1;
    }
    
    
}













