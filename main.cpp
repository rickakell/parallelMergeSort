#include "parallelMergeSort.h"
#include "arrayFunctions.h"

#include <ctime>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration;

int main()
{
    srand(time(NULL));

    const unsigned long LONGMAXSIZE = 350000000;

    const long RANDOMNUMBERMINIMUM = -10000;
    const long RANDOMNUMBERMAXIMUM = 10000;

    // used to convert to seconds
    const unsigned long CONVERSIONFACTOR = 1000000000;

    //unsigned long numberOfHardwareThreadsAvailable = thread::hardware_concurrency();

    unsigned long maxThreads = determineMaxThreads(LONGMAXSIZE);

    long* longArray = new long[LONGMAXSIZE]; // larger than ~1,000,000 will overflow the stack

    fillTestArrays(longArray, LONGMAXSIZE, RANDOMNUMBERMINIMUM, RANDOMNUMBERMAXIMUM);
    
    auto start = high_resolution_clock::now();
    parallelMergeSort(longArray, 0, LONGMAXSIZE - 1, maxThreads);
    auto end = high_resolution_clock::now();

    auto runTime = (end - start) / CONVERSIONFACTOR;
    cout << runTime.count() << 's' << endl;
    cout << runTime.count() / 60 << 'm' << endl;

    delete[] longArray;

    return 0;
}
