#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//1003
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        char arr[101] = { 0 };
        scanf("%s", arr);
        int len = strlen(arr);
        int countP = 0, countT = 0;
        int posP = -1, posT = -1;
        int valid = 1;
        for (int i = 0; i < len; i++) {
            if (arr[i] == 'P') {
                countP++;
                posP = i;
            }
            else if (arr[i] == 'T') {
                countT++;
                posT = i;
            }
            else if (arr[i] != 'A') {
                valid = 0;
                break;
            }
        }
        if (countP != 1 || countT != 1 || posP >= posT) {
            valid = 0;
        }

        if (!valid) {
            printf("NO\n");
            continue;
        }

        int a = posP;
        int b = posT - posP - 1;
        int c = len - posT - 1;
        if (b < 1) {
            printf("NO\n");
            continue;
        }
        if (a * b == c) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}

#include <stdlib.h>
//1004
typedef struct stu {
    char name[11];
    char id[11];
    int score;
} st;

int cmp(const void* a, const void* b) {
    return ((st*)a)->score - ((st*)b)->score;
}
int main() {
    int n = 0;
    scanf("%d", &n);
    int original_n = n;
    st* s = malloc(n * sizeof(st));
    if (s == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", s[i].name, s[i].id, &s[i].score);
    }
    qsort(s, n, sizeof(st), cmp);
    printf("%s %s\n", s[n - 1].name, s[n - 1].id);
    printf("%s %s\n", s[0].name, s[0].id);
    free(s);
    return 0;
}
