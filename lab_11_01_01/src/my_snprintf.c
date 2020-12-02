#include "my_snprintf.h"

const char *spec_arr[] = {
    "c",
    "ld",
    "i",
    "d",
    "s"

};

spec is_process_symbol(char *ptr)
{
    if (*ptr)
    {
        for (size_t i = 0; i < COUNT; ++i)
        {
            if (*ptr == *spec_arr[i] && i != LONG)
            {
                return i;
            }
            else if (*ptr == *spec_arr[i] && i == LONG)
            {
                if (*ptr == spec_arr[i][0] && *(ptr + 1) == spec_arr[i][1])
                {
                    return i;
                }
                return ERR;
            }
        }
    }
    return ERR;
}
size_t args_to_write(const char *str)
{
    size_t cn = 0;
    for (const char *cur = str; *cur != '\0'; cur++)
    {
        if (*cur == '%' && *(cur + 1) == '%')
        {
            cur++;
        }
        else if (*cur == '%')
        {
            cur++;
            spec type = is_process_symbol((char *)cur);
            if (type == ERR)
            {
                return ERR;
            }
            if (type == LONG)
            {
                cur++;
            }
            cn++;
        }
    }
    return cn;
}

size_t fill_arr_types(int arr[], size_t n, const char *types)
{
    size_t i = 0;
    char *cur = (char *)types;
    while (*cur)
    {
        while (*cur != '\0' && *cur != '%')
        {
            cur++;
        }
        if (!*cur)
        {
            break;
        }
        if (*(cur + 1) == '%')
        {
            cur += 2;
            continue;
        }
        cur++;
        for (size_t j = 0; j < COUNT; j++)
        {
            spec type = is_process_symbol(cur);
            if (type != ERR)
            {
                arr[i++] = type;
                cur++;
            }
            break;
        }
    }
    return n;
}
char *my_itoa(long long value, char *string, int radix)
{
    if (!string)
    {
        return string;
    }
    if (!value)
    {
        *string = '0';
        return string;
    }
    if (value < 0)
    {
        *string++ = '-';
    }
    long long tmp = value;
    while (tmp != 0)
    {
        string++;
        tmp /= radix;
    }
    *string = '\0';
    while (value != 0)
    {
        if (value < 0)
        {
            *(--string) = (value % radix) * (-1) + '0';
        }
        else
        {
            *(--string) = value % radix + '0';
        }

        value /= radix;
    }
    return string;
}
size_t my_strcpy(char *dest, char *src)
{
    assert(dest && src);

    char *beg = dest;
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return dest - beg;
}
char *my_strncat(char *dest, char *src, size_t n)
{
    char *ptr = NULL;
    for (ptr = dest; *ptr != '\0'; ptr++)
    {
        ;
    }
    for (size_t i = 0; i < n; i++)
    {
        *ptr++ = *src++;
    }
    return dest;
}
size_t my_strncpy(char *dest, char *src, size_t n)
{
    assert(dest && src);

    char *beg = dest;
    while (n)
    {
        *dest++ = *src++;
        n--;
    }
    *dest = '\0';
    return dest - beg;
}
size_t my_strlen(char *str)
{
    char *cur = str;
    while (*cur != '\0')
    {
        cur++;
    }
    return cur - str;
}
size_t write_to_str(int *cur_size, int size_max, char **str, const char **fmt, va_list write_args, spec type)
{
    switch (type)
    {
    case CHAR:
    {
        char val = va_arg(write_args, int);
        if (*cur_size < size_max)
        {
            **str = val;
        }
        *str += 1;
        *cur_size += 1;
        *fmt += 2;
        return sizeof(char);
    }
    case STRING:
    {
        char *val = va_arg(write_args, char *);
        int n_to_write = my_strlen(val);
        if (*cur_size + n_to_write <= size_max)
        {
            my_strncat(*str, val, n_to_write);
            *fmt += 2;
            *cur_size += n_to_write;
            *str += n_to_write;

            return n_to_write;
        }
        if (size_max > *cur_size)
        {
            size_t new_n = size_max - *cur_size;
            my_strncat(*str, val, new_n);
            *str += new_n;
        }
        *cur_size += n_to_write;
        *fmt += 2;

        return n_to_write;
    }
    case LONG:
    {
        char temp[LONG_MAX_M + 1] = {0};
        long val = va_arg(write_args, long);
        my_itoa(val, temp, 10);
        int n = my_strlen(temp);

        if (*cur_size + n <= size_max)
        {
            *str = my_strncat(*str, temp, n);
            *str += n;
        }
        *fmt += 3;
        *cur_size += n;
        return n;
    }
    default:
    {
        char temp[INT_MAX_M + 1] = {0};
        int val = va_arg(write_args, int);
        my_itoa(val, temp, 10);
        int n = my_strlen(temp);

        if (*cur_size + n <= size_max)
        {
            my_strncat(*str, temp, n);
            *str += n;
        }
        *fmt += 2;
        *cur_size += n;
        return n;
    }
    }
}
int my_snprintf(char *str, size_t size, const char *format, ...)
{
    if (!format)
    {
        return 0;
    }
    bool writing = my_strlen((char *)format) && size;
    if (writing)
    {
        memset(str, 0, my_strlen(str));
    }
    int n = args_to_write(format);
    if (n == ERR)
    {
        return -1;
    }
    int types[n];
    // Fill array flags of write types
    if (fill_arr_types(types, n, format) != (size_t) n)
    {
        return -1;
    }
    va_list write_args;
    va_start(write_args, format);

    int write_size = 0;
    int size_to_write = size - 1;
    size_t cur_arg = 0;

    char *dest = str;
    const char *tmp_format = format;

    while (cur_arg < (size_t) n || *tmp_format != '\0')
    {
        while (*tmp_format && *tmp_format != '%')
        {
            if (write_size < size_to_write)
            {
                *dest++ = *tmp_format;
            }
            write_size++;
            tmp_format++;
        }
        if (*tmp_format && *(tmp_format + 1) && *(tmp_format + 1) == '%')
        {
            if (write_size < size_to_write)
            {
                *dest++ = *tmp_format;
            }
            write_size++;
            tmp_format += 2;
        }
        else if (*tmp_format)
        {
            write_to_str(&write_size, size_to_write, &dest, &tmp_format, write_args, types[cur_arg]);
            cur_arg++;
        }
    }
    va_end(write_args);
    *(str + size_to_write) = '\0';

    return write_size;
}
