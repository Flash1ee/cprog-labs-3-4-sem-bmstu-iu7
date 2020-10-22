#include "check_test.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_get_row;
    Suite *s_get_col;
    
    SRunner *runner_get_row;
    SRunner *runner_get_col;


    s_get_row = get_row_suite();
    s_get_col = get_col_suite();

    runner_get_row = srunner_create(s_get_row);
    runner_get_col = srunner_create(s_get_col);


    srunner_run_all(runner_get_row, CK_VERBOSE);
    srunner_run_all(runner_get_col, CK_VERBOSE);


    no_failed += srunner_ntests_failed(runner_get_row);
    no_failed += srunner_ntests_failed(runner_get_col);

    srunner_free(runner_get_row);
    srunner_free(runner_get_col);


    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}