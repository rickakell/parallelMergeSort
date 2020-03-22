/**
 * \author Richard A. Kell
 * \file arrayFunctions.h
 * \brief Prototypes for array helper functions
 */

#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/**
 * \brief takes an array of size \p size and fills it with random numbers between 
 * \p minRandomNum and \p maxRandomNum inclusive
 * \pre
 *    * none
 * \post
 *    * \p array is filled with random numbers
 * \param array an array of type long
 * \param size the size of \p array
 * \param minRandomNum the lowest random number to be generated when filling \p array
 * \param maxRandomNum the highest random number to be generated when filling \p array
 * \return none
 */
void fillArray(long* array, const unsigned long size, const long minRandomNum, const long maxRandomNum);

/**
 * \brief prints the contents of \p array to the console
 * \pre
 *    * none
 * \post
 *    * none
 * \param array an array of type long
 * \param size the size of \p array
 * \return none
 */
void printArray(long* array, const unsigned long size);

/**
 * \brief checks if \p array is an array of sorted longs
 * \pre
 *    * none
 * \post
 *    * none
 * \param array an array of type long
 * \param size the size of \p array
 * \return a boolean that is true if \p array is sorted; false if it is unsorted
 */
bool arrayIsSorted(long* array, const unsigned long size);

#endif