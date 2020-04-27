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
    // ASCII [97:122] - нижние буквы;
    // ASCII [65:90] - верхние буквы;
    char *beg;
    char *end;
    char symbol;
    my_word cur_word;
    my_word tmp;
    for (size_t i = 0; i < MAXWORD; i++)
        tmp[i] = '\0';
    size_t size;
    for (size_t i = 0; word[i] != '\0'; i++)
    {
        if ((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
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
                for (size_t i = 0; i < MAXWORD; i++)
                    tmp[i] = '\0';
                *end = '\0';
                strcat(word, cur_word);
                end = strrchr(word, symbol);
            }
        }
    }
}
