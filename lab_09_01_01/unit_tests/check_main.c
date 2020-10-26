#include "check_test.h"


int main(void)
{
    int no_failed = 0;
    Suite *s_is_year;
    Suite *s_bin_search;


    SRunner *runner_is_year;
    SRunner *runner_bin_search;


    s_is_year = is_year_suite();
    s_bin_search = bin_search_suite();

    runner_is_year = srunner_create(s_is_year);
    runner_bin_search = srunner_create(s_bin_search);

    srunner_run_all(runner_is_year, CK_VERBOSE);
    srunner_run_all(runner_bin_search, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_is_year);
    no_failed += srunner_ntests_failed(runner_bin_search);


    srunner_free(runner_is_year);
    srunner_free(runner_bin_search);

    return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}