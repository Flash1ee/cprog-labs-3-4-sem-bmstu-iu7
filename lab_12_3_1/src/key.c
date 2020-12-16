#include "key.h"
#include "retcodes.h"


int last_neg(char *beg, char *end, size_t size)
{
    int p = end - beg;
    for (char *cur = beg; cur < end; cur += size)
        if (*cur < 0)
            p = cur - beg;
    return p;
}