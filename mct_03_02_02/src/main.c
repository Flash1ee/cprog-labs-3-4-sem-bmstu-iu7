#define _GNU_SOURCE
#include <stdio.h>
#include "matrix.h"
#include "validate.h"


int main()
{
    // Считаем, что ввод - беззнаковый...

    size_t rows, cols;
    char *buf = NULL;
    size_t n = 0;
    if (getline(&buf, &n, stdin) == -1)
    {
        free(buf);
        return READ_ERR;
    }
    if (valid_u_num(buf, &rows) || !rows)
    {
        free(buf);
        return VALIDATE_ERR;
    }
    free(buf);
    n = 0;
    if (getline(&buf, &n, stdin) == -1)
    {
        free(buf);
        return READ_ERR;
    }
    if (valid_u_num(buf, &cols) || !cols)
    {
        free(buf);
        return VALIDATE_ERR;
    }
    free(buf);
    // if (scanf("%zu", &rows) != 1 || scanf("%zu", &cols) != 1)
    // {
    //     return READ_ERR;
    // }
    
    matrix_t *matrix = allocate_matrix(rows, cols);
    if (!matrix)
    {
        return ALLOCATION_ERR;
    }
    if (input(matrix))
    {
        free_matrix(matrix);
        return READ_ERR;
    }

    output(matrix);
    
    del_max_col(matrix);
    
    printf("\n");
    output(matrix);
    
    free_matrix(matrix);

    return EXIT_SUCCESS;
}