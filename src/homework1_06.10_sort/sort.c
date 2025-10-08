#include <stdio.h>
#include <string.h>

extern void bubbleSortAsm(int* array, int count);

int main() {
    int numbers[100];
    int original[100];
    int count = 0;

    while (scanf("%d", &numbers[count]) == 1 && count < 100) {
        count++;
    }

    // Сохраняем оригинальный массив
    memcpy(original, numbers, count * sizeof(int));

    // Сортируем
    bubbleSortAsm(numbers, count);

    // Считаем элементы, которые изменили свою позицию
    int changedCount = 0;
    for (int i = 0; i < count; i++) {
        if (numbers[i] != original[i]) {
            changedCount++;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return changedCount;
}
