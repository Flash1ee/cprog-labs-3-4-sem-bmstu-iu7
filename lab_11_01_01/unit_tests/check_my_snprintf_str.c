#include "check_my_snprintf_str.h"

START_TEST(snprintf_one_str)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    const char *src = "MaMaPaPa";
    int my_n = my_snprintf(my, strlen(src) + 1, "%s", src);
    int n_res = snprintf(res, strlen(src) + 1, "%s", src);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_few_str)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    const char *src_a = "Hello";
    const char *src_b = "World";
    const char *src_c = "My Friend!";

    size_t len = strlen(src_a) + strlen(src_b) + strlen(src_c);

    int my_n = my_snprintf(my, len + 1, "%s%s%s", src_a, src_b, src_c);
    int n_res = snprintf(res, len + 1, "%s%s%s", src_a, src_b, src_c);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_strs_with_format_text)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    const char *src_a = "Hello";
    const char *src_b = "World";
    const char *src_c = "My Friend!";

    size_t len = strlen(src_a) + strlen(src_b) + strlen(src_c);
    size_t len_format_text = 20;
    len += len_format_text;

    int my_n = my_snprintf(my, len + 1, "%s Hello %s%s How are you?", src_a, src_b, src_c);
    int n_res = snprintf(res, len + 1, "%s Hello %s%s How are you?", src_a, src_b, src_c);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_ints_strs_with_format_text)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    const char *src_a = "Hello";
    const char *src_b = "World";
    const char *src_c = "My Friend!";

    size_t len = strlen(src_a) + strlen(src_b) + strlen(src_c);
    size_t len_format_text = 20;
    len += len_format_text;

    int my_n = my_snprintf(my, len + 1, "%s Hello %s%s How are you?", src_a, src_b, src_c);
    int n_res = snprintf(res, len + 1, "%s Hello %s%s How are you?", src_a, src_b, src_c);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_str_with_other_spec)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num_buf[BUF] = {0};
    const char *src_a = "This is ";
    const char *src_b = " year";

    int num = 2020;
    sprintf(num_buf, "%d", num);

    size_t len = strlen(src_a) + strlen(src_b) + strlen(num_buf);

    int my_n = my_snprintf(my, len + 1, "%s%d%s", src_a, num, src_b);
    int n_res = snprintf(res, len + 1, "%s%d%s", src_a, num, src_b);
    

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_str_size_more_len)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num_buf[BUF] = {0};
    const char *src_a = "This is ";
    const char *src_b = " year";

    int num = 2020;
    sprintf(num_buf, "%d", num);

    size_t len = strlen(src_a) + strlen(src_b) + strlen(num_buf) + 10;

    int my_n = my_snprintf(my, len + 1, "%s%d%s", src_a, num, src_b);
    int n_res = snprintf(res, len + 1, "%s%d%s", src_a, num, src_b);


    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_str_size_less_len)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num_buf[BUF] = {0};
    const char *src_a = "This is ";
    const char *src_b = " year";

    int num = 2020;
    sprintf(num_buf, "%d", num);

    size_t len = strlen(src_a) + strlen(src_b) + strlen(num_buf) - 10;

    int my_n = my_snprintf(my, len + 1, "%s%d%s", src_a, num, src_b);
    int n_res = snprintf(res, len + 1, "%s%d%s", src_a, num, src_b);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_format_err)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num_buf[BUF] = {0};
    const char *src_a = "This is ";

    size_t len = strlen(src_a);

    int my_n = my_snprintf(my, len + 1, "%#", src_a);
    int n_res = snprintf(res, len + 1, "%#", src_a);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST
START_TEST(snprintf_str_size_zero)
{
    char my[BUF] = {0};
    char res[BUF] = {0};

    char num_buf[BUF] = {0};
    const char *src_a = "This is ";

    size_t len = strlen(src_a);

    int my_n = my_snprintf(my, 0, "%s", src_a);
    int n_res = snprintf(res, 0, "%s", src_a);

    ck_assert_int_eq(my_n, n_res);
    ck_assert_str_eq(my, res);
}
END_TEST

Suite *my_snprintf_str_suite(void)
{
    Suite *t;
    TCase *tests;

    t = suite_create("my_snprintf_str_test");

    tests = tcase_create("str");
    tcase_add_test(tests, snprintf_one_str);
    tcase_add_test(tests, snprintf_few_str);
    tcase_add_test(tests, snprintf_strs_with_format_text);
    tcase_add_test(tests, snprintf_ints_strs_with_format_text);
    tcase_add_test(tests, snprintf_str_with_other_spec);
    tcase_add_test(tests, snprintf_str_size_more_len);
    tcase_add_test(tests, snprintf_str_size_less_len);
    tcase_add_test(tests, snprintf_format_err);
    tcase_add_test(tests, snprintf_str_size_zero);



    suite_add_tcase(t, tests);
    return t;
}
