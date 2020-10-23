#ifndef FILMS_H
#define FILMS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define N 25
#define MAX 15

#define READ_STRUCT_ERR 3


typedef struct
{
    char title[N + 1];
    char name[N + 1];
    long year;
} cinema;

// typedef struct 
// {
//     char **name;
//     char **title;
//     long year;
// } cinema;




typedef enum {
    TITLE,
    NAME,
    YEAR
} Field;


int fill(FILE *f, cinema list[], size_t *size, Field key);
void add_sort(cinema *tmp, cinema list[], Field key, size_t *size);
void print(cinema list[], size_t len);
long bin_search(cinema list[], Field field, char key[], size_t size);

// cinema **create_cinema_list(size_t n);

#endif //FILMS_H