#define __USE_MINGW_ANSI_STDIO 1
#include "array.h"

int input(my_int a[][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%lld", &a[i][j]) != 1)
                return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int output(my_int a[][N], size_t n, size_t m)
{
    if (m == 0)
        return EXIT_FAILURE;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%lld ", a[i][j]);
        printf("\n");
    }

    return EXIT_SUCCESS;
}
void swap(my_int *a, my_int *b)
{
    my_int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
