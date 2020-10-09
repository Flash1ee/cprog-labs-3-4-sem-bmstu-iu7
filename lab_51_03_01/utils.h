#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#define OK 0
#define ERROR_IN -1
#define EMPTY_IO -2 
#define FEW_PARAM -3

typedef long long my_int;

int process(FILE *f, size_t *cnt);

#endif