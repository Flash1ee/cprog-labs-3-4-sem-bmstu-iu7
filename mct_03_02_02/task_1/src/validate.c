#include "validate.h"

int valid_u_num(char *str, size_t *num)
{
    if (!str || !num || strlen(str) <= 1)
    {
        return PARSE_ERR;
    }

    if (!isdigit(*str) && *str != '+')
    {
        return NOT_UNSIGNED;
    }

    for (char *cur = str + 1; isspace(*cur) && *cur != '\0'; cur++)
    {
        if (!isdigit(*cur) && !isspace(*cur))
        {
            return PARSE_ERR;
        }
    }

    if (sscanf(str, "%zu", num) != 1)
    {
        return NOT_UNSIGNED;
    }

    
    return EXIT_SUCCESS;
}