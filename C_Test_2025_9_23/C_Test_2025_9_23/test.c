#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1015
typedef struct Stu {
    char id[9];
    int a;
    int b;
    int r;
}stu;

int cmp(void* a, void* b)
{
    stu* n = (stu*)a;
    stu* m = (stu*)b;
    int x = n->a + n->b;
    int y = m->a + m->b;
    if (x == y)
    {
        if (n->a == m->a)
        {
            int r = strcmp(n->id, m->id);
            return r;
        }
        else
        {
            return m->a - n->a;
        }
    }
    else
    {
        return y - x;
    }
}

int main()
{
    int N, L, H;
    scanf("%d %d %d", &N, &L, &H);
    stu* s = malloc(sizeof(stu) * N);
    stu* arr1 = malloc(sizeof(stu));
    int i1 = 0;
    stu* arr2 = malloc(sizeof(stu));
    int i2 = 0;
    stu* arr3 = malloc(sizeof(stu));
    int i3 = 0;
    stu* arr4 = malloc(sizeof(stu));
    int i4 = 0;
    stu* tmp;
    for (int i = 0; i < N; i++)
    {

        scanf("%s %d %d", s[i].id, &s[i].a, &s[i].b);
        s[i].r = s[i].a + s[i].b;
        if (s[i].a >= L && s[i].b >= L)
        {
            if (s[i].a >= H && s[i].b >= H)
            {
                memcpy(arr1 + i1, &s[i], sizeof(stu));
                i1++;
                arr1 = realloc(arr1, (i1 + 1) * sizeof(stu));
            }
            else if (s[i].a >= H && s[i].b < H)
            {
                memcpy(arr2 + i2, &s[i], sizeof(stu));
                i2++;
                arr2 = realloc(arr2, (i2 + 1) * sizeof(stu));

            }
            else if (s[i].a < H && s[i].b < H && s[i].a >= s[i].b)
            {
                memcpy(arr3 + i3, &s[i], sizeof(stu));
                i3++;
                arr3 = realloc(arr3, (i3 + 1) * sizeof(stu));
            }
            else
            {
                memcpy(arr4 + i4, &s[i], sizeof(stu));
                i4++;
                arr4 = realloc(arr4, (i4 + 1) * sizeof(stu));
            }
        }
    }
    qsort(arr1, i1, sizeof(stu), cmp);
    qsort(arr2, i2, sizeof(stu), cmp);
    qsort(arr3, i3, sizeof(stu), cmp);
    qsort(arr4, i4, sizeof(stu), cmp);
    printf("%d\n", i1 + i2 + i3 + i4);
    for (int i = 0; i < i1; i++)
    {
        printf("%s %d %d\n", arr1[i].id, arr1[i].a, arr1[i].b);
    }
    for (int i = 0; i < i2; i++)
    {
        printf("%s %d %d\n", arr2[i].id, arr2[i].a, arr2[i].b);
    }
    for (int i = 0; i < i3; i++)
    {
        printf("%s %d %d\n", arr3[i].id, arr3[i].a, arr3[i].b);
    }
    for (int i = 0; i < i4; i++)
    {
        if (i == i4 - 1)
        {
            printf("%s %d %d", arr4[i].id, arr4[i].a, arr4[i].b);
            break;
        }
        printf("%s %d %d\n", arr4[i].id, arr4[i].a, arr4[i].b);
    }

}
