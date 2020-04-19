#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#define MAXSTR 256
#define MAXWORD 16

typedef char* my_str;
typedef my_str string_t[MAXSTR+1];
typedef my_str my_word[MAXWORD+1];

char *my_strchr(const char *str, int symbol);
char *my_strrchr(const char *str, int symbol);
char *my_strpbrk(const char *str, const char *temp);
size_t my_strspn(const char *str, const char *temp);
size_t my_strcspn(const char *str, const char *temp);


#endif