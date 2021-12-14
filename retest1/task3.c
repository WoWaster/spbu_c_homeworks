#include "../library/array.h"
#include "../library/io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void evenInsertionSort(int* array, int arraySize)
{
    for (int i = 2; i < arraySize; i += 2)
        for (int j = i; j > 0 && array[j - 2] > array[j]; j -= 2)
            swap(array, j - 2, j);
}

int main()
{
    bool isInteractive = false;
    printf("Enter 0 for automatic mode or 1 for interactive mode: ");
    scanf("%d", &isInteractive);

    int length = 0;
    int* array = NULL;
    if (isInteractive) {
        printf("Enter length: ");
        scanf("%d", &length);
        array = calloc(length, sizeof(int));
        inputArrayOfInts("Input array: ", array, length);
    } else {
        srand(time(NULL));
        int length = rand() % 256;
        array = calloc(length, sizeof(int));
        for (int i = 0; i < length; ++i)
            array[i] = rand() % 31 + 11;
    }

    evenInsertionSort(array, length);

    printArrayOfInts("Sorted array: ", array, length);

    free(array);
    return 0;
}