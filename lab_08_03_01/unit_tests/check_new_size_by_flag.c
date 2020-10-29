#include "check_test.h"
START_TEST(new_size_by_min_cols)
{
    int size_new = 0;
    int cols = 2;
    int rows = 3;
    int flag = 0;

    int size_res = cols;
    int flag_res = ROW;

    new_size_by_min(&size_new, rows, cols, &flag);
    ck_assert_int_eq(size_new, size_res);
    ck_assert_int_eq(flag, flag_res);
}
END_TEST
START_TEST(new_size_by_min_rows)
{
    int size_new = 0;
    int cols = 3;
    int rows = 2;
    int flag = 0;

    int size_res = rows;
    int flag_res = COL;

    new_size_by_min(&size_new, rows, cols, &flag);
    ck_assert_int_eq(size_new, size_res);
    ck_assert_int_eq(flag, flag_res);
}
END_TEST
START_TEST(new_size_by_max_cols)
{
    int size_new = 0;
    int cols = 4;
    int rows = 3;

    int size_res = cols;

    new_size_by_max(&size_new, rows, cols);
    ck_assert_int_eq(size_new, size_res);
}
END_TEST
START_TEST(new_size_by_max_rows)
{
    int size_new = 0;
    int cols = 2;
    int rows = 4;

    int size_res = rows;

    new_size_by_max(&size_new, rows, cols);
    ck_assert_int_eq(size_new, size_res);
}
END_TEST

Suite *new_size_by_min_suite(void)
{
    Suite *t;
    TCase *test_pos;

    t = suite_create("new_size_by_min_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, new_size_by_min_cols);
    tcase_add_test(test_pos, new_size_by_min_rows);

    suite_add_tcase(t, test_pos);
    return t;
}
Suite *new_size_by_max_suite(void)
{
    Suite *t;
    TCase *test_pos;

    t = suite_create("new_size_by_max_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, new_size_by_max_cols);
    tcase_add_test(test_pos, new_size_by_max_rows);

    suite_add_tcase(t, test_pos);
    return t;
}