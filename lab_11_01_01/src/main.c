#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "my_snprintf.h"

int main()
{
    char temp[100] = {0};
    char temp_res[100] = {0};
    char a = 'A';
    char b = '1';
    char c = '2';

    int int_a = 2020;
    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "My Friend!";
    size_t len = strlen(str1) + strlen(str2) + strlen(str3);

    int n = my_snprintf(temp, len + 1 + 16, "Hello %s%s My Friend%s", str1, str2, str3);
    printf("%d\n%s\n", n, temp);
    // memset(temp, 0, strlen(temp));

    n = snprintf(temp_res, len + 1 + 16, "Hello %s%s My Friend%s", str1, str2, str3);
    printf("%d\n%s\n", n, temp_res);
    // memset(temp_res, 0, strlen(temp));

    n = my_snprintf(temp, len + 1, "%s%s%s", str1, str2, str3);
    printf("%d\n%s\n", n, temp);
    // memset(temp, 0, strlen(temp));

    n = snprintf(temp_res, len + 1, "%s%s%s", str1, str2, str3);
    printf("%d\n%s\n", n, temp_res);
    // memset(temp_res, 0, strlen(temp));

    n = my_snprintf(temp, 7 + 1, "D%d%cD", int_a, a);
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, 7 + 1, "D%d%cD", int_a, a);
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    long max = LONG_MAX;
    long min = LONG_MIN;
    char buf[LONG_MAX_M + 1] = {0};
    sprintf(buf, "%ld", max);

    n = my_snprintf(temp, strlen(buf) * 2 + 1 + 1, "%ld%ld", max, min);
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, strlen(buf) * 2 + 1 + 1, "%ld%ld", max, min);
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    n = my_snprintf(temp, 12 + 1, "%d%d%d", int_a, int_a, int_a);
    printf("%d\n%s\n", n, temp);
    // memset(temp, 0, 100);

    n = snprintf(temp_res, 12 + 1, "%d%d%d", int_a, int_a, int_a);
    printf("%d\n%s\n", n, temp_res);
    // memset(temp_res, 0, 100);

    n = my_snprintf(temp, 20 + 1, "mama%d%d%dpapa", int_a, int_a, int_a);
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, 20 + 1, "mama%d%d%dpapa", int_a, int_a, int_a);
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    n = my_snprintf(temp, 4 + 1, "maa");
    printf("%d\n%c%c%c\n", n, temp[0], temp[1], temp[2]);
    // *temp = '\0';

    n = snprintf(temp_res, 4 + 1, "maa");
    printf("%d\n%c%c%c\n", n, temp_res[0], temp_res[1], temp_res[2]);
    // *temp_res = '\0';

    n = my_snprintf(temp, 1, "%t   ", 'W');
    printf("%d\n%s\n", n, temp);

    n = snprintf(temp_res, 1, "%t", 'W');
    printf("%d\n%s\n", n, temp_res);



    n = my_snprintf(temp, sizeof(char) + 3, "%c%c%c", a, b, c);
    printf("%d\n%c%c%c\n", n, temp[0], temp[1], temp[2]);
    // *temp = '\0';

    n = snprintf(temp_res, sizeof(char) + 3, "%c%c%c", a, b, c);
    printf("%d\n%c%c%c\n", n, temp_res[0], temp_res[1], temp_res[2]);
    // *temp_res = '\0';

    n = my_snprintf(temp, sizeof(char) + 1, "%c", a);
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, sizeof(char) + 1, "%c", a);
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    n = my_snprintf(temp, sizeof(char) + 7, "%cmama%c\n", a, b);
    printf("%d\n%s", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, sizeof(char) + 7, "%cmama%c\n", a, b);
    printf("%d\n%s", n, temp_res);
    // *temp_res = '\0';

    n = my_snprintf(temp, 0, "pff");
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, 0, "pff");
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    n = my_snprintf(temp, 0, "");
    printf("%d\n%s\n", n, temp);
    // *temp = '\0';

    n = snprintf(temp_res, 0, "");
    printf("%d\n%s\n", n, temp_res);
    // *temp_res = '\0';

    // // n = my_snprintf(temp, sizeof(char) + 1, "op", c);

    // n = snprintf(temp, sizeof(char), "op%c", c);

    // printf("%s\n", temp);

    return EXIT_SUCCESS;
}