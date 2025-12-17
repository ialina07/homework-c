#include "double.h"
#include <stdio.h>

void printDoubleExponential(double num)
{
    DoubleUnion du;
    du.value = num;

    // Извлекаем биты
    uint64_t bits = du.bits;

    // Знак (1 бит)
    int sign = (bits >> 63) & 1;

    // Порядок (11 бит)
    int exponent = (bits >> 52) & 0x7FF;

    // Мантисса (52 бита)
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    // Обработка специальных случаев
    if (exponent == 0x7FF) {
        if (mantissa == 0) {
            printf("%cINF", sign ? '-' : '+');
        } else {
            printf("NaN");
        }
        return;
    }

    // Денормализованные числа
    if (exponent == 0) {
        if (mantissa == 0) {
            printf("%c0.0*2^0", sign ? '-' : '+');
            return;
        }
        // Для денормализованных чисел экспонента = -1022
        exponent = -1022;
        // Мантисса без неявной ведущей 1
    } else {
        // Нормализованные числа - добавляем неявную ведущую 1
        mantissa |= (1ULL << 52);
        exponent -= 1023; // Смещение экспоненты
    }

    // Выводим знак
    printf("%c", sign ? '-' : '+');

    // Вычисляем и выводим мантиссу как double
    double m = (double)mantissa / (1ULL << 52);

    // Выводим с высокой точностью
    printf("%.20f*2^%d", m, exponent);
}
