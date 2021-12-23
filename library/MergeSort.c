#include "MergeSort.h"
#include "commonUtils/numericOperations.h"
#include <stdlib.h>
#include <string.h>

void merge(const int* source, int* destination, int start, int middle, int end)
{
    int leftCounter = start;
    int rightCounter = middle;
    for (int i = start; i < end; ++i) {
        if (leftCounter < middle && (rightCounter >= end || source[leftCounter] <= source[rightCounter]))
            destination[i] = source[leftCounter++];
        else
            destination[i] = source[rightCounter++];
    }
}

void sort(int* array, int size)
{
    int* arrayA = calloc(size, sizeof(int));
    memcpy(arrayA, array, size * sizeof(int));
    int* arrayB = calloc(size, sizeof(int));

    for (int arraySize = 1; arraySize < size; arraySize *= 2) {
        for (int i = 0; i < size; i += 2 * arraySize)
            merge(arrayA, arrayB, i, min(i + arraySize, size), min(i + 2 * arraySize, size));

        int* temp = arrayA;
        arrayA = arrayB;
        arrayB = temp;
    }

    memcpy(array, arrayA, size * sizeof(int));
    free(arrayA);
    free(arrayB);
}