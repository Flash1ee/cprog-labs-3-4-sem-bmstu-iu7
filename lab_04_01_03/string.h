#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSTR 256
#define MAXWORD 16
#define SPLIT_CHAR 8

#define EXIT_SUCCESS 0
#define ERROR_IO 1
#define LEN_WORD 3
#define EQUAL_ROWS 2

typedef char my_str;
typedef my_str string_t[MAXSTR + 1];
typedef my_str my_word[MAXWORD + 1];
typedef my_str word_matrix[MAXSTR][MAXWORD + 1];

my_str *read_line(my_str str[]);
void delete_repeat_symbol(my_str word[]);

#endif