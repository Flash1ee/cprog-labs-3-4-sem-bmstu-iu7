#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int input(long mas[], size_t n);
int get_pos(long mas[], size_t k, long *len);
double get_pos_element_prod(long mas[], size_t n);
int main()
{
    size_t n; 
    long a[N], len_pos = 0;
    if (scanf("%zu", &n) != 1 || n > 10 || n <= 0)
        return EXIT_FAILURE;
    if (input(a, n) != EXIT_SUCCESS || get_pos(a, n, &len_pos) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    printf("%lf", pow(get_pos_element_prod(a, n), 1.0 / len_pos));
    return EXIT_SUCCESS;
}

int get_pos(long mas[], size_t n, long *len)
{
    for (size_t i = 0; i < n; i++)
        if (mas[i] > 0)
            *len += 1;
    if (!*len)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int input(long mas[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%ld", &mas[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
double get_pos_element_prod(long mas[], size_t n)
{
    double prod = 1.0;
    for (size_t i = 0; i < n; i++)
        if (mas[i] > 0)
            prod *= mas[i];
    return prod;
}
