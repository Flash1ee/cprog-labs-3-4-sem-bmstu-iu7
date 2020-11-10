#include "array.h"

inttype *allocate_vector(size_t len)
{
    inttype *arr = malloc(sizeof(inttype));
    if (!arr)
    {
        return NULL;
    }
    num_t *values = malloc(sizeof(num_t) * len);
    if (!values)
    {
        free(arr);
        return NULL;
    }
    arr->capacity = len;
    arr->len = 0;
    arr->data = values;
    return arr;
}
void free_vector(inttype *arr)
{
    free(arr->data);
    free(arr);
}
int input(inttype *arr, size_t len)
{
    // Не используется, т.к функция вводит элементы, а не добавляет => данная часть кода необходима в функции добавления.
    // if (arr->len >= arr->capacity)
    // {
    //     num_t *tmp = realloc(arr->data, arr->capacity + len * SIZE_K * sizeof(num_t));
    //     if (!tmp)
    //     {
    //         return ALLOCATION_ERR;
    //     }
    //     arr->data = tmp;
    //     arr->capacity += len * SIZE_K;
    // }
    for (size_t i = 0; i < len; i++)
    {
        if (scanf(ScNum, &(arr->data[i])) != 1)
        {
            return READ_ERR;
        }
    }
    arr->len = len;
    return EXIT_SUCCESS;
}
void output(inttype *arr)
{
    for (size_t i = 0; i < arr->len; i++)
    {
        printf(PrNum " ", arr->data[i]);
    }
    printf("\n");
}

size_t set_len(inttype **arr, size_t len, size_t newlen)
{
    if (!arr || len <= newlen)
    {
        return 0;
    }

    num_t *tmp = realloc((*arr)->data, sizeof(num_t) * (len + newlen));
    if (!tmp)
    {
        return 0;
    }
    
    (*arr)->data = tmp;
    (*arr)->capacity = newlen;
    return newlen;
}

int delete_prime_ind(inttype *arr)
{
    if (!arr)
    {
        return ARG_ERR;
    }
    if (!arr->len)
    {
        return EMPTY_ERR;
    }

    int k = 0;

    for (size_t i = 0; i < arr->len; i++)
    {
        if (isprime(i + k) == PRIME)
        {
            shift(arr->data, arr->len, i + 1);
            arr->len -= 1;
            i--;
            k++;
        }
    }

    return EXIT_SUCCESS;
}
void shift(num_t *arr, size_t len, size_t ind)
{
    for (size_t i = ind; i < len; i++)
    {
        arr[i - 1] = arr[i];
    }
}