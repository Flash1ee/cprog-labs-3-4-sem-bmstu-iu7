#include "check_test.h"
#include "utils.h"

START_TEST(new_arr_by_max_add_cols_and_rows)
{
    int n_src = 2;

    const int n_dst = 5;

    matrix_t **test = allocate_matrix(n_dst, n_dst);

    ck_assert_ptr_nonnull(test);
    fill(test, n_src, n_src, 1);
    new_arr_by_max(test, &n_src, n_dst);

    matrix_t expect[5][5] = {
        {0, 1, 1, 1, 1},
        {2, 3, 3, 3, 3},
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2},
        {1, 2, 2, 2, 2}};
    ck_assert_int_eq(n_src, n_dst);
    for (int i = 0; i < n_dst; i++)
    {
        for (int j = 0; j < n_dst; j++)
        {
            ck_assert_int_eq(expect[i][j], test[i][j]);
        }
    }
    free(test);
}
END_TEST
START_TEST(new_arr_by_max_not_change_arr)
{
    int n_src = 5;

    const int n_dst = 5;

    matrix_t **test = allocate_matrix(n_dst, n_dst);

    ck_assert_ptr_nonnull(test);
    fill(test, n_src, n_src, 1);
    new_arr_by_max(test, &n_src, n_dst);

    matrix_t expect[5][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24}};
    ck_assert_int_eq(n_src, n_dst);
    for (int i = 0; i < n_dst; i++)
    {
        for (int j = 0; j < n_dst; j++)
        {
            ck_assert_int_eq(expect[i][j], test[i][j]);
        }
    }
    free(test);
}
END_TEST

Suite *new_arr_by_max_suite(void)
{
    Suite *t;
    TCase *test_pos;

    t = suite_create("new_arr_by_max_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, new_arr_by_max_add_cols_and_rows);
    tcase_add_test(test_pos, new_arr_by_max_not_change_arr);

    suite_add_tcase(t, test_pos);
    return t;
}
