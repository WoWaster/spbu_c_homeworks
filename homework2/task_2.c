#include "../library/String.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char* inputFile, char* outputFile)
{
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    int M = 0;
    fscanf(input, "%d", &M);

    char buffer[128] = "";
    fscanf(input, "%s", buffer);
    String* string = newString(buffer);

    int N = 0;
    fscanf(input, "%d", &N);

    for (int i = 0; i < N; ++i) {
        char command[8] = "";
        char arg1[64] = "";
        char arg2[64] = "";

        fscanf(input, "%s", command);
        fscanf(input, "%s", arg1);
        fscanf(input, "%s", arg2);

        if (strcmp(command, "REPLACE") == 0)
            replace(string, arg1, arg2);
        else if (strcmp(command, "INSERT") == 0)
            insert(string, arg1, arg2);
        else if (strcmp(command, "DELETE") == 0)
            delete (string, arg1, arg2);

        char* charString = stringToChar(string);
        fprintf(output, "%s\n", charString);
        free(charString);
    }

    freeString(string);
    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 0;
    } else if (argc > 3) {
        printf("Too many arguments!\n");
        return 0;
    }
    if (!isFileExists(argv[1])) {
        printf("Input file does not exists.");
        return 0;
    }

    processData(argv[1], argv[2]);

    return 0;
}