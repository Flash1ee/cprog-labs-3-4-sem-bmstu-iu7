#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>


#define ALLOCATION_ERR 1

typedef struct {
    double **data;
    size_t rows;
    size_t cols;
} matrix_t;


matrix_t *allocate_matrix(size_t rows, size_t cols);
void free_matrix(matrix_t *arr);

#endif //_MATRIX_H_