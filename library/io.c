#include "io.h"
#include <stdio.h>

/**
 * inputSingleInt prints prompt and reads ONE integer from stdin.
 * @param prompt String describing what exactly need to be entered
 * @param var Variable to store input
 */
void inputSingleInt(char* prompt, int* var)
{
    printf("%s", prompt);
    scanf("%d", var);
}

/**
 * inputArrayOfInts prints prompt and reads MANY integers from stdin. Integers can be space or newline separated.
 * @param prompt String describing what exactly need to be entered
 * @param array Array to fill with integers
 * @param length Length of the given array (amount of integers to read)
 */
void inputArrayOfInts(char* prompt, int* array, int length)
{
    printf("%s\n", prompt);
    for (int i = 0; i < length; ++i) {
        scanf("%d", &array[i]);
    }
}

/**
 * printArrayOfInts prints description of array and then prints space separated array elements
 * @param text String describing data stored in array
 * @param array Array with data
 * @param length Length of the given array
 */
void printArrayOfInts(char* text, int* array, int length)
{
    printf("%s", text);
    for (int i = 0; i < length; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}