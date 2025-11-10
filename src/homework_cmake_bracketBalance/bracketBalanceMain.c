/**
 * Главная программа для проверки баланса скобок
 *
 * Предоставляет интерактивный интерфейс для проверки баланса скобок.
 * Пользователь вводит строки, программа проверяет их и выводит результат.
 */

#include "bracketBalance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char userInput[STACK_SIZE];

    printf("ПРОВЕРКА БАЛАНСА СКОБОК\n");
    printf("Проверяемые скобки: (), [], {}\n");
    printf("Для выхода введите 'exit'\n\n");

    while (1) {
        printf("Введите строку для проверки: ");

        // Чтение ввода пользователя
        if (fgets(userInput, sizeof(userInput), stdin) == NULL) {
            break;
        }

        // Удаление символа новой строки
        userInput[strcspn(userInput, "\n")] = 0;

        // Проверка команды выхода
        if (strcmp(userInput, "exit") == 0) {
            break;
        }

        // Пропуск пустого ввода
        if (strlen(userInput) == 0) {
            continue;
        }

        // Проверка баланса скобок
        int isBalanced = CheckBracketBalance(userInput);

        // Вывод результата
        printf("Строка: \"%s\"\n", userInput);
        if (isBalanced) {
            printf("Результат: СКОБКИ СБАЛАНСИРОВАНЫ\n");
        } else {
            printf("Результат: СКОБКИ НЕСБАЛАНСИРОВАНЫ\n");
        }
        printf("---\n");
    }

    printf("Выход из программы.\n");
    return 0;
}
