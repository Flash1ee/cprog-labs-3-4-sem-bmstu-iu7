#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"

int process(FILE *f, size_t *cnt)
{
    my_int frst, scnd;
    if (fscanf(f, "%lld", &frst) == 1)
    {
        while (fscanf(f, "%lld", &scnd) == 1)
        {
            if ((frst >= 0 && scnd < 0) || (frst < 0 && scnd >= 0))
                *cnt += 1;
            frst = scnd;
        }
        return OK;
    }
    return ERROR_IN;
}