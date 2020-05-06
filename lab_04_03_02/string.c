#include "string.h"
#include <string.h>


char *read_line(char line[])
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
int split_line(char line[], matrix_word words, char split_symbols[], size_t *cnt)
{
    char word[MAXWORD + 1];
    size_t i = 0;
    int flag = 0;
    size_t ind_line = 0;
    size_t ind_word = 0;
    size_t word_len = 0;

    while (line[ind_line] != '\0')
    {
        for (size_t j = 0; j < SPLIT_CHAR; j++)
            if (line[ind_line] == split_symbols[j])
                flag = 1;
        if (flag)
        {
            if (word_len > MAXWORD)
                return LONG_WORD;
            if (word_len != 0)
            {
                word[ind_word] = '\0';
                word_len = 0, ind_word = 0;
                strncpy(words[i++], word, strlen(word) + 1);
            }
            flag = 0;
        }
        else
        {
            word[ind_word++] = line[ind_line];
            word_len++;
        }
        ind_line++;
    }
    if (word_len != 0)
    {
        word[ind_word] = '\0';
        strncpy(words[i++], word, strlen(word) + 1);
    }
    *cnt = i;
    return OK;
}
void search_word(matrix_word s1, matrix_word s2, int *empty, size_t cnt_1, size_t cnt_2)
{
    my_word word_1;
    int flag = 0;

    for (size_t i = 0; i < cnt_1; i++)
    {
        strncpy(word_1, s1[i], strlen(s1[i]) + 1);
        for (size_t j = 0; j < cnt_2; j++)
            if (strcmp(word_1, s2[j]) == 0)
                flag = 1;
        for (size_t j = 0; j < cnt_1; j++)
            if ((j != i) && strcmp(word_1, s1[j]) == 0)
                flag = 1;
        if (!flag)
        {
            printf("%s ", word_1);
            if (!*empty)
                *empty = 1;
        }
        flag = 0;
    }
}
