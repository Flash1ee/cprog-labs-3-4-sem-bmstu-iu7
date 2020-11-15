#ifndef _UTILS_H_
#define _UTILS_H_

#include "types.h"
#include "node.h"

#define PRINT 0
#define MODIFIED 1

node_t *create_list_nodes(data_t *src, node_t **head);
node_t *update_list_nodes(node_t **head, data_t *data);
int validate_input(int argc, char *argv[], int *mode, long *cnt);
void clean_buf();
int print_to_file(node_t *head, char *f_name);

#endif // _UTILS_H_
