/*
 * Author: Richard A. Kell
 * File: main.h
 * Description: includes, usings, and template function definition needed
 * for main.cpp file
 */

#ifndef MAIN_H
#define MAIN_H

#include "parallelMergeSort.h"
#include "arrayFunctions.h"

#include <ctime>
#include <chrono>
#include <limits>
#include <sstream>

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::numeric_limits;
using std::istringstream;
using std::cerr;

template <typename T>
void storeCommandLineArgument(const char* & commandLineArgument, T & variableToStoreIn);

#include "main.hpp"

#endif