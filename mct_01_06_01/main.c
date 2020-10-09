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
double squad_average(my_int a[], long n);
int input(my_int a[], size_t n);
void output(my_int a[], size_t n);

int main()
{
    my_int a[N_MAX];
    my_size n;
    long p;
    my_size len;
    double flag;
    if (scanf("%ld", &n) != 1 || n < 0 || n > N_MAX)
        return IO_ERROR;
    if (scanf("%ld", &p) != 1 || p < 0 || p > n)
        return IO_ERROR;
    if (input(a,n) != OK)
        return IO_MAS_ERROR;
    flag = squad_average(a,p);

    len = n;
    my_size i = 0;

    while (i < len)
    {
        if (a[i] > flag)
        {
            len -=1;
            for (my_size j = i+1; j < n; j++)
                a[j-1] = a[j];
        }
        else i++;
        }
    output(a,len);



    return OK;
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
int input(my_int a[], my_size n)
{
    for (my_size i = 0; i < n; i++)
        if (scanf("%lld", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
void output(my_int a[], my_size n)
{
    for (my_size i = 0; i < n; i++)
        printf("%lld ", a[i]);
}
