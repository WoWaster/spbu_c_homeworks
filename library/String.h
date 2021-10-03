#ifndef SPBU_C_HOMEWORKS_STRING_H
#define SPBU_C_HOMEWORKS_STRING_H
#include <stdbool.h>
#include <stdlib.h>
typedef struct String String;

String* newString(const char* input);
size_t getLength(String* string);
void insert(String* string, const char* start, const char* template);
void replace(String* string, const char* template, const char* fragment);
void delete (String* string, const char* start, const char* end);
char* stringToChar(String* string);
void printString(String* string);
void freeString(String* string);
#endif // SPBU_C_HOMEWORKS_STRING_H
