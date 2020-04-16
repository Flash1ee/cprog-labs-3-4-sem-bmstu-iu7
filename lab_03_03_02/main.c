#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

#define INPUT_NUM_ERROR 5

void check(my_int a[][N], size_t n, size_t *m, long k);
int check_numb(my_int x, long k);
void swap_col(my_int a[][N], size_t col, size_t count_str, size_t count_col);

int main()
{
    my_int a[N][N];
    size_t n, m;
    long k;

    if (scanf("%zu", &n) != 1 || scanf("%zu", &m) != 1 || n < 1 || n > N || m < 1 || m > N)
        return SIZE_ERROR;
    if (input(a, n, m) != 0)
        return INPUT_ERROR;
    if (scanf("%ld", &k) != 1 || k < 0 || k > 9)
        return INPUT_NUM_ERROR;
        
    check(a, n, &m, k);
    if (output(a, n, m) != 0)
        return EMPTY_OUT;
        
    return EXIT_SUCCESS;
}

void check(my_int a[][N], size_t n, size_t *m, long k)
{
    my_int x;
    int flag = 0;
    size_t i = 0;
    size_t j = 0;
    //столбцы
    while (i < *m)
    {
        flag = 0;
        //строки
        while (j < n)
        {
            x = a[j][i];
            if (check_numb(x, k) == 1)
            {
                swap_col(a, i, n, *m);
                flag = 1;
                *m -= 1;
                break;
            }
            else
                j += 1;
        }
        if (!flag)
            i += 1;
        j = 0;
    }
}
int check_numb(my_int x, long k)
{
    my_int digit;
    
    if (x < 0)
        x *= -1;
    if ((x == 0) && (x == k))
        return 1;
        
    while (x > 0)
    {
        digit = x % 10;
        x /= 10;
        if (digit == k)
            return 1;
    }
    
    return 0;
}
void swap_col(my_int a[][N], size_t column, size_t count_str, size_t count_col)
{
    for (size_t i = column + 1; i < count_col; i++)
        for (size_t j = 0; j < count_str; j++)
            a[j][i - 1] = a[j][i];
}