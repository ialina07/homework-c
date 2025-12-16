#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sortedList.h"

// Вспомогательная функция для проверки содержимого списка
int isListEqual(const SortedList* list, int* expected, int expectedSize) {
    if (list == NULL) return 0;
    if (getListSize(list) != expectedSize) return 0;

    Node* current = list->head;
    for (int i = 0; i < expectedSize; i++) {
        if (current == NULL || current->data != expected[i]) {
            return 0;
        }
        current = current->next;
    }
    return current == NULL;
}

void printTestResult(const char* testName, int passed) {
    printf("  %s %s\n", passed ? "YES" : "NO", testName);
}

// Тесты
void testCreateDestroy() {
    printf("1. Создание и удаление списка\n");

    SortedList* list = createSortedList();
    int passed = (list != NULL && list->head == NULL && list->size == 0);
    printTestResult("Создание пустого списка", passed);

    destroySortedList(list);
    printTestResult("Корректное удаление", 1);
}

void testAddValues() {
    printf("\n2. Добавление значений\n");

    SortedList* list = createSortedList();

    // Добавляем в разном порядке
    addValue(list, 5);
    addValue(list, 2);
    addValue(list, 8);
    addValue(list, 1);

    int expected[] = {1, 2, 5, 8};
    int passed = isListEqual(list, expected, 4);
    printTestResult("Сортированное добавление", passed);

    destroySortedList(list);
}

void testRemoveValues() {
    printf("\n3. Удаление значений\n");

    SortedList* list = createSortedList();
    addValue(list, 1);
    addValue(list, 2);
    addValue(list, 3);
    addValue(list, 4);

    // Удаляем из середины
    removeValue(list, 3);
    int expected1[] = {1, 2, 4};
    int passed1 = isListEqual(list, expected1, 3);
    printTestResult("Удаление из середины", passed1);

    // Удаляем голову
    removeValue(list, 1);
    int expected2[] = {2, 4};
    int passed2 = isListEqual(list, expected2, 2);
    printTestResult("Удаление головы", passed2);

    // Удаляем хвост
    removeValue(list, 4);
    int expected3[] = {2};
    int passed3 = isListEqual(list, expected3, 1);
    printTestResult("Удаление хвоста", passed3);

    destroySortedList(list);
}

void testEmptyList() {
    printf("\n4. Граничные случаи\n");

    SortedList* list = createSortedList();

    // Удаление из пустого списка
    removeValue(list, 5);
    int passed1 = (getListSize(list) == 0);
    printTestResult("Удаление из пустого списка", passed1);

    // Добавление и удаление одного элемента
    addValue(list, 10);
    removeValue(list, 10);
    int passed2 = (getListSize(list) == 0);
    printTestResult("Добавление и удаление одного элемента", passed2);

    destroySortedList(list);
}

void testDuplicates() {
    printf("\n5. Обработка дубликатов\n");

    SortedList* list = createSortedList();

    // Добавляем дубликаты в другом порядке
    addValue(list, 3);
    addValue(list, 5);
    addValue(list, 5);

    int expected[] = {3, 5, 5};
    int passed = isListEqual(list, expected, 3);
    printTestResult("Добавление дубликатов", passed);

    // Удаляем один дубликат
    removeValue(list, 5);

    int expected2[] = {3, 5};
    int passed2 = isListEqual(list, expected2, 2);
    printTestResult("Удаление дубликата", passed2);

    destroySortedList(list);
}

// Главная функция тестов
void runTests() {
    printf("ЗАПУСК ТЕСТОВ\n\n");

    testCreateDestroy();
    testAddValues();
    testRemoveValues();
    testEmptyList();
    testDuplicates();

    printf("\nТЕСТЫ ЗАВЕРШЕНЫ\n");
}

int main() {
    runTests();
    return 0;
}
