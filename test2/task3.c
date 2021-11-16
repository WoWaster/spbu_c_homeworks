#include "../library/io.h"
#include <stdio.h>

typedef struct Date {
    int day;
    int month;
    int year;
} Date;

Date findEarliestDate(char* inputFile)
{
    FILE* input = fopen(inputFile, "r");

    char buffer[256] = "";
    Date minDate = { 32, 13, 9999 };
    while (!feof(input)) {
        fscanf(input, "%s", buffer);
        Date date = { 0, 0, 0 };
        sscanf(buffer, "%2d.%2d.%4d", &date.day, &date.month, &date.year);
        if (date.day == 0 && date.month == 0 && date.year == 0)
            continue;
        if (date.day > 31)
            continue;
        if (date.month > 12)
            continue;
        if (date.year < minDate.year) {
            minDate.year = date.year;
            minDate.month = date.month;
            minDate.day = date.day;
            continue;
        }
        if (date.year == minDate.year && date.month < minDate.month) {
            minDate.month = date.month;
            minDate.day = date.day;
            continue;
        }
        if (date.year == minDate.year && date.month == minDate.month && date.day < minDate.day) {
            minDate.day = date.day;
            continue;
        }
    }

    fclose(input);
    return minDate;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 0;
    } else if (argc > 2) {
        printf("Too many arguments!\n");
        return 0;
    }
    if (!isFileExists(argv[1])) {
        printf("Input file does not exists.");
        return 0;
    }

    Date result = findEarliestDate(argv[1]);
    printf("%d.%d.%d\n", result.day, result.month, result.year);

    return 0;
}