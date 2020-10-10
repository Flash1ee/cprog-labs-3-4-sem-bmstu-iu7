#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>
#include <string.h>
#include "retcodes.h"


#define ROW 1
#define COL 2

typedef long matrix_t;


matrix_t **allocate_matrix(size_t rows, size_t columns);
void matrix_free(matrix_t **data);

int input(size_t rows, size_t columns, matrix_t *arr);
void new_size(size_t *size_new, size_t row_src, size_t col_src, int *flag);


int form_sq_matrix(matrix_t *src[], size_t *row, size_t *col, size_t size_sq, size_t flag);
/**
*@brief Поиск строки с максимальным элементом, который встретился первым в строке, обходом по столбцам
*
*@param src Матрица
*@param rows Кол-во строк
*@param cols Кол-во столбцов
*@return int Индекс строки
 */

size_t get_row(matrix_t *src[], size_t rows, size_t cols);
size_t get_col(matrix_t *src[], size_t rows, size_t cols);

void del_row(matrix_t *src[], size_t rows, size_t cols, char *beg, size_t row_ind);
void del_col(matrix_t *src[], size_t rows, size_t cols, char *beg, size_t col_ind);



#endif // __MATRIX_H__