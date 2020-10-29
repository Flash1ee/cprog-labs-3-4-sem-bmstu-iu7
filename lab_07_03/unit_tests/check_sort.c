#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "sort.h"
// Test cases for cmp_i
START_TEST(test_cmp_i_equal_values)
{
    int a, b;
    int rc = 0;
    a = b = 10;

    rc = cmp_i(&a, &b);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_cmp_i_frst_bg)
{
    int a, b;
    int rc = 0;
    a = 10;
    b = 5;
    rc = cmp_i(&a, &b);
    //gt -> rc > 0
    ck_assert_int_gt(rc, 0);
}
END_TEST

START_TEST(test_cmp_i_sec_bg)
{
    int a, b;
    int rc = 0;
    a = 5;
    b = 10;
    rc = cmp_i(&a, &b);
    //lt -> rc < 0
    ck_assert_int_lt(rc, 0);
}
END_TEST

START_TEST(test_mysort_eq_nums)
{
    int arr[] = {1, 1, 1, 1, 1};
    size_t len_arr = 5;
    int res[] = {1, 1, 1, 1, 1};
    size_t len_res = 5;

    mysort(arr, len_arr, sizeof(int), cmp_i);

    ck_assert_mem_eq(arr, res, sizeof(int) * len_res);
}
END_TEST

START_TEST(test_mysort_nums_sorted)
{
    int arr[] = {-5, 2, 10, 128, 256, 1339};
    size_t len_arr = 6;
    int res[] = {-5, 2, 10, 128, 256, 1339};
    size_t len_res = 6;

    mysort(arr, len_arr, sizeof(int), cmp_i);

    ck_assert_mem_eq(arr, res, sizeof(int) * len_res);
}
END_TEST

START_TEST(test_mysort_nums_req_swap)
{
    int arr[] = {10, 5, -3, 9, 2};
    size_t len_arr = 5;
    int res[] = {-3, 2, 5, 9, 10};
    size_t len_res = 5;

    mysort(arr, len_arr, sizeof(int), cmp_i);

    ck_assert_mem_eq(arr, res, sizeof(int) * len_res);
}
END_TEST

START_TEST(test_mysort_nums_sort_not_all)
{
    int arr[] = {10, 5, 11, 59, 200};
    size_t len_arr = 5;
    int res[] = {5, 10, 11, 59, 200};
    size_t len_res = 5;

    mysort(arr, len_arr, sizeof(int), cmp_i);

    ck_assert_mem_eq(arr, res, sizeof(int) * len_res);
}
END_TEST

START_TEST(test_mysort_one_el)
{
    int arr[] = {1};
    size_t len_arr = 1;
    int res[] = {1};
    size_t len_res = 1;
    mysort(arr, len_arr, sizeof(int), cmp_i);
    ck_assert_mem_eq(arr, res, sizeof(int) * len_res);
}
END_TEST

Suite *mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_sort");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_mysort_eq_nums);
    tcase_add_test(tc_pos, test_mysort_nums_sorted);
    tcase_add_test(tc_pos, test_mysort_nums_req_swap);
    tcase_add_test(tc_pos, test_mysort_nums_sort_not_all);
    tcase_add_test(tc_pos, test_mysort_one_el);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite *cmp_i_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("cmp_i");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_cmp_i_equal_values);
    tcase_add_test(tc_pos, test_cmp_i_frst_bg);
    tcase_add_test(tc_pos, test_cmp_i_sec_bg);

    suite_add_tcase(s, tc_pos);

    return s;
}