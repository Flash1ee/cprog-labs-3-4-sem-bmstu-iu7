#include <stdio.h>
#include "array.h"


int main()
{
    size_t count = 0;
    if (scanf("%zu", &count) != 1)
    {
        return READ_ERR;
    }
    inttype *arr = allocate_vector(count);
    if (!arr)
    {
        return ALLOCATION_ERR;
    }
    if (input(arr, count))
    {
        free_vector(arr);
        return READ_ERR;
    }
    output(arr);

    int rc = delete_prime_ind(arr);
    if (rc == ARG_ERR)
    {
        free_vector(arr);
        return ARG_ERR;
    }

    output(arr);
    free_vector(arr);
    return EXIT_SUCCESS;
}
