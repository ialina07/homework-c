/**
 * Реализация алгоритма Дейкстры для преобразования инфиксной записи в постфиксную
 */

#include "sortStation.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int IsOperator(char character)
{
    return character == '+' || character == '-' || character == '*' || character == '/';
}

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
