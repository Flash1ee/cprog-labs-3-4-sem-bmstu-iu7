#include "../inc/sort.h"
#include "../inc/err.h"

int cmp_i(const void *a, const void *b)
{
    const int *frst = a;
    const int *sec = b;
    return (int)(*frst - *sec);
}

void mysort(void *first, size_t len, size_t size, int (*cmp)(const void *, const void *))
{
    assert(size > 0);
    char *last = (char *)first + len * size;
    char *prev;
    char *tmp = (char *)malloc(size);
    if (!tmp)
        free(tmp);
    else
    {
        for (char *i = (char *)first + size; i < last; i += size)
        {
            prev = (char *)(i - size);
            memcpy(tmp, i, size);
            while (prev >= (char *)first && cmp(prev, tmp) > 0)
            {
                memcpy(prev + size, prev, size);
                prev -= size;
            }
            memcpy(prev + size, tmp, size);
        }
        free(tmp);
    }
}
