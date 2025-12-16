#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

// Создание нового отсортированного списка
SortedList* createSortedList()
{
    SortedList* list = (SortedList*)malloc(sizeof(SortedList));
    if (list == NULL) {
        printf("Ошибка создания списка!\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Уничтожение списка и освобождение памяти
void destroySortedList(SortedList* list)
{
    if (list == NULL) return;

    Node* current = list->head;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }

    free(list);
    printf("Память освобождена\n");
}

// Добавление значения в отсортированный список
void addValue(SortedList* list, int value)
{
    if (list == NULL) {
        printf("Ошибка: список не существует!\n");
        return;
    }

    // Создаем новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка памяти!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Если список пустой
    if (list->head == NULL) {
        list->head = newNode;
        list->size++;
        printf("Добавлено: %d\n", value);
        return;
    }

    // Если вставляем в начало
    if (value < list->head->data) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        printf("Добавлено: %d\n", value);
        return;
    }

    // Ищем место для вставки
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    // Вставляем между prev и current
    if (prev != NULL) {
        prev->next = newNode;
    }
    newNode->next = current;
    list->size++;

    printf("Добавлено: %d\n", value);
}

// Удаление значения из списка
void removeValue(SortedList* list, int value)
{
    if (list == NULL || list->head == NULL) {
        printf("Список пуст!\n");
        return;
    }

    // Ищем элемент для удаления
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Число %d не найдено!\n", value);
        return;
    }

    // Удаляем элемент
    if (prev == NULL) {
        // Удаляем голову
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    list->size--;
    printf("Удалено: %d\n", value);
}

// Печать списка
void printList(const SortedList* list)
{
    if (list == NULL || list->head == NULL) {
        printf("Список пуст!\n");
        return;
    }

    printf("Список (%d элементов): ", list->size);
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Получение размера списка
int getListSize(const SortedList* list)
{
    if (list == NULL) return 0;
    return list->size;
}
