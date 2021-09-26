#include "../library/LinkedMap.h"
#include <stdio.h>

void fillMapFromFile(FILE* file, LinkedMap* map)
{
    char buffer[127] = "";
    while (fscanf(file, "%s", buffer) != EOF) {
        if (hasKey(map, buffer))
            put(map, buffer, getValue(map, buffer) + 1);
        else
            put(map, buffer, 1);
    }
}

void generateCSVFromMap(LinkedMap* map, const char* filename)
{
    FILE* output = fopen(filename, "w");
    Node* currentElement = map->first;
    while (currentElement != NULL) {
        fprintf(output, "%s,%d\n", currentElement->key, currentElement->value);
        currentElement = currentElement->nextNode;
    }
    fclose(output);
}

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: HW2_Task_1 input_file output_file\n");
        return 0;
    } else if (argc > 3) {
        printf("Too many arguments!\n");
        return 0;
    }

    FILE* input = fopen(argv[1], "r");
    LinkedMap* words = newMap();

    fillMapFromFile(input, words);
    generateCSVFromMap(words, argv[2]);

    fclose(input);
    freeMap(words);
    return 0;
}