#include "parallelMergeSort.h"
#include "arrayFunctions.h"

#include <ctime>

int main()
{
    srand(time(NULL));

    const unsigned long SHORTMAXSIZE = 100;
    const unsigned long LONGMAXSIZE = 10000;

    const long RANDOMNUMBERMINIMUM = 0;
    const long RANDOMNUMBERMAXIMUM = 10000;

    //unsigned long numberOfHardwareThreadsAvailable = thread::hardware_concurrency();

    //unsigned long maxThreads = determineMaxThreads();

    long shortArray[SHORTMAXSIZE];
    //long longArray[LONGMAXSIZE];

    fillTestArrays(shortArray, SHORTMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    //fillTestArrays(longArray, LONGMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);

    arrayIsSorted(shortArray, SHORTMAXSIZE);
    cout << "Before Parallel Sort" << endl;
    printArray(shortArray, SHORTMAXSIZE);
    parallelMergeSort(shortArray, 0, SHORTMAXSIZE - 1);
    cout << "After Parallel Sort" << endl;
    printArray(shortArray, SHORTMAXSIZE);
    arrayIsSorted(shortArray, SHORTMAXSIZE);

    /*
    arrayIsSorted(longArray, LONGMAXSIZE);
    parallelMergeSort(longArray, 0, LONGMAXSIZE - 1);
    arrayIsSorted(longArray, LONGMAXSIZE);
    */

    return 0;
}
