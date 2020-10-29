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


int input(matrix_t *src[], int rows, int cols);
void output(matrix_t *src[], int rows, int cols);



#endif // __MATRIX_H__