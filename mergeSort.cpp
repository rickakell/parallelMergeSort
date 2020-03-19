#include "mergeSort.h"

void sequentialMergeSort(long* arrayOfNumbers, const long & leftIndex, const long & rightIndex)
{
    if(leftIndex < rightIndex)
    {
        long halfArrayIndex = leftIndex + (rightIndex - leftIndex) / 2;

        sequentialMergeSort(arrayOfNumbers, leftIndex, halfArrayIndex);
        sequentialMergeSort(arrayOfNumbers, (halfArrayIndex + 1), rightIndex);

        sequentialMerge(arrayOfNumbers, leftIndex, halfArrayIndex, rightIndex);
    }
    return;
}

void sequentialMerge(long* arrayOfNumbers, const long & leftIndex, const long & halfArrayIndex, const long & rightIndex)
{
    long i, j, k;
    const long leftSubArraySize = halfArrayIndex - leftIndex + 1;
    const long rightSubArraySize = rightIndex - halfArrayIndex;

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