#include "array.h"
/**
 * Function swaps array[firstIndex] and array[secondIndex]
 * WARNING: No check for indexes out of array bounds
 */
void swap(int* array, int firstIndex, int secondIndex)
{
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

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
 * Actually is an alias for reverseArraySlice(array, 0, length);
 */
void reverseArray(int* array, int length)
{
    reverseArraySlice(array, 0, length);
}

/**
 * reverseArraySlice reverses array slice on range [start; end)
 */
void reverseArraySlice(int* array, int start, int end)
{
    end--;
    while (start < (start + end + 1) / 2) {
        swap(array, start, end);
        start++;
        end--;
    }
}
