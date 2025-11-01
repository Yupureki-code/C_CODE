#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//文件操作

struct stu {
	int age;
	char name[20];
	float score;
}s;
int main()
{
	char str1[100] = { 0 };
	char str2[100] = {0};
	sprintf(str1, "%d %s %f", 18, "zhangsan", 60.0f);
	sscanf(str1, "%d %s  %f", & s.age, s.name, &s.score);
	printf("%d %s  %f\n", s.age, s.name, s.score);
	fprintf(stdout, "%s", str2);
	printf("\n");
	FILE* pf1 = fopen("data.txt","w");
	if (pf1 == NULL)
	{
		perror("fopen");
		return 1;
	}

	fprintf(pf1, "%d %s %f",s.age,s.name,s.score);
	fclose(pf1);
	FILE* pf2 = fopen("data.txt", "r");
	if (pf2 == NULL)
	{
		perror("fopen");
		return 1;
	}
	int age = 0;
	char name[20] = {0};
	float score;
	fscanf(pf2, "%d %s %f", &age, name, &score);
	printf("%d %s  %f\n", age,name,score);
	fclose(pf2);
	FILE* pf3 = fopen("data.txt", "w");
	if (pf3 == NULL)
	{
		perror("fopen");
		return 1;
	}
	fprintf(pf3, "hello bit");
	fclose(pf3);
	FILE* pf4 = fopen("data.txt", "r");
	if (pf4 == NULL)
	{
		perror("fopen");
		return 1;
	}
	char arr[20] = { 0 };
	fgets(arr, 21, pf4);
	fputs(arr, stdout);
	return 0;
}

//int main()
//{
//	FILE* pf1 = fopen("data.txt", "w");
//	if (pf1 == NULL)
//	{
//		perror("fpoen");
//		return 1;
//	}
//	fprintf(pf1, "hello bit");
//	fclose(pf1);
//	FILE* pf2 = fopen("data.txt", "r");
//	if (pf2 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char arr[20];
//	fgets(arr, 21, pf2);
//	printf("%s\n", arr);
//	fclose(pf2);
//	FILE* pf3 = fopen("data_copy.txt", "w");
//	if (pf3 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf3, "%s\n", arr);
//	fclose(pf3);
//	FILE* pf4 = fopen("data_copy.txt", "r");
//	if (pf4 == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char arr2[20];
//	fgets(arr2, 21, pf4);
//	printf("%s\n", arr2);
//	fclose(pf4);
//	return 0;
//}

//offsetof宏

//#define offsetof(name,member)  ((char*)&(name.member) - (char*)&name)
//
//struct stu {
//	char name[15];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct stu s = { {"zhangsan"},18,65.5 };
//	size_t n = offsetof(s,age);
//	printf("%d\n", n);
//	printf("%d\n", (size_t)((char*) & s.age - (char*) & s));
//	return 0;
//}

//交换奇偶位

//#define change(n) (n = ((n)^(-1)));
//
//int main()
//{
//	int n = 11;//1011
//	change(n);
//	printf("%zd", n);
//	return 0;
//
//
//}

//模拟实现atoi

//int my_atoi(const char* str)
//{
//	int len = 0;
//	int r = 0;
//	int n = 0;
//	while (*(str + len))
//		len++;
//	for (int i = len; i > 0; i--)
//	{
//		n = *str - '0';
//		int a = 1;
//		for (int j = 1; j < i; j++)
//			a = a * 10;
//		r = r + n * a;
//		str++;
//	}
//	return r;
//}
//
//int main()
//{
//	char* p = "1234";
//	int n = my_atoi(p);
//	printf("%d",n);
//	return 0;
//}

//内存函数使用

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int* p1 = (int*)calloc(10, sizeof(int));
//	if (p1 == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		p1[i] = arr[i];
//		printf("%d ",p1[i]);
//	}
//	printf("\n");
//	free(p1);
//	p1 = NULL;
//	char str[] = "hello bit";
//	char* p2 = (char*)malloc(sizeof(str));
//	if (p2 == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	strcpy(p2, str);
//	printf("%s\n", p2);
//	char* p = NULL;
//	p = (char*)realloc(p2, sizeof("hello world"));
//	if (p == NULL)
//	{
//		perror("realloc");
//		return 1;
//	}
//	p2 = p;
//	strcpy(p2, "hello world");
//	printf("%s\n", p2);
//	free(p2);
//	p2 = NULL;
//	return 0;
//}

//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	int (*p)[5] = (int (*)[5])calloc(3,sizeof(int[5]));
//	if (p == NULL)
//	{
//		perror("calloc");
//		return 1;
//	}
//	memcpy(p, arr,sizeof(arr));
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j< 5; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

