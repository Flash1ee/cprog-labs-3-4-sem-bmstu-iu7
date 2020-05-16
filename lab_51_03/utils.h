#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_IN 1
#define ARG_ERR 2
#define OPEN_ERR 3
#define WRITE_ERR 4
#define MODE_ERR 5
#define ERR_CNT 6
#define READ_ERR 7
#define SIZE_ERR 8

#define DIGITS 1000

int write_rand(FILE *f, size_t cnt);
int print(FILE *f, size_t size);
int file_size(FILE *f , size_t *size);

#endif //_UTILS_H