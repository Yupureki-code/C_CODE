#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
//打印斐波那契数列

//int test1(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	while (n >= 3)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int test2(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 1;
//	return test2(n - 1) + test2(n - 2);
//}
//
//int main()
//{
//	int n = 20;
//	scanf("%d", &n);
//	printf("%d\n", test1(n));
//	printf("%d\n", test2(n));
//}

//递归实现n的k次方

//int fun(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * fun(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", fun(n));
//}


//计算一个数的每位之和（递归实现）

//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return n%10 +DigitSum(n / 10);
//	}
//	return n;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//
//	return 0;
//}

//递归和非递归分别实现求n的阶乘

//int fun1(int n)
//{
//	int r = 1;
//	while (n > 0)
//	{
//		r = r * n;
//		n--;
//	}
//	return r;
//}
//
//int fun2(int n)
//{
//	if (n == 1)
//		return 1;
//	return n * fun2(n - 1);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", fun1(n));
//	printf("%d\n", fun2(n));
//
//	return 0;
//}

//递归方式实现打印一个整数的每一位

//void fun(int n)
//{
//	if (n > 9)
//	{
//		fun(n / 10);
//		printf("%d ", n % 10);
//	}
//	else
//		printf("%d ", n);
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	fun(n);
//
//	return 0;
//}

//交换两个变量（不创建临时变量）

//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d %d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//
//	return 0;
//}

//统计二进制中1的个数
//int main()
//{
//	int n = 0;
//	while (scanf("%d", &n) != EOF)
//	{
//		int count = 0;
//		int a = 1;
//		while (n)
//		{
//			if (n & a == a)
//			{
//				count++;
//			}
//			 n =n >> 1;
//		}
//		printf("%d\n", count);
//	}
//}

//输入两个整数，求两个整数二进制格式有多少个位不同
//int main() {
//	int a, b = 0;
//	scanf("%d %d", &a, &b);
//	int n = a ^ b;
//	int count = 0;
//	while (n)
//	{
//		if (n & 1 == 1)
//		{
//			count++;
//		}
//		n =n >> 1;
//	}
//	printf("%d", count);
//}

//在一个整型数组中，只有一个数字出现一次，其他数组都是成对出现的，请找出那个只出现一次的数字。
//int main()
//{
//	int arr[9] = {1, 2, 3, 4, 5, 1, 2, 3, 4};
//	int r = 0;
//	for (int i = 0; i < 9; i++)
//	{
//		for (int j = 0; j < 9; j++)
//		{
//			if (arr[i] == arr[j] && i!=j)
//			{
//				r = 1;
//				break;
//			}
//		}
//		if (r == 0)
//			printf("%d ", arr[i]);
//		r = 0;
//	}
//
//	return 0;
//}

//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

//int main()
//{
//	int n = 15;
//	scanf("%d", &n);
//	int n1 = n;
//	for (int i = 1; 2 * i <= 32; i++)
//	{
//		printf("%d ", n1 & 1);
//		n1 = n1 >> 2 * i;
//	}
//	n1 = n;
//	printf("\n");
//	for (int i = 0; 2 * i + 1<= 32; i++)
//	{
//		printf("%d ", n1 & 1);
//		n1 = n1 >> 2 * i + 1 ;
//	}
//
//	return 0;
//}

//字符串逆序

//int main() {
//    char arr[10000];
//    char a = 0;
//    fgets(arr, sizeof(arr), stdin);
//    int sz = strlen(arr);
//    for (int i = 0; i < sz / 2; i++)
//    {
//        a = arr[i];
//        arr[i] = arr[sz - i - 1];
//        arr[sz - i - 1] = a;
//    }
//    printf("%s ", arr);
//}

//实现一个函数，可以左旋字符串中的k个字符。

//int main() {
//    char arr[10000];
//    int n = 0;
//    char a = 0;
//    fgets(arr, sizeof(arr), stdin);
//    scanf("%d", &n);
//    int sz = strlen(arr);
//    for (int i = 0; i < n; i++)
//    {
//        a = arr[i];
//        arr[i] = arr[sz - i - 1];
//        arr[sz - i - 1] = a;
//    }
//    printf("%s ", arr);
//}

//模拟实现库函数strlen

//int my_strlen(char str[])
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%99[^\n]", str);
//	int n = my_strlen(str);
//	printf("%d", n);
//	return 0;
//}

//调整奇数偶数顺序

void fun(int arr[], int sz)
{
	int tmp[20];
	int n = 0;
	memcpy(tmp, arr, sz*sizeof(arr));
	for (int i = 0; i < sz; i++)
	{
		if (tmp[i] % 2 != 0)
		{
			arr[n] = tmp[i];
			n++;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (tmp[i] % 2 == 0)
		{
			arr[n] = tmp[i];
			n++;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	fun(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}