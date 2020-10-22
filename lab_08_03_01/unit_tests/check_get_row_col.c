#include "utils.h"
#include "check.h"

START_TEST(get_row_pos_end)
{
    int rows = 4;
    int cols = 4;
    int max_row = 3;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(max_row, get_row(test, rows, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_row_pos_beg)
{
    int rows = 4;
    int cols = 4;
    int max_row = 0;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = (i * cols + j) * -1;
        }
    }
    ck_assert_int_eq(max_row, get_row(test, rows, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_row_neg_bad_ptr)
{
    int rows = 4;
    int cols = 4;
    ck_assert_int_eq(-1, get_row(NULL, rows, cols));
}
END_TEST
START_TEST(get_row_neg_bad_row)
{
    int rows = 4;
    int cols = 4;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(-1, get_row(test, -2, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_row_neg_bad_col)
{
    int rows = 4;
    int cols = 4;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(-1, get_row(test, rows, -2));
    free_matrix(test);
}
END_TEST

START_TEST(get_col_pos_end)
{
    int rows = 4;
    int cols = 4;
    int max_col = 3;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(max_col, get_col(test, rows, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_col_pos_beg)
{
    int rows = 4;
    int cols = 4;
    int max_col = 0;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = (i * cols + j) * -1;
        }
    }
    ck_assert_int_eq(max_col, get_col(test, rows, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_col_neg_bad_ptr)
{
    int rows = 4;
    int cols = 4;
    ck_assert_int_eq(-1, get_col(NULL, rows, cols));
}
END_TEST
START_TEST(get_col_neg_bad_row)
{
    int rows = 4;
    int cols = 4;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(-1, get_col(test, -2, cols));
    free_matrix(test);
}
END_TEST
START_TEST(get_col_neg_bad_col)
{
    int rows = 4;
    int cols = 4;
    matrix_t **test = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(test);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            test[i][j] = i * cols + j;
        }
    }
    ck_assert_int_eq(-1, get_col(test, rows, -2));
    free_matrix(test);
}
END_TEST

Suite *get_row_suite(void)
{
    Suite *t;
    TCase *test_pos;
    TCase *test_neg;

    t = suite_create("get_row_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, get_row_pos_beg);
    tcase_add_test(test_pos, get_row_pos_end);
    tcase_add_test(test_pos, get_row_pos_beg);

    suite_add_tcase(t, test_pos);

    test_neg = tcase_create("negatives");
    tcase_add_test(test_neg, get_row_neg_bad_ptr);
    tcase_add_test(test_neg, get_row_neg_bad_col);
    tcase_add_test(test_neg, get_row_neg_bad_row);

    suite_add_tcase(t, test_neg);

    return t;
}

Suite *get_col_suite(void)
{
    Suite *t;
    TCase *test_pos;
    TCase *test_neg;

    t = suite_create("get_col_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, get_col_pos_beg);
    tcase_add_test(test_pos, get_col_pos_end);
    tcase_add_test(test_pos, get_col_pos_beg);

    suite_add_tcase(t, test_pos);

    test_neg = tcase_create("negatives");
    tcase_add_test(test_neg, get_col_neg_bad_ptr);
    tcase_add_test(test_neg, get_col_neg_bad_col);
    tcase_add_test(test_neg, get_col_neg_bad_row);

    suite_add_tcase(t, test_neg);

    return t;
}