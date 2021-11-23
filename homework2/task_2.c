#include "../library/String.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char* inputFile, char* outputFile)
{
    FILE* input = fopen(inputFile, "r");
    FILE* output = fopen(outputFile, "w");

    int sequenceLength = 0;
    fscanf(input, "%d", &sequenceLength);

    char buffer[129] = "";
    fscanf(input, "%s", buffer);
    String* string = newString(buffer);

    int numberOfCommands = 0;
    fscanf(input, "%d", &numberOfCommands);

    for (int i = 0; i < numberOfCommands; ++i) {
        char command[8] = "";
        char firstArgument[128] = "";
        char secondArgument[128] = "";

        fscanf(input, "%s", command);
        fscanf(input, "%s", firstArgument);
        fscanf(input, "%s", secondArgument);

        if (strcmp(command, "REPLACE") == 0)
            replaceInString(string, firstArgument, secondArgument);
        else if (strcmp(command, "INSERT") == 0)
            insertInString(string, firstArgument, secondArgument);
        else if (strcmp(command, "DELETE") == 0)
            deleteInString(string, firstArgument, secondArgument);

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