#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//求最大值

//int cmp(void* a, void* b)
//{
//    return *((int*)a) - *((int*)b);
//}
//
//int main() {
//    int arr[4];
//    for (int i = 0; i < 4; i++)
//    {
//        scanf("%d", arr + i);
//    }
//    qsort(arr, 4, sizeof(arr[0]), cmp);
//    printf("%d", arr[3]);
//}

//判断字母

//int main() {
//    char a;
//    while (scanf("%c\n", &a) != EOF) {
//        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'z'))
//        {
//            printf("%c is an alphabet.\n", a);
//        }
//        else {
//            printf("%c is not an alphabet.\n", a);
//        }
//    }
//    return 0;
//}

//237整除

//int main() {
//    int a = 0;
//    scanf("%d", &a);
//    if (a % 2 == 0)
//    {
//        printf("2 ");
//    }
//    if (a % 3 == 0)
//    {
//        printf("3 ");
//    }
//    if (a % 7 == 0)
//    {
//        printf("7 ");
//    }
//    if (a % 2 != 0 && a % 3 != 0 && a % 7 != 0)
//    {
//        printf("n");
//    }
//}

//正负个数

//int main() {
//    int arr[10];
//    int a = 0;
//    int b = 0;
//    for (int i = 0; i < 10; i++)
//    {
//        scanf("%d", arr + i);
//        if (*(arr + i) > 0)
//        {
//            a++;
//        }
//        else if (*(arr + i) < 0)
//        {
//            b++;
//        }
//    }
//    printf("positive:%d\n", a);
//    printf("negative:%d\n", b);
//}

//网购

int main() {
    float a = 0;
    int b, c, d;
    scanf("%f %d %d %d", &a, &b, &c, &d);
    if (b == 11 && c == 11)
    {
        a = a * 0.7;
    }
    else if (b == 12 && c == 12)
    {
        a = a * 0.8;
    }
    if (d == 1)
    {
        a = a - 50;
    }
    if (a < 0)
    {
        a = 0;
    }
    printf("%.2f", a);
}
