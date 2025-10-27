#include <stdio.h>
#include <stdlib.h>

// Структура узла циклического списка
typedef struct Node {
    int position;
    struct Node* next;
} Node;

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

int josephus(int n, int m)
{
    if (n <= 0 || m <= 0)
        return -1;

    // Создаём круг воинов
    Node* current = createCircle(n);
    Node* prev = NULL;

    // Находим предыдущий узел перед current
    prev = current;
    while (prev->next != current) {
        prev = prev->next;
    }

    // Пока в круге не останется один воин
    while (current->next != current) {
        // Находим m-го воина
        for (int count = 1; count < m; count++) {
            prev = current;
            current = current->next;
        }

        // Убираем m-го воина из круга
        prev->next = current->next;
        Node* toDelete = current;
        current = current->next;
        free(toDelete);
    }

    int lastPosition = current->position;
    free(current);
    return lastPosition;
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

int main()
{
    int n, m;

    printf("Введите количество воинов (n): ");
    scanf("%d", &n);

    printf("Введите шаг убийства (m): ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Ошибка: n и m должны быть положительными числами\n");
        return 1;
    }

    int survivor = josephus(n, m);
    printf("Последним останется воин на позиции: %d\n", survivor);

    return 0;
}
