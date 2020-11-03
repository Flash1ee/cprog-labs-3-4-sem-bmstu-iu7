#include <stdio.h>
#include "matrix.h"

int main()
{
    // Считаем, что ввод - беззнаковый...
    size_t rows, cols;
    if (scanf("%zu", &rows) != 1 || scanf("%zu", &cols) != 1)
    {
        return READ_ERR;
    }
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