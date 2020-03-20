#ifndef ARRAYFUNCTIONS_H
#define ARRAYFUNCTIONS_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

void fillTestArrays(long* emptyArray, const unsigned long size, const long minRandomNum, const long maxRandomNum);

void printArray(long* emptyArray, const unsigned long size);

bool arrayIsSorted(long* array, const unsigned long size);

#endif