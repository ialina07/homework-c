#include "josephus.h"
#include <stdio.h>

int main()
{
    int n, m;

    printf("Введите количество воинов (n): ");
    scanf("%d", &n);

    printf("Введите шаг убийства (m): ");
    scanf("%d", &m);

    if (n <= 0 || m <= 0) {
        printf("Ошибка: n и m должны быть положительными числами\n");
        return 1;
    }

    int survivor = josephus(n, m);
    printf("Последним останется воин на позиции: %d\n", survivor);

    return 0;
}
