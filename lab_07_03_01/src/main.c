#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/err.h"
#include "../inc/io.h"
#include "../inc/sort.h"


int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
        return ARG_ERR;
    if (argc == 4 && !strcmp(argv[3], "f"))
        return ARG_ERR;
    int key;

    key = 1 ? argc == 4 : 0;
    FILE *in, *out;

    in = fopen(argv[1], "r");
    if (!in)
        return READ_ERR;
    size_t n = 0;
    printf("n = %zu\n", n);
    if (f_long_cnt(in, &n))
    {
        fclose(in);
        return EMPTY_FILE;
    }

    printf("n = %zu\n", n);

    long *arr = (long *)malloc(n * sizeof(long));
    if (!arr)
    {
        fclose(in);
        return ALLOCATION_ERR;
    }

    long *beg = arr;
    long *end = arr + n;
    fseek(in, 0, SEEK_SET);
    if (fill(in, beg, end))
    {
        free(arr);
        fclose(in);
        return READ_ERR;
    }
    mysort(arr, n, sizeof(long), cmp_l);

    for (size_t i = 0; i < n; i++)
    printf("%ld ", arr[i]);

    free(arr);
    fclose(in);

    return EXIT_SUCCESS;
}