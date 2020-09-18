#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void mysort(void *first, size_t len, size_t size, int (*cmp)(const void *, const void*));
int cmp_l(const void *a, const void *b);

#endif