#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void sadlePoints(int** matrix, int rows, int columns)
{
    for (int i = 0; i < rows; ++i) {
        int minimumInRow = INT_MAX;
        int columnNumber = 0;
        for (int j = 0; j < columns; ++j) {
            if (matrix[i][j] < minimumInRow) {
                minimumInRow = matrix[i][j];
                columnNumber = j;
            }
        }

        bool flag = true;
        for (int j = 0; j < rows; ++j) {
            if (matrix[j][columnNumber] > minimumInRow) {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Saddle point found: row %d, column %d\n", i + 1, columnNumber + 1);
    }
}

int main()
{
    int rows = 0;
    int columns = 0;
    printf("Enter rows and columns numbers, separate them with space: ");
    scanf("%d %d", &rows, &columns);

    int** matrix = calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; ++i)
        matrix[i] = calloc(columns, sizeof(int));

    printf("Enter matrix: ");
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            scanf("%d", &matrix[i][j]);

    sadlePoints(matrix, rows, columns);

    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);
    return 0;
}