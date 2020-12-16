#include "io_lib.h"

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

