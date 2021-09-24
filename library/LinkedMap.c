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

Node* newNode(const char* key, int value)
{
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->nextElement = NULL;
    return node;
}

Node* getNode(LinkedMap* map, const char* key)
{
    Node* currentElement = map->first;
    while (currentElement != NULL) {
        if (currentElement->key == key)
            return currentElement;
        currentElement = currentElement->nextElement;
    }
    return NULL;
}

bool hasKey(LinkedMap* map, const char* key)
{
    if (getNode(map, key) != NULL)
        return true;
    return false;
}