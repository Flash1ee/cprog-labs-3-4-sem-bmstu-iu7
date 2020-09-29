#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/err.h"
#include "../inc/io.h"
#include "../inc/sort.h"
#include "../inc/filter.h"


int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
        return ARG_ERR;
    if (argc == 4 && strcmp(argv[3], "f") != 0)
        return ARG_ERR;
    int filter;

    filter = 1 ? argc == 4 : 0;
    FILE *in, *out;
    int rc = 0;
    size_t n = 0;

    in = fopen(argv[1], "r");

    if (!in)
        return READ_ERR;

    if ((rc = f_int_cnt(in, &n)) != EXIT_SUCCESS)
    {
        fclose(in);
        return rc;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (!arr)
    {
        fclose(in);
        return ALLOCATION_ERR;
    }

    int *beg = arr;
    int *end = arr + n;
    fseek(in, 0, SEEK_SET);

    if (fill(in, beg, end))
    {
        free(arr);
        fclose(in);
        return READ_ERR;
    }

    if (filter)
    {
        int *dst_bg = NULL;
        int *dst_end = NULL;
        rc = key(arr, end, &dst_bg, &dst_end);
        if (rc)
        {
            free(arr);
            fclose(in);
            return rc;
        }
        n = dst_end - dst_bg;
        mysort(dst_bg, n, sizeof(int), cmp_i);

        out = fopen(argv[2], "w");
        if (!out)
        {
            free(arr);
            free(dst_bg);
            fclose(in);
            return READ_ERR;
        }
        print(out, dst_bg, n);
        free(dst_bg);
    }
    else
    {
        mysort(arr, n, sizeof(int), cmp_i);

        out = fopen(argv[2], "w");
        if (!out)
        {
            free(arr);
            fclose(in);
            return READ_ERR;
        }
        print(out, beg, n);
    }
    free(arr);
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}