#include "stack.h"
#define  _CRT_SECURE_NO_WARNINGS 1

int main()
{
	Stack Stack1 = { 0 };
	StackInit(&Stack1);
	int input = 0;
	void (*ps[4])(Stack*) = { NULL,StackPush,StackPop,StackTop };
	StackPrint(&Stack1);
	do {
		printf("ÇëÊäÈë->");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
			ps[input](&Stack1);
			break;
		case 0:
			break;
		default:
			printf("ÊäÈë´íÎó\n");
			break;
		}
	} while (input);
	StackDestroy(&Stack1);
}