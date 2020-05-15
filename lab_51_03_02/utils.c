#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"


int avg(FILE *f, double *average)
{
    size_t n = 0;
    double x;
    double sum = 0;
    if (fscanf(f, "%lf", &x) == 1)
    {
        sum += x;
        n += 1;
        while (fscanf(f, "%lf", &x) == 1)
        {
            sum += x;
            n += 1;
        }
        *average = sum / n;
        // printf("avg = %lf\n", *average);
        return OK;
    }
    else
        return ERROR_IN;
}

int disp(FILE *f, double *average, double *dispersion)
{
    size_t n = 0;
    double sum = 0;
    double x;
    if (fscanf(f, "%lf", &x) == 1)
    {
        sum += (x - *average) * (x - *average);
        n += 1;
        while (fscanf(f, "%lf", &x) == 1)
        {
            sum += (x - *average) * (x - *average);
            n += 1;
        }
        *dispersion = sum / n;
        // printf("disp = %lf\n", *dispersion);
        return OK;
    }
    else
        return ERROR_IN;
}

int check_three_sigma(FILE *f, double variance, double average)
{
    double x;
    double eps = 1e-6;
    size_t p_in, p_out;
    p_in = p_out = 0;
    int flag;
    double left = average - 3 * variance;
    double right = average + 3 * variance;

    if (2 * right - 2 * left < eps)
        return NO_INTERVAL;
    if (fscanf(f, "%lf", &x) == 1)
    {
        flag = ((x >= 0) && (x - right > eps)) || ((x < 0) && ((left - x > eps)));
        if (flag)
            p_out++;
        else
            p_in++;
        // printf("x = %lf, avg = %lf, variance = %lf PASSED\n", x, average, variance);
        while (fscanf(f, "%lf", &x) == 1)
        {
            // printf("x = %lf, avg = %lf, variance = %lf PASSED\n", x, average, variance);
            flag = ((x >= 0) && (x - right >= eps)) || ((x < 0) && (left - x >= eps));
            if (flag)
                p_out++;
            else
                p_in++;
        }
        // printf("p_in = %zu, p_out = %zu\n", p_in, p_out);
        if (fabs((double)p_in / (p_out + p_in) - THREE_SIGM_EPS) < eps)
            return SIGM_ERR;
        return OK;
    }
    return ERROR_IN;
}
