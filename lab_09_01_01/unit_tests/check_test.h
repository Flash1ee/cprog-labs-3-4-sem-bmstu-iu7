#ifndef _CHECK_TEST_H_
#define _CHECK_TEST_H_

#define _GNU_SOURCE
#include "films.h"
#include <check.h>
#include <stdlib.h>

Suite *is_year_suite(void);
Suite *bin_search_suite(void);
Suite *shift_cinema_suite(void);


#endif  // _CHECK_TEST_H_