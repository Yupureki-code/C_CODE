#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

void menu()
{
	printf("1.SListPushFront  2.SListPushBack\n");
	printf("3.SListPopFront   4.SLsitPopBack\n");
	printf("5.SListInsert     6.SListDelete\n");
	printf("0.exit\n");
}


int main()
{
	LL* phead = NULL;
	phead = InitSList();
	int input = 0;
	SLDataType n = 0;
	int pose = 0;
	SListPrint(&phead);
	do {
		menu();
		printf("«Î—°‘Ò->\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			scanf("%d", &n);
			SListPushFront(&phead, n);
			break;
		case 2:
			scanf("%d", &n);
			SListPushBack(&phead, n);
			break;
		case 3:
			SListPopFront(&phead);
			break;
		case 4:
			SListPopBack(&phead);
			break;
		case 5:
			scanf("%d %d", &pose, &n);
			SListInsert(&phead, pose,n);
			break;
		case 6:
			scanf("%d", &pose);
			SListDelete(&phead, pose);
			break;
		case 0:
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ\n");
			break;
		}
	} while (input);
	SListBreak(&phead);
	return 0;
}