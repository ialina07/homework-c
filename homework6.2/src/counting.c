#include "list.h"
#include <stdlib.h>

// Создание нового узла
Node* createNode(int pos)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->position = pos;
    newNode->next = NULL;
    return newNode;
}

// Построение циклического списка из n воинов
Node* createCircle(int n)
{
    if (n <= 0)
        return NULL;

    Node* head = createNode(1);
    Node* prev = head;

    for (int i = 2; i <= n; i++) {
        Node* newNode = createNode(i);
        prev->next = newNode;
        prev = newNode;
    }

    // Замыкаем в кольцо
    prev->next = head;
    return head;
}

// Освобождение памяти всего списка
void freeCircle(Node* head)
{
    if (!head)
        return;

    Node* current = head;
    Node* toDelete;

    do {
        toDelete = current;
        current = current->next;
        free(toDelete);
    } while (current != head);
}
