#include "list.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct List {
    ListElement* head;
    ListElement* tail;
    int listSize;
};

struct ListElement {
    int data;
    ListElement* nextElement;
};

List* makeNewList()
{
    List* lst = malloc(sizeof(List));
    lst->head = NULL;
    lst->tail = NULL;
    lst->listSize = 0;
    return lst;
}

ListElement* makeNewListElement(int data)
{
    ListElement* newElement = malloc(sizeof(ListElement));
    newElement->data = data;
    newElement->nextElement = NULL;
    return newElement;
}

bool insert(int data, int position, List* l)
{
    if (position > l->listSize)
        return false;

    ListElement* currentElement = makeNewListElement(data);
    if (!l->head) {
        if (position == 0) {
            l->head = currentElement;
            l->tail = currentElement;
            l->listSize++;
            return true;
        } else
            return false;
    }

    l->listSize++;

    if (position == 0) {
        currentElement->nextElement = l->head;
        l->head = currentElement;
        return true;
    }

    if (position == l->listSize - 1) {
        l->tail->nextElement = currentElement;
        l->tail = currentElement;
        return true;
    }

    ListElement* elementBefore = l->head;
    for (int i = 0; i < position - 1; ++i)
        elementBefore = elementBefore->nextElement;

    ListElement* elementAfter = elementBefore->nextElement;
    elementBefore->nextElement = currentElement;
    currentElement->nextElement = elementAfter;

    return true;
}

bool locate(int data, List* l, int* position)
{
    int index = 0;
    ListElement* currentElement = l->head;
    while (currentElement) {
        if (currentElement->data == data) {
            *position = index;

            return true;
        }

        index++;
        currentElement = currentElement->nextElement;
    }

    return false;
}

int getListSize(List* lst)
{
    return lst->listSize;
}

void printList(List* lst)
{
    if (!lst->head)
        printf("List is empty\n");

    ListElement* currentElement = lst->head;
    while (currentElement) {
        printf("%d -> ", currentElement->data);
        currentElement = currentElement->nextElement;
    }
    printf("\n");
}

int* getListAsArray(List* list)
{
    int* array = calloc(getListSize(list), sizeof(int));

    ListElement* current = list->head;
    for (int i = 0; i < getListSize(list); ++i) {
        array[i] = current->data;
        current = current->nextElement;
    }

    return array;
}

void freeList(List* list)
{
    ListElement* currentElement = list->head;
    ListElement* nextElement = NULL;

    while (currentElement) {
        nextElement = currentElement->nextElement;
        free(currentElement);
        currentElement = nextElement;
    }

    free(list);
}