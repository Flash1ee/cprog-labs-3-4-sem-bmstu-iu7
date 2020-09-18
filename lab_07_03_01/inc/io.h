#ifndef _IO_H
#define _IO_H
#include <stdio.h>
#include <stdlib.h>


int f_long_cnt(FILE *f, size_t *size);
int fill(FILE *f, long *pa, long *pb);


#endif