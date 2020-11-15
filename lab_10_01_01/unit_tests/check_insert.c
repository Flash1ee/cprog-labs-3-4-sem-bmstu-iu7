#include "check_test.h"
#include "node.h"
#include "types.h"

START_TEST(insert_neg_elem_null)
{
    node_t c =
    {
        "third",
        NULL
    };
    node_t b =
    {
        "second",
        &c
    };
    node_t a =
    {
        "first", 
        &b
    };
    node_t *head = &a;
    node_t *before = &b;
    insert(&head, NULL, before);
    ck_assert_ptr_eq(head, &a);
    ck_assert_ptr_eq(head->next, &b);
    ck_assert_ptr_eq((head->next)->next, &c);
    ck_assert_ptr_eq(((head->next)->next)->next, c.next);
}
END_TEST
START_TEST(insert_neg_head_null)
{
    node_t a =
    {
        "first", 
        NULL
    };
    node_t new = 
    {
        "new",
        NULL
    };
    node_t *head = NULL;
    node_t *before = &a;
    insert(&head, &new, before);
    ck_assert_ptr_eq(head, NULL);
}
END_TEST
START_TEST(insert_neg_before_null)
{
    node_t c =
    {
        "third",
        NULL
    };
    node_t b =
    {
        "second",
        &c
    };
    node_t a =
    {
        "first", 
        &b
    };
    node_t new = 
    {
        "new",
        NULL
    };
    node_t *head = &a;
    node_t *before = NULL;
    insert(&head, &new, before);
    ck_assert_ptr_eq(head, &a);
    ck_assert_ptr_eq(head->next, &b);
    ck_assert_ptr_eq((head->next)->next, &c);
    ck_assert_ptr_eq(((head->next)->next)->next, c.next);
}
END_TEST
START_TEST(insert_elem_typical)
{
    node_t c =
    {
        "third",
        NULL
    };
    node_t b =
    {
        "second",
        &c
    };
    node_t a =
    {
        "first", 
        &b
    };
    node_t new = 
    {
        "new",
        NULL
    };
    node_t *head = &a;
    node_t *before = &b;
    insert(&head, &new, before);
    ck_assert_ptr_eq(head, &a);
    ck_assert_ptr_eq(head->next, &new);
    ck_assert_ptr_eq((head->next)->next, &b);
    ck_assert_ptr_eq(((head->next)->next)->next, &c);
    ck_assert_ptr_eq((((head->next)->next)->next)->next, c.next);

}
END_TEST
START_TEST(insert_head_eq_before_no_null)
{
    node_t c =
    {
        "third",
        NULL
    };
    node_t b =
    {
        "second",
        &c
    };
    node_t a =
    {
        "first", 
        &b
    };
    node_t new = 
    {
        "new",
        NULL
    };
    node_t *head = &a;
    node_t *before = &a;
    insert(&head, &new, before);
    ck_assert_ptr_eq(head, &new);
    ck_assert_ptr_eq(head->next, &a);
    ck_assert_ptr_eq((head->next)->next, &b);
    ck_assert_ptr_eq(((head->next)->next)->next, &c);
    ck_assert_ptr_eq((((head->next)->next)->next)->next, c.next);

}
END_TEST
START_TEST(insert_before_no_null_pre_last)
{
    node_t c =
    {
        "third",
        NULL
    };
    node_t b =
    {
        "second",
        &c
    };
    node_t a =
    {
        "first", 
        &b
    };
    node_t new = 
    {
        "new",
        NULL
    };
    node_t *head = &a;
    node_t *before = &b;
    insert(&head, &new, before);
    ck_assert_ptr_eq(head, &a);
    ck_assert_ptr_eq(head->next, &new);
    ck_assert_ptr_eq((head->next)->next, &b);
    ck_assert_ptr_eq(((head->next)->next)->next, &c);
    ck_assert_ptr_eq((((head->next)->next)->next)->next, c.next);
}
END_TEST

Suite *insert_suite(void)
{
    Suite *t;

    TCase *pos_test;
    TCase *neg_test;

    t = suite_create("insert_test");

    neg_test = tcase_create("negatives");
    tcase_add_test(neg_test, insert_neg_before_null);
    tcase_add_test(neg_test, insert_neg_elem_null);
    tcase_add_test(neg_test, insert_neg_head_null);
    suite_add_tcase(t, neg_test);


    pos_test = tcase_create("positives");
    tcase_add_test(pos_test, insert_before_no_null_pre_last);
    tcase_add_test(pos_test, insert_head_eq_before_no_null);
    tcase_add_test(pos_test, insert_elem_typical);
    suite_add_tcase(t, pos_test);

    return t;
}