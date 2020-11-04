#define _GNU_SOURCE
#include <stdio.h>
#include "array.h"
#include "validate.h"


int main()
{
    size_t count = 0;
    size_t n = 0;
    char *buf = NULL;

    if (getline(&buf, &n, stdin) == -1)
    {
        free(buf);
        return READ_ERR;
    }
    if (valid_u_num(buf, &count) || !count)
    {
        free(buf);
        return READ_ERR;
    }
    free(buf);

    inttype *arr = allocate_vector(count);
    if (!arr)
    {
        free_vector(arr);
        return ALLOCATION_ERR;
    }

    if (input(arr, count))
    {
        free_vector(arr);
        return READ_ERR;
    }
    output(arr);

    if (delete_prime_ind(arr))
    {
        free_vector(arr);
        return ARG_ERR;
    }

    output(arr);
    free_vector(arr);

    
    return EXIT_SUCCESS;
}
