#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    double high, chest_len, mass;
    double normal_weight, index_mass;
    scanf("%lf%lf%lf", &high, &chest_len, &mass);
    normal_weight = high * chest_len / 240;
    high = high / 100;
    index_mass = mass / (high * high);
    printf("Normal weight = %.5lf,Index mass = %.5lf\n", normal_weight, index_mass);
    return EXIT_SUCCESS;
}