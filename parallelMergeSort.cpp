/*
 * Author: Richard A. Kell
 * File: parallelMergeSort.cpp
 * Description: Implementation file for functions relating to parallel merge sort
 */

#include "parallelMergeSort.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

void parallelMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, 
                            const unsigned long rightIndex, const unsigned long maxThreads)
{
    if(leftIndex < rightIndex)
    {
        unsigned long halfArrayIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if(maxThreads >= 2)
        {
            thread leftHalfThread(parallelMergeSort, arrayOfNumbers, leftIndex, 
                                    halfArrayIndex, (maxThreads - 2) / 2);
            thread rightHalfThread(parallelMergeSort, arrayOfNumbers, (halfArrayIndex + 1), 
                                    rightIndex, (maxThreads - 2) / 2);
            leftHalfThread.join();
            rightHalfThread.join();
            sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
        }
        else if(maxThreads == 1)
        {
            thread leftHalfThread(parallelMergeSort, arrayOfNumbers, leftIndex, 
                                    halfArrayIndex, 0);
            sequentialMergeSort(arrayOfNumbers, (halfArrayIndex + 1), rightIndex);
            leftHalfThread.join();
            sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
        }
        else
        {
            sequentialMergeSort(arrayOfNumbers, leftIndex, rightIndex);
        }
    }

    return;
}

unsigned long determineMaxThreads(const unsigned long arraySize)
{
    return arraySize / (pow(2, (log2(arraySize) / 2)) - 2);
}