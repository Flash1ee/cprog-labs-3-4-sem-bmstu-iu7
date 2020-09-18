#include "../inc/io.h"
#include "../inc/err.h"

int f_long_cnt(FILE *f, size_t *size)
{
    size_t tmp = 0;
    long num;
    while (fscanf(f, "%ld ", &num) == 1)
        tmp++;
    if (!tmp)
        return EMPTY_FILE;
    *size = tmp;
    return EXIT_SUCCESS;
}

int fill(FILE *f, long *pa, long *pb)
{
    long tmp;
    while (pa < pb)
    {
        if (fscanf(f, "%ld", pa++) != 1)
            return READ_ERR;
    }
    return EXIT_SUCCESS;
}