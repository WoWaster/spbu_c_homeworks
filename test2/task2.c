#include "../library/io.h"
#include <stdlib.h>

/**
 * @param output must be allocated with size of length1+length2
 */
void mergeArrays(const int* array1, int length1, const int* array2, int length2, int* output, int outputLength)
{
    int step1 = 0;
    int step2 = 0;
    for (int i = 0; i < outputLength; ++i) {
        if (step1 < length1 && (step2 >= length2 || array1[step1] >= array2[step2]))
            output[i] = array1[step1++];
        else
            output[i] = array2[step2++];
    }
}

int main()
{
    int length1 = 0;
    inputSingleInt("Enter amount of 1_st person's notebooks: ", &length1);
    int* array1 = calloc(length1, sizeof(int));
    inputArrayOfInts("Enter values: ", array1, length1);

    int length2 = 0;
    inputSingleInt("Enter amount of 2_nd person's notebooks: ", &length2);
    int* array2 = calloc(length1, sizeof(int));
    inputArrayOfInts("Enter values: ", array2, length2);

    int outputLength = length1 + length2;
    int* output = calloc(outputLength, sizeof(int));
    mergeArrays(array1, length1, array2, length2, output, outputLength);
    printArrayOfInts("Result: ", output, outputLength);

    free(array1);
    free(array2);
    free(output);
    return 0;
}