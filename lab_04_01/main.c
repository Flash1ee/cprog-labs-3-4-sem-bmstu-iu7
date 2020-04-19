#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
void func_strchr(const char *str, int el);
//Если не символа в строке нет => возвращает NULL
int main()
{
    const char *temp = " ,.!";
    const char *symbols = "abcde";
    const char *test1 = "$Unclea Sasha!";
    const char *test2 = "aMoscow?";
    const char *test3 = "";
    const char *test4 = "00 0";
    const char *test5 = "aa,a";
    const char *test6 = "123456789";
    func_strchr(test1,'S');
    func_strchr(test2, '\0');
    func_strchr(test3, '\0');
    func_strchr(test4, '1');
    func_strchr(test5, 'A');
    func_strchr(test6, '0');
    printf("%d\n", strpbrk(test1,temp)==my_strpbrk(test1,temp));
    printf("%d\n", strpbrk(test2,temp)==my_strpbrk(test2,temp));
    printf("%d\n", strpbrk(test3,temp)==my_strpbrk(test3,temp));
    printf("%d\n", strpbrk(test4,temp)==my_strpbrk(test4,temp));
    printf("%d\n", strpbrk(test5,temp)==my_strpbrk(test5,temp));
    printf("%d\n", strpbrk(test6,temp)==my_strpbrk(test6,temp));

    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));
    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));
    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));
    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));
    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));
    printf("%d\n", strspn(test6,temp)==my_strspn(test6,temp));

    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));
    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));
    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));
    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));
    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));
    printf("%d\n", strspn(test6,symbols)==my_strspn(test6,symbols));

    printf("%d\n", strcspn(test1,temp)==my_strcspn(test1,temp));
    printf("%d\n", strcspn(test2,temp)==my_strcspn(test2,temp));
    printf("%d\n", strcspn(test3,temp)==my_strcspn(test3,temp));
    printf("%d\n", strcspn(test4,temp)==my_strcspn(test4,temp));
    printf("%d\n", strcspn(test5,temp)==my_strcspn(test5,temp));
    printf("%lld %lld\n",strcspn(test5,temp),my_strcspn(test5,temp));
    printf("%d\n", strcspn(test6,temp)==my_strcspn(test6,temp));

    printf("%d\n", strrchr(test1,'a')==my_strrchr(test1,'a'));
    printf("%d\n", strrchr(test2,'o')==my_strrchr(test2,'o'));
    printf("%d\n", strrchr(test3,' ')==my_strrchr(test3,' '));
    printf("%d\n", strrchr(test4,'0')==my_strrchr(test4,'0'));
    printf("%d\n", strrchr(test5,'b')==my_strrchr(test5,'b'));
    printf("%d\n", strrchr(test6,'0')==my_strrchr(test6,'0'));


    

    

    return EXIT_SUCCESS;
}

void func_strchr(const char *str, int el)
{
    if (my_strchr(str, el) == strchr(str,el))
        printf("TEST PASSED\n");
    else printf("TEST FAILED\n");

}