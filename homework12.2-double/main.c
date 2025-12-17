#include "double.h"
#include <stdio.h>

int main()
{
    double number;

    printf("Enter a number: ");
    scanf("%lf", &number);

    printf("Result: ");
    printDoubleExponential(number);

    return 0;
}
