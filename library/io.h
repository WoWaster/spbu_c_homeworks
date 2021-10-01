#ifndef HOMEWORK_1_IO_H
#define HOMEWORK_1_IO_H

#include <stdbool.h>
void inputSingleInt(char* prompt, int* var);

void inputArrayOfInts(char* prompt, int* array, int length);

void printArrayOfInts(char* text, int* array, int length);

bool isFileExists(const char* filename);

#endif // HOMEWORK_1_IO_H
