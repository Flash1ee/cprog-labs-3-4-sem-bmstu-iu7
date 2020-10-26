#include "check_test.h"


int main(void)
{
    int no_failed = 0;
    Suite *s_is_year;

    SRunner *runner_is_year;

    s_is_year = is_year_suite();

    runner_is_year = srunner_create(s_is_year);

    srunner_run_all(runner_is_year, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_is_year);

    srunner_free(runner_is_year);

    return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}