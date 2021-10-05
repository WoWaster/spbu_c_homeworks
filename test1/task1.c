#include "../library/io.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int* values;
    int dim;
} Vector;

Vector* createVector(int dimension, int* values)
{
    Vector* vector = malloc(sizeof(Vector));
    vector->dim = dimension;
    vector->values = values;
    return vector;
}

Vector* createVectorFromStdin(int num)
{
    int dim = -1;
    printf("Введите размерность пространства вектора %d: ", num);
    scanf("%d", &dim);
    int* input = calloc(dim, sizeof(int));
    inputArrayOfInts("Введите координаты вектора через пробел: ", input, dim);
    Vector* vec = createVector(dim, input);
    return vec;
}

int getVectorDimension(Vector* vector)
{
    return vector->dim;
}

int dotProduct(Vector* vec1, Vector* vec2)
{
    if (getVectorDimension(vec1) != getVectorDimension(vec2))
        return 0;
    int result = 0;
    for (int i = 0; i < getVectorDimension(vec1); ++i)
        result += vec1->values[i] * vec2->values[i];

    return result;
}

Vector* addVectors(Vector* vec1, Vector* vec2)
{
    if (getVectorDimension(vec1) != getVectorDimension(vec2))
        return NULL;
    int* sum = calloc(getVectorDimension(vec1), sizeof(int));
    for (int i = 0; i < getVectorDimension(vec1); ++i)
        sum[i] = vec1->values[i] + vec2->values[i];
    Vector* sumVector = createVector(getVectorDimension(vec1), sum);
    return sumVector;
}

Vector* subtractVectors(Vector* vec1, Vector* vec2)
{
    if (getVectorDimension(vec1) != getVectorDimension(vec2))
        return NULL;
    int* difference = calloc(getVectorDimension(vec1), sizeof(int));
    for (int i = 0; i < getVectorDimension(vec1); ++i)
        difference[i] = vec1->values[i] - vec2->values[i];
    Vector* diffVector = createVector(getVectorDimension(vec1), difference);
    return diffVector;
}
double vectorLength(Vector* vector)
{
    double length = 0;
    for (int i = 0; i < getVectorDimension(vector); ++i)
        length += vector->values[i] * vector->values[i];

    length = sqrt(length);
    return length;
}

void printVector(Vector* vector)
{
    printf("(");
    for (int i = 0; i < vector->dim; ++i)
        printf("%d, ", vector->values[i]);
    printf(")\n");
}

void freeVector(Vector* vector)
{
    free(vector->values);
    free(vector);
}

int main(int argc, char* argv[])
{
    Vector* vec1 = createVectorFromStdin(1);
    Vector* vec2 = createVectorFromStdin(2);

    printf("Vector1: ");
    printVector(vec1);
    printf("Пространство Vector1: %d\n", getVectorDimension(vec1));
    printf("Длина Vector1: %f", vectorLength(vec1));
    printf("\n");

    printf("Vector2: ");
    printVector(vec2);
    printf("Пространство Vector2: %d\n", getVectorDimension(vec2));
    printf("\n");

    printf("Скалярное произведение Vector1 и Vector2 равно: %d \n", dotProduct(vec1, vec2));

    Vector* sum = addVectors(vec1, vec2);
    Vector* diff = subtractVectors(vec1, vec2);

    printf("Сумма векторов: ");
    printVector(sum);
    printf("Разность векторов: ");
    printVector(diff);

    freeVector(vec1);
    freeVector(vec2);

    freeVector(sum);
    freeVector(diff);

    return 0;
}