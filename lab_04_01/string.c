#include "string.h"

//Поиск первого вхождения указанного символа.(включая '\0') или NULL
char *my_strchr(const char *str, int symbol)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if ((int)str[i] == symbol) return (char*)&str[i];
    return NULL;
}
//Поиск последнего вхождения указанного символа.(включая '\0') или NULL;
char *my_strrchr(const char *str, int symbol)
{
    char *tmp = NULL;
    for (size_t i = 0; str[i] != '\0'; i++)
        if ((int)str[i] == symbol) 
            tmp = (char*)&str[i];
    return tmp;
}
//указатель на первое вхождение одного из символов temp в str или NULL
char *my_strpbrk(const char *str, const char* temp)
{
    for (size_t i = 0; str[i] != '\0';i++)
        for (size_t j = 0; temp[j] != '\0'; j++)
            if (temp[j] == str[i]) return (char*)&str[i];
    return NULL;
}
//Размер первой подстроки, содержащей только элементы temp
size_t my_strspn(const char *str, const char *temp)
{
    int flag = 0;
    size_t cnt = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for(size_t j = 0; temp[j] != '\0'; j++)
            if (str[i] == temp[j]) flag = 1;
        if (flag) return cnt += 1;
        else return cnt;
    }
    return cnt;
}
//Размер первой подстроки, НЕ содержащей символов из temp
size_t my_strcspn(const char *str, const char *temp)
{
    int flag = 0;
    size_t cnt = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for(size_t j = 0; temp[j] != '\0'; j++)
            if (str[i] == temp[j]) flag = 1;
        if (flag) return cnt;
        else cnt +=1;
    }
    return cnt;
}
