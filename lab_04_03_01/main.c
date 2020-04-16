#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 80
char *my_strchr(char *str, int symbol);
//Если не символа в строке нет => возвращает NULL
int main()
{
    /*
    char str[MAX_STR+1];
    char elem;
    char *my_ptr, *func_ptr;
    fgets(str, MAX_STR,stdin);
    elem = getchar();
    func_ptr = strchr(str, (int)elem);
    my_ptr = my_strchr(str,(int)elem);
    printf("%d", func_ptr==my_ptr);
    */
    char a[1];
    char b[6] = "hello";
    printf("%p\n",b);
    printf("%s\n",b);
    printf("addres a %p\n",a);
    strcpy(a,"1234567");
    printf("%p\n",a);
    printf("%s\n",a);
    printf("%p\n",b);
    printf("%s\n",b);


    return EXIT_SUCCESS;
}
/*
char *my_strchr(char *str, int symbol)
{
    char *ptr;
    for (char *ptr = str; *ptr > '\0'; ptr++)
        if ((int)*ptr == symbol) return ptr;
    return symbol == (int)*ptr;
}
*/