#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#define N 100000

int input(long a[], size_t *n);
void form(long a[], size_t *n);
long long process_1(long a[], size_t* n);
long long process_2(long a[],  long* n);
long long process_3(long *start, long *stop);
int search_min(long long a[], size_t n);
int search_max(long long a[], size_t n);
int search_sum(long long a[], size_t n, long long *sum);
void make_table_header(void);
void make_table_data(long iter_count, size_t size, long long time_1,long long time_2, long long time_3);

int main()
{
    setbuf(stdout, NULL);

    struct timeval tv_start, tv_stop;
    int64_t sum;


    long counts[] = {1000,2000,5000,10000,20000,30000};
    long long size[] = {100,500,1000,2000,5000,10000,20000};

    long a[N];
    long long time_1[N];
    long long time_2[N];
    long long time_3[N];
    long res[] = {0,0,0};

    make_table_header();
    for (size_t i = 0; i < (sizeof(counts) / sizeof(counts[0])); i++)
    {
        size_t n = counts[i];
        /*if (input(a, &n)!= 0)
            return EXIT_FAILURE;*/
        sum = 0;
        /*long long start,end;*/
        for (size_t j = 0; j < (sizeof(size) / sizeof(size[0])); j++)
        {
            /*if (input(a, &n)!= 0)
                return EXIT_FAILURE;*/
            size_t k = size[j];
            for (size_t m = 0; m < k; m++)
            {
                form(a,&k);
                gettimeofday(&tv_start, NULL);
                process_1(a,&n);
                gettimeofday(&tv_stop, NULL);
                time_1[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);
                gettimeofday(&tv_start, NULL);
                process_2(a,&(counts[i]));
                gettimeofday(&tv_stop, NULL);
                time_2[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);
                long *ptr_end = (a + counts[i]);
                gettimeofday(&tv_start, NULL);
                process_3(a,ptr_end);  
                gettimeofday(&tv_stop, NULL);
                time_3[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);

                /*sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);*/
            }
            search_min(time_1,k);
            search_min(time_2,k);
            search_min(time_3,k);
            search_max(time_1,k-1);
            search_max(time_2,k-1);
            search_max(time_3,k-1);
            search_sum(time_1,k-2,&sum);
            res[0] = sum / (k-2);
            sum = 0;
            search_sum(time_2,k-2,&sum);
            res[1] = sum / (k-2);
            sum = 0;
            search_sum(time_3,k-2,&sum);
            res[2] = sum / (k-2);
            sum = 0;
            make_table_data(counts[i],k,res[0],res[1],res[2]);
            /*if (input(a, &n)!= 0)
                return EXIT_FAILURE;
            for (size_t m = 0; m < k; m++)
            {
                form(a,&k);
                gettimeofday(&tv_start, NULL);
                process_2(a,&(counts[i]));
                gettimeofday(&tv_stop, NULL);
                time[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);
                sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);
            }
            search_min(time,k);
            search_max(time,k-1);
            search_sum(time,k-2,&sum);
            res[1] = sum / (k-2);
            sum = 0;*/
            /*if (input(a, &n)!= 0)
                return EXIT_FAILURE;
            for (size_t m = 0; m < k; m++)
            {
                form(a,&k);
                long *ptr_end = (a + counts[i]);
                gettimeofday(&tv_start, NULL);
                process_3(a,ptr_end);  
                gettimeofday(&tv_stop, NULL);
                time[m] = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +(tv_stop.tv_usec - tv_start.tv_usec);
                sum += (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +
                (tv_stop.tv_usec - tv_start.tv_usec); */
        
             
            /*
            search_min(time,k);
            search_max(time,k-1);
            search_sum(time,k-2,&sum);     
            res[2] = sum / (k-2);
            
            sum = 0;*/
        
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
long long process_1(long a[], size_t* n)
{
    long long minp = a[0] * a[1];
    for (size_t i = 0; i < *n - 1; i++)
        if (a[i] * a[i + 1] < minp)
            minp = a[i] * a[i + 1];
    return minp;
}

long long process_2(long a[], long* n)
{
    long long minp = *a * *(a + 1);
    for (long i = 0; i < (*n - 1); i++)
        if (*(a + i) * *(a + i + 1)<minp)
            minp = *(a + i) * *(a + i + 1);
    return minp;
}
long long process_3(long* start, long* stop)
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
    return minp;
}
void make_table_header(void)
{
    /*printf("┏ ━ ┓ ┃ ┣ ┫ ┳ ┻");*/
    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
    printf("┃%9s  ┃%9s   ┃%9s┃%-9s┃%9s┃\n", "Повторы", "Размер", "a[i]", "*(a+i)", "Указатели");
    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
}
void make_table_data(long iter_count, size_t size, long long time_1,long long time_2, long long time_3)
{
    printf("┃%9ld┃%9ld┃%9lld┃%9lld┃%9lld┃\n",iter_count,(long)size,time_1,time_2,time_3 );
}
void form(long a[], size_t *n)
{
    srand(time(NULL));
    for (size_t i = 0; i < *n; i++)
        a[i] = rand();
}
int search_min(long long a[], size_t n)
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
    for (size_t i = ind + 1; i < n - 1;i++)
    {
        a[i-1] = a[i];
    }
    return EXIT_SUCCESS;
}
int search_max(long long a[], size_t n)
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
    for (size_t i = ind + 1; i < n - 1;i++)
    {
        a[i-1] = a[i];
    }
    return EXIT_SUCCESS;
}
int search_sum(long long a[], size_t n, long long *sum)
{    
    for (size_t i = 0; i<n; i++)
        *sum += a[i];
    return EXIT_SUCCESS;    
}