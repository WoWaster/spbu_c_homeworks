#include "LinkedMap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedMap* newMap()
{
    LinkedMap* map = malloc(sizeof(LinkedMap));
    map->first = NULL;
    return map;
}

Node* newNode(const char* key, int value)
{
    Node* node = malloc(sizeof(Node));
    node->key = strdup(key);
    node->value = value;
    node->nextNode = NULL;
    return node;
}

Node* getNode(LinkedMap* map, const char* key)
{
    Node* currentElement = map->first;
    while (currentElement != NULL) {
        if (strcmp(currentElement->key, key) == 0)
            return currentElement;
        currentElement = currentElement->nextNode;
    }
    return NULL;
}

bool hasKey(LinkedMap* map, const char* key)
{
    if (getNode(map, key) != NULL)
        return true;
    return false;
}

void put(LinkedMap* map, const char* key, int value)
{
    if (hasKey(map, key)) {
        Node* node = getNode(map, key);
        node->value = value;
        return;
    }
    Node* node = newNode(key, value);
    node->nextNode = map->first;
    map->first = node;
}

int getValue(LinkedMap* map, const char* key)
{
    return getNode(map, key)->value;
}

void printMap(LinkedMap* map)
{
    Node* currentElement = map->first;
    while (currentElement != NULL) {
        printf("%s: %d\n", currentElement->key, currentElement->value);
        currentElement = currentElement->nextNode;
    }
}

void freeMap(LinkedMap* map)
{
    Node* currentElement = map->first;
    while (currentElement != NULL) {
        Node* nextElement = currentElement->nextNode;
        free((char*)currentElement->key);
        free(currentElement);
        currentElement = nextElement;
    }
    free(map);
}
