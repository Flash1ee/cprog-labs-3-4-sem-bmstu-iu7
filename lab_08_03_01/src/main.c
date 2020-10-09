#include <stdio.h>
#include <stdlib.h>





#include "retcodes.h"
#include "matrix.h"
int main(int argc, char *argv[])
{
    size_t row_a, col_a;
    if (scanf("%zu %zu", &row_a, &col_a) != 2)
    {
        return INPUT_ERR;
    }

    size_t row_b, col_b;
    if (scanf("%zu %zu", &row_b, &col_b) != 2)
    {
        return INPUT_ERR;
    }

    matrix_t **src_frst = allocate_matrix(row_a, col_a);
    matrix_t **src_sec = allocate_matrix(row_b, col_b);
    
    if (!src_frst || !src_sec)
    {
        return ALLOCATION_ERR;
    }

    

    return EXIT_SUCCESS;
}