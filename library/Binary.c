#include "Binary.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Basic initialization for bInt32
 */
bInt32 binaryZero()
{
    bInt32 binary = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    return binary;
}
/**
 * Checks if number is actually 16 bit extended binary
 */
bool is16bitBinary(bInt32 binary)
{
    bool result = true;
    int extendDigit = binary.digits[31];
    for (int i = 15; i < 32; i++)
        if (binary.digits[i] != extendDigit) {
            result = false;
            break;
        }
    return result;
}

/**
 * Bitwise NOT on bInt32
 */
bInt32 not(bInt32 binary)
{
    bInt32 notBinary = binaryZero();
    for (int i = 0; i < 32; ++i)
        notBinary.digits[i] = !binary.digits[i];
    return notBinary;
}

/**
 * Does left shift on given binary by given amount of places to shift
 */
bInt32 leftShift(bInt32 binary, int placesToShift)
{
    bInt32 shiftedBinary = binaryZero();
    for (int i = placesToShift; i < 32; ++i)
        shiftedBinary.digits[i] = binary.digits[i - placesToShift];

    return shiftedBinary;
}

/**
 * Addition of two bInt32 numbers
 */
bInt32 add(bInt32 binary1, bInt32 binary2)
{
    bInt32 sum = binaryZero();
    int carry = 0;
    for (int i = 0; i < 32; ++i) {
        int digit1 = binary1.digits[i];
        int digit2 = binary2.digits[i];
        sum.digits[i] = (digit1 ^ digit2) ^ carry;
        carry = digit1 & digit2 || (carry & (digit1 ^ digit2));
    }
    return sum;
}

/**
 * Returns "-number" of given bInt32
 */
bInt32 makeNegative(bInt32 binary)
{
    bInt32 negativeBinary = not(binary);
    bInt32 one = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
    negativeBinary = add(negativeBinary, one);
    return negativeBinary;
}

/**
 * Converts int to little-endian binary representation
 */
bInt32 intTobInt32(int number)
{
    bInt32 binaryNumber = binaryZero();
    bool isNegative = number < 0;
    number = abs(number);
    for (int i = 0; i < 31; ++i) {
        if (number <= 0)
            break;
        binaryNumber.digits[i] = number % 2;
        number = number / 2;
    }

    if (isNegative)
        binaryNumber = makeNegative(binaryNumber);

    return binaryNumber;
}

/**
 * Converts bInt32 to int
 */
int bInt32ToInt(bInt32 binary)
{
    int number = 0;
    int powerOfTwo = 1;
    for (int i = 0; i < 32; ++i) {
        number += binary.digits[i] * powerOfTwo;
        powerOfTwo *= 2; // Here is an abuse of overflow UB to calculate negative number correctly, but in both clang and gcc 2^32 becomes -2^32, which is what we need
    }
    return number;
}

void printbInt32(bInt32 binary)
{
    for (int i = 0; i < 32; ++i)
        printf("%d", binary.digits[i]);
}
