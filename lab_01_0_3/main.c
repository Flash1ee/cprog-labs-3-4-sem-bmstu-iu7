#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    setbuf(stdout,NULL);
    double h,circle_len,m;
    double normal_weight,index_mass;
    printf("Input h, circle_len,m: ");
    if (scanf("%lf",&h)!=1||scanf("%lf",&circle_len)!=1||scanf("%lf",&m)!=1||(h<0)||(circle_len<0)||(m<0)) { 
        printf("Incorrect input");
        return EXIT_FAILURE;
    }
    normal_weight = h*circle_len/240;
    index_mass = m/(h/100*h/100);
    printf("Normal weight = %.5lf,Index mass = %.5lf\n",normal_weight,index_mass);
    return EXIT_SUCCESS;
}