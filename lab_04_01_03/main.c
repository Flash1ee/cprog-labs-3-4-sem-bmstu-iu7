#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main()
{
    setbuf(stdout, NULL);
    string_t s1;
    string_t s2;
    size_t cnt = 0;

    word_matrix s1_words;
    char split_symbols[] = ",;:-.!? ";
    s2[0] = '\0';

    if (read_line(s1) == NULL)
        return ERROR_IO;

    if (split_line(s1, s1_words, split_symbols, &cnt) != OK)
        return ERROR_IO;

    if (make_output_line(s1_words, s2, cnt) != OK)
        return ERROR_IO;

    printf("Result: ");
    printf("%s", s2);

    return EXIT_SUCCESS;
}
