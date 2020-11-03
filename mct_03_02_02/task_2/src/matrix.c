#include "matrix.h"

matrix_t *allocate_matrix(size_t rows, size_t cols)
{
    matrix_t *temp = malloc(sizeof(matrix_t));
    if (!temp)
    {
        return NULL;
    }
    num_t **data = calloc(rows, sizeof(num_t*));
    if (!data)
    {
        free(temp);
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = malloc(sizeof(num_t) * cols);
        if (!data[i])
        {
            free_matrix(temp);
            return NULL;
        }
    }
    temp->data = data;
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
int input(matrix_t *arr)
{
    for (size_t i = 0; i < arr->rows; i++)
    {
        for (size_t j = 0; j < arr->cols; j++)
        {
            if (scanf(ScNum, &(arr->data[i][j])) != 1)
            {
                return READ_ERR;
            }
        }
    }
    return EXIT_SUCCESS;
}
void output(matrix_t *arr)
{
    for (size_t i = 0; i < arr->rows; i++)
    {
        for (size_t j = 0; j < arr->cols; j++)
        {
            printf(PrNum" ", arr->data[i][j]);
        }
        printf("\n");
    }
}
void del_max_col(matrix_t *arr)
{
    size_t delete_col = get_max_col(arr);
    for (size_t i = 0; i < arr->rows; i++)
    {
        for (size_t j = delete_col + 1; j < arr->cols; j++)
        {
            arr->data[i][j-1] = arr->data[i][j];
        }
    }
    arr->cols -= 1;
}
size_t get_max_col(matrix_t *arr)
{
    size_t i_max = 0;
    size_t max_sum = 0;
    int cur_sum = 0;

    for (size_t i = 0; i < arr->cols; i++)
    {
        cur_sum = 0;

        for (size_t j = 0; j < arr->rows; j++)
        {
            cur_sum += arr->data[j][i];
        }
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
            i_max = i;
        }
    }
    return i_max;
}