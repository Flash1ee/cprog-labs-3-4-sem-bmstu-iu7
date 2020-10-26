#include "films.h"
#include "check_test.h"


START_TEST(bin_search_pos_title)
{
    Field bin_key = TITLE;
    size_t n = 3;
    long res_expect = 1;
    char key[] = "Kameron";

    cinema **list_src = create_cinema_list(n);
    ck_assert_ptr_nonnull(list_src);

    list_src[0]->name = strdup("Titanic");
    list_src[0]->title = strdup("Kameron");
    list_src[0]->year = 1997;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[2]->name = strdup("Harry Potter and the PS");
    list_src[2]->title = strdup("Kolambus");
    list_src[2]->year = 2001;
    ck_assert_ptr_nonnull(list_src[2]->name);
    ck_assert_ptr_nonnull(list_src[2]->title);

    list_src[1]->name = strdup("Avatar");
    list_src[1]->title = strdup("Kameron");
    list_src[1]->year = 2009;
    ck_assert_ptr_nonnull(list_src[1]->name);
    ck_assert_ptr_nonnull(list_src[1]->title);

    long res = bin_search(list_src, bin_key, key, n);

    ck_assert_int_eq(res_expect, res);
    free_list(list_src, n);
}
END_TEST

START_TEST(bin_search_pos_name)
{
    Field bin_key = NAME;
    size_t n = 3;
    long res_expect = 2;
    char key[] = "Titanic";

    cinema **list_src = create_cinema_list(n);
    ck_assert_ptr_nonnull(list_src);

    list_src[2]->name = strdup("Titanic");
    list_src[2]->title = strdup("Kameron");
    list_src[2]->year = 1997;
    ck_assert_ptr_nonnull(list_src[2]->name);
    ck_assert_ptr_nonnull(list_src[2]->title);

    list_src[1]->name = strdup("Harry Potter and the PS");
    list_src[1]->title = strdup("Kolambus");
    list_src[1]->year = 2001;
    ck_assert_ptr_nonnull(list_src[1]->name);
    ck_assert_ptr_nonnull(list_src[1]->title);

    list_src[0]->name = strdup("Avatar");
    list_src[0]->title = strdup("Kameron");
    list_src[0]->year = 2009;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    long res = bin_search(list_src, bin_key, key, n);

    ck_assert_int_eq(res_expect, res);
    free_list(list_src, n);
}
END_TEST

START_TEST(bin_search_pos_year)
{
    Field bin_key = YEAR;
    size_t n = 3;
    long res_expect = 0;
    char key[] = "1997";

    cinema **list_src = create_cinema_list(n);
    ck_assert_ptr_nonnull(list_src);

    list_src[0]->name = strdup("Titanic");
    list_src[0]->title = strdup("Kameron");
    list_src[0]->year = 1997;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[1]->name = strdup("Harry Potter and the PS");
    list_src[1]->title = strdup("Kolambus");
    list_src[1]->year = 2001;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[2]->name = strdup("Avatar");
    list_src[2]->title = strdup("Kameron");
    list_src[2]->year = 2009;
    ck_assert_ptr_nonnull(list_src[2]->name);
    ck_assert_ptr_nonnull(list_src[2]->title);

    long res = bin_search(list_src, bin_key, key, n);

    ck_assert_int_eq(res_expect, res);
    free_list(list_src, n);
}
END_TEST
START_TEST(bin_search_pos_not_found)
{
    Field bin_key = YEAR;
    size_t n = 3;
    long res_expect = -1;
    char key[] = "2020";

    cinema **list_src = create_cinema_list(n);
    ck_assert_ptr_nonnull(list_src);

    list_src[0]->name = strdup("Titanic");
    list_src[0]->title = strdup("Kameron");
    list_src[0]->year = 1997;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[1]->name = strdup("Harry Potter and the PS");
    list_src[1]->title = strdup("Kolambus");
    list_src[1]->year = 2001;
    ck_assert_ptr_nonnull(list_src[0]->name);
    ck_assert_ptr_nonnull(list_src[0]->title);

    list_src[2]->name = strdup("Avatar");
    list_src[2]->title = strdup("Kameron");
    list_src[2]->year = 2009;
    ck_assert_ptr_nonnull(list_src[2]->name);
    ck_assert_ptr_nonnull(list_src[2]->title);

    long res = bin_search(list_src, bin_key, key, n);

    ck_assert_int_eq(res_expect, res);
    free_list(list_src, n);
}
END_TEST

Suite *bin_search_suite(void)
{
    Suite *t;

    TCase *pos_test;

    t = suite_create("bin_search_test");
    pos_test = tcase_create("positives");
    tcase_add_test(pos_test, bin_search_pos_not_found);
    tcase_add_test(pos_test, bin_search_pos_year);
    tcase_add_test(pos_test, bin_search_pos_name);
    tcase_add_test(pos_test, bin_search_pos_title);
    suite_add_tcase(t, pos_test);
    return t;
}