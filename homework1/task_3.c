/**
 * Дан массив целых чисел x[1]...x[m+n], рассматриваемый как соединение двух его отрезков:
 * начала x[1]...x[m] длины m и конца x[m+1]...x[m+n] длины n.
 * Не используя дополнительных массивов, переставить начало и конец.
 */

#include "../library/array.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Данная программа переставляет местами части массива x[m+n].\n");
    int m = 0;
    int n = 0;
    inputSingleInt("Введите число m: ", &m);
    inputSingleInt("Введите число n: ", &n);
    int* x = calloc(m + n, sizeof(int));
    inputArrayOfInts("Введите массив x: ", x, m + n);

    reverseArraySlice(x, 0, m);
    reverseArraySlice(x, m, m + n);
    reverseArray(x, m + n);

    printArrayOfInts("Массив x[n+m]: ", x, m + n);

    free(x);
    return 0;
}