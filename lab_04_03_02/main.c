#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"


int main()
{
    setbuf(stdout, NULL);

    string_t s1;
    string_t s2;
    string_t s1_words;
    string_t s2_words;

    int empty = 0;
    char split_symbols[] = { ',', ';', ':', '-', '.', '!', '?', ' ' };

    if (read_line(s1) == NULL || read_line(s2) == NULL)
        return ERROR_IO;

    if (split_line(s1, s1_words, split_symbols) != OK)
        return ERROR_IO;
    if (split_line(s2, s2_words, split_symbols) != OK)
        return ERROR_IO;

    printf("Result: ");

    search_word(s1_words, s2_words, &empty);
    search_word(s2_words, s1_words, &empty);

    if (!empty)
        return EQUAL_ROWS;


    return OK;
}
