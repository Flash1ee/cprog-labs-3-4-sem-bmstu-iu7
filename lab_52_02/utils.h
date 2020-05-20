#ifndef _UTIlS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NAME 30
#define MAKER 15
#define ARG_ERR 53
#define ERROR_IN 1
#define SEARCH_ERR 2
#define OPEN_ERR 3
#define WRITE_ERR 4
#define MODE_ERR 5
#define COPY_ERR 6
#define READ_ERR 7
#define SIZE_ERR 8
#define SORT_ERR 9
#define BEATEN_FILE 10
#define OUT_ERR 11


struct product
{
    char name[NAME + 1];
    char manufacture[MAKER + 1];
    uint32_t price;
    uint32_t count;
};

int sort(FILE *in, size_t size, struct product *s1, struct product *s2);
int file_size(FILE *in, size_t *size);
int get_struct(FILE *in, size_t pos, size_t size, struct product *s1);
int put_struct(FILE *in, size_t pos, size_t size, struct product *var);
int search_struct(FILE *in, const char *value);
int file_copy(FILE *src, FILE *dst);
int insert(FILE *in, size_t size);
int struct_shift(FILE *in, size_t st, size_t end);
int add_struct(FILE *in);
int print(FILE *f, size_t size);


#endif //_UTILS_H