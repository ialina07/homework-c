#include <stdio.h>

int main()
{
    // Создаем массив для подсчета количества троек цифр с каждой возможной суммой (от 0 до 27)
    int count[28] = { 0 }; // 0..27

    // Подсчитываем, сколько троек цифр имеют каждую возможную сумму
    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            for (int c = 0; c <= 9; c++) {
                int sum = a + b + c;
                count[sum]++;
            }
        }
    }

    // Суммируем квадраты количеств троек для каждой возможной суммы
    int happyTickets = 0;
    for (int sum = 0; sum <= 27; sum++) {
        happyTickets += count[sum] * count[sum];
    }

    printf("count of happy tickets: %d\n", happyTickets);
    return 0;
}
