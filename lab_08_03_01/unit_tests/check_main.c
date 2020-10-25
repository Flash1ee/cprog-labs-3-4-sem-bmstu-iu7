#include "check_test.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_get_row;
    Suite *s_get_col;
    Suite *s_form_sq_matrix;
    Suite *s_new_size_by_min;
    Suite *s_new_size_by_max;
    Suite *s_new_arr_by_max;
    Suite *s_make_identity;
    Suite *s_make_copy;



    SRunner *runner_get_row;
    SRunner *runner_get_col;
    SRunner *runner_form_sq_matrix;
    SRunner *runner_new_size_by_min;
    SRunner *runner_new_size_by_max;
    SRunner *runner_new_arr_by_max;
    SRunner *runner_make_identity;
    SRunner *runner_make_copy;



    s_get_row = get_row_suite();
    s_get_col = get_col_suite();
    s_form_sq_matrix = form_sq_matrix_suite();
    s_new_size_by_min = new_size_by_min_suite();
    s_new_size_by_max = new_size_by_max_suite();
    s_new_arr_by_max = new_arr_by_max_suite();
    s_make_identity = make_identity_suite();
    s_make_copy = make_copy_suite();
    


    runner_get_row = srunner_create(s_get_row);
    runner_get_col = srunner_create(s_get_col);
    runner_form_sq_matrix = srunner_create(s_form_sq_matrix);
    runner_new_size_by_min = srunner_create(s_new_size_by_min);
    runner_new_size_by_max = srunner_create(s_new_size_by_max);
    runner_new_arr_by_max = srunner_create(s_new_arr_by_max);
    runner_make_identity = srunner_create(s_make_identity);
    runner_make_copy = srunner_create(s_make_copy);


    srunner_run_all(runner_get_row, CK_VERBOSE);
    srunner_run_all(runner_get_col, CK_VERBOSE);
    srunner_run_all(runner_form_sq_matrix, CK_VERBOSE);
    srunner_run_all(runner_new_size_by_min, CK_VERBOSE);
    srunner_run_all(runner_new_size_by_max, CK_VERBOSE);
    srunner_run_all(runner_new_arr_by_max, CK_VERBOSE);
    srunner_run_all(runner_make_identity, CK_VERBOSE);
    srunner_run_all(runner_make_copy, CK_VERBOSE);



    no_failed += srunner_ntests_failed(runner_get_row);
    no_failed += srunner_ntests_failed(runner_get_col);
    no_failed += srunner_ntests_failed(runner_form_sq_matrix);
    no_failed += srunner_ntests_failed(runner_new_size_by_min);
    no_failed += srunner_ntests_failed(runner_new_size_by_max);
    no_failed += srunner_ntests_failed(runner_new_arr_by_max);
    no_failed += srunner_ntests_failed(runner_make_identity);
    no_failed += srunner_ntests_failed(runner_make_copy);




    srunner_free(runner_get_row);
    srunner_free(runner_get_col);
    srunner_free(runner_form_sq_matrix);
    srunner_free(runner_new_size_by_min);
    srunner_free(runner_new_size_by_max);
    srunner_free(runner_new_arr_by_max);
    srunner_free(runner_make_identity);
    srunner_free(runner_make_copy);




    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}