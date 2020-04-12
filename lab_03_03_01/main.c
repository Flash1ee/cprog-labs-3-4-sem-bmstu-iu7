#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_m(my_int a[], size_t n);
int monotonic_sequence(my_int a[], size_t m);
void increasing_sequence(my_int a[], size_t m, int *flag);
void decreasing_sequence(my_int a[], size_t m, int *flag);

int main()
{
    my_int a[N][N];
    size_t n, m;
    my_int b[N];

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n <= 0
        || n > N || m < 1 || m > N)
        return EXIT_FAILURE;

    if (input(a, n, m) != 0)
        return EXIT_FAILURE;

    for (size_t i = 0; i < n; i++)
    {
        if (monotonic_sequence(a[i], m) == 1)
            b[i] = 1;
        else
            b[i] = 0;
    }
    output_m(b, n);
    
    return EXIT_SUCCESS;
}

void output_m(my_int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%lld ", a[i]);
}

int monotonic_sequence(my_int a[], size_t m)
{
    int flag = 0;
    
    if (m <= 1)
        return flag;
        
    decreasing_sequence(a, m, &flag);
    increasing_sequence(a, m, &flag);
    
    return flag;
}

void increasing_sequence(my_int a[N], size_t m, int *flag)
{
    for (size_t i = 0; i < m - 1; i++)
        if (a[i] > a[i + 1])
            return;
    *flag = 1;
}

void decreasing_sequence(my_int a[N], size_t m, int *flag)
{
    for (size_t i = 0; i < m - 1; i++)
        if (a[i] < a[i + 1])
            return;
    *flag = 1;
}