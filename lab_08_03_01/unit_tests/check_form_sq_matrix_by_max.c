#include "check_test.h"

START_TEST(form_matrix_by_sq_max_bad_ptr_arr)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 2;
    int col_d = 2;

    matrix_t **rc = form_matrix_by_sq_max(NULL, &row_s, col_s, row_d, col_d);
    ck_assert_ptr_null(rc);
}
END_TEST
START_TEST(form_matrix_by_sq_max_bad_ptr_row)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 2;
    int col_d = 2;
    matrix_t **test = allocate_matrix(row_s, col_s);
    ck_assert_ptr_nonnull(test);
    matrix_t **rc = form_matrix_by_sq_max(&test, NULL, col_s, row_d, col_d);
    ck_assert_ptr_null(rc);
    free_matrix(test);

}
END_TEST
START_TEST(form_matrix_by_sq_max_bad_row_size)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 2;
    int col_d = 2;
    matrix_t **test = allocate_matrix(row_s, col_s);
    ck_assert_ptr_nonnull(test);
    matrix_t **rc = form_matrix_by_sq_max(&test, &row_s, -1, row_d, col_d);
    ck_assert_ptr_null(rc);
    free_matrix(test);
}
END_TEST
START_TEST(form_matrix_by_sq_max_no_sq)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 3;
    int col_d = 2;
    matrix_t **test = allocate_matrix(row_s, col_s);
    ck_assert_ptr_nonnull(test);
    matrix_t **rc = form_matrix_by_sq_max(&test, &row_s, col_s, row_d, col_d);
    ck_assert_ptr_null(rc);
    free_matrix(test);
}
END_TEST
START_TEST(form_sq_matrix_by_max_pos_void)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 2;
    int col_d = 2;

    matrix_t **expect = allocate_matrix(row_s, col_s);
    matrix_t **test = allocate_matrix(row_d, col_d);
    fill(expect, row_s, col_s,1);
    fill(test, row_d, col_d,1);
    ck_assert_ptr_nonnull(test);
    ck_assert_ptr_nonnull(expect);

    matrix_t **res = form_matrix_by_sq_max(&test, &row_s, col_s, row_d, col_d);
    ck_assert_ptr_nonnull(res);
    ck_assert_int_eq(row_s, row_d);
    for (int i = 0; i < row_s; i++)
    {
        for (int j = 0; j < col_s; j++)
        {
            ck_assert_int_eq(res[i][j], expect[i][j]);
        }
    }
    free_matrix(res);
    free_matrix(expect);
}
END_TEST
START_TEST(form_sq_matrix_by_max_pos_add_row)
{
    int row_s = 2;
    int col_s = 2;
    int row_d = 5;
    int col_d = 5;

    matrix_t expect[5][5] = {
        {0, 1, 1, 1, 1},
        {2, 3, 3, 3, 3},
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2}};
    matrix_t **test = allocate_matrix(row_d, col_d);
    
    fill(test, row_s, col_s,1);
    ck_assert_ptr_nonnull(test);
    matrix_t **res = form_matrix_by_sq_max(&test, &row_s, col_s, row_d, col_d);
    ck_assert_ptr_nonnull(res);
    ck_assert_int_eq(row_s, row_d);
    for (int i = 0; i < row_s; i++)
    {
        for (int j = 0; j < col_s; j++)
        {
            ck_assert_int_eq(res[i][j], expect[i][j]);
        }
    }
    free_matrix(res);
}
END_TEST



Suite *form_matrix_by_sq_max_suite(void)
{
    Suite *t;
    TCase *test_pos;
    TCase *test_neg;

    t = suite_create("form_sq_matrix_by_max_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, form_sq_matrix_by_max_pos_void);
    tcase_add_test(test_pos, form_sq_matrix_by_max_pos_add_row);

    suite_add_tcase(t, test_pos);

    test_neg = tcase_create("negatives");
    tcase_add_test(test_neg, form_matrix_by_sq_max_bad_ptr_arr);
    tcase_add_test(test_neg, form_matrix_by_sq_max_bad_ptr_row);
    tcase_add_test(test_neg, form_matrix_by_sq_max_bad_row_size);
    tcase_add_test(test_neg, form_matrix_by_sq_max_no_sq);


    suite_add_tcase(t, test_neg);

    return t;
}
