#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

#define N 26
#define MAX 15
#define FIRST_FILM 1895
#define LAST_FILM 2030
#define TITLE 41
#define NAME 42
#define YEAR 43



struct cinema
{
    char title[N + 1];
    char name[N + 1];
    long year;
};


#define ARG_ERR 1
#define READ_FILE_ERR 2
#define READ_STRUCT_ERR 3
#define EMPTY 4
#define BIN_ERR 4
#define KEY_ERR -2
#define NOT_FOUND -1


int fill(FILE *f, struct cinema list[], size_t *size, size_t key);
void print(struct cinema list[], size_t len);
long bin_search(struct cinema list[], long field, char key[], size_t size);

#endif