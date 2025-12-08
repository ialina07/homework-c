/**
 *@file stack.c
 * @brief Реализация функций стека
 */

#include "stack.h"

void CharStackInit(CharStack* stack) {
    stack->top = -1;
}

void IntStackInit(IntStack* stack) {
    stack->top = -1;
}

int CharStackIsEmpty(const CharStack* stack) {
    return stack->top == -1;
}

int IntStackIsEmpty(const IntStack* stack) {
    return stack->top == -1;
}

int CharStackIsFull(const CharStack* stack) {
    return stack->top == STACK_SIZE - 1;
}

int IntStackIsFull(const IntStack* stack) {
    return stack->top == STACK_SIZE - 1;
}

int CharStackPush(CharStack* stack, char value) {
    if (CharStackIsFull(stack)) {
        return 0;
    }
    stack->data[++(stack->top)] = value;
    return 1;
}

int IntStackPush(IntStack* stack, int value) {
    if (IntStackIsFull(stack)) {
        return 0;
    }
    stack->data[++(stack->top)] = value;
    return 1;
}

char CharStackPop(CharStack* stack) {
    if (CharStackIsEmpty(stack)) {
        return '\0';
    }
    return stack->data[(stack->top)--];
}

int IntStackPop(IntStack* stack) {
    if (IntStackIsEmpty(stack)) {
        return 0;
    }
    return stack->data[(stack->top)--];
}

char CharStackPeek(const CharStack* stack) {
    if (CharStackIsEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

int IntStackPeek(const IntStack* stack) {
    if (IntStackIsEmpty(stack)) {
        return 0;
    }
    return stack->data[stack->top];
}
