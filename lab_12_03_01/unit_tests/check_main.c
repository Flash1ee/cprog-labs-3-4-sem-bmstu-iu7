#include "check_sort.h"
#include "check_key.h"


int main()
{
    int no_failed = 0;
    Suite *s1_filter;
    Suite *s2_filter;

    Suite *s1_sort;
    Suite *s2_sort;

    SRunner *runner_last_neg;
    SRunner *runner_key;
    SRunner *runner_mysort;
    SRunner *runner_cmp_i;

    s1_sort = cmp_i_suite();
    s2_sort = mysort_suite();

    s1_filter = last_neg_suite();
    s2_filter = key_suite();

    runner_last_neg = srunner_create(s1_filter);
    runner_key = srunner_create(s2_filter);

    runner_cmp_i = srunner_create(s1_sort);
    runner_mysort = srunner_create(s2_sort);

    srunner_run_all(runner_last_neg, CK_VERBOSE);
    srunner_run_all(runner_key, CK_VERBOSE);
    srunner_run_all(runner_cmp_i, CK_VERBOSE);
    srunner_run_all(runner_mysort, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_last_neg);
    no_failed += srunner_ntests_failed(runner_key);
    no_failed += srunner_ntests_failed(runner_cmp_i);
    no_failed += srunner_ntests_failed(runner_mysort);

    srunner_free(runner_cmp_i);
    srunner_free(runner_mysort);
    srunner_free(runner_last_neg);
    srunner_free(runner_key);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}