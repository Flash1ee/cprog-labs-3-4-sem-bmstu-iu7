#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error count of arguments != 2");
        return ARG_ERR;
    }

    FILE *f;
    f = fopen(argv[1], "r");
    double average = 0;
    double dispers = 0;
    double variance = 0; //корень из дисперсии
    int rc = OK;

    if (f)
    {
        rc = avg(f, &average);
        if (!rc)
        {
            fseek(f, 0, SEEK_SET);
            rc = disp(f, &average, &dispers);
            if (!rc)
            {
                variance = sqrt(dispers);
                fseek(f, 0, SEEK_SET);
                rc = check_three_sigma(f, variance, average);
                if (rc == SIGM_ERR)
                    fprintf(stderr, "SIGM_ERR\n");
            }
        }
        else
            fprintf(stderr, "AVG_ERR\n");
        fclose(f);
    }
    else
    {
        fprintf(stderr, "Failed open %s\n", argv[1]);
        rc = OPEN_ERR;
    }

    if (rc == OPEN_ERR || rc == ERROR_IN)
        return rc;

    if (rc == SIGM_ERR)
        printf("0");
    else
        printf("1");

    return OK;
}