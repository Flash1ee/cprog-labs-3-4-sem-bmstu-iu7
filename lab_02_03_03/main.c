#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

long input_mas(long *a, long *n);
long get_new_mas(long *a, long *n, long *new_elem);
long count_digit(long x);
void print_mas(long *a, long *n, long *new_elem);
long get_pos_el(long *a, long *n);
long power(long x, long exp);

int main(void)
{
    long n, a[2 * N];
    if ((scanf("%ld", &n) != 1) || (input_mas(a, &n) != 0))
    {
        return EXIT_FAILURE;
    }
    long new_elem = get_pos_el(a, &n);
    get_new_mas(a, &n, &new_elem);
    print_mas(a, &n, &new_elem);
    return EXIT_SUCCESS;
}


long input_mas(long *a, long *n)
{
    for (long i = 0; i < *n; i++)
    {
        if (scanf("%ld", &a[i]) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

long get_new_mas(long *a, long *n, long *new_elem)
{
    long i = 0;
    long new_len = *n + *new_elem;
    while (i < new_len)
    {
        if (a[i] > 0)
        {
            for (long j = new_len; j > i; j--)
            {
                a[j + 1] = a[j];
            }
            long reverse_numb = 0, cur_numb = a[i], k = count_digit(a[i]) - 1;
            while (cur_numb > 0)
            {
                reverse_numb = reverse_numb + (power(N, k) * (cur_numb % 10));
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

void print_mas(long *a, long *n, long *new_elem)
{
    for (int i = 0; i < (*n + *new_elem); i++)
    {
        printf("%ld ", a[i]);
    }
}
long get_pos_el(long *a, long *n)
{
    long k = 0;
    for (int i = 0; i < *n; i++)
    {
        if (a[i] > 0)
            k += 1;
    }
    return k;
}
long power(long x, long exp)
{
    if (exp == 0)
        return 1;
    long k = 1;
    long result = x;
    while (k < exp)
    {
        result *= x;
        k += 1;
    }
    return result;
}