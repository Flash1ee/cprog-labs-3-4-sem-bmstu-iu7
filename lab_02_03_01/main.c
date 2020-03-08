#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int input_pos_massiv(int* mas, int k, int* len);
double get_pos_element_prod(int* mas, int k);
int main()
{
    int k, a[N], len_pos = 0;
    if (scanf("%d", &k) != 1 || k > 10 || k <= 0)
    {
        return EXIT_FAILURE;
    }
    if (input_pos_massiv(a, k, &len_pos) != 0)
        return EXIT_FAILURE;
    printf("%lf", pow(get_pos_element_prod(a, k), 1.0 / (double)len_pos));
    return EXIT_SUCCESS;
}

int input_pos_massiv(int* mas, int k, int* len)
{
    for (int i = 0; i < k; i++)
    {
        if (scanf("%d", &mas[i]) != 1)
            return EXIT_FAILURE;
        if (mas[i] > 0)
            *len += 1;
    }
    if (!*len)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
double get_pos_element_prod(int* mas, int k)
{
    double prod = 1.0;
    for (int i = 0; i < k; i++)
    {
        if (mas[i] > 0)
            prod *= mas[i];
    }
    return prod;
}
