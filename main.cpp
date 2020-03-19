#include "parallelSort.h"
#include "arrayFunctions.h"

#include <ctime>

int main()
{
    srand(time(NULL));

    const long SHORTMAXSIZE = 100;
    const long LONGMAXSIZE = 10000;

    const long RANDOMNUMBERMINIMUM = 0;
    const long RANDOMNUMBERMAXIMUM = 10000;

    const long MAXTHREADS = 10;
    const long SINGLEPROCESSOR = 1;

    long shortArray[SHORTMAXSIZE];
    long longArray[LONGMAXSIZE];

    fillTestArrays(shortArray, SHORTMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    fillTestArrays(longArray, LONGMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);

    arrayIsSorted(longArray, LONGMAXSIZE);
    sequentialMergeSort(longArray, 0, LONGMAXSIZE - 1);
    arrayIsSorted(longArray, LONGMAXSIZE);

    //printArray(shortArray, SHORTMAXSIZE);
    //arrayIsSorted(shortArray, SHORTMAXSIZE);
    //printArray(longArray, LONGMAXSIZE);

    //sequentialMergeSort(shortArray, 0, SHORTMAXSIZE - 1);

    //printArray(shortArray, SHORTMAXSIZE);
    //arrayIsSorted(shortArray, SHORTMAXSIZE);

    return 0;
}
