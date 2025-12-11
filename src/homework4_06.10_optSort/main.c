/**
 * @file main.c
 * @brief Основная программа для сортировки чисел
 */

#include <stdio.h>

extern int optimizedSort(int* array, int count);

int main() {
    int numberArray[100];
    int numberCount = 0;
    
    printf("Введите числа для сортировки (не более 100, разделены пробелами):\n");
    
    // Чтение чисел
    while (numberCount < 100 && scanf("%d", &numberArray[numberCount]) == 1) {
        numberCount++;
    }
    
    if (numberCount == 0) {
        printf("Не введено ни одного числа!\n");
        return 0;
    }
    
    printf("\n РЕЗУЛЬТАТЫ СОРТИРОВКИ \n");
    printf("Количество чисел: %d\n", numberCount);
    
    printf("Исходный массив:  [");
    for (int i = 0; i < numberCount; i++) {
        printf("%d", numberArray[i]);
        if (i < numberCount - 1) printf(", ");
    }
    printf("]\n");
    
    // Сортировка
    int movedElementsCount = optimizedSort(numberArray, numberCount);
    
    printf("Отсортированный:  [");
    for (int i = 0; i < numberCount; i++) {
        printf("%d", numberArray[i]);
        if (i < numberCount - 1) printf(", ");
    }
    printf("]\n");
    
    printf("Количество элементов, изменивших свое положение: %d\n", movedElementsCount);
    
    return movedElementsCount;
}
