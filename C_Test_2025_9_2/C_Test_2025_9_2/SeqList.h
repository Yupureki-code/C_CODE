#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <windows.h>

typedef  int SLDataType;
#define FORMAT " %d"
#define PRINT_FORMAT "%d "

typedef struct SeqList {
	SLDataType* arr;
	size_t size;
	size_t capacity;
}SL;

void initSL(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);
void SLPushBack(SL* ps, SLDataType n);
void SLCheck(SL* ps);
void SLPushFront(SL* ps, SLDataType n);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);
void SLErase(SL* ps, size_t pose);
void SLInsert(SL* ps, SLDataType num, size_t pose);
void menu();
