#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    double high, chest_len, mass;
    double normal_weight, index_mass;
    printf("Input high, chest_len,mass: ");
    if (scanf("%lf", &high) != 1 || scanf("%lf", &chest_len) != 1 || scanf("%lf", &mass) != 1
        || (high <= 0) || (chest_len < 0) || (mass < 0)) 
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    normal_weight = high * chest_len / 240;
    high = high / 100;
    index_mass = mass / (high * high);
    printf("Normal weight = %lf,Index mass = %lf\n", normal_weight, index_mass);
    return EXIT_SUCCESS;
}