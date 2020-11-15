#ifndef _NODE_H_
#define _NODE_H_

#include "data.h"
#include "types.h"
#include "retcodes.h"

void append(node_t **head_a, node_t **head_b);
void insert(node_t **head, node_t *elem, node_t *before);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

void print_list(node_t *head, FILE *out);

node_t *create_node(task_t *data_add);
void free_node(node_t *node);
node_t *list_add_front(node_t *head, node_t *new_node);
void free_list(node_t *head);
int comparator(const void *a, const void *b);

#endif // _NODE_H_