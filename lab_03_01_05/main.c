#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define SHIFT 3
#define SUM 10

int input(long long a[][N], size_t *n, size_t *m);
void output(long long a[][N], size_t *n, size_t *m);
int search_adding_numbers(long long a[][N], long long b[], size_t *n, size_t *m, size_t *k);
long sum_digits(long long x);
void cyclic_shift(long long b[], size_t *n);
void replace(long long a[][N], long long b[], size_t *n, size_t *m, size_t *vector_size);

int main()
{
    long long a[N][N];
    long long b[N * N];
    size_t size = 0;
    size_t n, m;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > N || m < 1 || m > N)
        return EXIT_FAILURE;

    if (input(a, &n, &m) != 0)
        return EXIT_FAILURE;

    if (search_adding_numbers(a, b, &n, &m, &size) == 0)
        return EXIT_FAILURE;
        
    cyclic_shift(b, &size);
    replace(a, b, &n, &m, &size);
    output(a, &n, &m);

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
int search_adding_numbers(long long a[][N], long long b[], size_t *n, size_t *m, size_t *k)
{
    int flag = 0;
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
            if (sum_digits(a[i][j]) > SUM)
            {
                flag += 1;
                b[*k] = a[i][j];
                *k += 1;
            }
    
    return flag;
}
long sum_digits(long long x)
{
    long sum = 0;
    if (x < 0)
        x *= -1;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}
void cyclic_shift(long long b[], size_t *n)
{
    for (size_t i = 0; i < SHIFT; i++)
    {
        long long tmp = b[0];
        for (size_t j = 1; j < *n; j++)
            b[j - 1] = b[j];
        b[*n - 1] = tmp;
    }
}
void replace(long long a[][N], long long b[], size_t *n, size_t *m, size_t *vector_size)
{
    size_t s = 0;
    size_t ind;
    for (size_t i = 0; i < *n; i++)
        for (size_t j = 0; j < *m; j++)
        {
            ind = (*vector_size - SHIFT + s) % *vector_size;
            if (a[i][j] == b[ind])
            {
                a[i][j] = b[s];
                s++;
            }
        }
}