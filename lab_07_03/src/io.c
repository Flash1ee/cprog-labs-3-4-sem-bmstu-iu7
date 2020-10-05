/**
*@file io.c
*@author Dmitry Varin
*@brief Файл с описанием функций для ввода данных из файла и вывода их в файл.
*@version 0.1
*@date 2020-09-25
*
*@copyright 
*
 */
#include "io.h"
#include "bug.h"

int f_int_cnt(FILE *f, size_t *size)
{
    size_t tmp = 0;
    int num;
    while (fscanf(f, "%d ", &num) == 1)
        tmp++;
    if (!tmp)
        return EMPTY_FILE;
    if (!feof(f))
        return READ_ERR;
    *size = tmp;
    return EXIT_SUCCESS;
}

int fill(FILE *f, int *pa, int *pb)
{
    int *beg = pa;
    while (beg < pb)
    {
        if (fscanf(f, "%d", beg++) != 1)
            return READ_ERR;
    }
    return EXIT_SUCCESS;
}

void print(FILE *f, int *arr, size_t n)
{
    for (int *cur = arr; cur < arr + n; cur++)
        fprintf(f, "%d ", *cur);
    fprintf(f, "\n");
}