#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <string.h>
#define SIZE 16
int create_bin_file(FILE *f, FILE *in)
{
    int num;
    if (fscanf(in, "%d", &num) == 1)
    {
        fwrite(&num, sizeof(int), 1, f);
        while (fscanf(in, "%d", &num) == 1)
            fwrite(&num, sizeof(int), 1, f);
        if (feof(f))
            return 0;
        return 1;
    }
    return 1;
}


int main(int argc, char *argv[])
{
    FILE *f;
    FILE *in;
    int rc;
    char txt[SIZE];
    char bin[SIZE];
    strcpy(txt, argv[1]);
    strcpy(bin, argv[2]);
    in = fopen(txt, "r");
    f = fopen(bin, "wb");
    if (f == NULL || in == NULL)
    {
        printf("I/O error\n");
        printf("%s", txt);
        return -1;
    }

    rc = create_bin_file(f, in);
    fclose(f);
    fclose(in);
    return rc;
}