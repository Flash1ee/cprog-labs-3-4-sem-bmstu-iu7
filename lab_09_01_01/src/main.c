#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "films.h"
#include "utils.h"


int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4)
        return ARG_ERR;
    if (strcmp(argv[2], "title") && strcmp(argv[2], "name") && strcmp(argv[2], "year"))
        return ARG_ERR;
    if (argc == 4 && strlen(argv[3]) > N)
        return ARG_ERR;
    if (argc == 4 && !strcmp(argv[2], "year")
        && (is_year(argv[3]) == ARG_ERR || atoi(argv[3]) <= 0))
        return ARG_ERR;

    Field key;

    if (!strcmp(argv[2], "title"))
        key = TITLE;
    else if (!strcmp(argv[2], "name"))
        key = NAME;
    else if (!strcmp(argv[2], "year"))
        key = YEAR;


    FILE *in = NULL;

    in = fopen(argv[1], "r");

    if (!in)
    {
        return READ_FILE_ERR;
    }

    fseek(in, 0, SEEK_END);

    if (!ftell(in))
    {
        fclose(in);
        return EMPTY;
    }

    fseek(in, 0, SEEK_SET);

    size_t file_len = 0;

    if (size_file(in, &file_len))
    {
        fclose(in);
        return READ_FILE_ERR;
    }

    cinema **list = create_cinema_list(file_len);
    if (!list)
    {
        fclose(in);
        return ALLOCATION_ERR;
    }

    if (fill(in, list, file_len, key))
    {
        free_list(list, file_len);
        fclose(in);
        return READ_FILE_ERR;
    }

    if (argc == 3)
    {
        print(list, file_len);
    }
    else
    {
        int rc = bin_search(list, key, argv[3], file_len);
        if (rc == -1)
        {
            printf("Not found\n");
        }
        else
        {
            int ind = rc;
            printf("%s\n%s\n%ld\n", list[ind]->title, list[ind]->name, list[ind]->year);
        }
    }
    free_list(list, file_len);
    fclose(in);
    return EXIT_SUCCESS;
}
