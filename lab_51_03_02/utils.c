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
        return OK;
    }
    else
        return ERROR_IN;
}

int check_three_sigma(FILE *f, double variance, double average)
{
    double x;
    double eps = 0.000001;
    size_t p_in, p_out;
    p_in = p_out = 0;
    int flag;
    double left = average - 3 * variance;
    double right = average + 3 * variance;

    if (fscanf(f, "%lf", &x) == 1)
    {
        flag = ((x >= right) && (x <= left));
        if (flag)
            p_out++;
        else
            p_in++;
        while (fscanf(f, "%lf", &x) == 1)
        {
            flag = ((x >= right) && (x <= left));
            if (flag)
                p_out++;
            else
                p_in++;
        }
        if ((double)p_in / (p_out + p_in) >= THREE_SIGM_EPS)
            return SIGM_ERR;
        return OK;
    }
    return ERROR_IN;
}
