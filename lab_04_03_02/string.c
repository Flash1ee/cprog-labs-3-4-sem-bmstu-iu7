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
int split_line(my_str line[],matrix_word words, my_str split_symbols[], size_t *cnt)
{
    int flag = 0;
    size_t ind_line = 0;
    size_t ind_words = 0;
    size_t word_len = 0;
    my_str word[MAXWORD+1];

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
                ind_words = 0;
                strncpy(words[*cnt], word, MAXWORD+1);
                *cnt = *cnt + 1;
                for (size_t ind = 0; ind < MAXWORD; ind++) word[ind] = '\0';
            }
            flag = 0;
        }
        else
        {
            word[ind_words++] = line[ind_line];
            word_len++;
        }
        ind_line++;
    }
    return OK;
}

void search_word(matrix_word s1, matrix_word s2, int *empty, size_t cnt_1, size_t cnt_2)
{
    my_word word_1;
    my_word word_2;
    size_t i = 0;
    size_t m = 0;
    size_t j = 0;
    int flag = 0;
    while (i != cnt_1)
    {
        strcpy(word_1, s1[i++]);
        while (m != cnt_2)
        {
            strcpy(word_2, s2[m]);
            if (strcmp(word_1, word_2) == 0)
            {
                flag = 1;
                break;
            }
            for (size_t ind = 0; ind < MAXWORD; ind++) word_2[ind] = '\0';
            m++;
        }
        while (j < i && !flag)
        {
            strcpy(word_2, s1[j]);
            if (strcmp(word_1, word_2) == 0)
            {
                flag = 1;
                break;
            }
            for (size_t ind = 0; ind < MAXWORD; ind++) word_2[ind] = '\0';
            j++;
        }
        if (!flag)
        {
            printf("%s ", word_1);
            if (!*empty)
                *empty = 1;
        }
        flag = 0;
        m = 0;
        j = 0;
        for (size_t ind = 0; ind < MAXWORD; ind++) word_1[ind] = '\0';
    }
}
