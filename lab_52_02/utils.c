#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"

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
    int rc = OUT_ERR;
    if (fread(&s1, sizeof(struct product), 1, in) == 1)
    {
        ptr = strrchr(s1.name, value[0]);
        if (ptr)
        {
            strncpy(tmp, s1.name + (ptr - s1.name), NAME + 1);
            if (!strcmp(value, tmp) || (strstr(s1.name, value) == s1.name && strlen(value) == strlen(s1.name)))
            {
                if (rc)
                    rc = 0;
                printf("%s\n%s\n%u\n%u\n", s1.name, s1.manufacture, s1.price, s1.count);
            }
        }
        while (fread(&s1, sizeof(struct product), 1, in) == 1)
        {
            ptr = strrchr(s1.name, value[0]);
            if (ptr)
            {
                strncpy(tmp, s1.name + (ptr - s1.name), NAME + 1);
                if (!strcmp(value, tmp) || (strstr(s1.name, value) == s1.name && strlen(value) == strlen(s1.name)))
                {
                    if (rc)
                        rc = 0;
                    printf("%s\n%s\n%u\n%u\n", s1.name, s1.manufacture, s1.price, s1.count);
                }
            }
        }
        if (!feof(in))
            return READ_ERR;

        return rc;
    }
    return READ_ERR;
}

int insert(FILE *in, size_t size)
{
    struct product s1;
    struct product s2;
    memset(&s1, 0, sizeof(struct product));
    memset(&s2, 0, sizeof(struct product));
    int flag = 0;

    if (scanf("%s", s1.name) != 1 || scanf("%s", s1.manufacture) != 1)
    {
        printf("ERROR NAME");
        return READ_ERR;
    }
    if (scanf("%u", &s1.price) != 1 || scanf("%u", &s1.count) != 1)
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
    memset(&s1, 0, sizeof(struct product));
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
int print(FILE *in, size_t *size)
{
    if (file_size(in, size))
        return SIZE_ERR;
    if (!(*size))
        return SIZE_ERR;
    if (*size % sizeof(struct product))
        return BEATEN_FILE;

    struct product s1;
    int rc;
    for (size_t i = 0; i < *size / sizeof(struct product); i++)
    {
        rc = fread(&s1, sizeof(struct product), 1, in);
        if (rc == 1)
            printf("%s\n%s\n%u\n%u\n", s1.name, s1.manufacture, s1.price, s1.count);
        else
            return READ_ERR;
    }
    return EXIT_SUCCESS;
}
int add_struct(FILE *in, size_t *size)
{
    if (file_size(in, size) || *size < 1)
        return SIZE_ERR;
    if (*size % sizeof(struct product))
        return BEATEN_FILE;
    *size = *size / sizeof(struct product);
    if (insert(in, *size))
    {
        printf("INSERT-ERR");
        return WRITE_ERR;
    }
    return EXIT_SUCCESS;
}
int write_struct(FILE *in)
{
    struct product s1;
    memset(&s1, 0, sizeof(struct product));
    if (scanf("%s", s1.name) != 1 || scanf("%s", s1.manufacture) != 1)
    {
        printf("ERROR-INPUT-STRUCT");
        return READ_ERR;
    }
    if (scanf("%u", &s1.price) != 1 || scanf("%u", &s1.count) != 1)
    {
        printf("ERROR-INPUT-STRUCT");
        return READ_ERR;
    }
    if (fwrite(&s1, sizeof(struct product), 1, in) != 1)
    {
        printf("ADD_STRUCT_ERROR");
        return WRITE_ERR;
    }
    return EXIT_SUCCESS;
}
int find_str(FILE *in, const char *end, size_t *size)
{
    int rc;
    if (file_size(in, size) || *size < 1)
        return SIZE_ERR;
    if (*size % sizeof(struct product))
        return BEATEN_FILE;
    *size = *size / sizeof(struct product);
    rc = search_struct(in, end);
    return rc;
}
int struct_sort(FILE *in, FILE *out, size_t *size)
{
    int rc;
    if (file_copy(in, out))
        return COPY_ERR;
    if (file_size(out, size) || *size < 1)
        return SIZE_ERR;
    if (*size % sizeof(struct product))
        return BEATEN_FILE;
    *size = *size / sizeof(struct product);
    struct product s1, s2;
    memset(&s1, 0, sizeof(struct product));
    memset(&s1, 0, sizeof(struct product));
    rc = sort(out, *size, &s1, &s2);
    return rc;
}
