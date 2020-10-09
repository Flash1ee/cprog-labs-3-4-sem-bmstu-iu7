#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <stdlib.h>

#include "retcodes.h"

typedef long matrix_t;
int input(size_t rows, size_t columns, matrix_t *arr);
matrix_t **allocate_matrix(size_t rows, size_t columns);
void matrix_free(matrix_t **data);

#endif // __MATRIX_H__