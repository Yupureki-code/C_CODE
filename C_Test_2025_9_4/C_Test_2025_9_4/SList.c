#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

size_t count = 0;

LL* InitSList()
{
	LL* p1 = malloc(sizeof(LL));
	assert(p1);
	count++;
	p1->Data = 1;
	p1->Next = NULL;
	return p1;
}

void SListPushFront(LL** phead,SLDataType n)
{
	LL* p1 = malloc(sizeof(LL));
	assert(p1);
	count++;
	p1->Data = n;
	p1->Next = *phead;
	*phead = p1;
	SListPrint(phead);

}

void SListPushBack(LL** phead, SLDataType n)
{
	LL* pl = malloc(sizeof(LL));
	assert(pl);
	count++;
	pl->Data = n;
	pl->Next = NULL;
	LL* pfind = *phead;
	while (pfind->Next)
	{
		pfind = pfind->Next;
	}
	pfind->Next = pl;
	SListPrint(phead);

}

void SListPrint(LL** phead)
{
	assert(*phead);
	system("cls");
	LL* pl = *phead;
	while (pl)
	{
		printf("%d->", pl->Data);
		pl = pl->Next;
	}
	printf("NULL");
	printf("\n");
}

void SListBreak(LL** phead)
{
	assert(*phead);
	LL* pl = *phead;
	LL* pn = NULL;
	while (pl->Next)
	{
		pn = pl->Next;
		free(pl);
		pl = pn;
	}
	pl = NULL;
	*phead = NULL;
	phead = NULL;
}

void SListDelete(LL** phead,int pose)
{
	assert(*phead);
	if (pose<1 || pose>count)
	{
		printf("ÊäÈë´íÎó\n");
		return;
	}
	LL* pl = *phead;
	count--;
	if (pose == 1)
	{
		*phead = pl->Next;
		free(pl);
		pl = NULL;
		SListPrint(phead);
		return;
	}
	LL* pn = NULL;
	pose--;
	while (pose--)
	{
		if (pose == 0)
			pn = pl;
		pl = pl->Next;
	}
	pn->Next = pl->Next;

	free(pl);
	SListPrint(phead);

}

void SListInsert(LL** phead, int pose, SLDataType n)
{
	assert(*phead);
	if (pose<1 || pose>count + 1)
	{
		printf("ÊäÈë´íÎó\n");
		return;
	}
	count++;
	LL* pl = *phead;
	LL* pn = NULL;
	LL* padd = malloc(sizeof(LL));
	padd->Data = n;
	padd->Next = NULL;
	if (pose == 1)
	{
		*phead = padd;
		padd->Next = pl;
		SListPrint(phead);
		return;
	}
	pose--;
	while (pose--)
	{
		if (pose == 0)
			pn = pl;
		pl = pl->Next;

	}
	pn->Next = padd;
	padd->Next = pl;
	SListPrint(phead);

}


void SListPopBack(LL** phead)
{
	assert(*phead);
	count--;
	LL* pl = *phead;
	LL* pn = NULL;
	while (pl->Next)
	{
		if (pl->Next->Next == NULL)
		{
			pn = pl;
		}
		pl = pl->Next;
	}
	free(pl);
	pn->Next = NULL;
	pl = NULL;
	pn = NULL;
	SListPrint(phead);

}

void SListPopFront(LL** phead)
{
	assert(*phead);
	count--;
	LL* pl = *phead;
	*phead = pl->Next;
	free(pl);
	pl = NULL;
	SListPrint(phead);

}