#include "check_test.h"

START_TEST(copy_elem_sq)
{
    int rows = 5;
    int cols = 5;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, 1);
    matrix_t **res = copy_elem(expect, rows, cols, rows, cols);
    ck_assert_ptr_nonnull(res);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(res[i][j], expect[i][j]);
        }
    }
    free(res);
    free(expect);
}
END_TEST
START_TEST(copy_elem_not_sq)
{
    int rows = 7;
    int cols = 5;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, 1);
    matrix_t **res = copy_elem(expect, rows, cols, rows, cols);
    ck_assert_ptr_nonnull(res);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(res[i][j], expect[i][j]);
        }
    }
    free(res);
    free(expect);
}
END_TEST
START_TEST(copy_elem_not_sq_neg_elems)
{
    int rows = 7;
    int cols = 5;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_nonnull(expect);
    fill(expect, rows, cols, -1);
    matrix_t **res = copy_elem(expect, rows, cols, rows, cols);
    ck_assert_ptr_nonnull(res);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ck_assert_int_eq(res[i][j], expect[i][j]);
        }
    }
    free(res);
    free(expect);
}
END_TEST
START_TEST(copy_elem_null_ptr)
{
    int rows = 7;
    int cols = 5;
    matrix_t **res = copy_elem(NULL, rows, cols, rows, cols);
    ck_assert_ptr_null(res);
}
END_TEST
START_TEST(copy_elem_neg_arg_one)
{
    int rows = -7;
    int cols = 5;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_null(expect);
    matrix_t **res = copy_elem(NULL, rows, cols, rows, cols);
    ck_assert_ptr_null(res);
}
END_TEST
START_TEST(copy_elem_neg_arg_two)
{
    int rows = 7;
    int cols = -5;
    matrix_t **expect = allocate_matrix(rows, cols);
    ck_assert_ptr_null(expect);
    matrix_t **res = copy_elem(NULL, rows, cols, rows, cols);
    ck_assert_ptr_null(res);
}
END_TEST

Suite *make_copy_suite(void)
{
    Suite *t;
    TCase *test_pos;
    TCase *test_neg;


    t = suite_create("make_copy_test");
    

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, copy_elem_sq);
    tcase_add_test(test_pos, copy_elem_not_sq);
    tcase_add_test(test_pos, copy_elem_not_sq_neg_elems);

    test_neg = tcase_create("negatives");
    tcase_add_test(test_neg, copy_elem_null_ptr);
    tcase_add_test(test_neg, copy_elem_neg_arg_one);
    tcase_add_test(test_neg, copy_elem_neg_arg_two);

    suite_add_tcase(t, test_pos);
    suite_add_tcase(t, test_neg);

    return t;
}