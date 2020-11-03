#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

#define ScNum "%d"
#define PrNum "%d"

typedef int num_t;

#define SIZE_K 2

#define ALLOCATION_ERR 1
#define READ_ERR 2
#define ARG_ERR 3
#define EMPTY_ERR 4

typedef struct {
    num_t *data;
    size_t capacity;
    size_t len;
} inttype;

inttype *allocate_vector(size_t len);
void free_vector(inttype *arr);
int input(inttype *arr, size_t len);
void output(inttype *arr);
int delete_prime_ind(inttype *arr);

void shift(num_t *arr, size_t len, size_t ind);

size_t set_len(inttype **arr, size_t len, size_t newlen);


#endif //_ARRAY_H_