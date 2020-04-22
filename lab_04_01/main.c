#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

#define TESTS 6

void func_strcspn(const char *str, const char *temp, size_t ind);
void func_strpbrk(const char *str, const char *temp, size_t ind);
void func_strspn(const char *str, const char *temp, size_t ind);
void func_strrchr(const char *str, int el, size_t ind);
void func_strchr(const char *str, int el, size_t ind);
int main()
{
    // const char *temp = " ,.!";
    const char *symbols = "abcde";
    const char test[][15] = { "$Unclea Sasha!", "aMoscow?", "", "00 0", "aa,a", "123456789", "S",
        "\0", "\0", "1", "A", "0" };

    const char test_1[][2] = { "a", "o", " ", "0", "b", "0" };
    for (size_t i = 0; i < (sizeof(test) / sizeof(test[1])) / 2; i++)
        func_strchr(test[i], (int)test[i + TESTS][0], i + 1);
    printf("\n");
    for (size_t i = 0; i < sizeof(test_1) / sizeof(test_1[0]); i++)
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

void func_strchr(const char *str, int el, size_t ind)
{
    if (my_strchr(str, el) == strchr(str, el))
        printf("TEST_STRCHR_%zu PASSED\n", ind);
    else
        printf("TEST_STRCHR_%zu FAILED\n", ind);
}
void func_strrchr(const char *str, int el, size_t ind)
{
    if (my_strrchr(str, el) == strrchr(str, el))
        printf("TEST_STRRCHR_%zu PASSED\n", ind);
    else
        printf("TEST_STRRCHR_%zu FAILED\n", ind);
}
void func_strpbrk(const char *str, const char *temp, size_t ind)
{
    if (my_strpbrk(str, temp) == strpbrk(str, temp))
        printf("TEST_STRPBRK_%zu PASSED\n", ind);
    else
        printf("TEST_STRPBRK_%zu FAILED\n", ind);
}
void func_strspn(const char *str, const char *temp, size_t ind)
{
    if (my_strspn(str, temp) == strspn(str, temp))
        printf("TEST_STRSPN_%zu PASSED\n", ind);
    else
        printf("TEST_STRSPN_%zu FAILED\n", ind);
}
void func_strcspn(const char *str, const char *temp, size_t ind)
{
    if (my_strcspn(str, temp) == strcspn(str, temp))
        printf("TEST_STRCSPN_%zu PASSED\n", ind);
    else
        printf("TEST_STRCSPN_%zu FAILED\n", ind);
}
