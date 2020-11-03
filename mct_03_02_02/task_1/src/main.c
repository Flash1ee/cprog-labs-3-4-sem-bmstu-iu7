#include <stdio.h>
#include "array.h"


int main()
{
    size_t count = 0;
    if (scanf("%zu", &count) != 1 || !count)
    {
        return READ_ERR;
    }
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
