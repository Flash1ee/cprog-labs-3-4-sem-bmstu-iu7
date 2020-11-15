#include <stdlib.h>
#include "check_test.h"

int main(void)
{
    int no_failed = 0;
    Suite *s_insert;



    SRunner *runner_insert;



    s_insert = insert_suite();

    runner_insert = srunner_create(s_insert);

    srunner_run_all(runner_insert, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_insert);
    
    return no_failed ? EXIT_FAILURE : EXIT_SUCCESS;
}