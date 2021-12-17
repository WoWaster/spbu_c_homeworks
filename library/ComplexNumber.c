#include "ComplexNumber.h"
#include <math.h>

ComplexNumber addition(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber sum = { first.real + second.real, first.imaginary + second.imaginary };
    return sum;
}

ComplexNumber subtraction(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber difference = { first.real - second.real, first.imaginary - second.imaginary };
    return difference;
}

ComplexNumber multiplication(ComplexNumber first, ComplexNumber second)
{
    ComplexNumber product = { first.real * second.real - first.imaginary * second.imaginary, first.real * second.imaginary + first.imaginary * second.real };
    return product;
}

ComplexNumber division(ComplexNumber first, ComplexNumber second)
{
    double divisor = pow(second.real, 2) + pow(second.imaginary, 2);
    double real = (first.real * second.real + first.imaginary * second.imaginary) / divisor;
    double imaginary = (first.imaginary * second.real - first.real * second.imaginary) / divisor;
    ComplexNumber quotient = { real, imaginary };
    return quotient;
}

double modulus(ComplexNumber number)
{
    return sqrt(pow(number.real, 2) + pow(number.imaginary, 2));
}
