#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define SIZE_ERROR 2
#define INPUT_ERROR 3
#define EMPTY_OUT 4

typedef long long my_int;
typedef my_int array_t[N][N];

int input(my_int a[][N], size_t n, size_t m);
int output(my_int a[][N], size_t n, size_t m);
void swap(my_int *a, my_int *b);

#endif