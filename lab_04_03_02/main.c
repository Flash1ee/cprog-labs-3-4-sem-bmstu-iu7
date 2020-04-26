#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"


int main()
{
    setbuf(stdout, NULL);

    string_t s1;
    string_t s2;
    matrix_word s1_words;
    matrix_word s2_words;

    int empty = 0;
    size_t cnt_1 = 0;
    size_t cnt_2 = 0;
    char split_symbols[] = { ',', ';', ':', '-', '.', '!', '?', ' ' };

    if (read_line(s1) == NULL || read_line(s2) == NULL)
        return ERROR_IO;

    if (split_line(s1, s1_words, split_symbols, &cnt_1) != OK)
        return ERROR_IO;
    if (split_line(s2, s2_words, split_symbols, &cnt_2) != OK)
        return ERROR_IO;

    printf("Result: ");

    search_word(s1_words, s2_words, &empty, cnt_1, cnt_2);
    search_word(s2_words, s1_words, &empty, cnt_1, cnt_2);

    if (!empty)
        return EQUAL_ROWS;


    return OK;
}
