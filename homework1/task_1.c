/**
 * Написать алгоритм нахождения неполного частного от деления a на b (целые числа),
 * используя только операции сложения, вычитания и умножения.
 */
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * computeQuotient find a quotient using only addition, subtraction and multiplication.
 * Shouldn't be used directly
 */
int computeQuotient(int dividend, int divisor);

/**
 * Helper function for computeQuotient which checks input and decides how to properly get value
 * based on dividend's and divisor's signs
 */
int solveForQuotient(int dividend, int divisor);

int main()
{
    int a = 0;
    int b = 0;

    printf("Данная программа вычисляет неполное частное от деления a на b.\n");
    inputSingleInt("Введите число a: ", &a);
    inputSingleInt("Введите число b: ", &b);

    int result = solveForQuotient(a, b);

    printf("Неполное частное от деления %d на %d равно %d.\n", a, b, result);
    return 0;
}

int computeQuotient(int dividend, int divisor)
{
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
    return quotient;
}

int solveForQuotient(int dividend, int divisor)
{
    if (divisor == 0) {
        printf("ERROR: Деление на 0 невозможно!\n");
        abort();
    }

    if (dividend >= 0 && divisor > 0)
        return computeQuotient(dividend, divisor);
    else if (dividend >= 0 && divisor < 0)
        return -computeQuotient(dividend, abs(divisor));
    else if (dividend < 0 && divisor > 0)
        return -computeQuotient(abs(dividend), divisor) - 1;
    else
        return computeQuotient(abs(dividend), abs(divisor)) + 1;
}