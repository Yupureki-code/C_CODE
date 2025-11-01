#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//1005
int cmp(void* a, void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int arr[100] = { 0 };
    int n = 0;
    scanf("%d", &n);
    int n1 = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int i = 0;
    while (n1--)
    {
        if (arr[i] == 0)
        {
            i++;
            continue;
        }
        int tmp = *(arr + i);
        while (tmp != 1)
        {
            if (tmp % 2 == 0)
            {
                tmp = tmp / 2;
            }
            else
            {
                tmp = (3 * tmp + 1) / 2;
            }
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == tmp)
                {
                    arr[j] = 0;
                    break;
                }
            }
        }
        i++;
    }
    qsort(arr, n, sizeof(int), cmp);
    i--;
    while (*(arr + i) != 0)
    {
        printf("%d", arr[i]);
        i--;
        if (*(arr + i) != 0)
            printf(" ");
    }
}

//1006
int main()
{
    int n = 0;
    scanf("%d", &n);
    char arr[4] = { 0 };
    sprintf(arr, "%d", n);
    int len = strlen(arr);
    char* tmp = arr;
    while (*tmp != '\0')
    {
        int a = *tmp - '0';
        switch (len)
        {
        case 3:
            while (a--)
                printf("B");
            break;
        case 2:
            while (a--)
                printf("S");
            break;
        case 1:
            for (int i = 1; i <= a; i++)
                printf("%d", i);
            break;
        }
        len--;
        tmp++;
    }
    return 0;
}
