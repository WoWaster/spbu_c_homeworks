#include "TreeMap.h"
#include "commonUtils/numericOperations.h"
#include <stdlib.h>
#include <string.h>

struct Node {
    Value key;
    Value value;
    int height;
    struct Node* parent;
    struct Node* leftChild;
    struct Node* rightChild;
};

void deleteNode(Node* node)
{
    if (!node)
        return;
    deleteNode(node->leftChild);
    deleteNode(node->rightChild);
    free(node);
}

Node* createNode(Value key, Value value, Node* parent)
{
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->height = 0;
    node->parent = parent;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

int getHeight(Node* node)
{
    return node == NULL ? -1 : node->height;
}

void updateHeight(Node* node)
{
    int heightLeft = getHeight(node->leftChild);
    int heightRight = getHeight(node->rightChild);
    node->height = max(heightLeft, heightRight) + 1;
}

int getBalanceFactor(Node* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

Node* rotateRight(Node* root)
{
    Node* child = root->leftChild;
    root->leftChild = child->rightChild;
    child->rightChild = root;
    child->parent = root->parent;
    root->parent = child;
    if (root->leftChild)
        root->leftChild->parent = root;
    updateHeight(root);
    updateHeight(child);
    return child;
}

Node* rotateLeft(Node* root)
{
    Node* child = root->rightChild;
    root->rightChild = child->leftChild;
    child->leftChild = root;
    child->parent = root->parent;
    root->parent = child;
    if (root->rightChild)
        root->rightChild->parent = root;
    updateHeight(root);
    updateHeight(child);
    return child;
}

Node* balance(Node* root)
{
    updateHeight(root);
    if (getBalanceFactor(root) == 2) {
        if (getBalanceFactor(root->rightChild) == -1)
            root->rightChild = rotateRight(root->rightChild);
        return rotateLeft(root);
    }
    if (getBalanceFactor(root) == -2) {
        if (getBalanceFactor(root->leftChild) == 1)
            root->leftChild = rotateLeft(root->leftChild);
        return rotateRight(root);
    }
    return root;
}

Node* insert(Node* node, Value key, Value value, Comparator comparator, Node* parent)
{
    if (!node) {
        return createNode(key, value, parent);
    }

    switch (comparator(key, node->key)) {
    case -1:
        node->leftChild = insert(node->leftChild, key, value, comparator, node);
        break;
    case 1:
        node->rightChild = insert(node->rightChild, key, value, comparator, node);
        break;
    case 0:
        node->value = value;
        return node;
    }
    node = balance(node);

    return node;
}

Node* maximum(Node* node)
{
    return node->rightChild ? maximum(node->rightChild) : node;
}

Node* minimum(Node* node)
{
    return node->leftChild ? minimum(node->leftChild) : node;
}

Node* removeMinimum(Node* node)
{
    if (!node->leftChild)
        return node->rightChild;
    node->leftChild = removeMinimum(node->leftChild);
    return balance(node);
}

Node* remove(Node* node, Value key, Comparator comparator, MapEntry* entry, Node* parent)
{
    if (!node)
        return NULL;

    switch (comparator(key, node->key)) {
    case -1:
        node->leftChild = remove(node->leftChild, key, comparator, entry, node);
        break;
    case 1:
        node->rightChild = remove(node->rightChild, key, comparator, entry, node);
        break;
    case 0: {
        Node* leftChild = node->leftChild;
        Node* rightChild = node->rightChild;
        entry->key = node->key;
        entry->value = node->value;
        free(node);
        if (!leftChild && !rightChild)
            return NULL;
        if (!rightChild) {
            leftChild->parent = parent;
            return leftChild;
        }
        Node* minimumInRightTree = minimum(rightChild);
        minimumInRightTree->rightChild = removeMinimum(rightChild);
        minimumInRightTree->rightChild->parent = minimumInRightTree;
        minimumInRightTree->leftChild = leftChild;
        leftChild->parent = minimumInRightTree;
        return balance(minimumInRightTree);
    }
    }
    return balance(node);
}

Node* find(Node* node, Value key, Comparator comparator)
{
    if (!node)
        return NULL;

    switch (comparator(key, node->key)) {
    case -1:
        return find(node->leftChild, key, comparator);
    case 1:
        return find(node->rightChild, key, comparator);
    case 0:
        return node;
    }
    return NULL;
}

struct TreeMap {
    Node* root;
    Comparator comparator;
};

TreeMap* createTreeMap(Comparator comparator)
{
    TreeMap* treeMap = malloc(sizeof(TreeMap));
    treeMap->root = NULL;
    treeMap->comparator = comparator;
    return treeMap;
}

void deleteTreeMap(TreeMap* map)
{
    deleteNode(map->root);
    free(map);
}

void put(TreeMap* map, Value key, Value value)
{
    map->root = insert(map->root, key, value, map->comparator, map->root);
}

MapEntry removeKey(TreeMap* map, Value key)
{
    MapEntry entry = { wrapNone(), wrapNone() };
    remove(map->root, key, map->comparator, &entry, map->root);
    return entry;
}

Value get(TreeMap* map, Value key)
{
    Node* node = find(map->root, key, map->comparator);
    return node ? node->value : wrapNone();
}

bool hasKey(TreeMap* map, Value key)
{
    Node* node = find(map->root, key, map->comparator);
    return node ? true : false;
}

Value getLowerBound(TreeMap* map, Value key)
{
    Node* current = map->root;
    Node* found = NULL;
    while (current) {
        if (map->comparator(key, current->key) == 1) {
            current = current->rightChild;
        } else {
            found = current;
            current = current->leftChild;
        }
    }
    return found ? found->key : wrapNone();
}

Value getUpperBound(TreeMap* map, Value key)
{
    Node* current = map->root;
    Node* found = NULL;
    while (current) {
        if (map->comparator(key, current->key) == -1) {
            current = current->rightChild;
        } else {
            found = current;
            current = current->leftChild;
        }
    }
    return found ? found->key : wrapNone();
}

Value getMaximum(TreeMap* map)
{
    Node* node = maximum(map->root);
    return node ? node->value : wrapNone();
}

Value getMinimum(TreeMap* map)
{
    Node* node = minimum(map->root);
    return node ? node->value : wrapNone();
}

TreeMapIterator getIterator(TreeMap* map)
{
    TreeMapIterator iterator = { map->root };

    iterator.current = map->root;
    if (!iterator.current)
        return iterator;
    while (iterator.current->leftChild)
        iterator.current = iterator.current->leftChild;

    return iterator;
}

Value getKey(TreeMapIterator* iterator)
{
    return iterator->current->key;
}

Value getValue(TreeMapIterator* iterator)
{
    return iterator->current->value;
}

void next(TreeMapIterator* iterator)
{
    if (iterator->current->rightChild) {
        iterator->current = iterator->current->rightChild;
        while (iterator->current->leftChild)
            iterator->current = iterator->current->leftChild;
        return;
    }
    while (true) {
        if (!iterator->current->parent) {
            iterator->current = NULL;
            return;
        }
        if (iterator->current->parent->leftChild == iterator->current) {
            iterator->current = iterator->current->parent;
            return;
        }
        iterator->current = iterator->current->parent;
    }
}

bool hasElement(TreeMapIterator* iterator)
{
    return iterator->current ? true : false;
}