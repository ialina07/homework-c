/**
 * Главная программа для тестирования алгоритма сортировочной станции
 */

#include "sortStation.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char infixInput[STACK_SIZE];
    char postfixOutput[STACK_SIZE * 2]; // Постфиксная запись может быть длиннее

    printf("АЛГОРИТМ ДЕЙКСТРЫ: ПРЕОБРАЗОВАНИЕ ИЗ ИНФИКСНОЙ ФОРМЫ В ПОСТФИКСНУЮ\n");
    printf("Поддерживаются: числа, операторы + - * /, скобки ( )\n");
    printf("Для выхода введите 'exit'\n\n");

    while (1) {
        printf("Введите инфиксное выражение: ");

        if (fgets(infixInput, sizeof(infixInput), stdin) == NULL) {
            break;
        }

        infixInput[strcspn(infixInput, "\n")] = 0;

        if (strcmp(infixInput, "exit") == 0) {
            break;
        }

        if (strlen(infixInput) == 0) {
            continue;
        }

        if (ConvertInfixToPostfix(infixInput, postfixOutput)) {
            printf("Инфикс:  %s\n", infixInput);
            printf("Постфикс: %s\n\n", postfixOutput);
        } else {
            printf("Ошибка: некорректное выражение\n\n");
        }
    }

    printf("Выход из программы.\n");
    return 0;
}
