#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

void fillTestArrays(long* emptyArray, const long & size, const long minRandomNum, const long maxRandomNum);

void printArray(long* emptyArray, const long & size);

bool arrayIsSorted(long* array, const long & size);

#endif