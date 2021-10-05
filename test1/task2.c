#include "../library/io.h"
#include "../library/list.h"
#include <stdio.h>
#include <stdlib.h>

void proccessData(char* inputFile, char* outputFile, int a, int b)
{
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    List* lessThatA = makeNewList();
    List* inAB = makeNewList();
    List* greaterThanB = makeNewList();

    int current = 0;
    while (!feof(input)) {
        fscanf(input, "%d", &current);
        if (current < a)
            insert(current, getListSize(lessThatA), lessThatA);
        else if (current >= a && current <= b)
            insert(current, getListSize(inAB), inAB);
        else
            insert(current, getListSize(greaterThanB), greaterThanB);
    }

    int* part1 = getListAsArray(lessThatA);
    for (int i = 0; i < getListSize(lessThatA); ++i)
        fprintf(output, "%d ", part1[i]);
    free(part1);

    int* part2 = getListAsArray(inAB);
    for (int i = 0; i < getListSize(inAB); ++i)
        fprintf(output, "%d ", part2[i]);
    free(part2);

    int* part3 = getListAsArray(greaterThanB);
    for (int i = 0; i < getListSize(greaterThanB); ++i)
        fprintf(output, "%d ", part3[i]);
    free(part3);

    fprintf(output, "\n");

    freeList(lessThatA);
    freeList(inAB);
    freeList(greaterThanB);

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[])
{
    if (argc != 5) {
        printf("Usage: %s input_file output_file a b\n", argv[0]);
        return 0;
    }
    if (!isFileExists(argv[1])) {
        printf("Input file does not exists.");
        return 0;
    }

    proccessData(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));

    return 0;
}