#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define N 100000

int input(long long a[], size_t n);
void output(long long a[], size_t n);
void bubble_sort(long long a[], size_t n);

int main()
{
    size_t n;
    long long a[N];

    if (scanf("%zu", &n) != 1 || n > N || n <= 0)
        return EXIT_FAILURE;

    if (input(a, n) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    bubble_sort(a, n);
    output(a, n);
    
    return EXIT_SUCCESS;
}


int input(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%lld", &a[i]) != 1)
            return EXIT_FAILURE;
            
    return EXIT_SUCCESS;
}

void output(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%lld ", a[i]);
}

void bubble_sort(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 1; j < n - i; j++)
            if (a[j - 1] > a[j])
            {
                long long tmp;
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
}