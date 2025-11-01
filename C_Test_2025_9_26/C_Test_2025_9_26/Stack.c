#include "Stack.h"
#define  _CRT_SECURE_NO_WARNINGS 1

void StackInit(Stack* ps)
{
	ps->data = malloc(sizeof(STDataType) * 4);
	ps->size = 0;
	ps->capacity = 4;
}

void StackCheck(Stack* ps)
{
	if (ps->capacity == ps->size)
	{
		size_t newcapacity = ps->capacity * 2;
		ps->data = realloc(ps->data, sizeof(STDataType) * newcapacity);
		assert(ps->data);
	}
}


void StackPush(Stack* ps, STDataType data)
{
	StackCheck(ps);
	printf("请输入数字->");
	size_t num = 0;
	scanf("%d", &num);
	ps->data[ps->size] = num;
	ps->size++;
	StackPrint(ps);
}

void StackPop(Stack* ps)
{
	if (ps->size == 0)
	{
		printf("栈中无数据\n");
		return;
	}
	ps->size--;
	StackPrint(ps);
}

void StackTop(Stack* ps)
{
	StackPrint(ps);
	if (ps->size == 0)
	{
		printf("栈中无数据\n");
		return;
	}
	printf("%d\n", ps->data[ps->size - 1]);
}

void StackPrint(Stack* ps)
{
	system("cls");
	int n = 50;
	for (int i = 0; i < n; i++)
	{
		printf("*");
	}
	printf("\n* ");
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("*");
	}
	printf("\n");
	printf("\n");
	printf("******************************\n");
	printf("** 1.StackPush   2.StackPop **\n");
	printf("** 3.StackTop    0.exit    ** \n");
	printf("******************************\n");
}

void StackDestroy(Stack* ps)
{
	free(ps->data);
}
