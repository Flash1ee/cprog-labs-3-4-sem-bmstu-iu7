#include <stdio.h>
#include <stdlib.h>

long gcd(long a, long b);

int main()
{
    setbuf(stdout, NULL);
    
    long a, b, x;
    
    printf("Input two numbers:\n");
    if (scanf("%ld%ld", &a, &b) != 2 || (a < 1) || (b < 1)) 
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }
    x = gcd(a, b);
    printf("NOD of two numbers is %ld", x);
    
    return EXIT_SUCCESS;
}

long gcd(long a, long b)
{
    long tmp;
    if (a < b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    while (a % b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return b;
}