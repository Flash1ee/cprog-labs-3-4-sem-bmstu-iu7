#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define N 10

int input(long long a[][N], size_t n, size_t m);
void output(long long a[], size_t n);
int monotonic_sequence(long long a[], size_t m);
void increasing_sequence(long long a[], size_t m, int *flag);
void decreasing_sequence(long long a[], size_t m, int *flag);
void vector(long long b[], long long a[][N], size_t n, size_t m);

int main()
{
    long long a[N][N];
    size_t n, m;
    long long b[N * N];

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n <= 0
     || n > 10 || m < 1 || m > 10)
        return EXIT_FAILURE;

    if (input(a, n, m) != 0)
        return EXIT_FAILURE;

    vector(b, a, n, m);

    for (size_t i = 0; i < n; i++)
    {
        if (monotonic_sequence(a[i], m) == 1)
            b[i] = 1;
        else
            b[i] = 0;
    }
    output(b, n);
    return EXIT_SUCCESS;
}

int input(long long a[][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%lld", &a[i][j]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void output(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%lld ", a[i]);
}
int monotonic_sequence(long long a[], size_t m)
{
    int flag = 0;
    if (m <= 1)
        return flag;
    decreasing_sequence(a, m, &flag);
    increasing_sequence(a, m, &flag);
    return flag;
}
void increasing_sequence(long long a[N], size_t m, int *flag)
{
    for (size_t i = 0; i < m - 1; i++)
    {
        if (a[i] > a[i + 1])
            return;
    }
    *flag = 1;
}
void decreasing_sequence(long long a[N], size_t m, int *flag)
{
    for (size_t i = 0; i < m - 1; i++)
    {
        if (a[i] < a[i + 1])
            return;
    }
    *flag = 1;
}
void vector(long long b[], long long a[][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            b[i * m + j] = a[i][j];
}