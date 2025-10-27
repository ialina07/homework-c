#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int sortedList[MAX_SIZE];
int listSize = 0;

void addValue();
void removeValue();
void printList();

int main()
{
    int choice;

    while (1) {
        printf("\nДоступные операции:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение в отсортированный список\n");
        printf("2 - удалить значение из списка\n");
        printf("3 - распечатать список\n");

        printf("Выберете операцию (0-3): ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введите число от 0 до 3\n");
            while (getchar() != '\n'); // очистка буфера ввода
            continue;
        }

        switch (choice) {
        case 0:
            printf("Выход из программы\n");
            return 0;
        case 1:
            addValue();
            break;
        case 2:
            removeValue();
            break;
        case 3:
            printList();
            break;
        default:
            ("Ошибка: неверный выбор операции\n");
        }
    }

    return 0;
}

void addValue()
{
    if (listSize >= MAX_SIZE) {
        printf("Ошибка: список полон\n");
        return;
    }

    int value;
    printf("Введите значение для добавления: ");
    if (scanf("%d", &value) != 1) {
        printf("Ошибка: введите целое число");
        while (getchar() != '\n'); // очистка буфера ввода
        return;
    }

    // находим позицию для вставки
    int pos = 0;
    while (pos < listSize && sortedList[pos] < value) {
        pos++;
    }

    // сдвигаем элементы вправо
    for (int i = listSize; i > pos; i--)
        sortedList[i] = sortedList[i - 1];

    // вставляем значение на найденную позицию
    sortedList[pos] = value;
    listSize++;

    printf("Значение %d добавлено в список\n", value);
}

void removeValue()
{
    if (listSize == 0) {
        printf("Список пуст. Удалять нечего");
        return;
    }

    int value;
    printf("Введите значение для удаления: ");
    if (scanf("%d", &value) != 1) {
        printf("Ошибка: введите целое число");
        while (getchar() != '\n'); // очистка буфера ввода
        return;
    }

    // ищем значение в списке
    int found = 0;
    int pos = -1;
    for (int i = 0; i < listSize; i++) {
        if (sortedList[i] == value) {
            found = 1;
            pos = i;
            break;
        }
    }

    if (found) {
        // сдвигаем элементы влево
        for (int i = pos; i < listSize - 1; i++) {
            sortedList[i] = sortedList[i + 1];
        }
        listSize--;
        printf("Значение %d удалено из списка\n", value);
    } else {
        printf("Значение %d не найдено в списке\n", value);
    }
}

void printList()
{
    if (listSize == 0)
        printf("Список пуст\n");
    else {
        printf("Текущий список: [");
        for (int i = 0; i < listSize; i++) {
            printf("%d", sortedList[i]);
            if (i < listSize - 1)
                printf(", ");
        }
        printf("]\n");
    }
}
