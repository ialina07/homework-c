/**
 * Реализация функций для проверки баланса скобок
 */

#include "bracketBalance.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IsOpenBracket(char character)
{
    return character == '(' || character == '[' || character == '{';
}

int IsCloseBracket(char character)
{
    return character == ')' || character == ']' || character == '}';
}

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
