#include "utils.h"

int form_sq_matrix(matrix_t *src[], int *row, int *col, int flag)
{
    if (!src || !row || !col || (flag != ROW && flag != COL))
    {
        return ARG_ERR;
    }
    char *begin = (char *)src + *row * sizeof(matrix_t *);
    int index = -1;
    int iter = abs((int)*col - (int)*row);
    if (flag == ROW)
    {
        for (int i = 0; i < iter; i++)
        {
            index = get_row(src, *row, *col);
            //printf("ind del row = %zu\n", index);
            del_row(*row, *col, begin, index);
            *row -= 1;
        }
    }
    else if (flag == COL)
    {
        for (int i = 0; i < iter; i++)
        {
            index = get_col(src, *row, *col);
            del_col(src, begin, *row, *col, index);
            *col -= 1;
        }
    }
    return EXIT_SUCCESS;
}
int get_col(matrix_t *src[], int rows, int cols)
{
    if (!src || rows < 0 || cols < 0)
    {
        return -1;
    }
    int ind_col = 0;
    matrix_t max = **src;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
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
void del_col(matrix_t *src[], char *beg, int rows, int cols, int col_ind)
{
    // size_t cur_cols = cols;
    beg++;
    for (int i = 0; i < rows; i++)
    {
        for (int j = col_ind; j < cols - 1; j++)
        {
            src[i][j] = src[i][j + 1];
        }
        // printf("MAMA\n");
        // memmove(beg + sizeof(matrix_t) * (i * cols + col_ind),
        //     beg + sizeof(matrix_t) * (i * cols + col_ind + 1),
        //     sizeof(matrix_t) * (cols - col_ind - 1));
        // output(src, rows, cols);
        // printf("\n\n");
    }
}
int get_row(matrix_t *src[], int rows, int cols)
{
    if (rows < 0 || cols < 0 || !src)
    {
        return -1;
    }
    size_t ind_row = 0;
    matrix_t max = **src;

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
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
void del_row(int rows, int cols, char *beg, int row_ind)
{
    // output(src, rows - 1, cols);
    // printf("\n");

    // for (int i = row_ind; i < rows - 1; i++)
    // {
    //     src[i] = src[i + 1];
    // }
    // printf("after swap pointers\n");
    // output(src, rows - 1, cols);
    // printf("\n");

    if (row_ind != rows - 1)
    {
        memmove(beg + sizeof(matrix_t) * cols * row_ind,
            beg + sizeof(matrix_t) * cols * (row_ind + 1),
            sizeof(matrix_t) * cols * (rows - row_ind - 1));
    }
    // output(src, rows - 1, cols);
    // printf("\n");
}

void new_size_by_min(int *size_new, int row_src, int col_src, int *flag)
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
void new_size_by_max(int *size_new, int size_frst, int size_sec)
{
    if (size_frst > size_sec)
    {
        *size_new = size_frst;
    }
    else
    {
        *size_new = size_sec;
    }
}
void new_arr_by_max(matrix_t *src[], int *size_src, int size_new)
{
    int add_count = size_new - *size_src;

    add_rows(src, *size_src, add_count);
    add_cols(src, *size_src, add_count);
    *size_src = size_new;
}

void add_rows(matrix_t *src[], int size_src, int count)
{
    matrix_t average = 0;
    int tmp_size = size_src;
    for (int i = 0; i < count; i++)
    {
        for (int c = 0; c < size_src; c++)
        {
            for (int r = 0; r < tmp_size; r++)
            {
                average += src[r][c];
            }
            average = floor(average / (double)tmp_size);
            src[tmp_size][c] = average;
            average = 0;
        }
        tmp_size += 1;
    }
}
void add_cols(matrix_t *src[], int size_src, int count)
{
    int max;
    int tmp_size = size_src;
    for (int i = 0; i < count; i++)
    {
        for (int r = 0; r < count + size_src; r++)
        {
            max = src[r][0];
            for (int c = 0; c < tmp_size; c++)
            {
                if (src[r][c] > max)
                {
                    max = src[r][c];
                }
            }
            src[r][tmp_size] = max;
        }
        tmp_size += 1;
    }
}
matrix_t **copy_elem(matrix_t *src[], int rows_src, int cols_src, int rows_dst, int cols_dst)
{
    if (!src || !rows_src || !cols_src || !rows_dst || !cols_dst)
    {
        return NULL;
    }
    matrix_t **tmp = allocate_matrix(rows_dst, cols_dst);
    if (!tmp)
    {
        return NULL;
    }
    for (int r = 0; r < rows_src; r++)
    {
        for (int c = 0; c < cols_src; c++)
        {
            tmp[r][c] = src[r][c];
        }
    }
    return tmp;
}
int calculate(matrix_t **src_frst, matrix_t **src_sec, int size_sq_frst, int size_sq_sec, int power_one, int power_two)
{
    if (!src_frst || !src_sec || size_sq_sec != size_sq_frst)
    {
        return ARG_ERR;
    }
    if (size_sq_frst < 0 || power_one < 0 || power_two < 0)
    {
        return ARG_ERR;
    }
    if (power_one != 0)
    {
        matrix_t **first = allocate_matrix(size_sq_frst, size_sq_frst);
        if (!first)
        {
            return ALLOCATION_ERR;
        }
        for (int i = 0; i < size_sq_sec; i++)
        {
            for (int j = 0; j < size_sq_frst; j++)
            {
                first[i][j] = src_frst[i][j];
            }
        }
        for (int i = 0; i < power_one - 1; i++)
        {
            multiply(src_frst, first, size_sq_frst);
            // printf("POWER i frst = %zu:\n", i);
            // output(src_frst, size_sq_frst, size_sq_frst);
            // printf("\n");
        }
        free_matrix(first);
    }
    else
    {
        make_identity(src_frst, size_sq_frst);
    }

    if (power_two != 0)
    {
        matrix_t **sec = allocate_matrix(size_sq_sec, size_sq_sec);
        if (!sec)
        {
            return ALLOCATION_ERR;
        }
        for (int i = 0; i < size_sq_sec; i++)
        {
            for (int j = 0; j < size_sq_sec; j++)
            {
                sec[i][j] = src_sec[i][j];
            }
        }
        for (int i = 0; i < power_two - 1; i++)
        {
            multiply(src_sec, sec, size_sq_sec);
            // printf("POWER i sec = %zu:\n", i);
            // output(src_sec, size_sq_sec, size_sq_sec);
            // printf("\n");
        }
        free_matrix(sec);
    }
    else
    {
        make_identity(src_sec, size_sq_sec);
    }
    multiply(src_frst, src_sec, size_sq_frst);
    // printf("\n");
    // output(src_frst, size_sq_frst, size_sq_frst);
    return EXIT_SUCCESS;
}
int multiply(matrix_t **frst, matrix_t **sec, int size)
{
    matrix_t res[size][size];
    matrix_t tmp = 0;
    for (int r_frst = 0; r_frst < size; r_frst++)
    {
        for (int c_sec = 0; c_sec < size; c_sec++)
        {
            for (int c_frst = 0; c_frst < size; c_frst++)
            {
                tmp += frst[r_frst][c_frst] * sec[c_frst][c_sec];
            }
            res[r_frst][c_sec] = tmp;
            tmp = 0;
        }
    }
    for (int r = 0; r < size; r++)
    {
        for (int c = 0; c < size; c++)
        {
            frst[r][c] = res[r][c];
        }
    }
    return EXIT_SUCCESS;
}
void make_identity(matrix_t *src[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                src[i][j] = 1;
            }
            else
            {
                src[i][j] = 0;
            }
        }
    }
}
matrix_t **form_matrix_by_sq_max(matrix_t **src[], int *rows_src, int cols_src, int rows_new, int cols_new)
{
    if (!src || !(*src) || !rows_src || *rows_src < 1 || cols_src < 1 || *rows_src != cols_src)
    {
        return NULL;
    }
    if (rows_new < 1 || cols_new < 1 || rows_new != cols_new)
    {
        return NULL;
    }
    if (rows_new != *rows_src)
    {
        matrix_t **new = copy_elem(*src, *rows_src, cols_src, rows_new, cols_new);
        if (!new)
        {
            return NULL;
        }
        new_arr_by_max(new, rows_src, rows_new);
        free_matrix(*src);
        *src = new;
        return *src;
    }
    return *src;
}