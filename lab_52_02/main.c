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
    int rc = 0;
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
            if (file_copy(in, out))
            {
                fclose(in);
                fclose(out);
                return COPY_ERR;
            }
            if (file_size(out, &size) || size < 1)
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

            rc = sort(out, size, &s1, &s2);
            if (rc)
            {
                fclose(in);
                fclose(out);
                return rc;
            }
            fclose(in);
            fclose(out);
            return EXIT_SUCCESS;
        }
        else if (!strcmp(mode, "fb"))
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
        if (!strcmp(mode, "do"))
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
        else if (!strcmp(mode, "pr"))
        {
            FILE *in;
            size_t size = 0;
            in = fopen(argv[2], "rb");
            if (file_size(in, &size))
            {
                fclose(in);
                return SIZE_ERR;
            }
            if (size % sizeof(struct product))
            {
                fclose(in);
                return BEATEN_FILE;
            }

            if (print(in, size))
            {
                fclose(in);
                return READ_ERR;
            }
            fclose(in);
            return EXIT_SUCCESS;
        }
        else if (!strcmp(mode, "ab"))
        {
            FILE *in;
            in = fopen(argv[2], "rb+");
            if (!in)
                return READ_ERR;
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
