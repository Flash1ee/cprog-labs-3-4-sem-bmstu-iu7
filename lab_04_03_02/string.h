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

my_str *read_line(my_str str[]);
int split_line(my_str line[], my_str words[], my_str split_symbols[]);
void search_word(my_str s1[], my_str s2[], int *empty);


#endif //STRING_H