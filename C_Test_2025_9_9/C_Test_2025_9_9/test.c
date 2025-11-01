#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//交换两个数

//int main() {
//    int a = 0;
//    int b = 0;
//    scanf("a=%d ,b=%d\n", &a, &b);
//    int c = a;
//    a = b;
//    b = c;
//    printf("a=%d,b=%d", a, b);
//
//}

//打印小写字母

//#include <ctype.h>
//int main() {
//    int ch;
//    while ((ch = getchar()) != EOF) {
//        if (ch >= 'A' && ch <= 'Z') {
//            printf("%c\n", tolower(ch));
//        }
//    }
//    return 0;
//}

//十六进制转十进制

//int main() {
//    int a = 0xABCDEF;
//    printf("%15d", a);
//}

//打印八进制和十六进制

//int main() {
//    int a = 1234;
//    printf("%#o ", a);
//    printf("%#X", a);
//    return 0;
//}

//打印字符 整数 浮点数
// 
//int main() {
//    char a = 0;
//    int b = 0;
//    float c = 0;
//    scanf("%c %d %f", &a, &b, &c);
//    printf("%c %d %.6f", a, b, c);
//}

//对齐打印

//int main() {
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("%d%8d%8d", a, b, c);
//}

//进制A+B

//int main() {
//	int a, b;
//	scanf("%x %o", &a, &b);
//	a = a + b;
//	printf("%d", a);
//}

//加法

//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d", a + b);
//}

//除法

//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d", a / b);
//}

//求余

//int main() {
//    int a, b;
//    scanf("%d %d", &a, &b);
//    printf("%d", a % b);
//}

//获取浮点数的个位数

int main() {
	char arr[100];
	scanf("%s", arr);
	int n = 0;
	sscanf(arr, "%d", &n);
	printf("%d", n % 10);
}