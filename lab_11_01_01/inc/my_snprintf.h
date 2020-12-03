#ifndef _MY_SNPRINTF_
#define _MY_SNPRINTF_

#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <stdarg.h>

#define INT_MAX_M 11
#define LONG_MAX_M 20

typedef enum
{
    CHAR,
    LONG,
    I_INT,
    INT,
    STRING,
    COUNT,
    ERR
} spec;

/**
*@brief Implementation of snprintf()
*
*@param str 
*@param size 
*@param format 
*@param ... 
*@return int 
 */
int my_snprintf(char *str, size_t size, const char *format, ...);

spec is_process_symbol(char *ptr);
size_t args_to_write(const char *str);
size_t fill_arr_types(int arr[], size_t n, const char *types);
char *my_itoa(long long value, char *string, int radix);
size_t my_strcpy(char *dest, char *src);
size_t my_strncpy(char *dest, char *src, size_t n);
char *my_strncat(char *dest, char *src, size_t n);
size_t my_strlen(char *str);
int is_percent(const char *str);
size_t print_to_string(char *str, size_t size, const char *format, va_list args, int types[], size_t cn_args);
size_t write_to_str(size_t *cur_size, size_t size_max, char **str, const char **fmt, va_list write_args, spec type);

#endif // _MY_SNPRINTF_
