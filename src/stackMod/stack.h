/**
 * @file stack.h
 * @brief Реализация стека для символов и целых чисел
 *
 * Модуль предоставляет универсальную реализацию стека, которая может
 * использоваться для различных задач, требующих LIFO-структуры данных.
 */

#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

/**
 * @brief Структура стека для символов
 */
typedef struct {
    char data[STACK_SIZE];  // Массив для хранения элементов стека
    int top;                // Индекс вершины стека (-1 если пуст)
} CharStack;

/**
 * @brief Структура стека для целых чисел
 */
typedef struct {
    int data[STACK_SIZE];   // Массив для хранения элементов стека
    int top;                // Индекс вершины стека (-1 если пуст)
} IntStack;

/**
 * @brief Инициализация стека символов
 * @param stack Указатель на стек для инициализации
 */
void CharStackInit(CharStack* stack);

/**
 * @brief Инициализация стека целых чисел
 * @param stack Указатель на стек для инициализации
 */
void IntStackInit(IntStack* stack);

/**
 * @brief Проверка стека символов на пустоту
 * @param stack Указатель на стек
 * @return 1 если стек пуст, 0 если нет
 */
int CharStackIsEmpty(const CharStack* stack);

/**
 * @brief Проверка стека целых чисел на пустоту
 * @param stack Указатель на стек
 * @return 1 если стек пуст, 0 если нет
 */
int IntStackIsEmpty(const IntStack* stack);

/**
 * @brief Проверка стека символов на переполнение
 * @param stack Указатель на стек
 * @return 1 если стек полон, 0 если нет
 */
int CharStackIsFull(const CharStack* stack);

/**
 * @brief Проверка стека целых чисел на переполнение
 * @param stack Указатель на стек
 * @return 1 если стек полон, 0 если нет
 */
int IntStackIsFull(const IntStack* stack);

/**
 * @brief Добавление элемента в стек символов
 * @param stack Указатель на стек
 * @param value Символ для добавления
 * @return 1 если успешно, 0 если стек полон
 */
int CharStackPush(CharStack* stack, char value);

/**
 * @brief Добавление элемента в стек целых чисел
 * @param stack Указатель на стек
 * @param value Число для добавления
 * @return 1 если успешно, 0 если стек полон
 */
int IntStackPush(IntStack* stack, int value);

/**
 * @brief Извлечение элемента из стека символов
 * @param stack Указатель на стек
 * @return Извлеченный символ или '\0' если стек пуст
 */
char CharStackPop(CharStack* stack);

/**
 * @brief Извлечение элемента из стека целых чисел
 * @param stack Указатель на стек
 * @return Извлеченное число или 0 если стек пуст
 */
int IntStackPop(IntStack* stack);

/**
 * @brief Просмотр верхнего элемента стека символов без извлечения
 * @param stack Указатель на стек
 * @return Верхний символ или '\0' если стек пуст
 */
char CharStackPeek(const CharStack* stack);

/**
 * @brief Просмотр верхнего элемента стека целых чисел без извлечения
 * @param stack Указатель на стек
 * @return Верхнее число или 0 если стек пуст
 */
int IntStackPeek(const IntStack* stack);

#endif // STACK_H
