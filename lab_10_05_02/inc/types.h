#ifndef _TYPES_H_
#define _TYPES_H_

#include "utils.h"
#define CAT_L 4
#define CAT_B 8

typedef struct node_t node_t;

struct node_t
{
    char data[BUF_SIZE];
    node_t *next;
};

void print_list(node_t *head);
void free_node(node_t *node);
void free_list(node_t *head);
node_t *list_add_back(node_t *new_node, node_t **head);
node_t *create_node(char *str);

#endif // _TYPES_H_