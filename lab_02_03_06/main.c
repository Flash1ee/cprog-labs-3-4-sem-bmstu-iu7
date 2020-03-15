#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 10000
#define COUNTS 5

int input(long a[], size_t *n);
void process_1(long a[], size_t* n);
void process_2(long a[],  size_t* n);
void process_3(long *start, long *stop);

int main()
{
    size_t counts[] = {10};
    long a[N];
    for (size_t i = 0; i < sizeof(counts) / sizeof(counts[0]); i++)
    {
        size_t n = counts[i];
        if (input(a, &n)!= 0)
            return EXIT_FAILURE;
        for (size_t j = 0; j < 1; j++)
        {
            size_t k = counts[j];
            for (size_t m = 0; m < k; m++)
                process_1(a,&n);
            for (size_t m = 0; m < k; m++)
                process_2(a,&(counts[i]));
            for (size_t m = 0; m < k; m++)
            {
                long *ptr_end = (a + counts[i]);
                process_3(a,ptr_end);   
            }       
        }

       
    }
}
int input(long a[], size_t *n)
{
    for (size_t i = 0; i < *n; i++)
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
void process_1(long a[], size_t* n)
{
    long long minp = a[0] * a[1];
    for (size_t i = 0; i < *n - 1; i++)
        if (a[i] * a[i + 1] < minp)
            minp = a[i] * a[i + 1];
    printf("%lld\n", minp);
}

void process_2(long a[], size_t* n)
{
    long long minp = *a * *(a + 1);
    for (size_t i = 0; i < (*n - 1); i++)
        if (*(a + i) * *(a + i + 1))
            minp = *(a + i) * *(a + i + 1);
    printf("%lld\n", minp);
}
void process_3(long* start, long* stop)
{
    /*long *pa_beg = NULL;
    long *pa_end = NULL;
    pa_beg = start;
    pa_end = stop;
    */
    long long minp = *start + *(start + 1);
    while (start < stop - 1)
    {
        long frst,sec;
        frst = *start;
        sec = *(start + 1);
        if (frst * sec < minp)
            minp = frst * sec;
        start++;
    }
    printf("%lld\n", minp);
}