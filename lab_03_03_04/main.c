#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void sort(my_int a[][N], size_t n);

int main()
{
    my_int a[N][N];
    size_t n, m;
    
    if (scanf("%zu", &n) != 1 || n < 1 || n > N)
        return EXIT_FAILURE;
    if (scanf("%zu", &m) != 1 || m < 1 || m > N || m != n)
        return EXIT_FAILURE;
    if (input(a, n, n) != 0)
        return EXIT_FAILURE;
        
    sort(a, n);
    output(a, n, n);
    
    return EXIT_SUCCESS;
}

void sort(my_int a[][N], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
        for (size_t j = i; j < n - i; j++)
            swap(&a[j][i], &a[j][n - i - 1]);
}