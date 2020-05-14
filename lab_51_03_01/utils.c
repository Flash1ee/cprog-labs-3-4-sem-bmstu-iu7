#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"

int process(FILE *f, size_t *cnt)
{
    my_int frst, scnd;
    size_t k = 0;
    if (fscanf(f, "%lld", &frst) == 1)
    {
        k += 1;
        while (fscanf(f, "%lld", &scnd) == 1)
        {
            k += 1;
            if ((frst >= 0 && scnd < 0) || (frst < 0 && scnd >= 0))
                *cnt += 1;
            frst = scnd;
        }
        if (k < 2) 
            return FEW_PARAM;
        return OK;
    }
    return ERROR_IN;
}