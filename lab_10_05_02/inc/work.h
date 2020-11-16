#ifndef _WORK_H_
#define _WORK_H_

#define FOUND 100
#define NOT_FOUND -1

#include "types.h"

void clean_buf();
int input_str(char **str);
int convert_to_list(char *str, node_t **head);
int output();
node_t *append(node_t *a, node_t *b);
int cat();
int remove_spaces(char *str);
int one_sps_str();
size_t len_node_str(node_t *head, size_t *cnt_nodes);
char get_elem(node_t *head, size_t pos);
int substr_in_str(node_t *head, char *substr);
int search_substr();

#endif // _WORK_H_