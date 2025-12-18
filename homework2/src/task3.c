#include <stdio.h>

int main()
{
    int m = 3;
    int n = 2;
    int arr[] = { 1, 2, 3, 4, 5 };
    int total = m + n;
    printf("Before: ");
    for (int i = 0; i < total; i++) {
        printf("%d", arr[i]);
    }

    for (int i = 0; i < m; i++) {
        int temp = arr[0];

        // shift all elements to the left by 1
        for (int j = 0; j < total - 1; j++) {
            arr[j] = arr[j + 1];
        }

        // putting the saved element at the end
        arr[total - 1] = temp;
    }

    printf("\nAfter: ");
    for (int i = 0; i < total; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
