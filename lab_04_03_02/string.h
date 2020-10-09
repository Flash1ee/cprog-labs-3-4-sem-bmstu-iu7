#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define ERROR_IO 1
#define EQUAL_ROWS 2
#define LONG_WORD 3

#define SPLIT_CHAR 8
#define MAXSTR 256
#define MAXWORD 16

typedef char string_t[MAXSTR + 1];
typedef char my_word[MAXWORD + 1];
typedef char matrix_word[MAXSTR][MAXWORD + 1];

char *read_line(char str[]);
int split_line(char line[], matrix_word words, char split_symbols[], size_t *cnt);
void search_word(matrix_word s1, matrix_word s2, int *empty, size_t cnt_1, size_t cnt_2);


#endif // STRING_H