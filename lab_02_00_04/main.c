#include <stdio.h>
#include <stdlib.h>

#define N 10

long input_mas(long *a, long *n);
long check_count_elem(long *n);
void print_mas(long *a, long *n);
void bubble_sort(long *a, long *n);

int main(void)
{
    long n;
    long a[N];
    if (check_count_elem(&n) != 0 || input_mas(a, &n) != 0)
    {
        return EXIT_FAILURE;
    }
    bubble_sort(a, &n);
    print_mas(a, &n);
    return EXIT_SUCCESS;
}


long input_mas(long *a, long *n)
{
    for (long i = 0; i < *n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long check_count_elem(long *n)
{
    if (scanf("%ld", n) != 1 || *n > N || *n <= 0)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
void print_mas(long *a, long *n)
{
    for (int i = 0; i < *n; i++)
    {
        printf("%ld ", a[i]);
    }
}
void bubble_sort(long *a, long *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = 1; j < *n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                long tmp;
                tmp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = tmp;
            }
        }
    }
}