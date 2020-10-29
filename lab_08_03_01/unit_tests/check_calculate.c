#include "check_test.h"
START_TEST(calculate_bad_arg_arr)
{
    int size_frst = 2;
    int size_sec = 2;
    int p_one = 1;
    int p_two = 1;

    int rc = calculate(NULL, NULL, size_frst, size_sec, p_one, p_two);
    ck_assert_int_ne(0, rc);
}
END_TEST
START_TEST(calculate_bad_arg_size)
{
    int size_frst = -2;
    int size_sec = 2;
    int p_one = 1;
    int p_two = 1;

    int rc = calculate(NULL, NULL, size_frst, size_sec, p_one, p_two);
    ck_assert_int_ne(0, rc);
}
END_TEST
START_TEST(calculate_bad_not_eq_size)
{
    int size_frst = 3;
    int size_sec = 2;
    int p_one = 1;
    int p_two = 1;
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);

    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_ne(0, rc);
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST
START_TEST(calculate_bad_power_neg)
{
    int size_frst = 3;
    int size_sec = 2;
    int p_one = -1;
    int p_two = 1;
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);

    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_ne(0, rc);
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST

START_TEST(calculate_pos_p_one_zero)
{
    int size_frst = 3;
    int size_sec = 3;
    int p_one = 0;
    int p_two = 1;
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);
    fill(arr1, size_frst, size_frst, 1);
    fill(arr2, size_frst, size_frst, 1);

    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_eq(0, rc);
    for (int i = 0; i < size_frst; i++)
    {
        for (int j = 0; j < size_frst; j++)
            {
                ck_assert_int_eq(arr1[i][j], arr2[i][j]);
            }
    }
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST
START_TEST(calculate_pos_p_two_zero)
{
    int size_frst = 3;
    int size_sec = 3;
    int p_one = 1;
    int p_two = 0;
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    matrix_t **expect = allocate_matrix(size_frst, size_frst);
    ck_assert_ptr_nonnull(expect);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);
    fill(arr1, size_frst, size_frst, 1);
    fill(arr2, size_frst, size_frst, 1);
    fill(expect, size_frst, size_frst, 1);
    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_eq(0, rc);
    for (int i = 0; i < size_frst; i++)
    {
        for (int j = 0; j < size_frst; j++)
            {
                ck_assert_int_eq(arr1[i][j], expect[i][j]);
            }
    }
    free_matrix(arr1);
    free_matrix(arr2);
    free_matrix(expect);
}
END_TEST
START_TEST(calculate_pos_p_one_one)
{
    int size_frst = 3;
    int size_sec = 3;
    int p_one = 1;
    int p_two = 2;
    matrix_t expect[3][3] = {
        {180, 234, 288},
        {558, 720, 882},
        {936, 1206, 1476}};
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);
    fill(arr1, size_frst, size_frst, 1);
    fill(arr2, size_frst, size_frst, 1);
    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_eq(0, rc);
    for (int i = 0; i < size_frst; i++)
    {
        for (int j = 0; j < size_frst; j++)
            {
                ck_assert_int_eq(arr1[i][j], expect[i][j]);
            }
    }
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST
START_TEST(calculate_pos_p_two_one)
{
    int size_frst = 3;
    int size_sec = 3;
    int p_one = 2;
    int p_two = 1;
    matrix_t expect[3][3] = {
        {180, 234, 288},
        {558, 720, 882},
        {936, 1206, 1476}};
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);
    fill(arr1, size_frst, size_frst, 1);
    fill(arr2, size_frst, size_frst, 1);
    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_eq(0, rc);
    for (int i = 0; i < size_frst; i++)
    {
        for (int j = 0; j < size_frst; j++)
            {
                ck_assert_int_eq(arr1[i][j], expect[i][j]);
            }
    }
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST
START_TEST(calculate_pos_p_one_eq_p_two)
{
    int size_frst = 3;
    int size_sec = 3;
    int p_one = 2;
    int p_two = 2;
    matrix_t expect[3][3] = {
        {2430, 3132, 3834},
        {7452, 9612, 11772},
        {12474, 16092, 19710}
    };
    matrix_t **arr1 = allocate_matrix(size_frst, size_frst);
    matrix_t **arr2 = allocate_matrix(size_sec, size_sec);
    ck_assert_ptr_nonnull(arr1);
    ck_assert_ptr_nonnull(arr2);
    fill(arr1, size_frst, size_frst, 1);
    fill(arr2, size_frst, size_frst, 1);
    int rc = calculate(arr1, arr2, size_frst, size_sec, p_one, p_two);
    ck_assert_int_eq(0, rc);
    for (int i = 0; i < size_frst; i++)
    {
        for (int j = 0; j < size_frst; j++)
            {
                ck_assert_int_eq(arr1[i][j], expect[i][j]);
            }
    }
    free_matrix(arr1);
    free_matrix(arr2);
}
END_TEST


Suite *calculate_suite(void)
{
    Suite *t;
    TCase *test_pos;
    TCase *test_neg;

    t = suite_create("calculate_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, calculate_pos_p_one_zero);
    tcase_add_test(test_pos, calculate_pos_p_two_zero);
    tcase_add_test(test_pos, calculate_pos_p_one_one);
    tcase_add_test(test_pos, calculate_pos_p_two_one);
    tcase_add_test(test_pos, calculate_pos_p_one_eq_p_two);

    suite_add_tcase(t, test_pos);

    test_neg = tcase_create("negatives");
    tcase_add_test(test_neg, calculate_bad_arg_arr);
    tcase_add_test(test_neg, calculate_bad_arg_size);
    tcase_add_test(test_neg, calculate_bad_not_eq_size);
    tcase_add_test(test_neg, calculate_bad_power_neg);

    suite_add_tcase(t, test_neg);

    return t;
}