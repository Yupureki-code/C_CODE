#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void initSL(SL* ps)
{
	ps->arr = calloc(4,sizeof(SLDataType));
	ps->size = 0;
	ps->capacity = 4;
}
void SLDestroy(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
void SLPrint(SL* ps)
{
	assert(ps && ps->arr);
	if (ps->size == 0)
		return;
	printf("arr :");
	for (int i = 0; i < ps->size; i++)
		printf(PRINT_FORMAT, ps->arr[i]);
	printf("\n");
}
void SLPushBack(SL* ps,SLDataType n)
{
	SLCheck(ps);
	ps->arr[ps->size] = n;
	ps->size++;
}
void SLCheck(SL* ps)
{
	assert(ps&&ps->arr);
	if (ps->size == ps->capacity)
	{
		SLDataType* p;
		SLDataType NewCapacity =2 * ps->capacity;
		p = realloc(ps->arr, NewCapacity*sizeof(SLDataType));
		assert(p);
		ps->arr = p;
		ps->capacity = NewCapacity;
	}
}
void SLPushFront(SL* ps, SLDataType n)
{
	SLCheck(ps);
	memmove(ps->arr + 1,ps->arr, ps->size * sizeof(SLDataType));
	ps->size++;
	ps->arr[0] = n;
}
void SLPopBack(SL* ps)
{
	SLCheck(ps);
	ps->arr[--ps->size] = 0;
}
void SLPopFront(SL* ps)
{
	SLCheck(ps);
	memmove(ps->arr, ps->arr + 1, (--ps->size) * sizeof(SLDataType));
	ps->arr[ps->size] = 0;
}
void SLInsert(SL* ps, SLDataType num,size_t pose)
{
	SLCheck(ps);
	if (pose > ps->size+1 || pose < 1)
	{
		printf("ÊäÈë´íÎó\n");
		return;
	}
	if (pose == ps->size)
	{
		ps->arr[pose-1] = num;
		return;
	}
	memmove(ps->arr + pose, ps->arr + pose-1, (ps->size - pose+1)*sizeof(SLDataType));
	ps->arr[pose - 1] = num;
	ps->size++;
}
void SLErase(SL* ps, size_t pose)
{
	SLCheck(ps);
	if (pose > ps->size || pose < 1)
	{
		printf("ÊäÈë´íÎó\n");
		return;
	}
	if (pose == ps->size)
	{
		SLPopBack(ps);
		return;
	}
	memmove(ps->arr + pose - 1, ps->arr + pose, (ps->size - pose) * sizeof(SLDataType));
	ps->size--;
}
void menu()
{
	printf("1.PushFront 2.PushBack\n");
	printf("3.PopFornt  4.PopBack\n");
	printf("5.SLInsert    6.SLErase\n");
	printf("0.exit\n");
}
