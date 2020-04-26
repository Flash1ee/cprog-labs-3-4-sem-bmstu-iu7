#include "string.h"
#include <string.h>


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
int split_line(my_str line[], my_str words[], my_str split_symbols[])
{
    int flag = 0;
    size_t ind_line = 0;
    size_t ind_words = 0;
    size_t word_len = 0;

    while (line[ind_line] != '\0')
    {
        for (size_t j = 0; j < SPLIT_CHAR; j++)
        {
            if (line[ind_line] == split_symbols[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            if (word_len > MAXWORD)
                return LONG_WORD;
            else if (word_len != 0)
            {
                word_len = 0;
                words[ind_words++] = ' ';
            }
            flag = 0;
        }
        else
        {
            words[ind_words++] = line[ind_line];
            word_len++;
        }
        ind_line++;
    }
    words[ind_words] = '\0';
    return OK;
}
void search_word(my_str s1[], my_str s2[], int *empty)
{
    my_word word_1;
    my_word word_2;
    size_t i = 0;
    size_t m = 0;
    size_t j_1 = 0;
    size_t j_2 = 0;
    int flag = 0;
    while (s1[i] != '\0')
    {
        while (s1[i] != ' ' && s1[i] != '\0')
            word_1[j_1++] = s1[i++];
        word_1[j_1] = '\0';
        if (s1[i] != '\0')
            i++;
        while (s2[m] != '\0')
        {
            while (s2[m] != ' ' && s2[m] != '\0')
                word_2[j_2++] = s2[m++];
            word_2[j_2] = '\0';
            if (s2[m] != '\0')
                m++;
            if (strcmp(word_1, word_2) == 0)
            {
                flag = 1;
                j_2 = 0;
                break;
            }
            j_2 = 0;
        }
        if (!flag)
        {
            printf("%s ", word_1);
            if (!*empty)
                *empty = 1;
        }
        flag = 0;
        m = 0;
        j_1 = 0;
    }
}
