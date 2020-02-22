#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    double up, down, h;
    double perimetr, rightsize;
    printf("Input upsize,downsize,h:\n");
    if (scanf("%lf", &up) != 1 || scanf("%lf", &down) != 1 || scanf("%lf", &h) != 1 || (h < 0)
        || (down < 0) || (up < 0) || (down < up))
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    rightsize = h * h + (up - down) * (up - down) / 4;
    perimetr = up + down + sqrt(rightsize) * 2;
    printf("Perimetr of figure = %.5lf\n", perimetr);
    return EXIT_SUCCESS;
}
