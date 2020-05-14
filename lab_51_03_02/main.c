#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include "utils.h"
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr,"Error count of arguments != 2");
        return ARG_ERR;
    }

    FILE *f;
    f = fopen(argv[1], "r");
    double average = 0;
    double disp = 0;
    double variance = 0; //корень из дисперсии
    int rc = OK;

    if (f)
    {
        if (!get_avg(f, &average))
        {
            fseek(f, 0, SEEK_SET);
            if (!get_disp(f, &average, &disp))
            {
                variance = sqrt(disp);
                fseek(f, 0, SEEK_SET);
                rc = check_three_sigma(f, variance, average);
                if (rc)
                    fprintf(stderr, "SIGM_ERR\n");
            }
            else
            {
                rc = DISP_ERR;
                fprintf(stderr, "AVG_ERR\n");
            }
        }  
        else
        {
            rc =  AVG_ERR;
            fprintf(stderr, "AVG_ERR\n");
        }
        fclose(f);
    }
    else
    {
        fprintf(stderr, "Failed open %s", argv[1]);
        rc = OPEN_ERR;
    }
    if (rc)
        printf("0");
    else 
        printf("1");
    return rc;
}