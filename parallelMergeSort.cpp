/**
 * \author Richard A. Kell
 * \file parallelMergeSort.cpp
 * \brief Implementation file for functions relating to parallel merge sort
 */

#include "parallelMergeSort.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

void parallelMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, 
                            const unsigned long rightIndex, const unsigned long maxThreads)
{
    // check if recursed to base case
    if(leftIndex < rightIndex)
    {
        unsigned long halfArrayIndex = leftIndex + (rightIndex - leftIndex) / 2;
        // generate threads based on maximum allowed
        if(maxThreads >= 2)
        {
            // call parallelMergSort() in a seperate thread for each sub array to process concurrently
            thread leftHalfThread(parallelMergeSort, arrayOfNumbers, leftIndex, 
                                    halfArrayIndex, (maxThreads - 2) / 2);
            thread rightHalfThread(parallelMergeSort, arrayOfNumbers, (halfArrayIndex + 1), 
                                    rightIndex, (maxThreads - 2) / 2);
            // wait for the threads to complete before merging the sub arrays
            leftHalfThread.join();
            rightHalfThread.join();
            // merge the halves back together
            sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
        }
        else if(maxThreads == 1)
        {
            // only 1 thread is allowed so spawn a thread for the left sub array
            thread leftHalfThread(parallelMergeSort, arrayOfNumbers, leftIndex, 
                                    halfArrayIndex, 0);
            sequentialMergeSort(arrayOfNumbers, (halfArrayIndex + 1), rightIndex);
            // wait for the thread to complete
            leftHalfThread.join();
            // merge the halves back together
            sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
        }
        else
        {
            // no more threads allowed, call sequentialMergeSort()
            sequentialMergeSort(arrayOfNumbers, leftIndex, rightIndex);
        }
    }

    return;
}

unsigned long determineMaxThreads(const unsigned long arraySize)
{
    // log2 of the array size is the height of the binary tree representing parallelMergeSort() recursion
    // 2 to the power of half the height of the tree - 2 will give the number of nodes in the upper half
    // of the tree, this is reasonable number of threads to generate with parallelMergeSort()
    return arraySize / (pow(2, (log2(arraySize) / 2)) - 2);
}