#define __USE_MINGW_ANSI_STDIO 1
#include "utils.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    if (argc != 3 && argc != 4)
        return ARG_ERR;

    char mode[3];
    strncpy(mode, argv[1], 2);
    mode[2] = '\0';
    size_t size = 0;
    int rc = OUT_ERR;
    if (argc == 4)
    {
        if (!strcmp(mode, "sb"))
        {
            FILE *in;
            FILE *out;
            in = fopen(argv[2], "rb+");
            out = fopen(argv[3], "wb+");
            if (!in || !out)
                return OPEN_ERR;
            rc = struct_sort(in, out, &size);
            fclose(in);
            fclose(out);
            return rc;
        }
        else if (!strcmp(mode, "fb"))
        {
            const char *end = argv[3];
            FILE *in;
            in = fopen(argv[2], "rb");
            if (!in)
                return OPEN_ERR;
            rc = find_str(in, end, &size);
            fclose(in);
            return rc;
        }
        else
            return ARG_ERR;
    }
    else if (argc == 3)
    {
        if (!strcmp(mode, "do"))
        {
            FILE *in;
            in = fopen(argv[2], "ab+");
            if (!in)
                return READ_ERR;
            rc = write_struct(in);
            fclose(in);
            return rc;
        }
        else if (!strcmp(mode, "pr"))
        {
            FILE *in;
            in = fopen(argv[2], "rb");
            if (!in)
                return READ_ERR;
            rc = print(in, &size);
            fclose(in);
            return rc;
        }
        else if (!strcmp(mode, "ab"))
        {
            FILE *in;
            in = fopen(argv[2], "rb+");
            if (!in)
                return READ_ERR;
            rc = add_struct(in, &size);
            fclose(in);
            return rc;
        }
        else
            return ARG_ERR;
    }

    return EXIT_SUCCESS;
}
