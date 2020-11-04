#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>
#include <stdlib.h>


#define ALLOCATION_ERR 1
#define READ_ERR 2



#define ScNum "%lf"
#define PrNum "%lf"

typedef double num_t;

typedef struct {
    num_t **data;
    size_t rows;
    size_t cols;
} matrix_t;


matrix_t *allocate_matrix(size_t rows, size_t cols);
int input(matrix_t *arr);
void output(matrix_t *arr);
void free_matrix(matrix_t *arr);

void del_max_col(matrix_t *arr);
size_t get_max_col(matrix_t *arr);

#endif //_MATRIX_H_