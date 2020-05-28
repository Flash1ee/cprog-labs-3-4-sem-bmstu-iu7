#include <stdio.h>
#include <stdlib.h>

int main()
{
    setbuf(stdout, NULL);
    
    double high, chest_girth, mass;
    double normal_weight, index_mass;
    
    printf("Input high, chest_girth,mass: ");
    if (scanf("%lf", &high) != 1 || scanf("%lf", &chest_girth) != 1 || (high <= 0))
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    if (scanf("%lf", &mass) != 1 || (chest_girth < 0) || (mass < 0)) 
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    normal_weight = high * chest_girth / 240.;
    high = high / 100.;
    index_mass = mass / (high * high);
    
    printf("Normal weight = %.5lf\n", normal_weight);
    printf("Index mass = %.5lf", index_mass);
    
    return EXIT_SUCCESS;
}
