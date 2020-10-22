#include "check_test.h"

void fill(matrix_t **arr, int rows, int cols, int flag)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = (i * cols + j) * flag;
        }
    }
}