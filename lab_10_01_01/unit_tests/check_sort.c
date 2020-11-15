#include "check_test.h"
#include "node.h"
START_TEST(sort_neg_null_head)
{
    node_t *head = NULL;
    ck_assert_ptr_null(sort(head, comparator));
}
END_TEST

START_TEST(sort_neg_null_cmp)
{
    node_t a =
        {
            "test",
            NULL};
    node_t *head = &a;
    ck_assert_ptr_null(sort(head, NULL));
}
END_TEST
START_TEST(sort_pos_one_el)
{
    task_t arr[] = {{"Breakfast", 9, 0}, {"Dinner", 12, 0}, {"Siesta", 15, 0}};

    node_t a_res =
        {
            &(arr[0]),
            NULL};
    node_t a =
        {
            &(arr[0]),
            NULL};

    node_t *head = &a;
    
    node_t *new = sort(head, comparator);
    ck_assert_ptr_nonnull(new);
    head = new;
    ck_assert_ptr_eq(head, &a);
    ck_assert_ptr_eq(head->next, NULL);
    task_t *head_data = head->data;
    task_t *expect_data = (&(a_res))->data;
    ck_assert_str_eq(head_data->describe, expect_data->describe);
}
START_TEST(sort_pos_sorted_list)
{
    task_t arr[] = {{"Breakfast", 9, 0}, {"Dinner", 12, 0}, {"Siesta", 15, 0}};
    
    node_t expect[] = {{&(arr[0]), &(expect[1])}, {&(arr[1]), &(expect[2])}, {&(arr[2]), NULL}};

    node_t *head = &(expect[0]);
    node_t *new = sort(head, comparator);
    ck_assert_ptr_nonnull(new);
    head = new;
    ck_assert_ptr_eq(((task_t*)(head->data))->describe, arr[0].describe);
    ck_assert_ptr_eq(((task_t*)(head->next->data))->describe, arr[1].describe);
    ck_assert_ptr_eq(((task_t*)(head->next->next->data))->describe, arr[2].describe);
    ck_assert_ptr_eq(head->next->next->next, NULL);
}
END_TEST
START_TEST(sort_pos_reversed_list)
{
    task_t arr[] = {{"Siesta", 15, 0}, {"Dinner", 12, 0}, {"Breakfast", 9, 0}};
    
    node_t expect[] = {{&(arr[0]), &(expect[1])}, {&(arr[1]), &(expect[2])}, {&(arr[2]), NULL}};

    // node_t expect[] = {{&(arr[2]), &(expect[1])}, {&(arr[1]), &(expect[2])}, {&(arr[0]), NULL}};

    node_t *head = &(expect[0]);
    node_t *new = sort(head, comparator);
    ck_assert_ptr_nonnull(new);
    head = new;
    ck_assert_str_eq(((task_t*)(head->data))->describe, arr[2].describe);
    ck_assert_str_eq(((task_t*)(head->next->data))->describe, arr[1].describe);
    ck_assert_str_eq(((task_t*)(head->next->next->data))->describe, arr[0].describe);
    ck_assert_ptr_eq(head->next->next->next, NULL);

}
END_TEST
START_TEST(sort_pos_general_list)
{
    task_t arr[] = {{"Dinner", 12, 0}, {"Breakfast", 9, 0}, {"Siesta", 15, 0}};
    
    // node_t expect[] = {{&(arr[1]), &(expect[1])}, {&(arr[0]), &(expect[2])}, {&(arr[2]), NULL}};
    node_t expect[] = {{&(arr[0]), &(expect[1])}, {&(arr[1]), &(expect[2])}, {&(arr[2]), NULL}};

    node_t *head = &(expect[0]);

    node_t *new = sort(head, comparator);
    ck_assert_ptr_nonnull(new);
    head = new;
    ck_assert_str_eq(((task_t*)(head->data))->describe, arr[1].describe);
    ck_assert_str_eq(((task_t*)(head->next->data))->describe, arr[0].describe);
    ck_assert_str_eq(((task_t*)(head->next->next->data))->describe, arr[2].describe);
    ck_assert_ptr_eq(head->next->next->next, NULL);
}
END_TEST


Suite *sort_suite(void)
{
    Suite *t;

    TCase *pos_test;
    TCase *neg_test;

    t = suite_create("sort_test");

    neg_test = tcase_create("negatives");
    tcase_add_test(neg_test, sort_neg_null_cmp);
    tcase_add_test(neg_test, sort_neg_null_head);
    suite_add_tcase(t, neg_test);


    pos_test = tcase_create("positives");
    tcase_add_test(pos_test, sort_pos_general_list);
    tcase_add_test(pos_test, sort_pos_one_el);
    tcase_add_test(pos_test, sort_pos_reversed_list);
    tcase_add_test(pos_test, sort_pos_sorted_list);
    suite_add_tcase(t, pos_test);

    return t;
}
