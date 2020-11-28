#include <stdlib.h>
#include "check_test.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_insert;
    Suite *s_sort;


    SRunner *runner_insert;
    SRunner *runner_sort;

    s_insert = insert_suite();
    s_sort = sort_suite();

    runner_insert = srunner_create(s_insert);
    runner_sort = srunner_create(s_sort);

    srunner_run_all(runner_insert, CK_VERBOSE);
    srunner_run_all(runner_sort, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_insert);
    no_failed += srunner_ntests_failed(runner_sort);

    srunner_free(runner_insert);
    srunner_free(runner_sort);

    return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}