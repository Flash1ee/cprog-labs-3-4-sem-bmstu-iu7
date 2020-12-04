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
        if (is_percent(cur))
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
        while (*cur && *cur != '%')
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
char *my_strncat(char *dest, char *src, size_t n)
{
    char *ptr = dest;
    while (*ptr)
    {
        ptr++;
    }
    for (size_t i = 0; i < n; i++)
    {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return dest;
}
size_t my_strncpy(char *dest, char *src, size_t n)
{
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
    while (*cur)
    {
        cur++;
    }
    return cur - str;
}
size_t write_to_str(size_t *cur_size, size_t size_max, char **str, const char **fmt, va_list write_args, spec type)
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
            if (!*cur_size)
            {
                my_strncpy(*str, val, n_to_write);
            }
            else
            {
                my_strncat(*str, val, n_to_write);
            }
            *fmt += 2;
            *cur_size += n_to_write;
            *str += n_to_write;

            return n_to_write;
        }
        if (size_max > *cur_size)
        {
            size_t new_n = size_max - *cur_size;
            if (!*cur_size)
            {
                my_strncpy(*str, val, new_n);
            }
            else
            {
                my_strncat(*str, val, new_n);
            }
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
            if (!*cur_size)
            {
                my_strncpy(*str, temp, n);
            }
            else
            {
                my_strncat(*str, temp, n);
            }
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
            if (!*cur_size)
            {
                my_strncpy(*str, temp, n);
            }
            else
            {
                my_strncat(*str, temp, n);
            }
            *str += n;
        }
        *fmt += 2;
        *cur_size += n;
        return n;
    }
    }
}
int is_percent(const char *str)
{
    if (*str == '%' && *(str + 1) == '%')
    {
        return true;
    }
    return false;
}
size_t print_to_string(char *str, size_t size, const char *format, va_list args, int types[], size_t cn_args)
{
    size_t cur_size = 0;
    size_t max_size = 0;
    size_t cur_arg = 0;
    char *dest = str;
    const char *tmp_format = format;
    bool writing = my_strlen((char *)format) && size;

    if (size)
    {
        max_size = size - 1;
    }
    while (cur_arg < cn_args || *tmp_format)
    {
        while (*tmp_format != '%' || is_percent(tmp_format))
        {
            if (!*tmp_format)
            {
                break;
            }
            if (cur_size < max_size)
            {
                *dest++ = *tmp_format;
                *dest = '\0';
            }
            cur_size++;
            if (is_percent(tmp_format))
            {
                tmp_format += 2;
                continue;
            }
            tmp_format++;
        }
        if (*tmp_format)
        {
            write_to_str(&cur_size, max_size, &dest, &tmp_format, args, types[cur_arg]);
            cur_arg++;
        }
    }
    if (writing)
    {
        (size == 1) ? *str = '\0' : (*dest = '\0');
    }

    return cur_size;
}

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    if (!format)
    {
        return 0;
    }
    size_t n = args_to_write(format);
    if (n == ERR)
    {
        return -1;
    }
    int types[n];
    if (fill_arr_types(types, n, format) != n) // Fill array flags of write types
    {
        return -1;
    }

    va_list args;
    va_start(args, format);
    size_t cnt_all = print_to_string(str, size, format, args, types, n);
    va_end(args);

    return cnt_all;
}
