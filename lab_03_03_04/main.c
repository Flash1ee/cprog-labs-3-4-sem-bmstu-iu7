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
    size_t n;
    if (scanf("%zu", &n) != 1 || n < 1 || n > 10)
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
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *n; j++)
            if ((i + j < *n - 1) && (i > j))
            {
                tmp = a[i][j];
                a[i][j] = a[*n - i - 1][*n - j - 1];
                a[*n - i - 1][*n - j - 1] = tmp;
            }
    for (size_t i = 0; i < *n / 2; i++)
        for (size_t j = 0; j < *n; j++)
            if (i == j)
            {
                tmp = a[i][j];
                a[i][j] = a[*n - i - 1][*n - j - 1];
                a[*n - i - 1][*n - j - 1] = tmp;
            }
            else if (i + j == *n - 1)
            {
                tmp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = tmp;
            }
}
