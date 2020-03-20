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
        case 4:
            storeCommandLineArgument(argv[3], randomNumberMinimum);
        case 3:
            storeCommandLineArgument(argv[2], maxThreads);
        case 2:
            storeCommandLineArgument(argv[1], arraySize);
        case 1:
            break;
        default:
            cout << "Wrong" << endl;
            return 1;
            break;
    }

    if(maxThreads == numeric_limits<unsigned long>::max())
    {
        maxThreads = determineMaxThreads(arraySize);
    } 

    srand(time(NULL));

    long* longArray = new long[arraySize]; // larger than ~1,000,000 will overflow the stack

    fillTestArrays(longArray, arraySize, randomNumberMinimum, randomNumberMaximum);
    
    auto start = high_resolution_clock::now();
    parallelMergeSort(longArray, 0, arraySize - 1, maxThreads);
    auto end = high_resolution_clock::now();

    duration<double> runTime = (end - start);
    cout << runTime.count() << 's' << endl;
    cout << runTime.count() / 60 << 'm' << endl;

    delete[] longArray;

    return 0;
}
