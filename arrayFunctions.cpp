#include "arrayFunctions.h"

void fillTestArrays(long* emptyArray, const unsigned long size, const long minRandomNum, const long maxRandomNum)
{
    for(unsigned long i = 0; i < size; ++i)
    {
        emptyArray[i] = rand() % (maxRandomNum - minRandomNum) + minRandomNum;
    }
    return;
}

void printArray(long* array, const unsigned long size)
{
    for(unsigned long i = 0; i < size; ++i)
    {
        printf("%ld ", array[i]);
    }
    cout << endl;
    return;
}

bool arrayIsSorted(long* array, const unsigned long size)
{
    bool sorted = true;
    for(unsigned long i = 0; i < size - 1; ++i)
    {
        if(array[i] > array[i + 1])
        {
            sorted = false;
        }
    }
    cout << (sorted ? "Array is sorted" : "Array is not sorted") << endl;
    return sorted;
}