#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retcodes.h"

#define ROW 1
#define COL 2

typedef long matrix_t;

matrix_t **allocate_matrix(int rows, int columns);
void free_matrix(matrix_t **data);

void new_size_by_min(int *size_new, int row_src, int col_src, int *flag);

int input(matrix_t *src[], int rows, int cols);
void output(matrix_t *src[], int rows, int cols);

int form_sq_matrix(matrix_t *src[], int *row, int *col, int size_sq, int flag);
/**
*@brief Поиск строки с максимальным элементом, который встретился первым в строке, обходом по столбцам
*
*@param src Матрица
*@param rows Кол-во строк
*@param cols Кол-во столбцов
*@return int Индекс строки
 */

int get_row(matrix_t *src[], int rows, int cols);
int get_col(matrix_t *src[], int rows, int cols);

void del_row(int rows, int cols, char *beg, int row_ind);
void del_col(char *beg, int rows, int cols, int col_ind);

void new_arr_by_max(matrix_t *src[], int *size_src, int size_new);

void add_rows(matrix_t *src[], int size_src, int size_new);
void add_cols(matrix_t *src[], int size_src, int size_new);
matrix_t **copy_elem(matrix_t *src[], int rows_src, int cols_src, int rows_dst, int cols_dst);
int calculate(matrix_t **src_frst, matrix_t **src_sec, int size_sq_frst, int size_sq_sec, int power_one, int power_two);
int multiply(matrix_t **frst, matrix_t **sec, int size);

#endif // __MATRIX_H__