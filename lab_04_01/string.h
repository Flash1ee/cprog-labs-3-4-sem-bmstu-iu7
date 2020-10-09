#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TESTS 6


char *my_strchr(const char *str, int symbol);
char *my_strrchr(const char *str, int symbol);
char *my_strpbrk(const char *str, const char *temp);
size_t my_strspn(const char *str, const char *temp);
size_t my_strcspn(const char *str, const char *temp);


void func_strcspn(const char *str, const char *temp, size_t ind);
void func_strpbrk(const char *str, const char *temp, size_t ind);
void func_strspn(const char *str, const char *temp, size_t ind);
void func_strrchr(const char *str, int el, size_t ind);
void func_strchr(const char *str, int el, size_t ind);


#endif //STRING_H