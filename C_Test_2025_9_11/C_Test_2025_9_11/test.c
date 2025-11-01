#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//乘法

//int main() {
//	int x = 0;
//	scanf("%d", &x);
//	printf("%d", 100 * x);
//}

//除法和求余

//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d %d", a / b, a % b);
//}

//求个位数

//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d", a % 10);
//}

//求十位数

//int main() {
//	int a = 0;
//	scanf("%d", &a);
//	printf("%d", (a / 10) % 10);
//}

//求星期

//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    int c = a + b;
//    while (c > 7)
//    {
//        c = c - 7;
//    }
//    printf("%d", c);
//}

//时间转换

//int main() {
//    int a;
//    scanf("%d", &a);
//    printf("%d", a / 3600);
//    a = a % 3600;
//    printf(" %d", a / 60);
//    a = a % 60;
//    printf(" %d", a);
//}

//2的n次方

//int main() {
//    int a;
//    int n = 2;
//    scanf("%d", &a);
//    while (--a)
//    {
//        n = n * 2;
//    }
//    printf("%d", n);
//}

//活了多少秒

//int main() {
//    size_t a;
//    scanf("%d", &a);
//    printf("%zu", a * 31560000);
//}

//统计成绩

//#include <stdlib.h>
//
//int cmp(void* a, void* b)
//{
//    return (*(double*)a) - (*(double*)b);
//}
//
//int main() {
//    int n = 0;
//    double arr[100];
//    double m = 0;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%lf", arr + i);
//    }
//    qsort(arr, n, sizeof(arr[0]), cmp);
//    for (int i = 0; i < n; i++)
//    {
//        m = m + arr[i];
//    }
//    printf("%.2lf %.2lf %.2lf", arr[n - 1], arr[0], m / n);
//}

//求周长和面积

#include <math.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("circumference=%.2lf", a + b + c);
    double p = (a + b + c) / 2;
    double S = p * (p - a) * (p - b) * (p - c);
    double r = sqrt(S);
    printf(" area=%.2lf", r);
}