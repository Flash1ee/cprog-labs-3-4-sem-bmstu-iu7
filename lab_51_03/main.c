#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <time.h>
int main(int argc, char *argv[])
{

    if (argc != 4 && argc != 3)
        return ARG_ERR;

    char mode = argv[1][0];

    if (mode != 'c' && mode != 'p' && mode != 's')
        return MODE_ERR;

    size_t cnt;
    int rc;
    
    if (argc == 4)
    {
        if (!(cnt = strtol(argv[2],NULL, 10)))
            return ERR_CNT;
        
        FILE *f;
        f = fopen(argv[3], "w");

        if (write_rand(f, cnt))
        {
            fclose(f);
            return WRITE_ERR;
        }
        else
            fclose(f);
    }
    else 
    {
        if (mode == 'p')
        {
            size_t size;
            FILE *f;
            f = fopen(argv[2], "r");
            
            if (file_size(f, &size))
            {
                fclose(f);
                return READ_ERR;
            }
            rc = print(f, size);
            if (rc)
            {
                fclose(f);
                return rc;
            }
            fclose(f);
        }    
    }

    return OK;
}

int write_rand(FILE *f, size_t cnt)
{
    srand(time(NULL));
    int buf;
    for (size_t i = 0; i < cnt; i++)
    {
        buf = (rand() % DIGITS * 2 ) - DIGITS;
        if (fwrite(&buf, sizeof(int), 1, f) != 1)
            return WRITE_ERR;
    }
    return OK;
}

int print(FILE *f, size_t size)
{
    printf("%zu\n", size);
    if (!size)
        return SIZE_ERR;
    int num;
    int rc;
    for (size_t i = 0; i < size / sizeof(int); i++)
    {
        rc = fread(&num, sizeof(int), 1, f);
        if (rc == 1)
            printf("%d ", num);
        else
            return READ_ERR;
    }
    return OK;
}


int file_size(FILE *f , size_t *size)
{
    long tmp;
    if (fseek(f, 0, SEEK_END))
        return READ_ERR;
    tmp = ftell(f);
    if (tmp < 0)
        return READ_ERR;
    *size = tmp;
    fseek(f, 0, SEEK_SET);
    return OK;
}
