#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define IND 2

int input(long long a[][N], size_t *n, size_t *m);
void output(long long a[][N], size_t *n, size_t *m);
void search_min(long long a[][N], long long min[][N], size_t *n, size_t *m);
void sort(long long min[][N], size_t *col);
void swap_str(long long a[][N], long long b[][N], long long min[], size_t *str, size_t *col);

int main()
{
    long long a[N][N];
    long long b[N][N];
    long long min[IND][N];
    size_t n, m;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > 10 || m < 1 || m > 10)
        return EXIT_FAILURE;
    if (input(a, &n, &m) != 0)
        return EXIT_FAILURE;
    search_min(a, min, &n, &m);
    sort(min, &n);
    swap_str(a, b, min[1], &n, &m);
    output(b, &n, &m);
    return EXIT_SUCCESS;
}

int input(long long a[][N], size_t *n, size_t *m)
{
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (scanf("%lld", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output(long long a[][N], size_t *n, size_t *m)
{
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *m; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
}

void search_min(long long a[][N], long long min[][N], size_t *n, size_t *m)
{
    for (size_t i = 0; i < *n; i++)
    {
        min[0][i] = a[i][0];
        min[1][i] = i;
        for (size_t j = 0; j < *m; j++)
            if (a[i][j] < min[0][i])
                min[0][i] = a[i][j];
    }
}

void sort(long long min[][N], size_t *col)
{
    for (size_t i = 0; i < *col - 1; i++)
        for (size_t j = 0; j < *col - i - 1; j++)
        {
            if (min[0][j] > min[0][j + 1])
            {
                long long tmp = min[0][j];
                min[0][j] = min[0][j + 1];
                min[0][j + 1] = tmp;
                tmp = min[1][j];
                min[1][j] = min[1][j + 1];
                min[1][j + 1] = tmp;
            }
        }
}

void swap_str(long long a[][N], long long b[][N], long long min[], size_t *str, size_t *col)
{
    long long cur_str;
    for (size_t i = 0; i < *str; i++)
    {
        cur_str = min[i];
        for (size_t j = 0; j < *col; j++)
            b[i][j] = a[cur_str][j];
    }
}