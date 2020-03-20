/*
 * Author: Richard A. Kell
 * File: parallelMergeSort.h
 * Description: Function prototypes for parallel merge sort
 */

#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include "mergeSort.h"
#include <thread>
#include <cmath>

using std::thread;

void parallelMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, 
                            const unsigned long rightIndex, const unsigned long maxThreads = 0);

unsigned long determineMaxThreads(const unsigned long arraySize);

#endif
