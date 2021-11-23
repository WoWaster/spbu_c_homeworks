#include <stdio.h>
#include <string.h>

typedef union Number {
    double value;
    unsigned char binaryForm[8];
} Number;

void hexToBinary(const char hex[17], char bin[65])
{
    const char binary[16][5] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };
    const char digits[] = "0123456789ABCDEF";
    int p = 0;
    while (hex[p]) {
        const char* v = strchr(digits, hex[p++]);
        strcat(bin, binary[v - digits]);
    }
}

void doubleToBinary(unsigned char number[8], char binary[65])
{
    char hex[17] = "";
    for (int i = 7; i >= 0; --i) {
        char buffer[4] = "";
        sprintf(buffer, "%02X", number[i]);
        strcat(hex, buffer);
    }
    hexToBinary(hex, binary);
}

void printNormalizedBinaryDouble(Number number)
{
    char binary[65] = "";
    doubleToBinary(number.binaryForm, binary);

    double powerOfTwo = 1024;

    int exponent = -1023;
    for (int i = 1; i < 12; ++i) {
        if (binary[i] == '1')
            exponent += (int)powerOfTwo;
        powerOfTwo /= 2;
    }

    double fraction = 1;
    for (int i = 12; i < 64; ++i) {
        if (binary[i] == '1')
            fraction += powerOfTwo;
        powerOfTwo /= 2;
    }

    if (binary[0] == '1')
        printf("-");
    if (exponent == -1023 && fraction == 1) {
        printf("0\n");
        return;
    }
    printf("%.17f * 2^%d\n", fraction, exponent);
}

int main()
{
    Number number = { 0 };

    printf("This app will print normalized form of given double.\n");
    printf("Enter the double: ");
    scanf("%lf", &number.value);
    printNormalizedBinaryDouble(number);

    return 0;
}