#include <limits.h>
#include "check_my_snprintf_long.h"

START_TEST(snprintf_one_long)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a = 2020;
    sprintf(num, "%ld", a);

    int my_n = my_snprintf(my, strlen(num) + 1, "%ld", a);
    int n = snprintf(res, strlen(num) + 1, "%ld", a);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_few_long)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {2020, 201, 2, -1};

    size_t len = 0;
    for (size_t i = 0; i < 4; i++)
    {
        sprintf(num, "%ld", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    int my_n = my_snprintf(my, len + 1, "%ld%ld%ld%ld", a[0], a[1], a[2], a[3]);
    int n = snprintf(res, len + 1, "%ld%ld%ld%ld", a[0], a[1], a[2], a[3]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_long_with_text)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%ld", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "mama%ld%ld%ldpapa", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "mama%ld%ld%ldpapa", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_text_between_long)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%ld", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%ldmama%ldpapa%ld", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "%ldmama%ldpapa%ld", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_long_with_spaces)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {2020, -201, -1, -7, 666};

    size_t len_text = 4;
    size_t len = 0;

    for (size_t i = 0; i < 5; i++)
    {
        sprintf(num, "%ld", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%ld %ld %ld %ld %ld", a[0], a[1], a[2], a[3], a[4]);
    int n = snprintf(res, len + 1, "%ld %ld %ld %ld %ld", a[0], a[1], a[2], a[3], a[4]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_size_less_symbols)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%ld", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%ldmamaPAPAPAAPAPA%ldpapaOP%ld", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "%ldmamaPAPAPAAPAPA%ldpapaOP%ld", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST

START_TEST(snprintf_max_long)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    long a[] = {LONG_MAX, LONG_MIN};

    size_t len = 0;
    for (size_t i = 0; i < 4; i++)
    {
        my_itoa(a[i], num, 10);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    int my_n = my_snprintf(my, len + 1, "%ld%ld", a[0], a[1]);
    int n = snprintf(res, len + 1, "%ld%ld", a[0], a[1]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST

Suite *my_snprintf_long_suite(void)
{
    Suite *t;
    TCase *tests;

    t = suite_create("my_snprintf_long_test");

    tests = tcase_create("long");
    tcase_add_test(tests, snprintf_one_long);
    tcase_add_test(tests, snprintf_few_long);
    tcase_add_test(tests, snprintf_long_with_text);
    tcase_add_test(tests, snprintf_text_between_long);
    tcase_add_test(tests, snprintf_long_with_spaces);
    tcase_add_test(tests, snprintf_size_less_symbols);
    tcase_add_test(tests, snprintf_max_long);

    suite_add_tcase(t, tests);
    return t;
}
