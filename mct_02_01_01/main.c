#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 30
size_t get_digits(char str[]);
int main()
{
    char a[N];
    printf("%llu\n", get_digits(a));
    char b[] = "pascal";
    printf("%llu\n", get_digits(b));
    char c[] = "mama pa1pa c1+10+ babush2ka 9";
    printf("%llu\n", get_digits(c));
    char d[] = "123456789!";
    printf("%llu\n", get_digits(d));
    char e[] = "abddvahsbfjaf!";
    printf("%llu\n", get_digits(e));


    return EXIT_SUCCESS;
}

/*
Функция get_digits возвращает количество цифр в строке,
В случае пустрой строки - возвращает 0, 
Иначе - количество цифр
*/
size_t get_digits(char str[])
{
    size_t cnt = 0;
    size_t i = 0;
    
    while (str[i])
    {
        if (isdigit(str[i]))
            cnt++;
        i++;
    }

    return cnt;
}