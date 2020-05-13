#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include "utils.h"

int main()
{
    size_t cnt = 0;
    if (process(stdin, &cnt))
        return ERROR_IN;

    printf("%zu", cnt);

    return OK;
}