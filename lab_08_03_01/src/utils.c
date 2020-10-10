#include "utils.h"

void new_size(size_t *size_new, size_t row_src, size_t col_src, int *flag)
{
    /*
    flag - переменная которая является сигналом для формирования матрицы
    */
    if (row_src < col_src)
    {
        *size_new = row_src;
        *flag = COL;
    }
    else
    {
        *size_new = col_src;
        *flag = ROW;
    }
}