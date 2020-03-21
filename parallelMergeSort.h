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

/**
 * \brief parallelization of the merge sort algorithm that uses multiple threads to sort concurrently
 * \pre
 *    * \p arrayOfNumbers is filled with unsorted longs 
 *    * \p leftIndex and \p rightIndex are within the bounds of \p arrayOfNumbers 
 * \post
 *    * \p arrayOfNumbers is sorted
 * \param arrayOfNumbers an array of type long
 * \param leftIndex the starting index of the 
 * \param rightIndex
 * \param maxThreads the maximum number of threads parallelMergeSort is allowed to spawn
 * \return none
 */
void parallelMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, 
                            const unsigned long rightIndex, const unsigned long maxThreads = 0);

/**
 * \brief attempts to determine an efficient number of threads based on 
 * the size of the array that will be sorted in parallelMergeSort()
 * \pre
 *    * none
 * \post
 *    * none
 * \param arraySize the size of the array to be sorted in parallelMergeSort()
 * \return an unsigned long - the maximum number of threads recommended to be used in parallelMergeSort()
 */
unsigned long determineMaxThreads(const unsigned long arraySize);

#endif
