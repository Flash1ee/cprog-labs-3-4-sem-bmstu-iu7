#include "check_my_snprintf_i_int.h"

START_TEST(snprintf_one_i_int)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a = 2020;
    sprintf(num, "%i", a);

    int my_n = my_snprintf(my, strlen(num) + 1, "%i", a);
    int n = snprintf(res, strlen(num) + 1, "%i", a);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_few_i_ints)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a[] = {2020, 201, 2, -1};

    size_t len = 0;
    for (size_t i = 0; i < 4; i++)
    {
        sprintf(num, "%i", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    int my_n = my_snprintf(my, len + 1, "%i%i%i%i", a[0], a[1], a[2], a[3]);
    int n = snprintf(res, len + 1, "%i%i%i%i", a[0], a[1], a[2], a[3]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_i_ints_with_text)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%i", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "mama%i%i%ipapa", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "mama%i%i%ipapa", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_text_between_i_ints)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%i", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%imama%ipapa%i", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "%imama%ipapa%i", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_i_ints_with_spaces)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a[] = {2020, -201, -1, -7, 666};

    size_t len_text = 4;
    size_t len = 0;

    for (size_t i = 0; i < 5; i++)
    {
        sprintf(num, "%i", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%i %i %i %i %i", a[0], a[1], a[2], a[3], a[4]);
    int n = snprintf(res, len + 1, "%i %i %i %i %i", a[0], a[1], a[2], a[3], a[4]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_size_less_symbols)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num[BUF] = {0};
    int a[] = {2020, -201, -1};

    size_t len_text = 8;
    size_t len = 0;

    for (size_t i = 0; i < 3; i++)
    {
        sprintf(num, "%i", a[i]);
        len += strlen(num);
        memset(num, 0, BUF);
    }
    len += len_text;
    int my_n = my_snprintf(my, len + 1, "%imamaPAPAPAAPAPA%ipapaOP%i", a[0], a[1], a[2]);
    int n = snprintf(res, len + 1, "%imamaPAPAPAAPAPA%ipapaOP%i", a[0], a[1], a[2]);

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
Suite *my_snprintf_i_int_suite(void)
{
    Suite *t;
    TCase *tests;

    t = suite_create("my_snprintf_i_int_test");

    tests = tcase_create("i_int");
    tcase_add_test(tests, snprintf_one_i_int);
    tcase_add_test(tests, snprintf_few_i_ints);
    tcase_add_test(tests, snprintf_i_ints_with_text);
    tcase_add_test(tests, snprintf_text_between_i_ints);
    tcase_add_test(tests, snprintf_i_ints_with_spaces);
    tcase_add_test(tests, snprintf_size_less_symbols);

    suite_add_tcase(t, tests);
    return t;
}
