#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include "retcodes.h"
#include "matrix.h"

matrix_t **form_matrix_by_sq_max(matrix_t **src[], int *rows_src, int cols_src, int rows_new, int cols_new);
int form_sq_matrix(matrix_t *src[], int *row, int *col, int flag);
void new_arr_by_max(matrix_t *src[], int *size_src, int size_new);
void add_rows(matrix_t *src[], int size_src, int size_new);
void add_cols(matrix_t *src[], int size_src, int size_new);
matrix_t **copy_elem(matrix_t *src[], int rows_src, int cols_src, int rows_dst, int cols_dst);
void new_size_by_min(int *size_new, int row_src, int col_src, int *flag);
void new_size_by_max(int *size_new, int size_frst, int size_sec);
int rounding_down(matrix_t average, int tmp_size);
int get_row(matrix_t *src[], int rows, int cols);
int get_col(matrix_t *src[], int rows, int cols);
void del_row(int rows, int cols, char *beg, int row_ind);
void del_col(matrix_t *src[], char *beg, int rows, int cols, int col_ind);
void make_identity(matrix_t *src[], int size);
int calculate(matrix_t **src_frst, matrix_t **src_sec, int size_sq_frst, int size_sq_sec, int power_one, int power_two);
int multiply(matrix_t **frst, matrix_t **sec, int size);



#endif // __UTILS_H__