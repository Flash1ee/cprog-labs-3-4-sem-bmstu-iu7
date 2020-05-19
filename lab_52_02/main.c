#define __USE_MINGW_ANSI_STDIO 1
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NAME 30
#define MAKER 15
#define ARG_ERR 53
#define ERROR_IN 1
#define SEARCH_ERR 2
#define OPEN_ERR 3
#define WRITE_ERR 4
#define MODE_ERR 5
#define COPY_ERR 6
#define READ_ERR 7
#define SIZE_ERR 8
#define SORT_ERR 9
#define BEATEN_FILE 10

struct product
{
    char name[NAME + 1];
    char manufacture[MAKER + 1];
    uint32_t price;
    uint32_t count;
};

int sort(FILE *in, size_t size, struct product *s1, struct product *s2);
int file_size(FILE *in, size_t *size);
int get_struct(FILE *in, size_t pos, size_t size, struct product *s1);
int put_struct(FILE *in, size_t pos, size_t size, struct product *var);
int search_struct(FILE *in, const char *value);
int file_copy(FILE *src, FILE *dst);
int insert(FILE *in, size_t size);
int struct_shift(FILE *in, size_t st, size_t end);
int add_struct(FILE *in);
int print(FILE *f, size_t size);

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    if (argc != 3 && argc != 4)
        return ARG_ERR;

    char mode[3];
    strncpy(mode, argv[1], 2);
    mode[2] = '\0';
    size_t size = 0;
    int rc = 0;
    if (argc == 4)
    {
        if (mode[0] == 's' && mode[1] == 'b')
        {
            FILE *in;
            FILE *out;
            in = fopen(argv[2], "rb+");
            out = fopen(argv[3], "wb");
            if (!in || !out)
                return OPEN_ERR;
            if (file_size(in, &size) || size < 1)
            {
                fclose(in);
                fclose(out);
                return SIZE_ERR;
            }
            if (size % sizeof(struct product))
            {
                fclose(in);
                fclose(out);
                return BEATEN_FILE;
            }
            size = size / sizeof(struct product);
            struct product s1, s2;

            rc = sort(in, size, &s1, &s2);
            if (rc)
            {
                fclose(in);
                fclose(out);
                return rc;
            }

            if (file_copy(in, out))
            {
                fclose(in);
                fclose(out);
                return COPY_ERR;
            }
            fclose(in);
            fclose(out);
            return EXIT_SUCCESS;
        }
        else if (mode[0] == 'f' && mode[1] == 'b')
        {
            const char *end = argv[3];
            FILE *in;
            in = fopen(argv[2], "rb");
            if (!in)
                return OPEN_ERR;
            if (file_size(in, &size) || size < 1)
            {
                fclose(in);
                return SIZE_ERR;
            }
            if (size % sizeof(struct product))
            {
                fclose(in);
                return BEATEN_FILE;
            }
            size = size / sizeof(struct product);
            rc = search_struct(in, end);
            if (rc)
            {
                fclose(in);
                return rc;
            }
            fclose(in);
            return EXIT_SUCCESS;
        }
        else
            return ARG_ERR;
    }
    else if (argc == 3)
    {
        if (mode[0] == 'd' && mode[1] == 'o')
        {
            FILE *in;
            struct product s1;
            in = fopen(argv[2], "ab+");
            if (!in)
                return READ_ERR;
            if (!fgets(s1.manufacture, MAKER + 1, stdin) || !fgets(s1.name, NAME + 1, stdin))
            {
                fclose(in);
                return READ_ERR;
            }
            if (scanf("%u%u", &s1.price, &s1.count) != 2)
            {
                printf("ERROR-INPUT-STRUCT");
                fclose(in);
                return READ_ERR;
            }
            if (fwrite(&s1, sizeof(struct product), 1, in) != 1)
            {
                printf("ADD_STRUCT_ERROR");
                fclose(in);
                return WRITE_ERR;
            }
            fclose(in);
            return EXIT_SUCCESS;
        }
        else if (mode[0] == 'p' && mode[1] == 'r')
        {
            FILE *in;
            size_t size = 0;
            in = fopen(argv[2], "rb+");
            if (file_size(in, &size))
            {
                fclose(in);
                return SIZE_ERR;
            }
            if (size % sizeof(struct product))
                return BEATEN_FILE;

            if (print(in, size))
            {
                fclose(in);
                return READ_ERR;
            }
            fclose(in);
            return EXIT_SUCCESS;
        }
        else if (mode[0] == 'a' && mode[1] == 'b')
        {
            FILE *in;
            in = fopen(argv[2], "rb+");
            if (!in)
                return READ_ERR;
            if (file_size(in, &size) || size < 1)
                return SIZE_ERR;
            size = size / sizeof(struct product);

            if (insert(in, size))
            {
                fclose(in);
                printf("INSERT-ERR");
                return WRITE_ERR;
            }
        }
        else
            return ARG_ERR;
    }

    return EXIT_SUCCESS;
}
int sort(FILE *in, size_t size, struct product *s1, struct product *s2)
{
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (get_struct(in, j, sizeof(struct product), s1)
                || get_struct(in, j + 1, sizeof(struct product), s2))
            {
                printf("GET_ERR");
                return READ_ERR;
            }
            if (s2->price > s1->price || (s2->price == s1->price && s2->count > s1->count))
            {
                if (put_struct(in, j, sizeof(struct product), s2)
                    || put_struct(in, j + 1, sizeof(struct product), s1))
                {
                    printf("PUT-ERR");
                    return READ_ERR;
                }
            }
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
int get_struct(FILE *in, size_t pos, size_t size, struct product *var)
{
    if (fseek(in, pos * size, SEEK_SET))
        return READ_ERR;
    if (fread(var, size, 1, in) != 1)
        return READ_ERR;
    if (fseek(in, 0, SEEK_SET))
        return READ_ERR;
    return EXIT_SUCCESS;
}
int put_struct(FILE *in, size_t pos, size_t size, struct product *var)
{
    if (fseek(in, pos * size, SEEK_SET))
        return READ_ERR;
    if (fwrite(var, size, 1, in) != 1)
        return READ_ERR;
    if (fseek(in, 0, SEEK_SET))
        return READ_ERR;
    return EXIT_SUCCESS;
}
int file_copy(FILE *src, FILE *dst)
{
    char tmp;
    if (fread(&tmp, sizeof(char), 1, src) == 1)
    {
        if (fwrite(&tmp, sizeof(char), 1, dst) != 1)
            return WRITE_ERR;
        while (fread(&tmp, sizeof(char), 1, src) == 1)
            if (fwrite(&tmp, sizeof(char), 1, dst) != 1)
                return WRITE_ERR;
        if (!feof(src))
            return READ_ERR;
        return EXIT_SUCCESS;
    }
    return READ_ERR;
}
int search_struct(FILE *in, const char *value)
{
    struct product s1;
    char *ptr;
    char tmp[NAME + 1];
    size_t len = strlen(value);
    if (fread(&s1, sizeof(struct product), 1, in) == 1)
    {
        ptr = strrchr(s1.name, value[0]);
        if (ptr)
        {
            strncpy(tmp, s1.name + (ptr - s1.name), NAME + 1);
            if (!strncmp(value, tmp, len))
                printf("%s%s%u\n%u\n", s1.name, s1.manufacture, s1.price, s1.count);
        }
        while (fread(&s1, sizeof(struct product), 1, in) == 1)
        {
            ptr = strrchr(s1.name, value[0]);
            if (ptr)
            {
                strcpy(tmp, s1.name + (ptr - s1.name));
                if (!strncmp(value, tmp, len))
                    printf("%s%s%u\n%u\n", s1.name, s1.manufacture, s1.price, s1.count);
            }
        }
        if (!feof(in))
            return READ_ERR;

        return EXIT_SUCCESS;
    }
    return READ_ERR;
}

int insert(FILE *in, size_t size)
{
    struct product s1;
    struct product s2;
    int flag = 0;

    if (!fgets(s1.manufacture, MAKER + 1, stdin) || !fgets(s1.name, NAME + 1, stdin))
    {
        printf("ERROR NAME");
        return READ_ERR;
    }
    if (scanf("%u%u", &s1.price, &s1.count) != 2)
    {
        printf("ERROR-INPUT-STRUCT");
        return READ_ERR;
    }


    for (size_t i = 0; i < size; i++)
    {
        if (get_struct(in, i, sizeof(struct product), &s2))
            return READ_ERR;
        if (s1.price > s2.price || (s1.price == s2.price && s1.count > s2.count))
        {
            flag = 1;
            if (struct_shift(in, i * sizeof(struct product), size * sizeof(struct product)))
            {
                printf("SHIFT-ERR");
                return WRITE_ERR;
            }
            if (fseek(in, i * sizeof(struct product), SEEK_SET)
                || (fwrite(&s1, sizeof(struct product), 1, in) != 1))
            {
                printf("ERR INSERT BEFORE STRUCTS IN FILE\n");
                return WRITE_ERR;
            }
            return EXIT_SUCCESS;
        }
    }
    if (!flag)
    {
        if (fseek(in, 0, SEEK_END) < 0)
            return READ_ERR;
        if (fwrite(&s1, sizeof(struct product), 1, in) != 1)
        {
            printf("FLAG-ERR");
            return WRITE_ERR;
        }
    }
    return EXIT_SUCCESS;
}
int struct_shift(FILE *in, size_t st, size_t end)
{
    struct product s1;
    size_t size = sizeof(struct product);

    while (st < end)
    {
        if (get_struct(in, end / size - 1, size, &s1))
            return READ_ERR;
        if (put_struct(in, (end / size), size, &s1))
            return WRITE_ERR;
        end -= size;
    }
    return EXIT_SUCCESS;
}
int print(FILE *f, size_t size)
{
    if (!size)
        return SIZE_ERR;
    struct product s1;
    int rc;
    for (size_t i = 0; i < size / sizeof(struct product); i++)
    {
        rc = fread(&s1, sizeof(struct product), 1, f);
        if (rc == 1)
            printf("%s%s%u\n%u\n", s1.manufacture, s1.name, s1.price, s1.count);
        else
            return READ_ERR;
    }
    return EXIT_SUCCESS;
}
