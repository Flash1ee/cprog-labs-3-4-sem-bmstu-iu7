#ifndef _CHECK_TEST_H_
#define _CHECK_TEST_H_

#include <check.h>
#include <stdlib.h>
#include "utils.h"
#include "matrix.h"


void fill(matrix_t **arr, int rows, int cols, int flag);

Suite *get_row_suite(void);
Suite *get_col_suite(void);
Suite *form_sq_matrix_suite(void);


#endif  // _CHECK_TEST_H_