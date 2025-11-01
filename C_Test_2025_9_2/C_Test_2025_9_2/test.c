#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


int main()
{
	SL a = { 0 };
	int input = 0;
	SLDataType num = 0;
	size_t pose = 0;
	initSL(&a);
	SLPrint(&a);
	do
	{
		menu();
		again:
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				scanf(FORMAT, &num);
				system("cls");
				SLPushFront(&a, num);
				SLPrint(&a);
				break;
			case 2:
				scanf(FORMAT, &num);
				system("cls");
				SLPushBack(&a, num);
				SLPrint(&a);
				break;
			case 3:
				system("cls");
				SLPopFront(&a);
				SLPrint(&a);
				break;
			case 4:
				system("cls");
				SLPopBack(&a);
				SLPrint(&a);
				break;
			case 5:
				scanf("%zd"FORMAT, &pose, &num);
				system("cls");
				SLInsert(&a, num, pose);
				SLPrint(&a);
				break;
			case 6:
				scanf("%zd", &pose);
				system("cls");
				SLErase(&a, pose);
				SLPrint(&a);
				break;
			case 0:
				break;
			default:
				printf(" ‰»Î¥ÌŒÛ\n");
				goto again;
		}
	} while (input);
	/*initSL(&a);
	SLPushFront(&a, 1);
	SLPrint(&a);
	SLPushBack(&a, 2);
	SLPrint(&a);
	SLPushBack(&a, 3);
	SLPrint(&a);
	SLPushFront(&a, 4);
	SLPrint(&a);
	SLPushFront(&a, 5);
	SLPrint(&a);
	SLPopBack(&a);
	SLPrint(&a);
	SLPopFront(&a);
	SLPrint(&a);
	SLInsert(&a, 1, 3);
	SLPrint(&a);
	SLErase(&a, 2);
	SLPrint(&a);*/

	SLDestroy(&a);

	return 0;
}