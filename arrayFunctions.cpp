#include "arrayFunctions.h"

void fillTestArrays(long* emptyArray, const long & size, const long minRandomNum, const long maxRandomNum)
{
    for(long i = 0; i < size; ++i)
    {
        emptyArray[i] = rand() % (maxRandomNum - minRandomNum) + minRandomNum;
    }
    return;
}

void printArray(long* array, const long & size)
{
    for(long i = 0; i < size; ++i)
    {
        printf("%ld ", array[i]);
    }
    cout << endl;
    return;
}

bool arrayIsSorted(long* array, const long & size)
{
    bool sorted = true;
    for(long i = 0; i < size - 1; ++i)
    {
        if(array[i] > array[i + 1])
        {
            sorted = false;
        }
    }
    cout << (sorted ? "Array is sorted" : "Array is not sorted") << endl;
    return sorted;
}