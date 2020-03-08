#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int input_pos_massiv(int *mas, int k,int *LenPos);
float get_pos_element_prod(int *mas, int k);
int main()
{
    int k, A[N],LenPosMas = 0;
    if (scanf("%d", &k)!= 1 || k > 10 || k <= 0)  
    {
        return EXIT_FAILURE;
    }
    if (input_pos_massiv(A,k,&LenPosMas)!=0)
        return EXIT_FAILURE;
    printf("%f",pow(get_pos_element_prod(A,k), 1.0 / (double) LenPosMas));
    return EXIT_SUCCESS;
}

int input_pos_massiv(int *mas,int k,int *LenPos)
{
    for (int i = 0;i<k;i++)
    {
        if (scanf("%d",&mas[i])!=1)
            return EXIT_FAILURE;
        if (mas[i] > 0)
            *LenPos +=1;
    }
    if (!*LenPos)   
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
float get_pos_element_prod(int *mas, int k)
{
    float prod = 1.0;
    for (int i=0;i<k;i++)
    {
        if (mas[i]>0)
            prod*=mas[i];
    }
    return prod;
}

