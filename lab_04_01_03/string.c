#include <string.h>
#include "string.h"

my_str *read_line(my_str line[])
{
    int el;
    size_t i = 0;
    while ((el = getchar()) != '\n' && el != EOF && i < MAXSTR)
        line[i++] = el;
    if (el != '\n' || i < 1)
        return NULL;
    line[i] = '\0';
    return line;
}

void delete_repeat_symbol(my_str word[])
{
    char *beg;
    char *end;
    char symbol;
    my_word cur_word;
    my_word tmp;
    size_t size;
    for (size_t i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            symbol = word[i];
            beg = strchr(word, symbol);
            end = strrchr(word, symbol);
            while (beg != end)
            {
                size = strlen(word);
                strcpy(cur_word, end + 1);
                strcpy(tmp, word);
                strncpy(word, tmp, (size - strlen(end)));
                *end = '\0';
                //Зануление,чтобы корректно сконкатенировать строки.
                strcat(word, cur_word);
                end = strrchr(word, symbol);
            }
        }
    }
}

int split_line(my_str s1[], word_matrix words, my_str delim[], size_t *cnt)
{
    char *ptr;
    int empty_err = 0;
    ptr = strtok(s1, delim);
    size_t i = 0;
    while (ptr != NULL)
    {
        if (strlen(ptr) > MAXWORD)
            return LEN_WORD;
        if (!empty_err)
            empty_err = 1;
        strncpy(words[i++], ptr, strlen(ptr) + 1);
        ptr = strtok(NULL, delim);
    }
    *cnt = i;
    if (!empty_err)
        return ERROR_IO;

    return OK;
}
int make_output_line(word_matrix words, my_str output[], size_t cnt)
{
    int error_io = 0;
    my_word word_flag;
    my_word new_word;
    strncpy(word_flag, words[cnt - 1], strlen(words[cnt - 1]) + 1);
    for (int j = cnt - 2; j >= 0; j--)
    {
        if (strcmp(words[j], word_flag) != 0)
        {
            error_io = 1;
            strncpy(new_word, words[j], strlen(words[j]) + 1);
            delete_repeat_symbol(new_word);
            strcat(output, new_word);
            strcat(output, " ");
        }
    }
    if (output[strlen(output) - 1] == ' ')
        output[strlen(output) - 1] = '\0';

    if (!error_io)
        return ERROR_IO;
    return OK;
}