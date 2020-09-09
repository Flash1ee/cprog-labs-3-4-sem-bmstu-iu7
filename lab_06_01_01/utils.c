#include "utils.h"

int is_year(char str[])
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return ARG_ERR;
    return EXIT_SUCCESS;
}