#ifndef SPBU_C_HOMEWORKS_COMPLEXNUMBER_H
#define SPBU_C_HOMEWORKS_COMPLEXNUMBER_H

typedef struct {
    double real;
    double imaginary;
} ComplexNumber;

ComplexNumber addition(ComplexNumber first, ComplexNumber second);
ComplexNumber subtraction(ComplexNumber first, ComplexNumber second);
ComplexNumber multiplication(ComplexNumber first, ComplexNumber second);
ComplexNumber division(ComplexNumber first, ComplexNumber second);
double modulus(ComplexNumber number);

#endif // SPBU_C_HOMEWORKS_COMPLEXNUMBER_H
