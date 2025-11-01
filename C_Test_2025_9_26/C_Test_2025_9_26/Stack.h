#pragma once
#include <stdio.h>
#include <stdlib.h>
#include  <assert.h>
#include <windows.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* data;//数组
	size_t size;//栈的数据个数		
	size_t capacity;//栈的最大容量  
}Stack;

void StackInit(Stack* ps);
//初始化栈
void StackPush(Stack* ps);
//压栈
void StackPop(Stack* ps);
//出栈
void StackTop(Stack* ps);
//头数据的打印
void StackCheck(Stack* ps);
//检测栈是否已满
void StackDestroy(Stack* ps);
//销毁栈
void StackPrint(Stack* ps);
//栈的打印