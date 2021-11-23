#include "../library/TreeMap.h"
#include "../library/io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processData(char* logFile, char* resultsFile, char* balanceFile)
{
    FILE* log = fopen(logFile, "r");
    FILE* results = fopen(resultsFile, "w");

    int numberOfCommands = 0;
    fscanf(log, "%d", &numberOfCommands);

    TreeMap* map = createTreeMap(compare);

    for (int i = 0; i < numberOfCommands; ++i) {
        char command[7] = "";

        fscanf(log, "%s", command);

        if (strcmp(command, "ADD") == 0) {
            int size = -1;
            int count = -1;
            fscanf(log, "%d %d", &size, &count);
            Value sizeValue = wrapInt(size);
            if (hasKey(map, sizeValue)) {
                int currentCount = getInt(get(map, sizeValue));
                put(map, sizeValue, wrapInt(currentCount + count));
            } else
                put(map, sizeValue, wrapInt(count));
        } else if (strcmp(command, "GET") == 0) {
            int size = -1;
            int count = -1;
            fscanf(log, "%d", &size);
            Value sizeValue = wrapInt(size);
            if (hasKey(map, sizeValue))
                count = getInt(get(map, sizeValue));
            else
                count = 0;
            fprintf(results, "%d\n", count);
        } else if (strcmp(command, "SELECT") == 0) {
            int size = -1;
            int count = -1;
            fscanf(log, "%d", &size);
            Value sizeValue = wrapInt(size);
            Value foundSize = getLowerBound(map, sizeValue);
            if (compare(foundSize, wrapNone()) == 0)
                fprintf(results, "SORRY\n");
            else {
                int currentCount = getInt(get(map, foundSize));
                if (currentCount < 1)
                    fprintf(results, "SORRY\n");
                else {
                    put(map, foundSize, wrapInt(currentCount - 1));
                    fprintf(results, "%d\n", getInt(foundSize));
                }
            }
        }
    }

    fclose(log);
    fclose(results);

    FILE* balance = fopen(balanceFile, "w");

    for (TreeMapIterator iterator = getIterator(map); hasElement(&iterator); next(&iterator)) {
        int key = getInt(getKey(&iterator));
        int value = getInt(getValue(&iterator));
        fprintf(balance, "%d %d\n", key, value);
    }

    fclose(balance);
    deleteTreeMap(map);
}

int main(int argc, char* argv[])
{
    if (argc < 4) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 0;
    } else if (argc > 4) {
        printf("Too many arguments!\n");
        return 0;
    }
    if (!isFileExists(argv[1])) {
        printf("Input file does not exists.");
        return 0;
    }

    processData(argv[1], argv[2], argv[3]);

    return 0;
}