#include "matrix.h"

matrix_t **allocate_matrix(int rows, int columns)
{
    if (!rows || !columns)
    {
        return NULL;
    }
    matrix_t **data = NULL;
    data = (matrix_t **)malloc(sizeof(matrix_t *) * rows + sizeof(matrix_t) * rows * columns);
    if (!data)
    {
        return NULL;
    }
    for (int i = 0; i < rows; i++)
    {
        data[i] = (matrix_t *)((char *)data + sizeof(matrix_t *) * rows + i * columns * sizeof(matrix_t));
    }
    return data;
}
void free_matrix(matrix_t **data)
{
    free(data);
}

int input(matrix_t *src[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (scanf("%ld", &src[i][j]) != 1)
            {
                return READ_ERR;
            }
        }
    }
    return EXIT_SUCCESS;
}
void output(matrix_t *src[], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%ld ", src[i][j]);
        }
        printf("\n");
    }
}

