#include "dv.h"
#include <stdint.h>
#include <stdio.h>

// Функция для преобразования числа в двоичное представление в дополнительном коде
void toTwosComplement(int num, char* binary)
{
    if (num >= 0) {
        // Положительное число - прямое представление
        for (int i = 7; i >= 0; i--) {
            binary[7 - i] = ((num >> i) & 1) ? '1' : '0';
        }
    } else {
        // Отрицательное число - дополнительный код
        uint8_t twosComp = (uint8_t)(256 + num); // Для -128: 256 + (-128) = 128

        for (int i = 7; i >= 0; i--) {
            binary[7 - i] = ((twosComp >> i) & 1) ? '1' : '0';
        }
    }
    binary[8] = '\0';
}

// Функция для преобразования двоичного дополнительного кода в число
int fromTwosComplement(const char* binary)
{
    int result = 0;

    // Если старший бит = 1, число отрицательное
    if (binary[0] == '1') {
        // Инвертируем все биты
        uint8_t inverted = 0;
        for (int i = 0; i < 8; i++) {
            inverted <<= 1;
            inverted |= (binary[i] == '0') ? 1 : 0;
        }

        // Прибавляем 1 и берем с отрицательным знаком
        result = -(int)(inverted + 1);
    } else {
        // Положительное число - прямое преобразование
        for (int i = 0; i < 8; i++) {
            result <<= 1;
            result |= (binary[i] == '1') ? 1 : 0;
        }
    }

    return result;
}

// Функция для сложения двух двоичных чисел
void binaryAddition(const char* bin1, const char* bin2, char* result)
{
    int carry = 0;

    // Складываем с младших разрядов
    for (int i = 7; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';

        int sum = bit1 + bit2 + carry;
        result[i] = (sum % 2) + '0';
        carry = sum / 2;
    }
    result[8] = '\0';
}
