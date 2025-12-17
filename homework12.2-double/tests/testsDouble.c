#include "double_exponential.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

void testZero()
{
    printf("0: ");
    printDoubleExponential(0.0);
    // Ожидается: +0.0*2^0 или -0.0*2^0
    printf("\n");
}

void testOne()
{
    printf("1: ");
    printDoubleExponential(1.0);
    // Ожидается: +1.0*2^0
    printf("\n");
}

void testMinusTwoPointFive()
{
    printf("-2.5: ");
    printDoubleExponential(-2.5);
    // Ожидается: -1.25*2^1 (пример из задания)
    printf("\n");
}

void testExampleFromTask()
{
    printf("12312.323: ");
    printDoubleExponential(12312.323);
    // Ожидается: +1.5029691162109375384*2^13 (пример из задания
    printf("\n");
}

void testPowerOfTwo()
{
    printf("8 (2^3): ");
    printDoubleExponential(8.0);
    // Ожидается: +1.0*2^3
    printf("\n");

    printf("0.125 (2^-3): ");
    printDoubleExponential(0.125);
    // Ожидается: +1.0*2^-3
    printf("\n");
}

void testNormalization()
{
    // Проверка нормализации
    printf("3.0: ");
    printDoubleExponential(3.0);
    // 3 = 1.5 * 2^1, ожидается: +1.5*2^1
    printf("\n");

    printf("0.75: ");
    printDoubleExponential(0.75);
    // 0.75 = 1.5 * 2^-1, ожидается: +1.5*2^-1
    printf("\n");
}

int main()
{
    printf("Тестирование\n\n");

    printf("Примеры из задания:\n");
    testMinusTwoPointFive();
    testExampleFromTask();

    printf("\nБазовые числа:\n");
    testZero();
    testOne();
    testPowerOfTwo();
    testNormalization();

    printf("\nТесты завершены\n");
    return 0;
}
