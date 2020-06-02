#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSTR 256
#define MAXWORD 16
#define SPLIT_CHAR 8

#define OK 0
#define ERROR_IO 1
#define LEN_WORD 3
#define EQUAL_ROWS 2

typedef char string_t[MAXSTR + 1];
typedef char my_word[MAXWORD + 1];
typedef char word_matrix[MAXSTR][MAXWORD + 1];

char *read_line(char str[]);
void delete_repeat_symbol(char word[]);
int split_line(char s1[], word_matrix words, char delim[], size_t *cnt);
int make_output_line(word_matrix words, char output[], size_t cnt);

#endif