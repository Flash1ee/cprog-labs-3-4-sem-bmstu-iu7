#include "check_test.h"

START_TEST(shift_cinema_neg_frst_arg_null)
{
    cinema src;
    ck_assert_int_ne(0, shift_cinema(NULL, &src));
}
END_TEST

START_TEST(shift_cinema_neg_sec_arg_null)
{
    cinema src;
    ck_assert_int_ne(0, shift_cinema(&src, NULL));
}
END_TEST
START_TEST(shift_cinema_pos_swap)
{
    size_t n = 3;
    cinema **list_src = create_cinema_list(n);
    ck_assert_ptr_nonnull(list_src);

    list_src[0]->name = strdup("Titanic");
    list_src[0]->title = strdup("Kameron");
    list_src[0]->year = 1997;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[2]->name = strdup("Avatar");
    list_src[2]->title = strdup("Kameron");
    list_src[2]->year = 2009;
    ck_assert_ptr_nonnull(list_src[2]->name);
    ck_assert_ptr_nonnull(list_src[2]->title);
    ck_assert_int_eq(0, shift_cinema(list_src[1], list_src[2]));

    ck_assert_ptr_eq(list_src[1]->title, list_src[2]->title);
    ck_assert_ptr_eq(list_src[1]->name, list_src[2]->name);
    ck_assert_int_eq(list_src[1]->year, list_src[2]->year);

    free_list(list_src, n - 1);

}
END_TEST

Suite *shift_cinema_suite(void)
{
    Suite *t;

    TCase *pos_test;
    TCase *neg_test;


    t = suite_create("shift_cinema_test");
    pos_test = tcase_create("positives");
    tcase_add_test(pos_test, shift_cinema_pos_swap);
    suite_add_tcase(t, pos_test);

    neg_test = tcase_create("negatives");
    tcase_add_test(neg_test, shift_cinema_neg_frst_arg_null);
    tcase_add_test(neg_test, shift_cinema_neg_sec_arg_null);
    suite_add_tcase(t, neg_test);


    suite_add_tcase(t, pos_test);
    return t;
}