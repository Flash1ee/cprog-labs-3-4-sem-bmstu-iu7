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

typedef char my_str;
typedef my_str string_t[MAXSTR + 1];
typedef my_str my_word[MAXWORD + 1];
typedef my_str matrix_word[MAXSTR][MAXWORD + 1];

my_str *read_line(my_str str[]);
int split_line(my_str line[], matrix_word words, my_str split_symbols[], size_t *cnt);
void search_word(matrix_word s1, matrix_word s2, int *empty, size_t cnt_1, size_t cnt_2);


#endif // STRING_H