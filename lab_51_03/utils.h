#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define OK 0
#define ERROR_IN -1
#define ARG_ERR -2
#define OPEN_ERR -3
#define WRITE_ERR -4
#define MODE_ERR -5
#define ERR_CNT -6
#define READ_ERR -7
#define SIZE_ERR -8
#define SORT_ERR -9
#define BEATEN_FILE -10

#define DIGITS 1000

int write_rand(FILE *f, size_t cnt);
int print(FILE *f, size_t size);
int file_size(FILE *f, size_t *size);
int get_number_by_pos(FILE *f, size_t pos, int *num);
int put_number_by_pos(FILE *f, size_t pos, int *num);
int bubble_sort(FILE *f, size_t j);


#endif //_UTILS_H