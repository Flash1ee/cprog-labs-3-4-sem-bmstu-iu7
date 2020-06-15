#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#define N 30

#define NAME 15

#define READ_ERR 1
#define OPEN_ERR 2
#define WRITE_ERR 3
#define BEATEN_FILE 4
#define SIZE_ERR 5

struct student
{
    char name[NAME + 1];
    uint32_t years;
    uint32_t enter;
};

int file_size(FILE *in, size_t *size);
int bubble_sort(long long a[], size_t n);
int get(FILE *in, size_t pos, size_t size, struct student *s1, struct student *s2);
int write_struct(FILE *in);
int put(FILE *in, size_t pos, size_t size, struct student *s1, struct student *s2);
int sort(FILE *in);
int print(FILE *in, size_t *size);


int main(int argc, char **argv)
{
    if (argc != 3)
        return EXIT_FAILURE;
    FILE *in;
    char mode[3];
    strncpy(mode, argv[1], 2);
    mode[2] = '\0';
    size_t size = 0;
    if (!strcmp("do", mode))
    {

        in = fopen(argv[2], "ab+");
        if (!in)
            return READ_ERR;
        if (write_struct(in))
        {
            fclose(in);
            return WRITE_ERR;
        }
        fclose(in);
    }
    else if (!strcmp("m", mode))
    {
        in = fopen(argv[2], "rb+");
        int rc = sort(in);
        fclose(in);
        return rc;
    }
    else if (!strcmp(mode, "pr"))
        {
            in = fopen(argv[2], "rb");
            if (!in)
                return READ_ERR;
            if (print(in, &size))
            {
                fclose(in);
                return EXIT_FAILURE;
            }
        }

    return EXIT_SUCCESS;
}




int sort(FILE *in)
{
    //Файл открыт в режиме rb+
    if (in == NULL)
        return OPEN_ERR;
    size_t size;

    if (file_size(in, &size) || size < 1)
        return SIZE_ERR;

    if (size % sizeof(struct student))
        return BEATEN_FILE;
        
    size = size / sizeof(struct student);

    struct student s1;
    struct student s2;

    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (get(in, j, sizeof(struct student), &s1, &s2))
                return READ_ERR;
            if (s1.enter > s2.enter)
                if (put(in, j, sizeof(struct student), &s2, &s1))
                    return WRITE_ERR;
        }
    return EXIT_SUCCESS;
}



int bubble_sort(long long a[], size_t n)
{
    long long tmp;
    if (a == NULL)
        return EXIT_FAILURE;
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - i - 1;j++)
            if (a[j] > a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    return EXIT_SUCCESS;
}

int file_size(FILE *in, size_t *size)
{
    long tmp;
    if (fseek(in, 0, SEEK_END))
        return READ_ERR;
    tmp = ftell(in);
    if (tmp < 0)
        return READ_ERR;
    *size = tmp;
    fseek(in, 0, SEEK_SET);
    return EXIT_SUCCESS;
}
int get(FILE *in, size_t pos, size_t size, struct student *s1, struct student *s2)
{
    if (fseek(in, pos * size, SEEK_SET))
        return READ_ERR;

    if (fread(s1, size, 1, in) != 1)
        return READ_ERR;
    if (fread(s2, size, 1, in) != 1)
        return READ_ERR;

    if (fseek(in, 0, SEEK_SET))
        return READ_ERR;
    return EXIT_SUCCESS;
}
int put(FILE *in, size_t pos, size_t size, struct student *s1, struct student *s2)
{
    if (fseek(in, pos * size, SEEK_SET))
        return READ_ERR;

    if (fwrite(s1, size, 1, in) != 1)
        return READ_ERR;

    if (fwrite(s2, size, 1, in) != 1)
        return READ_ERR;

    if (fseek(in, 0, SEEK_SET))
        return READ_ERR;
    return EXIT_SUCCESS;
}
int write_struct(FILE *in)
{
    struct student s1;
    if (scanf("%s", s1.name) != 1)
        return READ_ERR;
    if (scanf("%u", &s1.years) != 1 || scanf("%u", &s1.enter) != 1)
        return READ_ERR;
    if (fwrite(&s1, sizeof(struct student), 1, in) != 1)
        return WRITE_ERR;
    return EXIT_SUCCESS;
}

int print(FILE *in, size_t *size)
{
    if (file_size(in, size))
        return SIZE_ERR;
    if (!(*size))
        return SIZE_ERR;
    if (*size % sizeof(struct student))
        return BEATEN_FILE;

    struct student s1;
    int rc;
    for (size_t i = 0; i < *size / sizeof(struct student); i++)
    {
        rc = fread(&s1, sizeof(struct student), 1, in);
        if (rc == 1)
            printf("%s\n%u\n%u\n", s1.name, s1.years, s1.enter);
        else
            return READ_ERR;
    }
    return EXIT_SUCCESS;
}
