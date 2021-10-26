#ifndef SPBU_C_HOMEWORKS_BINARY_H
#define SPBU_C_HOMEWORKS_BINARY_H
/**
 * 32 bits int in binary representation
 */
typedef struct bInt32 {
    int digits[32];
} bInt32;

bInt32 not(bInt32 binary);
bInt32 add(bInt32 binary1, bInt32 binary2);
bInt32 makeNegative(bInt32 binary);
bInt32 intTobInt32(int number);
int bInt32ToInt(bInt32 binary);
void printbInt32(bInt32 binary);
#endif // SPBU_C_HOMEWORKS_BINARY_H
