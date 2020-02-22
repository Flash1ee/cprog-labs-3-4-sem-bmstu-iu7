#include <stdio.h>
#include <stdlib.h>
long int nod(long int a, long int b);
int main()
{
    long int a, b;
    if (scanf("%ld%ld", &a, &b)!= 2 || (a < 1) || (b < 1)) 
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    printf("%ld", nod(a, b));
    return EXIT_SUCCESS;
}

long int nod(long int a, long int b)
{
    if (a > b)
    {   
        if (a % b == 0)
            return b;
        return a % b;
    }
    else
    {   if (b % a == 0)
            return a;
        return b % a;
    }   
}