#include "check_my_snprintf_char.h"

START_TEST(snprintf_size_zero_no_args)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    int my_n = my_snprintf(my, 0, "");
    int n = snprintf(res, 0, "");

    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_size_zero_with_args)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char x = 'O';

    int my_n = my_snprintf(my, 0, "%c", x);
    int n = snprintf(res, 0, "%c", x);
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_no_args)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    const char *src = "mama";

    int my_n = my_snprintf(my, sizeof(src) + 1, "mama");
    int n = snprintf(res, sizeof(src) + 1, "mama");
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_one_char)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char x = 'O';

    int my_n = my_snprintf(my, sizeof(char) + 1, "%c", x);
    int n = snprintf(res, sizeof(char) + 1, "%c", x);
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_few_args)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char a = 'I';
    char b = 'U';
    char c = '7';

    int my_n = my_snprintf(my, sizeof(char) * 3 + 1, "%c%c%c", a, b, c);
    int n = snprintf(res, sizeof(char) * 3 + 1, "%c%c%c", a, b, c);
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_args_with_format_text)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char a = 'I';
    char b = 'U';
    char c = '7';

    int my_n = my_snprintf(my, sizeof(char) * 3 + 9 + 1, "COVID%c%c%cMAMA", a, b, c);
    int n = snprintf(res, sizeof(char) * 3 + 9 + 1, "COVID%c%c%cMAMA", a, b, c);
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_text_between_args)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char a = 'I';
    char b = 'U';
    char c = '7';

    int my_n = my_snprintf(my, sizeof(char) * 3 + 3 + 1, "%c%cIU7%c", a, b, c);
    int n = snprintf(res, sizeof(char) * 3 + 3 + 1, "%c%cIU7%c", a, b, c);
    ck_assert_int_eq(my_n, n);
    ck_assert_str_eq(my, res);
}
END_TEST

Suite *my_snprintf_char_suite(void)
{
    Suite *t;
    TCase *tests;

    t = suite_create("my_snprintf_char_test");

    tests = tcase_create("units");
    tcase_add_test(tests, snprintf_size_zero_no_args);
    tcase_add_test(tests, snprintf_size_zero_with_args);
    tcase_add_test(tests, snprintf_no_args);
    tcase_add_test(tests, snprintf_one_char);
    tcase_add_test(tests, snprintf_few_args);
    tcase_add_test(tests, snprintf_args_with_format_text);
    tcase_add_test(tests, snprintf_text_between_args);

    suite_add_tcase(t, tests);
    return t;
}
