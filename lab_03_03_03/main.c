#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define IND 2

void search_min(my_int a[][N], my_int min[][N], size_t n, size_t m);
void sort(my_int min[][N], size_t col);
void swap_str(my_int a[][N], my_int b[][N], my_int min[], size_t str, size_t col);

int main()
{
    my_int a[N][N];
    my_int b[N][N];
    my_int min[IND][N];
    size_t n, m;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > N || m < 1 || m > N)
        return EXIT_FAILURE;
    if (input(a, n, m) != 0)
        return EXIT_FAILURE;
        
    search_min(a, min, n, m);
    sort(min, n);
    swap_str(a, b, min[1], n, m);
    output(b, n, m);
    
    return EXIT_SUCCESS;
}

void search_min(my_int a[][N], my_int min[][N], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        min[0][i] = a[i][0];
        min[1][i] = i;
        for (size_t j = 0; j < m; j++)
            if (a[i][j] < min[0][i])
                min[0][i] = a[i][j];
    }
}

void sort(my_int min[][N], size_t col)
{
    for (size_t i = 0; i < col - 1; i++)
        for (size_t j = 0; j < col - i - 1; j++)
        {
            if (min[0][j] < min[0][j + 1])
            {
                swap(&min[0][j], &min[0][j + 1]);
                swap(&min[1][j], &min[1][j + 1]);
            }
        }
}

void swap_str(my_int a[][N], my_int b[][N], my_int min[], size_t str, size_t col)
{
    my_int cur_str;
    for (size_t i = 0; i < str; i++)
    {
        cur_str = min[i];
        for (size_t j = 0; j < col; j++)
            b[i][j] = a[cur_str][j];
    }
}
