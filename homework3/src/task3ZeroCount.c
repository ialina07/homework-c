#include <stdio.h>

#define MAXSIZE 100

int main()
{
    int arr[MAXSIZE];
    int n;
    printf("input the size of the array (no more than %d): ", MAXSIZE);
    scanf("%d", &n);

    if (n <= 0 || n > MAXSIZE) {
        printf("incorrect array size!");
        return 1;
    }

    printf("input %d elemens\n", n);

    for (int i = 0; i < n; i++) {
        printf("element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int zeroCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            zeroCount++;
    }
    printf("the number of zero elements in the array is %d\n", zeroCount);
    return 0;
}
