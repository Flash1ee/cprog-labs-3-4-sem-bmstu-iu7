#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR_IN -1
#define EMPTY_IO -2
#define ARG_ERR -3
#define OPEN_ERR -4
#define AVG_ERR -5
#define DISP_ERR -6
#define SIGM_ERR -7
#define NO_INTERVAL -8

#define THREE_SIGM_EPS 0.9973

int get_avg(FILE *f, double *average);
int get_disp(FILE *f, double *average, double *dispersion);
int check_three_sigma(FILE *f, double variance, double average);


#endif //_UTILS_H