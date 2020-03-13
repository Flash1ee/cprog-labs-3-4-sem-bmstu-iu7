#include <stdio.h>
#include <stdlib.h>

long int dot_product(long ax, long ay, long bx, long by);
void print_result(long res);

int main(void)
{
    setbuf(stdout, NULL);
    long x1, y1;
    long x2, y2;
    long xpoint, ypoint, result;
    printf("Input coords x1 y1 x2 y2 of line ");
    printf("and coords point for check xA yA:\n");
    if ((scanf("%ld%ld%ld%ld", &x1, &y1, &x2, &y2) != 4) || ((x1 == x2) && (y1 == y2)))
    {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }
    else if (scanf("%ld%ld", &xpoint, &ypoint) != 2)
    {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }
    if (x2 < x1)
    {
        long tmp_x, tmp_y;
        tmp_x = x1;
        tmp_y = y1;
        x1 = x2;
        y1 = y2;
        x2 = tmp_x;
        y2 = tmp_y;
    }
    result = dot_product(x2 - x1, y2 - y1, xpoint - x1, ypoint - y1);
    print_result(result);
    return EXIT_SUCCESS;
}

long int dot_product(long ax, long ay, long bx, long by)
{
    long s;
    s = (ax * by - bx * ay);
    return s;
}

void print_result(long result)
{
    if (result > 0)
    {
        printf("Upper line => %d", 0);
    }
    else if (result == 0)
    {
        printf("On line => %d", 1);
    }
    else
    {
        printf("Down of line => %d", 2);
    }
}