/*
 * Ввести два числа, перевести в двоичное представление (в каком-либо из кодов)
 * и в этом двоичном виде напечатать, сложить, вывести сумму в двоичном и
 * десятичном виде (суммировать двоичные числа).
 */

#include "../library/Binary.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("This app will calculate sum of a and b using binary operations.\n");
    int a = 0;
    inputSingleInt("Enter a: ", &a);
    int b = 0;
    inputSingleInt("Enter b: ", &b);
    printf("\n");

    bInt32 aBinary = intTobInt32(a);
    bInt32 bBinary = intTobInt32(b);
    printf("a:  \t");
    printbInt32(aBinary);
    printf("\nb:\t  + ");
    printbInt32(bBinary);

    bInt32 sumBinary = add(aBinary, bBinary);
    int sum = bInt32ToInt(sumBinary);
    printf("\n\t\t--------------------------------\n\t\t");
    printbInt32(sumBinary);
    printf(" = %d\n", sum);

    free(aBinary);
    free(bBinary);
    free(sumBinary);
    return 0;
}