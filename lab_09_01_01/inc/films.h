#ifndef FILMS_H
#define FILMS_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#include "utils.h"
#define N 25
#define MAX 15

#define ALLOCATION_ERR 4
#define READ_STRUCT_ERR 3


// typedef struct
// {
//     char title[N + 1];
//     char name[N + 1];
//     long year;
// } cinema;

typedef struct 
{
    char *title;
    char *name;
    long year;
} cinema;




typedef enum {
    TITLE,
    NAME,
    YEAR
} Field;


// int fill(FILE *f, cinema list[], size_t *size, Field key);
int fill(FILE *f, cinema **list, size_t file_len, Field key);

// void add_sort(cinema *tmp, cinema list[], Field key, size_t *size);
int add_sort(char *title, char *name, long year, cinema **list, Field key, size_t *size);

// void print(cinema list[], size_t len);
void print(cinema **list, size_t len);

// long bin_search(cinema list[], Field field, char key[], size_t size);
long bin_search(cinema **list, Field field, char key[], size_t size);

cinema **create_cinema_list(size_t n);
void free_list(cinema **list, size_t n);
int size_file(FILE *in, size_t *count);
int swap_cinema(cinema *dst, cinema *src);

/**
*@brief Инициализация структуры
*
*@param dst Структура для присваивания
*@param title Поле заголовка
*@param name Поле имени
*@param year Поле года
*@return int 
*@warning В случае ошибки выделения памяти title, name освобождаются внутри.
 */
int initialize_cinema(cinema *dst, char *title, char *name, long year);


#endif //FILMS_H