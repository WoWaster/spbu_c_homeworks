/*
 * Написать программу, печатающую все простые числа, не превосходящие заданного числа.
 */

#include "../library/io.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Using logic of sieve of Eratosthenes fills given array with 1's and 0's.
 * Input array must be allocated and zeroed by calloc
 * Result of function's work must be parsed separately
 */
void sieveOfEratosthenes(int n, bool* arr)
{
    for (int i = 0; i <= n; ++i) {
        arr[i] = true;
    }

    arr[0] = arr[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (arr[i])
            for (int j = i * i; j <= n; j += i)
                arr[j] = false;
}

/**
 * Simple parser for sieveOfEratosthenes, just prints all non-zero indexes of array
 */
void printSieveOfEratosthenes(int n, const bool* arr)
{
    for (int i = 0; i <= n; ++i) {
        if (arr[i])
            printf("%d ", i);
    }
}

int main()
{
    printf("Данная программа выводит все простые числа, не превосходящие заданного n.\n");
    int n = 0;
    inputSingleInt("Введите число n: ", &n);

    bool* primes = calloc(n + 1, sizeof(bool));
    sieveOfEratosthenes(n, primes);

    printf("Простые числа меньше %d:\n", n);
    printSieveOfEratosthenes(n, primes);

    free(primes);
    return 0;
}
