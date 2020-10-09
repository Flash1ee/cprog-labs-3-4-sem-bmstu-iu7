#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

int main()
{
    const char *symbols = "abcde";

    const char test[][15] = { "$Unclea Sasha!", "aMoscow?", "", "00 0", "aa,a", "123456789", "S",
        "\0", "\0", "1", "A", "0" };

    const char test_1[][2] = { "a", "o", " ", "0", "b", "\0" };

    for (size_t i = 0; i < TESTS; i++)
        func_strchr(test[i], (int)test[i + TESTS][0], i + 1);
    printf("\n");
    for (size_t i = 0; i < TESTS; i++)
        func_strrchr(test[i], (int)test_1[i][0], i + 1);
    printf("\n");
    for (size_t i = 0; i < TESTS; i++)
        func_strpbrk(test[i], symbols, i + 1);
    printf("\n");
    for (size_t i = 0; i < TESTS; i++)
        func_strspn(test[i], symbols, i + 1);
    printf("\n");
    for (size_t i = 0; i < TESTS; i++)
        func_strcspn(test[i], symbols, i + 1);

    return EXIT_SUCCESS;
}

