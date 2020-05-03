#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    
    double up_side, down_side, h;
    double perimeter, lateral_side;
    
    printf("Input up_side, down_side, h:\n");
    if (scanf("%lf", &up_side) != 1 || scanf("%lf", &down_side) != 1 || scanf("%lf", &h) != 1)
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    else if ((h < 0) || (down_side < 0) || (up_side < 0))
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    lateral_side = h * h + (up_side - down_side) * (up_side - down_side) / 4.;
    perimetr = up_side + down_side + sqrt(lateral_side) * 2;
    
    printf("Perimetr of figure = %.5lf\n", perimetr);
    
    return EXIT_SUCCESS;
}
