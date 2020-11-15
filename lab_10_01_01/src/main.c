#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "node.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    int flag;
    long cnt_add = 0;
    int rc = validate_input(argc, argv, &flag, &cnt_add);
    if (rc)
    {
        return rc;
    }
    char *f_in = argv[1];
    size_t count = get_size(f_in);
    if (!count)
    {
        return F_READ_ERR;
    }

    data_t *database = NULL;
    rc = fill_list(f_in, &database, count);
    if (rc)
    {
        return rc;
    }

    node_t *head = NULL;
    if (!create_list_nodes(database, &head))
    {
        free_arr(database);
        return LIST_CR_ERR;
    }

    // printf("Tasks from file: \n");
    // print_list(head);

    node_t *sort_head = NULL;
    sort_head = sort(head, comparator);
    if (!sort_head)
    {
        free_arr(database);
        free_list(head);
        return SORT_ERR;
    }
    head = sort_head;
    printf("SORTED\n");
    print_list(head, stdout);
    printf("\n\n");
    if (flag == MODIFIED)
    {
        for (long i = 0; i < cnt_add; i++)
        {
            rc = add_list(&database, &head);
            if (rc)
            {
                free_list(head);
                return F_READ_ERR;
            }
            node_t *node_to_add = create_node(&(database->arr[database->len - 1]));
            insert(&head, node_to_add, head);
        }
        sort_head = sort(head, comparator);
        if (!sort_head)
        {
            free_arr(database);
            free_list(head);
            return SORT_ERR;
        }
        head = sort_head;

        print_list(head, stdout);
    }
    if (flag == MODIFIED)
    {
        rc = print_to_file(head, argv[2]);
    }
    free_arr(database);
    free_list(head);

    return rc;
}