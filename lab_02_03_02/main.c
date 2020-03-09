#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

long input_mas(long *a, long n);
long armstrong_numb(long *a, long *out, long n);
long count_digit(long x);

int main()
{
    long n, pos;
    long a[N], out[N] = { 0 };

    if (scanf("%ld", &n) != 1 || n <= 0 || n > N)
    {
        return EXIT_FAILURE;
    }
    if (input_mas(a, n) != 0)
        return EXIT_FAILURE;
    pos = armstrong_numb(a, out, n);
    if (pos <= 0)
        return EXIT_FAILURE;
    for (int i = 0; i < pos; i++)
        printf("%ld ", out[i]);
    return EXIT_SUCCESS;
}


long input_mas(long *a, long n)
{
    for (long i = 0; i < n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long armstrong_numb(long *a, long *out, long n)
{
    long pos = 0;
    for (long i = 0; i < n; i++)
    {
        long k = count_digit(a[i]);
        long numb_check = 0, cur = a[i];
        while (cur > 0)
        {
            long last = cur % 10;
            numb_check += pow(last, k);
            cur /= 10;
        }
        if (numb_check == a[i])
        {
            out[pos] = a[i];
            pos += 1;
        }
    }
    return pos;
}
long count_digit(long x)
{
    long k = 0;
    while (x > 0)
    {
        k += 1;
        x /= 10;
    }
    return k;
}