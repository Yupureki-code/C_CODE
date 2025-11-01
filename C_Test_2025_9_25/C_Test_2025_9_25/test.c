#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//1018
char getMaxGesture(int b, int c, int j) {
    int max = b;
    if (c > max) max = c;
    if (j > max) max = j;
    if (b == max) return 'B';
    if (c == max) return 'C';
    return 'J';
}

int main() {
    int N;
    scanf("%d", &N);

    int winA = 0, drawA = 0;
    int a_win_b = 0, a_win_c = 0, a_win_j = 0;
    int b_win_b = 0, b_win_c = 0, b_win_j = 0;

    for (int i = 0; i < N; i++) {
        char a, b;
        scanf(" %c %c", &a, &b);

        if (a == b) {
            drawA++;
        }
        else if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B') || (a == 'B' && b == 'C')) {
            winA++;
            if (a == 'B') a_win_b++;
            else if (a == 'C') a_win_c++;
            else if (a == 'J') a_win_j++;
        }
        else {
            if (b == 'B') b_win_b++;
            else if (b == 'C') b_win_c++;
            else if (b == 'J') b_win_j++;
        }
    }

    int loseA = N - winA - drawA;
    printf("%d %d %d\n", winA, drawA, loseA);
    printf("%d %d %d\n", loseA, drawA, winA);

    char gestureA = getMaxGesture(a_win_b, a_win_c, a_win_j);
    char gestureB = getMaxGesture(b_win_b, b_win_c, b_win_j);
    printf("%c %c\n", gestureA, gestureB);

    return 0;
}
//1019
#include <stdlib.h>
#include <string.h>

int up(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}

int down(const void* a, const void* b) {
    return *(char*)b - *(char*)a;
}

int main() {
    int n;
    scanf("%d", &n);
    char arr[5] = { 0 };
    sprintf(arr, "%04d", n);

    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
        printf("%s - %s = 0000\n", arr, arr);
        return 0;
    }

    while (1) {
        char max_str[5] = { 0 };
        char min_str[5] = { 0 };
        strcpy(max_str, arr);
        strcpy(min_str, arr);

        qsort(max_str, 4, sizeof(char), down);
        qsort(min_str, 4, sizeof(char), up);

        int num_max, num_min;
        sscanf(max_str, "%d", &num_max);
        sscanf(min_str, "%d", &num_min);

        int result = num_max - num_min;
        printf("%04d - %04d = %04d\n", num_max, num_min, result);

        if (result == 6174) {
            break;
        }

        sprintf(arr, "%04d", result);
    }

    return 0;
}
//1020
typedef struct mooncake {
    double stock;       // 库存量
    double total_price; // 总售价
    double unit_price;  // 单价
} cake;

int compare(const void* a, const void* b) {
    cake* c1 = (cake*)a;
    cake* c2 = (cake*)b;
    if (c1->unit_price < c2->unit_price) return 1;
    else if (c1->unit_price > c2->unit_price) return -1;
    else return 0;
}

int main() {
    int total, need;
    scanf("%d %d", &total, &need);
    cake* mc = (cake*)malloc(total * sizeof(cake));

    for (int i = 0; i < total; i++) {
        scanf("%lf", &mc[i].stock);
    }
    for (int i = 0; i < total; i++) {
        scanf("%lf", &mc[i].total_price);
        mc[i].unit_price = mc[i].total_price / mc[i].stock;
    }

    // 按单价降序排序
    qsort(mc, total, sizeof(cake), compare);

    double profit = 0.0;
    int remaining = need;
    for (int i = 0; i < total && remaining > 0; i++) {
        if (mc[i].stock <= remaining) {
            profit += mc[i].total_price;
            remaining -= mc[i].stock;
        }
        else {
            profit += mc[i].unit_price * remaining;
            remaining = 0;
        }
    }

    printf("%.2f\n", profit);
    free(mc);
    return 0;
}