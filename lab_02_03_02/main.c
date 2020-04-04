#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

int input(long long a[], size_t n);
void output(long long a[], size_t n);
int is_armstrong(long long elem);
long count(long long x);
long append_armstrong(long long a[], long long out[], size_t n);

int main()
{
    size_t n, pos;
    long long a[N], out[N] = { 0 };

    if (scanf("%zu", &n) != 1 || n <= 0 || n > N)
        return EXIT_FAILURE;

    if (input(a, n) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    pos = append_armstrong(a, out, n);
    if (pos <= 0)
        return EXIT_FAILURE;

    output(out, pos);

    return EXIT_SUCCESS;
}


int input(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%lld", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

int is_armstrong(long long elem)
{
    long long cur, numb_check = 0;
    long last;
    long k = count(elem);
    cur = elem;
    while (cur > 0)
        {
            last = cur % 10;
            numb_check += pow(last, k);
            cur /= 10;
        }
    if (numb_check == elem)
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

long append_armstrong(long long a[], long long out[], size_t n)
{
    size_t len = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (is_armstrong(a[i]) == EXIT_SUCCESS)
        {
            out[len] = a[i];
            len += 1;
        }
    }
    return len;
}

long count(long long x)
{
    long k = 0;
    while (x > 0)
    {
        k += 1;
        x /= 10;
    }
    return k;
}

void output(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%lld ", a[i]);
}