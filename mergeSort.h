#ifndef MERGESORT_H
#define MERGESORT_H

void sequentialMergeSort(long* arrayOfNumbers, const long & leftIndex, const long & rightIndex);

void sequentialMerge(long* arrayOfNumbers, const long & leftIndex, const long & halfArrayIndex, const long & rightIndex);

#endif