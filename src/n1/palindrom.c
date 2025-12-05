#include <stdio.h>
#include <stdlib.h>
#include "palindrom.h"

// создание нового узла
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// добавление элемента в конец списка
void append(Node** head, int value) {
    Node* newNode = createNode(value);

    // Если список пустой
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // Добавляем в конец
    current->next = newNode;
}

// печать списка
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// очистка памяти списка
void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// получение длины списка
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// разворот списка
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// проверка симметричности
int isSymmetric(Node* head) {
    // Пустой список или из одного элемента
    if (head == NULL || head->next == NULL) {
        return 1; // true
    }

    // Находим середину списка
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Разворачиваем вторую половину
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;

    // Сравниваем две половины
    int result = 1;
    Node* secondHalfCopy = secondHalf;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            result = 0;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Восстанавливаем список
    reverseList(secondHalfCopy);

    return result;
}

// тесты
void runSimpleTests() {
    printf("Тестирование\n");

    // Тест 1: Пустой список
    Node* list1 = NULL;
    printf("1. Пустой список: %s\n",
           isSymmetric(list1) ? "симметричен" : "не симметричен");

    // Тест 2: Один элемент
    Node* list2 = NULL;
    append(&list2, 5);
    printf("2. Список [5]: %s\n",
           isSymmetric(list2) ? "симметричен" : "не симметричен");
    freeList(list2);

    // Тест 3: Пример из задания - симметричный
    Node* list3 = NULL;
    int arr3[] = {10, 20, 30, 20, 10};
    for (int i = 0; i < 5; i++) {
        append(&list3, arr3[i]);
    }
    printf("3. Список [10 20 30 20 10]: ");
    printList(list3);
    printf("   Результат: %s\n",
           isSymmetric(list3) ? "симметричен" : "не симметричен");
    freeList(list3);

    // Тест 4: Пример из задания - не симметричный
    Node* list4 = NULL;
    int arr4[] = {10, 20, 30, 40, 20, 10};
    for (int i = 0; i < 6; i++) {
        append(&list4, arr4[i]);
    }
    printf("4. Список [10 20 30 40 20 10]: ");
    printList(list4);
    printf("   Результат: %s\n",
           isSymmetric(list4) ? "симметричен" : "не симметричен");
    freeList(list4);

    // Тест 5: Четное количество, симметричный
    Node* list5 = NULL;
    int arr5[] = {1, 2, 3, 3, 2, 1};
    for (int i = 0; i < 6; i++) {
        append(&list5, arr5[i]);
    }
    printf("5. Список [1 2 3 3 2 1]: %s\n",
           isSymmetric(list5) ? "симметричен" : "не симметричен");
    freeList(list5);

    printf("Тесты завершены\n\n");
}

int main() {
    Node* head = NULL;
    int number;
    char choice;

    printf("Проверка списка на симметричность\n");

    // запускаем тесты
    runSimpleTests();
    // ввод данных от пользователя
    printf("Введите натуральные числа (0 для завершения):\n");

    while (1) {
        printf("Число: ");
        if (scanf("%d", &number) != 1) {
            printf("Ошибка ввода! Введите число.\n");
            while (getchar() != '\n'); // Очистка буфера
            continue;
        }

        if (number == 0) {
            break;
        }

        if (number < 1) {
            printf("Только натуральные числа!\n");
            continue;
        }

        append(&head, number);
    }

    // Вывод результата
    if (head == NULL) {
        printf("Список пустой.\n");
    } else {
        printf("\nВаш список: ");
        printList(head);

        if (isSymmetric(head)) {
            printf("Список симметричен!\n");
        } else {
            printf("Список не симметричен.\n");
        }
    }

    // Очистка памяти
    freeList(head);

    return 0;
}
