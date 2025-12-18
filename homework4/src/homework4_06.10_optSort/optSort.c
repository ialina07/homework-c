#include "OptSort.h"

void optimizedSort(int* array, int count)
{
    if (count <= 1) {
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped)
            break;
    }
}

int countMovedElements(const int* original, const int* sorted, int count)
{
    int movedCount = 0;

    // Для каждого элемента в отсортированном массиве
    for (int i = 0; i < count; i++) {
        int currentElement = sorted[i];

        // Ищем этот элемент в исходном массиве
        for (int j = 0; j < count; j++) {
            if (original[j] == currentElement) {
                // Если позиция изменилась, увеличиваем счетчик
                if (i != j) {
                    movedCount++;
                }
                break;
            }
        }
    }

    return movedCount;
}
