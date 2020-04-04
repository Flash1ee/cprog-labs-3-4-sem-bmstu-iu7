#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>

#define N 10

int input(long long *beg, long long *end);
int get_min_prod(long long *start, long long *stop, long long *minp);

int main()
{
    long long a[N];
    size_t n;
    long long minp;
    long long *pa_beg = NULL;
    long long *pa_end = NULL;

    if (scanf("%zu", &n) != 1 || n > N || n <= 0)
        return EXIT_FAILURE;

    pa_beg = a;
    pa_end = a + n;

    if (input(pa_beg, pa_end) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    minp = *pa_beg * *(pa_beg + 1);
    if (get_min_prod(pa_beg, pa_end, &minp) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    printf("%lld", minp);

    return EXIT_SUCCESS;
}

int input(long long *beg, long long *end)
{
    for (long long *pcur = beg; pcur < end; pcur++)
        if (scanf("%lld", pcur) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int get_min_prod(long long *start, long long *stop, long long *minp)
{
    if ((stop - start) <= 1)
        return EXIT_FAILURE;
    while (start < stop - 1)
    {
        long frst = *start;
        long sec = *(start + 1);
        if (frst * sec < *minp)
            *minp = frst * sec;
        start++;
    }
    return EXIT_SUCCESS;
}