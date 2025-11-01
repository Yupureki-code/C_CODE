#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <windows.h>

typedef int SLDataType;

typedef struct LinkedList {
	SLDataType Data;
	struct LinkedList* Next;
}LL;

LL* InitSList();
void SListPushFront(LL** phead, SLDataType n);
void SListPushBack(LL** phead, SLDataType n);
void SListPrint(LL** phead);
void SListBreak(LL** phead);
void SListInsert(LL** phead, int pose, SLDataType n);
void SListDelete(LL** phead, int pose);
void SListPopBack(LL** phead);
void SListPopFront(LL** phead);
