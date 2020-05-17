#include "utils.h"

int file_size(FILE *f, size_t *size)
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
int get_number_by_pos(FILE *f, size_t pos, int *num)
{
    int rc;
    rc = fseek(f, pos, SEEK_SET);
    if (rc)
        return READ_ERR;

    rc = fread(num, sizeof(int), 1, f);

    if (rc != 1)
        return READ_ERR;
    fseek(f, 0, SEEK_SET);

    return OK;
}
int put_number_by_pos(FILE *f, size_t pos, int *num)
{
    int rc;
    rc = fseek(f, pos, SEEK_SET);
    if (rc)
        return READ_ERR;
    rc = fwrite(num, sizeof(int), 1, f);

    if (rc != 1)
        return WRITE_ERR;
    fseek(f, 0, SEEK_SET);
    return OK;
}
int bubble_sort(FILE *f, size_t j)
{
    int x, y;
    if (get_number_by_pos(f, j, &x) || get_number_by_pos(f, j + sizeof(int), &y))
        return READ_ERR;
    if (x > y)
    {
        if (put_number_by_pos(f, j, &y) || put_number_by_pos(f, j + sizeof(int), &x))
            return WRITE_ERR;
    }
    return OK;
}
int write_rand(FILE *f, size_t cnt)
{
    srand(time(NULL));
    int buf;
    for (size_t i = 0; i < cnt; i++)
    {
        buf = (rand() % DIGITS) - DIGITS / 2;
        if (fwrite(&buf, sizeof(int), 1, f) != 1)
            return WRITE_ERR;
    }
    return OK;
}

int print(FILE *f, size_t size)
{
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
