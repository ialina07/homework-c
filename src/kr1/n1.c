#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

int sumNumbers(int a);

int main()
{
    int m[MAX_SIZE];
    int n;
    printf("Введите длину массива: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Неверный размер массива!\n");
        return 1;
    }

    printf("Введите %d элементов\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", &m[i]);
    }

    int mx = -1; // Максимальная сумма цифр
    int ch = m[0]; // Число с максимальной суммой цифр

    for (int i = 0; i < n; i++) {
        int currentSum = sumNumbers(m[i]);
        if (currentSum > mx) {
            mx = currentSum;
            ch = m[i];
        }
    }

    printf("Число с максимальной суммой цифр: %d (сумма цифр: %d)\n", ch, mx);
    return 0;
}

int sumNumbers(int a)
{
    int res = 0;
    char s[20];

    // Работаем с абсолютным значением числа
    int n = a < 0 ? -a : a;

    // Преобразуем число в строку
    sprintf(s, "%d", n);
    int len = strlen(s);

    // Суммируем цифры
    for (int i = 0; i < len; i++) {
        res = res + (s[i] - '0');
    }

    return res;
}
