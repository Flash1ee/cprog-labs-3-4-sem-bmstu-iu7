#include "matrix.h"

matrix_t **allocate_matrix(size_t rows, size_t columns)
{
    if (!rows || !columns)
    {
        return ARG_ERR;
    }
    matrix_t **data = NULL;
    data = (matrix_t **)malloc(sizeof(matrix_t *) * rows +
                               sizeof(matrix_t) * rows * columns);
    if (!data)
    {
        return NULL;
    }
    for (size_t i = 0; i < rows; i++)
    {
        data[i] = (matrix_t *)((char *)data + sizeof(matrix_t *) * rows +
                               i * columns * sizeof(matrix_t));
    }
    return data;
}
void matrix_free(matrix_t **data)
{
    free(data);
}

int form_sq_matrix(matrix_t *src[], size_t *row, size_t *col, size_t size_sq, size_t flag)
{
    if (!src || !row || !col || !size_sq || (flag != ROW && flag != COL))
    {
        return ARG_ERR;
    }
    char *begin = (char *)src + *row * sizeof(matrix_t *);
    size_t index = -1;
    size_t iter = abs(*col - *row);
    if (flag == ROW)
    {
        for (size_t i = 0; i < iter; i++)
        {
            index = get_row(src, *row, *col);
            del_row(src, *row, *col, begin, index);
            *row -= 1;
        }
    }
    else if (flag == COL)
    {
        for (size_t i = 0; i < iter; i++)
        {
            index = get_col(src, *row, *col);
            del_col(src, *row, *col, begin, index);
            *col -= 1;
        }
    }
    return EXIT_SUCCESS;
}
size_t get_col(matrix_t *src[], size_t rows, size_t cols)
{
    size_t ind_col = 0;
    size_t max = **src;

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            if (src[j][i] > max)
            {
                max = src[j][i];
                ind_col = i;
            }
        }
    }
    return ind_col;
}
void del_col(matrix_t *src[], size_t rows, size_t cols, char *beg, size_t col_ind)
{
    size_t ind_col = 0;
    size_t max = **src;

    for (size_t i = 0; i < rows; i++)
    {
        memmove(beg + sizeof(matrix_t) * (i * cols + col_ind),
                beg + sizeof(matrix_t) * (i * cols + col_ind + 1),
                sizeof(matrix_t) * ((rows - i - 1) * cols + cols - col_ind - 1));
    }
}
size_t get_row(matrix_t *src[], size_t rows, size_t cols)
{
    size_t ind_row = 0;
    size_t max = **src;

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            if (src[j][i] > max)
            {
                max = src[j][i];
                ind_row = j;
            }
        }
    }
    return ind_row;
}
void del_row(matrix_t *src[], size_t rows, size_t cols, char *beg, size_t row_ind)
{
    for (size_t i = row_ind; i < rows - 1; i++)
    {
        src[i] = src[i + 1];
    }
    memmove(beg + sizeof(matrix_t) * cols * row_ind, beg + sizeof(matrix_t) * cols * (row_ind + 1),
            sizeof(matrix_t) * cols * (rows - row_ind - 1));
    memmove(beg - 1, beg, sizeof(matrix_t) * (rows - 1) * cols);
}

// Поиск строки с максимальным элементом, который встретился первым в строке, обходам по столбцам
size_t search_row(matrix_t *src[], size_t rows, size_t cols)
{
    matrix_t max = **src;
    size_t n_string = -1;

    for (size_t i = 0; i < cols; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            if (*src[rows + j * cols + i] > max)
            {
                max = *src[rows + j * cols + i];
                n_string = j;
            }
        }
    }
    return n_string;
}
void new_size(size_t *size_new, size_t row_src, size_t col_src, int *flag)
{
    /*
    flag - переменная которая является сигналом для формирования матрицы
    */
    if (row_src < col_src)
    {
        *size_new = row_src;
        *flag = COL;
    }
    else
    {
        *size_new = col_src;
        *flag = ROW;
    }
}