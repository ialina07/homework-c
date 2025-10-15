#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Структура стека
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Инициализация стека
void initStack(Stack* s)
{
    s->top = -1;
}

// Проверка на пустоту
int isEmpty(Stack* s)
{
    return s->top == -1;
}

// Проверка на переполнение
int isFull(Stack* s)
{
    return s->top == MAX_SIZE - 1;
}

// Добавление элемента в стек
void push(Stack* s, char c)
{
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

// Извлечение элемента из стека
char pop(Stack* s)
{
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

// Просмотр верхнего элемента
char peek(Stack* s)
{
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// Проверка, является ли символ открывающей скобкой
int isOpenBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

// Проверка, является ли символ закрывающей скобкой
int isCloseBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

// Проверка соответствия скобок
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

// Основная функция проверки баланса
int checkBracketBalance(const char* str)
{
    Stack stack;
    initStack(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        char current = str[i];

        // Если открывающая скобка - помещаем в стек
        if (isOpenBracket(current)) {
            push(&stack, current);
        }
        // Если закрывающая скобка
        else if (isCloseBracket(current)) {
            // Если стек пуст - несбалансировано
            if (isEmpty(&stack)) {
                return 0;
            }

            // Извлекаем последнюю открывающую скобку
            char lastOpen = pop(&stack);

            // Проверяем соответствие
            if (!isMatchingPair(lastOpen, current)) {
                return 0;
            }
        }
        // Игнорируем другие символы
    }

    // Если после обработки всех символов стек пуст - сбалансировано
    return isEmpty(&stack);
}

int main()
{
    printf("  ПРОВЕРКА БАЛАНСА СКОБОК\n");

    char input[MAX_SIZE];

    printf("Введите строку для проверки (или 'exit' для выхода):\n");

    while (1) {

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Удаляем символ новой строки
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (strlen(input) == 0) {
            continue;
        }

        int result = checkBracketBalance(input);

        printf("Строка: \"%s\"\n", input);
        if (result) {
            printf("Результат: СКОБКИ СБАЛАНСИРОВАНЫ\n");
        } else {
            printf("Результат: СКОБКИ НЕСБАЛАНСИРОВАНЫ\n");
        }
        printf("---\n");
    }

    printf("Выход из программы.\n");
    return 0;
}
