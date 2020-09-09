#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "films.h"


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
        return READ_FILE_ERR;

    fseek(in, 0, SEEK_END);

    if (!ftell(in))
        return EMPTY;

    fseek(in, 0, SEEK_SET);

    cinema list[MAX];
    size_t len = 0;
    long rc = 0;

    rc = fill(in, list, &len, key);
    if (rc)
    {
        fclose(in);
        return rc;
    }

    if (argc == 3)
        print(list, len);
    else
    {
        rc = bin_search(list, key, argv[3], len);
        if (rc == -1)
        {
            printf("Not found\n");
            rc = EXIT_SUCCESS;
        }
        else
        {
            size_t ind = rc;
            printf("%s\n%s\n%ld\n", list[ind].title, list[ind].name, list[ind].year);
            rc = EXIT_SUCCESS;
        }
    }
    fclose(in);
    return rc;
}
