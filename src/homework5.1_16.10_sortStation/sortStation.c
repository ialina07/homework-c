/**
 * @file SortStation.c
 * @brief Реализация алгоритма Дейкстры для преобразования инфиксной записи в постфиксную
 *
 * Программа преобразует математические выражения из инфиксной формы в постфиксную
 * используя алгоритм "сортировочной станции" Эдсгера Дейкстры.
 */

#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Определение приоритета оператора
 * @param operatorChar Символ оператора
 * @return Числовой приоритет (чем выше число, тем выше приоритет)
 */
int GetOperatorPriority(char operatorChar)
{
    switch (operatorChar) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

/**
 * @brief Проверка, является ли символ оператором
 * @param character Проверяемый символ
 * @return 1 если оператор, 0 если нет
 */
int IsOperator(char character)
{
    return character == '+' || character == '-' || character == '*' || character == '/';
}

/**
 * @brief Преобразование инфиксного выражения в постфиксное
 * @param infixExpression Входная строка в инфиксной записи
 * @param postfixExpression Выходной буфер для постфиксной записи
 * @return 1 если преобразование успешно, 0 если ошибка
 */
int ConvertInfixToPostfix(const char* infixExpression, char* postfixExpression)
{
    CharStack operatorStack;
    CharStackInit(&operatorStack);
    int outputIndex = 0;

    for (int inputIndex = 0; infixExpression[inputIndex] != '\0'; inputIndex++) {
        char currentChar = infixExpression[inputIndex];

        // Пропускаем пробелы
        if (currentChar == ' ') {
            continue;
        }

        // Если цифра - добавляем в выход
        if (isdigit(currentChar)) {
            // Обрабатываем многозначные числа
            while (isdigit(infixExpression[inputIndex]) || infixExpression[inputIndex] == '.') {
                postfixExpression[outputIndex++] = infixExpression[inputIndex++];
            }
            postfixExpression[outputIndex++] = ' ';
            inputIndex--; // Компенсируем инкремент цикла
        }
        // Если открывающая скобка - в стек
        else if (currentChar == '(') {
            if (!CharStackPush(&operatorStack, currentChar)) {
                return 0; // Переполнение стека
            }
        }
        // Если закрывающая скобка
        else if (currentChar == ')') {
            // Выталкиваем операторы до открывающей скобки
            while (!CharStackIsEmpty(&operatorStack) && CharStackPeek(&operatorStack) != '(') {
                postfixExpression[outputIndex++] = CharStackPop(&operatorStack);
                postfixExpression[outputIndex++] = ' ';
            }
            // Удаляем открывающую скобку
            if (!CharStackIsEmpty(&operatorStack) && CharStackPeek(&operatorStack) == '(') {
                CharStackPop(&operatorStack);
            } else {
                return 0; // Несбалансированные скобки
            }
        }
        // Если оператор
        else if (IsOperator(currentChar)) {
            // Выталкиваем операторы с высшим или равным приоритетом
            while (!CharStackIsEmpty(&operatorStack) && IsOperator(CharStackPeek(&operatorStack)) && GetOperatorPriority(CharStackPeek(&operatorStack)) >= GetOperatorPriority(currentChar)) {
                postfixExpression[outputIndex++] = CharStackPop(&operatorStack);
                postfixExpression[outputIndex++] = ' ';
            }
            // Помещаем текущий оператор в стек
            if (!CharStackPush(&operatorStack, currentChar)) {
                return 0; // Переполнение стека
            }
        }
    }

    // Выталкиваем оставшиеся операторы из стека
    while (!CharStackIsEmpty(&operatorStack)) {
        char operatorChar = CharStackPop(&operatorStack);
        if (operatorChar == '(') {
            return 0; // Несбалансированные скобки
        }
        postfixExpression[outputIndex++] = operatorChar;
        postfixExpression[outputIndex++] = ' ';
    }

    postfixExpression[outputIndex] = '\0';
    return 1;
}

/**
 * @brief Главная функция программы
 */
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
