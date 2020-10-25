#include "check_test.h"

START_TEST(make_identity_sq)
{
    int n = 4;
    matrix_t expect[4][4] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}

    };
    matrix_t **test = allocate_matrix(n, n);
    ck_assert_ptr_nonnull(test);
    make_identity(test, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ck_assert_int_eq(test[i][j], expect[i][j]);
        }
    }
    free(test);
}
END_TEST

Suite *make_identity_suite(void)
{
    Suite *t;
    TCase *test_pos;

    t = suite_create("make_identity_test");

    test_pos = tcase_create("positives");
    tcase_add_test(test_pos, make_identity_sq);

    suite_add_tcase(t, test_pos);
    return t;
}