/*
 * Author: Richard A. Kell
 * File: mergeSort.cpp
 * Description: Implementation of merge sort algorithm
 */

#include "mergeSort.h"

void sequentialMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, const unsigned long rightIndex)
{
    // checks if recursed to base case
    if(leftIndex < rightIndex)
    {
        // index for the middle of the array
        unsigned long halfArrayIndex = leftIndex + (rightIndex - leftIndex) / 2;

        // recursive calls for left and right sub arrays 
        sequentialMergeSort(arrayOfNumbers, leftIndex, halfArrayIndex);
        sequentialMergeSort(arrayOfNumbers, (halfArrayIndex + 1), rightIndex);

        // merge sub arrays back together in increasing (sorted) order
        sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
    }
    return;
}

void sequentialMerge(long* arrayOfNumbers, const unsigned long leftIndex, 
                        const unsigned long halfArrayIndex, const unsigned long rightIndex)
{
    // initialize counting variables
    unsigned long i, j, k;
    const unsigned long leftSubArraySize = halfArrayIndex - leftIndex + 1;
    const unsigned long rightSubArraySize = rightIndex - halfArrayIndex;

    // create sub arrays for the left and right half of the current array
    long* leftSubArray = new long[leftSubArraySize];
    long* rightSubArray = new long[rightSubArraySize];

    for(i = 0; i < leftSubArraySize; ++i)
    {
        leftSubArray[i] = arrayOfNumbers[leftIndex + i];
    }

    for(i = 0; i < rightSubArraySize; ++i)
    {
        rightSubArray[i] = arrayOfNumbers[halfArrayIndex + 1 + i];
    }

    i = j = 0;
    k = leftIndex;
    // merge sub arrays
    while(i < leftSubArraySize && j < rightSubArraySize)
    {
        if(leftSubArray[i] <= rightSubArray[j])
        {
            arrayOfNumbers[k] = leftSubArray[i++];
        }
        else
        {
            arrayOfNumbers[k] = rightSubArray[j++];
        }
        ++k;
    }

    // copy any left over values
    while(i < leftSubArraySize)
    {
        arrayOfNumbers[k++] = leftSubArray[i++];
    }

    while(j < rightSubArraySize)
    {
        arrayOfNumbers[k++] = rightSubArray[j++];
    }

    delete[] leftSubArray;
    delete[] rightSubArray;

    return;
} 