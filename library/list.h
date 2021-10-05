#ifndef SPBU_C_HOMEWORKS_LIST_H
#define SPBU_C_HOMEWORKS_LIST_H

#include <stdbool.h>

typedef struct List List;
typedef struct ListElement ListElement;

List* makeNewList();

bool insert(int data, int position, List* l);
bool locate(int data, List* l, int* position);

int getListSize(List* l);
void printList(List* lst);
int* getListAsArray(List* list);
#endif // SPBU_C_HOMEWORKS_LIST_H
