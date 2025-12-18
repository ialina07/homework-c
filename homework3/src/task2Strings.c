#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char s1[100];

    printf("input string s: ");
    scanf("%99s", s);

    printf("input substring s1: ");
    scanf("%99s", s1);

    int count = 0;
    int sLength = strlen(s);
    int s1Length = strlen(s1);

    if (s1Length == 0 || s1Length > sLength) {
        printf("number of occurrences: %d\n", count);
        return 0;
    }

    for (int i = 0; i <= sLength - s1Length; i++) {
        int found = 1;

        for (int j = 0; j < s1Length; j++) {
            if (s[i + j] != s1[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            count++;
        }
    }

    printf("number of occurrences '%s' in '%s': %d\n", s1, s, count);
    return 0;
}
