#include "../library/ComplexNumber.h"
#include <stdio.h>
/*
 *  Определить операции над ней, позволяющие находить  и частное между двумя значениями.
 * В функции main реализуйте считывание двух комплексных чисел, примените к ним реализованные операции и выведите результат обратно.
 */

int main()
{
    ComplexNumber first = { 0, 0 };
    ComplexNumber second = { 0, 0 };

    printf("This program will calculate sum, difference, product, quotient and modulus of two complex numbers.\n");
    printf("Please enter numbers in format \"Re Im\"\n");

    printf("Enter complex number a: ");
    scanf("%lf %lf", &first.real, &first.imaginary);

    printf("Enter complex number b: ");
    scanf("%lf %lf", &second.real, &second.imaginary);
    printf("\n");

    printf("a: %lf + (%lfi) \nb: %lf + (%lfi)\n", first.real, first.imaginary, second.real, second.imaginary);

    ComplexNumber sum = addition(first, second);
    printf("Sum: %lf + (%lfi)\n", sum.real, sum.imaginary);

    ComplexNumber difference = subtraction(first, second);
    printf("Difference: %lf + (%lfi)\n", difference.real, difference.imaginary);

    ComplexNumber product = multiplication(first, second);
    printf("Product: %lf + (%lfi)\n", product.real, product.imaginary);

    ComplexNumber quotient = division(first, second);
    printf("Quotient: %lf + (%lfi)\n", quotient.real, quotient.imaginary);

    double modFirst = modulus(first);
    double modSecond = modulus(second);
    printf("Modulus of a: %f\nModulus of b: %f\n", modFirst, modSecond);

    return 0;
}