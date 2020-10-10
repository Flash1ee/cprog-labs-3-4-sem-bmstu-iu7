#include <stdio.h>
#include <stdlib.h>

#include "retcodes.h"
#include "matrix.h"
#include "utils.h"
int main(int argc, char *argv[])
{
    size_t row_a, col_a;
    if (scanf("%zu %zu", &row_a, &col_a) != 2 || row_a < 1 || col_a < 1)
    {
        return INPUT_ERR;
    }

    size_t row_b, col_b;
    if (scanf("%zu %zu", &row_b, &col_b) != 2 || row_b < 1 || col_b < 1)
    {
        return INPUT_ERR;
    }

    matrix_t **src_frst = allocate_matrix(row_a, col_a);
    matrix_t **src_sec = allocate_matrix(row_b, col_b);

    if (!src_frst || !src_sec)
    {
        return ALLOCATION_ERR;
    }

    size_t size_sq_frst = 0;
    size_t size_sq_sec = 0;

    int flag_frst = 0;
    int flag_sec = 0;

    new_size(&size_sq_frst, row_a, col_a, &flag_frst);
    new_size(&size_sq_sec, row_b, col_b, &flag_sec);

    form_sq_matrix(src_frst, row_a, col_a, size_sq_frst, flag_frst);
    form_sq_matrix(src_sec, row_b, col_b, size_sq_sec, flag_sec);


    
    return EXIT_SUCCESS;
}