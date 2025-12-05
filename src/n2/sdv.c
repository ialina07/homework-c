#include <stdio.h>
#include <stdbool.h>

// Преобразование массива булевых значений в число
unsigned int boolArrayToInt(const bool arr[], int n) {
    unsigned int result = 0;
    for (int i = 0; i < n; i++) {
        result = (result << 1) | (arr[i] ? 1 : 0);
    }
    return result;
}

// Циклический сдвиг массива влево на 1 позицию
void rotateArrayLeft(bool arr[], int n) {
    if (n <= 1) return;
    bool first = arr[0];
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = first;
}

// Нахождение максимального циклического сдвига
unsigned int maxRotation(const bool arr[], int n) {
    if (n <= 0) return 0;

    bool temp[32];
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    unsigned int maxValue = boolArrayToInt(temp, n);

    for (int i = 1; i < n; i++) {
        rotateArrayLeft(temp, n);
        unsigned int current = boolArrayToInt(temp, n);
        if (current > maxValue) {
            maxValue = current;
        }
    }

    return maxValue;
}

// тесты
void runTests() {
    printf("Тесты:\n");

    // Тест 1: 101 (5) -> 110 (6)
    bool arr1[] = {1, 0, 1};
    unsigned int res1 = maxRotation(arr1, 3);
    printf("101 -> %u %s\n", res1, res1 == 6 ? "passed" : "not passed");

    // Тест 2: 11010 (26) -> 11010 (26)
    bool arr2[] = {1, 1, 0, 1, 0};
    unsigned int res2 = maxRotation(arr2, 5);
    printf("11010 -> %u %s\n", res2, res2 == 26 ? "passed" : "not passed");

    // Тест 3: 1101 (13) -> 1110 (14)
    bool arr3[] = {1, 1, 0, 1};
    unsigned int res3 = maxRotation(arr3, 4);
    printf("1101 -> %u %s\n", res3, res3 == 14 ? "passed" : "not passed");
    }
int main() {
    runTests();
    printf("\n");

    int n;
    printf("Введите длину двоичного числа (N <= 32): ");
    scanf("%d", &n);

    if (n <= 0 || n > 32) {
        printf("Ошибка: N должно быть от 1 до 32\n");
        return 1;
    }

    bool bits[32];
    printf("Введите %d битов (0 или 1 через пробел):\n", n);

    for (int i = 0; i < n; i++) {
        int bit;
        scanf("%d", &bit);
        if (bit != 0 && bit != 1) {
            printf("Ошибка: введите 0 или 1\n");
            i--;
            continue;
        }
        bits[i] = (bit == 1);
    }

    unsigned int decimal = boolArrayToInt(bits, n);
    unsigned int result = maxRotation(bits, n);

    printf("\nВведенное число: ");
    for (int i = 0; i < n; i++) {
        printf("%d", bits[i]);
    }
    printf(" = %u\n", decimal);

    printf("Максимальное число после сдвигов: %u\n", result);

    return 0;
}
