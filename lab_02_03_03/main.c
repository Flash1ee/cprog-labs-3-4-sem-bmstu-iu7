#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define N 10

long input(long a[], long *n);
void output(long a[], long *n, long *new_elem);
long get_new(long a[], long *n, long *new_elem);
long count_digit(long x);
long get_pos_el(long a[], long *n);
long get_digit(long numb, long k);

int main(void)
{
    long n, a[2 * N];
    if ((scanf("%ld", &n) != 1) || (n <= 0) || (n > N) || (input(a, &n) != 0))
        return EXIT_FAILURE;
    long new_elem = get_pos_el(a, &n);
    if (get_new(a, &n, &new_elem)!=0)
	return EXIT_FAILURE;
    output(a, &n, &new_elem);
    return EXIT_SUCCESS;
}


long input(long a[], long *n)
{
    for (long i = 0; i < *n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long get_new(long a[], long *n, long *new_elem)
{
    long i = 0;
    long new_len = *n + *new_elem;
    while (i < new_len)
    {
        if (a[i] > 0)
        {
            for (long j = new_len; j > i; j--)
                a[j + 1] = a[j];
            unsigned long long reverse_numb = 0, cur_numb = a[i];
            long long k = count_digit(a[i]) - 1;
            while (k > k/2)
            {
                long digit = get_digit(cur_numb, k);
                if (reverse_numb > (ULLONG_MAX - digit))
                    return EXIT_FAILURE;
                reverse_numb = reverse_numb + get_digit(cur_numb, k);
                cur_numb /= 10;
                k -= 1;
            }
            k= k / 2;
            while (k >= 0)
            {
                long digit = get_digit(cur_numb, k);
                if (reverse_numb > (ULLONG_MAX - digit))
                    return EXIT_FAILURE;
                reverse_numb = reverse_numb + get_digit(cur_numb, k);
                cur_numb /= 10;
                k -= 1;
            }
            a[i + 1] = reverse_numb;
            i++;
        }
        i++;
    }
    return EXIT_SUCCESS;
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

void output(long a[], long *n, long *new_elem)
{
    for (int i = 0; i < (*n + *new_elem); i++)
        printf("%ld ", a[i]);
}
long get_pos_el(long a[], long *n)
{
    long k = 0;
    for (int i = 0; i < *n; i++)
    {
        if (a[i] > 0)
            k += 1;
    }
    return k;
}
long get_digit(long numb, long k)
{
    long num = 1;
    while (k > 0)
    {
        num *= 10;
        k -= 1;
    }
    num = num * (numb % 10);
    return num;
}