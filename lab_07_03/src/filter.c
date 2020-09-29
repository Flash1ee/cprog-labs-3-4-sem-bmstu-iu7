#include "../inc/filter.h"
#include "../inc/err.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (!pb_src || !pe_src)
        return PTR_ERR;

    size_t len = pe_src - pb_src;
    int neg_i = -1;
    size_t p = len;

    for (int *cur = (int *)pb_src; cur < pe_src; cur++)
        if (*cur < 0)
            neg_i = cur - pb_src;
    if (neg_i != -1)
        p = neg_i;

    int *pa_dst = (int *)malloc(p * sizeof(int));
    if (!pa_dst)
        return ALLOCATION_ERR;

    int *src = (int *)pb_src;
    int *dst_beg = pa_dst;
    int *dst_end = dst_beg + p;

    for (; dst_beg < dst_end; dst_beg++)
        memcpy(dst_beg, src++, sizeof(int));

    *pb_dst = pa_dst;
    *pe_dst = pa_dst + p;

    return EXIT_SUCCESS;
}

int last_neg(char *beg, char *end, size_t size)
{
    int p = end - beg;
    for (char *cur = beg; cur < end; cur += size)
        if (*cur < 0)
            p = cur - beg;
    return p;
}