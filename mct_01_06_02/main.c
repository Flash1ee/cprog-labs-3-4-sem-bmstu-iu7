#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N_MAX 64
#define OK 0
#define IO_ERROR 1
#define IO_MAS_ERROR 2


typedef my_int long long;
typedef my_size long;
double squad_average(my_int a[], my_size n);
int input(my_int a[][N], my_size n, my_size m);

int main()
{
    double res;
    my_int a[N_MAX][N_MAX];
    my_size r,c;
    if (scanf("%ld", &r) != 1 || r < 0)
        return IO_ERROR;
    if (scanf("%ld", &c) != 1 || c < 0 || c > N_MAX)
        return IO_ERROR;
    input(a,r,c);
    double b[N_MAX];
    for (my_size i = 0; i < c; i++)
    {
        res = squad_average(a[i], r);
        b[i] = res;
    }
    for (size_t i = 0; i < c - 1; i++)
        for (size_t j = 0; j < c - i - 1; j++)
            if (b[j] < b[j+1])
            {
                double tmp = b[j];
                b[j] = b[j+1];
                b[j+1] = tmp;
            }
    






    return OK;
}
int input(my_int a[][N], my_size n, my_size m)
{
    for (my_size i = 0; i < m; i++)
        for (my_size j = 0; j < n; j++)
            if (scanf("%lld", &a[j][i]) != 1)
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
double squad_average(my_int a[], my_size n)
{
    double res = 0;
    long sum_squad = 0;
    if (n < 0)
        return EXIT_FAILURE;
    if (n == 0)
        return res;

    for (my_size i = 0; i < n;i++)
        sum_squad += a[i]*a[i];
    res = sum_squad / (double) n;
    return sqrt(res);
}