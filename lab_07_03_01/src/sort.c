#include "../inc/sort.h"
#include "../inc/err.h"


int cmp_l(const void *a, const void *b)
{
    const long *frst = a;
    const long *sec = b;
    return (int)(*frst - *sec);
}

void mysort(void *first, size_t len, size_t size, int (*cmp)(const void *, const void *))
{
    char *last = (char*)first + len * size;
    char *prev;
    char *tmp = (char *)malloc(size);
    assert(tmp);
    for (char *i = (char*)first + size; i < last; i += size)
    {
        prev = (char*)(i - size);
        memcpy(tmp, i, size);
        while (prev >= (char*)first && cmp(prev, tmp) > 0)
        {
            memcpy(prev + size, prev, size);
            prev -= size;
        }
        memcpy(prev + size, tmp, size);
    }
    free(tmp);
}
