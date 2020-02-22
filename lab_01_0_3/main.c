#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout, NULL);
    double high, chest_len, mass;
    double normal_weight, index_mass;
    printf("Input high, chest_len,mass: ");
    if (scanf("%lf", &high) != 1 || scanf("%lf", &chest_len) != 1 || scanf("%lf", &mass) != 1
        || (high < 0) || (chest_len < 0) || (mass < 0)) {
        printf("Incorrect input");
        return EXIT_FAILURE;
    }
    normal_weight = high * chest_len / 240;
    index_mass = mass / (high / 100 * high / 100);
    printf("Normal weight = %.5lf,Index mass = %.5lf\n", normal_weight, index_mass);
    return EXIT_SUCCESS;
}