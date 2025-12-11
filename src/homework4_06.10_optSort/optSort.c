/**
 * @file OptSort.c
 * @brief Оптимизированная сортировка пузырьком с подсчетом перемещенных элементов
 *
 * Возвращает количество элементов, изменивших свою позицию при сортировке.
 * @param array Указатель на массив для сортировки
 * @param count Количество элементов в массиве
 * @return Количество элементов, изменивших позицию при сортировке
 */
int optimizedSort(int* array, int count)
{
    if (count <= 1) {
        return 0;
    }

    // Сохраняем исходные позиции элементов
    int originalPositions[100];
    for (int i = 0; i < count; i++) {
        originalPositions[i] = array[i];
    }

    // Сортируем массив
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

    // Считаем элементы, которые изменили позицию
    int movedCount = 0;

    // Для каждого элемента в отсортированном массиве
    for (int i = 0; i < count; i++) {
        int currentElement = array[i];

        // Ищем этот элемент в исходном массиве
        for (int j = 0; j < count; j++) {
            if (originalPositions[j] == currentElement) {
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
