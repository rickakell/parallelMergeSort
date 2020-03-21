/*
 * Author: Richard A. Kell
 * File: mergeSort.h
 * Description: Function prototypes for merge sort algorithm
 */

#ifndef MERGESORT_H
#define MERGESORT_H

/**
 * \brief recursively sorts an array of longs by repeatedly breaking \p arrayOfNumbers
 * into halves until reaching the middle and recursively merging each sub array 
 * into a sorted array
 * \pre
 *    * \p arrayOfNumbers is filled with unsorted longs
 * \post
 *    * \p arrayOfNumbers is sorted
 * \param name description
 * \return name
 */
void sequentialMergeSort(long* arrayOfNumbers, const unsigned long leftIndex, const unsigned long rightIndex);

/**
 * \brief merges two halves of \p arrayOfNumbers in increasing order (sorted)
 * \pre
 *    * \p leftIndex, \p halfArrayIndex, and \p rightIndex are all within the bounds of \p arrayOfNumbers
 * \post
 *    * 
 * \param arrayOfNumbers an array of type long 
 * \param leftIndex starting index of the left sub array to be created
 * \param halfArrayIndex ending index of left sub array 1 less than starting index of right sub array
 * \param rightIndex ending index of right sub array to be created
 * \return none
 */
void sequentialMerge(long* arrayOfNumbers, const unsigned long leftIndex, 
                        const unsigned long halfArrayIndex, const unsigned long rightIndex);

#endif