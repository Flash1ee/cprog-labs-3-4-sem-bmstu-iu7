#include "check_test.h"
#include "utils.h"

START_TEST(is_year_neg_null_ptr)
{
    ck_assert_int_ne(0, is_year(NULL));
}
START_TEST(is_year_neg_not_num)
{
    char test[] = "abc";
    ck_assert_int_ne(0, is_year(test));
}
START_TEST(is_year_neg_num_with_symbols)
{
    char test[] = "1234a";
    ck_assert_int_ne(0, is_year(test));
}
START_TEST(is_year_neg_num_neg)
{
    char test[] = "-20";
    ck_assert_int_ne(0, is_year(test));
}
START_TEST(is_year_pos_num)
{
    char test[] = "2020";
    ck_assert_int_eq(0, is_year(test));
}

Suite *is_year_suite(void)
{
    Suite *t;
    TCase *pos_test;
    TCase *neg_test;

    t = suite_create("is_year_test");


    neg_test = tcase_create("negatives");
    tcase_add_test(neg_test, is_year_neg_null_ptr);
    tcase_add_test(neg_test, is_year_neg_not_num);
    tcase_add_test(neg_test, is_year_neg_num_with_symbols);
    tcase_add_test(neg_test, is_year_neg_num_neg);
    suite_add_tcase(t, neg_test);

    pos_test = tcase_create("positives");
    tcase_add_test(pos_test, is_year_pos_num);
    suite_add_tcase(t, pos_test);

    return t;
}