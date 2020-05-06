#define __USE_MINGW_ANSI_STDIO 1
#include "string.h"


char *my_strchr(const char *str, int symbol)
//Поиск первого вхождения указанного символа.(включая '\0') или NULL
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
        if ((int)str[i] == symbol)
            return (char*)str + i;
    if (str[i] == symbol)
        return (char*)str+i;
    return NULL;
}
char *my_strrchr(const char *str, int symbol)
//Поиск последнего вхождения указанного символа.(включая '\0') или NULL;
{
    char *tmp = NULL;
    size_t i;
    for (i = 0; str[i] != '\0'; i++)
        if ((int)str[i] == symbol)
            tmp = (char*)str+i;
    if (str[i] == symbol)
        return (char*)str+i;
    return tmp;
}
char *my_strpbrk(const char *str, const char *temp)
//указатель на первое вхождение одного из символов temp в str или NULL
{
    for (size_t i = 0; str[i] != '\0'; i++)
        for (size_t j = 0; temp[j] != '\0'; j++)
            if (temp[j] == str[i])
                return (char*)str+i;
    return NULL;
}
size_t my_strspn(const char *str, const char *temp)
//Размер первой подстроки, содержащей только элементы temp
{
    int flag = 0;
    size_t cnt = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for (size_t j = 0; temp[j] != '\0'; j++)
            if (str[i] == temp[j])
                flag = 1;
        if (flag)
            cnt += 1;
        else
            return cnt;
        flag = 0;
    }
    return cnt;
}
size_t my_strcspn(const char *str, const char *temp)
//Размер первой подстроки, НЕ содержащей символов из temp
{
    int flag = 0;
    size_t cnt = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for (size_t j = 0; temp[j] != '\0'; j++)
            if (str[i] == temp[j])
                flag = 1;
        if (flag)
            return cnt;
        else
            cnt += 1;
    }
    return cnt;
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

