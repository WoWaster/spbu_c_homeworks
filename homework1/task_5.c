/**
 * Дано нечетное число – n. Вывести числа от 1 до n^2 по спирали, начиная с центра, направление смотрите в примере.
 */
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int** matrix, int n)
{
    int x = n / 2; // starting point, because n is odd, we can assume it equals to floor(n/2)
    int y = n / 2; // same as x

    int currentDirection = 0; // 0 = RIGHT, 1 = DOWN, 2 = LEFT, 3 = UP
    int counter = 1;

    for (int chainLength = 1; chainLength <= n; ++chainLength) { // length of chain lies in range [1, n], counting starts at edge
        for (int chainCount = 0; chainCount < (chainLength < n ? 2 : 1); // there's always two chains, except for the last chain
             ++chainCount) {
            for (int chainElement = 0; chainElement < chainLength; ++chainElement) {
                matrix[x][y] = counter;
                counter++;

                switch (currentDirection) {
                case 0:
                    y += 1;
                    break;
                case 1:
                    x += 1;
                    break;
                case 2:
                    y -= 1;
                    break;
                case 3:
                    x -= 1;
                    break;
                }
            }
            currentDirection = (currentDirection + 1) % 4;
        }
    }
}

int main()
{
    printf("Данная программа выводит числа от 1 от n^2 по спирали для заданного нечетного n.\n");
    int n = 0;
    inputSingleInt("Введите нечетное n: ", &n);
    int** matrix = malloc(sizeof(int*) * n);
    for (int i = 0; i < n; ++i) {
        matrix[i] = calloc(n, sizeof(int));
    }

    fillMatrix(matrix, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
