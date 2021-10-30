/**
 * Ввести два числа, перевести в двоичное представление и перемножить их используя только сложение и побитовые операции.
 */
#include "../library/Binary.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This app will calculate product of a and b using only binary shifting and addition.\n");
    int a = 0;
    inputSingleInt("Enter a: ", &a);
    int b = 0;
    inputSingleInt("Enter b: ", &b);
    printf("\n");

    bInt32 aBinary = intTobInt32(a);
    bInt32 bBinary = intTobInt32(b);
    bool error = false;
    bInt32 productBinary = multiply(aBinary, bBinary, &error);

    if (error) {
        printf("Can't multiply because of integer (2^31-1) overflow. Aborting.\n");
        return 0;
    }

    printf("a:  \t");
    printbInt32(aBinary);
    printf("\nb:\t  * ");
    printbInt32(bBinary);

    int product = bInt32ToInt(productBinary);
    printf("\n\t\t--------------------------------\n\t\t");
    printbInt32(productBinary);
    printf(" = %d\n", product);

    free(aBinary);
    free(bBinary);
    free(productBinary);
    return 0;
}