#pragma once

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} SortedList;

SortedList* createSortedList();
void destroySortedList(SortedList* list);
void addValue(SortedList* list, int value);
void removeValue(SortedList* list, int value);
void printList(const SortedList* list);
int getListSize(const SortedList* list);
