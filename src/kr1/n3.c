#include <stdbool.h>
#include <stdio.h>

bool isBinaryPalindrome(int n)
{
    int highBit = 0;
    int temp = n;

    while (temp > 0) {
        highBit++;
        temp >>= 1;
    }

    for (int i = 0; i < highBit / 2; i++) {
        int leftBit = (n >> (highBit - 1 - i)) & 1;
        int rightBit = (n >> i) & 1;
        if (leftBit != rightBit)
            return false;
    }

    return true;
}

int main()
{
    int n;

    printf("Введите n: ");
    scanf("%d", &n);

    printf("Палиндромы [1; %d]: ", n);

    for (int i = 1; i <= n; i++) {
        if (isBinaryPalindrome(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
