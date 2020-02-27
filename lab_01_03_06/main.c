/*Определить взаимное расположение точки и прямой: лежит выше прямой, на прямой, под
прямой.*/

#include <stdio.h>
#include <stdlib.h>

long int vector_prod(long int ax, long int ay, long int bx, long int by);
void print_result(long int res);

int main(void)
{
    setbuf(stdout, NULL);
    long int x1, y1, x2, y2, xpoint, ypoint, result;
    printf("Input coords x1 y1 x2 y2 of line ");
    printf("and coords point for check xA yA:\n");
    if ((scanf("%ld%ld%ld%ld", &x1, &y1, &x2, &y2) != 4) || scanf("%ld%ld", &xpoint, &ypoint) != 2
        || ((x1 == x2) && (y1 == y2)))
    {
        printf("Invalid input\n");
        return EXIT_FAILURE;
    }
    if (x2 < x1)
    {
        long int tmp_x, tmp_y;
        tmp_x = x1;
        tmp_y = y1;
        x1 = x2;
        y1 = y2;
        x2 = tmp_x;
        y2 = tmp_y;
    }
    result = vector_prod(x2 - x1, y2 - y1, xpoint - x1, ypoint - y1);
    print_result(result);
    return EXIT_SUCCESS;
}

long int vector_prod(long int ax, long int ay, long int bx, long int by)
{
    long int s;
    s = (ax * by - bx * ay);
    return s;
}

void print_result(long int result)
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