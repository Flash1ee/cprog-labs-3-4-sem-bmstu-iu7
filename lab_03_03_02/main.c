#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

int input(long long a[][N], size_t *n, size_t *m);
int output(long long a[][N], size_t *n, size_t *m);
void check_matrix(long long a[][N], size_t *n, size_t *m, long k);
int check_numb(long long x, long k);
void swap_column(long long a[][N], size_t *column, size_t *count_str, size_t *count_col);

int main()
{
    long long a[N][N];
    size_t n, m;
    long k;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > 10 || m < 1 || m > 10)
        return EXIT_FAILURE;
    if (scanf("%ld", &k) != 1 || k < 0 || k > 9)
        return EXIT_FAILURE;
    if (input(a, &n, &m) != 0)
        return EXIT_FAILURE;
    check_matrix(a, &n, &m, k);
    if (output(a, &n, &m) != 0)
    	return EXIT_FAILURE;
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

int output(long long a[][N], size_t *n, size_t *m)
{
    if (*m == 0)
        return EXIT_FAILURE;
    for (size_t i = 0; i < *n; i++)
    {
        for (size_t j = 0; j < *m; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }
    return EXIT_SUCCESS;
}

void check_matrix(long long a[][N], size_t *n, size_t *m, long k)
{
    long long x;
    int flag = 0;
    size_t i = 0;
    size_t j = 0;
    //столбцы
    while (i < *m)
    {
        flag = 0;
        //строки
        while (j < *n)
        {
            x = a[j][i];
            if (check_numb(x, k) == 1)
            {
                swap_column(a, &i, n, m);
                flag = 1;
                *m -= 1;
                break;
            }
            else
                j += 1;
        }
        if (!flag)
            i += 1;
        j = 0;
    }
}
int check_numb(long long x, long k)
{
    long long digit;
    if (x < 0)
        x *= (-1);
    if ((x == 0) && (x == k))
        return 1;
    while (x > 0)
    {
        digit = x % 10;
        x /= 10;
        if (digit == k)
            return 1;
    }
    return 0;
}
void swap_column(long long a[][N], size_t *column, size_t *count_str, size_t *count_col)
{
    for (size_t i = *column + 1; i < *count_col; i++)
        for (size_t j = 0; j < *count_str; j++)
            a[j][i - 1] = a[j][i];
}