int main()
{
    int firstNumber, secondNumber;
    char firstBinary[9], secondBinary[9], sumBinary[9];

    // Ввод чисел
    printf("Введите первое число (от -128 до 127): ");
    scanf("%d", &firstNumber);
    printf("Введите второе число (от -128 до 127): ");
    scanf("%d", &secondNumber);

    // Проверка диапазона
    if (firstNumber < -128 || firstNumber > 127 || secondNumber < -128 || secondNumber > 127) {
        printf("Ошибка: числа должны быть в диапазоне от -128 до 127\n");
        return 1;
    }

    // Преобразование в двоичный вид
    toTwosComplement(firstNumber, firstBinary);
    toTwosComplement(secondNumber, secondBinary);

    printf("\nПервое число в двоичном дополнительном коде: %s\n", firstBinary);
    printf("Второе число в двоичном дополнительном коде: %s\n", secondBinary);

    // Сложение в двоичном виде
    binaryAddition(firstBinary, secondBinary, sumBinary);
    printf("Сумма в двоичном виде: %s\n", sumBinary);

    // Преобразование обратно в десятичное
    int decimalSum = fromTwosComplement(sumBinary);
    printf("Сумма в десятичном виде: %d\n", decimalSum);

    return 0;
}
