#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define N 10

int input(long long a[], size_t n);
void output(long long a[], size_t n);
void append_reverse(long long a[], size_t n);
size_t get_count_pos(long long a[], size_t n);
long long get_digit(long long numb, long k);
size_t count_digit(long long x);

int main()
{
    size_t n;
    size_t count;
    long long a[2 * N];
    if ((scanf("%zu", &n) != 1) || (n <= 0) || (n > N))
        return EXIT_FAILURE;
    if (input(a, n) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    count = get_count_pos(a, n);
    append_reverse(a, n + count);
    output(a, n + count);
    return EXIT_SUCCESS;
}


int input(long long a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (scanf("%lld", &a[i]) != 1)
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void append_reverse(long long a[], size_t n)
{
    size_t i = 0;
    size_t new_len = n;
    while (i < new_len)
    {
        if (a[i] > 0)
        {
            for (size_t j = new_len; j > i; j--)
                a[j + 1] = a[j];

            long long reverse_numb = 0;
            long long cur_numb = a[i];
            long k = count_digit(a[i]) - 1;
            long digit;

            while (k > k / 2)
            {
                digit = get_digit(cur_numb, k);
                reverse_numb = reverse_numb + digit;
                cur_numb /= 10;
                k -= 1;
            }
            k = k / 2;
            while (k >= 0)
            {
                digit = get_digit(cur_numb, k);
                reverse_numb = reverse_numb + digit;
                cur_numb /= 10;
                k -= 1;
            }
            a[i + 1] = reverse_numb;
            i++;
        }
        i++;
    }
}

size_t count_digit(long long x)
{
    size_t k = 0;
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

size_t get_count_pos(long long a[], size_t n)
{
    size_t k = 0;
    for (size_t i = 0; i < n; i++)
        if (a[i] > 0)
            k += 1;
    return k;
}

long long get_digit(long long numb, long k)
{
    long long num = 1;
    while (k > 0)
    {
        num *= 10;
        k -= 1;
    }
    num = num * (numb % 10);
    return num;
}