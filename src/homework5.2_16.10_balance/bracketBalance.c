/**
 * @file bracketBalance.c
 * @brief Программа для проверки баланса скобок в строке
 *
 * Проверяет корректность расстановки скобок трёх видов: (), [], {}.
 * Последовательность скобок вида ({)} считается некорректной, ({}) — корректной.
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Проверка, является ли символ открывающей скобкой
 * @param character Проверяемый символ
 * @return 1 если открывающая скобка, 0 если нет
 */
int IsOpenBracket(char character)
{
    return character == '(' || character == '[' || character == '{';
}

/**
 * @brief Проверка, является ли символ закрывающей скобкой
 * @param character Проверяемый символ
 * @return 1 если закрывающая скобка, 0 если нет
 */
int IsCloseBracket(char character)
{
    return character == ')' || character == ']' || character == '}';
}

/**
 * @brief Получение соответствующей закрывающей скобки для открывающей
 * @param openBracket Открывающая скобка
 * @return Соответствующая закрывающая скобка или '\0' если не скобка
 */
char GetMatchingCloseBracket(char openBracket)
{
    switch (openBracket) {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    default:
        return '\0';
    }
}

/**
 * @brief Проверка баланса скобок в строке
 * @param inputString Входная строка для проверки
 * @return 1 если скобки сбалансированы, 0 если нет
 *
 * Алгоритм:
 * 1. Проходим по каждому символу строки
 * 2. При встрече открывающей скобки - помещаем в стек
 * 3. При встрече закрывающей скобки:
 *    - Если стек пуст - ошибка
 *    - Если тип скобки не соответствует последней открывающей - ошибка
 *    - Иначе удаляем открывающую скобку из стека
 * 4. В конце стек должен быть пуст
 */
int CheckBracketBalance(const char* inputString)
{
    CharStack bracketStack;
    CharStackInit(&bracketStack);

    for (int i = 0; inputString[i] != '\0'; i++) {
        char currentChar = inputString[i];

        // Если символ - открывающая скобка, помещаем в стек
        if (IsOpenBracket(currentChar)) {
            if (!CharStackPush(&bracketStack, currentChar)) {
                return 0; // Переполнение стека
            }
        }
        // Если символ - закрывающая скобка
        else if (IsCloseBracket(currentChar)) {
            // Если стек пуст - несбалансировано (лишняя закрывающая скобка)
            if (CharStackIsEmpty(&bracketStack)) {
                return 0;
            }

            // Извлекаем последнюю открывающую скобку из стека
            char lastOpenBracket = CharStackPop(&bracketStack);

            // Получаем ожидаемую закрывающую скобку
            char expectedCloseBracket = GetMatchingCloseBracket(lastOpenBracket);

            // Проверяем соответствие типов скобок
            if (currentChar != expectedCloseBracket) {
                return 0; // Несоответствие типов скобок
            }
        }
        // Остальные символы игнорируем
    }

    // Если после обработки всех символов стек пуст - скобки сбалансированы
    // Если стек не пуст - остались незакрытые открывающие скобки
    return CharStackIsEmpty(&bracketStack);
}

/**
 * @brief Главная функция программы
 *
 * Предоставляет интерактивный интерфейс для проверки баланса скобок.
 * Пользователь вводит строки, программа проверяет их и выводит результат.
 */
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
