#include "check_main.h"

int main(void)
{
    int no_failed = 0;

    Suite *s_my_snprintf_char;
    Suite *s_my_snprintf_int;
    Suite *s_my_snprintf_str;
    Suite *s_my_snprintf_i_int;
    Suite *s_my_snprintf_long;

    SRunner *runner_my_snprintf_char;
    SRunner *runner_my_snprintf_int;
    SRunner *runner_my_snprintf_str;
    SRunner *runner_my_snprintf_i_int;
    SRunner *runner_my_snprintf_long;

    s_my_snprintf_char = my_snprintf_char_suite();
    s_my_snprintf_int = my_snprintf_int_suite();
    s_my_snprintf_str = my_snprintf_str_suite();
    s_my_snprintf_i_int = my_snprintf_i_int_suite();
    s_my_snprintf_long = my_snprintf_long_suite();

    runner_my_snprintf_char = srunner_create(s_my_snprintf_char);
    runner_my_snprintf_int = srunner_create(s_my_snprintf_int);
    runner_my_snprintf_str = srunner_create(s_my_snprintf_str);
    runner_my_snprintf_i_int = srunner_create(s_my_snprintf_i_int);
    runner_my_snprintf_long = srunner_create(s_my_snprintf_long);

    srunner_run_all(runner_my_snprintf_char, CK_VERBOSE);
    srunner_run_all(runner_my_snprintf_int, CK_VERBOSE);
    srunner_run_all(runner_my_snprintf_str, CK_VERBOSE);
    srunner_run_all(runner_my_snprintf_i_int, CK_VERBOSE);
    srunner_run_all(runner_my_snprintf_long, CK_VERBOSE);

    no_failed += srunner_ntests_failed(runner_my_snprintf_char);
    no_failed += srunner_ntests_failed(runner_my_snprintf_int);
    no_failed += srunner_ntests_failed(runner_my_snprintf_str);
    no_failed += srunner_ntests_failed(runner_my_snprintf_i_int);
    no_failed += srunner_ntests_failed(runner_my_snprintf_long);

    srunner_free(runner_my_snprintf_char);
    srunner_free(runner_my_snprintf_int);
    srunner_free(runner_my_snprintf_str);
    srunner_free(runner_my_snprintf_i_int);
    srunner_free(runner_my_snprintf_long);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
