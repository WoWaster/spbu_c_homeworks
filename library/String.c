#include "String.h"
#include <stdio.h>
#include <string.h>

struct String {
    struct Node* head;
    struct Node* tail;
    size_t length;
};

typedef struct Node {
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

/**
 * Actually is a part of existing String, so head and tail may have links where NULL is expected.
 * Be cautious while using freeString on StringView, it may not be desired.
 */
typedef String StringView;

size_t getLength(String* string)
{
    return string->length;
}

Node* newNode(char value)
{
    Node* node = malloc(sizeof(Node));
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

String* newString(const char* input)
{
    String* string = malloc(sizeof(String));
    if (!*input) {
        string->head = NULL;
        string->tail = NULL;
        string->length = 0;
        return string;
    }
    string->head = newNode(input[0]);
    string->length = 1;
    Node* before = string->head;
    for (const char* pointer = input + 1; *pointer; pointer++) {
        Node* new = newNode(*pointer);
        before->next = new;
        new->prev = before;
        before = new;
        string->length++;
    }
    string->tail = before;
    return string;
}

/**
 * You must free substring by using free not freeString.
 * @return new String where head=template[0] and tail=template[-1]
 */
String* find(String* string, const char* template)
{
    String* templateString = newString(template);
    String* substring = malloc(sizeof(String));

    for (Node* current = string->head; current; current = current->next) {
        Node* currentTemplate = templateString->head;
        Node* currentString = current;
        Node* previousString = NULL;
        bool flag = true;
        while (currentTemplate) {
            if (currentTemplate->value != currentString->value) {
                flag = false;
                break;
            }

            currentTemplate = currentTemplate->next;
            previousString = currentString;
            currentString = currentString->next;
        }
        if (flag) {
            substring->head = current;
            substring->tail = previousString;
            substring->length = strlen(template);
            break;
        }
    }

    freeString(templateString);
    return substring;
}

void insertInString(String* string, const char* start, const char* template)
{
    String* location = find(string, start);
    Node* before = location->tail;
    Node* after = location->tail->next;

    String* templateString = newString(template);
    templateString->head->prev = before;
    before->next = templateString->head;
    templateString->tail->next = after;
    if (after)
        after->prev = templateString->tail;
    else
        string->tail = templateString->tail;
    string->length += templateString->length;

    free(templateString);
    free(location);
}

void replaceInString(String* string, const char* template, const char* fragment)
{
    String* substring = find(string, template);
    String* insertion = newString(fragment);

    if (substring->head->prev)
        substring->head->prev->next = insertion->head;
    else
        string->head = insertion->head;
    insertion->head->prev = substring->head->prev;
    insertion->tail->next = substring->tail->next;
    if (substring->tail->next)
        substring->tail->next->prev = insertion->tail;
    else
        string->tail = insertion->tail;
    string->length = string->length - substring->length + insertion->length;

    freeString(substring);
    free(insertion);
}

void deleteInString(String* string, const char* start, const char* end)
{
    String* foundStart = find(string, start);
    String* foundEnd = find(string, end);

    foundStart->head->prev->next = foundEnd->tail->next;
    if (foundEnd->tail->next)
        foundEnd->tail->next->prev = foundStart->head->prev;

    Node* current = foundStart->head;
    while (current != foundEnd->tail->next) {
        Node* next = current->next;
        free(current);
        current = next;
        string->length -= 1;
    }

    free(foundStart);
    free(foundEnd);
}

void printString(String* string)
{
    for (Node* current = string->head; current; current = current->next)
        printf("%c", current->value);
}

char* stringToChar(String* string)
{
    char* output = malloc((string->length + 1) * sizeof(char));

    Node* current = string->head;
    for (int i = 0; i < string->length; ++i) {
        output[i] = current->value;
        current = current->next;
    }
    output[string->length] = '\0';

    return output;
}

void freeString(String* string)
{
    Node* node = string->head;
    for (int i = 0; i < string->length; ++i) {
        Node* next = node->next;
        free(node);
        node = next;
    }
    free(string);
}