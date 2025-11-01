#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印水仙花数

//int main() {
//    int n = 1;
//    for (; n <= 100000; n++)
//    {
//        int r = 0;
//        int a = 0;
//        for (int n1 = n; n1 > 0; a++)
//        {
//            n1 = n1 / 10;
//        }
//        a--;
//        for (int i = 0; i < a; i++)
//        {
//            int tmp = n;
//            int b = 10;
//            for (int j = 0; j < i; j++)
//            {
//                b = b * 10;
//            }
//            int x = tmp % b;
//            int y = tmp / b;
//            r = r + x * y;
//        }
//        if (r == n)
//        {
//            printf("%d ", n);
//        }
//   }
//}

//联合体判断大小端

union a {
	int a;
	char b;
};
int main()
{
	union a b = { 0 };
	b.a = 0x11223344;
	if (b.b == 0x11)
		printf("大端");
	else if (b.b == 0x44)
		printf("小端");

	return 0;
}
