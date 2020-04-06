#include <stdio.h>
#include <stdlib.h>

#define PRICE_BUY 45
#define PRICE_SELL 20

int main()
{
    setbuf(stdout, NULL);
    
    long s, k;
    k = 0;
    
    printf("Input counts of money:\n");
    if ((scanf("%ld", &s) != 1) || (s < 0)) 
    {
        printf("Incorrect data\n");
        return EXIT_FAILURE;
    }
    while (s >= PRICE_BUY) 
    {
        s = s - PRICE_BUY;
        k += 1;
        s = s + PRICE_SELL;
    }
    printf("Count of bottles with water %ld\n", k);
    
    return EXIT_SUCCESS;
}