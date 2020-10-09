#include "matrix.h"

matrix_t **allocate_matrix(size_t rows, size_t columns)
{
    if (!rows || !columns || !arr)
    {
        return ARG_ERR;
    }
    matrix_t **data = NULL;
    data = (matrix_t **) malloc(sizeof(matrix_t*) * rows + 
                                sizeof(matrix_t) * rows * columns);
    if (!data)
    {
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = (matrix_t *) malloc((char*)data + sizeof(matrix_t*) * rows + 
                                    i * columns * sizeof(matrix_t));
    }
    return data;
}
void matrix_free(matrix_t **data)
{
    free(data);
}