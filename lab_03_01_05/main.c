#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define SHIFT 3
#define SUM 10
#define NO_NUMBERS_OVER_SUM 5

int search_by_property(my_int a[][N], my_int b[], size_t n, size_t m, size_t *k);
long sum_digits(my_int x);
void cyclic_shift(my_int b[], size_t n);
void replace(my_int a[][N], my_int b[], size_t n, size_t m, size_t vector_size);

int main()
{
    my_int a[N][N];
    my_int b[N * N];
    size_t size = 0;
    size_t n, m;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > N || m < 1 || m > N)
        return SIZE_ERROR;

    if (input(a, n, m) != 0)
        return INPUT_ERROR;

    if (search_by_property(a, b, n, m, &size) == 0)
        return NO_NUMBERS_OVER_SUM;
        
    cyclic_shift(b, size);
    replace(a, b, n, m, size);
    output(a, n, m);

    return EXIT_SUCCESS;
}

int search_by_property(my_int a[][N], my_int b[], size_t n, size_t m, size_t *k)
{
    int flag = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (sum_digits(a[i][j]) > SUM)
            {
                flag += 1;
                b[*k] = a[i][j];
                *k += 1;
            }
    
    return flag;
}
long sum_digits(my_int x)
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
void cyclic_shift(my_int b[], size_t n)
{
    for (size_t i = 0; i < SHIFT; i++)
    {
        my_int tmp = b[0];
        for (size_t j = 1; j < n; j++)
            b[j - 1] = b[j];
        b[n - 1] = tmp;
    }
}
void replace(my_int a[][N], my_int b[], size_t n, size_t m, size_t vector_size)
{
    size_t s = 0;
    size_t ind;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            ind = (vector_size - SHIFT + s) % vector_size;
            if (a[i][j] == b[ind])
            {
                a[i][j] = b[s];
                s++;
            }
        }
}