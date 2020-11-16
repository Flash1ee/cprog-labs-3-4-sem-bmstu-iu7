#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <retcodes.h>
#include "utils.h"

const char *values[] = {
    "out",
    "cat",
    "sps",
    "pos"};

int input_process(mode *val)
{
    char buf[BUF_SIZE + 1];
    if (!fgets(buf, BUF_SIZE + 1, stdin) || buf[strlen(buf) - 1] != '\n')
    {
        return INPUT_ERR;
    }
    buf[strlen(buf) - 1] = '\0';
    if (!strcmp(buf, values[OUT]))
    {
        *val = OUT;
    }
    else if (!strcmp(buf, values[CAT]))
    {
        *val = CAT;
    }
    else if (!strcmp(buf, values[RM_SPS]))
    {
        *val = RM_SPS;
    }
    else if (!strcmp(buf, values[SEARCH_PSTR]))
    {
        *val = SEARCH_PSTR;
    }
    else
    {
        return INPUT_ERR;
    }

    return EXIT_SUCCESS;
}