#include "../library/MergeSort.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This app will sort given array of ints using merge sort.\n");
    int size = 0;
    inputSingleInt("Please enter length of array: ", &size);
    int* array = calloc(size, sizeof(int));
    inputArrayOfInts("Now enter contents of array: ", array, size);
    sort(array, size);
    printArrayOfInts("Sorted array: ", array, size);
    return 0;
}