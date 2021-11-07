#include "Binary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bInt32 {
    int digits[32];
};

/**
 * Basic initialization for bInt32
 */
bInt32 binaryZero()
{
    bInt32 binary = malloc(sizeof(struct bInt32));
    for (int i = 0; i < 32; ++i)
        binary->digits[i] = 0;
    return binary;
}
/**
 * Checks if number is actually 16 bit extended binary
 */
bool is16bitBinary(bInt32 binary)
{
    int extendDigit = binary->digits[31];
    for (int i = 15; i < 32; i++)
        if (binary->digits[i] != extendDigit)
            return false;

    return true;
}

/**
 * Bitwise NOT on bInt32
 */
bInt32 not(bInt32 binary)
{
    bInt32 notBinary = binaryZero();
    for (int i = 0; i < 32; ++i)
        notBinary->digits[i] = !binary->digits[i];
    free(binary);
    return notBinary;
}

/**
 * Does left shift on given binary by given amount of places to shift
 */
bInt32 leftShift(bInt32 binary, int placesToShift)
{
    bInt32 shiftedBinary = binaryZero();
    for (int i = placesToShift; i < 32; ++i)
        shiftedBinary->digits[i] = binary->digits[i - placesToShift];
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
        int digit1 = binary1->digits[i];
        int digit2 = binary2->digits[i];
        sum->digits[i] = (digit1 ^ digit2) ^ carry;
        carry = digit1 & digit2 || (carry & (digit1 ^ digit2));
    }
    return sum;
}

/**
 * Multiplies given binary numbers using only shifting and addition
 */
bInt32 multiply(bInt32 binary1, bInt32 binary2, bool* isError)
{
    bInt32 output = binaryZero();

    // Check for overflow
    // 16-bit number * 16-bit number = 32-bit number
    if (!is16bitBinary(binary1) || !is16bitBinary(binary2)) {
        *isError = true;
        return output;
    }
    bInt32 multiplier = malloc(sizeof(struct bInt32));
    memcpy(multiplier, binary1, sizeof(struct bInt32));

    for (int i = 0; i < 32; ++i) {
        if (binary2->digits[i] == 1) {
            bInt32 temp = output;
            output = add(output, multiplier);
            free(temp);
        }
        bInt32 temp = multiplier;
        multiplier = leftShift(multiplier, 1);
        free(temp);
    }
    free(multiplier);
    return output;
}

/**
 * Returns "-number" of given bInt32
 */
bInt32 makeNegative(bInt32 binary)
{
    bInt32 negativeBinary = not(binary);
    bInt32 one = malloc(sizeof(struct bInt32));
    for (int i = 0; i < 32; ++i)
        one->digits[i] = 0;
    one->digits[0] = 1;
    bInt32 temp = negativeBinary;
    negativeBinary = add(negativeBinary, one);
    free(temp);
    free(one);
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
        binaryNumber->digits[i] = number % 2;
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
    long powerOfTwo = 1; // long is needed because at 30th step of loop we get 2^31 which is bigger than int (2^31-1)
    for (int i = 0; i < 31; ++i) {
        number += (int)(binary->digits[i] * powerOfTwo);
        powerOfTwo *= 2;
    }
    powerOfTwo = -powerOfTwo;
    number += (int)(binary->digits[31] * powerOfTwo);
    return number;
}

void printbInt32(bInt32 binary)
{
    for (int i = 0; i < 32; ++i)
        printf("%d", binary->digits[i]);
}