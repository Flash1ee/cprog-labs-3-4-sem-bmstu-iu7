#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    double high, chest_len, mass;
    double normal_weight, index_mass;
    printf("Input high, chest_len,mass: ");
    if (scanf("%lf", &high) != 1 || scanf("%lf", &chest_len) != 1 || scanf("%lf", &mass) != 1) 
    {
        printf("Incorrect input");
        return EXIT_FAILURE;
    }
    normal_weight = high * chest_len / 240;
    high = high / 100;
    index_mass = mass / (high * high);
    printf("Normal weight = %.5lf,Index mass = %.5lf\n", normal_weight, index_mass);
    return EXIT_SUCCESS;
}