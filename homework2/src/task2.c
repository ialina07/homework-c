#include <stdio.h>
#include <stdlib.h> //for abs()
int main()
{
    int a, b, q = 0;
    printf("input divisible ");
    scanf("%d", &a);

    printf("input divider ");
    scanf("%d", &b);

    if (b == 0) {
        printf("error!\n");
        return 1;
    }

    int s = 1;
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        s = -1;
    }

    int abs_a = abs(a);
    int abs_b = abs(b);

    while (abs_a >= abs_b) {
        abs_a = abs_a - abs_b;
        q++;
    }

    q *= s;

    if (abs_a == 0)
        printf("doesnt match the task condition\n");
    else
        printf("incomplete quotient of deviding %d by %d = %d\n", a, b, q);
    return 0;
}
