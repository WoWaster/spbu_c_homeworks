#include "../library/io.h"
#include <stdio.h>

unsigned long long computeFibonacciNumber(int number)
{
    unsigned long long term1 = 0;
    unsigned long long term2 = 1;
    unsigned long long result = 0;
    if (number == 0)
        return term1;
    if (number == 1)
        return term2;
    for (int i = 2; i <= number; ++i) {
        result = term1 + term2;
        term1 = term2;
        term2 = result;
    }
    return result;
}

int main()
{
    int number = 0;
    inputSingleInt("Enter number (0<=n<=90) in sequence: ", &number);
    if (number > 90 || number < 0) {
        printf("Incorrect input\n");
        return 0;
    }
    unsigned long long result = computeFibonacciNumber(number);
    printf("%d-th fibonacci number is %llu\n", number, result);

    return 0;
}