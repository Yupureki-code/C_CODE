#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//二维数组元素的倒置
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int a = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for (int i = 9; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			a = arr[9-j];
//			arr[9-j] = arr[8-j];
//			arr[8-j] = a;
//		}
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//
//
//	return 0;
//}
//两个数组的合并并正序排列
//int cmp(const void* x, const void* y)
//{
//    return *(int*)x - *(int*)y;
//}
//int main()
//{
//    int arr1[10];
//    int arr2[10];
//    int tmp[20];
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", arr1 + i);
//    }
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d", arr2 + i);
//    }
//    for (int i = 0; i < n + m; i++)
//    {
//        if (i < n)
//        {
//            tmp[i] = arr1[i];
//        }
//        else
//        {
//            tmp[i] = arr2[i - n];
//        }
//    }
//    qsort(tmp, n+m, sizeof(tmp[0]), cmp);
//    for (int i = 0; i < n + m; i++)
//    {
//        printf("%d ", tmp[i]);
//    }
//    return 0;
//}
//打印正方形
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (i == 1 || i == n || j == 1 || j == n)
//			{
//				printf("* ");
//			}
//			else
//			{
//				printf("  ");
//			}
//
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}
//数组元素的总和
/*int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int r = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", arr + i);
		r = r + arr[i];
	}
	printf("%d", r / 10);
	return 0;
}*/
//两个相同数量元素的数组的交换
//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9.10 };
//	int arr2[10] = { 11,12,13,14,15,16,17,18,19,20 };
//	int a = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		a = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = a;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//
//	return 0;
//}
//二分查找
//int bin_search(int arr[], int left, int right, int key)
//{
//	while (left<=right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] == key)
//			return mid;
//		if (arr[mid] > key)
//			right = mid - 1;
//		else
//			left = mid + 1;
//	}
//	return -1;
//}
//int main()
//{
//	int arr[10] = {1,2,4,8,10,23,28,30,34,50};
//	int n = 15;
//	scanf("%d", &n);
//	int r = bin_search(arr,0,9,n);
//	if (r == -1)
//		printf("不存在");
//	else
//		printf("第%d位", r + 1);
//}
//打印n的乘法表
//int main()
//{
//	int n = 0;
//	scanf("%d", &n); 
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//			printf("%d*%d=%d ", j, i, i * j);
//		printf("\n");
//	}
//
//	return 0;
//}
// 
//判断year是否为闰年
//int main()
//{
//	int year = 0;
//	scanf("%d", &year);
//	if (year % 4 == 0)
//	{
//		if (year % 100 == 0)
//		{
//			if (year % 400 == 0)
//				printf("yes");
//			else
//				printf("no");
//		}
//		else
//		{
//			printf("yes");
//		}
//	}
//	return 0;
//}
//void is_prime(a, b)
//{
//	for (int i = a; i <= b; i++)
//	{
//		for (int j = 2; j < i; j++)
//		{
//			if (i % j == 0)
//				break;
//			if (j == i - 1)
//				printf("%d ", i);
//		}
//
//	}
//}
//int main()
//{
//	is_prime(100, 200);
//	return 0;
//}
// 
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void reverse(int* arr, int sz)
{
	int a = 0;
	for (int i = sz - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			a = arr[sz - 1 - j];
			arr[sz - 1 - j] = arr[sz - 2 - j];
			arr[sz - 2 - j] = a;
		}
	}
}
void init(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
		*(arr + i) = 0;
}
int  main()
{
	int arr[10] = { 1,7,2,6,3,9,4,8,5,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	init(arr, sz);
	print(arr, sz);
	return 0;
}