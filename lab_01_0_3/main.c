#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    float high, chest_len, mass;
    float normal_weight, index_mass;
    printf("Input high, chest_len,mass: ");
    if (scanf("%f", &high) != 1 || scanf("%f", &chest_len) != 1 || scanf("%f", &mass) != 1
        || (high <= 0) || (chest_len < 0) || (mass < 0)) 
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    normal_weight = high * chest_len / 240;
    high = high / 100;
    index_mass = mass / (high * high);
    printf("Normal weight = %f,Index mass = %f\n", normal_weight, index_mass);
    return EXIT_SUCCESS;
}