#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main()
{
    setbuf(stdout, NULL);
    string_t s1;
    string_t s2;
    word_matrix s1_words;
    my_word word_flag;
    my_word new_word;
    int empty = 0;
    int error_io = 0;
    char split_symbols[] = ",;:-.!? ";

    if (read_line(s1) == NULL)
        return ERROR_IO;

    for (size_t i = 0; i < MAXWORD; i++)
        s2[i] = '\0';

    char* ptr;
    ptr = strtok(s1, split_symbols);
    size_t i = 0;

    while (ptr != NULL)
    {
        if (!empty)
            empty = 1;
        if (strlen(ptr) > MAXWORD)
            return LEN_WORD;
        strncpy(s1_words[i++], ptr, MAXWORD + 1);
        ptr = strtok(NULL, split_symbols);
    }

    strncpy(word_flag, s1_words[i - 1], MAXWORD + 1);

    for (int j = i - 2; j >= 0; j--)
    {
        if (strcmp(s1_words[j], word_flag) != 0)
        {
            error_io = 1;
            strncpy(new_word, s1_words[j], MAXWORD + 1);
            delete_repeat_symbol(new_word);
            strcat(s2, new_word);
            strcat(s2, " ");
        }
    }
    if (s2[strlen(s2) - 1] == ' ')
        s2[strlen(s2) - 1] = '\0';

    if (!error_io)
        return ERROR_IO;

    printf("Result: ");
    printf("%s", s2);

    return EXIT_SUCCESS;
}