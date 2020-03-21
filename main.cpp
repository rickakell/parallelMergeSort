/*
 * Author: Richard A. Kell
 * File: main.cpp
 * Date: Friday, March 20, 2020
 * Description: Driver file for parallel merge sort
 */

#include "main.h"

int main(int argc, char** argv)
{
    // Set default values
    unsigned long arraySize = 1000000;
    unsigned long maxThreads = numeric_limits<unsigned long>::max();
    long randomNumberMinimum = -100000;
    long randomNumberMaximum = 100000;

    // Overwrite each value that was passed in
    switch (argc)
    {
        case 5:
            storeCommandLineArgument(argv[4], randomNumberMaximum);
            // fall through
        case 4:
            storeCommandLineArgument(argv[3], randomNumberMinimum);
            // fall through
        case 3:
            storeCommandLineArgument(argv[2], maxThreads);
            // fall through
        case 2:
            storeCommandLineArgument(argv[1], arraySize);
            // fall through
        case 1:
            break;
        default:
            cout << "Usage:\n./sort [arraySize] [maxThreads] [randomNumberMaximum] [randomNumberMinimum]" << endl;
            return 1;
            break;
    }

    // use function to determine a reasonable number of threads based on the size of the array
    if(maxThreads == numeric_limits<unsigned long>::max())
    {
        maxThreads = determineMaxThreads(arraySize);
    } 

    srand(time(NULL));

    // create a dynamic array to avoid overflowing the stack
    long* longArray = new long[arraySize];

    fillArray(longArray, arraySize, randomNumberMinimum, randomNumberMaximum);
    
    // timing
    auto start = high_resolution_clock::now();
    parallelMergeSort(longArray, 0, arraySize - 1, maxThreads);
    auto end = high_resolution_clock::now();

    // output
    duration<double> runTime = (end - start);
    cout << runTime.count() << 's' << endl;
    cout << runTime.count() / 60 << 'm' << endl;

    delete[] longArray;

    return 0;
}
