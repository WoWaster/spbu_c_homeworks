#include "LinkedMap.h"
#include <stdlib.h>

struct LinkedMap {
    Node* first;
    Node* last;
};

struct Node {
    const char* key;
    int value;
    Node* nextElement;
};

LinkedMap* newMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->first = NULL;
    map->last = NULL;
    return map;
}