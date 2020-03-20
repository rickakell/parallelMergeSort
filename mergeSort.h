#ifndef MERGESORT_H
#define MERGESORT_H

void sequentialMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, const unsigned long rightIndex);

void sequentialMerge(long* arrayOfNumbers, const unsigned long leftIndex, 
                        const unsigned long halfArrayIndex, const unsigned long rightIndex);

#endif