#include <stdio.h>
#include <string.h>
#include "utils.h"

node_t *create_list_nodes(data_t *src, node_t **head)
{
    if (!src || !src->arr || !src->len)
    {
        return NULL;
    }
    node_t *new = NULL;
    for (size_t i = 0; i < src->len; i++)
    {
        new = create_node(&src->arr[i]);
        if (!new)
        {
            free_list(*head);
            return NULL;
        }

        *head = list_add_front(*head, new);
        if (!*head)
        {
            free_list(*head);
            return NULL;
        }
    }
    return *head;
}
node_t *update_list_nodes(node_t **head, data_t *data)
{
    free_list(*head);
    *head = NULL;
    node_t *tmp = create_list_nodes(data, head);
    if (!tmp)
    {
        return NULL;
    }
    *head = tmp;
    return *head;
}
int validate_input(int argc, char *argv[], int *mode, long *cnt)
{
    if (!argv || !mode || !cnt)
    {
        return ARG_ERR;
    }
    if (argc != 2 && argc != 4)
    {
        return ARG_ERR;
    }
    if (argc == 2)
    {
        *mode = PRINT;
        return EXIT_SUCCESS;
    }
    *cnt = strtol(argv[3], NULL, 10);
    if (!(*cnt))
    {
        return ARG_ERR;
    }
    *mode = MODIFIED;

    return EXIT_SUCCESS;
}
void clean_buf()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
int print_to_file(node_t *head, char *f_name)
{
    FILE *f = fopen(f_name, "w");
    if (!f)
    {
        return F_READ_ERR;
    }
    print_list(head, f);
    if (!ferror(f))
    {
        fclose(f);
        return F_READ_ERR;
    }
    fclose(f);
    return EXIT_SUCCESS;
}