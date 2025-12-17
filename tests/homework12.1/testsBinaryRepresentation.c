#include "dv.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// тестовые функции

void testPositiveNumbers()
{
    printf("1. Тест положительных чисел:\n");

    char binary[9];

    // 0
    toTwosComplement(0, binary);
    assert(strcmp(binary, "00000000") == 0);
    assert(fromTwosComplement(binary) == 0);
    printf(" 0 -> 00000000 -> 0\n");

    // 5
    toTwosComplement(5, binary);
    assert(strcmp(binary, "00000101") == 0);
    assert(fromTwosComplement(binary) == 5);
    printf(" 5 -> 00000101 -> 5\n");

    // 127 (максимальное положительное)
    toTwosComplement(127, binary);
    assert(strcmp(binary, "01111111") == 0);
    assert(fromTwosComplement(binary) == 127);
    printf(" 127 -> 01111111 -> 127\n");
}

void testNegativeNumbers()
{
    printf("\n2. Тест отрицательных чисел:\n");

    char binary[9];

    // -1
    toTwosComplement(-1, binary);
    assert(strcmp(binary, "11111111") == 0);
    assert(fromTwosComplement(binary) == -1);
    printf(" -1 -> 11111111 -> -1\n");

    // -5
    toTwosComplement(-5, binary);
    assert(strcmp(binary, "11111011") == 0);
    assert(fromTwosComplement(binary) == -5);
    printf(" -5 -> 11111011 -> -5\n");

    // -128 (минимальное)
    toTwosComplement(-128, binary);
    assert(strcmp(binary, "10000000") == 0);
    assert(fromTwosComplement(binary) == -128);
    printf(" -128 -> 10000000 -> -128\n");

    // -127
    toTwosComplement(-127, binary);
    assert(strcmp(binary, "10000001") == 0);
    assert(fromTwosComplement(binary) == -127);
    printf(" -127 -> 10000001 -> -127\n");
}

void testAddition()
{
    printf("\n3. Тест сложения:\n");

    char bin1[9], bin2[9], sum[9];

    // 5 + 3 = 8
    toTwosComplement(5, bin1);
    toTwosComplement(3, bin2);
    binaryAddition(bin1, bin2, sum);
    assert(fromTwosComplement(sum) == 8);
    printf(" 5 + 3 = 8\n");

    // 10 + (-3) = 7
    toTwosComplement(10, bin1);
    toTwosComplement(-3, bin2);
    binaryAddition(bin1, bin2, sum);
    assert(fromTwosComplement(sum) == 7);
    printf(" 10 + (-3) = 7\n");

    // (-5) + (-3) = -8
    toTwosComplement(-5, bin1);
    toTwosComplement(-3, bin2);
    binaryAddition(bin1, bin2, sum);
    assert(fromTwosComplement(sum) == -8);
    printf(" (-5) + (-3) = -8\n");

    // 127 + 1 = -128 (переполнение)
    toTwosComplement(127, bin1);
    toTwosComplement(1, bin2);
    binaryAddition(bin1, bin2, sum);
    assert(fromTwosComplement(sum) == -128);
    printf(" 127 + 1 = -128 (переполнение)\n");

    // (-128) + (-1) = 127 (переполнение)
    toTwosComplement(-128, bin1);
    toTwosComplement(-1, bin2);
    binaryAddition(bin1, bin2, sum);
    assert(fromTwosComplement(sum) == 127);
    printf(" (-128) + (-1) = 127 (переполнение)\n");
}

void testRoundTrip()
{
    printf("\n4. Тест преобразования туда-обратно:\n");

    char binary[9];
    int passed = 0;

    // Тестируем все 256 значений
    for (int i = -128; i <= 127; i++) {
        toTwosComplement(i, binary);
        int back = fromTwosComplement(binary);
        if (back != i) {
            printf("Ошибка: %d -> %s -> %d\n", i, binary, back);
            assert(0);
        }
        passed++;
    }
    printf("Все %d значений пройдены\n", passed);
}

int main()
{
    printf("\n\n");

    testPositiveNumbers();
    testNegativeNumbers();
    testAddition();
    testRoundTrip();

    printf("\nВсе тесты продены!\n");
    return 0;
}
