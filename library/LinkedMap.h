#ifndef SPBU_C_HOMEWORKS_LINKEDMAP_H
#define SPBU_C_HOMEWORKS_LINKEDMAP_H

#include <stdbool.h>

typedef struct LinkedMap LinkedMap;
typedef struct Node Node;

LinkedMap* newMap();
bool hasKey(LinkedMap* map, const char* key);
void put(LinkedMap* map, const char* key, int value);
int getValue(LinkedMap* map, const char* key);
void printMap(LinkedMap* map);
void freeMap(LinkedMap* map);
#endif // SPBU_C_HOMEWORKS_LINKEDMAP_H
