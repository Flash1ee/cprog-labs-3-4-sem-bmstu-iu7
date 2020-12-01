#include <stdio.h>
#include <stdlib.h>

#include "my_snprintf.h"

int main()
{
    char temp[100] = {0};
    char a = '0';
    char b = '1';
    char c = '2';
    char d = '3';


    int n = my_snprintf(temp, sizeof(char) + 3, "%c%c%c", a,b,c);
    printf("%d\n%c%c%c\n", n, temp[0],temp[1],temp[2]);

    // // n = my_snprintf(temp, sizeof(char) + 1, "op", c);

    // n = snprintf(temp, sizeof(char), "op%c", c);

    // printf("%s\n", temp);

    return EXIT_SUCCESS;
}