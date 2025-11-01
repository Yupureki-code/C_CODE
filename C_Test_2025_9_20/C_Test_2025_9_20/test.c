#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//1007
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    if (N < 2) {
        printf("0\n");
        return 0;
    }

    bool* isPrime = (bool*)malloc((N + 1) * sizeof(bool));
    for (int i = 0; i <= N; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int* primes = (int*)malloc(N * sizeof(int));
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes[count++] = i;
        }
    }

    int pairCount = 0;
    for (int i = 1; i < count; i++) {
        if (primes[i] - primes[i - 1] == 2) {
            pairCount++;
        }
    }

    printf("%d\n", pairCount);

    free(isPrime);
    free(primes);
    return 0;
}

//1008
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    m = m % n;
    if (m != 0) {
        reverse(arr, 0, n - 1);
        reverse(arr, 0, m - 1);
        reverse(arr, m, n - 1);
    }

    for (int i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n");

    return 0;
}

//1009
int main()
{
    char arr[81] = { 0 };
    char str[81] = { 0 };
    scanf("%[^\n]", arr);
    int i = 0;
    char* tmp;
    while (*(arr + i) != '\0')
    {
        if (*(arr + i) == ' ')
        {
            *(arr + i) = '\0';
        }
        i++;
    }
    i--;
    int len = 0;
    for (; i >= 0; i--)
    {
        if (*(arr + i) == '\0')
        {
            tmp = arr + i + 1;
            strcpy(str + len, tmp);
            len = len + strlen(tmp) + 1;
            str[len - 1] = ' ';
        }
        if (i == 0)
        {
            strcpy(str + len, arr);
        }
    }
    printf("%s", str);
    return 0;
}