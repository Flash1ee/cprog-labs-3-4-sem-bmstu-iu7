#include "check_test.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_get_row;
    
    SRunner *runner_get_row;

    s_get_row = get_row_suite();

    runner_get_row = srunner_create(s_get_row);

    srunner_run_all(runner_get_row, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_get_row);
    srunner_free(runner_get_row);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}