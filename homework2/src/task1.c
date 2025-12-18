#include <stdio.h>
int main()
{
    float x;
    printf("input x: ");
    scanf("%f", &x);

    float x2 = x * x; // first multiplication
    float res = (x2 + x) * (x2 + 1) + 1; // second multiplication
    printf("result: %f\n", res);
    return 0;
}
