#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define N 100000

void form(long long a[], size_t n);
long long process_1(long long a[], size_t n);
long long process_2(long long a[], size_t n);
long long process_3(long long *start, long long *stop);
int search_min(long a[], size_t n);
int search_max(long a[], size_t n);
void search_sum(long a[], size_t n, long long *sum);
void make_table_header(void);
void make_table_data(long iter_count, size_t size, long time_1, long time_2, long time_3);

int main()
{
    setbuf(stdout, NULL);
    struct timeval tv_start, tv_stop;
    int64_t sum;


    long counts[] = { 1000, 2000, 5000, 10000, 20000, 30000, 50000, 100000 };
    long size[] = { 100, 500, 1000, 2000, 5000, 10000, 20000, 50000 };
    long long a[N];
    long time_1[N];
    long time_2[N];
    long time_3[N];
    long long res[] = { 0, 0, 0 };

    make_table_header();

    for (size_t i = 0; i < (sizeof(counts) / sizeof(counts[0])); i++)
    {
        size_t n = counts[i];
        sum = 0;
        for (size_t j = 0; j < (sizeof(size) / sizeof(size[0])); j++)
        {
            size_t k = size[j];
            for (size_t m = 0; m < k; m++)
            {
                form(a, k);
                gettimeofday(&tv_start, NULL);
                process_1(a, n);
                gettimeofday(&tv_stop, NULL);
                time_1[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL
                    + (tv_stop.tv_usec - tv_start.tv_usec);
                gettimeofday(&tv_start, NULL);
                process_2(a, counts[i]);
                gettimeofday(&tv_stop, NULL);
                time_2[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL
                    + (tv_stop.tv_usec - tv_start.tv_usec);
                long long *ptr_end = (a + counts[i]);
                gettimeofday(&tv_start, NULL);
                process_3(a, ptr_end);
                gettimeofday(&tv_stop, NULL);
                time_3[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL
                    + (tv_stop.tv_usec - tv_start.tv_usec);
            }
            search_min(time_1, k);
            search_min(time_2, k);
            search_min(time_3, k);
            search_max(time_1, k - 1);
            search_max(time_2, k - 1);
            search_max(time_3, k - 1);
            search_sum(time_1, k - 2, &sum);
            res[0] = sum / (k - 2);
            sum = 0;
            search_sum(time_2, k - 2, &sum);
            res[1] = sum / (k - 2);
            sum = 0;
            search_sum(time_3, k - 2, &sum);
            res[2] = sum / (k - 2);
            sum = 0;
            make_table_data(counts[i], k, res[0], res[1], res[2]);
        }
    }
    return EXIT_SUCCESS;
}

long long process_1(long long a[], size_t n)
{
    long long minp = a[0] * a[1];
    for (size_t i = 0; i < n - 1; i++)
        if (a[i] * a[i + 1] < minp)
            minp = a[i] * a[i + 1];
    return minp;
}

long long process_2(long long a[], size_t n)
{
    long long minp = *a * *(a + 1);
    for (size_t i = 0; i < n - 1; i++)
        if (*(a + i) * *(a + i + 1) < minp)
            minp = *(a + i) * *(a + i + 1);
    return minp;
}

long long process_3(long long *start, long long *stop)
{
    long long minp = *start + *(start + 1);
    while (start < stop - 1)
    {
        long long frst, sec;
        frst = *start;
        sec = *(start + 1);
        if (frst * sec < minp)
            minp = frst * sec;
        start++;
    }
    return minp;
}

void make_table_header(void)
{

    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
    printf("┃%9s  ┃%9s   ┃%9s┃%-9s┃%9s┃\n", "Повторы", "Размер", "a[i]", "*(a+i)",
            "Указатели");
    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
}

void make_table_data(long iter_count, size_t size, long time_1, long time_2, long time_3)
{
    printf("┃%9ld┃%9ld┃%9ld┃%9ld┃%9ld┃\n", iter_count, (long)size, time_1, time_2, time_3);
}

void form(long long a[], size_t n)
{
    srand(time(NULL));
    for (size_t i = 0; i < n; i++)
        a[i] = rand();
}

int search_min(long a[], size_t n)
{
    long long min = a[0];
    long ind = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            ind = i;
        }
    }
    for (size_t i = ind + 1; i < n - 1; i++)
    {
        a[i - 1] = a[i];
    }
    
    return EXIT_SUCCESS;
}

int search_max(long a[], size_t n)
{
    long long max = a[0];
    long ind = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            ind = i;
        }
    }
    for (size_t i = ind + 1; i < n - 1; i++)
        a[i - 1] = a[i];
        
    return EXIT_SUCCESS;
}

void search_sum(long a[], size_t n, long long *sum)
{
    for (size_t i = 0; i < n; i++)
        *sum += a[i];
}
