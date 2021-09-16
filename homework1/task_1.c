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
int computeQuotient(int dividend, int divisor)
{
    int quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }
    return quotient;
}

/**
 * Helper function for computeQuotient which decides how to properly get value
 * based on dividend's and divisor's signs
 * WARNING: No check for division by zero
 */
int solveForQuotient(int dividend, int divisor)
{
    int result = computeQuotient(abs(dividend), abs(divisor));

    if (dividend < 0)
        result = -result - 1;
    if (divisor < 0)
        result = -result;

    return result;
}

int main()
{
    int dividend = 0;
    int divisor = 0;

    printf("Данная программа вычисляет неполное частное от деления a на b.\n");
    inputSingleInt("Введите число a: ", &dividend);
    inputSingleInt("Введите число b: ", &divisor);

    if (divisor == 0) {
        printf("ERROR: Деление на 0 невозможно!\n");
        return 1; // Standard exit code for error
    }

    int result = solveForQuotient(dividend, divisor);

    printf("Неполное частное от деления %d на %d равно %d.\n", dividend, divisor, result);
    return 0;
}
