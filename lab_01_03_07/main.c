#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    setbuf(stdout,NULL);
    
    double x, eps, cur_x;
    long k = 0;
    double sum = 0, func_res, abs_diff, relative_diff;
    
    printf("Input x, eps\n");

    if (scanf("%lf%lf", &x, &eps) != 2 || eps <= 0 || (x >= 1) || (x <= -1))
    {
        printf("Incorrect input\n");
        return EXIT_FAILURE;
    }

    cur_x = x;
    while (fabs(cur_x) > eps)
    {
        k = k + 1;
        sum = sum + cur_x;
        cur_x = cur_x * (-1) * (x * x) * (2 * k - 1) / (2 * k + 1);
    }
    
    
    func_res = atan(x);
    abs_diff = fabs(func_res - sum);
    if (func_res <= eps && sum <= eps)
        relative_diff = 0;
    else
        relative_diff = fabs((func_res - sum) / func_res);
        
    printf("Sum of row with eps = %.6lf\n", sum);
    printf("Absolute diff = %.6lf\n", abs_diff);
    printf("Relative diff = %.6lf\n", relative_diff);

    return EXIT_SUCCESS;
}
