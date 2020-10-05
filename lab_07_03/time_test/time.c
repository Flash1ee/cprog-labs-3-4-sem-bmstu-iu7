#include "sort.h"
#include "time.h"


const int low_size = 10000;
const int big_size = 20000;
const int step = 100;

#define EPS 1e-9
void make_table_header(void)
{
    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
    printf("┃%9s   ┃%9s┃%9s┃\n", "Размер", "mysort", "qsort");
    printf("┃━━━━━━━━━┃━━━━━━━━━┃━━━━━━━━━┃\n");
}

void make_table_data(size_t size, int64_t time_1, int64_t time_2)
{
    printf("%ld\t%" PRId64 "\t%" PRId64 "\t\n", size, time_1, time_2);
}

void measure_time_sort()
{
    struct timeval tv_start, tv_stop;
    int64_t time_m, time_q;
    printf("Сравнение mysort и qsort на отсортированных массивах.\n");
    make_table_header();

    for (int size = low_size; size < big_size; size += step)
    {
        int arr_m[size];
        int arr_q[size];

        for (int j = 0; j < size; j++)
        {
            arr_m[j] = j;
            arr_q[j] = j;
        }
        gettimeofday(&tv_start, NULL);
        mysort(arr_m, size, sizeof(int), cmp_i);
        gettimeofday(&tv_stop, NULL);
        time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);

        gettimeofday(&tv_start, NULL);
        qsort(arr_q, size, sizeof(int), cmp_i);
        gettimeofday(&tv_stop, NULL);

        time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);

        make_table_data(size, time_m, time_q);
    }
}
void measure_time_reverse_sort()
{
    struct timeval tv_start, tv_stop;
    int64_t time_m, time_q;

    printf("Сравнение mysort и qsort на reverse массивах.\n");
    make_table_header();

    for (int size = low_size; size < big_size; size += step)
    {
        int arr_m[size];
        int arr_q[size];

        for (int j = 0; j < size; j++)
        {
            arr_m[j] = size - j;
            arr_q[j] = size - j;
        }
        gettimeofday(&tv_start, NULL);
        mysort(arr_m, size, sizeof(int), cmp_i);
        gettimeofday(&tv_stop, NULL);
        time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);

        gettimeofday(&tv_start, NULL);
        qsort(arr_q, size, sizeof(int), cmp_i);
        gettimeofday(&tv_stop, NULL);
        time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);

        make_table_data(size, time_m, time_q);
    }
}
int main()
{
    measure_time_sort();
    measure_time_reverse_sort();

    return EXIT_SUCCESS;
}