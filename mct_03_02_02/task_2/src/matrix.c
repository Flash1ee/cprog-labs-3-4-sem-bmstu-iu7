#include "matrix.h"

matrix_t *allocate_matrix(size_t rows, size_t cols)
{
    matrix_t *temp = malloc(sizeof(matrix_t));
    if (!temp)
    {
        return NULL;
    }
    double **data = calloc(rows, sizeof(double*));
    if (!data)
    {
        free(temp);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = malloc(sizeof(double) * cols);
        if (!data)
        {
            free_matrix(temp);
            return NULL;
        }
    }
    temp->rows = rows;
    temp->cols = cols;
    return temp;
}
void free_matrix(matrix_t *arr)
{
    for (size_t i = 0; i < arr->rows; i++)
    {
        free(arr->data[i]);
    }
    free(arr);
}