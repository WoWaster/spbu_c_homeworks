#include "../library/io.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void fillAdjacencyMatrix(FILE* input, int** matrix, int amountOfVertexes, int amountOfEdges)
{
    for (int i = 0; i < amountOfVertexes; ++i)
        matrix[i] = calloc(amountOfVertexes, sizeof(int));

    for (int i = 0; i < amountOfEdges; ++i) {
        int from = 0;
        int to = 0;
        int weight = 0;
        fscanf(input, "%d %d %d", &from, &to, &weight);
        matrix[from][to] = weight;
    }
}

void dijkstra(int amountOfVertexes, int** matrix, int from, int to)
{
    int* distance = malloc(amountOfVertexes * sizeof(int));
    for (int i = 0; i < amountOfVertexes; ++i)
        distance[i] = INT_MAX;
    bool* used = calloc(amountOfVertexes, sizeof(bool));
    int* paths = calloc(amountOfVertexes, sizeof(int));

    distance[from] = 0;
    for (int i = 0; i < amountOfVertexes; ++i) {
        int vertex = -1;
        for (int j = 0; j < amountOfVertexes; ++j)
            if (!used[j] && (vertex == -1 || distance[j] < distance[vertex]))
                vertex = j;
        if (distance[vertex] == INT_MAX)
            break;
        used[vertex] = true;
        for (int j = 0; j < amountOfVertexes; ++j) {
            if (!matrix[vertex][j])
                continue;
            if (distance[vertex] + matrix[vertex][j] < distance[j]) {
                paths[j] = vertex;
                distance[j] = distance[vertex] + matrix[vertex][j];
            }
        }
    }

    int* path = calloc(amountOfVertexes, sizeof(int));
    for (int v = to, i = 0; v != from; v = paths[v], i++)
        path[i] = v;

    int pathLength = 0;
    for (int i = 0; i < amountOfVertexes; ++i)
        if (path[i])
            pathLength++;

    printf("%d %d\n%d ", pathLength, distance[to], from);
    for (int i = amountOfVertexes - 1; i >= 0; --i)
        if (path[i])
            printf("%d ", path[i]);
    printf("\n");

    free(distance);
    free(used);
    free(paths);
    free(path);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("This app will find shortest path using Dijkstra's algorithm.\nUsage: %s input_file\n", argv[0]);
        return 0;
    } else if (argc > 2) {
        printf("Too many arguments!\n");
        return 0;
    }
    if (!isFileExists(argv[1])) {
        printf("Input file does not exists.");
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    int amountOfVertexes = 0;
    int amountOfEdges = 0;
    fscanf(input, "%d %d", &amountOfVertexes, &amountOfEdges);

    int** adjacencyMatrix = malloc(amountOfVertexes * sizeof(int*));
    fillAdjacencyMatrix(input, adjacencyMatrix, amountOfVertexes, amountOfEdges);

    int fromVertex = 0;
    int toVertex = 0;
    fscanf(input, "%d %d", &fromVertex, &toVertex);

    dijkstra(amountOfVertexes, adjacencyMatrix, fromVertex, toVertex);

    fclose(input);
    for (int i = 0; i < amountOfVertexes; ++i)
        free(adjacencyMatrix[i]);
    free(adjacencyMatrix);

    return 0;
}