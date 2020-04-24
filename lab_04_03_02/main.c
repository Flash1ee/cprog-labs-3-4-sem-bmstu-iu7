#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

#define EXIT_SUCCESS 0
#define ERROR_IO 1
#define EQUAL_ROWS 2
#define SPLIT_CHAR 8

char *read_line(char str[]);
int split_line(char line[], char words[], char split_symbols[]);
void search_word(char s1[], char s2[], int *empty);
int main()
{
    setbuf(stdout, NULL);
    string_t s1;
    string_t s2;
    string_t s1_words;
    string_t s2_words;
    int empty = 0;
    char split_symbols[] = {',',';',':','-','.','!','?', ' '};

    if (read_line(s1) == NULL || read_line(s2) == NULL) return ERROR_IO;

    if (split_line(s1, s1_words, split_symbols) != EXIT_SUCCESS)
            return ERROR_IO;
    if (split_line(s2, s2_words, split_symbols) != EXIT_SUCCESS)
            return ERROR_IO;
    printf("Result:");
    search_word(s1_words,s2_words,&empty);
    search_word(s2_words,s1_words,&empty);
    if (!empty) return EQUAL_ROWS;


    return EXIT_SUCCESS;
}

char *read_line(char line[])
{
    int el;
    size_t i = 0;
    while ((el = getchar()) != '\n' && el != EOF && i < MAXSTR)
            line[i++] = el;
    if (el != '\n' || i < 1) return NULL;
    line[i] = '\0';
    return line;
}
int split_line(char line[], char words[], char split_symbols[])
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
             if (word_len > MAXWORD) return EXIT_FAILURE;
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
    return EXIT_SUCCESS;
}
void search_word(char s1[], char s2[], int *empty)
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
        while (s1[i]!=' ' && s1[i]!='\0') 
            word_1[j_1++] = s1[i++];
        word_1[j_1] = '\0';
        if (s1[i]!='\0') i++;
        while (s2[m] != '\0')
        {
            while (s2[m]!=' ' && s2[m]!='\0') 
                word_2[j_2++] = s2[m++];
            word_2[j_2] = '\0';
            if (s2[m]!='\0') m++;
            if (word_2 && strcmp(word_1, word_2) == 0)
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
            if (!*empty) *empty = 1;
        }
        flag = 0;
        m = 0;
        j_1 = 0;
    }
}
