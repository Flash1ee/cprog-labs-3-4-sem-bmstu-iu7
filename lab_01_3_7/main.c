/*Вычислить с точность eps:
− приближенное значение функции s(x);
− точное значение функции f(x);
− абсолютную f(x) -s(x) и относительную (f(x) -s(x)) / f(x) ошибки приближенного
значения.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double x, eps, cur_x;
    long int k = 0;
    double sum = 0, func_res, abs_error, relative_error;

    if (scanf("%lf%lf", &x, &eps) != 2 || eps <= 0 || (x > 1) || (x < -1) || (x == 0))
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
    abs_error = fabs(func_res - sum);
    relative_error = fabs((func_res - sum) / func_res);

    printf("Sum of row with eps {%lf} = %lf\n", eps, sum);
    printf("Absolute error = %lf\nRelative error = %lf\n", abs_error, relative_error);

    return EXIT_SUCCESS;
}
