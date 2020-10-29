#include "check_test.h"

START_TEST(form_sq_matrix_del_average_row)
{
    int rows = 4;
    int cols = 3;
    int del_row = 1;
    matrix_t **expect = allocate_matrix(rows - 1, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows - 1, cols, 1);
    for (int i = del_row; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            expect[i][j] = (i + 1) * cols + j;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[del_row][2] = 100;
    form_sq_matrix(test, &rows, &cols, ROW);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST
START_TEST(form_sq_matrix_del_first_row)
{
    int rows = 4;
    int cols = 3;
    int del_row = 0;
    matrix_t **expect = allocate_matrix(rows - 1, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows - 1, cols, 1);
    for (int i = del_row; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            expect[i][j] = (i + 1) * cols + j;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[del_row][2] = 100;
    form_sq_matrix(test, &rows, &cols, ROW);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST
START_TEST(form_sq_matrix_del_last_row)
{
    int rows = 4;
    int cols = 3;
    int del_row = 3;
    matrix_t **expect = allocate_matrix(rows - 1, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows - 1, cols, 1);
    for (int i = del_row; i < rows - 1; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            expect[i][j] = (i + 1) * cols + j;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[del_row][2] = 100;
    form_sq_matrix(test, &rows, &cols, ROW);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST

START_TEST(form_sq_matrix_del_average_col)
{
    int rows = 4;
    int cols = 5;
    int del_col = 2;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = del_col; j < cols; j++)
        {
            expect[i][j] = i * cols + j + 1;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[0][del_col] = 100;
    form_sq_matrix(test, &rows, &cols, COL);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST
START_TEST(form_sq_matrix_del_last_col)
{
    int rows = 4;
    int cols = 5;
    int del_col = 4;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = del_col; j < cols; j++)
        {
            expect[i][j] = i * cols + j + 1;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[0][del_col] = 100;
    form_sq_matrix(test, &rows, &cols, COL);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST
START_TEST(form_sq_matrix_del_first_col)
{
    int rows = 4;
    int cols = 5;
    int del_col = 0;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = del_col; j < cols; j++)
        {
            expect[i][j] = i * cols + j + 1;
        }
    }
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    fill(test, rows, cols, 1);
    test[0][del_col] = 100;
    form_sq_matrix(test, &rows, &cols, COL);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free_matrix(expect);
    free_matrix(test);
}
END_TEST

Suite *form_sq_matrix_suite(void)
{
    Suite *t;
    TCase *test_del_row;
    TCase *test_del_col;

    t = suite_create("form_sq_matrix_test");

    test_del_row = tcase_create("del_rows");
    tcase_add_test(test_del_row, form_sq_matrix_del_average_row);
    tcase_add_test(test_del_row, form_sq_matrix_del_first_row);
    tcase_add_test(test_del_row, form_sq_matrix_del_last_row);

    test_del_col = tcase_create("del_cols");
    tcase_add_test(test_del_col, form_sq_matrix_del_average_col);
    tcase_add_test(test_del_col, form_sq_matrix_del_last_col);
    tcase_add_test(test_del_col, form_sq_matrix_del_first_col);

    suite_add_tcase(t, test_del_row);
    suite_add_tcase(t, test_del_col);

    return t;
}