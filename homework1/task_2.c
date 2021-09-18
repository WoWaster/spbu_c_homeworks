/**
 * Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).
 */
#include "../library/io.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int findMaxNonUniqueElement(const int* arr,
    int length)
{
    int* elements = calloc(UINT_MAX, sizeof(int));
    unsigned int delta = INT_MAX + 1u;
    for (int i = 0; i < length; ++i) {
        elements[arr[i] + delta]++;
    }
    int max = 0;
    for (unsigned int i = UINT_MAX; i >= 0; i--) {
        if (elements[i] > 1) {
            max = (int)(i - delta);
            break;
        }
    }
    free(elements);
    return max;
}

int main()
{
    printf("Данная программа вычисляет самый большой элемент, встречающийся в массиве более одного раза.\n");
    int n = 0;
    inputSingleInt("Введите длину массива: ", &n);
    int* arr = calloc(n, sizeof(int));
    inputArrayOfInts("Введите содержимое массива: ", arr, n);

    printf("Максимальный элемент, встречающийся более одного раза равен %d", findMaxNonUniqueElement(arr, n));

    free(arr);
    return 0;
}