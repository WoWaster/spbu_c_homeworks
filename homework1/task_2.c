/**
 * Найдите максимальный элемент массива, встречающийся более одного раза (массив неупорядоченный).
 */
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>
int findMaxNonUniqueElement(const int* arr, int length)
{
    int max = arr[0];
    int position = -1;
    for (int i = 0; i < length; ++i) {
        int count = 1;
        for (int j = i + 1; j < length; ++j) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > 1 && max <= arr[i]) {
            max = arr[i];
            position = i;
        }
    }
    return position;
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