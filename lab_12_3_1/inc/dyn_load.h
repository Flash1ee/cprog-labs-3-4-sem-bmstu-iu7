#ifndef __DYN_LOAD_H__
#define __DYN_LOAD_H__

#include <stdio.h>

typedef int (*fn_key_t)(const int *, const int *, int **, int **);
typedef int (*fn_fill_t)(FILE *, int *, int *);
typedef void (*fn_print_t)(FILE *, int *, size_t);

int dyn_load(int argc, char *argv[]);


#endif  // __DYN_LOAD_H__