#include "key.h"
#include "bug.h"
#include "check_key.h"

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
    char *arr = {'\0'};
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
    free(dst_a);

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
    free(dst_a);
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
    free(dst_a);

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