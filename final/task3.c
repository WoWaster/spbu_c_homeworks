#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void DFS(int** matrix, int vertices, int paths, int vertex, bool* visitedVertexes)
{
    if (visitedVertexes[vertex])
        return;

    visitedVertexes[vertex] = true;
    for (int i = 0; i < paths; ++i) {
        if (matrix[vertex][i] > 0) {
            for (int j = 0; j < vertices; ++j)
                if (matrix[j][i] < 0)
                    DFS(matrix, vertices, paths, j, visitedVertexes);
        }
    }
}

void universalVertex(int** matrix, int vertices, int paths)
{
    for (int i = 0; i < vertices; ++i) {
        bool* isVisted = calloc(vertices, sizeof(bool));
        DFS(matrix, vertices, paths, i, isVisted);

        bool flag = true;
        for (int j = 0; j < vertices; ++j)
            if (!isVisted[j])
                flag = false;

        if (flag)
            printf("Universal vertex found: %d", i + 1);

        free(isVisted);
    }
}

int main()
{
    int rows = 0;
    int columns = 0;
    printf("Enter vertices and paths numbers, separate them with space: ");
    scanf("%d %d", &rows, &columns);

    int** matrix = calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; ++i)
        matrix[i] = calloc(columns, sizeof(int));

    printf("Enter matrix: ");
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            scanf("%d", &matrix[i][j]);

    universalVertex(matrix, rows, columns);

    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);

    return 0;
}