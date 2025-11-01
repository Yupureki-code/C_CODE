#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//1010
int main()
{
    char arr[81] = { 0 };
    char str[81] = { 0 };
    scanf("%[^\n]", arr);
    int i = 0;
    char* tmp;
    while (*(arr + i) != '\0')
    {
        if (*(arr + i) == ' ')
        {
            *(arr + i) = '\0';
        }
        i++;
    }
    i--;
    int len = 0;
    for (; i >= 0; i--)
    {
        if (*(arr + i) == '\0')
        {
            tmp = arr + i + 1;
            strcpy(str + len, tmp);
            len = len + strlen(tmp) + 1;
            str[len - 1] = ' ';
        }
        if (i == 0)
        {
            strcpy(str + len, arr);
        }
    }
    printf("%s", str);
    return 0;
}
//1011
int main()
{
    int n = 0;
    scanf("%d", &n);
    long long a, b, c;
    int count = 1;
    while (n--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a + b > c)
        {
            printf("Case #%d: true\n", count);
        }
        else
        {
            printf("Case #%d: false\n", count);
        }
        count++;
        a = 0;
        b = 0;
        c = 0;
    }
    return 0;
}
//1012
#include <stdlib.h>

int main() {
    int n = 0;
    int A1 = 0;
    int A2 = 0;
    int A3 = 0;
    float A4 = 0;
    int A4Count = 0;
    int A5 = 0;
    int r = 0;
    int hasA1 = 0, hasA2 = 0, hasA3 = 0, hasA4 = 0, hasA5 = 0;

    scanf("%d", &n);
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        int num = arr[i];
        if (num % 5 == 0 && num % 2 == 0) {
            A1 += num;
            hasA1 = 1;
        }
        else if (num % 5 == 1) {
            if (r == 0) {
                A2 += num;
                r = 1;
            }
            else {
                A2 -= num;
                r = 0;
            }
            hasA2 = 1;
        }
        else if (num % 5 == 2) {
            A3++;
            hasA3 = 1;
        }
        else if (num % 5 == 3) {
            A4 += num;
            A4Count++;
            hasA4 = 1;
        }
        else if (num % 5 == 4) {
            if (num > A5) {
                A5 = num;
            }
            hasA5 = 1;
        }
    }

    if (hasA1) {
        printf("%d", A1);
    }
    else {
        printf("N");
    }
    if (hasA2) {
        printf(" %d", A2);
    }
    else {
        printf(" N");
    }
    if (hasA3) {
        printf(" %d", A3);
    }
    else {
        printf(" N");
    }
    if (hasA4) {
        printf(" %.1f", A4 / A4Count);
    }
    else {
        printf(" N");
    }
    if (hasA5) {
        printf(" %d", A5);
    }
    else {
        printf(" N");
    }

    free(arr);
    return 0;
}