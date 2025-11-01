#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("********************\n");
	printf("*******1.play*******\n");
	printf("*******0.exit*******\n");
	printf("********************\n");
	printf("请选择->");
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	int n = 0;
again2:
	menu();
again:
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		n = 100 + rand() % (200 - 100 + 1);
		while (1)
		{
			int a = 0;
			printf("猜数字->");
			scanf("%d", &a);
			if (a > n)
				printf("大了\n");
			if (a < n)
				printf("小了\n");
			if (a == n)
			{
				printf("猜对了\n");
				goto again2;
			}
		}
		break;
	case 0:break;
	default:
		printf("选择错误\n");
		printf("重新选择->");
		goto again;
	}
	return 0;
}