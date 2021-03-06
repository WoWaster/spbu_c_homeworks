#ifndef SPBU_C_HOMEWORKS_BINARY_H
#define SPBU_C_HOMEWORKS_BINARY_H
#include <stdbool.h>
/**
 * 32 bits int in binary representation
 */
typedef struct bInt32* bInt32;

bool is16bitBinary(bInt32 binary);
bInt32 not(bInt32 binary);
bInt32 leftShift(bInt32 binary, int placesToShift);
bInt32 add(bInt32 binary1, bInt32 binary2);
bInt32 multiply(bInt32 binary1, bInt32 binary2, bool* isError);
bInt32 makeNegative(bInt32 binary);
bInt32 intTobInt32(int number);
int bInt32ToInt(bInt32 binary);
void printbInt32(bInt32 binary);
#endif // SPBU_C_HOMEWORKS_BINARY_H