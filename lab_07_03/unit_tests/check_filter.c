#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "../inc/filter.h"
#include "../inc/err.h"

// Test cases for cmp_i
START_TEST(test_last_neg_only_pos)
{
    char arr[] = {1, 2, 3, 4, 5};
    int rc = 0;
    int res = 5;
    rc = last_neg(arr, arr + res, sizeof(int));
    ck_assert_int_eq(rc, res);
}
END_TEST

START_TEST(test_last_neg_one_el)
{
    char arr[] = {};
    int rc = 0;
    int res = 0;
    rc = last_neg(arr, arr + res, sizeof(int));
    ck_assert_int_eq(rc, res);
}
END_TEST

START_TEST(test_last_neg_with_neg)
{
    char arr[] = {-1, 1, 2, 3, 4, 5, 6};
    size_t len_arr = 7;
    int rc = 0;
    int res = 0;
    rc = last_neg(arr, arr + len_arr, sizeof(int));
    ck_assert_int_eq(rc, res);
}
END_TEST

START_TEST(test_key_nullptr)
{
    int arr[] = {1, 2, 3, 4};
    int rc = 0;

    int *dst_a = NULL;
    int *dst_b = NULL;

    rc = key(NULL, NULL, &dst_a, &dst_b);
    ck_assert_int_eq(rc, PTR_ERR);

    rc = key(arr, NULL, &dst_a, &dst_b);
    ck_assert_int_eq(rc, PTR_ERR);

    rc = key(NULL, arr, &dst_a, &dst_b);
    ck_assert_int_eq(rc, PTR_ERR);
}
END_TEST

START_TEST(test_key_all_pos)
{
    int arr[] = {1, 2, 3, 4};
    int res[] = {1, 2, 3, 4};

    size_t res_len = 4;
    int rc = 0;

    int *dst_a = NULL;
    int *dst_b = NULL;

    rc = key(arr, arr + res_len, &dst_a, &dst_b);
    ck_assert_int_eq(rc, 0);

    ck_assert_mem_eq(arr, res, sizeof(int) * res_len);
}
END_TEST

START_TEST(test_key_with_neg)
{
    int arr[] = {1, -2, 3, 4};
    int res[] = {1};

    size_t arr_len = 4;
    size_t res_len = 1;
    int rc = 0;

    int *dst_a = NULL;
    int *dst_b = NULL;

    rc = key(arr, arr + arr_len, &dst_a, &dst_b);
    ck_assert_int_eq(rc, 0);

    ck_assert_mem_eq(arr, res, sizeof(int) * res_len);
}
END_TEST

START_TEST(test_key_with_neg_on_last_pos)
{
    int arr[] = {1, 2, 3, -4};
    int res[] = {1, 2, 3};

    size_t arr_len = 4;
    size_t res_len = 3;
    int rc = 0;

    int *dst_a = NULL;
    int *dst_b = NULL;

    rc = key(arr, arr + arr_len, &dst_a, &dst_b);
    ck_assert_int_eq(rc, 0);

    ck_assert_mem_eq(arr, res, sizeof(int) * res_len);
}
END_TEST

Suite *last_neg_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("last_neg");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_last_neg_one_el);
    tcase_add_test(tc_pos, test_last_neg_only_pos);
    tcase_add_test(tc_pos, test_last_neg_with_neg);

    suite_add_tcase(s, tc_pos);

    return s;
}

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("key");

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_all_pos);
    tcase_add_test(tc_pos, test_key_with_neg);
    tcase_add_test(tc_pos, test_key_with_neg_on_last_pos);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_nullptr);

    suite_add_tcase(s, tc_neg);
    return s;
}
int main(void)
{
    int no_failed = 0;
    Suite *s1;
    Suite *s2;
    SRunner *runner_last_neg;
    SRunner *runner_key;

    s1 = last_neg_suite();
    s2 = key_suite();
    runner_last_neg = srunner_create(s1);
    runner_key = srunner_create(s2);
    srunner_run_all(runner_last_neg, CK_VERBOSE);
    srunner_run_all(runner_key, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_last_neg);
    no_failed += srunner_ntests_failed(runner_key);

    srunner_free(runner_last_neg);
    srunner_free(runner_key);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}