#include "LinkedMap.h"

struct LinkedMap {
    Node* first;
    Node* last;
};

struct Node {
    const char* key;
    int value;
    Node* nextElement;
};