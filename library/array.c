#include "array.h"

/**
 * fillArray fills array with given value
 */
void fillArray(int value, int* array, int length)
{
    for (int i = 0; i < length; ++i) {
        array[i] = value;
    }
}

/**
 * reverseArray reverses full array
 */
void reverseArray(int* array, int length)
{
    for (int i = 0; i < (length / 2); ++i) {
        int temp = array[i];
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }
}

/**
 * reverseArraySlice reverses array slice on range [start; end)
 */
void reverseArraySlice(int* array, int start, int end)
{
    end--;
    for (; start < end;
         start++, end--) {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
    }
}
