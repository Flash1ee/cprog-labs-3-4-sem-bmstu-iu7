#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"


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
        if (!(cnt = strtol(argv[2], NULL, 10)))
            return ERR_CNT;

        FILE* f;
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
            if (!f)
                return OPEN_ERR;
            if (file_size(f, &size))
            {
                fclose(f);
                return READ_ERR;
            }
            if ((size % sizeof(int)))
                return BEATEN_FILE;
            rc = print(f, size);
            if (rc)
            {
                fclose(f);
                return rc;
            }
            fclose(f);
        }
        else
        {
            size_t size;
            FILE *f;
            f = fopen(argv[2], "rb+");
            if (!f)
                return OPEN_ERR;
            if (file_size(f, &size))
            {
                fclose(f);
                return READ_ERR;
            }
            if ((size % sizeof(int)))
                return BEATEN_FILE;
            for (size_t i = 0; i < size - sizeof(int); i += sizeof(int))
                for (size_t j = 0; j < size - i - sizeof(int); j += sizeof(int))
                    if (bubble_sort(f, j))
                    {
                        fclose(f);
                        return SORT_ERR;
                    }
            fclose(f);
        }
    }
    return OK;
}
