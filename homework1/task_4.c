/*
 * Написать программу, печатающую все простые числа, не превосходящие заданного числа.
 */

#include "../library//array.h"
#include "../library//io.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Using logic of sieve of Eratosthenes fills given array with 1's and 0's.
 * Result of function's work must be parsed separately
 */
void sieveOfEratosthenes(int n, int* arr)
{
    arr[0] = arr[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (arr[i])
            for (int j = i * i; j <= n; j += i)
                arr[j] = 0;
}

/**
 * Simple parser for sieveOfEratosthenes, just prints all non-zero indexes of array
 */
void printSieveOfEratosthenes(int n, const int* arr)
{
    for (int i = 0; i <= n; ++i) {
        if (arr[i] != 0)
            printf("%d ", i);
    }
}

int main()
{
    printf("Данная программа выводит все простые числа, не превосходящие заданного n.\n");
    int n = 0;
    inputSingleInt("Введите число n: ", &n);
    int* primes = calloc(n + 1, sizeof(int));
    fillArray(1, primes, n + 1);
    sieveOfEratosthenes(n, primes);
    printf("Простые числа меньше %d:\n", n);
    printSieveOfEratosthenes(n, primes);
    free(primes);
    return 0;
}
