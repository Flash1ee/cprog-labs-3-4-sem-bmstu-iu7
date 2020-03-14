#include <stdio.h>
#include <stdlib.h>

#define N 10

long input(long *beg, long *end);
long search_min_prod(long *start, long *stop, long long *minp);
int main()
{
    long a[N];
    long n;
    long *pa_beg = NULL;
    long *pa_end = NULL;
    if (scanf("%ld", &n) != 1 || n > N || n <= 0)
        return EXIT_FAILURE;
    pa_beg = a;
    pa_end = a + n;
    if (input(pa_beg, pa_end) != 0)
        return EXIT_FAILURE;
    long long minp = *pa_beg * *(pa_beg + 1);
    if (search_min_prod(pa_beg, pa_end, &minp) != 0)
        return EXIT_FAILURE;
    printf("%lld", minp);
    return EXIT_SUCCESS;
}
long input(long *beg, long *end)
{
    for (long *pcur = beg; pcur < end; pcur++)
        if (scanf("%ld", pcur) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
long search_min_prod(long *start, long *stop, long long *minp)
{
    if ((stop - start) <= 1)
        return EXIT_FAILURE;
    while (start < stop - 1)
    {
        long frst = *start;
        long sec = *(start + 1);
        if (frst * sec < *minp)
        {
            *minp = frst * sec;
        }
        start++;
    }
    return EXIT_SUCCESS;
}