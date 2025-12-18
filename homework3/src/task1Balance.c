#include <stdio.h>
#include <string.h>

int main()
{
    int balance = 0;
    char origString[100];
    printf("введите строку: ");
    scanf("%99s", origString);

    int l = strlen(origString);
    for (int i = 0; i < l; i++) {
        char s = origString[i];

        if (s == '(')
            balance++;
        if (s == ')')
            balance--;

        if (balance < 0) {
            printf("не выполняется правило вложенности скобок\n");
            return 0;
        }
    }

    if (balance != 0) {
        printf("не выполняется правило вложенности скобок\n");
        return 0;
    }

    printf("баланс скобок соблюдается\n");
    return 0;
}
