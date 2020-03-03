/*Определить нормальный вес человека и индекс массы его тела по формулам: h * t / 240 и
m / h2, где h – рост человека (измеряемый в сантиметрах в первой формуле и в метрах – во
второй); t – длина окружности грудной клетки (в сантиметрах); m – вес (в килограммах).*/
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
    normal_weight = high * chest_len / 240.;
    high = high / 100.;
    index_mass = mass / (high * high);
    printf("Normal weight = %.5lf\n", normal_weight);
    printf("Index mass = %.5lf", index_mass);
    return EXIT_SUCCESS;
}
