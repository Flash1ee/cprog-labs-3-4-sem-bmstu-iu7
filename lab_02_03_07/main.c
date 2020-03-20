#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define N 1000000

long input(long a[], long *n);
void output(long a[], long *n);
void bubble_sort(long a[], long *n);

int main(void)
{
    long n;
    long a[N];
    if (scanf("%ld", &n) != 1 || n > N || n <= 0 || input(a, &n) != 0)
    {
        return EXIT_FAILURE;
    }
    bubble_sort(a, &n);
    output(a, &n);
    return EXIT_SUCCESS;
}


long input(long a[], long *n)
{
    for (long i = 0; i < *n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void output(long a[], long *n)
{
    for (long i = 0; i < *n; i++)
    {
        printf("%ld " , a[i]);
    }
}
void bubble_sort(long a[], long *n)
{
    for (long i = 0; i < *n; i++)
        for (long j = 1; j < *n - i; j++)
            if (a[j - 1] > a[j])
            {
                long tmp;
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
}