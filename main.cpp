#include "parallelMergeSort.h"
#include "arrayFunctions.h"

#include <ctime>

int main()
{
    srand(time(NULL));

    const unsigned long SHORTMAXSIZE = 100;
    const unsigned long LONGMAXSIZE = 1000000;

    const long RANDOMNUMBERMINIMUM = -10000;
    const long RANDOMNUMBERMAXIMUM = 10000;

    //unsigned long numberOfHardwareThreadsAvailable = thread::hardware_concurrency();

    //unsigned long maxThreads = determineMaxThreads();

    long shortArray[SHORTMAXSIZE];
    long longArray[LONGMAXSIZE];

    fillTestArrays(shortArray, SHORTMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    fillTestArrays(longArray, LONGMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);

    arrayIsSorted(shortArray, SHORTMAXSIZE);
    parallelMergeSort(shortArray, 0, SHORTMAXSIZE - 1, 14);
    arrayIsSorted(shortArray, SHORTMAXSIZE);

    arrayIsSorted(longArray, LONGMAXSIZE);
    parallelMergeSort(longArray, 0, LONGMAXSIZE - 1);
    arrayIsSorted(longArray, LONGMAXSIZE);

    return 0;
}
