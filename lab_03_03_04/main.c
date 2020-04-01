#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define N 10

int input(long long a[][N], size_t *n);
void output(long long a[][N], size_t *n);
void sort(long long a[][N], size_t *n);

int main()
{
    long long a[N][N];
    size_t n, m;
    if (scanf("%zu", &n) != 1 || n < 1 || n > 10)
        return EXIT_FAILURE;
    if (scanf("%zu", &m) != 1 || m < 1 || m > 10 || m != n)
        return EXIT_FAILURE;
    if (input(a, &n) != 0)
        return EXIT_FAILURE;
    sort(a, &n);
    output(a, &n);
    return EXIT_SUCCESS;
}

int input(long long a[][N], size_t *n)
{
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *n; j++)
            if (scanf("%lld", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output(long long a[][N], size_t *n)
{
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *n; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}

void sort(long long a[][N], size_t *n)
{
    long long tmp;
    for (size_t i = 0; i < *n / 2; i++)
        for (size_t j = i; j < *n - i; j++)
            {
                tmp = a[j][i];
                a[j][i] = a[j][*n - i - 1];
                a[j][*n - i - 1] = tmp;

            }
}
