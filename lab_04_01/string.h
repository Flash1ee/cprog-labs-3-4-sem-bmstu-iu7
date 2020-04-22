#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

char *my_strchr(const char *str, int symbol);
char *my_strrchr(const char *str, int symbol);
char *my_strpbrk(const char *str, const char *temp);
size_t my_strspn(const char *str, const char *temp);
size_t my_strcspn(const char *str, const char *temp);


#endif