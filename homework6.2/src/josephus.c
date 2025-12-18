#include "list.h"
#include <stdlib.h>

int josephus(int n, int m)
{
    if (n <= 0 || m <= 0)
        return -1;

    // Создаём круг воинов
    Node* current = createCircle(n);
    if (current == NULL) {
        return -1;
    }

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
