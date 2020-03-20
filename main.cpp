#include "parallelMergeSort.h"
#include "arrayFunctions.h"

#include <ctime>

int main()
{
    srand(time(NULL));

    //const unsigned long SHORTMAXSIZE = 100;
    const unsigned long LONGMAXSIZE = 1000000000;

    const long RANDOMNUMBERMINIMUM = -10000;
    const long RANDOMNUMBERMAXIMUM = 10000;

    //unsigned long numberOfHardwareThreadsAvailable = thread::hardware_concurrency();

    unsigned long maxThreads = determineMaxThreads(LONGMAXSIZE);

    //long* shortArray = new long[SHORTMAXSIZE];
    long* longArray = new long[LONGMAXSIZE]; // larger than ~1,000,000 will overflow the stack

    //fillTestArrays(shortArray, SHORTMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    fillTestArrays(longArray, LONGMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    
    // .26
    // arrayIsSorted(shortArray, SHORTMAXSIZE);
    // parallelMergeSort(shortArray, 0, SHORTMAXSIZE - 1, 14);
    // arrayIsSorted(shortArray, SHORTMAXSIZE);

    arrayIsSorted(longArray, LONGMAXSIZE);
    parallelMergeSort(longArray, 0, LONGMAXSIZE - 1, maxThreads);
    arrayIsSorted(longArray, LONGMAXSIZE);

    // delete[] shortArray;
    delete[] longArray;

    return 0;
}
