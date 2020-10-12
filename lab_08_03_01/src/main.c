#include <stdio.h>
#include <stdlib.h>

#include "retcodes.h"
#include "matrix.h"
#include "utils.h"

int main(void)
{
    size_t row_a, col_a;
    if (scanf("%zu %zu", &row_a, &col_a) != 2 || row_a < 1 || col_a < 1)
    {
        return INPUT_ERR;
    }
    matrix_t **src_frst = allocate_matrix(row_a, col_a);
    if (!src_frst)
    {
        return ALLOCATION_ERR;
    }

    if (input(src_frst, row_a, col_a))
    {
        return READ_ERR;
    }

    size_t row_b, col_b;
    if (scanf("%zu %zu", &row_b, &col_b) != 2 || row_b < 1 || col_b < 1)
    {
        return INPUT_ERR;
    }
    matrix_t **src_sec = allocate_matrix(row_b, col_b);
    if (!src_sec)
    {
        return ALLOCATION_ERR;
    }

    if (input(src_sec, row_b, col_b))
    {
        return READ_ERR;
    }
    // printf("FRST:\n");
    // output(src_frst, row_a, col_a);
    // printf("\nSEC:\n");
    // output(src_sec, row_b, col_b);

    size_t size_sq_frst = 0;
    size_t size_sq_sec = 0;

    int flag_frst = 0;
    int flag_sec = 0;

    new_size_by_min(&size_sq_frst, row_a, col_a, &flag_frst);
    new_size_by_min(&size_sq_sec, row_b, col_b, &flag_sec);

    form_sq_matrix(src_frst, &row_a, &col_a, size_sq_frst, flag_frst);
    form_sq_matrix(src_sec, &row_b, &col_b, size_sq_sec, flag_sec);

    // printf("FRST RES:\n");
    // output(src_frst, size_sq_frst, size_sq_frst);
    // printf("\n\n");
    // printf("SEC RES:\n");
    // output(src_sec, size_sq_sec, size_sq_sec);

    size_t size_new = 0;
    if (size_sq_frst > size_sq_sec)
    {
        size_new = size_sq_frst;
    }
    else
    {
        size_new = size_sq_sec;
    }

    if (size_sq_frst != size_new)
    {
        matrix_t **src_frst_new = copy_elem(src_frst, size_sq_frst, size_sq_frst, size_new, size_new);
        if (src_frst_new)
        {
            free(src_frst);
            src_frst = src_frst_new;
            new_arr_by_max(src_frst, &size_sq_frst, size_new);
        }
        else
        {
            free(src_frst);
            free(src_sec);
            return ALLOCATION_ERR;
        }
    }

    if (size_sq_sec != size_new)
    {
        matrix_t **src_sec_new = copy_elem(src_sec, size_sq_sec, size_sq_sec, size_new, size_new);
        if (src_sec_new)
        {
            free(src_sec);
            src_sec = src_sec_new;
            new_arr_by_max(src_sec, &size_sq_sec, size_new);
        }
        else
        {
            free(src_frst);
            free(src_sec);
            return ALLOCATION_ERR;
        }
    }
    // printf("FRST AFTER ADD:\n");
    // output(src_frst, size_sq_frst, size_sq_frst);
    // printf("\n\n");
    // printf("SEC AFTER ADD:\n");
    // output(src_sec, size_sq_sec, size_sq_sec);

    size_t power_one, power_two;
    if (scanf("%zu%zu", &power_one, &power_two) != 2)
    {
        free(src_frst);
        free(src_sec);
        return INPUT_ERR;
    }
    // printf("\n\n%zu %zu \n\n", power_one, power_two);

    calculate(src_frst, src_sec, size_sq_frst, size_sq_sec, power_one, power_two);

    // printf("FRST AFTER ADD:\n");
    output(src_frst, size_sq_frst, size_sq_frst);
    // printf("\n\n");
    // printf("SEC AFTER ADD:\n");
    // output(src_sec, size_sq_sec, size_sq_sec);

    free(src_frst);
    free(src_sec);

    return EXIT_SUCCESS;
}