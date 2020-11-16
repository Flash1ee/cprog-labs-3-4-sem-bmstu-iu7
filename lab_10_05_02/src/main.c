#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "retcodes.h"
#include "utils.h"
#include "types.h"
#include "work.h"

int main(void)
{
    mode option;
    int rc = input_process(&option);
    if (rc)
    {
        return rc;
    }
    switch (option)
    {
    case OUT:
    {
        rc = output();
        return rc;
    }
    case CAT:
    {
        rc = cat();
        return rc;
    }
    case RM_SPS:
    {
        rc = one_sps_str();
        return rc;
    }
    case SEARCH_PSTR:
    {
        rc = search_substr();
        return rc;
    }
    }

    return EXIT_SUCCESS;
}